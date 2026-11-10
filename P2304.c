// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2304 · ★☆☆ · O manual do guarda-roupa
//
// Montar o guarda-roupa tem sete passos (índices 0 a 6): separar, base,
// laterais, prateleiras, portas, puxadores e fixar. As regras "a antes de
// b" do manual são:
//
//   separar -> base, base -> laterais, laterais -> prateleiras,
//   laterais -> portas, portas -> puxadores, prateleiras -> fixar,
//   portas -> fixar
//
// Escreva kahn(rotulo) do zero: o Kahn com fila mostra a ordem de montagem.
// Quando a fila esvazia antes de sair todo mundo, o manual tem ciclo: mostre
// também os passos que ficaram travados (grau de entrada ainda maior que 0).
// Chame para o manual certo e para a reimpressão com erro, que acrescentou a
// regra puxadores -> laterais.
//
//   Saída esperada:
//   Manual certo: separar base laterais prateleiras portas puxadores fixar
//   Manual com erro: separar base
//     travados: laterais prateleiras portas puxadores fixar
//
// Dicas:
// 1. grau[b] = quantas regras chegam em b. Comece a fila com os de grau 0.
// 2. Ao tirar u da fila, mostre-o e desconte 1 do grau de cada v com
//    antes[u][v]; quem chegar a 0 entra na fila.
// 3. Resposta esperada: com o erro só saem separar e base; os outros cinco
//    ficam travados (laterais, portas e puxadores formam o ciclo, e
//    prateleiras e fixar esperam por eles).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
