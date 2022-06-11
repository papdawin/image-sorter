#include "analyzer.h"
#include "analyzer.cpp"
#include "exif.h"
#include "exif.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    try
        {
            if(argc!=2)
                throw "Please enter an image as argument";
            FILE *fp = fopen(argv[1], "rb");
            Analyzer *analyzer = new Analyzer(fp);
            cout<<analyzer->getDateTaken();
        }
        catch (const char *errormsg)
        {
            printf(errormsg);
        }
    return 0;
}
