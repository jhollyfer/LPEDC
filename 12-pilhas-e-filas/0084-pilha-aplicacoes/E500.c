// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E500 · ★☆☆
//
// Quando só existe um tipo de delimitador, nem precisa de pilha. Escreva
// bool parenteses_ok(const char *s) usando só um contador int: soma 1 no
// "(", tira 1 no ")". Teste com as quatro strings abaixo. Depois escreva
// uma segunda versão, bool contador_ok(const char *s), que conta os três
// tipos juntos (abre: "(", "[" ou "{"; fecha: ")", "]" ou "}") e teste com
// "( [ ) ]": repare que o contador aprova uma expressão errada.
//
//   Saída esperada:
//   (a+(b*c))  ok
//   (a+b))(    erro
//   )(         erro
//   ((x)       erro
//   ( [ ) ]    contador diz ok, mas está errado
//
// Dicas:
// 1. Se o contador ficar negativo no meio do caminho, já é erro: fechou
//    sem abrir. É o que pega o ")(".
// 2. No fim, ok só se o contador for 0.
// 3. Use printf("%-10s %s\n", s, ...) para alinhar.
// 4. Para a última linha: if (contador_ok("( [ ) ]")) printf(...).
// 5. Resposta esperada: as cinco linhas acima. Com tipos diferentes, o
//    contador só sabe QUANTOS estão abertos, não QUAL foi o último a abrir.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
