
#include "../../library/common.h"
#include "./node/node.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// === APIs ===
void *malloc(size_t size);
void free(void *ptr);


// === HELPERS ===

/**
 * DESCRIPTION: Adds a new block of memory to the program break
 * RETURNS: The pointer to the Node at the start of the newly allocated 
 *          of memory
 */
Node *add_new_block();

/**
 * DESCRIPTION: Increases the size of the heap by a block
 * RETURNS: The end of the new program break
 */
__uint8_t *increase_size();

/**
 * DESCRIPTION: Gets the starting node for malloc
 * RETURN: The startig node 
 */
Node *get_start();

Node *create_new_node(Node *curr_node, size_t size);

Node *create_at_end(Node *curr_node, size_t size);


// === MACROS ===
#define get_data_start(node) (node+NODE_SIZE)
#define get_data_end(node,size) (get_data_start(node)+size)
#define get_total_needed(size) (sizeof(Node)+size)
#define get_previous_program_break(program_break) (program_break-BLOCK_SIZE)

// === START ===
Node *starting_node;
 
