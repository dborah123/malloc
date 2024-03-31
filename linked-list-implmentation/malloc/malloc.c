#include "malloc.h"

int
main() {
    printf("\n%ld", sizeof(size_t));
}

void *
malloc(size_t size)
{
    Node *start = get_start();

    void *open_space = get_next_open_mem(start, size);

    return NULL;
}

void
free(void *ptr)
{

}



Node *
get_start()
{
    if (starting_node == NULL)
    {
        starting_node = add_new_block();
    }

    return starting_node;
}

Node *
add_new_block()
{
    // Move the program break by a block
    __uint8_t *program_break = increase_size();

    Node *new_mem_start = (Node*)get_previous_program_break(program_break);

    return new_mem_start;

}

__uint8_t *
increase_size()
{
    __uint8_t *program_break = sbrk(BLOCK_SIZE);

    if (program_break == (__uint8_t*) -1) {
        perror("sbrk");
        exit(1);
        return NULL;
    }

    return program_break;
}

void *
get_next_open_mem(Node *node, size_t size)
{
    // ITERATE THRU NODES

    // If node->next == NULL -> add_new_block
    if (node->next == NULL) {
        return create_new_node(node, size);
    }

    // If node->next - node > size needed -> Insert block here

    // else get_next_open_mem(curr_node->next, size)

    return NULL;
}

Node *
create_new_node(Node *prev_node, size_t size)
{
    Node *new_node_start;
    Node *next_open_place = get_data_end(prev_node, size);

    size_t size_needed = get_total_needed(size);

    if (next_open_place + size_needed > (Node*)sbrk(0))
    {
        new_node_start = add_new_block();
    }
    else
    {
        new_node_start = next_open_place;
    }

    return NULL;
}


