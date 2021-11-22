#pragma once

#include <iostream>
#include <vector>
#include "neuron.hpp"

using namespace std;


class Layer
{
    public:
    vector<Neuron> neurons;
    //Layer();

    void addNeuron(Neuron n);

    int NumNeurons();
};