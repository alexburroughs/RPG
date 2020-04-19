
#include <unordered_map>
#include <string>
#include <utility>
#include "settings.h"

Settings::Settings(std::unordered_map<std::string, std::string>* map) {
    this->map = map;
}

std::string Settings::get_value(std::string key) {
    return (*map)[key];
}

std::string Settings::get_value_at(std::string key, int32_t pos) {

}

void Settings::set_value(std::string key, std::string value) {
    (*map)[key] = value;
}

void Settings::set_value_at(std::string key, int32_t pos, std::string value) {

}

std::pair<std::unordered_map<std::string, std::string>::iterator, 
 std::unordered_map<std::string, std::string>::iterator> Settings::get_iter() {
    std::unordered_map<std::string, std::string>::iterator b = map->begin();
    std::unordered_map<std::string, std::string>::iterator e = map->end();
    
    std::pair<std::unordered_map<std::string, std::string>::iterator,
    std::unordered_map<std::string, std::string>::iterator> tmp = std::make_pair(b,e);

    return tmp;
}
