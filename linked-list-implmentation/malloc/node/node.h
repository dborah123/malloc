#include <stddef.h>

/* Structs */
typedef struct Node Node;
struct Node {
    struct Node *next;
    size_t size;
};

/* Node Helper Functions */
Node *get_next();
Node *get_end();

/* Constants */
#define NODE_SIZE sizeof(Node)


