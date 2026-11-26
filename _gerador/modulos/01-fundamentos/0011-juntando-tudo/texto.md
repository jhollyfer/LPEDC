## 0011 · Juntando tudo

Cada assunto do módulo ensinou uma peça isolada: variável, tipo, constante,
`printf`, `scanf`, aritmética, conversão, atribuição e `math.h`. Um problema
de verdade pede todas ao mesmo tempo, e a dificuldade passa a ser outra:
decidir por onde começar e em que ordem montar as peças. Ajuda ter um
jeito fixo de organizar o raciocínio antes de escrever a primeira linha.

Pense na conta de luz de uma república. Todo mês alguém pega a fatura, faz
a divisão no celular e manda no grupo quanto cada um deve. Antes de abrir a
calculadora, essa pessoa já sabe três coisas: o que precisa olhar (as duas
leituras do relógio e quantos moram na casa), que conta fazer e o que
mandar no grupo. O programa segue o mesmo roteiro.

Esse roteiro tem nome: **entrada → processamento → saída**. Antes de
codificar, separe o que o programa lê, o que ele calcula a partir disso e o
que ele mostra no fim (LEAL, 2016). A entrada vira variáveis lidas com
`scanf`; o processamento vira expressões e atribuições; a saída vira
`printf`. Com essa separação feita no papel, cada parte do código tem um
papel claro, e um erro fica mais fácil de achar: você sabe se procura na
leitura, na conta ou na hora de mostrar.

Todos os programas deste módulo têm a mesma forma, chamada **estrutura
sequencial**: os passos são sempre os mesmos e rodam sempre na mesma ordem,
de cima para baixo, sem decidir nada e sem repetir nada (CARVALHO, 2010).
Isso é também um limite. O programa da conta de luz não confere se a
leitura atual é maior que a anterior, e não sabe repetir a conta para vários
meses. Conferir é assunto do módulo 02, com as condicionais; repetir é do
módulo 03, com os laços.

O programa do exemplo junta as peças assim. A tarifa e a taxa fixa viram
constantes com `#define` (0004), para mudar num lugar só. As leituras do
relógio são `int` e o dinheiro é `double` (0002). O `scanf` leva `&` em
cada variável, e o seu retorno fica guardado (0006). No processamento
entram o `+=` (0009), um **cast** para a média por dia não virar divisão
inteira (0008) e o `ceil` (0010) para arredondar o centavo para cima, já que
ninguém quer pagar um centavo a menos e deixar a conta descoberta. Na saída,
o `printf` usa largura e duas casas para alinhar as colunas (0005).

Como saber se a fórmula está certa antes de confiar nela? Com o **teste de
mesa**: você executa o programa no papel, uma linha de cada vez, e anota
numa tabela o valor de cada variável depois de cada passo (CARVALHO, 2010).
O teste de mesa obriga você a fazer a conta que o computador faria, com os
tipos que ele usaria, e por isso pega a divisão inteira, o arredondamento
no lugar errado e a variável que nunca recebeu valor. O exemplo abaixo traz
um teste de mesa completo para você acompanhar.

> [!WARNING]
> Sem o cast, `consumo / DIAS` seria `257 / 30` entre dois `int` e daria 8.
> A ordem também importa: com o `ceil` antes do `* 100`, `ceil(76.4133)`
> daria R$ 77. Faça o teste de mesa antes de confiar numa fórmula.

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
