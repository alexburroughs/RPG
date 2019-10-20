#ifndef SETTINGS_H
#define SETTINGS_H

#include <unordered_map>
#include <string>

class Settings {
    private:
        std::unordered_map<std::string, std::string>* map;
    public:
        Settings(std::unordered_map<std::string, std::string>* map);
        std::string get_value(std::string key);
        void set_value(std::string key, std::string value); 
};

#endif