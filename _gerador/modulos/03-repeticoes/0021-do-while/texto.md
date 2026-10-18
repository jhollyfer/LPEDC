## 0021 · Do-while

A geladeira custa R$ 1.200 e o app pergunta: "em quantas parcelas (1 a 12)?".
Você digita 15, ele recusa e pergunta de novo. Repare num detalhe: antes da
primeira resposta, não há nada para conferir. A pergunta **tem** que aparecer
pelo menos uma vez.

Com o `while`, a pergunta vem antes do corpo. Para usá-lo aqui, você teria que
inventar um valor inválido só para entrar no laço (`parcelas = 0`). Funciona,
mas é um truque. O **`do...while`** resolve sem truque: ele **faz primeiro e
pergunta depois**.

```c
do {
    // corpo: roda pelo menos uma vez
} while (condição);   // o ; no fim é obrigatório
```

A ordem: roda o corpo, testa a condição; se der verdadeiro, volta para o
começo do corpo. Por isso o corpo roda **uma ou mais vezes**, nunca zero.

O lugar natural dele é onde a primeira volta é obrigatória:

- **validação de entrada**: pergunte, e repita enquanto a resposta for
  inválida;
- **menu**: mostre as opções, execute a escolhida e repita até a pessoa
  escolher "sair" (o exemplo A042 faz um caixa eletrônico);
- **"jogar de novo?"**: a primeira partida sempre acontece.

A condição do `do...while` descreve quando **repetir**, não quando parar.
Numa validação, ela descreve o valor **inválido**: `parcelas < 1 || parcelas >
12`.

Vamos ver na prática. A pessoa digita 0, depois 15, depois 4. As duas
primeiras respostas caem fora da faixa, a pergunta "fora de 1 a 12?" responde
Sim e o programa volta para pedir de novo. O 4 está dentro, a resposta é Não e
o programa segue:

{{ideia}}

O mesmo app em C. O `if` em volta do `scanf` confere se chegou mesmo um número
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

Repara no fluxograma: a leitura vem **antes** do losango. A seta do Sim sai do
losango e volta para o começo do corpo, "Mostrar a pergunta". No `while` (assunto
0020) a seta voltava para o losango porque a pergunta abria o laço; aqui ela
fecha. O caminho verde passa três vezes pelo losango: duas pelo Sim e uma pelo
Não:

{{fluxograma}}

> [!WARNING]
> A condição é de **continuar**, não de parar. Quem pensa "o laço termina
> quando as parcelas estiverem certas" escreve `while (parcelas >= 1 &&
> parcelas <= 12)`, e o programa fica ao contrário: repete com o 4 e aceita o
> 15. Leia sempre em voz alta: "faça isso **enquanto** ...". Para inverter uma
> condição com `&&`, use De Morgan (assunto 0013): o contrário de `a && b` é
> `!a || !b`.

> [!TIP]
> **Por dentro do C:** o `do...while` é o laço mais barato para a máquina: o
> corpo, uma comparação e **um** salto condicional para trás. Tanto que o gcc,
> com otimização ligada, costuma reescrever o seu `while` como "um `if` na
> entrada e um `do...while` dentro" (*loop rotation*). A pergunta do topo vira
> um teste único, e cada volta economiza um salto.

> [!NOTE]
> **Pergunta para você:** e se você apagar o `if` em volta do `scanf` e digitar
> `x`? O `scanf` não consegue ler um número, devolve 0, deixa o `x` no buffer e
> não muda `parcelas`. O que acontece na próxima volta? Preveja e depois teste
> no A041 (se travar, `Ctrl+C`).

{{pratique}}
