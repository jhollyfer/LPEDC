## 0021 · Do-while

- **`do...while`**: **faz primeiro e pergunta depois**. Roda o corpo e testa;
  se a condição é verdadeira, volta ao começo do corpo
  (DEITEL; DEITEL, 2011, cap. 4).

```c
do {
    // corpo: roda pelo menos uma vez
} while (condição);   // o ; no fim é obrigatório
```

- **Teste no fim** (pós-teste): o corpo roda **uma ou mais vezes**, nunca
  zero. Dispensa inventar um valor inválido só para entrar no laço
  (CARVALHO, 2010).
- **`;` obrigatório** depois do `while (...)` final (BACKES, 2013, cap. 5).
- **`repita ... até`**: no pseudocódigo da prova, a condição é de **parar**.
  `repita ... até x > 10` vira `do { ... } while (!(x > 10));`, que é
  `while (x <= 10)` (DORNELLES F., 1997).
- **Quando usar**: a primeira volta é obrigatória. Validação de entrada, menu
  (o A042 faz um caixa eletrônico) e "jogar de novo?"
  (BACKES, 2013, cap. 5).
- **Condição de validação**: descreve o valor **inválido**, o que faz repetir:
  `parcelas < 1 || parcelas > 12` (DEITEL; DEITEL, 2011, cap. 3).

> [!WARNING]
> A condição é de **continuar**, não de parar. Com
> `while (parcelas >= 1 && parcelas <= 12)`, o programa repete com o 4 e
> aceita o 15. Para inverter um `&&`, use De Morgan (0013): `!a || !b`.

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
