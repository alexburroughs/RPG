#ifndef READER_H
#define READER_H

#include <string>
#include <deque>
#include "map.h"

class Reader {
    public:
    Reader();
    virtual char* read(const std::string file_name, long position, long length) = 0;
    virtual char* read(std::string file_name) = 0;
    virtual std::deque<mapbits>* readmap(std::string filename) = 0;
    ~Reader();

    protected:
    off_t file_size(std::string file_name);
};

#endif