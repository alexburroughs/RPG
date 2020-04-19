#ifndef SETTINGS_H
#define SETTINGS_H

#include <unordered_map>
#include <string>
#include <utility>

class Settings {
    private:
        std::unordered_map<std::string, std::string>* map;
    public:
        Settings(std::unordered_map<std::string, std::string>* map);
        std::string get_value(std::string key);
        std::string get_value_at(std::string key, int32_t pos);
        void set_value(std::string key, std::string value);
        void set_value_at(std::string key, int32_t pos, std::string value);

        std::pair<std::unordered_map<std::string, std::string>::iterator, 
        std::unordered_map<std::string, std::string>::iterator> get_iter();
};

#endif