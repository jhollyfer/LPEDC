## 0079 · Lista dupla

Na Estrada de Ferro Carajás, um trem de minério para no pátio de manobras.
O terceiro vagão, com 87 toneladas, está com o freio travado e precisa sair.
O manobrista vai direto até ele, solta o engate da frente e o de trás, e
engata o segundo vagão no quarto. Ele não precisa voltar até a locomotiva
para descobrir quem vem antes do vagão quebrado: ele está vendo.

Na lista simples, o nó só conhece o próximo. Para remover um nó, você
precisa do anterior, e achar o anterior custa percorrer desde o início. Na
**lista duplamente encadeada**, cada nó guarda **dois** ponteiros: `prox`
(o próximo) e `ant` (o anterior). Com isso:

- dá para andar nos **dois sentidos**: do início para o fim e do fim para o
  início;
- dá para remover um nó conhecendo **só ele**, em O(1);
- guardando também o ponteiro para o **último** nó, inserir no fim vira O(1).

Por isso a lista desta pasta não é só um `No *`. Ela é uma struct que guarda
as duas pontas e o tamanho, e que pode morar numa variável do `main`:

```c
typedef struct no {
    int valor;
    struct no *ant;  // o anterior, ou NULL no primeiro
    struct no *prox; // o próximo, ou NULL no último
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;
```

A lista dupla tem uma regra que nunca pode quebrar: para todo nó `p` que não
é o último, `p->prox->ant == p`. Toda operação mexe nas setas **aos pares**,
e esquecer uma delas é o erro clássico.

Remover o nó `p` é desviar as duas setas que chegam nele, cada uma com o seu
caso de borda:

```c
void lista_remove_no(Lista *l, No *p) {
    if (p->ant == NULL) l->inicio = p->prox;  // era o primeiro
    else p->ant->prox = p->prox;              // o anterior pula o p
    if (p->prox == NULL) l->fim = p->ant;     // era o último
    else p->prox->ant = p->ant;               // o seguinte pula o p para trás
    free(p);
    l->tamanho--;
}
```

Vamos ver na prática. O trem tem os vagões de 98, 105, 87 e 110 toneladas.
Com `p` no vagão de 87, a seta de cima faz o 105 apontar para o 110, e a de
baixo faz o 110 apontar de volta para o 105. Ninguém precisou ser procurado:

{{ideia}}

```c
#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista trem;
    lista_inicia(&trem);
    int cargas[] = {98, 105, 87, 110}; // toneladas, da locomotiva para o fim
    for (int i = 0; i < 4; i++) lista_insere_fim(&trem, cargas[i]);

    printf("da locomotiva: ");
    lista_imprime(&trem);
    printf("do fim:        ");
    lista_imprime_reverso(&trem);

    No *vagao = lista_busca(&trem, 87);
    if (vagao != NULL) {
        lista_remove_no(&trem, vagao); // sem procurar o anterior: p->ant
        printf("desengatou o vagão de 87 t (%d vagões)\n", trem.tamanho);
    }

    printf("da locomotiva: ");
    lista_imprime(&trem);
    printf("do fim:        ");
    lista_imprime_reverso(&trem);

    lista_libera(&trem);
    return 0;
}
// Saída:
// da locomotiva: 98 <-> 105 <-> 87 <-> 110
// do fim:        110 <-> 87 <-> 105 <-> 98
// desengatou o vagão de 87 t (3 vagões)
// da locomotiva: 98 <-> 105 <-> 110
// do fim:        110 <-> 105 <-> 98
```

Repara no fluxograma: são duas perguntas independentes, uma para cada
ponta. O vagão de 87 tem anterior e tem seguinte, então o caminho passa pelos
dois Não. Para remover o primeiro vagão, a primeira pergunta daria Sim; para
o último, a segunda:

{{fluxograma}}

Imprimir de trás para frente é o mesmo `for` de sempre, começando em
`l->fim` e andando com `p = p->ant`. O exemplo A158 usa essa ida e volta para
fazer um controle remoto com "canal seguinte" e "canal anterior".

> [!WARNING]
> Lista dupla com uma seta faltando **parece certa**. Se a inserção esquecer o
> `ant`, andar para frente funciona e só o caminho de volta sai errado, às
> vezes muito depois, em outra parte do programa. Teste sempre imprimindo
> **nos dois sentidos**. E na remoção, os dois casos de borda são
> obrigatórios: `p->ant->prox` com `p` no primeiro nó é acessar `NULL`, e
> esquecer de atualizar o `fim` deixa ele apontando para memória liberada.

> [!TIP]
> **Por dentro do C:** num PC de 64 bits, `sizeof(No)` passa de 16 para 24
> bytes: 4 do `int`, 4 de preenchimento e dois ponteiros de 8. É 50% a mais de
> memória por nó, o preço das remoções em O(1) e da volta. Existe um truque
> antigo para economizar: guardar num campo só o **XOR** dos dois endereços
> (`ant ^ prox`, convertidos para `uintptr_t`). Quem vem andando de um lado
> conhece um dos vizinhos e recupera o outro com mais um XOR. Funciona, mas
> nenhum depurador entende, e o ganho raramente compensa.

> [!NOTE]
> **Pergunta para você:** se `lista_insere_fim` esquecesse a linha `novo->ant =
> l->fim;`, o que `lista_imprime` mostraria para o trem do exemplo? E
> `lista_imprime_reverso`?

{{pratique}}
