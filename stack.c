#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


Node *create_node(Color color) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed for node.\n");
        exit(1);
    }
    node->color = color;
    node->next = NULL;
    return node;
}

void destroy_node(Node *node) {
    if (node != NULL) {
        free(node);
    }
}

const char* get_color(Color color){
    switch (color) {
        case RED:
            return "RED";
        case GREEN:
            return "GREEN";
        case BLUE:
            return "BLUE";
        case YELLOW:
            return "YELLOW";
        default:
            fprintf(stderr,"UNKNOWN COLOR ");
            break;
    }
}

const char* get_stack_id(StackID id) {
    switch (id) {
        case P1:
            return "P1";
        case P2:
            return "P2";
        case P3:
            return "P3";
        case P4:
            return "P4";
        case T1:
            return "T1";
        case T2:
            return "T2";
        default:
            fprintf(stderr, "UNKNOWN STACK ID ");
            break;
    }
}

void push(Stack *stack, Color color) {
    if (stack->size >= stack->max_size) {
        fprintf(stderr, "Stack %s is full. Cannot push color.\n", get_stack_id(stack->id));
        return;
    }
    Node *new_node = create_node(color);
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

void top(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Empty stack.\n");
        return;
    }
    get_color(stack->top->color);
    printf("Top color of stack %s: %s\n", get_stack_id(stack->id), get_color(stack->top->color));
}

Color pop(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Empty stack.\n");
        return -1;
    }
    Node *node_to_pop = stack->top;
    Color color = node_to_pop->color;
    stack->top = node_to_pop->next;
    destroy_node(node_to_pop);
    stack->size--;
    return color;
}


Stack* init_stack(int max_size,StackID id) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed for stack.\n");
        exit(1);
    }
    stack->top = NULL;
    stack->max_size = max_size;
    stack->size = 0;
    stack->id = id;
    return stack;
}

void destroy_stack(Stack *stack) {
    Node *next_node;
    Node *current = stack->top;
    while (current != NULL) {
        next_node = current->next;
        destroy_node(current);
        current = next_node;
    }
    free(stack);
}

void print_stack(Stack *stack) {
    Node *current = stack->top;
    int pos=0;
    while (current != NULL) {
        printf("Stack %s, Position %d: %s ", get_stack_id(stack->id), ++pos, get_color(current->color));
        current = current->next;
    }
    printf("\n");
}


void reverse_stack(Stack *stack) {
    Node *prev = NULL;
    Node *current = stack->top;
    Node *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;      
        current = next;
    }
    
    stack->top = prev;
}

bool check_if_stack_filled_with_one_color(Stack *stack) {
    if (stack->top == NULL) {
        return false;
    }

    if (stack->size != 3) {
        return false;
    }
    
    Color first_color = stack->top->color;
    Node *current = stack->top->next;
    
    while (current != NULL) {
        if (current->color != first_color) {
            return false;
        }
        current = current->next;
    }
    
    return true;
}