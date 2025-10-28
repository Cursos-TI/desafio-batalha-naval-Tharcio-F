#include <stdio.h>

// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
#define TAMANHO 10
#define AGUA 0
#define NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar sobreposição e limites
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        if (coluna + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) return 0;
        }
    } else if (orientacao == 'V') { // Vertical
        if (linha + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) return 0;
        }
    } else if (orientacao == 'D') { // Diagonal crescente (ex: [0][0], [1][1])
        if (linha + tamanho > TAMANHO || coluna + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna + i] != AGUA) return 0;
        }
    } else if (orientacao == 'I') { // Diagonal decrescente (ex: [0][9], [1][8])
        if (linha + tamanho > TAMANHO || coluna - tamanho < -1) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna - i] != AGUA) return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    if (podePosicionar(tabuleiro, linha, coluna, tamanho, orientacao)) {
        if (orientacao == 'H') {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha][coluna + i] = NAVIO;
            }
        } else if (orientacao == 'V') {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha + i][coluna] = NAVIO;
            }
        } else if (orientacao == 'D') {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha + i][coluna + i] = NAVIO;
            }
        } else if (orientacao == 'I') {
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[linha + i][coluna - i] = NAVIO;
            }
        }
    } else {
        printf("Erro: Não foi possível posicionar o navio na posição (%d, %d) com orientação %c.\n", linha, coluna, orientacao);
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // 1. Inicializar o tabuleiro com 0s
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar os quatro navios
    // Navio horizontal de tamanho 3
    posicionarNavio(tabuleiro, 1, 2, 3, 'H');

    // Navio vertical de tamanho 4
    posicionarNavio(tabuleiro, 5, 8, 4, 'V');

    // Navio diagonal crescente (da esquerda para a direita e para baixo) de tamanho 3
    posicionarNavio(tabuleiro, 6, 0, 3, 'D');

    // Navio diagonal decrescente (da esquerda para a direita e para cima) de tamanho 3
    posicionarNavio(tabuleiro, 0, 6, 3, 'I');

    // 3. Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

// Sugestão: Expanda o tabuleiro para uma matriz 10x10.
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.