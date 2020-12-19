#ifndef EZDL_FILE_H
#define EZDL_FILE_H

#include <fstream>


class EZDL_File
{
private:
    const char* m_path;
    std::ofstream m_writer;
    std::ifstream m_reader;

public:
	EZDL_File(const char* path)
	{
	    m_path = path;
	}

    char* read()
    {
	    EZDL_Assert(m_path != NULL, "Path for reading the file is NULL");
	    
	    m_reader.open(m_path, std::ifstream::in);
	    if(m_reader.is_open())
	    {
	        m_reader.seekg(0, m_reader.end);
	        int length = m_reader.tellg();
	        m_reader.seekg(0, m_reader.beg);
	        
	        char* buffer = new char[length];
	        m_reader.read(buffer, length);

	        return buffer;
	        delete buffer;
	        m_reader.close();
	    }
	    else
	    {
	        EZDL_Error("Couldn't open the file for reading");
	    }
	}

    void write(const char* in)
	{
	    m_writer.open(m_path, std::ifstream::out);
	    if(m_writer.is_open())
	    {
	        m_writer << in;
	        m_writer.close();
	    }
	    else
	    {
	        EZDL_Error("Couldn't open the file for writing");
	    }
	}


	void clear()
	{
	    m_writer.open(m_path, std::ifstream::trunc);
	    if(m_writer.is_open())
	    {
	        m_writer.write("", 0);
	        m_writer.close();
	    }
	    else
	    {
	        EZDL_Error("Couldn't open the file for clearing");
	    }
	}
};


#endif
