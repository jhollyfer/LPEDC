// 0142 · Distância de edição
// Exercício E850 · ★★☆
//
// A câmera do estacionamento lê placas com erro: troca O por 0, perde um
// caractere no fim, inventa outro. As placas cadastradas são:
//
//   BRA2E19 RIO1A23 SPX9F87 BRA2E79 MGA4B56 BRZ2E19 PE1234 AM12B3456
//
// Para cada leitura (BRA2E19, RI01A23, SPX9F8 e XYZ0000), mostre todas as
// placas cadastradas a distância de edição de no máximo 1, com a distância
// entre parênteses, ou "nenhuma". Antes de montar cada tabela, pule as
// placas cujo tamanho difere da leitura em mais de 1 (a distância é pelo
// menos a diferença dos tamanhos), e conte quantas tabelas foram montadas.
//
//   Saída esperada:
//   BRA2E19: BRA2E19 (0) BRA2E79 (1) BRZ2E19 (1)
//   RI01A23: RIO1A23 (1)
//   SPX9F8: SPX9F87 (1)
//   XYZ0000: nenhuma
//   tabelas montadas: 28 de 32
//
// Dicas:
// 1. Reaproveite a distancia() do texto com um contador global que sobe a
//    cada chamada.
// 2. abs() de <stdlib.h> dá o valor absoluto da diferença dos strlen
//    (converta para int antes de subtrair: strlen devolve size_t, sem sinal).
// 3. Uma flag "achou" decide se no fim da linha vai " nenhuma".
// 4. Resposta esperada: a saída acima. Uma leitura exata também tem
//    "parentes" a distância 1: é por isso que o sistema precisa confirmar
//    com uma pessoa.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
