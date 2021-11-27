#include "neuralnet.hpp"
//#include <cmath>
#include <math.h>

NeuralNetwork::NeuralNetwork(const vector<int> &topology)
{
    //int numLayers = topology.size();
    for (int i = 0; i < topology.size(); i++) //adding layer to the net
    {
        cout << "Adding Layer with " << topology[i] << " neurons" << endl;
        Layer layer;
        layers.push_back(layer);

        //densely connct the layers
        int conections;
        if (i == topology.size() - 1)
        {
            conections = 0;
        }
        else
        {
            conections = topology[i + 1];
        }

        for (int j = 0; j <= topology[i]; j++) //adding neurons to layer
        {
            Neuron neuron(conections,j);
            //neuron.setIndex(j);
            layers.back().addNeuron(neuron);
            cout << "neuron added" << endl;
        }
    }
}



void NeuralNetwork::FeedForward(const vector <double> input)
{
    //assert(input.size == layers[0].NumNeurons - 1);
    for (int j = 0; j <input.size();j++) // feed ing input to the first layer.
    {
        layers[0].neurons[j].setVal(input[j]);
    }

    for (int i =1; i < layers.size(); i++)
    {
        //layers[i].neurons[j].setVal(input[j]);
        Layer &previous = layers[i-1];
        for (int n = 0; n < layers[i].neurons.size(); n++)
        {
            //layers[i].neurons[j].setVal(input[j]);
            layers[i].neurons[n].feedforward(previous);
        }
    }
}



void NeuralNetwork::BackPropagation(const vector <double> target)
{
    Layer &outputLayer = layers.back();

    double sum = 0.0;
    double rms;
    double delta;

    for (int i = 0; i < outputLayer.neurons.size()-1; i++)
    {
        delta = target[i] - outputLayer.neurons[i].getval();
        sum += (delta * delta);
    }
    rms = sqrt((1/outputLayer.neurons.size())*sum);

    error = rms;

}