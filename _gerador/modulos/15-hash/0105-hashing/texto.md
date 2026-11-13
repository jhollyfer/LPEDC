## 0105 · A ideia e a função hash

- **Endereçamento direto**: a chave é o próprio índice do vetor e o acesso
  custa O(1). Falha quando a chave é grande (um CPF tem 11 dígitos) ou não é
  número (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Função hash**: recebe a chave e devolve um índice de `0` a `m - 1`, com
  `m` o tamanho da tabela. O vetor é a **tabela hash** e cada posição é um
  **balde** (CORMEN et al., 2024, cap. 11).
- **Boa função**: **determinística** (mesma chave, mesmo índice), **rápida** e
  **espalhadora** (chaves diferentes em baldes diferentes). Deve depender de
  todas as partes da chave (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).
- **Método da divisão**: `h(k) = k mod m`, em C `k % m`. Prefira `m` primo e
  longe de potência de 2: com `m = 2^p`, o resto só vê os `p` bits de baixo
  (CORMEN et al., 2024, cap. 11). O **da multiplicação** fica para o 0178.
- **Colisão**: duas chaves diferentes no mesmo balde. Há mais chaves possíveis
  que baldes, então ela **vai** acontecer; trata-se nos assuntos 0106 e 0107
  (KNUTH, 1998, seção 6.4).
- **Fator de carga**: `α = n / m`, itens por balde. 5 itens em 7 baldes dão
  α ≈ 0,71; perto de 1, as colisões crescem (CORMEN et al., 2024, cap. 11).
- **Bytes sem sinal**: no gcc de PC, `char` tem sinal e letra acentuada em
  UTF-8 vira byte negativo. A função lê `unsigned char` e soma em `unsigned`,
  cujo estouro é definido (KERNIGHAN; RITCHIE, 1988, seção 6.6).

> [!WARNING]
> A soma **não vê a ordem das letras**: "amor", "roma", "mora" e "ramo" somam
> 431 e caem no mesmo balde. Use o **polinômio** `h = h * 31 + letra`, que
> multiplica cada letra pela sua posição (exemplo A210).

{{exemplo}}

O guarda-volumes da academia tem 7 armários, e a regra é "soma dos códigos das
letras, resto por 7". "caio" soma 412 e cai no 6; "bia" soma 300, também dá 6
e chegou antes. Os outros três caem em armários livres:

{{ideia}}

No código, o vetor `dono` é a tabela e `NULL` é armário vazio. O programa só
**detecta** a colisão:

```c
#include <stdio.h>

#define ARMARIOS 7

// função hash: soma os códigos das letras e reduz para 0..6
int armario(const char *nome) {
    unsigned soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += (unsigned char)nome[i]; // o byte da letra, sempre >= 0
    }
    return (int)(soma % ARMARIOS);
}

int main(void) {
    const char *dono[ARMARIOS] = {NULL}; // NULL = armário vazio
    const char *alunos[] = {"ana", "davi", "lia", "bia", "caio"};

    for (int i = 0; i < 5; i++) {
        int a = armario(alunos[i]);
        if (dono[a] == NULL) {
            dono[a] = alunos[i];
            printf("%-4s -> armário %d\n", alunos[i], a);
        } else {
            printf("%-4s -> armário %d (colisão com %s!)\n", alunos[i], a, dono[a]);
        }
    }
    return 0;
}
// Saída:
// ana  -> armário 3
// davi -> armário 0
// lia  -> armário 2
// bia  -> armário 6
// caio -> armário 6 (colisão com bia!)
```

O fluxograma mostra o caminho do "caio": quatro voltas no laço, índice 6,
armário ocupado, colisão:

{{fluxograma}}
