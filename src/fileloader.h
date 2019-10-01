class FileLoader {
    public:
        virtual int** loadMap() {};
};

class BinaryLoader : public FileLoader {
    
};

class TextLoader : public FileLoader {
    public:

};