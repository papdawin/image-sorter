#ifndef ANALYZER_H
#define ANALYZER_H
#include "exif.h"
#include <iostream>

class Analyzer
{
    unsigned char *buffer;
    easyexif::EXIFInfo exifinfo;
public:
    Analyzer(FILE *fp);
    std::string getDateTaken();
    std::string getCamera();

};
#endif // ANALYZER_H
