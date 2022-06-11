#include "analyzer.h"

Analyzer::Analyzer(FILE *fp){
    if (fp == nullptr)
        throw "Couldn't open file";
    fseek(fp, 0, SEEK_END);
    unsigned long fsize = ftell(fp);
    fseek(fp, 0, 0);
    buffer = new unsigned char[fsize];
    if (fread(buffer, 1, fsize, fp) != fsize)
        throw "Can't read file";
    fclose(fp);
    int code = exifinfo.parseFrom(buffer, fsize);
    delete[] buffer;
    switch (code) {
    case 1982:
        throw "No JPEG markers found in buffer, possibly invalid JPEG file";
        break;
    case 1983:
        throw "No EXIF header found in JPEG file";
        break;
    case 1984:
        throw "Byte alignment specified in EXIF file was unknown (not Motorola or Intel)";
        break;
    case 1985:
        throw "EXIF header was found, but data was corrupted";
        break;
    }
}

std::string Analyzer::getDateTaken(){
    return exifinfo.DateTime.c_str();
}

std::string Analyzer::getCamera(){
    return (exifinfo.Make+exifinfo.Model).c_str();
}
