#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Image
{
    public:
    int label;
    vector <double> target;
    vector <double> pixels;
    void display();
    void setTarget();
};