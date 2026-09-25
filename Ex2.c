/*
 * Disciplina: Projeto e Analise de Algoritmos
 * Prof. Antonio Luiz Basile - Universidade Presbiteriana Mackenzie
 *
 * Aluno: Bruno Matheus Garutti Pinto  * RA: 10736747
 * Aluno: Gabrieli Souza Santos   * RA: 10732702
 * Aluno: Stella Faria Viera  * RA: 10732983
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
 