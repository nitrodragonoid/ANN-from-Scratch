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
private:
    double val;
    int index;
    double gradient;

public:
    vector<Edge> edges;
    Neuron(int connect,int ind, double e, double a); //construct a densely connected neuron

    void setVal(double v);
    void feedforward(const Layer &prev);
    void setIndex(int ind);
    double getval();


    double activation(double sum);
    double activationDerivative(double sum);

    
    void setGrad(double target);
    void setGrad(Layer &next);
    void updateWeight(Layer &prev);


    double eta;
    double alpha;
};
