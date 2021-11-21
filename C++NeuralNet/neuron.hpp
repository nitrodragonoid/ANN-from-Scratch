#include <iostream>
#include <vector>
//#include <stdlib>

using namespace std;

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

    vector<Edge> edges;
    Neuron(int connect); //construct a densely connected neuron
};
