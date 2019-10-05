#ifndef TEXTREADER_H
#define TEXTREADER_H

#include <string>
#include "filereader.h"


class TextReader : public FileReader {
    public:
    TextReader();
    char* read(const std::string file_name, long position, long length);
    char* read(std::string file_name);
    ~TextReader();
};

#endif