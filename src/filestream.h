#ifndef FILELOADER_H
#define FILELOADER_H

#include <string>
#include <cstdint>

typedef u_int8_t mapbits;

class FileStream {
    public:
        virtual mapbits** loadMap(std::string filename);
        virtual void writeMap(std::string filename, mapbits** arr);
};

class BinaryStream : public FileStream {
    public:
        mapbits** loadMap(std::string filename);
        void writeMap(std::string filename, mapbits** arr);
};

class TextStream : public FileStream {
    private:
        
    public:
        mapbits** loadMap(std::string filename);
        void writeMap(std::string filename, mapbits** arr);
};

#endif