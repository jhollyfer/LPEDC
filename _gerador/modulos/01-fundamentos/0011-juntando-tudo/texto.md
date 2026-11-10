## 0011 · Juntando tudo

Chegou a conta de luz da república, com três moradores. Todo mês alguém faz a
divisão no celular e manda no grupo. Um programa pode ler as duas leituras do
relógio e o número de moradores e devolver o valor de cada um.

Ele reúne tudo o que o módulo ensinou:

- **constantes** (`#define`) para a tarifa e a taxa fixa;
- **variáveis** com o tipo certo: leituras em `int`, dinheiro em `double`;
- **entrada** com `scanf`, `&` em cada variável e o retorno guardado;
- **processamento** com aritmética, um operador composto (`+=`), um **cast**
  para a média não virar divisão inteira e o `ceil` para arredondar o
  centavo para cima (ninguém quer pagar um centavo a menos e deixar a conta
  descoberta);
- **saída** com `printf` alinhado, largura e duas casas.

É o modelo **entrada → processamento → saída** e **sequência** pura: os mesmos
passos, na mesma ordem. Ele não confere se a leitura atual é maior que a
anterior nem repete nada. Isso vem nos módulos 02 (decisão) e 03 (repetição).

Entram três valores; o consumo é 257 kWh, a conta é R$ 229,24 e a divisão por
três, com o centavo para cima, dá R$ 76,42 para cada um:

{{ideia}}

O programa completo:

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

Teste de mesa com a entrada 45230, 45487 e 3. Cada linha é uma instrução; as
colunas mostram as variáveis depois dela:

| Instrução | consumo | total | por_dia | cada |
| --- | --- | --- | --- | --- |
| `consumo = atual - anterior` | 257 | | | |
| `total = consumo * TARIFA_KWH` | 257 | 210.74 | | |
| `total += ILUMINACAO` | 257 | 229.24 | | |
| `por_dia = (double) consumo / DIAS` | 257 | 229.24 | 8.5666... | |
| `cada = ceil(total / moradores * 100) / 100` | 257 | 229.24 | 8.5666... | 76.42 |

Na última linha: 229,24 ÷ 3 = 76,4133...; vezes 100 dá 7641,33...; o `ceil`
sobe para 7642; dividido por 100, 76,42. Três vezes 76,42 dá 229,26: sobram
dois centavos, mas a conta fica paga.

Entrada, quatro contas e saída, sem nenhum losango, como todo programa deste
módulo:

{{fluxograma}}

> [!WARNING]
> Sem o cast, `consumo / DIAS` seria `257 / 30` entre dois `int`: daria 8 e a
> média por dia sairia 8.00. A ordem das contas também importa: com o `ceil`
> antes da multiplicação por 100, `ceil(76.4133)` daria R$ 77, e cada um
> pagaria 58 centavos a mais. Faça o teste de mesa antes de confiar numa
> fórmula.

> [!NOTE]
> **Pergunta para você:** e se alguém digitar a leitura atual menor que a
> anterior (45487 e depois 45230)? O que o programa mostra? Que pergunta ele
> deveria fazer antes de calcular? Guarde a resposta para o módulo 02.

{{pratique}}
