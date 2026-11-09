// Lista · Módulo 06 · Ponteiros
// Exercício P0609 · ★☆☆ · Uma função que mostra qualquer coisa
//
// O painel do posto mostra dados de tipos diferentes. Escreva
//
//   void mostrar(const char *rotulo, const void *p, char tipo)
//
// em que tipo diz o que existe no endereço p: 'i' (int), 'd' (double),
// 'c' (char) ou 's' (string). A função converte p para o tipo certo antes de
// ler. No main, mostre as quatro variáveis abaixo com ela:
//
//   int bomba = 3;
//   double litro = 6.29;
//   char combustivel = 'G';
//   char frentista[] = "Rosinete";
//
//   Saída esperada:
//   Bomba:       3
//   Litro: R$    6.29
//   Tipo:        G
//   Frentista:   Rosinete
//
// Dicas:
// 1. Um void * não pode ser lido direto: *p não compila. Converta antes:
//    *(const int *) p, *(const double *) p, *(const char *) p.
// 2. Para a string, o próprio p já é o endereço do primeiro char:
//    printf("%s", (const char *) p).
// 3. Use um switch no tipo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int bomba = 3;
    double litro = 6.29;
    char combustivel = 'G';
    char frentista[] = "Rosinete";
    (void) bomba, (void) litro, (void) combustivel, (void) frentista; // apague esta linha quando escrever

    return 0;
}
