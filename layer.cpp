#include "layer.hpp"

void Layer::addNeuron(Neuron n)
{
    neurons.push_back(n);
}


int Layer::NumNeurons()
{
    return neurons.size();
}