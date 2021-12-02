#include <iostream>
#include <vector> 
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "neuralnet.hpp"
#include "image.hpp"

using namespace std;


/*
int reverseInt (int i) 
{
    unsigned char c1, c2, c3, c4;

    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}


void read_mnist(string full_path)
{
    ifstream file (full_path"t10k-images-idx3-ubyte.gz");
    if (file.is_open())
    {
        int magic_number=0;
        int number_of_images=0;
        int n_rows=0;
        int n_cols=0;
        file.read((char*)&magic_number,sizeof(magic_number)); 
        magic_number= reverseInt(magic_number);
        file.read((char*)&number_of_images,sizeof(number_of_images));
        number_of_images= reverseInt(number_of_images);
        file.read((char*)&n_rows,sizeof(n_rows));
        n_rows= reverseInt(n_rows);
        file.read((char*)&n_cols,sizeof(n_cols));
        n_cols= reverseInt(n_cols);
        for(int i=0;i<number_of_images;++i)
        {
            for(int r=0;r<n_rows;++r)
            {
                for(int c=0;c<n_cols;++c)
                {
                    unsigned char temp=0;
                    file.read((char*)&temp,sizeof(temp));

                }
            }
        }
    }
}
*/




const int MAXN = 6e4 + 7;
unsigned int image[MAXN][30][30];
unsigned int num, magic, rows, cols;
unsigned int label[MAXN];
unsigned int in(ifstream& icin, unsigned int size) {
    unsigned int ans = 0;
    for (int i = 0; i < size; i++) {
        unsigned char x;
        icin.read((char*)&x, 1);
        unsigned int temp = x;
        ans <<= 8;
        ans += temp;
    }
    return ans;
}

vector <Image> images;

void input() {
    ifstream icin;
    icin.open("train-images.idx3-ubyte", ios::binary);
    magic = in(icin, 4), num = in(icin, 4), rows = in(icin, 4), cols = in(icin, 4);
    for (int i = 0; i < num; i++) {
        Image img;
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                image[i][x][y] = in(icin, 1);
                //cout << image[i][x][y] << endl;
                img.pixels.push_back(image[i][x][y]);
            }
        }
        images.push_back(img);
    }
    icin.close();
    icin.open("train-labels.idx1-ubyte", ios::binary);
    magic = in(icin, 4), num = in(icin, 4);
    for (int i = 0; i < num; i++) {
        label[i] = in(icin, 1);
        images[i].label = label[i];
        images[i].setTarget();
    }
}

void show(vector <double> res)
{
    for(int r = 0; r < res.size(); r++)
    {
        cout << res[r] << ", ";
    }
    cout << endl;
}


void build_model()
{
    //vector <double> result;
    
    vector <int> top;
    top.push_back(785);
    top.push_back(785);
    top.push_back(785);
    top.push_back(393);
    top.push_back(10);

    NeuralNetwork ANN(top,0.5,0.5);

    cout << "Network Built!" << endl;

    input();

    for (int j = 0; j < images.size(); j++)
    {
        //images[j].display();
        ANN.FeedForward(images[j].pixels);
        //cout << "Feetforward Done!" << endl;
        ANN.GetResult(/*result*/);

        //cout << "Got Results!" << endl;
        images[j].display();
        //show(result);
        //cout << "Starting Backprops" << endl;
        ANN.BackPropagation(images[j].target);
        //cout << "BackProp Done!" << endl;
    }

}


int main()
{
    //vector <int> vec;
    //vec.push_back(1);
    //cout << vec[0] << endl;
    /*
    input();

    for (int j = 0; j < images.size(); j++)
    {
        images[j].display();
    }
    */

    build_model();
    
    //NeuralNetwork Net(top, 0.15, 0.5);
    return 0;
}
