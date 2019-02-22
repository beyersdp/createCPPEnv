#include <iostream>
#include <string>
#include "createCPPEnv.h"

int main(int argc, char* argv[]) {

	if (argc <= 1) {
		std::cout<<"[CONTROL][ERR] No arguments"<<std::endl;
		return 1;
	}
	if (argc != 3) {
		std::cout<<"[CONTROL][ERR] Not enough arguments"<<std::endl;
		std::cout<<"argv[1] = project name (e.g. myProject)"<<std::endl;
		std::cout<<"argv[2] = project path (e.g. ./myProg/)"<<std::endl;
		return 1;
	}

	std::string name(argv[1]);
	std::string path(argv[2]);
		
	bool res1 = create_makefile(name, path);
	bool res2 = create_headerfile(name, path);
	bool res3 = create_header_implementation(name, path);
	bool res4 = create_mainfile(name, path);

	int check = 0;
	if(!res1) {check++;}
	if(!res2) {check++;}
	if(!res3) {check++;}
	if(!res4) {check++;}

	if (check > 0) {
		std::cout<<"[CONTROL] "<<std::to_string(check)<<" Errors occurred"
			<<std::endl;
	}

	return 0;
}
