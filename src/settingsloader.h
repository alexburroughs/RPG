#ifndef SETTINGSLOADER_H
#define SETTINGSLOADER_H

#include "reader.h"
#include "settings.h"

class Settingsloader {

    private:
        Reader* reader;
    public:
        Settingsloader(Reader* reader);
        Settings* loadsettings(std::string filename, std::string tag);
};

#endif