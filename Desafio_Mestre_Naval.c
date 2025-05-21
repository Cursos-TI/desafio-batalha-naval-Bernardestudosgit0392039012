#include <stdio.h>
#include <stdlib.h>  // Incluído para uso de abs()

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para sobrepor uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTabuleiro = origemLinha - 2 + i;
                int colunaTabuleiro = origemColuna - 2 + j;
                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- Colocação dos navios ---
    // Horizontal
    int linhaHorizontal = 2, colunaHorizontal = 4;
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
            }
        }
    }

    // Vertical
    int linhaVertical = 5, colunaVertical = 7;
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
            }
        }
    }

    // Diagonal Principal ↘
    int linhaDiagonal1 = 0, colunaDiagonal1 = 0;
    if (linhaDiagonal1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonal1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = NAVIO;
            }
        }
    }

    // Diagonal Secundária ↙
    int linhaDiagonal2 = 0, colunaDiagonal2 = 9;
    if (linhaDiagonal2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaDiagonal2 - (TAMANHO_NAVIO - 1) >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = NAVIO;
            }
        }
    }

    // --- Matrizes de habilidades ---
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Cone
    for (int i = 0; i < 5; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            if (j >= 0 && j < 5)
                cone[i][j] = 1;
        }
    }

    // Cruz
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1;
        cruz[i][2] = 1;
    }

    // Octaedro (losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // --- Aplicação das habilidades no tabuleiro ---
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      // Cruz em (7,2)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro em (7,7)

    // --- Impressão do tabuleiro ---
    printf("\n    ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf(" ~"); // Água
            else if (tabuleiro[i][j] == NAVIO)
                printf(" N"); // Navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf(" *"); // Habilidade
        }
        printf("\n");
    }

    return 0;
}
