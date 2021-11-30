#pragma once
#include "layer.hpp"

class NeuralNetwork
{
private:   
    //Layer layer1; 
    //Layer layer2;
    vector <Layer> layers;
    double error;

    double avgError;
    double avgSmoothingFactor;

public:
    double eta;
    double alpha;

    NeuralNetwork(const vector<int> &topology, double eta, double alpha);
    void BackPropagation(const vector <double> target);
    void FeedForward(const vector <double> input);
    void GetResult(vector <double> result);
};