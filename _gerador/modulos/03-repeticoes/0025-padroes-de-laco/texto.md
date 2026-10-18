## 0025 · Padrões de laço

Fim de semana de calor e você anotou a temperatura máxima de cada dia: 28, 31,
36, 25 e 30 °C. Quantos dias foram? Qual a média? Qual foi o dia mais quente,
e o mais frio? Teve algum dia de 35 °C ou mais?

Cada pergunta dessas é um **padrão de laço**: um jeito de usar uma variável
que já foi resolvido milhares de vezes. Quem programa há tempo reconhece de
longe e escreve sem pensar. São cinco, e todos seguem o mesmo roteiro: a
variável ganha um valor **antes** do laço, é atualizada **dentro** e usada
**depois**.

| Padrão | Antes do laço | Dentro do laço | Depois |
| --- | --- | --- | --- |
| **contador** | `dias = 0` | `dias++` | quantos foram |
| **acumulador** | `soma = 0` (produto: `= 1`) | `soma += temp` | total, média |
| **maior/menor** | o **primeiro** valor | `if (temp > maior) maior = temp` | o recorde |
| **flag** | `calorao = false` | `if (temp >= 35) calorao = true` | aconteceu ou não? |
| **sentinela** | ler o primeiro valor | ler o próximo, no fim | (o laço para nela) |

Alguns detalhes que separam o código certo do quase certo:

- o acumulador de **produto** começa em **1**: começar em 0 zera tudo;
- a **flag** só sobe. Ninguém escreve `else calorao = false`, senão um dia de
  25 °C depois do de 36 apagaria a resposta;
- a **sentinela** é um valor que **não pode** ser um dado de verdade. Temperatura
  pode ser 0 ou negativa, então a sentinela aqui é 999. E ela não entra em
  conta nenhuma: o laço testa antes de contar;
- para a sentinela funcionar, a leitura acontece em dois lugares: uma vez
  **antes** do laço e uma vez no **fim** do corpo. É a **leitura antecipada**:
  a pergunta do `while` sempre olha para um valor recém-lido;
- a média é `(double) soma / dias`, com cast (assunto 0008), e só se `dias >
  0`. Se a primeira coisa digitada for a sentinela, a conta vira 0 / 0: com
  `double`, sai `nan` (*not a number*); com `int`, o programa quebra.

Vamos ver na prática. As cinco temperaturas entram uma a uma e cada uma
atualiza as caixinhas. O 999 não muda nada: só manda parar. No fim, as
caixinhas guardam as respostas:

{{ideia}}

Os cinco padrões juntos em C:

```c
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    const int FIM = 999;          // sentinela: nenhuma temperatura real vale 999
    int temp;
    int dias = 0;                 // contador
    int soma = 0;                 // acumulador
    int maior = 0, menor = 0;     // só valem depois do 1º dia
    bool calorao = false;         // flag: algum dia passou de 35?

    printf("Máxima do dia (999 encerra): ");
    if (scanf("%d", &temp) != 1) {
        temp = FIM;
    }
    while (temp != FIM) {
        dias++;
        soma += temp;
        if (dias == 1 || temp > maior) {
            maior = temp;
        }
        if (dias == 1 || temp < menor) {
            menor = temp;
        }
        if (temp >= 35) {
            calorao = true;       // levanta a flag e não abaixa mais
        }
        printf("Máxima do dia (999 encerra): ");
        if (scanf("%d", &temp) != 1) {
            temp = FIM;
        }
    }

    if (dias == 0) {
        printf("Nenhum dia lido.\n");
        return 0;
    }
    printf("Dias: %d\n", dias);
    printf("Média: %.1f °C\n", (double) soma / dias);
    printf("Maior: %d °C | Menor: %d °C\n", maior, menor);
    printf("Teve dia de 35 °C ou mais? %s\n", calorao ? "sim" : "não");
    return 0;
}
// Máxima do dia (999 encerra): 28
// Máxima do dia (999 encerra): 31
// Máxima do dia (999 encerra): 36
// Máxima do dia (999 encerra): 25
// Máxima do dia (999 encerra): 30
// Máxima do dia (999 encerra): 999
// Dias: 5
// Média: 30.0 °C
// Maior: 36 °C | Menor: 25 °C
// Teve dia de 35 °C ou mais? sim
```

Repara no fluxograma: tem **duas** caixas de leitura. "Ler temp" fica antes do
losango e roda uma vez; "Ler a próxima temp" fica no fim do corpo e é dela que
sai a seta de volta para o losango. Assim, a pergunta "temp != 999?" sempre
olha para o valor que acabou de chegar:

{{fluxograma}}

> [!WARNING]
> `maior = 0` parece inofensivo, até chegar o inverno na serra catarinense:
> com máximas de -3, -1 e -4 °C, nenhuma passa de 0, e o programa jura que o
> dia mais quente teve 0 °C, um dia que nunca existiu. O maior (e o menor)
> começa com o **primeiro valor lido**, como no código acima (`dias == 1 ||
> ...`). Outra saída é começar com o pior valor possível: `INT_MIN` para o
> maior e `INT_MAX` para o menor, de `<limits.h>` (assunto 0003).

> [!TIP]
> **Por dentro do C:** o acumulador tem os limites do tipo dele. Some salários
> num `int` e, passando de 2.147.483.647, a soma dá a volta e vira negativa
> (*overflow*, assunto 0003). Com `double`, o perigo é outro: 0,1 não tem
> representação exata em binário, então somar 0,1 dez vezes dá
> 0,9999999999999999, não 1. Para dinheiro, quem faz sistema de verdade
> acumula **centavos** num inteiro grande (`long long`) e só divide por 100 na
> hora de mostrar.

> [!NOTE]
> **Pergunta para você:** se a primeira coisa digitada for 999, o que o A049
> mostra? E se você apagar o `if (dias == 0)`, o que aconteceria na média?
> Preveja e teste com `printf '999\n' | ~/LPEDC/rodar ...`.

{{pratique}}
