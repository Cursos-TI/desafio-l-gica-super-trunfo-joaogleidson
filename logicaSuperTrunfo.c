#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 10
#define MAX_ATRIBUTOS 5

// Estrutura para representar uma carta
typedef struct {
    char nome[50];
    int atributos[MAX_ATRIBUTOS];
} Carta;

// Função para comparar duas cartas com base em dois atributos
void compararCartas(Carta c1, Carta c2, int attr1, int attr2) {
    int resultado1 = (c1.atributos[attr1] > c2.atributos[attr1]) ? 1 : (c1.atributos[attr1] < c2.atributos[attr1]) ? -1 : 0;
    int resultado2 = (c1.atributos[attr2] > c2.atributos[attr2]) ? 1 : (c1.atributos[attr2] < c2.atributos[attr2]) ? -1 : 0;
    
    printf("\nComparando %s vs %s:\n", c1.nome, c2.nome);
    
    if (resultado1 + resultado2 > 0) {
        printf("Vencedor: %s\n", c1.nome);
    } else if (resultado1 + resultado2 < 0) {
        printf("Vencedor: %s\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta cartas[MAX_CARTAS];
    int numCartas = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar carta\n");
        printf("2. Comparar cartas\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        if (opcao == 1) {
            if (numCartas < MAX_CARTAS) {
                printf("Nome da carta: ");
                fgets(cartas[numCartas].nome, 50, stdin);
                cartas[numCartas].nome[strcspn(cartas[numCartas].nome, "\n")] = 0;
                for (int i = 0; i < MAX_ATRIBUTOS; i++) {
                    printf("Atributo %d: ", i + 1);
                    scanf("%d", &cartas[numCartas].atributos[i]);
                }
                numCartas++;
            } else {
                printf("Limite de cartas atingido!\n");
            }
        } else if (opcao == 2) {
            if (numCartas < 2) {
                printf("Cadastre pelo menos duas cartas antes de comparar!\n");
                continue;
            }
            int c1, c2, attr1, attr2;
            printf("Escolha duas cartas (0-%d): ", numCartas - 1);
            scanf("%d %d", &c1, &c2);
            printf("Escolha dois atributos (1-%d): ", MAX_ATRIBUTOS);
            scanf("%d %d", &attr1, &attr2);
            compararCartas(cartas[c1], cartas[c2], attr1 - 1, attr2 - 1);
        }
    } while (opcao != 3);

    printf("Encerrando programa...\n");
    return 0;
}
