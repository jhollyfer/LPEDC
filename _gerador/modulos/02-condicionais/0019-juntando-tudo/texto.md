## 0019 · Juntando tudo: a conta de luz

O módulo apresentou as ferramentas de decisão do C: comparações, operadores
lógicos, `if` e `if/else`, `else if`, ternário e `switch`. Num programa de
verdade elas aparecem juntas, e a pergunta deixa de ser "como se escreve" e
passa a ser "qual delas serve aqui". Escolher bem deixa o código curto e
fácil de conferir; escolher mal produz escadas de `if` que ninguém consegue
seguir.

Pense de novo na conta de luz do 0011, agora com as regras de verdade. O
valor depende do consumo e da **bandeira** do mês, verde, amarela ou
vermelha. Famílias de baixa renda têm a **tarifa social**, um desconto. A
taxa de iluminação muda com o consumo, e um carimbo diz se o consumo foi
baixo, médio ou alto. Cada uma dessas regras é uma decisão diferente, e
cada uma tem a sua forma.

A forma da pergunta indica a ferramenta (DEITEL; DEITEL, 2011, cap. 4). Se
a resposta é um entre poucos **valores exatos**, como a letra da bandeira,
o `switch` (0018) pula direto para ela. Se a regra exige **duas condições
ao mesmo tempo**, como ter tarifa social e consumir até 220 kWh, é um `if`
com `&&` (0013), um passo a mais ou nada. Se a decisão só **escolhe um
valor** entre dois, como R$ 15 ou R$ 5 de iluminação, o ternário (0017)
resolve numa linha. E se o valor cai em **faixas**, como baixo, médio e
alto, o `else if` (0016) testa em ordem. A tabela resume:

| Decisão | Ferramenta | Por quê |
| --- | --- | --- |
| a bandeira é V, A ou R? | `switch` | valores exatos de um `char` |
| tem tarifa social **e** consumo até 220 kWh? | `if` com `&&` | duas condições juntas, um passo a mais ou nada |
| iluminação: R$ 15 acima de 100 kWh, senão R$ 5 | ternário | escolhe **um valor** entre dois |
| consumo baixo, médio ou alto? | `else if` | faixas, testadas em ordem |
| a leitura deu certo e o consumo não é negativo? | `if` com `\|\|` | barra a entrada ruim logo no começo |

A última linha da tabela trata de outra coisa: a entrada. Um programa que
lê do teclado precisa desconfiar de quem digita. O `scanf` devolve
**quantos valores leu** (0006); se ele pediu um número e veio "abc",
devolve 0, e a variável continua com lixo (BACKES, 2013, cap. 2). Por isso
a primeira decisão do programa é conferir a leitura: `scanf(...) != 1` ou
um consumo negativo indicam entrada ruim.

O jeito de reagir a essa entrada ruim tem nome: **cláusula de guarda**.
Você trata o caso ruim primeiro, mostra um aviso e encerra o programa com
`return 1`. O número 1 é um código de erro que o terminal enxerga; depois
de rodar, `echo $?` o mostra. A vantagem aparece no resto do código: como o
caso ruim já saiu, tudo o que vem depois fica reto, sem um `else` gigante
envolvendo o programa inteiro.

As tarifas do exemplo são simplificadas para a conta caber de cabeça. A
energia custa R$ 0,80 por kWh. A bandeira amarela soma R$ 0,02 por kWh, e
a vermelha, R$ 0,05; a verde não soma nada. O desconto social é de 40% e
vale sobre a energia e a bandeira, mas não sobre a iluminação. Com essas
regras, a ordem dos passos passa a fazer parte da conta.

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
