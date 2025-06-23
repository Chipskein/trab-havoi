#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "game.h"

int main()
{
    srand(time(NULL));
    printf("Bem-vindo ao jogo Torres de Hanoi Simples!\n");
    printf("Instruções: Mova as peças de uma pilha para outra, respeitando as regras do jogo.\n");
    printf("Selecione a dificuldade do jogo:\n");
    printf("1. Fácil\n");
    printf("2. Médio\n");
    printf("3. Difícil\n");
    int dificuldade;
    scanf("%d", &dificuldade);
    getchar();
    switch (dificuldade) {
        case EASY:
            printf("Dificuldade: Fácil\n");
            break;
        case MEDIUM:
            printf("Dificuldade: Médio\n");
            break;
        case HARD:
            printf("Dificuldade: Difícil\n");
            break;
        default:
            printf("Dificuldade inválida! Usando padrão: Fácil.\n");
            dificuldade = EASY;
    }
    printf("Iniciando o jogo...\n");
    game(dificuldade);
    printf("Obrigado por jogar Torres de Hanoi Simples!\n");
    return 0;
}