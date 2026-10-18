## 0024 · Laços aninhados

Uma sala de cinema pequena tem 4 fileiras (A a D) com 5 poltronas cada. Para
imprimir o mapa, você percorre a fileira A da poltrona 1 à 5, desce para a B e
faz tudo de novo, e assim por diante. É uma repetição **dentro** de outra.

Isso é um **laço aninhado**: o corpo de um laço contém outro laço inteiro. A
regra que faz tudo funcionar:

> a cada volta do laço **de fora**, o laço **de dentro** roda **do começo ao
> fim**.

Pense no relógio: o ponteiro dos minutos dá uma volta completa a cada hora
que passa. O de fora é o das horas, e o de dentro é o dos minutos.

Três consequências práticas:

- o contador de dentro **recomeça** a cada volta de fora. No `for`, isso é
  automático: o `int poltrona = 1` do cabeçalho roda de novo a cada vez. Com
  `while`, você precisa zerar à mão (o exercício E142 mostra o estrago quando
  esquece);
- o corpo de dentro roda **(voltas de fora) x (voltas de dentro)** vezes: 4 x
  5 = 20 no cinema;
- o limite de dentro pode **depender** do contador de fora. Com
  `for (int col = 1; col <= linha; col++)`, a linha 1 tem 1 asterisco, a
  linha 2 tem 2, e sai um triângulo (exemplo A048).

Use nomes que digam quem é quem: `fileira` e `poltrona`, `linha` e `coluna`.
Com `i` e `j`, a troca de um pelo outro é um erro difícil de ver.

Vamos ver na prática. O desenho congela o mapa no meio do caminho: a fileira A
já saiu inteira (o laço de dentro deu suas 5 voltas), a B está na poltrona 3, e
a C e a D ainda esperam a vez do laço de fora:

{{ideia}}

O mapa em C. O `printf("\n")` fica **entre** os dois laços: depois que o de
dentro termina a fileira, antes de o de fora passar para a próxima:

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

Repara no fluxograma: são dois losangos, cada um com a sua seta de volta. A
volta pequena (de "Mostrar e poltrona++" para "poltrona <= 5?") fica **dentro** da
volta grande (de "pula linha" para "fileira <= 'D'?"). E logo depois do Sim de
fora vem `poltrona = 1`: é ali que o laço de dentro recomeça:

{{fluxograma}}

> [!WARNING]
> O `printf("\n")` no lugar errado muda o desenho inteiro. Dentro do laço de
> dentro, sai uma poltrona por linha (20 linhas). Fora dos dois laços, sai tudo
> numa linha só. Antes de escrever, pergunte: isto acontece **uma vez por
> poltrona**, **uma vez por fileira** ou **uma vez no programa todo**? A
> resposta diz em qual nível o comando fica. Lembre também que `break` sai só
> do laço **mais interno** (assunto 0023).

> [!TIP]
> **Por dentro do C:** o custo de um laço aninhado é a **multiplicação**. Com 4
> x 5 são 20 voltas, nada. Mas compare uma lista de 1.000 clientes com outra de
> 1.000 pedidos, cada um contra cada um: 1.000 x 1.000 = 1 milhão de
> comparações. Com 100 mil de cada lado, 10 bilhões, e o programa que levava um
> segundo passa a levar horas. É o que o módulo de análise vai chamar de
> **O(n²)**. Sempre que vir um laço dentro de outro, faça a conta.

> [!NOTE]
> **Pergunta para você:** se o laço de dentro fosse
> `for (int poltrona = 1; poltrona <= fileira - 'A' + 1; poltrona++)`, quantas
> poltronas teria cada fileira e quantos lugares no total? Lembre que `char` é
> número: `'C' - 'A'` vale 2. Desenhe o mapa no papel e depois troque o laço
> de dentro no código acima e rode.

{{pratique}}
