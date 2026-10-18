// 0125 · Subconjuntos
// Exercício E748 · ★★☆
//
// Uma tia doou seis brinquedos para os sobrinhos Ana e Beto dividirem:
//
//   bicicleta R$ 500   patinete R$ 300   skate R$ 250
//   patins R$ 200      bola R$ 150       livro R$ 100
//
// O programa abaixo já mostra TODAS as 64 divisões: cada subconjunto vai
// para a Ana e o resto (o complemento) vai para o Beto. Rode e veja. Depois
// estenda o programa para mostrar só as divisões JUSTAS (os dois recebem o
// mesmo valor) e, no fim, quantas são. Para não mostrar a mesma divisão duas
// vezes (com os nomes trocados), mostre só as que dão a bicicleta para a Ana.
//
//   Saída esperada:
//   Ana: bicicleta skate | Beto: patinete patins bola livro
//   Ana: bicicleta bola livro | Beto: patinete skate patins
//   2 divisões justas
//
// Dicas:
// 1. O total dos seis é R$ 1500, então cada um precisa de R$ 750.
// 2. Na folha da recursão (i == N), some o valor da Ana antes de mostrar.
//    Se não der 750, ou se da_ana[0] for false, volte sem mostrar.
// 3. Use um contador global para o total de divisões justas.
// 4. Resposta esperada: as 3 linhas acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdbool.h>
#include <stdio.h>

#define N 6

const char *nomes[N] = {"bicicleta", "patinete", "skate", "patins", "bola", "livro"};
const int valores[N] = {500, 300, 250, 200, 150, 100};
bool da_ana[N];

void mostra_lado(bool ana) {
    for (int j = 0; j < N; j++) {
        if (da_ana[j] == ana) {
            printf(" %s", nomes[j]);
        }
    }
}

void divide(int i) {
    if (i == N) {
        printf("Ana:");
        mostra_lado(true);
        printf(" | Beto:");
        mostra_lado(false);
        printf("\n");
        return;
    }
    da_ana[i] = true;  // o brinquedo i vai para a Ana
    divide(i + 1);
    da_ana[i] = false; // o brinquedo i vai para o Beto
    divide(i + 1);
}

int main(void) {
    divide(0);
    return 0;
}
