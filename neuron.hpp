#pragma once

#include <iostream>
#include <vector>
// #include "layer.hpp"
//#include <stdlib>

using namespace std;
class Layer;
class Edge
{
public:
    //Node*point;
    Edge();
    //Neuron *to;
    double weight;
    double delWeight;
};

class Neuron
{
public:
    double val;
    int index;

    vector<Edge> edges;
    Neuron(int connect,int ind); //construct a densely connected neuron

    void setVal(double v);
    void feedforward(const Layer &prev);
    void setIndex(int ind);

    double activation(double sum);
    double activationDerivative(double sum);
};
