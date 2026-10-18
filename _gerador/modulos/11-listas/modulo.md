# Módulo 11 · Listas

Até aqui você guardou coleções em vetores: tamanho fixo, itens lado a lado,
acesso instantâneo pelo índice. Mas quase nunca você sabe de antemão quantos
itens vão chegar. Este módulo começa resolvendo isso: você constrói o vetor
que cresce sozinho, dobrando de tamanho quando enche.

Depois vem a primeira estrutura de dados de verdade feita só de ponteiros: a
**lista encadeada**. Cada item mora num pedaço separado do heap e sabe onde
está o próximo. Você troca o acesso direto pela liberdade de inserir e
remover sem empurrar ninguém. Vai fazer busca, remoção, inserção em ordem, a
lista dupla (que anda para os dois lados) e a circular (que não tem fim).

A mudança na cabeça é parar de pensar em posições e começar a pensar em
**setas**. Toda operação de lista é "quem aponta para quem, antes e depois".
Por isso o conselho do módulo inteiro é um só: desenhe os nós e as setas no
papel antes de escrever o código. E rode tudo com o `rodar`: com ponteiros, o
AddressSanitizer vira o seu melhor amigo.

## O que você vai aprender

- montar um **TAD lista sequencial** sobre um vetor que dobra de capacidade com `realloc`, e entender o custo amortizado
- criar **nós** com struct autorreferenciada, inserir no início, percorrer e liberar uma **lista encadeada**
- **buscar** e **remover** com o par de ponteiros `ant`/`p`, e por que remover o primeiro nó é um caso especial (e como sumir com ele)
- manter uma **lista ordenada** com inserção no lugar certo
- usar a **lista dupla** para andar nos dois sentidos e remover um nó em O(1)
- usar a **lista circular** para rodízios, guardando o ponteiro para o último nó
- juntar tudo num **TAD playlist** com arquivo, callbacks e tipo opaco

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com os
   nós e as setas.
2. Leia o código. É o mesmo exemplo, com os mesmos valores. As funções da
   estrutura ficam no `lista.h` e no `lista.c` da pasta do assunto: abra os
   dois.
3. Siga o **fluxograma** com o dedo: é o caminho que a operação faz.
4. Rode os exemplos. Mude um valor, apague uma linha de propósito e veja o
   AddressSanitizer reclamar.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa; vermelho, o nó que vai embora.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você precisa estar firme em ponteiros (módulo 06), `malloc` e `free`
(módulo 07), structs e `->` (módulo 08) e no padrão TAD (assunto 0079). Se
`No **inicio` ainda assusta, releia o assunto 0054 antes do 0082.

Cada pasta de assunto traz um `lista.h` (a interface) e um `lista.c` (a
implementação). O `rodar` compila o `lista.c` junto com o exemplo ou o
exercício automaticamente, porque ele está na mesma pasta:

```bash
~/LPEDC/rodar 11-listas/0081-lista-encadeada/A161.c
```

Por isso, nos exercícios, não dê às suas funções o mesmo nome de uma função
do `lista.c` (como `lista_imprime`): o ligador reclamaria de nome repetido.
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
o `rodar` em todos: resposta certa com vazamento não vale.

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

Um ponteiro em cada lista, como na intercalação do E496: se os valores são
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
nó. Para imprimir, use recursão (como no E484) ou uma lista dupla e ande do
fim para o começo.

</details>

**5. Desfazer e refazer.** Um editor guarda o histórico de versões numa
lista dupla com um cursor na versão atual. "Desfazer" volta, "refazer"
avança. O que precisa acontecer com as versões à frente do cursor quando a
pessoa desfaz duas vezes e depois digita algo novo?

<details><summary>Resposta</summary>

Elas são **descartadas**: libere todos os nós depois do cursor, faça
`cursor->prox = NULL`, atualize o `fim` e só então insira a versão nova
depois do cursor. É o comportamento de todo editor: depois de editar, o
"refazer" some. Esquecer os `free` desses nós é vazamento clássico.

</details>

**6. LRU: o cache das páginas recentes.** Um navegador guarda as últimas 3
páginas visitadas. Visitar uma página que já está na lista leva ela para a
frente; visitar uma nova com a lista cheia expulsa a mais antiga (a do fim).
Simule as visitas A, B, C, A, D, B. Como fica a lista?

<details><summary>Resposta</summary>

A → `A`; B → `B A`; C → `C B A`; A (já está: vai para a frente) → `A C B`;
D (nova, cheia: sai o B do fim) → `D A C`; B (nova, cheia: sai o C) →
**`B D A`**. A lista dupla com `inicio` e `fim` faz cada movimento em O(1)
depois de achar o nó. Achar ainda é O(n); com uma tabela hash (módulo 15)
apontando para os nós, tudo vira O(1). É assim que caches de verdade
funcionam.

</details>

**7. Sem casos especiais.** Reescreva a lista dupla do assunto 0084 com um
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

Aplique a inversão do E486 em pedaços: inverta 3 nós, guardando o primeiro
do bloco (que vira o último) e o início do resto. Ligue o fim do bloco
invertido ao resultado da inversão do resto. Fica elegante com recursão:
`inverte_k(inicio)` inverte os 3 primeiros e faz
`primeiro_do_bloco->prox = inverte_k(resto)`.

</details>

**9. Ordenar uma lista em O(n log n).** O E498 ordena por inserção em
O(n²). Escreva o **merge sort** de lista: divida a lista ao meio, ordene cada
metade recursivamente e intercale. Teste com `5 1 4 2 8 3 7 6`.

<details><summary>Resposta</summary>

Para dividir, use a lebre e a tartaruga (E492): quando a lebre chega ao fim,
corte depois da tartaruga (`meio = tartaruga->prox; tartaruga->prox =
NULL`). Caso base: lista com 0 ou 1 nó. Junte com a intercalação do E496.
Resultado `1 2 3 4 5 6 7 8`. Na lista, o merge sort não precisa de vetor
auxiliar: só religa nós. É o assunto 0099, um módulo adiantado.

</details>

**10. Josephus de cabeça.** Com n pessoas em roda e eliminando de k em k, a
posição do sobrevivente (contando de 0) obedece a J(1) = 0 e
J(n) = (J(n − 1) + k) % n. Use a fórmula para n = 8, k = 3 e confira com a
batata quente do A170. Depois responda: quando vale a pena simular com a
lista e quando a fórmula basta?

<details><summary>Resposta</summary>

J(1)=0, J(2)=1, J(3)=1, J(4)=0, J(5)=3, J(6)=0, J(7)=3, J(8)=6. Posição 6
contando de 0 é a pessoa **7**, igual ao A170. A fórmula é O(n) e não usa
memória, mas só diz quem sobra. A lista dá a **ordem** de eliminação e
aguenta variações que a fórmula não cobre (passo diferente para cada pessoa,
alguém entrando no meio).

</details>

## Para ler mais

- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. 10: listas encadeadas.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Rio de Janeiro: Elsevier, 2004.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Cap. 4: listas encadeadas. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 4: filas e listas.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Cap. 6: lista.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, Departamento de Eletrônica e Telecomunicações.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 12: estruturas de dados.
- BACKES, A. *Linguagem C: descomplicada* (apostila). Cap. sobre alocação dinâmica e structs.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 6.5: estruturas autorreferenciadas.
- CPPREFERENCE. *realloc*. Disponível em: <https://en.cppreference.com/w/c/memory/realloc>.
- GCC. *AddressSanitizer*. Disponível em: <https://github.com/google/sanitizers/wiki/AddressSanitizer>.
