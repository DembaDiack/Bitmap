#ifndef _BMPHEADER_
#define _BMPHEADER_

#include<cstdint>

using namespace std;

#pragma pack(2)

struct BMP_File_Header
{
    char signature[2]{'B','M'};
    int32_t filesize;
    int32_t reserved;
    int32_t offset;
};


#endif