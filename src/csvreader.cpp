#include "debug.h"
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <deque> 

#include "csvreader.h"


CsvReader::CsvReader() : Reader() { }


/**
 * Reads binary files from any position and of any length within the corresponding file.
 **/
char* CsvReader::read(const std::string file_name, long position, long length) {
    // Check file size and reading size.
    off_t size = file_size(file_name);
    if (size > 0 && position + length <= size) {
        // Read text file into buffer.
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

char* CsvReader::read(std::string file_name) {
    off_t size = file_size(file_name);
    if (size > 0)
        return read(file_name, 0, size);
    return new char[1]{ '\0' };
}

std::deque<mapbits>* CsvReader::readmap(std::string filename) {

    char delim(',');
    std::string csv(read(filename));
    std::deque<mapbits>* deq = new std::deque<mapbits>();

    std::stringstream ss(csv);
    std::string token;
    
    while (std::getline(ss, token, delim)) {
        deq->push_back(str_to_mapbits(token));
    }

    return deq;
}

mapbits str_to_mapbits(std::string inp) {

    int i(std::stoi(inp));
    mapbits to(0);
    
    if (i <= static_cast<int>(UINT16_MAX) && i >=0) {
        to = static_cast<mapbits>(i);
    }
    else {
        DEBUG("Error: Map value to large for uint16");
        std::exit(1);
    }

    return to;
}

CsvReader::~CsvReader() { }