#ifndef DEBUG_H
#define DEBUG_H
#define DEBUG_MODE
#ifdef DEBUG_MODE
#define DEBUG(x) printf(x);
#else
#define DEBUG(x)
#endif
#endif