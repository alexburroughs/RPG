
#include <unordered_map>
#include <string>
#include "settings.h"

Settings::Settings(std::unordered_map<std::string, std::string>* map) {
    this->map = map;
}

std::string Settings::get_value(std::string key) {
    return (*map)[key];
}

void Settings::set_value(std::string key, std::string value) {
    (*map)[key] = value;
}
