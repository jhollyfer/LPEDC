## 0021 · Do-while

A geladeira custa R$ 1.200 e o app pergunta: "em quantas parcelas (1 a 12)?".
Você digita 15, ele recusa e pergunta de novo. A pergunta **tem** que aparecer
pelo menos uma vez.

Com o `while`, você precisaria inventar um valor inválido só para entrar no
laço (`parcelas = 0`). O **`do...while`** evita o truque: **faz primeiro e
pergunta depois**.

```c
do {
    // corpo: roda pelo menos uma vez
} while (condição);   // o ; no fim é obrigatório
```

Roda o corpo e testa a condição; se verdadeira, volta ao começo do corpo. O
corpo roda **uma ou mais vezes**, nunca zero. É o laço **com teste no fim**
(pós-teste).

No pseudocódigo da prova, `repita ... até condição` também testa no fim, mas a
condição é de **parar**: `repita ... até x > 10` vira
`do { ... } while (!(x > 10));`, ou seja, `while (x <= 10)`.

Use quando a primeira volta é obrigatória:

- **validação de entrada**: pergunte e repita enquanto a resposta for
  inválida;
- **menu**: mostre as opções, execute a escolhida e repita até "sair" (o
  exemplo A042 faz um caixa eletrônico);
- **"jogar de novo?"**: a primeira partida sempre acontece.

A condição descreve quando **repetir**. Numa validação, descreve o valor
**inválido**: `parcelas < 1 || parcelas > 12`.

No exemplo, a pessoa digita 0, 15 e 4. Os dois primeiros caem fora da faixa:
"fora de 1 a 12?" responde Sim e o programa pergunta de novo. O 4 está dentro,
a resposta é Não e o programa segue:

{{ideia}}

O mesmo app em C. O `if` em volta do `scanf` confere se chegou um número
(assunto 0006):

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

A leitura vem **antes** do losango. A seta do Sim sai do losango e volta ao
começo do corpo, "Mostrar a pergunta". No `while` (assunto 0020) a seta
voltava ao losango, que abria o laço; aqui ele fecha. O caminho verde passa
três vezes pelo losango: duas pelo Sim e uma pelo Não:

{{fluxograma}}

> [!WARNING]
> A condição é de **continuar**, não de parar. Quem escreve
> `while (parcelas >= 1 && parcelas <= 12)` inverte o programa: repete com o 4
> e aceita o 15. Leia em voz alta: "faça isso **enquanto** ...". Para inverter
> uma condição com `&&`, use De Morgan (assunto 0013): o contrário de `a && b`
> é `!a || !b`.

> [!NOTE]
> **Pergunta para você:** e se você apagar o `if` em volta do `scanf` e digitar
> `x`? O `scanf` não consegue ler um número, devolve 0, deixa o `x` no buffer e
> não muda `parcelas`. O que acontece na próxima volta? Preveja e depois teste
> no código acima (se travar, `Ctrl+C`).

{{pratique}}
