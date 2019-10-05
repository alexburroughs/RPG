#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <string>
#include <cstdint>
#include <memory>

typedef u_int8_t mapbits;

class FileStream {
    public:
        virtual std::unique_ptr<mapbits>** loadMap(std::string filename);
        virtual void writeMap(std::string filename, mapbits** arr);
};

class BinaryStream : public FileStream {
    public:
        std::unique_ptr<mapbits>** loadMap(std::string filename);
        void writeMap(std::string filename, mapbits** arr);
};

class TextStream : public FileStream {
    private:
        
    public:
        std::unique_ptr<mapbits>** loadMap(std::string filename);
        void writeMap(std::string filename, mapbits** arr);
};

#endif