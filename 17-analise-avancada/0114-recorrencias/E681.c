// 0114 · Recorrências e árvore de recursão
// Exercício E681 · ★★☆
//
// Um comparador de preços confere um lote de produtos assim: compara cada
// preço do lote com TODOS os preços do lote (n² comparações), procurando
// pares suspeitos, depois divide o lote ao meio e confere cada metade do
// mesmo jeito. A recorrência é T(n) = 2 T(n/2) + n², com T(1) = 1.
//
// O programa abaixo só mostra o total. Mude-o para contar as comparações
// POR NÍVEL da recursão (como o custo_nivel do texto), mostrar os níveis
// para n = 8 e depois os totais para n = 16, 32 e 64 ao lado de 2n² - n:
//
//   Saída esperada:
//   nível 0: 64 comparações
//   nível 1: 32 comparações
//   nível 2: 16 comparações
//   nível 3: 8 comparações
//   total: 120
//   
//    n  T(n)  2n² - n
//   16   496   496
//   32  2016  2016
//   64  8128  8128
//
// Repare: aqui o custo CAI pela metade a cada nível. É o oposto da
// auditoria do texto, em que todo nível custava igual.
//
// Dicas:
// 1. Troque o contador único por um vetor long custo_nivel[32] e passe o
//    nível como parâmetro (a raiz é o nível 0; os filhos, nível + 1).
// 2. Antes de cada medição, zere o vetor inteiro.
// 3. Por que 2n² - n? Os níveis custam n², n²/2, n²/4, ..., n: a soma de
//    uma progressão geométrica de razão 1/2 fica abaixo do dobro do
//    primeiro termo. A raiz sozinha já é metade de tudo: Θ(n²).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>

long comparacoes = 0;

// devolve quantos pares suspeitos (um preço mais que o dobro do outro) achou
long confere_precos(const int preco[], int ini, int fim) {
    int n = fim - ini;
    long suspeitos = 0;
    for (int i = ini; i < fim; i++) {
        for (int j = ini; j < fim; j++) {
            comparacoes++;                     // uma comparação
            if (preco[i] > 2 * preco[j]) {
                suspeitos++;
            }
        }
    }
    if (n == 1) {
        return suspeitos;
    }
    int meio = ini + n / 2;
    suspeitos += confere_precos(preco, ini, meio);
    suspeitos += confere_precos(preco, meio, fim);
    return suspeitos;
}

int main(void) {
    int preco[64];
    for (int i = 0; i < 64; i++) {
        preco[i] = 5 + (i * 13) % 40;
    }

    long s = confere_precos(preco, 0, 8);
    printf("n = 8: %ld suspeitos, %ld comparações\n", s, comparacoes);
    return 0;
}
