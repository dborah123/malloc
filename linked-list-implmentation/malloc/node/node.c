#include "node.h"

Node *
get_next(Node *node) {
    return node->next;
}

Node *
get_end(Node *node) {
    if (node->next == NULL) {
        return node;
    }
    
    return get_end(node->next);
}