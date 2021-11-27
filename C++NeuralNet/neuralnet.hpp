#pragma once
#include "layer.hpp"

class NeuralNetwork
{
private:   
    //Layer layer1; 
    //Layer layer2;
    vector <Layer> layers;
    double error;

public:
    NeuralNetwork(const vector<int> &topology);
    void BackPropagation(const vector <double> target);
    void FeedForward(const vector <double> input);
    void GetResult(const vector <double> result) const;
};