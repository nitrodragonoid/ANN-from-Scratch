#include "neuralnet.hpp"
//#include <cmath>
#include <math.h>

NeuralNetwork::NeuralNetwork(const vector<int> &topology, double eta, double alpha)
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
            Neuron neuron(conections, j, eta, alpha);
            //neuron.setIndex(j);
            layers.back().addNeuron(neuron);
            cout << "neuron added" << endl;
        }
        layers.back().neurons.back().setVal(1.0);
    }
}



void NeuralNetwork::FeedForward(const vector <double> input)
{
    //assert(input.size == layers[0].NumNeurons - 1);
    for (int j = 0; j <input.size();j++) // feed ing input to the first layer.
    {
        layers[0].neurons[j].setVal(input[j]);
    }

    for (int i =1; i < layers.size(); i++) //feed to the rest of the layers
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

    //calculate error from output layer
    for (int i = 0; i < outputLayer.neurons.size()-1; i++)
    {
        //cout << "setting output" << endl;
        delta = target[i] - outputLayer.neurons[i].getval();
        sum += (delta * delta);
    }
    rms = sqrt((1/outputLayer.neurons.size())*sum); //calculate root mean square

    error = rms;
    //cout << "rms calculated!" << endl;
    //calculate avg error
    //avgError = (avgError * avgSmoothingFactor + error) / (avgSmoothingFactor + 1);
    cout << "Error: " << rms << endl;
    
    //calculate gradient of ouytput layer
    for (int  n = 0; n < outputLayer.neurons.size() - 1; n++)
    {
        //cout << "calc output grad" << endl;
        outputLayer.neurons[n].setGrad(target[n]);
    }
    
    
    // calculate gradient for each hidden layer
    for (int l = layers.size()-2; l > 0; l--)
    {
        //cout << "calc hidden grad" << endl;
        Layer &current = layers[l];
        Layer &next  = layers[l+1];
        for (int n = 0; n < current.neurons.size(); n++)
        {
            current.neurons[n].setGrad(next);
        }
    }

    //update weights accordingly
    for (int l = layers.size()-1; l > 0; l--)
    {
        //cout << "updating weights" << endl;
        Layer &current  = layers[l];
        Layer &prev  = layers[l-1];

        for (int n = 0; n < current.neurons.size(); n++)
        {
            current.neurons[n].updateWeight(prev);
        }
    }

}


void NeuralNetwork::GetResult(/*vector <double> result*/)
{
    //result.clear();

    Layer &outputLayer = layers.back();
    for (int n = 0; n < outputLayer.neurons.size() - 1; n++)
    {
        //result.push_back(outputLayer.neurons[n].getval());
        cout << outputLayer.neurons[n].getval() << ", ";
    }
    cout << endl;
}