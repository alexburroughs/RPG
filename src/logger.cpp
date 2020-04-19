#include <string>
#include <fstream>
#include <chrono>

void log(std::string content, std::string context) {

    std::locale::global(std::locale("en_US.UTF8"));
    std::time_t t = std::time(nullptr);
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), ((std::string)"%F %T ["+ context +"]:").c_str(), std::localtime(&t))) {
    
        std::ofstream __outfile;
        __outfile.open("process.log", std::ios_base::app);
        __outfile << mbstr + content << "\n";
        __outfile.close();
    }
}