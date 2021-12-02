#include "neuron.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "layer.hpp"

using namespace std;


Edge::Edge()
{
    double initialWeight = rand() / double(RAND_MAX);

    weight = -1 * initialWeight;
    delWeight = 0;

    cout << weight << endl;
}

Neuron::Neuron(int connect,int ind, double e, double a)
{
    for (int i = 0; i < connect; i++)
    {
        Edge e;
        edges.push_back(e);
    }
    cout << "Forward connection of " << connect << " created" << endl;
    index = ind;  

    eta = e;
    alpha = a;
}


void Neuron::setVal(double v)
{
    val = v;
}

void Neuron::feedforward(const Layer &prev)
{
    double sum = 0.0;
    for (int i = 0; i < prev.neurons.size(); i++)
    {
        sum += prev.neurons[i].val * prev.neurons[i].edges[index].weight;
    }
    double act;
    act = activation(sum);
    //cout << " Current Value =" << act << endl;
    val = act;
    //cout << " Current Value ="<< val;
}

void Neuron::setIndex(int ind)
{
    index = ind;
}

double Neuron::activation(double sum)
{
    double y;
    //yp = 1 - ((tanh(sum))*tanh(sum));
    double e;
    e = 1/exp(sum);
    //cout << "sum =" << sum << " e^-x =" << e << endl;
    y = 1/(1+ e);
    return y;
}


double Neuron::activationDerivative(double sum)
{
    double sig;
    double yp;
    //yp = 1 - ((tanh(sum))*tanh(sum));
    double e;
    e = 1/exp(sum);
    sig = 1/(1+ e);
    yp = sig * (1-sig);
    return yp;
}

double Neuron::getval()
{
    return val;
}

void Neuron::setGrad(double target)
{
    gradient = (target - val) * activationDerivative(val);
    //cout << "gradient: " << gradient << endl;
}


void Neuron::setGrad(Layer &next)
{
    double sum = 0;

    for (int n = 0; n < next.neurons.size()-1; n++)
    {
        sum += edges[n].weight * next.neurons[n].gradient;
    }
    gradient = sum * activationDerivative(val);
    //cout << "gradient: " << gradient << endl;
}

void Neuron::updateWeight(Layer &prev)
{
    for (int n = 0; n < prev.neurons.size(); n++)
    {
        Neuron &neuron = prev.neurons[n];

        double oldDelta = neuron.edges[index].delWeight;

        double Delta = (eta * neuron.getval() * gradient) + (alpha * oldDelta);

        neuron.edges[index].delWeight = Delta;
        neuron.edges[index].weight += Delta;

        //cout << " Edge Weight = " << neuron.edges[index].weight << endl;
    }
}