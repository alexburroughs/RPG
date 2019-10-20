#include "settingsloader.h"
#include "settings.h"
#include "reader.h"
#include <unordered_map>
#include <string>

Settingsloader::Settingsloader(Reader* reader) {
    this->reader = reader;
}

Settings* Settingsloader::loadsettings(std::string filename) {

    std::unordered_map<std::string, std::string>* map = reader->readkv(filename);

    return new Settings(map);
}