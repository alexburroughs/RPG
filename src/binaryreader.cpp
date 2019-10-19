#include <fstream>
#include <string>
#include <sys/stat.h>

#include "binaryreader.h"


BinaryReader::BinaryReader() : Reader() { }


/**
 * Reads binary files from any position and of any length within the corresponding file.
 **/
char* BinaryReader::read(const std::string file_name, long position, long length) {
    // Check file size and reading size.
    off_t size = file_size(file_name);
    if (size > 0 && position + length <= size) {
        // Read binary file into buffer.
        char* buffer = new char[length + 1]();
        std::ifstream file(file_name, std::ios::in | std::ios::binary);
        if (file) {
            file.seekg(position, std::ios::beg);
            file.read(buffer, length);
            file.close();
            buffer[length] = '\0';
            return buffer;
        }
    }
    return new char[1]{ '\0' };
}

char* BinaryReader::read(std::string file_name) {
    off_t size = file_size(file_name);
    if (size > 0)
        return read(file_name, 0, size);
    return new char[1]{ '\0' };
}


BinaryReader::~BinaryReader() { }