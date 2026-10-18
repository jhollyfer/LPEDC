## 0002 · Pseudocódigo e teste de mesa

Fim de semestre. Você tirou 7,5 na primeira prova e 5,5 na segunda. Para
passar, a média precisa ser pelo menos 6. Passou?

Antes de ir para o C, dá para escrever a solução numa linguagem "de mentira",
em português, só para organizar o raciocínio. Isso é **pseudocódigo**. Ele não
roda em computador nenhum, e é justamente por isso que é útil: você pensa no
problema sem brigar com ponto e vírgula.

Existe um jeito tradicional de escrever pseudocódigo no Brasil, o **Portugol**
(é o que o VisuAlg usa). As palavras que importam:

| Portugol | O que faz | Em C (vem no módulo 01) |
| --- | --- | --- |
| `var nota1: real` | cria uma variável | `double nota1;` |
| `nota1 <- 7.5` | guarda um valor | `nota1 = 7.5;` |
| `leia(nota1)` | lê do teclado | `scanf("%lf", &nota1);` |
| `escreva("Oi")` | mostra na tela | `printf("Oi");` |
| `se ... entao ... senao ... fimse` | decisão | `if (...) { } else { }` |
| `enquanto ... faca ... fimenquanto` | repetição | `while (...) { }` |

O cálculo da média em Portugol:

```text
algoritmo "media"
var
    nota1, nota2, media: real
inicio
    leia(nota1)              // 7.5
    leia(nota2)              // 5.5
    media <- (nota1 + nota2) / 2
    se media >= 6 entao
        escreva("Aprovado")
    senao
        escreva("Reprovado")
    fimse
fimalgoritmo
```

Escreveu? Agora **confira à mão** antes de confiar. Esse é o **teste de mesa**:
uma tabela com uma coluna para cada variável e uma linha para cada passo. Você
"executa" o algoritmo no papel, como se fosse o computador:

| Passo | nota1 | nota2 | media | Na tela |
| --- | --- | --- | --- | --- |
| `leia(nota1)` | 7.5 | | | |
| `leia(nota2)` | 7.5 | 5.5 | | |
| `media <- ...` | 7.5 | 5.5 | 6.5 | |
| `se media >= 6` | 7.5 | 5.5 | 6.5 | Aprovado |

Vamos ver na prática. As duas notas entram, viram uma média de 6,5, e a
pergunta "média >= 6?" responde Sim:

{{ideia}}

O mesmo algoritmo em C. Compare linha por linha com o Portugol:

```c
#include <stdio.h>

int main(void) {
    double nota1 = 7.5;
    double nota2 = 5.5;
    double media = (nota1 + nota2) / 2;

    printf("Média: %.1f\n", media);
    if (media >= 6) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }
    return 0;
}
// Saída:
// Média: 6.5
// Aprovado
```

Repara no fluxograma: o teste de mesa é exatamente seguir esse caminho com o
dedo e anotar o valor de cada variável:

{{fluxograma}}

> [!WARNING]
> Os parênteses mudam tudo. `nota1 + nota2 / 2` calcula `7.5 + 2.75 = 10.25`,
> porque a divisão vem antes da soma, igual na matemática da escola. O teste de
> mesa pega esse erro na hora: 10,25 de média com notas 7,5 e 5,5 não faz
> sentido.

> [!TIP]
> **Por dentro do C:** o teste de mesa não é só coisa de iniciante. É o que o
> **depurador** (`gdb`) faz por você: para o programa linha a linha e mostra o
> valor de cada variável. Cada coluna da sua tabela é, de verdade, um pedacinho
> da memória com nome. No módulo 01 você vai ver que `double` ocupa 8 bytes e
> que a coluna `media` é um endereço como `0x7ffc5a3c`.

> [!NOTE]
> **Pergunta para você:** com notas 6,0 e 5,9, o aluno passa? Faça o teste de
> mesa antes de rodar. Depois troque os valores no exemplo A003 e confira.

{{pratique}}
