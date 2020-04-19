#include "settingsloader.h"
#include "settings.h"
#include "reader.h"
#include <unordered_map>
#include <string>

Settingsloader::Settingsloader(Reader* reader) {
    this->reader = reader;
}

Settings* Settingsloader::loadsettings(std::string filename, std::string tag) {

    std::unordered_map<std::string, std::string>* map = reader->readkv(filename, tag);

    return new Settings(map);
}