## 0025 · Padrões de laço

Fim de semana de calor e você anotou a máxima de cada dia: 28, 31, 36, 25 e
30 °C. Agora quer saber quantos dias foram, qual a média, qual o dia mais
quente e o mais frio, e se teve algum dia de 35 °C ou mais. O laço que lê as
temperaturas você já sabe escrever. A dúvida é o que fazer com cada valor lido
para que, no fim, as respostas estejam prontas.

Cada uma dessas perguntas tem uma solução conhecida, um **padrão de laço**: um
jeito de usar uma variável que já foi resolvido milhares de vezes e que você
só precisa reconhecer (DEITEL; DEITEL, 2011, cap. 3). Todos seguem o mesmo
roteiro em três tempos. A variável ganha um valor **antes** do laço, é
atualizada **dentro** dele e é usada **depois**. Errar qualquer um dos três
tempos dá resposta errada, mesmo com o laço certo.

O **contador** responde "quantos?". Começa em 0 e soma 1 a cada volta:
`dias++`. O **acumulador** responde "quanto ao todo?". Também começa em 0, mas
soma o valor lido: `soma += temp` (DEITEL; DEITEL, 2011, cap. 3). Com os dois,
a média sai depois do laço. O acumulador também multiplica, e aí muda o ponto
de partida: um **produto** começa em 1, porque começar em 0 zera tudo na
primeira volta.

O **maior** e o **menor** guardam o recorde até agora. A cada valor lido, você
compara com o recorde e troca se o novo for melhor:
`if (temp > maior) maior = temp`. A pegadinha está no primeiro tempo. O
recorde começa com o **primeiro valor lido**, nunca com um número inventado
como 0, porque o 0 pode vencer todos os valores reais (BACKES, 2013, cap. 5).
O alerta no fim do texto mostra o caso.

A **flag** (bandeira) responde "aconteceu alguma vez?". É uma variável `bool`
que começa `false` e sobe para `true` quando o caso aparece:
`if (temp >= 35) calorao = true`. Ela só sobe, nunca desce. Se você puser um
`else calorao = false`, um dia de 25 °C depois do de 36 apaga a resposta, e a
flag passa a dizer só se o **último** dia foi quente (LEAL, 2016).

A **sentinela** resolve outro problema: como avisar ao programa que os dados
acabaram. Ela é um valor que **não pode** ser dado real e só serve para mandar
parar (DEITEL; DEITEL, 2011, cap. 3). Temperatura pode ser 0 ou negativa,
então a sentinela aqui é 999. Ela não entra em conta nenhuma: o laço testa o
valor antes de contar ou somar.

Para isso funcionar, a leitura aparece em dois lugares: uma vez **antes** do
laço e outra no **fim** do corpo. Essa é a **leitura antecipada**. Com ela, a
pergunta do `while` sempre olha um valor que acabou de chegar, e a sentinela é
barrada antes de entrar no corpo (DEITEL; DEITEL, 2011, cap. 3).

A média pede dois cuidados. O primeiro é o tipo: `soma / dias` com dois `int`
descarta os decimais, então você escreve `(double) soma / dias`, com o cast do
assunto 0008. O segundo é o zero: se a primeira entrada for a sentinela,
`dias` fica 0. Com `double`, 0 / 0 dá `nan` (*not a number*); com `int`, o
programa quebra. Teste `dias > 0` antes de dividir. E o acumulador tem os
limites do tipo: um `int` que passa de 2.147.483.647 estoura, e somar 0,1 em
`double` acumula erro de arredondamento. Para dinheiro, some **centavos** num
`long long` e divida por 100 só ao mostrar (DEITEL; DEITEL, 2011).

A tabela junta os padrões para consulta:

| Padrão | Antes do laço | Dentro do laço | Depois |
| --- | --- | --- | --- |
| **contador** | `dias = 0` | `dias++` | quantos foram |
| **acumulador** | `soma = 0` (produto: `= 1`) | `soma += temp` | total, média |
| **maior/menor** | o **primeiro** valor | `if (temp > maior) maior = temp` | o recorde |
| **flag** | `calorao = false` | `if (temp >= 35) calorao = true` | aconteceu ou não? |
| **sentinela** | ler o primeiro valor | ler o próximo, no fim | (o laço para nela) |

> [!WARNING]
> `maior = 0` parece inofensivo, até o inverno: com máximas de -3, -1 e -4 °C,
> o programa diz que o dia mais quente teve 0 °C, um dia que nunca existiu.
> Comece com o **primeiro valor lido** ou com `INT_MIN` (e `INT_MAX` para o
> menor), de `<limits.h>`.

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
