#ifndef FILEREADER_H
#define FILEREADER_H


#include <string>

class FileReader {
    public:
    FileReader();
    virtual char* read(const std::string file_name, long position, long length) = 0;
    virtual char* read(std::string file_name) = 0;
    ~FileReader();

    protected:
    off_t file_size(std::string file_name);
};

#endif