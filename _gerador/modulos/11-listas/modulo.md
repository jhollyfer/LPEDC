# Módulo 11 · Listas

Até aqui você guardou coleções em vetores: tamanho fixo, itens lado a lado,
acesso instantâneo pelo índice. Só que quase nunca você sabe de antemão
quantos itens vão chegar. Por isso o módulo começa pelo vetor que cresce
sozinho, dobrando de tamanho quando enche.

Depois vem a primeira estrutura de dados feita só de ponteiros: a
**lista encadeada**. Cada item mora num pedaço separado do heap e sabe onde
está o próximo. Você troca o acesso direto pela liberdade de inserir e
remover sem empurrar ninguém. Vai fazer busca, remoção, inserção em ordem, a
lista dupla (que anda para os dois lados) e a circular (que não tem fim).

A mudança na cabeça é trocar posições por **setas**. Toda operação de lista é
"quem aponta para quem, antes e depois". O conselho do módulo inteiro
é desenhar os nós e as setas no papel antes de escrever o código. E
rode tudo com as flags de estudo: com ponteiros, o AddressSanitizer pega o que o olho
deixa passar.

## O que você vai aprender

- montar um **TAD lista sequencial** sobre um vetor que dobra de capacidade com `realloc`, e entender o custo amortizado
- criar **nós** com struct autorreferenciada, inserir no início, percorrer e liberar uma **lista encadeada**
- **buscar** e **remover** com o par de ponteiros `ant`/`p`, e por que remover o primeiro nó é um caso especial (e como sumir com ele)
- manter uma **lista ordenada** com inserção no lugar certo
- usar a **lista dupla** para andar nos dois sentidos e remover um nó em O(1)
- usar a **lista circular** para rodízios, guardando o ponteiro para o último nó
- juntar tudo num **TAD playlist** com arquivo, callbacks e tipo opaco

## Antes de começar

Nos desenhos, vermelho marca o nó que vai embora.

Você precisa estar firme em ponteiros (módulo 06), `malloc` e `free`
(módulo 07), structs e `->` (módulo 08) e no padrão TAD (assunto 0074). Se
`No **inicio` ainda assusta, releia o assunto 0049 antes do 0077.

Cada pasta de assunto traz um `lista.h` (a interface) e um `lista.c` (a
implementação): abra os dois junto com o exemplo. O comando do exemplo compila o
`lista.c` junto com o exemplo ou o exercício, porque ele está na mesma pasta:

```bash
gcc ~/LPEDC/11-listas/0076-lista-encadeada/A151.c ~/LPEDC/11-listas/0076-lista-encadeada/lista.c -o ~/LPEDC/11-listas/0076-lista-encadeada/A151 && ~/LPEDC/11-listas/0076-lista-encadeada/A151
```

Nos exercícios, não dê às suas funções o mesmo nome de uma função do
`lista.c` (como `lista_imprime`): o ligador reclamaria de nome repetido.
Os exercícios que usam outra estrutura trazem tudo no próprio arquivo.

> [!NOTE]
> Nos exercícios de "ache o bug", o código vem com o erro **de propósito**.
> Às vezes o próprio `gcc` já avisa; às vezes só o AddressSanitizer pega,
> quando o programa roda. Leia o relatório inteiro: ele diz o tipo do erro
> (`heap-use-after-free`, `heap-buffer-overflow`, `memory leaks`) e a linha.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para fazer num arquivo seu, misturando os assuntos do módulo. Use
o gcc com as flags de estudo em todos: resposta certa com vazamento não vale.

**1. Lista com ciclo.** Um bug deixou o `prox` do último nó apontando para
um nó do meio, e agora percorrer a lista nunca termina. Escreva
`bool tem_ciclo(const No *inicio)` que descobre isso sem alocar memória e sem
modificar a lista.

<details><summary>Resposta</summary>

Lebre e tartaruga (algoritmo de Floyd): a tartaruga anda 1 nó por vez e a
lebre anda 2. Se a lebre chegar em `NULL`, não há ciclo. Se houver, a lebre
dá a volta e alcança a tartaruga: `lebre == tartaruga` em algum momento.
O(n) de tempo, O(1) de memória. Bônus: depois do encontro, volte a tartaruga
para o início e ande os dois de 1 em 1; eles se encontram no primeiro nó do
ciclo.

</details>

**2. O k-ésimo a partir do fim.** Numa lista simples de tamanho desconhecido,
ache o 3º nó contando do fim, percorrendo a lista uma vez só. Em
`10 -> 20 -> 30 -> 40 -> 50`, a resposta é 30.

<details><summary>Resposta</summary>

Dois ponteiros com distância fixa: adiante o primeiro 3 nós; depois ande os
dois juntos até o primeiro virar `NULL`. O segundo está no 3º a partir do
fim. Trate a lista com menos de 3 nós (o primeiro vira `NULL` antes de
completar os 3 passos).

</details>

**3. Interseção de listas ordenadas.** Dadas duas listas crescentes, monte
uma terceira (nova, com `malloc`) só com os valores que aparecem nas duas.
Para `1 3 4 7 9` e `2 3 7 8 9`, o resultado é `3 7 9`.

<details><summary>Resposta</summary>

Um ponteiro em cada lista, como na intercalação do E466: se os valores são
iguais, copie para a resposta e ande os dois; senão ande só o do menor.
O(n + m), sem nenhum laço aninhado. Inserir no fim com um ponteiro para o
último mantém a ordem.

</details>

**4. Números gigantes.** Um `long long` vai até uns 9 × 10¹⁸. Some
`98765432109876543210` com `12345678901234567890` guardando cada número numa
lista com **um dígito por nó, do menos significativo para o mais**.

<details><summary>Resposta</summary>

**111111111011111111100**. Com os dígitos de trás para frente, a soma anda
nas duas listas do começo, igual à conta armada: dígito = (a + b + vai_um) %
10, vai_um = (a + b + vai_um) / 10. No fim, se sobrar vai-um, crie mais um
nó. Para imprimir, use recursão (como no E454) ou uma lista dupla e ande do
fim para o começo.

</details>

**5. Desfazer e refazer.** Um editor guarda o histórico de versões numa
lista dupla com um cursor na versão atual (`inicio`, `fim` e `cursor` numa
struct `Historico`). Escreva `digita` (que **descarta e libera** as versões
à frente do cursor antes de inserir a nova depois dele), `desfaz` (volta o
cursor, se der), `refaz` (avança, se der) e `mostra` (imprime as versões com
a atual entre colchetes). Digite "v1" a "v4", desfaça duas vezes, refaça uma,
digite "v5" e tente refazer, mostrando a lista depois de cada passo.

<details><summary>Resposta</summary>

```
digitou 4:   v1 v2 v3 [v4]
desfez 2:    v1 [v2] v3 v4
refez 1:     v1 v2 [v3] v4
digitou v5:  v1 v2 v3 [v5]
refez 1:     v1 v2 v3 [v5]
```

Dica: no `digita`, libere todos os nós depois do cursor, faça
`cursor->prox = NULL` e `fim = cursor`, e só então insira no fim. É o
comportamento de todo editor: depois de editar, o "refazer" some. Esquecer os
`free` desses nós é vazamento, e o gcc com as flags de estudo acusa.

</details>

**6. LRU: o cache das páginas recentes.** Um navegador guarda as últimas 3
páginas visitadas numa lista dupla (cada nó guarda um `char`). Visitar uma
página que já está na lista leva ela para a frente; visitar uma nova com a
lista cheia expulsa (e libera) a mais antiga, a do fim. Escreva
`void visita(char pg)` e simule as visitas A, B, C, A, D, B, imprimindo a
lista depois de cada uma.

<details><summary>Resposta</summary>

```
A -> A
B -> B A
C -> C B A
A -> A C B
D -> D A C
B -> B D A
```

Dica: duas funções auxiliares resolvem tudo: `desliga(p)` tira o nó da lista
sem liberar (cuidando de `inicio` e `fim`) e `poe_na_frente(p)` insere no
início. Página encontrada: desliga e põe na frente. Página nova: se cheia,
desliga e libera o `fim`; depois cria o nó e põe na frente. Achar ainda é
O(n); com uma tabela hash (módulo 15) apontando para os nós, tudo vira O(1).

</details>

**7. Sem casos especiais.** Reescreva a lista dupla do assunto 0079 com um
**nó sentinela** circular: um nó de mentira cujo `prox` é o primeiro e cujo
`ant` é o último. Lista vazia é a sentinela apontando para si mesma nos dois
sentidos. Quantos `if` sobram na inserção e na remoção?

<details><summary>Resposta</summary>

**Nenhum.** Todo nó real tem anterior e seguinte de verdade (às vezes a
sentinela), então remover é sempre `p->ant->prox = p->prox; p->prox->ant =
p->ant;` e inserir depois de `q` é sempre as mesmas quatro atribuições.
Inserir no início é inserir depois da sentinela; no fim, depois de
`sentinela->ant`. Percorrer vai de `s->prox` até voltar a `s`.

</details>

**8. Inverter de k em k.** Inverta uma lista simples em blocos de 3 nós, só
mexendo nos ponteiros. `1 2 3 4 5 6 7 8` vira `3 2 1 6 5 4 8 7` (o último
bloco incompleto também é invertido).

<details><summary>Resposta</summary>

Aplique a inversão do E456 em pedaços: inverta 3 nós, guardando o primeiro
do bloco (que vira o último) e o início do resto. Ligue o fim do bloco
invertido ao resultado da inversão do resto. Com recursão fica curto:
`inverte_k(inicio)` inverte os 3 primeiros e faz
`primeiro_do_bloco->prox = inverte_k(resto)`.

</details>

**9. Ordenar uma lista em O(n log n).** O E468 ordena por inserção em
O(n²). Escreva o **merge sort** de lista: divida a lista ao meio, ordene cada
metade recursivamente e intercale. Teste com `5 1 4 2 8 3 7 6`.

<details><summary>Resposta</summary>

Para dividir, use a lebre e a tartaruga (E462): quando a lebre chega ao fim,
corte depois da tartaruga (`meio = tartaruga->prox; tartaruga->prox =
NULL`). Caso base: lista com 0 ou 1 nó. Junte com a intercalação do E466.
Resultado `1 2 3 4 5 6 7 8`. Na lista, o merge sort não precisa de vetor
auxiliar: só religa nós. É o assunto 0094, um módulo adiantado.

</details>

**10. Josephus: fórmula contra lista.** Com n pessoas em roda e eliminando
de k em k, a posição do sobrevivente (contando de 0) obedece a J(1) = 0 e
J(n) = (J(n − 1) + k) % n. Escreva um programa que, para n = 8 e k = 3,
imprima J(1) a J(8) com um laço e o sobrevivente (numerado de 1), e depois
simule a roda com uma lista circular (como a batata quente do A160),
imprimindo a ordem de saída e quem sobra.

<details><summary>Resposta</summary>

```
formula: J(1)=0 J(2)=1 J(3)=1 J(4)=0 J(5)=3 J(6)=0 J(7)=3 J(8)=6
sobrevivente pela formula: pessoa 7
simulacao: saem 3 6 1 5 2 8 4, sobra a pessoa 7
```

Dica: a fórmula é um laço `for (m = 2; m <= n; m++) j = (j + k) % m;`,
O(n) e sem memória, e a pessoa é `j + 1`. A simulação começa com `ant` no
último nó e `p` no primeiro e anda `k - 1` passos antes de cada remoção. A
fórmula só diz quem sobra; a lista dá a **ordem** de eliminação e aguenta
variações que a fórmula não cobre (passo diferente para cada pessoa, alguém
entrando no meio).

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado do PPGI/UFAM. Leia,
decida e só depois abra o gabarito. Nas que têm código, desenhe os nós e as
setas e simule à mão. As questões de código e de simulação foram conferidas
rodando programas em C (`gcc -std=c17 -Wall`, com AddressSanitizer). Os nós
são do tipo do assunto 0076: `typedef struct no { int valor; struct no *prox; } No;`.
Desconfie de "sempre", "com certeza" e "nunca".

**Questão 1.** Com o código abaixo, qual afirmação é **correta**?

```c
void insere_inicio(No *prim, int v) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = v;
        novo->prox = prim;
        prim = novo;
    }
}

int main(void) {
    No *lista = NULL;
    insere_inicio(lista, 3);
    insere_inicio(lista, 8);
    imprime(lista);
    return 0;
}
```

- (A) Imprime `8 3`.
- (B) Imprime `3 8`.
- (C) Imprime só `8`.
- (D) Não imprime nenhum valor e os dois nós alocados ficam perdidos na memória.
- (E) Falha de segmentação ao imprimir, porque `lista` é `NULL`.

<details><summary>Gabarito</summary>

**(D)**. O C passa tudo por valor: `prim` dentro da função é uma **cópia**
de `lista`. A atribuição `prim = novo` muda a cópia, e a `lista` do `main`
continua `NULL`. Cada chamada aloca um nó que ninguém mais alcança (vazamento).
`imprime(NULL)` com laço `while (p != NULL)` simplesmente não imprime nada,
então não há falha (E). A correção é receber `No **prim` e fazer `*prim = novo`.
Veja 0076 e 0049.

</details>

**Questão 2.** A lista tem os valores 8 e 3 (montada corretamente). Sobre a
função abaixo, é **correto** afirmar que:

```c
int soma(No *prim) {
    No *p = malloc(sizeof(No));
    int s = 0;
    p = prim;
    while (p != NULL) {
        s += p->valor;
        p = p->prox;
    }
    return s;
}
```

- (A) Devolve 11, mas a cada chamada perde um bloco de memória alocado.
- (B) Devolve 0, porque `p` começa apontando para um nó sem valor.
- (C) Falha de segmentação, porque `p` termina valendo `NULL`.
- (D) Devolve 11 e não tem nenhum problema de memória.
- (E) Não compila, porque `p` é declarado e depois reatribuído.

<details><summary>Gabarito</summary>

**(A)**. A soma está certa: `p = prim` descarta o nó recém-alocado e o laço
percorre a lista de verdade. Mas esse `malloc` fica sem ponteiro e sem `free`:
um bloco perdido por chamada (o LeakSanitizer acusa isso). Para percorrer
uma lista não se aloca nada. Veja 0076 e 0054.

</details>

**Questão 3.** A função deveria remover o primeiro nó de uma lista
simplesmente encadeada. Qual alternativa descreve o que o código faz?

```c
void remove_primeiro(No **prim) {
    if (*prim != NULL) {
        No *aux = *prim;
        free(aux);
        *prim = aux->prox;
    }
}
```

- (A) Funciona: o nó sai e `*prim` passa a apontar para o segundo.
- (B) Funciona, mas vaza o nó removido.
- (C) Não compila, porque `aux` é usado depois do `free`.
- (D) Só dá problema se a lista tiver um único nó.
- (E) Lê `aux->prox` depois do `free(aux)`: comportamento indefinido.

<details><summary>Gabarito</summary>

**(E)**. O `free(aux)` devolve o bloco, e a linha seguinte ainda lê
`aux->prox` dele. O compilador deixa passar (o `gcc -Wall` até avisa), mas
o AddressSanitizer reporta `heap-use-after-free`. Como o bloco liberado
costuma continuar com o conteúdo antigo, o código pode "funcionar" por
sorte, e por isso é perigoso. A ordem certa é guardar
`aux->prox` em `*prim` e só então dar o `free`. Veja 0076, 0077 e 0057.

</details>

**Questão 4.** Considere as afirmações sobre listas simplesmente encadeadas
e vetores de `n` elementos:

I. Remover um nó do meio da lista, já tendo o ponteiro para o nó anterior,
não obriga a mover nenhum outro nó.
II. Acessar o k-ésimo elemento da lista custa O(1), como no vetor.
III. A lista ocupa sempre menos memória que um vetor com os mesmos `n`
elementos.
IV. Inserir no início da lista custa O(1), qualquer que seja `n`.

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas I e IV.
- (D) Apenas II, III e IV.
- (E) Todas estão corretas.

<details><summary>Gabarito</summary>

**(C)**. I e IV são verdadeiras: só se religam ponteiros, sem mover nós. II é
falsa: para chegar ao k-ésimo é preciso andar k nós, O(k). III é falsa por
causa do "sempre": cada nó guarda também o `prox`, então a lista costuma
gastar mais que o vetor. Veja 0075 e 0076.

</details>

**Questão 5.** Considere as afirmações sobre listas duplamente encadeadas e
circulares:

I. Na lista duplamente encadeada, dado só o ponteiro para um nó, é possível
removê-lo sem percorrer a lista desde o início.
II. Numa lista circular, o laço `while (p != NULL)` pode nunca terminar, porque
nenhum nó aponta para `NULL`.
III. A lista duplamente encadeada gasta o mesmo espaço por nó que a
simplesmente encadeada.

- (A) Apenas I.
- (B) Apenas I e II.
- (C) Apenas II e III.
- (D) Apenas I e III.
- (E) Todas estão corretas.

<details><summary>Gabarito</summary>

**(B)**. I é verdadeira: o nó conhece o anterior (`ant`) e o próximo
(`prox`), então basta religar os dois vizinhos. II é verdadeira: na circular
o último aponta para o primeiro, e o laço precisa parar ao voltar ao ponto de
partida. III é falsa: o nó da dupla carrega um ponteiro a mais (`ant`).
Veja 0079 e 0080.

</details>

**Questão 6.** Considere as afirmações sobre vetor dinâmico e lista ordenada:

I. Se o vetor dobra de capacidade sempre que fica cheio, inserir `n` itens
copia, no total, menos de 2n elementos.
II. Depois de um `realloc`, um ponteiro guardado antes para um item do vetor
continua válido, sempre.
III. Inserir um valor numa lista encadeada ordenada de `n` nós custa O(n) no
pior caso.
IV. Como a lista está ordenada, dá para achar a posição de inserção com busca
binária em O(log n).

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas III e IV.
- (D) Apenas I, II e IV.
- (E) Apenas I e III.

<details><summary>Gabarito</summary>

**(E)**. I é verdadeira: as cópias somam 1 + 2 + 4 + ... < 2n. II é falsa
("sempre"): o `realloc` pode mover o bloco, e o ponteiro antigo passa a
apontar para memória liberada. III é verdadeira: no pior caso o valor vai
para o fim, depois de `n` nós. IV é falsa: a lista não tem acesso direto ao
meio, então não há busca binária. Veja 0075 e 0078.

</details>

**Questão 7.** Uma lista começa vazia. `insere_inicio(v)` e `insere_fim(v)`
colocam o valor no começo e no fim, e `remove(v)` tira a **primeira**
ocorrência de `v` (se existir). Depois das operações abaixo, a lista, do
início ao fim, é:

```text
insere_fim(4)   insere_inicio(9)   insere_fim(6)   insere_inicio(4)
remove(4)       insere_fim(1)      remove(7)        remove(6)
```

- (A) `9 6 1`
- (B) `9 4 1`
- (C) `4 9 1`
- (D) `4 9 6 1`
- (E) `9 4 6 1`

<details><summary>Gabarito</summary>

**(B)**. Passo a passo: `4`; `9 4`; `9 4 6`; `4 9 4 6`. O `remove(4)`
tira a primeira ocorrência (a do início): `9 4 6`. Entra o 1 no fim:
`9 4 6 1`. O `remove(7)` não encontra nada e não muda a lista, e o
`remove(6)` deixa `9 4 1`. A (A) é o erro de remover o segundo 4. Veja 0076 e 0077.

</details>

**Questão 8.** Numa lista duplamente encadeada `... <-> p <-> q <-> ...`, o
nó `n` deve ser inserido entre `p` e `q = p->prox` (com `q` existente). Qual
sequência de atribuições deixa os dois sentidos da lista corretos?

- (A) `n->prox = p->prox; n->ant = p; p->prox->ant = n; p->prox = n;`
- (B) `n->prox = p->prox; n->ant = p; p->prox = n; p->prox->ant = n;`
- (C) `p->prox = n; n->prox = p->prox; n->ant = p; p->prox->ant = n;`
- (D) `n->ant = p; n->prox = p->prox; p->prox = n;`
- (E) `n->prox = p; n->ant = p->prox; p->prox = n; p->prox->ant = n;`

<details><summary>Gabarito</summary>

**(A)**. O ponto é a **ordem**: enquanto `p->prox` ainda é `q`, ele serve
para alcançar `q` e ligar `q->ant = n`; só depois `p->prox` passa a ser `n`.
Na (B), a linha `p->prox->ant = n` roda com `p->prox` já valendo `n`, e
o `n` vira o próprio anterior. Na (C), `n->prox = p->prox` faz o nó apontar
para si mesmo. A (D) esquece o `q->ant`: andando de trás para a frente o
`n` é pulado. A (E) inverte os campos. Veja 0079.

</details>

**Questão 9.** Um vetor dinâmico nasce com capacidade 3 (alocado com
`malloc`). Antes de cada inserção, se `tam == cap`, ele dobra a capacidade
com `realloc`. Depois de inserir 100 itens, quantas vezes o `realloc` rodou e
qual é a capacidade final?

- (A) 5 vezes, capacidade 96.
- (B) 6 vezes, capacidade 100.
- (C) 7 vezes, capacidade 192.
- (D) 6 vezes, capacidade 192.
- (E) 33 vezes, capacidade 100.

<details><summary>Gabarito</summary>

**(D)**. O `realloc` roda ao inserir o 4º item (3 para 6), o 7º (12), o 13º
(24), o 25º (48), o 49º (96) e o 97º (192): 6 vezes, e sobram 92 posições.
Com 96 itens ainda cabe na capacidade 96; é o 97º que dobra de novo. A (C)
conta a alocação inicial como se fosse `realloc`. Veja 0075.

</details>

**Questão 10.** Marque a alternativa **INCORRETA** sobre custos em listas
encadeadas com `n` nós.

- (A) Numa lista simples com ponteiro só para o início, inserir no fim custa O(n).
- (B) Numa lista simples com ponteiros para o início e para o fim, inserir no fim custa O(1).
- (C) Numa lista simples com ponteiros para o início e para o fim, remover o último nó custa O(1).
- (D) Numa lista dupla com ponteiros para o início e para o fim, remover o último nó custa O(1).
- (E) Buscar uma chave numa lista não ordenada custa O(n) no pior caso.

<details><summary>Gabarito</summary>

**(C)**. Para remover o último nó da lista simples é preciso mudar o `prox`
do **penúltimo**, e o ponteiro `fim` não diz quem ele é: só percorrendo desde o
início, O(n). Na lista dupla o último tem `ant`, e a remoção é O(1) (D).
Inserir no fim com `fim` guardado é O(1) (B) e sem ele é O(n) (A). Veja
0076 e 0079.

</details>

## Para ler mais

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 10: estruturas de dados elementares (listas ligadas e sentinelas).
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010. Cap. 3: estruturas de dados básicas (listas lineares).
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. 10: listas encadeadas.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Cap. 4: listas encadeadas. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 4: filas e listas.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Cap. 6: lista.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, Departamento de Eletrônica e Telecomunicações.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 12: estruturas de dados.
- BACKES, A. *Linguagem C: descomplicada* (apostila). Cap. sobre alocação dinâmica e structs.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 6.5: estruturas autorreferenciadas.
- CPPREFERENCE. *realloc*. Disponível em: <https://en.cppreference.com/w/c/memory/realloc>.
- GCC. *AddressSanitizer*. Disponível em: <https://github.com/google/sanitizers/wiki/AddressSanitizer>.
