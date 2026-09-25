/*
 * Disciplina: Projeto e Analise de Algoritmos
 * Prof. Antonio Luiz Basile - Universidade Presbiteriana Mackenzie
 *
 * Aluno: Bruno Matheus Garutti Pinto  * RA: 10736747
 * Aluno: Gabrieli Souza Santos   * RA: 10732702
 * Aluno: Stella Farias Viera  * RA: 10732983
 *
 */

#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <string>\n", argv[0]);
        return 1;
    }
 
    char *s = argv[1];
    int n = (int) strlen(s);
    int i = 0;
    int primeiroBloco = 1;
    while (i < n) {
        int restante = n - i;
 
        int melhorP = 1;      /* tamanho do padrao escolhido */
        int melhorK = 1;      /* numero de repeticoes do padrao escolhido */
        int melhorCobertura = 1; /* melhorP * melhorK */
 
        /* testa tamanhos de padrao p que cabem pelo menos 2 vezes no
           restante da string (k >= 2); um padrao com apenas 1 copia
           nao e compactacao nenhuma, entao esse caso e ignorado aqui
           e tratado pelo valor padrao (melhorP = melhorK = 1) */
        for (int p = 1; p <= restante / 2; p++) {
            int k = 1;
 
            /* conta quantas copias consecutivas de s[i..i+p) existem */
            while (1) {
                int proximoInicio = i + k * p;
                if (proximoInicio + p > n) {
                    break;
                }
                if (strncmp(&s[i], &s[proximoInicio], (size_t) p) == 0) {
                    k++;
                } else {
                    break;
                }
            }
 
            if (k < 2) {
                continue; /* nao repetiu, nao conta como padrao */
            }
 
            int cobertura = p * k;
 
            /* so troca se cobrir estritamente mais caracteres,
               garantindo que em empates o menor p seja mantido
               (pois p cresce em ordem crescente no laco) */
            if (cobertura > melhorCobertura) {
                melhorCobertura = cobertura;
                melhorP = p;
                melhorK = k;
            }
        }
 
        if (!primeiroBloco) {
            printf("-");
        }
        for (int j = 0; j < melhorP; j++) {
            putchar(s[i + j]);
        }
        printf("%d", melhorK);
        primeiroBloco = 0;
 
        i += melhorCobertura;
    }
 
    printf("\n");
    return 0;
}