// Lista · Módulo 15 · Tabelas hash
// Exercício P1530 · ★★★ · O carro que passou duas vezes mais rápido
//
// O radar da avenida anotou as placas na ordem das passagens:
//
//   ABC1D23 QWE4R56 ZXC7V89 ABC1D23 JKL0M12 QWE4R56 POI3U45 ZXC7V89
//   JKL0M12 QWE4R56
//
// Para cada placa que já tinha passado, a DISTÂNCIA é quantas passagens
// separam esta da anterior da mesma placa. Ache a menor distância (no
// empate, a que aparece primeiro) numa passada só, com uma tabela hash que
// guarda, para cada placa, a posição da última passagem:
//
//   typedef struct { char placa[8]; int ultima; } Registro;
//
// Use endereçamento aberto (m = 17, sondagem linear, djb2 % 17, placa ""
// = livre) e uma função Registro *registro(t, placa, &nova) que devolve o
// registro da placa, criando se for nova. Mostre cada volta e o resultado.
//
//   Saída esperada:
//   ABC1D23 voltou (distância 3)
//   QWE4R56 voltou (distância 4)
//   ZXC7V89 voltou (distância 5)
//   JKL0M12 voltou (distância 4)
//   QWE4R56 voltou (distância 4)
//   menor intervalo: ABC1D23, passagens 1 e 4 (distância 3)
//
// Dicas:
// 1. Depois de calcular a distância, atualize r->ultima = i: a próxima volta
//    é medida a partir desta passagem, não da primeira.
// 2. As passagens no resultado contam a partir de 1 (posição + 1).
// 3. Com hash, O(n); comparando cada passagem com todas as anteriores,
//    O(n²).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define M 17

typedef struct {
    char placa[8];
    int ultima;
} Registro;

int main(void) {

    return 0;
}
