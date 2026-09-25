#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[]) {
 
    char *texto;        /* string que o usuario digitou */
    int tamanho;         /* quantidade de caracteres da string */
    int i, j;             /* variaveis usadas para percorrer a string */
    int contador;         /* conta quantas vezes um caractere se repete */
    int primeiroBloco;   /* usada so para saber se ja imprimimos algo antes */
 
    /* Verifica se o usuario passou a string como parametro */
    if (argc < 2) {
        printf("Uso: %s <string>\n", argv[0]);
        return 1;
    }

    texto = argv[1];
    tamanho = strlen(texto);
 
    i = 0;
    primeiroBloco = 1; /* 1 = verdadeiro, ainda nao imprimimos nenhum bloco */
 
    /* Percorre a string do inicio ao fim */
    while (i < tamanho) {
 
        contador = 1; /* ja estamos contando o caractere da posicao i */
 
        /* Enquanto o proximo caractere for igual ao atual, soma 1 no contador */
        j = i + 1;
        while (j < tamanho && texto[j] == texto[i]) {
            contador = contador + 1;
            j = j + 1;
        }
 
        /* Imprime um "-" antes de cada bloco, menos no primeiro */
        if (primeiroBloco == 0) {
            printf("-");
        }
 
        /* Imprime o caractere seguido de quantas vezes ele se repetiu */
        printf("%c%d", texto[i], contador);
 
        primeiroBloco = 0;
 
        /* Pula para a posicao logo depois do bloco que acabamos de contar */
        i = i + contador;
    }