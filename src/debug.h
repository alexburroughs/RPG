#ifndef DEBUG_H
#define DEBUG_H
#include "logger.h"
#define DEBUG_MODE
#ifdef DEBUG_MODE
#define DEBUG(x) log(x);
#else
#define DEBUG(x)
#endif
#endif