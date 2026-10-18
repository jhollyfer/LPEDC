## 0058 · Juntando tudo

O mercadinho da esquina ainda anota o fiado num caderno: nome do cliente e
quanto ele deve. Cliente novo ganha uma linha; cliente antigo soma na conta
dele; quem paga zera. O caderno nunca tem um número fixo de páginas, e cada
nome tem um tamanho. É um ótimo programa para juntar o módulo inteiro.

O programa usa tudo o que você viu:

- **heap** (0053): o caderno precisa durar o programa todo e crescer, então
  mora no heap, não na pilha;
- **malloc e free** (0054): cada nome é copiado para um bloco do tamanho
  exato com `duplicar`, o `strlen + 1` de sempre;
- **realloc** (0055): dois vetores paralelos (`nomes` e `centavos`) dobram de
  capacidade juntos quando enchem, sempre com ponteiro temporário;
- **vetor de ponteiros** (0056): `char **nomes` é um vetor de `char *`, cada
  um apontando para o seu bloco, como as linhas de uma matriz dinâmica com
  tamanhos diferentes;
- **erros de memória** (0057): para liberar, primeiro cada nome, depois os
  dois vetores. Nada sobra no heap.

Uma novidade: `crescer` recebe `char ***nomes`. Parece assustador, mas é a
mesma regra do E341 do assunto anterior. A função precisa **mudar** o
ponteiro `nomes` do `main` (o `realloc` pode trocar o endereço), então recebe
o endereço dele. `nomes` é `char **`; o endereço de `nomes` é `char ***`. O
mesmo vale para `int **centavos`.

Valores em centavos, como fazem os sistemas de pagamento: `int` não tem erro
de arredondamento, e R$ 12,50 vira `1250`.

Vamos ver na prática. Chegam seis anotações: Dona Cida (R$ 12,50), Seu Jorge
(R$ 8,30), Dona Cida de novo (R$ 4,70), Bia (R$ 20,00), Tonho (R$ 3,15) e
Rosa (R$ 5,60). São 5 clientes diferentes, então o caderno cresce de 2 para
4 e de 4 para 8. Depois Seu Jorge paga tudo:

{{ideia}}

O programa completo. Leia função por função: cada uma cuida de uma coisa e
nenhuma esquece um `free`:

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

Repara no fluxograma: cada anotação passa por uma busca. Achou, soma; não
achou, talvez cresça e cria uma linha nova. Todo caminho de erro termina em
`liberar`:

{{fluxograma}}

> [!WARNING]
> Liberar só `nomes` vaza todos os nomes: cada `nomes[i]` é um bloco
> separado, com o seu `malloc` (dentro de `duplicar`). Conte os `malloc` do
> programa: 2 no começo, 5 nomes e os `realloc`, que trocam um bloco por
> outro. No fim, `liberar` faz 5 + 2 `free`. Rode com `rodar --valgrind` e
> confira a linha `All heap blocks were freed`.

> [!TIP]
> **Por dentro do C:** os dois vetores paralelos são um remendo para a falta
> de um jeito de agrupar "nome e saldo" numa coisa só. É exatamente o que a
> `struct` resolve no módulo 08: um vetor de `struct cliente` com um `realloc`
> só. Mesmo assim, o desenho na memória continua parecido: o nome é um
> `char *` que aponta para um bloco do heap, e a struct guarda só os 8 bytes
> do ponteiro.

> [!NOTE]
> **Pergunta para você:** se Dona Cida pagar e você quiser **apagar** a linha
> dela (e não só zerar), o que precisa acontecer com `nomes[0]`, com as
> linhas de baixo e com `qtd`? Quantos `free` essa remoção faz?

{{pratique}}
