// Lista · Módulo 08 · Tipos compostos
// Exercício P0830 · ★★★ · A fila da triagem
//
// No pronto-socorro, a triagem classifica cada paciente por cor, e a fila de
// atendimento é ordenada pela gravidade (vermelho antes de laranja, antes de
// amarelo, antes de verde) e, na mesma cor, pela ordem de chegada:
//
//   typedef enum { VERDE, AMARELO, LARANJA, VERMELHO } Cor;
//   typedef struct { char nome[16]; Cor cor; int chegada; } Paciente;
//
// A fila é um vetor de Paciente mantido SEMPRE em ordem: escreva
// bool entrar(Paciente *fila, int *n, int cap, Paciente p), que encaixa o
// paciente no lugar certo (como no P0514, empurrando quem tem prioridade
// menor), e Paciente atender(Paciente *fila, int *n), que tira o primeiro.
// Simule os eventos abaixo, na ordem, mostrando a fila depois de cada um
// (chegada é o minuto em que o paciente chegou):
//
//   chega Josué (verde, 0)    chega Ana (amarelo, 2)   chega Rui (verde, 3)
//   atende                    chega Lia (vermelho, 7)  chega Téo (amarelo, 8)
//   atende                    atende
//
//   Saída esperada:
//   Chega Josué (verde, min 0)
//     fila: Josué(verde)
//   Chega Ana (amarelo, min 2)
//     fila: Ana(amarelo) Josué(verde)
//   Chega Rui (verde, min 3)
//     fila: Ana(amarelo) Josué(verde) Rui(verde)
//   Atende Ana
//     fila: Josué(verde) Rui(verde)
//   Chega Lia (vermelho, min 7)
//     fila: Lia(vermelho) Josué(verde) Rui(verde)
//   Chega Téo (amarelo, min 8)
//     fila: Lia(vermelho) Téo(amarelo) Josué(verde) Rui(verde)
//   Atende Lia
//     fila: Téo(amarelo) Josué(verde) Rui(verde)
//   Atende Téo
//     fila: Josué(verde) Rui(verde)
//
// Dicas:
// 1. Escreva bool antes(const Paciente *a, const Paciente *b): a tem
//    prioridade se a cor for MAIOR (o enum vai de VERDE = 0 a VERMELHO = 3)
//    ou, na mesma cor, se a chegada for menor.
// 2. Em entrar: i = *n - 1; enquanto i >= 0 e antes(&p, &fila[i]), empurre
//    fila[i] para fila[i + 1]. Uma struct se copia com = inteira.
// 3. Em atender: guarde fila[0], puxe todos uma casa para a frente e faça
//    (*n)--.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

typedef enum { VERDE, AMARELO, LARANJA, VERMELHO } Cor;

typedef struct {
    char nome[16];
    Cor cor;
    int chegada;
} Paciente;

int main(void) {

    return 0;
}
