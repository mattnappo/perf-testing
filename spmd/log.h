#ifndef __LOG_H
#define __LOG_H

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_ERROR 3

#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define DYEL "\e[1;39m"
#define RRST "\e[0m"

#define LOG(level, color, label, ...) do {          \
    if (LOG_LEVEL <= level) {                       \
        printf("["color label RRST"] "__VA_ARGS__); \
    }                                               \
} while (0)

#define LOG_DEBUG(...) LOG(LOG_LEVEL_DEBUG, BBLU, "DEBUG", __VA_ARGS__)
#define LOG_INFO(...)  LOG(LOG_LEVEL_INFO,  BGRN, "INFO",  __VA_ARGS__)
#define LOG_WARN(...)  LOG(LOG_LEVEL_WARN,  BYEL, "WARN",  __VA_ARGS__)
#define LOG_ERROR(...) LOG(LOG_LEVEL_ERROR, BRED, "ERROR", __VA_ARGS__)

#endif
