#include <iostream>
#include <string>
#include "createCPPEnv.h"

int main(int argc, char* argv[]) {

	//TODO: check if argc > 1
	//TODO: if not implement user input function
	//TODO: check, if argv[2][:-1] == '/'

	std::string name(argv[1]);
	std::string path(argv[2]);

	std::cout << name << " " << path << std::endl;
	
	create_makefile(name, path);

	return 0;
}
