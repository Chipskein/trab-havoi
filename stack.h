#include <stdbool.h>

typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW
} Color;

typedef enum {
    P1,
    P2,
    P3,
    P4,
    T1,
    T2
} StackID;

typedef struct Node {
    Color color;
    struct Node* next;
} Node;


Node *create_node(Color color);

void destroy_node(Node *node);

typedef struct stack {
    Node* top;
    int max_size;
    int size;
    StackID id;
} Stack;

Color pop(Stack *stack);

void push(Stack *stack,Color color);

void top(Stack *stack);// or peek

Stack* init_stack(int max_size,StackID id);

void destroy_stack(Stack* stack);

void print_stack(Stack* stack);


const char* get_color(Color color);

const char* get_stack_id(StackID id);

void reverse_stack(Stack* stack);

bool check_if_stack_filled_with_one_color(Stack* stack);
