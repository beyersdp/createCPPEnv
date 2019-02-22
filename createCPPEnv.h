#ifndef CREATECPPENV_H_
#define CREATECPPENV_H_

#include <string>

// Creates a specific makefile for the given project information
// argv[1] == name of the project, argv[2] == path of the project
bool create_makefile(const std::string& name, const std::string& path);

// Creates a specific headerfile for the given project information
// argv[1] == name of the project, argv[2] == path of the project
bool create_headerfile(const std::string& name, const std::string& path);

// Creates a specific file for the header implementation
// argv[1] == name of the project, argv[2] == path of the project
bool create_header_implementation(const std::string& name
				  , const std::string& path);

// Creates a specific mainfile for the given project information
// argv[1] == name of the project, argv[2] == path of the project
bool create_mainfile(const std::string& name, const std::string& path);

#endif  // CREATECPPENV_H_
