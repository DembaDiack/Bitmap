#include<iostream>
#include "include/Bitmap.h"

using namespace std;

int main()
{
    const int width = 600;
    const int height = 800;

    Bitmap bmp(width,height);
    
    bmp.write("test.bmp");
}