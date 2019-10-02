#ifndef FILELOADER_H
#define FILELOADER_H

#include <string>

class FileLoader {
    public:
        virtual int** loadMap(std::string filename);
};

class BinaryLoader : public FileLoader {
    
};

class TextLoader : public FileLoader {
    public:

};

#endif