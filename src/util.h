#ifndef UTIL_H
#define UTIL_H

#include "map.h"

mapbits str_to_mapbits(std::string inp) {

    int i(std::stoi(inp));
    mapbits to(0);
    
    if (i <= static_cast<int>(UINT16_MAX) && i >=0) {
        to = static_cast<mapbits>(i);
    }
    else {
        DEBUG("Error: Map value to large for uint16");
        std::exit(1);
    }

    return to;
}

#endif