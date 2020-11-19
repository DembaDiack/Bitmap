#ifndef _BITMAP_
#define _BITMAP_

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

#include <cstdint>
#include<memory>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;
class Bitmap
{
    int width,height;
    unique_ptr<uint8_t[]> pixels{nullptr};
    public:
    Bitmap(int width,int height) : width{width},height{height},pixels{new uint8_t[height * width * 3]{}}
    {};
    void setPixel(int x,int y,uint8_t red,uint8_t green,uint8_t blue)
    {
        uint8_t *pPixel = pixels.get();
        pPixel += (y * 3) * width + (x * 3);
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    }
    bool write(string filename)
    {
        BMP_File_Header fileheader;
        BMP_Info_Header infoheader;
        fileheader.filesize = sizeof(BMP_Info_Header) + sizeof(BMP_File_Header) + width * height * 3;
        fileheader.offset = sizeof(BMP_File_Header) + sizeof(BMP_Info_Header);

        infoheader.height = height;
        infoheader.width = width;
        
        ofstream file;
        file.open(filename,ios::binary);

        if(!file){return false;}

        file.write((char*)&fileheader,sizeof(fileheader));
        file.write((char*)&infoheader,sizeof(infoheader));
        file.write((char*)pixels.get(),height*width*3);

        file.close();


        return true;
    }
};

#endif