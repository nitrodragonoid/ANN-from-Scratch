#include "neuralnet.hpp"

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
            Neuron neuron(conections);
            layers.back().addNeuron(neuron);
            cout << "neuron added" << endl;
        }
    }
}