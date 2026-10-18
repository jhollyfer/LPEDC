// 0150 · Componentes e ciclos
// Exercício E897 · ★★☆
//
// A prefeitura mapeou as ciclovias entre nove bairros (índices 0 a 8):
// Centro, Prainha, Jardim, Lagoa, Industrial, Vila Nova, Alto, Porto e
// Mangue. As ciclovias, de mão dupla, são:
//
//   Centro-Prainha, Prainha-Jardim, Jardim-Centro, Lagoa-Alto,
//   Centro-Porto, Alto-Vila Nova
//
// Escreva o programa do zero. Ele mostra o maior grupo de bairros ligados
// por ciclovia (quantos e quais), os bairros sem nenhuma ciclovia e quantas
// ciclovias novas, no mínimo, ligariam a cidade toda.
//
//   Saída esperada:
//   Maior grupo: 4 bairros (Centro, Prainha, Jardim, Porto)
//   Sem ciclovia: Industrial Mangue
//   Ciclovias novas para ligar tudo: 3
//
// Dicas:
// 1. Faça a DFS devolver um int: quantos bairros ela marcou (1 pelo próprio
//    u, mais o que cada chamada recursiva devolver).
// 2. Guarde o número do maior grupo enquanto o laço externo roda. "Sem
//    ciclovia" é grau zero: a linha do bairro na matriz só tem zeros.
// 3. Resposta esperada: a saída acima. São 4 grupos ({Centro, Prainha,
//    Jardim, Porto}, {Lagoa, Vila Nova, Alto}, {Industrial}, {Mangue}),
//    então faltam 4 - 1 = 3 ciclovias.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
