#ifndef STREAMREADER_H
#define STREAMREADER_H

#include <cinttypes>
#include <string>


class StreamReader {
    public:
    StreamReader(char* array);
    char read();
    char* read(uint16_t n);
    int8_t readInt8();
    int16_t readInt16();
    int32_t readInt32();
    uint8_t readUInt8();
    uint16_t readUInt16();
    uint32_t readUInt32();
    std::string readString();
    void reset();
    void skip(uint16_t n);
    ~StreamReader();
};

#endif