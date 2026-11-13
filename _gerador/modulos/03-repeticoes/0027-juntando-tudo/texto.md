## 0027 · Juntando tudo

- **Craps**: jogo de dois dados. No **primeiro** lançamento, soma 7 ou 11
  ganha e 2, 3 ou 12 perde; qualquer outra soma vira o **ponto**. Depois,
  relança até repetir o ponto (ganha) ou tirar 7 (perde)
  (DEITEL; DEITEL, 2011, cap. 5).
- **Peças do módulo**: sorteio com `rand` (0026), `switch` com casos agrupados
  no primeiro lançamento (0018), `while` nos relançamentos (0020) e um
  contador de lançamentos (0025).
- **Variável de situação**: funciona como flag. `0` continua, `1` ganhou, `-1`
  perdeu; só o corpo do laço sabe o que saiu, então só ele a muda
  (DEITEL; DEITEL, 2011, cap. 5).
- **Número mágico**: `1`, `-1` e `0` exigem lembrar o significado. No módulo
  08, o `enum` dá nomes a eles (`GANHOU`, `PERDEU`, `CONTINUA`).
- **Repetição de código**: o sorteio `1 + rand() % 6` aparece quatro vezes. No
  módulo 04 ele vira a função `lancar()`.

> [!WARNING]
> Confira se o laço **termina**. Com `while (soma != ponto)` e sem o 7, o jogo
> nunca perde e o programa está errado sem dar erro. Antes de escrever um
> `while`, diga **todas** as formas de sair dele e confira cada uma.

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
