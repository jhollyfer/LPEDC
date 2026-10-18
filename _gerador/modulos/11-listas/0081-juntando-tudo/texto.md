## 0081 · Juntando tudo

Viagem de carro, celular no painel, a playlist tocando. Alguém pula duas
músicas, outra pessoa tira aquela que ninguém aguenta mais, e quando a última
acaba, o modo "repetir tudo" volta para a primeira. Por trás desse player tem
quase tudo deste módulo: uma lista dupla (anterior e próxima), busca e
remoção pelo título, um cursor que anda e, no repetir, a volta da lista
circular.

O programa do módulo é um **TAD playlist** completo, em `playlist.h` e
`playlist.c`. Desta vez os nós ficam **escondidos** de novo: quem usa a
playlist vê só a struct `Musica` (título, artista, segundos) e as operações.
Lá dentro, no `.c`, cada nó (`Faixa`) guarda uma `Musica` e os ponteiros
`ant` e `prox`, e a `struct playlist` guarda `inicio`, `fim`, `atual` (a
música que está tocando), `tamanho` e o `bool repetir`.

Cada peça do módulo aparece num lugar:

- **adicionar** é a inserção no fim da lista dupla (0079), com o `fim`
  guardado para custar O(1);
- **remover pelo título** é a busca com `strcmp` (0077) seguida da remoção
  dupla, com um cuidado novo: se a música removida era a que tocava, o
  `atual` passa para a seguinte (ou para a anterior, se era a última);
- **próxima** e **anterior** andam com `prox` e `ant`; na ponta, com repetir
  ligado, dão a volta como numa lista circular (0080);
- **salvar** e **carregar** usam arquivo texto (módulo 09): uma música por
  linha, no formato `titulo;artista;segundos`, lida com `fgets` e `sscanf`;
- **para cada** recebe um ponteiro para função e um `void *` (0050 e 0051),
  e assim quem usa a playlist percorre as músicas sem ver os nós.

O "repetir" mora numa função só:

```c
const Musica *playlist_proxima(Playlist *p) {
    if (p->atual == NULL) return NULL;
    if (p->atual->prox != NULL) p->atual = p->atual->prox;
    else if (p->repetir) p->atual = p->inicio;  // dá a volta
    else return NULL;                           // fim da playlist
    return &p->atual->musica;
}
```

Repare que a lista **não** é circular de verdade: o último `prox` continua
`NULL`. A volta é uma decisão da função, ligada ou desligada por um `bool`.
Assim o resto do código (imprimir, liberar, salvar) continua com o `for` de
sempre, sem risco de laço infinito.

Vamos ver na prática. A playlist começa com cinco músicas e 20:01 no total.
Pulando duas, toca a terceira. Depois a "Asa Branca" sai, a playlist chega na
última e, com o repetir ligado, a próxima volta para "Aquarela":

{{ideia}}

```c
#include <stdio.h>
#include "playlist.h"

int main(void) {
    Playlist *viagem = playlist_cria();
    if (viagem == NULL) return 1;
    playlist_adiciona(viagem, "Aquarela", "Toquinho", 252);
    playlist_adiciona(viagem, "Asa Branca", "Luiz Gonzaga", 186);
    playlist_adiciona(viagem, "Mas Que Nada", "Jorge Ben", 182);
    playlist_adiciona(viagem, "Evidências", "Chitãozinho e Xororó", 279);
    playlist_adiciona(viagem, "Tempo Perdido", "Legião Urbana", 302);

    int total = playlist_duracao(viagem);
    printf("%d músicas, %d:%02d no total\n", playlist_tamanho(viagem), total / 60, total % 60);

    playlist_proxima(viagem);
    playlist_proxima(viagem);   // pulou duas: agora toca a 3ª
    playlist_imprime(viagem);

    playlist_remove(viagem, "Asa Branca");
    playlist_proxima(viagem);
    playlist_proxima(viagem);   // chegou na última
    if (playlist_proxima(viagem) == NULL) printf("fim da playlist\n");

    playlist_repetir(viagem, true);
    printf("repetir ligado, próxima: %s\n", playlist_proxima(viagem)->titulo);
    printf("anterior: %s\n", playlist_anterior(viagem)->titulo);

    playlist_libera(viagem);
    return 0;
}
// Saída:
// 5 músicas, 20:01 no total
//   1. Aquarela - Toquinho (4:12)
//   2. Asa Branca - Luiz Gonzaga (3:06)
// > 3. Mas Que Nada - Jorge Ben (3:02)
//   4. Evidências - Chitãozinho e Xororó (4:39)
//   5. Tempo Perdido - Legião Urbana (5:02)
// fim da playlist
// repetir ligado, próxima: Aquarela
// anterior: Tempo Perdido
```

Repara no fluxograma da `playlist_proxima`: tocando "Tempo Perdido", não há
próxima. Na primeira tentativa o repetir está desligado e a função devolve
`NULL` ("fim da playlist"). Na segunda, ligado, o caminho é o verde: o
`atual` volta para o início:

{{fluxograma}}

O exemplo A162 grava a playlist em `playlist.txt`, libera tudo, carrega de
volta numa playlist nova e usa `playlist_para_cada` com um callback para
contar as músicas longas.

> [!WARNING]
> `playlist_proxima(viagem)->titulo` só é seguro quando você **sabe** que a
> função não vai devolver `NULL`, como no exemplo, com o repetir ligado e a
> playlist cheia. Com o repetir desligado na última música, o mesmo código
> acessa `NULL`. Em código de verdade, guarde o ponteiro e teste. E copie
> texto com `snprintf(destino, sizeof destino, "%s", origem)`: um título
> maior que 39 caracteres é cortado em vez de estourar o vetor, coisa que o
> `strcpy` faria sem pensar duas vezes.

> [!TIP]
> **Por dentro do C:** a `Musica` tem 40 + 30 bytes de texto, 2 de
> preenchimento e 4 do `int`: 76 bytes. A `Faixa` soma mais 4 de
> preenchimento (para o ponteiro começar num múltiplo de 8) e dois ponteiros:
> `sizeof(Faixa)` dá 96 bytes. O
> `const Musica *` que as funções devolvem aponta para **dentro** da faixa,
> no heap. Ele vale enquanto a música existir: depois de
> `playlist_remove` daquela música, é um ponteiro solto. É a mesma regra do
> vetor dinâmico (0075), em outra roupa: quem empresta um endereço de dentro
> da estrutura precisa dizer até quando ele vale.

> [!NOTE]
> **Pergunta para você:** se o exemplo chamasse `playlist_remove(viagem,
> "Tempo Perdido")` logo depois do "fim da playlist", qual música passaria a
> tocar? E se a playlist tivesse só essa música?

{{pratique}}
