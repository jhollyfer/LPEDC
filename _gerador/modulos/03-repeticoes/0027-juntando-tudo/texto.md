## 0027 · Juntando tudo

Cada assunto do módulo resolveu um pedaço: repetir enquanto algo vale,
repetir pelo menos uma vez, contar, sair no meio, sortear. Um programa de
verdade raramente usa uma peça só. Este assunto monta um jogo inteiro com
elas, para você ver as peças encaixadas e treinar a pergunta que mais importa
num laço: como ele termina?

O jogo é o **craps**, o dos dados da mesa de cassino (DEITEL; DEITEL, 2011,
cap. 5). Você lança dois dados e olha a soma. No **primeiro** lançamento, 7 ou
11 **ganha** na hora, e 2, 3 ou 12 **perde** na hora. Qualquer outra soma (4,
5, 6, 8, 9 ou 10) vira o **ponto**, o número que você precisa repetir. A
partir daí, você relança até tirar o ponto de novo, e **ganha**, ou até tirar
um 7, e **perde**. As outras somas não fazem nada.

Cada regra vira uma peça já conhecida. O lançamento é o sorteio com
`1 + rand() % 6` para cada dado (assunto 0026). O primeiro lançamento tem
três destinos, decididos por valores exatos da soma, e o `switch` com casos
agrupados resolve isso: `case 7: case 11:` ganha, `case 2: case 3: case 12:`
perde, e o `default` guarda o ponto (assunto 0018). Os relançamentos são um
`while` (assunto 0020), e um contador de lançamentos (assunto 0025) diz em
que jogada a partida acabou.

O `while` dos relançamentos é do tipo "não sei quantas voltas": a partida
pode acabar no segundo lançamento ou no trigésimo. Por isso a condição não
conta voltas. Ela testa uma **variável de situação**, que guarda o estado da
partida: `0` continua, `1` ganhou, `-1` perdeu (DEITEL; DEITEL, 2011, cap. 5).
Ela funciona como a flag do assunto 0025, com um valor a mais. Só o corpo do
laço sabe o que saiu no dado, então só ele muda a situação.

Os valores `1`, `-1` e `0` são **números mágicos**: códigos que só fazem
sentido para quem lembra o que cada um quer dizer. Quem lê `situacao == -1`
precisa voltar ao começo do programa para entender. O módulo 08 resolve isso
com o `enum`, que dá nomes a esses valores (`GANHOU`, `PERDEU`, `CONTINUA`);
por baixo, eles continuam sendo `int`.

O programa também mostra o que ainda falta. O sorteio `1 + rand() % 6`
aparece quatro vezes no código, dois dados no primeiro lançamento e dois nos
relançamentos. Repetir a mesma conta em vários lugares obriga a corrigir
todos quando algo muda. No módulo 04 o sorteio vira uma **função** chamada
`lancar()`, escrita uma vez e usada onde for preciso, e o programa encolhe.

Por fim, a pergunta do começo. Este laço sempre termina, porque a cada
lançamento há chance de sair o ponto ou o 7. Mas a garantia depende de as
duas saídas estarem no código, e é essa conferência que o alerta pede.

> [!WARNING]
> Confira se o laço **termina**. Com `while (soma != ponto)` e sem o 7, o jogo
> nunca perde e o programa está errado sem dar erro nenhum. Antes de escrever
> um `while`, diga **todas** as formas de sair dele e confira se cada uma está
> na condição ou num `break`.

{{exemplo}}

Com a semente 21, o primeiro lançamento dá 3 + 6 = 9, que vira o ponto. O
jogo relança: 8, depois 5 (nada acontece), depois 9. Saiu o ponto antes do 7:
ganhou no quarto lançamento:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    srand(21); // semente fixa: a rodada abaixo se repete (glibc)

    int d1 = 1 + rand() % 6;
    int d2 = 1 + rand() % 6;
    int soma = d1 + d2;
    int lancamentos = 1;
    int ponto = 0;
    int situacao; // 1 = ganhou, -1 = perdeu, 0 = continua

    printf("Lançamento %d: %d + %d = %d\n", lancamentos, d1, d2, soma);
    switch (soma) {
    case 7:
    case 11:
        situacao = 1;          // natural: ganha de cara
        break;
    case 2:
    case 3:
    case 12:
        situacao = -1;         // craps: perde de cara
        break;
    default:
        situacao = 0;          // virou o ponto
        ponto = soma;
        printf("Ponto: %d. Agora precisa repetir o %d antes de um 7.\n", ponto, ponto);
    }

    while (situacao == 0) {
        d1 = 1 + rand() % 6;
        d2 = 1 + rand() % 6;
        soma = d1 + d2;
        lancamentos++;
        printf("Lançamento %d: %d + %d = %d\n", lancamentos, d1, d2, soma);
        if (soma == ponto) {
            situacao = 1;
        } else if (soma == 7) {
            situacao = -1;
        }
    }

    printf("%s em %d lançamentos.\n", situacao == 1 ? "Ganhou" : "Perdeu", lancamentos);
    return 0;
}
// Saída (glibc, Linux):
// Lançamento 1: 3 + 6 = 9
// Ponto: 9. Agora precisa repetir o 9 antes de um 7.
// Lançamento 2: 3 + 5 = 8
// Lançamento 3: 1 + 4 = 5
// Lançamento 4: 4 + 5 = 9
// Ganhou em 4 lançamentos.
```

O A054 vai além: menu com `do...while`, aposta validada e uma banca de R$ 100.
No fluxograma, as perguntas do primeiro lançamento acontecem **uma vez**; o
laço começa em "soma = novo lançamento" e volta pelo Não de "soma == 7?":

{{fluxograma}}
