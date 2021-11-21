#include <iostream>
#include <vector> 
#include "neuralnet.hpp"

using namespace std;

int main()
{
    //vector <int> vec;
    //vec.push_back(1);
    //cout << vec[0] << endl;
    vector <int> top;
    top.push_back(3);
    top.push_back(5);
    top.push_back(7);
    top.push_back(6);
    top.push_back(2);
    NeuralNetwork Net(top);
    return 0;
}
