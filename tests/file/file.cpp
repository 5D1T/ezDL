#include <iostream>
#include "src/ezDL.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	const char* file_path = "test";
	EZDL_File f(file_path);

	// Read
	std::cout << "Read from file: '" << f.read() << '\'' << std::endl;

	// Clear
	f.clear();
	std::cout << "Cleared the file" << std::endl;

	// Write
	const char* write = "EZDL File writing test";
	f.write(write);
	std::cout << "Writed to file: '" << write << '\'' << std::endl;

	SDL_Quit();
	return 0;
}
