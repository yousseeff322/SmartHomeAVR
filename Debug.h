#ifndef DEBUG_H_
#define DEBUG_H_

#define debug  

#define DPRINTF(debug_level, ...) do { \
                                    if (debug_level > 1) { \
                                        printf("@ FUNC: %s , FILE: %s , LINE %d ", __func__, __FILE__, __LINE__); \
                                        printf(">>\t"); \
                                        printf(__VA_ARGS__); \
                                    }} \
                                } while(0)


#endif  