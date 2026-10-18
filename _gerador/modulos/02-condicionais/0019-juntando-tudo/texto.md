## 0019 · Juntando tudo: a conta de luz

Chegou a conta de luz, e ela é um festival de decisões. O valor depende do
consumo, da **bandeira** do mês (verde, amarela ou vermelha), de você ter ou
não **tarifa social**, de uma taxa de iluminação que muda com o consumo, e
ainda vem um carimbo dizendo se o seu consumo foi baixo, médio ou alto.

Cada pedaço pede uma ferramenta diferente do módulo, e escolher a certa é
metade do trabalho:

| Decisão | Ferramenta | Por quê |
| --- | --- | --- |
| a bandeira é V, A ou R? | `switch` | valores exatos de um `char` |
| tem tarifa social **e** consumo até 220 kWh? | `if` com `&&` | duas condições juntas, um passo a mais ou nada |
| iluminação: R$ 15 acima de 100 kWh, senão R$ 5 | ternário | escolhe **um valor** entre dois |
| consumo baixo, médio ou alto? | `else if` | faixas, testadas em ordem |
| a leitura deu certo e o consumo não é negativo? | `if` com `\|\|` | barra a entrada ruim logo no começo |

Repare na última linha. Um programa que lê do teclado precisa desconfiar de
quem digita. O `scanf` devolve **quantos valores conseguiu ler** (assunto
0006): se você pediu um número e a pessoa digitou "abc", ele devolve 0. A
primeira decisão do programa é essa: se a entrada não presta, avisa e sai com
`return 1` (o código de erro que o terminal enxerga). Esse padrão tem nome:
**cláusula de guarda**. Trate o caso ruim primeiro e o resto do código fica
reto, sem um `else` gigante.

As tarifas do exemplo são simplificadas, mas a estrutura é a de uma conta de
verdade: energia a R$ 0,80 por kWh, bandeira amarela com R$ 0,02 a mais por
kWh, vermelha com R$ 0,05, desconto social de 40%.

Vamos ver na prática. Consumo de 230 kWh, bandeira amarela, sem tarifa social.
Cada decisão do módulo entra em cena uma vez, e o total sai no terminal:

{{ideia}}

O programa completo. Ele lê os três dados, e o comentário no fim mostra uma
execução:

```c
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int consumo, resposta;
    char bandeira;

    printf("Consumo do mês (kWh): ");
    if (scanf("%d", &consumo) != 1 || consumo < 0) { // guarda
        printf("Consumo inválido.\n");
        return 1;
    }
    printf("Bandeira (V, A ou R): ");
    if (scanf(" %c", &bandeira) != 1) {
        printf("Bandeira inválida.\n");
        return 1;
    }
    printf("Tarifa social (1 = sim, 0 = não): ");
    if (scanf("%d", &resposta) != 1) {
        printf("Resposta inválida.\n");
        return 1;
    }
    bool social = resposta;

    double adicional; // por kWh, conforme a bandeira
    switch (bandeira) {
    case 'V':
    case 'v':
        adicional = 0.0;
        break;
    case 'A':
    case 'a':
        adicional = 0.02;
        break;
    case 'R':
    case 'r':
        adicional = 0.05;
        break;
    default:
        printf("Bandeira inválida.\n");
        return 1;
    }

    double energia = consumo * 0.80;
    double extra = consumo * adicional;
    double desconto = 0.0;
    if (social && consumo <= 220) {
        desconto = (energia + extra) * 0.40;
    }
    double iluminacao = consumo > 100 ? 15.0 : 5.0;
    double total = energia + extra - desconto + iluminacao;

    printf("Energia: R$ %.2f\n", energia);
    printf("Bandeira: R$ %.2f\n", extra);
    if (desconto > 0) {
        printf("Desconto social: -R$ %.2f\n", desconto);
    }
    printf("Iluminação pública: R$ %.2f\n", iluminacao);

    if (consumo <= 100) {
        printf("Consumo baixo.\n");
    } else if (consumo <= 300) {
        printf("Consumo médio.\n");
    } else {
        printf("Consumo alto.\n");
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
// Consumo do mês (kWh): 230
// Bandeira (V, A ou R): A
// Tarifa social (1 = sim, 0 = não): 0
// Energia: R$ 184.00
// Bandeira: R$ 4.60
// Iluminação pública: R$ 15.00
// Consumo médio.
// Total: R$ 203.60
```

Repara no fluxograma: a primeira decisão é a guarda, com uma saída direta
para o Fim. Depois dela, o caminho é quase uma linha reta, com um único
desvio opcional para o desconto. É assim que um programa bem organizado se
parece por fora:

{{fluxograma}}

> [!WARNING]
> **A ordem dos passos é parte da regra.** O desconto social vale sobre a
> energia **e** a bandeira, mas não sobre a iluminação. Se você somar a
> iluminação antes de calcular os 40%, a conta muda e ninguém percebe, porque
> o programa compila e roda. Antes de escrever, faça um **teste de mesa** com
> um caso que passa por todos os ramos (150 kWh, verde, com tarifa social:
> 120 + 0 - 48 + 15 = **R$ 87.00**) e confira com a saída.

> [!TIP]
> **Por dentro do C:** o `return 1` da guarda não é enfeite. O valor que o
> `main` devolve vira o **código de saída** do processo. No terminal,
> `echo $?` logo depois de rodar mostra 0 (deu certo) ou 1 (deu erro). Scripts
> e ferramentas como o `make` usam esse número para decidir se continuam.
> Repare também que o `switch` aqui tem um `default` com `return`: assim o
> compilador sabe que `adicional` sempre recebe um valor antes de ser usado.
> Tire o `return` e o `gcc -O2 -Wall` avisa que ela pode ser usada sem valor.

> [!NOTE]
> **Pergunta para você:** com 400 kWh, bandeira vermelha e tarifa social,
> quanto dá a conta? O desconto entra? Faça a conta no papel e depois rode o
> código acima com essa entrada.

{{pratique}}
