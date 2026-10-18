## 0027 · Juntando tudo

Todo filme de cassino tem a mesa de **craps**: alguém sopra os dados, joga e
a mesa inteira grita. As regras cabem em três linhas:

1. no **primeiro** lançamento de dois dados, soma 7 ou 11 **ganha** na hora;
   2, 3 ou 12 **perde** na hora;
2. qualquer outra soma (4, 5, 6, 8, 9 ou 10) vira o **ponto**;
3. daí em diante, você relança até tirar o ponto de novo (**ganha**) ou um 7
   (**perde**). As outras somas não fazem nada.

É o programa do módulo porque usa quase tudo o que veio até aqui: sorteio com
`rand` (assunto 0026), um `switch` com casos agrupados para o primeiro
lançamento (assunto 0018), um `while` para os relançamentos, com uma variável
de situação que funciona como flag (assuntos 0020 e 0025), e um contador de
lançamentos.

O `while` dos relançamentos é do tipo "não sei quantas voltas": pode acabar
no segundo lançamento ou no trigésimo. E a condição dele não é sobre os
dados, e sim sobre a **situação**: `0` continua, `1` ganhou, `-1` perdeu.
Quem muda a situação é o corpo do laço, que é o único lugar que sabe o que
saiu.

Repare num incômodo do código: o sorteio `1 + rand() % 6` aparece quatro
vezes. No módulo 04 ele vira uma **função** `lancar()` e o programa encolhe.
Por enquanto, a repetição de código é o preço de não ter funções ainda.

Vamos ver na prática. Com a semente 21, o primeiro lançamento dá 3 + 6 = 9. O
`switch` não acha o 9 em nenhum caso especial, e ele vira o ponto. O jogo
relança: 8, depois 5 (nada acontece), depois 9. Saiu o ponto antes do 7:
ganhou no quarto lançamento:

{{ideia}}

A rodada em C:

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

O exemplo A054 vai além: põe a rodada dentro de um menu com `do...while`,
valida a aposta com outro `do...while` e controla uma banca de R$ 100 até você
sair ou quebrar. É o mesmo algoritmo, embrulhado em mais dois laços.

Repara no fluxograma: as duas primeiras perguntas (7 ou 11? 2, 3 ou 12?) só
acontecem **uma vez**. O laço começa em "soma = novo lançamento", e a seta de
volta sai do Não de "soma == 7?". As duas saídas do laço vão para os mesmos
"Ganhou" e "Perdeu" do primeiro lançamento:

{{fluxograma}}

> [!WARNING]
> Num jogo com sorteio, o erro mais traiçoeiro é o laço que **pode** não
> terminar. Aqui ele sempre termina, porque a cada lançamento existe chance de
> sair o ponto ou o 7. Mas troque a condição para `while (soma != ponto)` e
> esqueça o 7: o jogo nunca perde, e o programa está errado sem dar erro
> nenhum. Antes de escrever um `while`, diga em voz alta **todas** as formas
> de sair dele, e confira se cada uma está na condição ou num `break`.

> [!TIP]
> **Por dentro do C:** a variável `situacao` guarda um código numérico (`1`,
> `-1`, `0`), e quem lê o código precisa lembrar o que cada número quer dizer.
> É um "número mágico". No módulo 08, o `enum` dá nome a esses valores
> (`GANHOU`, `PERDEU`, `CONTINUA`), mas por baixo continuam sendo `int`: o
> compilador troca cada nome pelo número, e o programa gerado é idêntico. O
> nome existe só para você.

> [!NOTE]
> **Pergunta para você:** qual é a chance de ganhar no craps? Antes de chutar,
> pense: no primeiro lançamento, o 7 e o 11 juntos saem em 8 de 36
> combinações. Depois, rode uma versão do A053 que joga 100 000 rodadas sem os
> `printf` e conta as vitórias (é o desafio 7 do módulo). A resposta é um
> pouco menos de 50%, e é daí que o cassino tira o lucro.

{{pratique}}
