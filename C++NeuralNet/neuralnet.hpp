#include "layer.hpp"

class NeuralNetwork
{
    public:
    //Layer layer1; 
    //Layer layer2;
    vector <Layer> layers;

    NeuralNetwork(const vector<int> &topology);
    void BackPropagation(const vector <double> target);
    void FeedForward(const vector <double> input);
    void GetResult(const vector <double> result) const;
};