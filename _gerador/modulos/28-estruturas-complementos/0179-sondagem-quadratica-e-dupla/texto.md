## 0179 · Sondagem quadrática e dupla

- **Sequência de sondagem**: no endereçamento aberto, cada chave tem uma lista
  de posições `h(k, 0), h(k, 1), ...`. A inserção para na primeira livre; a
  busca refaz o caminho até achar a chave ou uma livre (CORMEN et al., 2024, cap. 11).
- **Linear**: `h(k, i) = (h'(k) + i) mod m`. Sofre **agrupamento primário**:
  toda chave que cai em qualquer ponto de um bloco ocupado vai para o fim dele
  e o aumenta (CORMEN et al., 2024, cap. 11).
- **Quadrática**: `h(k, i) = (h'(k) + c₁·i + c₂·i²) mod m`. Os saltos crescem
  (1, 4, 9...) e os blocos se desfazem, mas sobra o **agrupamento
  secundário**: chaves com o mesmo `h'(k)` seguem a mesma trilha
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995).
- **Dispersão dupla**: `h(k, i) = (h₁(k) + i·h₂(k)) mod m`. O passo depende
  da chave, nunca é 0 e é primo com `m`; com `m` primo, `h₂(k) = 1 + (k mod
  (m - 1))` (CORMEN et al., 2024, cap. 11).
- **Fator de carga** `α = n / m`: com hash uniforme, a busca sem sucesso faz
  no máximo `1 / (1 - α)` sondagens em média, e a com sucesso,
  `(1/α) · ln(1 / (1 - α))`. Com α = 0,9: 10 e 2,6 (CORMEN et al., 2024, cap. 11).
- **Lápide** (*tombstone*): a remoção marca a posição como removida, nunca
  como livre, senão corta o caminho de quem pulou por ela. A busca passa reto;
  a inserção pode reaproveitar (TENENBAUM; LANGSAM; AUGENSTEIN, 1995).

> [!WARNING]
> O passo `h₂(k)` **não pode ser 0** nem ter fator comum com `m`: com `m = 12`
> e passo 4, a chave visita só 3 posições. Na quadrática com carga acima de
> 1/2, a inserção pode falhar **com posições livres**.

{{exemplo}}

Um guarda-volumes de 13 armários usa `cartão % 13`, e os cartões 18, 31, 44,
20 e 57 entram nas três tabelas; quatro deles começam no armário 5. No
desenho, as posições que a busca do 57 olha:

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

Na linear, o 20 cai no meio do bloco e vai para o 8. Na quadrática, 31, 44 e
57 repetem a trilha 5, 6, 9, 1. Na dupla, cada um sai do 5 com um passo
diferente. O fluxograma é a inserção do 57 na dupla: `(5 + 10) % 13 = 2` está
livre:

{{fluxograma}}
