## 0021 · Do-while

A geladeira custa R$ 1.200 e o app pergunta: "em quantas parcelas (1 a 12)?".
Você digita 15, ele recusa e pergunta de novo. Repare na ordem: o app precisa
fazer a pergunta pelo menos uma vez antes de ter algo para conferir. Com o
`while` do assunto 0020, a conferência vem antes de tudo, e você teria de
inventar um valor inválido só para entrar no laço (`parcelas = 0`). O truque
funciona, mas esconde a intenção.

Pense numa prova de roupa. Você veste primeiro e só depois decide se serve; se
não serviu, troca e veste de novo. Ninguém decide se a roupa serve antes de
vestir. O **`do...while`** segue essa lógica: **faz primeiro e pergunta
depois**. Ele roda o corpo, testa a condição e, se ela for verdadeira, volta
ao começo do corpo (DEITEL; DEITEL, 2011, cap. 4).

```c
do {
    // corpo: roda pelo menos uma vez
} while (condição);   // o ; no fim é obrigatório
```

Como a pergunta fica no fim, ele é o laço **com teste no fim**, também chamado
de pós-teste. A consequência é a diferença inteira em relação ao `while`: o
corpo roda **uma ou mais vezes**, nunca zero. Por isso você não precisa de
valor inicial falso para a variável da condição; a primeira volta acontece de
qualquer jeito e é ela que dá o primeiro valor (CARVALHO, 2010).

Um detalhe de escrita pega muita gente. No `do...while`, o `while (...)` do
fim é o último pedaço do comando, então leva **`;`** logo depois do parêntese
(BACKES, 2013, cap. 5). Sem ele, o compilador acusa erro. É o oposto do
`while` comum, em que o `;` depois do parêntese estraga o laço.

Use o `do...while` quando a primeira volta é obrigatória (BACKES, 2013, cap.
5). O caso mais comum é a **validação de entrada**: você lê o dado e repete a
leitura enquanto ele vier inválido. Outro é o **menu**: o programa mostra as
opções, executa a escolhida e repete até a pessoa escolher "sair" (o exemplo
A042 faz um caixa eletrônico assim). O terceiro é o "jogar de novo?": a
primeira partida sempre acontece, e só depois faz sentido perguntar.

Na validação, a condição descreve o valor **inválido**, porque é ele que faz o
programa perguntar de novo. Para parcelas de 1 a 12, o valor inválido é o que
fica abaixo de 1 ou acima de 12: `parcelas < 1 || parcelas > 12` (DEITEL;
DEITEL, 2011, cap. 3). Leia em voz alta: "peça as parcelas **enquanto** forem
menores que 1 ou maiores que 12".

O pseudocódigo da prova costuma usar outra forma de pós-teste: `repita ...
até condição`. Ele também testa no fim, mas a condição é de **parar**, não de
continuar. Para levar para C, você inverte a condição: `repita ... até x > 10`
vira `do { ... } while (!(x > 10));`, que é o mesmo que `while (x <= 10)`
(DORNELLES F., 1997). Na prova, confira sempre se o enunciado usa "enquanto"
ou "até" antes de contar as voltas.

> [!WARNING]
> A condição é de **continuar**, não de parar. Quem escreve
> `while (parcelas >= 1 && parcelas <= 12)` inverte o programa: repete com o 4
> e aceita o 15. Para inverter uma condição com `&&`, use De Morgan (assunto
> 0013): o contrário de `a && b` é `!a || !b`.

{{exemplo}}

A geladeira de R$ 1.200 em 1 a 12 parcelas. A pessoa digita 0, 15 e 4: os
dois primeiros caem fora da faixa e o programa pergunta de novo; o 4 passa. O
`if` em volta do `scanf` confere se chegou um número (0006):

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double preco = 1200.0; // a geladeira
    int parcelas;

    do {
        printf("Em quantas parcelas (1 a 12)? ");
        if (scanf("%d", &parcelas) != 1) { // letra no lugar de número
            printf("\nIsso não é um número.\n");
            return 1;
        }
    } while (parcelas < 1 || parcelas > 12); // repete ENQUANTO for inválido

    printf("%dx de R$ %.2f\n", parcelas, preco / parcelas);
    return 0;
}
// Em quantas parcelas (1 a 12)? 0
// Em quantas parcelas (1 a 12)? 15
// Em quantas parcelas (1 a 12)? 4
// 4x de R$ 300.00
```

A leitura vem **antes** do losango, e a seta do Sim volta ao começo do corpo.
No `while` o losango abria o laço; aqui ele fecha:

{{fluxograma}}
