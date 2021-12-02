#include "image.hpp"

void Image::display()
{
    cout << label << " : ";
    /*
    for (int i = 0; i < pixels.size(); i++)
    {
        cout << pixels[i] << ", ";
    }
    */
    cout << endl << "targets: ";

    for (int j = 0; j < target.size(); j++)
    {
        cout << target[j] << ", ";
    }
    //cout << endl << "size of image: " << pixels.size() << endl;
}

void Image::setTarget()
{
    
    for (int i = 0; i < 10; i++)
    {
        if (i == label)
        {
            target.push_back(1.0);
        }
        else
        {
            target.push_back(0.0);
        }
    }
}