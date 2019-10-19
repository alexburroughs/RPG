#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <string>
#include "reader.h"


class BinaryReader : public Reader {
    public:
    BinaryReader();
    char* read(const std::string file_name, long position, long length);
    char* read(std::string file_name);
    ~BinaryReader();
};

#endif