// linhas.h · um arquivo de texto como vetor de linhas
#ifndef LINHAS_H
#define LINHAS_H

// Lê o arquivo inteiro: devolve um vetor de n strings (sem o '\n'), ou NULL
// se não conseguir abrir. Cada linha e o vetor vêm do malloc.
char **le_linhas(const char *nome, int *n);

// Libera as n linhas e o vetor.
void libera_linhas(char **v, int n);

// Grava n linhas no arquivo, uma por linha. Devolve 0 se deu certo.
int grava_linhas(const char *nome, const char *linhas[], int n);

#endif
