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
Node *insert(Node *curr_node, Node *node_to_insert);

/* Constants */
#define NODE_SIZE sizeof(Node)


