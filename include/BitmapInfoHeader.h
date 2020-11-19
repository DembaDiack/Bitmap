#ifndef _BMPINFOHEADER_
#define _BMPINFOHEADER_
#include<cstdint>

using namespace std;

#pragma pack(2)

struct BMP_Info_Header
{
    int32_t size{40};
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bits_per_pixel{24};
    int32_t compression{0};
    int32_t imageSize{0};
    int32_t Hresolution{2400};
    int32_t Vresolution{2400};
    int32_t colors{0};
    int32_t iColors{0};
};
#endif