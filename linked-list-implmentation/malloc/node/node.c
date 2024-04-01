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

Node *
insert(Node *curr_node, Node *node_to_insert)
{
    node_to_insert->next = curr_node->next;
    curr_node->next = node_to_insert;

    return node_to_insert;
}