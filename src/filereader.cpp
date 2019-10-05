#include <fstream>
#include <string>
#include <sys/stat.h>

#include "filereader.h"


FileReader::FileReader() { }


off_t FileReader::file_size(std::string file_name) {
    struct stat results;
    return stat(file_name.c_str(), &results) == 0 ? results.st_size : 0;
}


FileReader::~FileReader() { }