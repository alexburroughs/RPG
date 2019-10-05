#include "streamreader.h"


char* _array;
uint32_t _position;


StreamReader::StreamReader(char* array) {
    _array = array;
    _position = 0;
}

char StreamReader::read() {
    if (_array[_position] == '\0')
        return '\0';
    
    return _array[_position++];
}

char* StreamReader::read(uint16_t n) {
    char* buffer = new char[n]();
    for (int i = 0; i < n; i++)
        buffer[i] = read();
    
    return buffer;
}

int8_t StreamReader::readInt8() {
    return int8_t((read() << 4) | read());
}

int16_t StreamReader::readInt16() {
    return int16_t((readInt8() << 8) | readInt8());
}
int32_t StreamReader::readInt32() {
    return int32_t((readInt8() << 16) | readInt16());
}

uint8_t StreamReader::readUInt8() {
    return uint8_t((read() << 4) | read());
}

uint16_t StreamReader::readUInt16() {
    return uint16_t((readUInt8() << 8) | readUInt8());
}

uint32_t StreamReader::readUInt32() {
    return uint32_t((readUInt16() << 16) | readUInt16());
}

std::string StreamReader::readString() {
    int32_t size = readUInt32();
    return std::string(read(size));
}

void StreamReader::reset() {
    _position = 0;
}

void StreamReader::skip(uint16_t n) {
    _position += n;
}

StreamReader::~StreamReader() { }