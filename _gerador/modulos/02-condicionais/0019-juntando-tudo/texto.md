## 0019 · Juntando tudo: a conta de luz

- **Escolher a ferramenta**: valores exatos pedem `switch`; duas condições
  juntas, `if` com `&&`; um valor entre dois, ternário; faixas, `else if`
  (DEITEL; DEITEL, 2011, cap. 4).
- **Validar a entrada**: o `scanf` devolve quantos valores leu; com "abc" no
  lugar de um número, devolve 0. Confira antes de usar
  (BACKES, 2013, cap. 2).
- **Cláusula de guarda**: trate o caso ruim primeiro, avise e saia com
  `return 1` (o código de erro que `echo $?` mostra). O resto fica reto, sem
  um `else` gigante.
- **Tarifas simplificadas**: R$ 0,80 por kWh; bandeira amarela com R$ 0,02 a
  mais por kWh e vermelha com R$ 0,05; desconto social de 40%.

| Decisão | Ferramenta | Por quê |
| --- | --- | --- |
| a bandeira é V, A ou R? | `switch` | valores exatos de um `char` |
| tem tarifa social **e** consumo até 220 kWh? | `if` com `&&` | duas condições juntas, um passo a mais ou nada |
| iluminação: R$ 15 acima de 100 kWh, senão R$ 5 | ternário | escolhe **um valor** entre dois |
| consumo baixo, médio ou alto? | `else if` | faixas, testadas em ordem |
| a leitura deu certo e o consumo não é negativo? | `if` com `\|\|` | barra a entrada ruim logo no começo |

> [!WARNING]
> **A ordem dos passos é parte da regra.** O desconto vale sobre energia e
> bandeira, não sobre a iluminação. Teste um caso que passe por todos os
> ramos: 150 kWh, verde, social dá 120 + 0 - 48 + 15 = **R$ 87.00**.

{{exemplo}}

A conta de luz do módulo 01 volta com decisões. Com 230 kWh, bandeira amarela
e sem tarifa social, cada decisão do módulo entra uma vez:

{{ideia}}

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

A guarda tem uma saída direta para o Fim. Depois dela, o caminho é quase reto,
com um único desvio opcional para o desconto:

{{fluxograma}}
