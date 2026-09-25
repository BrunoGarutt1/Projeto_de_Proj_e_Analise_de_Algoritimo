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
 
    char *texto;     /* string compactada que o usuario digitou */
    int tamanho;      /* quantidade de caracteres da string */
    int i, k;          /* variaveis usadas nos lacos (loops) */
    char letra;        /* letra que sera repetida */
    int quantidade;    /* quantas vezes a letra deve ser repetida */
 
    /* Verifica se o usuario passou a string como parametro */
    if (argc < 2) {
        printf("Uso: %s <string_compactada>\n", argv[0]);
        return 1;
    }
 
    texto = argv[1];
    tamanho = strlen(texto);
 
    i = 0;    
        /* Percorre a string compactada do inicio ao fim */
    while (i < tamanho) {
 
        /* O primeiro caractere de cada bloco e sempre uma letra */
        letra = texto[i];
        i = i + 1;
 
        /* Agora lemos os numeros que vem depois da letra.
           Pode ser mais de um digito, por isso usamos um laco. */
        quantidade = 0;
        while (i < tamanho && texto[i] >= '0' && texto[i] <= '9') {
            quantidade = quantidade * 10 + (texto[i] - '0');
            i = i + 1;
        }

        /* Imprime a letra "quantidade" vezes seguidas */
        for (k = 0; k < quantidade; k++) {
            printf("%c", letra);
        }
 
        /* Se o proximo caractere for um "-", pulamos ele
           para chegar na proxima letra do bloco seguinte */
        if (i < tamanho && texto[i] == '-') {
            i = i + 1;
        }
    }
 
    printf("\n");
 
    return 0;
}
 