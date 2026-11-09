// pombal.h · pigeonhole sort e ordenações por nota, estáveis ou não
#ifndef POMBAL_H
#define POMBAL_H

typedef struct {
    char nome[16];
    int nota;  // a chave, de 0 a 10
    int turma; // uma segunda chave, para os exemplos de chave composta
} Aluno;

// pigeonhole sort pela nota, que tem que estar entre min e max.
// Estável: quem chega primeiro na casa sai primeiro. 0 se ok, -1 sem memória
int pb_pigeonhole(Aluno *v, int n, int min, int max);

void pb_selecao(Aluno *v, int n); // por nota; NÃO é estável
void pb_insercao(Aluno *v, int n); // por nota; estável

void pb_mostra(const Aluno *v, int n); // nome(nota), numa linha

#endif
