#include <string>
#include <fstream>

void log(std::string content) {

    std::ofstream __outfile;
    __outfile.open("process.log", std::ios_base::app);
    __outfile << content << "\n";
}