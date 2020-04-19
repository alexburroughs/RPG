#ifndef DEBUG_H
#define DEBUG_H
#include "logger.h"
#define DEBUG_MODE
#ifdef DEBUG_MODE
#define DEBUG(x) log(x, "INFO");
#define ERROR(x) log(x, "ERROR");
#else
#define DEBUG(x)
#endif
#endif