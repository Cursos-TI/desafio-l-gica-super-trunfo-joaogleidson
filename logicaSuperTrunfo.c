#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numeroCarta) {
    printf("\nCadastro da Carta %d\n", numeroCarta);
    printf("Digite o estado: ");
    scanf(" %[^\n]s", carta->estado);
    printf("Digite o codigo da carta: ");
    scanf(" %[^\n]s", carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", carta->nome);
    printf("Digite a populacao: ");
    scanf("%d", &carta->populacao);
    printf("Digite a area (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB (em milhoes): ");
    scanf("%f", &carta->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);

    carta->densidade = (float)carta->populacao / carta->area;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numeroCarta) {
    printf("\nCarta %d - %s\n", numeroCarta, carta.nome);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhoes\n", carta.pib);
    printf("Pontos turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidade);
}

// Função para exibir o menu de atributos e retornar a escolha
int exibirMenuAtributos() {
    int escolha;
    printf("\nEscolha um atributo para comparacao:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Populacional\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha);
    return (escolha >= 1 && escolha <= 5) ? escolha : 1; // Operador ternário para validação básica
}

// Função para comparar dois atributos entre cartas
void compararDoisAtributos(Carta carta1, Carta carta2, int attr1, int attr2) {
    char *atributos[] = {"populacao", "area", "pib", "pontos_turisticos", "densidade"};
    float valor1_attr1, valor1_attr2, valor2_attr1, valor2_attr2;
    int pontos_carta1 = 0, pontos_carta2 = 0;

    // Mapeia os valores dos atributos escolhidos
    valor1_attr1 = (attr1 == 1) ? carta1.populacao : (attr1 == 2) ? carta1.area : 
                   (attr1 == 3) ? carta1.pib : (attr1 == 4) ? carta1.pontos_turisticos : carta1.densidade;
    valor2_attr1 = (attr1 == 1) ? carta2.populacao : (attr1 == 2) ? carta2.area : 
                   (attr1 == 3) ? carta2.pib : (attr1 == 4) ? carta2.pontos_turisticos : carta2.densidade;
    valor1_attr2 = (attr2 == 1) ? carta1.populacao : (attr2 == 2) ? carta1.area : 
                   (attr2 == 3) ? carta1.pib : (attr2 == 4) ? carta1.pontos_turisticos : carta1.densidade;
    valor2_attr2 = (attr2 == 1) ? carta2.populacao : (attr2 == 2) ? carta2.area : 
                   (attr2 == 3) ? carta2.pib : (attr2 == 4) ? carta2.pontos_turisticos : carta2.densidade;

    printf("\nComparando %s x %s\n", carta1.nome, carta2.nome);
    printf("Atributo 1: %s\n", atributos[attr1 - 1]);
    printf("Atributo 2: %s\n", atributos[attr2 - 1]);

    // Comparação do primeiro atributo
    if (attr1 == 5) { // Densidade: menor valor vence
        pontos_carta1 += (valor1_attr1 < valor2_attr1) ? 1 : 0;
        pontos_carta2 += (valor2_attr1 < valor1_attr1) ? 1 : 0;
    } else { // Outros atributos: maior valor vence
        pontos_carta1 += (valor1_attr1 > valor2_attr1) ? 1 : 0;
        pontos_carta2 += (valor2_attr1 > valor1_attr1) ? 1 : 0;
    }

    // Comparação do segundo atributo
    if (attr2 == 5) { // Densidade: menor valor vence
        pontos_carta1 += (valor1_attr2 < valor2_attr2) ? 1 : 0;
        pontos_carta2 += (valor2_attr2 < valor1_attr2) ? 1 : 0;
    } else { // Outros atributos: maior valor vence
        pontos_carta1 += (valor1_attr2 > valor2_attr2) ? 1 : 0;
        pontos_carta2 += (valor2_attr2 > valor1_attr2) ? 1 : 0;
    }

    // Resultado final com lógica aninhada e ternário
    printf("\nResultado:\n");
    pontos_carta1 > pontos_carta2 ? printf("Vencedora: %s (%d x %d)\n", carta1.nome, pontos_carta1, pontos_carta2) :
    pontos_carta2 > pontos_carta1 ? printf("Vencedora: %s (%d x %d)\n", carta2.nome, pontos_carta2, pontos_carta1) :
    printf("Empate! (%d x %d)\n", pontos_carta1, pontos_carta2);
}

// Menu principal
void menuPrincipal() {
    Carta carta1, carta2;
    int opcao, attr1, attr2;

    do {
        printf("\n=== Super Trunfo - Nivel Mestre ===\n");
        printf("1. Cadastrar Cartas\n");
        printf("2. Exibir Cartas\n");
        printf("3. Comparar Cartas\n");
        printf("4. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCarta(&carta1, 1);
                cadastrarCarta(&carta2, 2);
                printf("Cartas cadastradas com sucesso!\n");
                break;
            case 2:
                exibirCarta(carta1, 1);
                exibirCarta(carta2, 2);
                break;
            case 3:
                attr1 = exibirMenuAtributos();
                attr2 = exibirMenuAtributos();
                compararDoisAtributos(carta1, carta2, attr1, attr2);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);
}

int main() {
    menuPrincipal();
    return 0;
}