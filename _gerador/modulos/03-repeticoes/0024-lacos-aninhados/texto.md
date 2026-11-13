## 0024 · Laços aninhados

- **Laço aninhado**: o corpo de um laço contém outro laço inteiro. A cada
  volta do laço **de fora**, o **de dentro** roda do começo ao fim, como os
  ponteiros de horas e minutos (BACKES, 2013, cap. 5).
- **Recomeço**: o contador de dentro volta ao início a cada volta de fora. No
  `for`, é automático; no `while`, você zera à mão (o E142 mostra o estrago)
  (BACKES, 2013, cap. 5).
- **Voltas**: o corpo de dentro roda (voltas de fora) × (voltas de dentro)
  vezes: 4 × 5 = 20 (DEITEL; DEITEL, 2011, cap. 4).
- **Limite dependente**: o de dentro pode usar o contador de fora. Com
  `for (int col = 1; col <= linha; col++)`, sai um triângulo (A048)
  (DEITEL; DEITEL, 2011, cap. 4).
- **Custo**: a conta é uma **multiplicação**. Comparar 1.000 clientes com
  1.000 pedidos dá 1 milhão de comparações, o **O(n²)** do módulo de análise
  (CELES; CERQUEIRA; RANGEL, 2016).
- **Nomes**: `fileira` e `poltrona`, `linha` e `coluna`. Com `i` e `j`, é
  fácil trocar um pelo outro sem perceber.

> [!WARNING]
> O `printf("\n")` no lugar errado muda o desenho: dentro do laço de dentro,
> sai uma poltrona por linha; fora dos dois, tudo numa linha. Pergunte: isto
> acontece uma vez por poltrona, por fileira ou no programa?

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
