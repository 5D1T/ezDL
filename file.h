#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

#endif // FILE_H_INCLUDED

class File
{
private:
    ofstream writer;
    ifstream reader;
    const char* data = NULL;

public:

    char* Read(const char* path)
    {
        if(path == NULL)
        {
            cout<<"path for fileRead is null"<<endl;
        }

        reader.open(path,std::ifstream::in);

        if(reader.is_open())
        {
            reader.seekg (0, reader.end);
            int length = reader.tellg();
            reader.seekg (0, reader.beg);

            char* buffer = new char[length];
            reader.read(buffer,length);

            return buffer;
            delete buffer;
            reader.close();
        }
        else
        {
            cout<<"could not open file"<<endl;
        }


    }

    void Write(const char* path,const char* in)
    {
        writer.open(path,ifstream::out);
        if(writer.is_open())
        {
            writer<<in;
            writer.close();
        }
    }

    void Clear(const char* path)
    {
        writer.open(path,ifstream::trunc);
        if(writer.is_open())
        {
            writer.write("",0);
            writer.close();
        }
        else
        {
            cout<<"couldn't open file"<<endl;
        }


    }


};
