#include "malloc.h"

int
main() {
    printf("\n%ld", sizeof(size_t));
}

void *
malloc(size_t size)
{
    Node *start = get_start();

    Node *open_space = create_new_node(start, size);

    return (void*) open_space;
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

Node *
create_new_node(Node *curr_node, size_t size)
{
    // ITERATE THRU NODES

    // If this is the last node, create a node at the end
    if (curr_node->next == NULL)
    {
        return create_at_end(curr_node, size);
    }

    // If there is room in between nodes
    if (curr_node->next - curr_node > get_total_needed(size))
    {
        return insert(curr_node, get_data_end(curr_node, size));
    }

    // else get_next_open_mem(curr_node->next, size)
    return create_new_node(curr_node->next, size);
}

Node *
create_at_end(Node *curr_node, size_t size)
{
    Node *new_node_start;
    Node *next_open_place = get_data_end(curr_node, size);

    size_t size_needed = get_total_needed(size);

    // If the size needed goes beyond the page break, extend it
    if (next_open_place + size_needed > (Node*)sbrk(0))
    {
        new_node_start = add_new_block();
    }
    else
    {
        new_node_start = next_open_place;
    }

    return insert(curr_node, new_node_start);
}


