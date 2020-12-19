#include "src/oneH.h"


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	EZDL_File f;
	const char* file_name = "test";

	// Read
	std::cout << "Read from file: '" << f.read(file_name) << '\'' << std::endl;

	// Clear
	f.clear(file_name);
	std::cout << "Cleared the file" << std::endl;

	// Write
	const char* write = "EZDL File writing test";
	f.write(file_name, write);
	std::cout << "Writed to file: '" << write << '\'' << std::endl;

	SDL_Quit();
}