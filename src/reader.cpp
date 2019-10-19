#include <fstream>
#include <string>
#include <sys/stat.h>

#include "reader.h"


Reader::Reader() { }


off_t Reader::file_size(std::string file_name) {
    struct stat results;
    return stat(file_name.c_str(), &results) == 0 ? results.st_size : 0;
}

Reader::~Reader() { }