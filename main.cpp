#include<iostream>
#include "include/Bitmap.h"

using namespace std;

int main()
{
    const int width = 600;
    const int height = 800;

    Bitmap bmp(width,height);
    
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            bmp.setPixel(x,y,66,168,50);
        }
    }

    bmp.write("test.bmp");
}