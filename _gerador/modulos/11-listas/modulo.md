# Módulo 11 · Listas

O vetor tem tamanho fixo, mas você quase nunca sabe quantos itens vão chegar.
O módulo começa pelo vetor que dobra quando enche.

Depois vem a **lista encadeada**, a primeira estrutura feita só de ponteiros:
cada item mora num pedaço do heap e sabe onde está o próximo. Troca-se o
acesso direto pela liberdade de inserir e remover sem empurrar ninguém. Seguem
busca, remoção, inserção em ordem, a lista dupla e a circular.

Toda operação de lista é "quem aponta para quem": desenhe os nós e as setas
antes de codar e compile com as flags de estudo, para o AddressSanitizer pegar
os erros de ponteiro.

## O que você vai aprender

- montar um **TAD lista sequencial** sobre um vetor que dobra com `realloc`, e
  o custo amortizado
- criar **nós** com struct autorreferenciada, inserir no início, percorrer e
  liberar uma **lista encadeada**
- **buscar** e **remover** com o par `ant`/`p`, e por que remover o primeiro
  nó é caso especial (e como eliminá-lo)
- manter uma **lista ordenada** inserindo no lugar certo
- usar a **lista dupla** para andar nos dois sentidos e remover em O(1)
- usar a **lista circular** para rodízios
- juntar tudo num **TAD playlist** com arquivo, callbacks e tipo opaco

## Antes de começar

Este módulo usa ponteiros (módulo 06, incluindo `No **inicio`, assunto 0049),
`malloc` e `free` (módulo 07), structs e `->` (módulo 08) e o padrão TAD
(assunto 0074). O vetor dinâmico estende o `realloc` do módulo 07 e a lista
encadeada é a base do módulo 12 (pilhas e filas), que reaproveita nós e setas
com outras regras de acesso.

Cada assunto traz `lista.h` (interface) e `lista.c` (implementação). O
comando compila o `lista.c` junto com o exemplo ou exercício:

```bash
gcc ~/LPEDC/11-listas/0076-lista-encadeada/A151.c ~/LPEDC/11-listas/0076-lista-encadeada/lista.c -o ~/LPEDC/11-listas/0076-lista-encadeada/A151 && ~/LPEDC/11-listas/0076-lista-encadeada/A151
```

Nos exercícios, não repita o nome de uma função do `lista.c` (como
`lista_imprime`): o ligador reclama. Exercícios com outra estrutura trazem
tudo no arquivo. Nos desenhos, vermelho marca o nó que sai.

> [!NOTE]
> Nos exercícios de "ache o bug", o erro vem **de propósito**. Às vezes o
> `gcc` avisa; às vezes só o AddressSanitizer pega, ao rodar. Leia o relatório
> inteiro: ele traz o tipo do erro (`heap-use-after-free`,
> `heap-buffer-overflow`, `memory leaks`) e a linha.

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

## Questões de provas do PPGI

Questões reais das provas de conhecimento do PPGI/UFAM, na íntegra e com o gabarito oficial. Resolva no papel, em 3 minutos por questão, e só depois abra o gabarito.

**Edital 032/2016 · Questão 03**

Quando um novo nó é removido no meio de uma lista encadeada dinâmica, qual das seguintes afirmações é verdadeira:

- a) Somente os nós que aparecem após o novo nó precisam ser movidos
- b) Somente os nós que aparecem antes do novo nó precisam ser movidos
- c) Os nós que aparecem antes do novo nó e o último nó precisam ser movidos
- d) Os nós que aparecem depois do novo nó e o primeiro nó precisam ser movidos
- e) Nenhuma das opções acima

<details><summary>Gabarito</summary>

**E.** Remover no meio de lista encadeada só religa ponteiros, nenhum nó é movido. Assunto 0076.

</details>

**Edital 032/2016 · Questão 08**

Considere os códigos de funções abaixo, assumindo que os mesmos são usados dentro de um programa e que os todos os cabeçalhos necessários são incluídos:

```c
/*QUADRO I) Código para inserir em uma lista
encadeada. Cada nó da lista tem um campo
prox, que é usado para encadea-lo ao próximo
elemento, e tem um dado do tipo int. */
/* prim é um ponteiro para o ponteiro ao
primeiro elemento da lista */
void insere(tipoNo **prim, int d) {
  tipoNo *aux;
  aux = (tipoNo *)malloc(sizeof(tipoNo));
  if(aux) { aux ->prox = *prim;
    *prim = aux;
    aux -> dado = d;
  }
}
```

```c
/*QUADRO II) Código para remover primeiro
elemento de uma lista encadeada. Cada nó da
lista tem um campo prox, que é usado para
encadea-lo ao próximo elemento, e tem um
dado do tipo int. */
/* prim é um ponteiro para o ponteiro ao
primeiro elemento da lista */
1. void remove (tipoNo **prim){
2.   tipoNo *aux;
3.   if(*prim) { aux = *prim;
4.     *prim = aux->prox;
5.     free(*prim);
6.     *prim = aux;
7.   }
8. }
```

Marque a alternativa correta dentre as afirmações abaixo:

- a) Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica, de vazamento de memória ou falha de segmentação
- b) Apenas os código I realiza sem erros a tarefa descrita nos comentários
- c) Apenas os código II realiza sem erros a tarefa descrita nos comentários
- d) Os dois códigos não executam suas tarefas como descrito nos comentários, mas também não geram vazamento de memória
- e) O primeiro código gera vazamento de memória e o segundo não realiza a tarefa descrita nos comentários

<details><summary>Gabarito</summary>

**B.** O insere está certo; o remove dá free no novo início (*prim) e depois faz *prim = aux, apontando para nó já removido. Assunto 0076.

</details>

**Edital 053/2016 · Questão 06**

Marque a alternativa CORRETA.
Uma lista duplamente encadeada tem como característica ser formada por elementos que:

- a) se concatenam de forma circular, de tal maneira que, ao chegar ao final da lista, o próximo elemento volta a ser o primeiro.
- b) contêm, além de um ou mais campos chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista.
- c) contêm, além de um campo chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista, de tal forma que os campos chave estão ordenados, ou seja, a chave do próximo é sempre maior ou igual à chave do atual elemento.
- d) contêm, além de um ou mais campos chave, dois outros campos de ponteiros: próximo e anterior, que permitem o acesso aos elementos adjacentes (próximo e anterior) presentes na mesma lista.
- e) Estão em posições adjacentes da memória, permitindo o acesso sequencial ao próximo e ao anterior de cada elemento pelo simples uso de um índice.

<details><summary>Gabarito</summary>

**D.** Dois ponteiros por nó: próximo e anterior. Assunto 0079.

</details>

**Edital 053/2016 · Questão 09**

Os registros em uma lista duplamente encadeada com 20 elementos possuem, cada um, três campos:

1. próximo: um ponteiro para o próximo elemento da lista;
2. valor: informação armazenada pelo elemento;
3. anterior: um ponteiro para o elemento anterior da lista.

Sendo "Z" o décimo elemento desta lista e "X" e "Y" dois outros elementos que não pertencem à lista, sendo apontados, respectivamente, pelos seguintes ponteiros "PZ", "PX" e "PY", considere o trecho de código abaixo.

```
PY->próximo = PX;
PX->anterior = PY;
PX->próximo = PZ->próximo;
PZ->próximo->anterior = PX;
PZ->próximo = PY;
PY->anterior = PZ;
```

Este trecho de código é usado para inserir na lista os elementos:

- a) Y, logo após o Z, e X, logo após o Y.
- b) Y, antes do Z, e X, logo após o Z
- c) Y, antes do Z, e X, antes do Y.
- d) X, logo após o Z, e Y, logo após o X.
- e) X, antes do Z, e Y, logo após o Z.

<details><summary>Gabarito</summary>

**A.** As linhas ligam Z → Y → X → antigo próximo de Z. Assunto 0079.

</details>

**Edital 024/2017 · Questão 04**

Considere as seguintes afirmações sobre a estrutura lista encadeada dinâmica e marque a alternativa CORRETA.

I. A busca em tal estrutura realiza menos comparações do que a melhor opção de algoritmo de busca em um vetor ordenado quando se considera o pior cenário para cada estrutura.\
II. É uma estrutura de dados usada para ordenar chaves por ser mais eficiente no processo de ordenação que o heapsort\
III. É tipicamente utilizada como estrutura de dados básica na implementação de hash por endereçamento aberto\

- a) As três afirmações são falsas
- b) As três afirmações são verdadeiras
- c) Apenas a afirmação I é verdadeira
- d) Apenas a afirmação II é verdadeira
- e) Apenas a afirmação III é verdadeira

<details><summary>Gabarito</summary>

**A.** busca em lista é O(n) contra O(log n) no vetor; lista não ordena melhor que heapsort; endereçamento aberto usa vetor Assunto 0076.

</details>

**Edital 024/2017 · Questão 05**

Dada uma lista encadeada onde cada nó da lista é do tipo No, cujos campos são um ponteiro para o próximo elemento (campo prox) e um dado do tipo inteiro (campo dado). Dado também quatro (4) opções (versões) de funções para realizar a busca por um elemento em uma lista encadeada, onde recebe-se um ponteiro para o primeiro elemento da lista e uma chave. A função de busca deve retornar 1 (um) caso encontre o elemento buscado e 0 (zero) em caso contrário.

Com base nas informações anteriores, considere que: (1) a lista encadeada não possui um nó cabeça de lista, portanto todos os nós contém valores presentes na lista; (2) todos os tipos de dados foram previamente declarados no programa; (3) a função não deve ter problemas de alocação de memória, seja por deixar de alocar dinamicamente dados necessários ou por causar alocação dinâmica de dados desnecessária.

Analise as funções abaixo e marque a alternativa CORRETA

```c
/* versão I */
int busca(No *prim, int chave) {
  No *aux = (No *) malloc(sizeof(No));
  aux = prim;
  while(aux!= NULL) {
    if(aux->dado == chave) return 1;
    aux = aux>prox;
  }
  return 0;
}

/* versão II */
int busca(No *prim, int chave) {
  while(prim!= NULL) {
    if(prim->dado == chave) return 1;
    prim = prim->prox;
  }
  return 0;
}

/* versão III */
int busca(No *prim, int chave) {
  No * aux = prim;
  while(prim->prox!= NULL) {
    if(prim->dado == chave) return 1;
    aux = aux->prox;
  }
  return 0;
}

/* versão IV */
int busca(No *prim, int chave) {
  No *aux = (No *) malloc(sizeof(No));
  while(aux->prox!= NULL) {
    if(aux->dado == chave) return 1;
    aux = aux>prox;
  }
  return 0;
}
```

- a) A versão I está correta e não apresenta problemas de alocação de memória.
- b) A versão II está correta e não apresenta problemas de alocação de memória.
- c) A versão III está correta e não apresenta problemas de alocação de memória
- d) A versão IV está correta e não apresenta problemas de alocação de memória
- e) Nenhuma das alternativas anteriores está correta

<details><summary>Gabarito</summary>

**B.** só a versão II percorre sem malloc e sem erro; I vaza memória e tem `aux>prox`, III e IV têm laço errado Assunto 0076.

</details>

**Edital 024/2017 · Questão 18**

Considere o código abaixo, assumindo que o mesmo é usado dentro de um programa e que os todos os cabeçalhos necessários são incluídos:

```c
// Conta ocorrências de uma chave na lista encadeada, retornando o total de ocorrências , zero caso a chave não ocorra
int ContaOcorrenciasChave(tipoNo *prim, int chave) {
  tipoNo *aux = prim;
  int cont = 0;
  int x;
  for (x = 0; aux[x] != NULL; x++){
    if(aux[x].dado == chave)
      cont++;
  }
  return x;
}
```

Marque a alternativa CORRETA dentre as afirmações abaixo:

- a) O código executa a tarefas proposta sem gerar qualquer tipo de erro de lógica ou de vazamento de memória
- b) O código nem compila
- c) O código executa a tarefa proposta sem erros de lógica
- d) O código não gera erro de segmentação
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**E.** Assunto 0076.

</details>

**Edital 024/2017 · Questão 19**

Uma lista encadeada simples é uma estrutura que corresponde a uma sequência lógica de entradas ou nós. Cada nó armazena a localização do próximo elemento na sequência, ou seja, de seu nó sucessor.

Marque a alternativa CORRETA:

- a) A existência de um ponteiro apontando para o 1º elemento e outro para o fim da lista permite que a inserção ou deleção de dados de um nó que esteja nas extremidades da lista seja rapidamente executada
- b) Enquanto a entrada que determina o topo da lista é mantida em um nó descritor dessa lista, a entrada que marca o fim da lista é mantida em todos os nós da lista.
- c) O armazenamento de uma lista requer uma área contígua de memória para permitir a otimização no processamento de busca de valores chaves na lista
- d) O armazenamento de uma lista requer uma área contígua de memória. Como listas são estruturas previamente projetadas e definidas, normalmente são definidos procedimentos que permitem inserir e remover valores com eficiência.
- e) Para estabelecer a ligação entre um nó já pertencente a uma lista e um novo nó, basta fazer com que o novo nó referencie no campo next, o nó que anteriormente era referenciado pelo nó original, desde que esse campo não tenha o valor nulo

<details><summary>Gabarito</summary>

**A.** ponteiros para início e fim dão acesso rápido às extremidades; as outras são falsas ou truncadas Assunto 0076.

</details>

**Edital 024/2017 · Questão 20**

Marque a alternativa CORRETA. Uma lista duplamente encadeada tem como característica ser formada por elementos que:

- a) Se concatenam de forma circular, de tal maneira que, ao chegar ao final da lista, o próximo elemento volta a ser o primeiro.
- b) Contêm, além de um ou mais campos chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista.
- c) Contêm, além de um campo chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista, de tal forma que os campos chave estão ordenados, ou seja, a chave do próximo é sempre maior ou igual à chave do atual elemento.
- d) Contêm, além de um ou mais campos chave, dois outros campos de ponteiros: próximo e anterior, que permitem o acesso aos elementos adjacentes (próximo e anterior) presentes na mesma lista.
- e) Estão em posições adjacentes da memória, permitindo o acesso sequencial ao próximo e ao anterior de cada elemento pelo simples uso de um índice.

<details><summary>Gabarito</summary>

**D.** lista dupla tem próximo e anterior (mesmas alternativas da 053/2016 Q06) Assunto 0079.

</details>

**Edital 055/2017 · Questão 11**

Considere as seguintes afirmações sobre a estrutura lista encadeada dinâmica

I. A busca em tal estrutura realiza menos comparações do que a melhor opção de algoritmo de busca em um vetor ordenado quando se considera o pior cenário para cada estrutura.\
II. É uma estrutura de dados usada unicamente no armazenamento de grandes quantidades de chaves por lista, dado o seu dinamismo e velocidade de busca quando comparada a outras estruturas de dados.\
III. É utilizada como estrutura de dados na implementação de alguns tipos de hash.\

Marque a alternativa CORRETA:

- A) As três afirmações são falsas
- B) Apenas a afirmação I é verdadeira
- C) Apenas a afirmação II é verdadeira
- D) Apenas a afirmação III é verdadeira
- E) Apenas as afirmações I e II são verdadeiras.

<details><summary>Gabarito</summary>

**D.** I falsa (lista é O(n)), II falsa ("unicamente"), III verdadeira (encadeamento) Assunto 0076.

</details>

**Edital 023/2018 · Questão 09**

Os registros em uma lista, duplamente encadeada com 20 elementos possuem cada um três campos:

- próximo: um ponteiro para o próximo elemento da lista;
- valor: informação armazenada pelo elemento;
- anterior: um ponteiro para o elemento anterior da lista.

Sendo "Z" o décimo elemento desta lista e "X" e "Y" dois outros elementos que não pertencem à lista, com seus respectivos ponteiros "pZ", "pX" e "pY", considere o trecho de código abaixo.

```
pY↑.próximo = pX;
pX↑.anterior = pY;
pX↑.próximo = pZ↑.próximo;
pZ↑.próximo↑.anterior = pX;
pZ↑.próximo = pY;
pY↑.anterior = pZ;
```

Este trecho de código é usado para inserir na lista os elementos:

- a) Y, logo após o Z, e X, logo após o Y.
- b) Y, antes do Z, e X, logo após o Z.
- c) Y, antes do Z, e X, antes do Y.
- d) X, logo após o Z, e Y, logo após o X.
- e) X, antes do Z, e Y, logo após o Z.

<details><summary>Gabarito</summary>

**A.** Ficam Z, Y, X, antigo próximo de Z: Y logo após Z e X logo após Y. Assunto 0079.

</details>

**Edital 023/2018 · Questão 19**

Marque a alternativa CORRETA. Uma lista encadeada simples é uma estrutura que corresponde a uma sequência lógica de entradas ou nós. Cada nó armazena a localização do próximo elemento na sequência, ou seja, de seu nó sucessor. Nessa estrutura:

- a) Para estabelecer a ligação entre um nó já pertencente a uma lista e um novo nó, basta fazer com que o novo nó referencie no, campo next, o nó que anteriormente era referenciado pelo nó original, desde que esse campo não tenha o valor nulo.
- b) A existência de um ponteiro apontando para o 1º elemento e outro para o fim da lista permite que a inserção ou deleção de dados de um nó que esteja no meio da lista seja rapidamente executada.
- c) Enquanto a entrada que determina o topo da lista é mantida em um nó descritor dessa lista, a entrada que marca o fim da lista é mantida fora do descritor.
- d) O armazenamento de uma lista requer uma área contígua de memória para permitir a otimização no processamento de criação e remoção de nós da lista.
- e) O armazenamento de uma lista não requer uma área contígua de memória. Como listas são estruturas dinâmicas, normalmente são definidos procedimentos que permitem criar e remover nós na memória.

<details><summary>Gabarito</summary>

**E.** Lista encadeada não exige área contígua e cria e remove nós dinamicamente. Assunto 0076.

</details>

**Edital 023/2018 · Questão 20**

A estrutura de dados é um modo de armazenamento e organização de dados para que possam ser usados eficientemente. Dentre as alternativas abaixo, sobre as afirmações de estrutura de dados, escolha a CORRETA:

I. Uma fila é uma estrutura de dados em que cada elemento tem um ou mais elementos associados.\
II. A árvore é uma estrutura de dados baseada no princípio Last-in, First-out (LIFO), na qual os dados que foram inseridos primeiro serão os últimos a serem removidos.\
III. Uma lista é uma estrutura de dados linear, que pode ser encadeada, a qual é composta por nós que apontam para o próximo elemento e o último elemento apontará para nulo.\
IV. As pilhas são estruturas baseadas no princípio First-in, First-out (FIFO), em que os elementos que foram inseridos no início são os primeiros a serem removidos.\

- a) Somente a afirmação I é verdadeira.
- b) Somente a afirmação II é verdadeira.
- c) Somente a afirmação III é verdadeira.
- d) Somente a afirmação IV é verdadeira.
- e) Todas as afirmativas são verdadeiras.

<details><summary>Gabarito</summary>

**C.** Só a III é correta: fila não tem associação a vários elementos, árvore não é LIFO e pilha é LIFO. Assunto 0076.

</details>

**Edital 061/2018 · Questão 12**

Lista circular encadeada é uma das estruturas de dados dinâmicas básicas. Uma questão que deve ser resolvida pelo algoritmo de busca em lista circular encadeada é:

- a) Saber quando finalizar a busca, se o elemento procurado não estiver na lista circular.
- b) Retornar o elemento anterior ao buscado, dada a propriedade de circularidade da lista.
- c) Devolver o número de elementos constantes na lista.
- d) Parar a busca assim que encontrar um elemento cujo ponteiro para o próximo elemento tenha valor nulo, o que indica o fim da lista.
- e) Devolver o ponteiro de marcação de início, em sua nova posição

<details><summary>Gabarito</summary>

**A.** Na circular não há nulo: é preciso marcar o ponto de parada quando o elemento não existe. Assunto 0080.

</details>

**Edital 033/2019 · Questão 06**

Qual é a saída da seguinte função que inicia apontando para o primeiro nó da seguinte lista encadeada?

`1->2->3->4->5->6`

```c
void fun(struct node* start)
{
  if(start == NULL)
    return;
  printf("%d ", start->data);
  if(start->next != NULL )
    fun(start->next->next);
  printf("%d ", start->data);
}
```

- a) 1 4 6 6 4 1
- b) 1 3 5 1 3 5
- c) 1 2 3 5
- d) 1 3 5 5 3 1
- e) Nenhuma das anteriores

<details><summary>Gabarito</summary>

**D.** Imprime 1, 3, 5, chama com NULL e volta imprimindo 5, 3, 1: `1 3 5 5 3 1`. Assunto 0076.

</details>

**Edital 033/2019 · Questão 11**

Qual a função do seguinte trecho de código?

```java
public void function(int data)
{
  int flag = 0;
  if( head != null)
  {
    Node temp = head.getNext();
    while((temp != head) && (!(temp.getItem() == data)))
    {
      temp = temp.getNext();
      flag = 1;
      break;
    }
  }
  if(flag)
    System.out.println("success");
  else
    System.out.println("fail");
}
```

- a) Imprimir sucess se um determinado elemento não for encontrado
- b) Imprimir fail se um determinado elemento não for encontrado
- c) Imprimir sucess se um elemento em particular for igual a 1
- d) Imprimir fail se a lista estiver vazia e success caso contrário
- e) Nenhuma das respostas anteriores.

<details><summary>Gabarito</summary>

**B.** Assunto 0080.

</details>

**Edital 060/2019 · Questão 05**

Considere o código da função abaixo:

```c
void fun1(struct node* head)
{
  if(head == NULL)
    return;
  fun1(head->next);
  printf("%d ", head->data);
}
```

O que essa função faz, dada uma lista encadeada de valores inteiros como entrada?

- a) Imprime todos os nós da lista encadeada, começando com primeiro o nó da lista
- b) Imprime todos os nós da lista encadeada, começando com o último nó da lista
- c) Imprime apenas os nós de posições pares da lista encadeada
- d) Imprime apenas os nós de posições impares da lista encadeada
- e) Nenhuma das alternativas anteriores

<details><summary>Gabarito</summary>

**B.** Recursão antes do printf imprime do último ao primeiro. Assunto 0076.

</details>

**Edital 060/2019 · Questão 07**

A seguinte função em C usa uma lista simplesmente encadeada como argumento de entrada. Ela modifica a lista, movendo o último elemento para a frente da lista e retorna a lista modificada.

```c
typedef struct node {
  int value;
  struct node *next;
}Node;

Node *move_to_front(Node *head) {
  Node *p, *q;
  if ((head == NULL || (head->next == NULL))
    return head;
  q = NULL; p = head;
  while (p-> next !=NULL)
  {
    q = p;
    p = p->next;
  }
  _ _ _ _ _ _ _ _ _ _ _ _ _ _
  return head;
}
```

Certa parte do código foi deixada em branco (linha tracejada). Escolha a alternativa CORRETA para substituir a linha em branco.

- a) q = NULL; p->next = head; head = p;
- b) q->next = NULL; head = p; p->next = head;
- c) head = p; p->next = q; q->next = NULL;
- d) q->next = NULL; p->next = head; head = p;
- e) A função não precisa ser complementada.

<details><summary>Gabarito</summary>

**D.** `q->next = NULL; p->next = head; head = p;` tira o último e o põe na frente. Assunto 0076.

</details>

**Edital 060/2019 · Questão 19**

Considere uma lista duplamente encadeada não ordenada (com ponteiros na início e final da lista). Qual das seguintes operações a seguir pode ser implementada no tempo O(1)? Marque a alternativa CORRETA.

I. Inserção na frente da lista encadeada\
II. Inserção no final da lista encadeada\
III. Exclusão do nó frontal da lista encadeada\
IV. Exclusão do último nó da lista encadeada\

- a) I e II
- b) I e III
- c) I, II e III
- d) I, II e IV
- e) Todas as afirmativa estão corretas

<details><summary>Gabarito</summary>

**E.** Com ponteiros de início e fim e elo anterior, as quatro operações são O(1). Assunto 0079.

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
