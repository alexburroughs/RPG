#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include "reader.h"
#include "map.h"
#include <deque>
#include <unordered_map>

mapbits str_to_mapbits(std::string inp);

class CsvReader : public Reader {
    private:
        char* read(const std::string file_name, long position, long length);
        char* read(std::string file_name);
   
    public:
        CsvReader();
        std::deque<mapbits>* readnums(std::string filename);
        std::unordered_map<std::string, std::string>* readkv(std::string filename);
        ~CsvReader();
};

#endif