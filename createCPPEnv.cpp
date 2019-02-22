#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include "createCPPEnv.h"

//_________________________________________________________________________
bool create_makefile(const std::string& name, const std::string& path) {
		
	std::ofstream makefile (path + "makefile");
	if (!makefile) {
		std::cout<<"[MAKEFILE][ERR] File not creatable"<<std::endl;
		return false;
	}

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

//_________________________________________________________________________
bool create_headerfile(const std::string& name, const std::string& path) {

	std::ofstream headerfile (path + name + ".h");
	if (!headerfile) {
		std::cout<<"[HEADERFILE][ERR] File not creatable"<<std::endl;
		return false;
	}
	
	time_t now = time(0);
	char* dt = ctime(&now);
	
	headerfile<<"/*"<<std::endl;
	headerfile<<" * Project name  = "<<name<<std::endl;
	headerfile<<" * Author name   = P. Beyersdorffer"<<std::endl;
	headerfile<<" * Creation date = "<<dt;
	headerfile<<" */"<<std::endl;
	headerfile<<std::endl;

	std::string n_up = name;
	std::transform(n_up.begin(), n_up.end(), n_up.begin(), 
		[] (char c) {return (toupper(c)); }); 

	headerfile<<"#ifndef "<<n_up<<"_H_"<<std::endl;
	headerfile<<"#define "<<n_up<<"_H_"<<std::endl;
	headerfile<<std::endl;
	headerfile<<std::endl;
	headerfile<<std::endl;
	headerfile<<std::endl;
	headerfile<<"#endif  //"<<n_up<<"_H_"<<std::endl;
	headerfile<<std::endl;

	headerfile.close();
	return true;
}

//_________________________________________________________________________
bool create_header_implementation(const std::string& name
					, const std::string& path) {

	std::ofstream implementation (path + name + ".cpp");
	if (!implementation) {
		std::cout<<"[HEADERFILE IMPLEMENTATION][ERR] File not creatable"
			<<std::endl;
		return false;
	}
	
	time_t now = time(0);
	char* dt = ctime(&now);

	implementation<<"/*"<<std::endl;	
	implementation<<" * Project name  = "<<name<<std::endl;
	implementation<<" * Author name   = P. Beyersdorffer"<<std::endl;
	implementation<<" * Creation date = "<<dt;
	implementation<<" */"<<std::endl;
	implementation<<std::endl;
	implementation<<"#include \""<<name<<".h\""<<std::endl;
	implementation<<std::endl;

	implementation.close();
	return true;
}

//_________________________________________________________________________
bool create_mainfile(const std::string& name, const std::string& path) {
	
	std::ofstream mainfile (path + name + "Main.cpp");
	if (!mainfile) {
		std::cout<<"[MAINFILE][ERR] File not creatable"<<std::endl;
		return false;
	}
	
	time_t now = time(0);
	char* dt = ctime(&now);
	
	mainfile<<"/*"<<std::endl;
	mainfile<<" * Project name  = "<<name<<std::endl;
	mainfile<<" * Author name   = P. Beyersdorffer"<<std::endl;
	mainfile<<" * Creation date = "<<dt;
	mainfile<<" */"<<std::endl;
	mainfile<<std::endl;
	mainfile<<"#include \""<<name<<".h\""<<std::endl;
	mainfile<<std::endl;
	mainfile<<"int main(int argc, char* argv[]) {"<<std::endl;
	mainfile<<std::endl;
	mainfile<<std::endl;
	mainfile<<std::endl;
	mainfile<<"\treturn 0;"<<std::endl;
	mainfile<<std::endl;
	mainfile<<"}"<<std::endl;	

	mainfile.close();
	return true;
}
