## 0024 · Laços aninhados

Uma sala de cinema tem 4 fileiras, de A a D, com 5 poltronas cada. Para
imprimir o mapa da sala, você percorre a fileira A da poltrona 1 à 5, desce
para a B e faz tudo de novo, até a D. Repare que há duas repetições, uma
dentro da outra: a das fileiras e, para cada fileira, a das poltronas. Um laço
só não dá conta disso.

O nome dessa construção é **laço aninhado**: o corpo de um laço contém outro
laço inteiro (BACKES, 2013, cap. 5). A regra que governa tudo é esta: a cada
volta do laço **de fora**, o laço **de dentro** roda **do começo ao fim**.
Pense no relógio de ponteiros. O dos minutos dá uma volta completa a cada hora,
e só então o das horas avança uma casa. O de fora é o das horas; o de dentro,
o dos minutos.

Da regra sai a primeira consequência: o contador de dentro **recomeça** a cada
volta de fora (BACKES, 2013, cap. 5). No `for`, isso é automático, porque o
início do cabeçalho (`int poltrona = 1`) roda de novo toda vez que o laço de
dentro começa. No `while`, o início fica fora do laço, e você precisa zerar o
contador à mão antes de cada nova fileira. Esquecer disso faz o laço de dentro
rodar só na primeira fileira, porque nas seguintes o contador já está no fim.
O exercício E142 mostra esse estrago.

A segunda consequência é a conta de voltas. O corpo do laço de dentro roda
(voltas de fora) × (voltas de dentro) vezes (DEITEL; DEITEL, 2011, cap. 4). No
cinema, são 4 × 5 = 20 poltronas impressas. Essa conta vale quando o laço de
dentro tem sempre o mesmo tamanho.

Ele nem sempre tem. A terceira consequência é que o limite de dentro pode
**depender** do contador de fora (DEITEL; DEITEL, 2011, cap. 4). Com
`for (int col = 1; col <= linha; col++)`, a linha 1 tem 1 asterisco, a linha 2
tem 2, a linha 3 tem 3, e o desenho vira um triângulo. O exemplo A048 faz
isso. Aqui a conta de voltas deixa de ser multiplicação e vira soma:
1 + 2 + 3 + ... até a última linha.

A multiplicação também mostra o **custo** de um laço aninhado. Com 4 × 5, não
há o que medir. Mas comparar 1.000 clientes com 1.000 pedidos, cada um contra
cada um, dá 1 milhão de comparações. Quando o tamanho da entrada dobra, o
trabalho quadruplica. É o crescimento quadrático, o **O(n²)** que o módulo de
análise de algoritmos estuda (CELES; CERQUEIRA; RANGEL, 2016). Ao ver um laço
dentro de outro, faça a conta antes de rodar com dados grandes.

Com dois contadores no ar, o nome pesa. Use nomes que digam quem é quem:
`fileira` e `poltrona`, `linha` e `coluna`. Com `i` e `j`, é fácil trocar um
pelo outro numa condição ou num `printf` sem perceber, e o programa compila do
mesmo jeito. Lembre também que `break` e `continue` valem só para o laço mais
interno (assunto 0023): um `break` no laço das poltronas encerra a fileira
atual, não o mapa.

> [!WARNING]
> O `printf("\n")` no lugar errado muda o desenho: dentro do laço de dentro,
> sai uma poltrona por linha; fora dos dois, tudo numa linha. Pergunte: isto
> acontece **uma vez por poltrona**, **uma vez por fileira** ou **uma vez no
> programa**? A resposta diz em que nível o comando vai.

{{exemplo}}

O mapa de um cinema com 4 fileiras (A a D) de 5 poltronas. O desenho congela
o meio do caminho: a fileira A já saiu inteira, a B está na poltrona 3, e a C
e a D esperam o laço de fora. O `printf("\n")` fica **entre** os dois laços:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int lugares = 0;

    for (char fileira = 'A'; fileira <= 'D'; fileira++) {    // laço de fora
        for (int poltrona = 1; poltrona <= 5; poltrona++) {  // laço de dentro
            printf("%c%d ", fileira, poltrona);
            lugares++;
        }
        printf("\n"); // acabou a fileira: pula linha
    }
    printf("Total: %d lugares\n", lugares);
    return 0;
}
// Saída:
// A1 A2 A3 A4 A5 
// B1 B2 B3 B4 B5 
// C1 C2 C3 C4 C5 
// D1 D2 D3 D4 D5 
// Total: 20 lugares
```

São dois losangos, cada um com sua seta de volta; a volta pequena fica
**dentro** da grande. Logo depois do Sim de fora vem `poltrona = 1`: ali o
laço de dentro recomeça:

{{fluxograma}}
