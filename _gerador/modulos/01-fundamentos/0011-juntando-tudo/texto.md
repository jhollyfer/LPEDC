## 0011 · Juntando tudo

- **Entrada → processamento → saída**: antes de codificar, separe o que o
  programa lê, o que calcula e o que mostra (LEAL, 2016).
- **Estrutura sequencial**: os mesmos passos, sempre na mesma ordem, sem
  decisão nem repetição. Conferir a entrada vem no módulo 02; repetir, no 03
  (CARVALHO, 2010).
- **Teste de mesa**: executar o programa no papel, linha a linha, anotando
  numa tabela o valor de cada variável depois de cada passo
  (CARVALHO, 2010).
- **O que o programa reúne**: `#define` para a tarifa e a taxa; `int` para as
  leituras e `double` para dinheiro; `scanf` com `&` e retorno guardado;
  `+=`, **cast** e `ceil`; `printf` com largura e duas casas.

> [!WARNING]
> Sem o cast, `consumo / DIAS` seria `257 / 30` entre dois `int` e daria 8. A
> ordem também importa: com o `ceil` antes do `* 100`, `ceil(76.4133)` daria
> R$ 77. Faça o teste de mesa antes de confiar numa fórmula.

{{exemplo}}

A conta de luz de uma república com três moradores. Entram as duas leituras
do relógio e os moradores; o consumo é 257 kWh, a conta é R$ 229,24 e cada um
paga R$ 76,42, com o centavo para cima:

{{ideia}}

```c
#include <stdio.h>
#include <math.h>

#define TARIFA_KWH 0.82    // R$ por kWh
#define ILUMINACAO 18.50   // taxa fixa de iluminação pública
#define DIAS 30

int main(void) {
    int anterior, atual, moradores;

    // entrada
    printf("Leitura anterior (kWh): ");
    scanf("%d", &anterior);
    printf("Leitura atual (kWh): ");
    scanf("%d", &atual);
    printf("Moradores: ");
    int lidos = scanf("%d", &moradores);

    // processamento
    int consumo = atual - anterior;
    double total = consumo * TARIFA_KWH;
    total += ILUMINACAO;
    double por_dia = (double) consumo / DIAS;
    double cada = ceil(total / moradores * 100) / 100; // centavo para cima

    // saída
    printf("\n%-18s %8d kWh\n", "Consumo:", consumo);
    printf("%-18s %8.2f kWh\n", "Por dia:", por_dia);
    printf("%-18s R$ %8.2f\n", "Total da conta:", total);
    printf("%-18s R$ %8.2f\n", "Cada morador:", cada);
    printf("(o último scanf leu %d item)\n", lidos);
    return 0;
}
// Exemplo de execução:
// Leitura anterior (kWh): 45230
// Leitura atual (kWh): 45487
// Moradores: 3
//
// Consumo:                257 kWh
// Por dia:               8.57 kWh
// Total da conta:    R$   229.24
// Cada morador:      R$    76.42
// (o último scanf leu 1 item)
```

### Passo a passo

Teste de mesa com a entrada 45230, 45487 e 3; as colunas mostram as variáveis
depois de cada instrução:

| Instrução | consumo | total | por_dia | cada |
| --- | --- | --- | --- | --- |
| `consumo = atual - anterior` | 257 | | | |
| `total = consumo * TARIFA_KWH` | 257 | 210.74 | | |
| `total += ILUMINACAO` | 257 | 229.24 | | |
| `por_dia = (double) consumo / DIAS` | 257 | 229.24 | 8.5666... | |
| `cada = ceil(total / moradores * 100) / 100` | 257 | 229.24 | 8.5666... | 76.42 |

Na última linha: 229,24 ÷ 3 = 76,4133...; vezes 100, 7641,33...; o `ceil`
sobe para 7642; dividido por 100, 76,42. Três vezes 76,42 dá 229,26: sobram
dois centavos, mas a conta fica paga.

Entrada, quatro contas e saída, sem nenhum losango:

{{fluxograma}}
