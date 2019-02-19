#include <iostream>
#include <fstream>
#include <string>
#include "createCPPEnv.h"

//_________________________________________________________________________
bool create_makefile(const std::string& name, const std::string& path) {

	std::string pathWithName = path;
	
	std::ofstream makefile (path + "makefile");

	makefile<< "all: "<<name<< " clean"<<std::endl;
	makefile<<std::endl;
	makefile<<name<<": "<<name<<"Main.o "<<name<<".o"<<std::endl;
	makefile<<'\t'<<"g++ -o "<<name<<" " <<name<<"Main.o "<<name
		<<".o"<<std::endl;
	makefile<<std::endl;
	makefile<<name<<"Main.o: "<<name<<"Main.cpp"<<std::endl;
	makefile<<'\t'<<"g++ -c "<<name<<"Main.cpp"<<std::endl;
	makefile<<std::endl;
	makefile<<name<<".o: "<<name<<".cpp"<<std::endl;
  	makefile<<'\t'<<"g++ -c "<<name<<".cpp"<<std::endl;
	makefile<<std::endl;
	makefile<<"clean:"<<std::endl;
	makefile<<'\t'<<"rm -f *.o"<<std::endl;

	makefile.close();
	
	return true;
}
