## 0058 · Juntando tudo

- **Heap** (0053): o caderno de fiado dura o programa todo e cresce, então mora
  no heap (CELES; RANGEL, 2002).
- **`malloc` e `free`** (0054): `duplicar` copia cada nome para um bloco do
  tamanho exato, `strlen + 1` (BACKES, 2013, cap. 11).
- **`realloc`** (0055): dois vetores paralelos (`nomes` e `centavos`) dobram a
  capacidade juntos, com ponteiro temporário (CELES; RANGEL, 2002).
- **Vetor de ponteiros** (0056): `char **nomes` é um vetor de `char *`, como as
  linhas de tamanhos diferentes de uma matriz dinâmica (BACKES, 2013, cap. 11).
- **`char ***`**: `crescer` precisa mudar o ponteiro `nomes` do `main`, então
  recebe o endereço dele (assunto 0049) (FEOFILOFF, 2009, ap. F).
- **Centavos**: valores em `int` não têm erro de arredondamento; R$ 12,50 vira
  `1250`.

> [!WARNING]
> Liberar só `nomes` vaza todos os nomes: cada `nomes[i]` tem seu `malloc`. São
> 2 `malloc` no começo e 5 nomes, então `liberar` faz 5 + 2 `free`. Confira com
> `valgrind ./programa` a linha `All heap blocks were freed`.

{{exemplo}}

Chegam seis anotações: Dona Cida (R$ 12,50), Seu Jorge (R$ 8,30), Dona Cida de
novo (R$ 4,70), Bia (R$ 20,00), Tonho (R$ 3,15) e Rosa (R$ 5,60). São 5
clientes, então o caderno cresce de 2 para 4 e de 4 para 8. Depois Seu Jorge
paga tudo:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cópia de uma string num bloco do tamanho exato.
char *duplicar(const char *texto) {
    char *copia = malloc(strlen(texto) + 1);
    if (copia != NULL) {
        strcpy(copia, texto);
    }
    return copia;
}

// Dobra a capacidade dos dois vetores paralelos. Recebe o ENDEREÇO dos
// ponteiros do main (char *** e int **) porque o realloc pode mudá-los.
int crescer(char ***nomes, int **centavos, int *cap) {
    int nova = *cap * 2;
    char **mais_nomes = realloc(*nomes, nova * sizeof **nomes);
    if (mais_nomes == NULL) {
        return 0;
    }
    *nomes = mais_nomes;
    int *mais_centavos = realloc(*centavos, nova * sizeof **centavos);
    if (mais_centavos == NULL) {
        return 0;
    }
    *centavos = mais_centavos;
    printf("(caderno cresceu: %d -> %d clientes)\n", *cap, nova);
    *cap = nova;
    return 1;
}

int buscar(char **nomes, int qtd, const char *nome) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Soma uma compra na conta do cliente; cria a conta se ela não existe.
int anotar(char ***nomes, int **centavos, int *qtd, int *cap, const char *nome, int valor) {
    int i = buscar(*nomes, *qtd, nome);
    if (i >= 0) {
        (*centavos)[i] += valor;
        return 1;
    }
    if (*qtd == *cap && !crescer(nomes, centavos, cap)) {
        return 0;
    }
    char *copia = duplicar(nome);
    if (copia == NULL) {
        return 0;
    }
    (*nomes)[*qtd] = copia;
    (*centavos)[*qtd] = valor;
    (*qtd)++;
    return 1;
}

void liberar(char **nomes, int *centavos, int qtd) {
    for (int i = 0; i < qtd; i++) {
        free(nomes[i]); // cada nome é um bloco
    }
    free(nomes);        // depois o vetor de ponteiros
    free(centavos);
}

int main(void) {
    int qtd = 0;
    int cap = 2;
    char **nomes = malloc(cap * sizeof *nomes);
    int *centavos = malloc(cap * sizeof *centavos);
    if (nomes == NULL || centavos == NULL) {
        free(nomes);
        free(centavos);
        return 1;
    }

    const char *quem[] = {"Dona Cida", "Seu Jorge", "Dona Cida", "Bia", "Tonho", "Rosa"};
    int valor[] = {1250, 830, 470, 2000, 315, 560}; // em centavos
    for (int k = 0; k < 6; k++) {
        if (!anotar(&nomes, &centavos, &qtd, &cap, quem[k], valor[k])) {
            liberar(nomes, centavos, qtd);
            return 1;
        }
    }

    int i = buscar(nomes, qtd, "Seu Jorge"); // Seu Jorge pagou tudo
    if (i >= 0) {
        centavos[i] = 0;
    }

    int total = 0;
    for (int k = 0; k < qtd; k++) {
        printf("%-10s R$ %3d.%02d\n", nomes[k], centavos[k] / 100, centavos[k] % 100);
        total += centavos[k];
    }
    printf("Total na rua: R$ %d.%02d\n", total / 100, total % 100);

    liberar(nomes, centavos, qtd);
    return 0;
}
// Saída:
// (caderno cresceu: 2 -> 4 clientes)
// (caderno cresceu: 4 -> 8 clientes)
// Dona Cida  R$  17.20
// Seu Jorge  R$   0.00
// Bia        R$  20.00
// Tonho      R$   3.15
// Rosa       R$   5.60
// Total na rua: R$ 45.95
```

Cada anotação passa por uma busca. Achou, soma; não achou, talvez cresça e cria
a linha. Todo caminho de erro termina em `liberar`:

{{fluxograma}}
