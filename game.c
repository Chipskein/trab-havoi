#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "game.h"

void clear()
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

void print_game_state(
    Stack* sP1,
    Stack* sP2,
    Stack* sP3,
    Stack* sP4,
    Stack* sT1,
    Stack* sT2
)
{
    if (sP1 == NULL || sP2 == NULL || sP3 == NULL || sP4 == NULL) {
        fprintf(stderr, "One or more stacks are NULL.\n");
        return;
    }

    reverse_stack(sP1);
    reverse_stack(sP2);
    reverse_stack(sP3);
    reverse_stack(sP4);

    if(sT1 != NULL && sT2 != NULL) {
        //easy mode
        printf("\n");
        char t1 = (sT1->size == 0) ? ' ' : get_color(sT1->top->color)[0];
        char t2 = (sT2->size == 0) ? ' ' : get_color(sT2->top->color)[0];
        printf("    -----------------   \n");
        printf("    | T1 |     | T2 |\n");
        printf("    | %c  |-----| %c  |\n", t1, t2);
        printf("                       \n\n\n\n");
    } else if(sT1 != NULL) {
        //Medium mode
        printf("\n");
        char t1 = (sT1->size == 0) ? ' ' : get_color(sT1->top->color)[0];
        printf("    -----------------   \n");
        printf("    | T1 |     |    |\n");
        printf("    | %c  |-----|    |\n", t1);
        printf("                       \n\n\n\n");
    } else{
        //Hard mode
        printf("\n");
        printf("    -----------------   \n");
        printf("    |    |     |    |\n");
        printf("    |    |-----|    |\n");
        printf("                       \n\n\n\n");
    }
    

    Node* nodesP1[MAX_SIZE_P_STACK];
    Node* nodesP2[MAX_SIZE_P_STACK];
    Node* nodesP3[MAX_SIZE_P_STACK];
    Node* nodesP4[MAX_SIZE_P_STACK];

    Node* curP1 = sP1->top;
    Node* curP2 = sP2->top;
    Node* curP3 = sP3->top;
    Node* curP4 = sP4->top;
    for(int i=0;i<MAX_SIZE_P_STACK;i++){
        nodesP1[i] = curP1;
        nodesP2[i] = curP2;
        nodesP3[i] = curP3;
        nodesP4[i] = curP4;
        if (curP1) curP1 = curP1->next;
        if (curP2) curP2 = curP2->next;
        if (curP3) curP3 = curP3->next;
        if (curP4) curP4 = curP4->next;
    }
    for (int i = MAX_SIZE_P_STACK - 1; i >= 0; i--) {
        char colorP1 = (nodesP1[i] != NULL) ? get_color(nodesP1[i]->color)[0] : ' ';
        char colorP2 = (nodesP2[i] != NULL) ? get_color(nodesP2[i]->color)[0] : ' ';
        char colorP3 = (nodesP3[i] != NULL) ? get_color(nodesP3[i]->color)[0] : ' ';
        char colorP4 = (nodesP4[i] != NULL) ? get_color(nodesP4[i]->color)[0] : ' ';
        printf("    | %c | %c | %c | %c |   \n", colorP1, colorP2, colorP3, colorP4);
    }
    printf("    -----------------   \n");
    printf("    | %s| %s| %s| %s|   \n", get_stack_id(sP1->id), get_stack_id(sP2->id), get_stack_id(sP3->id), get_stack_id(sP4->id));

    printf("\n\n\n\n\n\n");

    reverse_stack(sP1);
    reverse_stack(sP2);
    reverse_stack(sP3);
    reverse_stack(sP4);
};


Color get_random_color()
{
    return rand() % 4;
}

bool is_color_avaliable(int color_count[], int max_por_cor) {
    for (int c = 0; c < COLOR_COUNT; c++) {
        if (color_count[c] < max_por_cor) {
            return true;
        }
    }
    return false;
}

void fill_stacks(Stack *stacks[], int size)
{
    int color_count[COLOR_COUNT] = {0};

    for (int i = 0; i < size; i++)
    {
        if (!is_color_avaliable(color_count, MAX_SIZE_P_STACK-1)) break;
        
        if (stacks[i] == NULL) continue;

        int remaining_slots = stacks[i]->max_size;

        Color base_color;
        
        while (remaining_slots > 0)
        {
            if (!is_color_avaliable(color_count, MAX_SIZE_P_STACK-1)) {
                break;
            }

            Color color = get_random_color();

            if (color_count[color] < MAX_SIZE_P_STACK-1)
            {
                push(stacks[i], color);
                color_count[color]++;
                remaining_slots--;
            }
        }
    }
}

bool check_if_game_over(Stack *stacks[], int size)
{
    for (int i = 0; i < size; i++)
    {
        Stack *stack = stacks[i];
        if (stack != NULL && stack->size > 0)
        {
            bool pass = check_if_stack_filled_with_one_color(stack);
            if (!pass)
                return false;
        }
    }
    return true;
}

StackID string_to_stack_id(const char* str) {
    if (strcmp(str, "P1") == 0 || strcmp(str, "p1") == 0) return P1;
    if (strcmp(str, "P2") == 0 || strcmp(str, "p2") == 0) return P2;
    if (strcmp(str, "P3") == 0 || strcmp(str, "p3") == 0) return P3;
    if (strcmp(str, "P4") == 0 || strcmp(str, "p4") == 0) return P4;
    if (strcmp(str, "T1") == 0 || strcmp(str, "t1") == 0) return T1;
    if (strcmp(str, "T2") == 0 || strcmp(str, "t2") == 0) return T2;
    return -1;
}

Stack* get_stack_from_user(Stack* stacks[], int size) {
    char input[10];
    printf("Digite o ID da pilha (P1, P2, P3, P4, T1, T2): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    StackID id = string_to_stack_id(input);
    if (id == -1) {
        printf("ID inválido! Tente novamente.\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        if (stacks[i] == NULL) continue;
        if (stacks[i]->id == id) {
            return stacks[i];
        }
    }

    printf("Pilha com ID %s não encontrada!\n", input);
    return NULL;
}

void game(Difficulty difficulty){
    
    Stack *sT1 = NULL;
    Stack *sT2 = NULL;

    Stack *sP1 = init_stack(MAX_SIZE_P_STACK, P1);
    Stack *sP2 = init_stack(MAX_SIZE_P_STACK, P2);
    Stack *sP3 = init_stack(MAX_SIZE_P_STACK, P3);
    Stack *sP4 = init_stack(MAX_SIZE_P_STACK, P4);


    if (difficulty == EASY) {
        sT1 = init_stack(MAX_SIZE_T_STACK, T1);
        sT2 = init_stack(MAX_SIZE_T_STACK, T2);
    } else if (difficulty == MEDIUM) {
        sT1 = init_stack(MAX_SIZE_T_STACK, T1);
    }
    

    Stack *stacksP[] = {sP1, sP2, sP3, sP4};
    size_t sizeP = sizeof(stacksP) / sizeof(stacksP[0]);

    Stack *stacks[] = {sP1, sP2, sP3, sP4, sT1, sT2};
    size_t size = sizeof(stacks) / sizeof(stacks[0]);


    printf("Torres de Hanoi Simples\n");
    fill_stacks(stacksP, sizeP);
    double duracao;
    int turn = 0;
    time_t inicio_turno, fim_turno;
    inicio_turno = time(NULL);
    
    while(!check_if_game_over(stacksP,sizeP)){
        clear();
        print_game_state(sP1, sP2, sP3, sP4, sT1, sT2);
    
        Stack* stack_from = NULL;
        while (stack_from == NULL) {
            printf("Escolha uma pilha de origem:\n");
            stack_from = get_stack_from_user(stacks, size);
        }

        if (stack_from->size == 0) {
            printf("A pilha escolhida está vazia!\n");
            turn++;
            continue;
        }
        
        Color color = pop(stack_from);
        printf("Pop: %s\n", get_color(color));
        
        Stack* stack_to = NULL;
        while (stack_to == NULL) {
            printf("Escolha uma pilha de destino:\n");
            stack_to = get_stack_from_user(stacks, size);
        }

        if (stack_to->size >= stack_to->max_size) {
            printf("A pilha de destino está cheia!\n");
            push(stack_from, color);
            
            turn++;
            continue;
        }
        
        push(stack_to, color);
        printf("Push: %s\n", get_color(color));
        turn++;
    }
    fim_turno = time(NULL);
    
    print_game_state(sP1, sP2, sP3, sP4, sT1, sT2);
    printf("Fim de jogo! Você venceu em %d turnos!\n", turn);
    duracao = difftime(fim_turno, inicio_turno);
    printf("Duração do jogo: %.2f segundos\n", duracao);
    
    destroy_stack(sP1);
    destroy_stack(sP2);
    destroy_stack(sP3);
    destroy_stack(sP4);

    if (sT1!=NULL) destroy_stack(sT1);
    if (sT2!=NULL) destroy_stack(sT2);
}
