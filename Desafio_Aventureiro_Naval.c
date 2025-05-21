#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- Navio Horizontal ---
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
        } else {
            printf("Erro: sobreposição no navio horizontal.\n");
        }
    } else {
        printf("Erro: navio horizontal fora do limite.\n");
    }

    // --- Navio Vertical ---
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
        } else {
            printf("Erro: sobreposição no navio vertical.\n");
        }
    } else {
        printf("Erro: navio vertical fora do limite.\n");
    }

    // --- Navio Diagonal Principal (↘) ---
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
        } else {
            printf("Erro: sobreposição no navio diagonal principal.\n");
        }
    } else {
        printf("Erro: navio diagonal principal fora do limite.\n");
    }

    // --- Navio Diagonal Secundária (↙) ---
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
        } else {
            printf("Erro: sobreposição no navio diagonal secundária.\n");
        }
    } else {
        printf("Erro: navio diagonal secundária fora do limite.\n");
    }

    // --- Impressão do tabuleiro ---
    printf("\n    ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
