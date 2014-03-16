#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <cstring>
using namespace std;

bool getLineFromNtoM(char *newFileName, char *sourceFileName, int startLine, int endLine)
{
    assert(NULL != newFileName && NULL != sourceFileName && startLine > 0 && endLine >= startLine);
    ifstream fdSource;
    fdSource.open(sourceFileName,ios::in);
    if(!fdSource.is_open())
    {
        printf("open file %s failed.\n",sourceFileName);
    }
    ofstream fdNew;
    fdNew.open(newFileName,ios::out | ios::trunc);
    if(!fdNew.is_open())
    {
        printf("open file %s failed.\n",newFileName);
    }
    int startLinei = 1;
    string str;
    while(startLinei < startLine && !fdSource.eof())
    {
        getline(fdSource, str);
        startLinei++;
        if(startLinei == startLine)
            break;
    }
    if (startLinei == startLine)
    {
       while(getline(fdSource, str))
       {
           fdNew << str << endl;
           startLinei++;
           if(startLinei == endLine +1)
               break;
           
       }
    }
    fdSource.close();
    fdNew.close();


}

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        printf("input parameters number are not enough.\n");
        printf("for example: ./xxx newFileName sourceFileName startLine endLine\n");
        exit(1);
    }
    char newFileName[50];
    strcpy(newFileName,argv[1]);
    char sourceFileName[50];
    strcpy(sourceFileName,argv[2]);
    int startLine = atoi(argv[3]);
    int endLine = atoi(argv[4]);

    getLineFromNtoM(newFileName,sourceFileName,startLine,endLine);

    return 0;
}
