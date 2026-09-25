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
 