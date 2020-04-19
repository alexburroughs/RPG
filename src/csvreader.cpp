#include "debug.h"
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <deque> 
#include <unordered_map>
#include "util.h"

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

std::deque<mapbits>* CsvReader::readnums(std::string filename) {

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

std::unordered_map<std::string,std::string>* CsvReader::readkv(std::string filename, std::string tag) {
    
    char delim('\n');
    char delimkv('=');
    char tagind('#');
   
    std::unordered_map<std::string, std::string>* map = new std::unordered_map<std::string, std::string>();
    
    std::string str(read(filename));

    std::stringstream ss(str);
    std::string token;

    std::deque<std::string> lines;

    bool skipping;
    bool processing = skipping = tag == "";

    DEBUG((processing ? "Skipping tags" : "Processing tag: " + tag))

    while (std::getline(ss, token, delim)) {
        if (!processing) {
            processing = token == tagind + tag;
            DEBUG("Reached tag")
            continue;
        }
        
        if (token.at(0) == tagind) {
            if (skipping)
                continue;
            break;
        }

        lines.push_back(token);
    }

    int size = lines.size();

    for (int16_t i = 0; i < size; i++) {

        std::string current;
        std::stringstream ess(lines.front());

        std::getline(ess, current, delimkv);
        std::string k = current;

        std::getline(ess, current, delimkv);
        std::string v = current;

        DEBUG("loaded " + k + " = " + v)

        (*map)[k] = v;

        lines.pop_front();
    }

    return map;
}

CsvReader::~CsvReader() { }