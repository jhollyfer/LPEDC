# Módulo 15 · Tabelas hash

Até aqui, achar uma coisa sempre custou alguma procura: O(n) na lista, O(log
n) na busca binária e na árvore equilibrada. A tabela hash troca a procura
por uma **conta**: uma função transforma a chave num índice de vetor, e o
acesso ao vetor custa O(1). É a estrutura de dados mais usada na prática.

Você usa tabela hash todo dia no TypeScript sem pensar: `Map`, `Set` e os
objetos `{}` usados como dicionário são tabelas hash por baixo. No C não tem
nada disso pronto, e é aí que você entende o que o motor do JS faz: a função
hash que mistura os bytes da chave, o que acontece quando duas chaves caem no
mesmo lugar, por que a tabela cresce quando enche e por que ela não guarda
ordem nenhuma.

O módulo tem duas famílias para tratar colisão: o **encadeamento**, que
pendura uma lista em cada balde, e o **endereçamento aberto**, que procura
outra posição dentro do próprio vetor. Termina com um contador de palavras
de verdade, que junta tabela, strings, `qsort` e memória dinâmica.

## O que você vai aprender

- o que é **endereçamento direto**, **função hash**, **colisão** e **fator de carga**
- escrever funções hash boas para inteiros (`k % m`, com `m` primo) e para texto (polinômio de base 31, em `unsigned`)
- montar uma tabela com **encadeamento**: inserir, buscar, remover e liberar cada corrente
- montar uma tabela com **endereçamento aberto** e sondagem linear, com a marca de **removida**
- medir o custo: comparações, sondagens, agrupamento e quando crescer a tabela (**rehash**)
- usar a tabela como contador e como conjunto, num programa completo

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude um valor, quebre de propósito, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas ficam escondidas: abra só se travar.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa; vermelho, erro ou colisão. Nas tabelas, cada balde é uma gaveta com o
índice à esquerda, e a corrente de nós sai dela para a direita.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Este módulo usa listas encadeadas (módulo 11) o tempo todo: inserir no
início, percorrer e remover guardando o anterior. Usa também `malloc`/`free`,
structs, ponteiro para função e `qsort`. Se algo disso estiver nebuloso,
revise antes.

As tabelas seguem o padrão TAD: `tabela.h`/`tabela.c` (encadeamento),
`aberta.h`/`aberta.c` (endereçamento aberto) e `palavras.h`/`palavras.c`
(o contador) ficam na pasta de cada assunto, e o `rodar` compila tudo junto:

```bash
~/LPEDC/rodar 15-hash/0111-encadeamento/A221.c
```

Os exercícios trazem a própria implementação dentro do arquivo, para você
escrever cada pedaço com as mãos.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras, misturando os assuntos do módulo. Resolva no papel primeiro
e depois, se quiser, num arquivo seu.

**1. Base e tamanho brigando.** Um colega usou o hash polinomial de base 31
com uma tabela de `m = 31` baldes. Num texto com 500 palavras diferentes,
quase todas caíram em poucos baldes. Por quê? Que `m` você usaria?

<details><summary>Resposta</summary>

Como `h = h * 31 + c`, o resto por 31 de `h * 31` é sempre 0: sobra só `c %
31`, o código da **última letra**. Todas as palavras terminadas em "a" caem
juntas, e assim por diante. Use um `m` sem fator comum com a base: um primo
diferente de 31, como 37, 101 ou 1009.

</details>

**2. Sondagem linear à mão.** Tabela com `m = 7`, `h(k) = k % 7`, sondagem
linear. Insira 15, 22, 9, 4 e 29, nessa ordem. Desenhe a tabela e conte as
sondagens de cada inserção. Quantas sondagens custa depois buscar o 36, que
não está lá?

<details><summary>Resposta</summary>

15 → 1 (1 sondagem); 22 → 2 (2); 9 → 3 (2, porque a 2 já tem o 22); 4 → 4
(1); 29 → 5 (5: tenta 1, 2, 3, 4 e 5). Total: 11. A busca pelo 36 (hash 1)
olha 1, 2, 3, 4, 5 e para na 6, livre: **6 sondagens**. Um bloco de 5
ocupadas seguidas é o agrupamento primário em ação.

</details>

**3. Média de comparações.** Uma tabela com encadeamento tem 5 baldes, com
correntes de 3, 1, 0, 2 e 0 nós. Em média, quantas comparações custa buscar
uma chave que **está** na tabela? E uma que não está, supondo que ela caia em
qualquer balde com a mesma chance?

<details><summary>Resposta</summary>

Achar o k-ésimo nó de uma corrente custa k comparações: (1 + 2 + 3) + 1 + (1
+ 2) = 10 para 6 chaves, **≈ 1,67**. Sem sucesso, você percorre a corrente
inteira: (3 + 1 + 0 + 2 + 0) / 5 = **1,2**, que é exatamente o fator de carga
α = 6/5.

</details>

**4. A remoção que quebra tudo.** Tabela aberta com `m = 5`, `h(k) = k % 5`.
Entram 10, 15 e 20 (vão para 0, 1 e 2). O 15 sai e alguém marca a posição 1
como **livre**. O que acontece ao buscar o 20? E com a marca de removida?

<details><summary>Resposta</summary>

Com livre: a busca começa em 0 (é o 10), vai para 1, vê livre e conclui que
o 20 **não está**, embora ele esteja na 2. Com removida: a busca passa reto
pela 1 e acha o 20 na 2, com 3 sondagens. Uma inserção nova com hash 0 pode
reaproveitar a 1, depois de conferir que a chave não existe adiante.

</details>

**5. Hash de número negativo.** Uma função `int h(int k) { return k % 10; }`
recebe o saldo de uma conta: -37. Qual índice sai? Como consertar sem perder
a distribuição?

<details><summary>Resposta</summary>

Em C, o resto tem o sinal do dividendo: `-37 % 10` é **-7**, índice fora do
vetor. Conserto: `((k % m) + m) % m`, que dá 3. Ou converta antes para
`unsigned` (o valor muda, mas fica sempre no intervalo certo).

</details>

**6. Dois preços que fecham a conta.** Você tem um vale de R$ 50 e uma
lista de preços: 12, 31, 7, 19 e 43. Existe um par de produtos que soma
exatamente 50? Descreva um algoritmo O(n) com uma tabela hash usada como
conjunto.

<details><summary>Resposta</summary>

Para cada preço `p`, pergunte se `50 - p` já está no conjunto; se não, guarde
`p`. Com 12: 38 não está, guarda 12. Com 31: 19 não está, guarda 31. Com 7:
43 não está, guarda 7. Com 19: **31 está**: o par é 31 + 19. Uma passada só,
O(n) em média, contra O(n²) de testar todos os pares.

</details>

**7. Qual estrutura?** Para cada caso, escolha entre tabela hash e árvore de
busca equilibrada (AVL), e justifique: (a) o compilador consultando as
palavras reservadas; (b) a agenda que precisa listar os contatos em ordem
alfabética e achar "todos entre Ana e Bia"; (c) o cache de sessões de um
servidor, com milhares de entradas e saídas por segundo.

<details><summary>Resposta</summary>

(a) **hash**: conjunto fixo, só pergunta "existe?"; dá até para achar um
`m` sem colisão (hash perfeito). (b) **árvore**: a tabela não guarda ordem,
e listar em ordem ou por intervalo exigiria ordenar tudo a cada consulta;
a AVL faz isso com o percurso em ordem. (c) **hash**: O(1) médio em
inserir, buscar e remover; com encadeamento a remoção é simples, com
endereçamento aberto as lápides pedem reconstruções periódicas.

</details>

**8. Crescer sem copiar.** Uma tabela aberta com `m = 7` tem 5 chaves (α ≈
0,71) e vai crescer para `m = 17`. Por que não dá para copiar o vetor velho
para o começo do novo, posição por posição? Quanto custa crescer?

<details><summary>Resposta</summary>

A posição de cada chave depende de `m`: `k % 7` e `k % 17` são outros
índices, e as sondagens também mudam. Copiar deixaria as chaves onde a busca
nova não procura. É preciso **reinserir** cada uma: O(n) para crescer. Como
isso acontece só quando a tabela dobra, o custo diluído por inserção
continua O(1), igual ao vetor que cresce com `realloc` (módulo 07).

</details>

**9. A letra mais comum, em O(1) de memória.** Conte quantas vezes cada
letra de "a" a "z" aparece num texto, sem tabela hash com listas. Por que
essa solução é uma tabela hash perfeita?

<details><summary>Resposta</summary>

Um vetor `int conta[26] = {0};` e `conta[c - 'a']++` para cada letra
minúscula. A "função hash" `c - 'a'` leva as 26 chaves possíveis em 26
posições diferentes: zero colisões, porque o universo de chaves é pequeno e
conhecido. É o endereçamento direto, o caso em que a tabela hash nem
precisa de função esperta.

</details>

## Para ler mais

- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. de tabelas de dispersão.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Rio de Janeiro: Elsevier, 2004.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 7: busca (espalhamento).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Seção 6.6: table lookup.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Cap. 11: tabelas de espalhamento.
- KNUTH, D. E. *The art of computer programming*: volume 3: sorting and searching. 2. ed. Reading: Addison-Wesley, 1998. Seção 6.4: hashing.
- CPPREFERENCE. *isalpha*. Disponível em: <https://en.cppreference.com/w/c/string/byte/isalpha>.
