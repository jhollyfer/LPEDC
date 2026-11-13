## 0025 · Padrões de laço

- **Padrão de laço**: um uso de variável já resolvido milhares de vezes. A
  variável ganha valor **antes** do laço, muda **dentro** e é usada **depois**
  (DEITEL; DEITEL, 2011, cap. 3).
- **Contador e acumulador**: o contador soma 1 a cada volta; o acumulador soma
  o valor lido. Ambos começam em 0; o acumulador de **produto** começa em 1
  (DEITEL; DEITEL, 2011, cap. 3).
- **Maior e menor**: começam com o **primeiro valor lido**, nunca com 0
  (BACKES, 2013, cap. 5).
- **Flag**: um `bool` que só sobe. Sem `else flag = false`, senão um valor
  comum depois do especial apaga a resposta (LEAL, 2016).
- **Sentinela**: valor que **não pode** ser dado real e só manda parar; não
  entra em conta nenhuma (DEITEL; DEITEL, 2011, cap. 3).
- **Leitura antecipada**: lê **antes** do laço e no **fim** do corpo, para a
  pergunta do `while` olhar sempre um valor recém-lido
  (DEITEL; DEITEL, 2011, cap. 3).
- **Média**: `(double) soma / dias`, e só com `dias > 0`. Com 0 / 0, o `double`
  dá `nan` e o `int` derruba o programa. O acumulador também estoura: para
  dinheiro, some **centavos** num `long long` (DEITEL; DEITEL, 2011).

| Padrão | Antes do laço | Dentro do laço | Depois |
| --- | --- | --- | --- |
| **contador** | `dias = 0` | `dias++` | quantos foram |
| **acumulador** | `soma = 0` (produto: `= 1`) | `soma += temp` | total, média |
| **maior/menor** | o **primeiro** valor | `if (temp > maior) maior = temp` | o recorde |
| **flag** | `calorao = false` | `if (temp >= 35) calorao = true` | aconteceu ou não? |
| **sentinela** | ler o primeiro valor | ler o próximo, no fim | (o laço para nela) |

> [!WARNING]
> `maior = 0` falha no inverno: com máximas de -3, -1 e -4 °C, o programa diz
> que o dia mais quente teve 0 °C. Comece com o **primeiro valor lido** ou com
> `INT_MIN` (e `INT_MAX` para o menor), de `<limits.h>`.

{{exemplo}}

As máximas de cinco dias: 28, 31, 36, 25 e 30 °C, e 999 como sentinela (uma
temperatura pode ser 0 ou negativa). Cada valor atualiza as caixinhas; o 999
só manda parar:

{{ideia}}

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

Há **duas** caixas de leitura: "Ler temp", antes do losango, e "Ler a próxima
temp", no fim do corpo, de onde sai a seta de volta:

{{fluxograma}}
