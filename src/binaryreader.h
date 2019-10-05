#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <string>
#include "filereader.h"


class BinaryReader : public FileReader {
    public:
    BinaryReader();
    char* read(const std::string file_name, long position, long length);
    char* read(std::string file_name);
    ~BinaryReader();
};

#endif