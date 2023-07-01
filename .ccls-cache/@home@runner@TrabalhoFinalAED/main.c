#include <stdio.h>
#include <stdlib.h>


//Constantes
#define LINHAS 5
#define COLUNAS 5
#define MAX_JOGADORES 2


//Estruturas
typedef struct {
    char nome[50];
    int pontos;
} Arqueologo;

typedef struct {
    char nome[50];
    Arqueologo arqueologos[MAX_JOGADORES];
    int pontos;
} Equipa;


//Método Escavação
void escavar(int terreno[LINHAS][COLUNAS], int linha, int coluna, Equipa* equipa, Arqueologo* arqueologo) {
    if (terreno[linha][coluna] == 0) {
        printf("Nenhum prêmio encontrado.\n");
        equipa->pontos -= 1;
        arqueologo->pontos -= 1;
    } else {
        printf("Parabéns, %s! Encontras te um prêmio com valor %d.\n", arqueologo->nome, terreno[linha][coluna]);
        equipa->pontos += terreno[linha][coluna];
        arqueologo->pontos += terreno[linha][coluna];
        terreno[linha][coluna] = 0;
    }
}


//Método que exibe o terreno
void exibirTerreno(int terreno[LINHAS][COLUNAS], int terrenoVisivel[LINHAS][COLUNAS]) {
    printf("Terreno:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (terrenoVisivel[i][j]) {
                if (terreno[i][j] == 0) {
                    printf("  0 ");
                } else {
                    printf(" %2d ", terreno[i][j]);
                }
            } else {
                printf("  * ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int x = 0;
    int y = 0;
    int jogadas = 0;
    int turno = 1;
    int linha, coluna;

    Equipa equipa1, equipa2;
    equipa1.pontos = 0;
    equipa2.pontos = 0;

    printf("Insira o nome da primeira equipa: ");
    scanf("%s", equipa1.nome);
    printf("Insira o nome da segunda equipa: ");
    scanf("%s", equipa2.nome);

    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("Insira o nome do %dº jogador da %s: ", x = x + 1, equipa1.nome);
        scanf("%s", equipa1.arqueologos[i].nome);
       equipa1.arqueologos[i].pontos = 0;
    }

    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("Insira o nome do %dº jogador da %s: ", y = y + 1, equipa2.nome);
        scanf("%s", equipa2.arqueologos[i].nome);
       equipa2.arqueologos[i].pontos = 0;
    }

 srand(time(0));

    int terreno[LINHAS][COLUNAS];

    //Os prémios são aleatoriamente decididos
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            terreno[i][j] = rand() % 16;
        }
    }

    int terrenoVisivel[LINHAS][COLUNAS] = {0};

    while (jogadas < LINHAS * COLUNAS) {
        exibirTerreno(terreno, terrenoVisivel);

        Equipa* equipaAtual;
        Arqueologo* arqueologoAtual;


      //Decidir quem vai jogar
        int indiceJogadorEquipa1 = (turno - 1) / 2 % MAX_JOGADORES;
        int indiceJogadorEquipa2 = (turno - 1) / 2 % MAX_JOGADORES;

        if (turno % 2 != 0) {
            printf("\n%s, é tua vez de jogar:\n", equipa1.arqueologos[indiceJogadorEquipa1].nome);
            equipaAtual = &equipa1;
            arqueologoAtual = &equipa1.arqueologos[indiceJogadorEquipa1];
           printf("\n%s, tem %d pontos\n\n",equipa1.arqueologos[indiceJogadorEquipa1].nome, arqueologoAtual ->pontos );
        } else {
            printf("\n%s, é tua vez de jogar:\n", equipa2.arqueologos[indiceJogadorEquipa2].nome);
            equipaAtual = &equipa2;
            arqueologoAtual = &equipa2.arqueologos[indiceJogadorEquipa2];
           printf("\n%s, tem %d pontos\n\n",equipa2.arqueologos[indiceJogadorEquipa2].nome, arqueologoAtual ->pontos );
        }

        printf("Digite as coordenadas (linha e coluna) para escavar (0 a 4): ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        if (terrenoVisivel[linha][coluna]) {
            printf("Este espaço já foi escavado! Você perde 5 pontos.\n");
            arqueologoAtual->pontos -= 5;
        } else {
            terrenoVisivel[linha][coluna] = 1;
            escavar(terreno, linha, coluna, equipaAtual, arqueologoAtual);
        }

        jogadas++;
        turno++;
    }


  //Classificacao final do jogo
    printf("\n--- Resultado final ---\n");
    printf("%s: %d pontos\n", equipa1.nome, equipa1.pontos);
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("%s: %d pontos\n", equipa1.arqueologos[i].nome, equipa1.arqueologos[i].pontos);
    }
    printf("%s: %d pontos\n", equipa2.nome, equipa2.pontos);
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("%s: %d pontos\n", equipa2.arqueologos[i].nome, equipa2.arqueologos[i].pontos);
    }

    if (equipa1.pontos > equipa2.pontos) {
        printf("%s venceu!\n", equipa1.nome);
    } else if (equipa2.pontos > equipa1.pontos) {
        printf("%s venceu!\n", equipa2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
