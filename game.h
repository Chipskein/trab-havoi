#include "stack.h"


#define MAX_SIZE_P_STACK 4

#define MAX_SIZE_T_STACK 1

#define COLOR_COUNT 4


typedef enum {
    EASY = 1,
    MEDIUM,
    HARD
} Difficulty;

void clear();

void print_game_state(Stack* sp1,Stack* sp2,Stack* sp3,Stack* sp4,Stack* st1,Stack* st2);

Color get_random_color();

bool is_color_avaliable(int color_count[], int max_por_cor);

void fill_stacks(Stack *stacks[], int size);

bool check_if_game_over(Stack *stacks[], int size);

StackID string_to_stack_id(const char* str);

Stack* get_stack_from_user(Stack* stacks[], int size);

void game(Difficulty difficulty);
