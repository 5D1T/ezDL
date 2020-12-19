#ifndef EZDL_FILE_H
#define EZDL_FILE_H

#include "error.h"
#include <iostream>
#include <fstream>


class EZDL_File
{
private:
    std::ofstream writer;
    std::ifstream reader;
    const char* data = NULL;

public:
    char* read(const char* path)
    {
        EZDL_Assert(path != NULL, "Path for reading the file is NULL");
        
        reader.open(path, std::ifstream::in);
        if(reader.is_open())
        {
            reader.seekg(0, reader.end);
            int length = reader.tellg();
            reader.seekg(0, reader.beg);
            
            char* buffer = new char[length];
            reader.read(buffer,length);

            return buffer;
            delete buffer;
            reader.close();
        }
        else
        {
            EZDL_Error("Couldn't open the file for reading");
        }
    }

    void write(const char* path, const char* in)
    {
        writer.open(path, std::ifstream::out);
        if(writer.is_open())
        {
            writer << in;
            writer.close();
        }
        else
        {
            EZDL_Error("Couldn't open the file for writing");
        }
    }

    void clear(const char* path)
    {
        writer.open(path, std::ifstream::trunc);
        if(writer.is_open())
        {
            writer.write("", 0);
            writer.close();
        }
        else
        {
            EZDL_Error("Couldn't open the file for clearing");
        }
    }
};


#endif
