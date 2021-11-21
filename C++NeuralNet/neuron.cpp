#include "neuron.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


Edge::Edge()
{
    srand(time(NULL));
    double initialWeight = rand() / double(RAND_MAX);

    weight = initialWeight;
    delWeight = 0;

    cout << weight << endl;
}

Neuron::Neuron(int connect)
{
    for (int i = 0; i < connect; i++)
    {
        Edge e;
        edges.push_back(e);
    }
    cout << "Forward connection of " << connect << " created" << endl;
}
