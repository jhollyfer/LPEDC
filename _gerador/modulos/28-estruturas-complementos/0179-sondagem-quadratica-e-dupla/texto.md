## 0179 · Sondagem quadrática e dupla

O guarda-volumes tem 13 armários, escolhidos por `cartão % 13`. Se estiver
ocupado, o funcionário tenta outro: no 0107, o **seguinte** (sondagem
linear). Cinco clientes chegam com os cartões 18, 31, 44, 20 e 57, e quatro
caem no armário 5. Qual é o melhor "outro"?

No endereçamento aberto, cada chave tem uma **sequência de sondagem** `h(k,
0), h(k, 1), ...`. A inserção para na primeira posição livre; a busca refaz o
caminho até achar a chave ou uma livre. O Cormen apresenta três:

- **linear**: `h(k, i) = (h'(k) + i) mod m`. Sofre de **agrupamento
  primário**: as ocupadas formam blocos, e toda chave que cai **em qualquer
  ponto** do bloco vai para o fim dele e o aumenta;
- **quadrática**: `h(k, i) = (h'(k) + c₁·i + c₂·i²) mod m`. Com c₁ = 0 e c₂ =
  1, os saltos crescem (1, 4, 9, 16...) e os blocos se desfazem. Sobra o
  **agrupamento secundário**: chaves com o mesmo `h'(k)` seguem **a mesma
  trilha**, que com `m` primo visita só metade das posições (carga abaixo de
  1/2);
- **dispersão dupla** (*double hashing*): `h(k, i) = (h₁(k) + i·h₂(k)) mod m`.
  O passo `h₂(k)` depende da chave, então chaves do mesmo início andam com
  passos diferentes: é a que mais se aproxima do hash uniforme. O passo nunca
  é 0 e tem que ser **primo com m**: com `m` primo, `h₁(k) = k mod m` e
  `h₂(k) = 1 + (k mod (m - 1))`; com `m = 2^p`, um `h₂` sempre ímpar.

O **fator de carga** `α = n / m` manda no custo. Com hash uniforme, uma busca
**sem sucesso** faz em média no máximo `1 / (1 - α)` sondagens, e uma **com
sucesso**, `(1/α) · ln(1 / (1 - α))`: com α = 0,5, 2 e 1,4; com α = 0,9, 10 e
2,6. A linear é pior (o A357 mede 45 sondagens com α = 0,9).

Nas três, a **remoção** deixa uma **lápide** (*tombstone*), nunca uma posição
livre, que cortaria o caminho de quem pulou por ela. A busca passa reto pela
lápide; a inserção pode reaproveitá-la.

Os cinco cartões entram nas três tabelas. No desenho, as posições que a
busca do 57 olha:

{{ideia}}

A sequência de sondagem do `sondagem.c` (modo escolhido na criação):

```c
int sd_posicao(const Sondagem *t, int chave, int i) {
    int m = t->m;
    int h1 = chave % m;
    switch (t->modo) {
    case SD_LINEAR:
        return (h1 + i) % m;
    case SD_QUADRATICA:
        return (int)((h1 + (long)i * i) % m);
    default: { // dupla: o passo h2 depende da chave e nunca é 0
        int h2 = 1 + chave % (m - 1);
        return (int)((h1 + (long)i * h2) % m);
    }
    }
}
```

Inserção, busca e remoção chamam `sd_posicao(t, chave, i)`. O
guarda-volumes:

```c
#include <stdio.h>
#include "sondagem.h"

int main(void) {
    const char *nomes[] = {"linear:    ", "quadrática:", "dupla:     "};
    int cartoes[] = {18, 31, 44, 20, 57};
    printf("           ");
    for (int j = 0; j < 13; j++) {
        printf(" %3d", j);
    }
    printf("\n");
    for (int modo = 0; modo < 3; modo++) {
        Sondagem *t = sd_cria(13, (ModoSondagem)modo);
        if (t == NULL) {
            return 1;
        }
        int total = 0;
        for (int i = 0; i < 5; i++) {
            int s;
            sd_insere(t, cartoes[i], &s);
            total += s;
        }
        printf("%s", nomes[modo]);
        sd_mostra(t);
        int s;
        sd_busca(t, 57, &s);
        printf("            sondagens para guardar: %d | para achar o 57: %d\n", total, s);
        sd_libera(t);
    }
    return 0;
}
// Saída:
//               0   1   2   3   4   5   6   7   8   9  10  11  12
// linear:       .   .   .   .   .  18  31  44  20  57   .   .   .
//             sondagens para guardar: 13 | para achar o 57: 5
// quadrática:   .  57   .   .   .  18  31  20   .  44   .   .   .
//             sondagens para guardar: 11 | para achar o 57: 4
// dupla:       31  44  57   .   .  18   .  20   .   .   .   .   .
//             sondagens para guardar: 8 | para achar o 57: 2
```

Na linear, o 20 (começa no 7) cai no meio do bloco e vai para o 8. Na
quadrática, 31, 44 e 57 repetem a trilha 5, 6, 9, 1. Na dupla, o 31 anda de 8
em 8, o 44 de 9 em 9 e o 57 de 10 em 10: cada um sai do 5 para um lugar
diferente.

O fluxograma é a inserção do 57 na dupla: o 5 está ocupado, `i` vira 1, e
`(5 + 10) % 13 = 2` está livre:

{{fluxograma}}

> [!WARNING]
> O passo `h₂(k)` **não pode ser 0** nem ter fator comum com `m`: com `m = 12`
> e passo 4, a chave visita só 3 das 12 posições e a inserção falha com a
> tabela quase vazia. Na quadrática, com carga acima de 1/2, ela pode falhar
> **com posições livres**.

> [!NOTE]
> **Pergunta para você:** na tabela da dispersão dupla do exemplo, chega o
> cartão 70 (70 % 13 = 5, passo 1 + 70 % 12 = 11). Em que posição ele fica, e
> com quantas sondagens? E na linear?

{{pratique}}
