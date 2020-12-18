#ifndef EZDL_FILE_H
#define EZDL_FILE_H

#include <iostream>
#include <fstream>


class File
{
private:
    std::ofstream writer;
    std::ifstream reader;
    const char* data = NULL;

public:

    char* Read(const char* path)
    {
        if(path == NULL)
        {
            std::cout << "Error: The part for FileRead is NULL" << std::endl;
        }
        
        reader.open(path, std::ifstream::in);
        
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
            std::cout << "Error: Couldn't open file" << std::endl;
        }
    }

    void Write(const char* path, const char* in)
    {
        writer.open(path,ifstream::out);
        if(writer.is_open())
        {
            writer << in;
            writer.close();
        }
    }

    void Clear(const char* path)
    {
        writer.open(path,ifstream::trunc);
        if(writer.is_open())
        {
            writer.write("", 0);
            writer.close();
        }
        else
        {
            std::cout << "Error: Couldn't open the file" << std::endl;
        }
    }
};


#endif
