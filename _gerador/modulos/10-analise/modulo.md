# Módulo 10 · Pensar como cientista da computação

Até aqui a pergunta foi "como escrevo isso em C?". Daqui para a frente, com
listas, pilhas, árvores e grafos, ela muda para "**qual** jeito de escrever é o
certo?". Para listar pedidos dá para usar um vetor ou uma lista encadeada, e
para achar um cliente, uma busca sequencial, uma binária ou uma tabela hash.
Todas funcionam com 10 itens. Com 1 milhão, umas respondem na hora e outras
travam o servidor.

Este módulo é a caixa de ferramentas para decidir. São três ideias que
atravessam o resto do curso: **medir o custo** contando passos e resumindo o
crescimento na notação O; **ter certeza de que está certo** com invariantes de
laço, em vez de confiar em meia dúzia de testes; e **esconder os detalhes**
atrás de um tipo abstrato de dado, para poder trocar a implementação sem
quebrar quem usa.

Todo programador já esbarrou nisso sem nome: a busca dentro de um laço que
deixou o programa lento, o módulo que esconde a implementação atrás de
funções. Aqui essas coisas ganham nome, com o C mostrando o custo de cada
escolha.

## O que você vai aprender

- medir a **eficiência** de um algoritmo contando passos: melhor, pior e caso médio
- ler e escrever a **notação O**: O(1), O(log n), O(n), O(n log n) e O(n²), e por que constantes somem
- enunciar **invariantes de laço** e usá-los para provar que um laço está certo (e achar bugs)
- montar um **tipo abstrato de dado** com interface (`.h`), implementação (`.c`) e tipo opaco: o padrão de todos os próximos módulos

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude o n, troque os dados, quebre um invariante de
   propósito e veja o `assert` disparar.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue (e, nas tabelas de
custo, o que continua leve); vermelho é erro ou custo que explodiu; cinza, o
que o exemplo não usa.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você vai usar tudo dos módulos anteriores, em especial funções, vetores,
ponteiros, `malloc`/`free` e `struct`. Duas novidades pequenas:

- `<assert.h>`: `assert(condicao)` para o programa na hora se a condição for
  falsa. É o jeito de transformar um invariante em código.
- **arquivos de apoio**: no assunto 0079, a pasta tem `contador.h`,
  `contador.c`, `conta.h` e `conta.c` além dos exemplos. O `rodar` compila
  junto todo `.c` da pasta que não se chama `A000.c`/`E000.c`, então é só
  rodar o exemplo, como sempre:

```bash
~/LPEDC/rodar 10-analise/0079-tad/A157.c
```

Os contadores de passos dos exemplos não medem segundos: medem trabalho. Rode
na sua máquina e os números saem iguais aos do texto.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas que misturam os quatro assuntos, do médio ao difícil. Alguns pedem
código; outros, só papel.

**1. Convidados em comum.** Você tem a lista de convidados do seu aniversário
(n nomes) e a do seu amigo (m nomes) e quer saber quem está nas duas. Quantas
comparações faz o jeito "cada nome meu contra cada nome dele"? E se as duas
listas estiverem em ordem alfabética?

<details><summary>Resposta</summary>

O jeito ingênuo faz **n · m** comparações: O(n · m), O(n²) se forem do mesmo
tamanho. Com as duas ordenadas, ande com um índice em cada lista, como numa
intercalação: compare os dois nomes da vez e avance o menor. Cada comparação
avança pelo menos um índice, então são no máximo **n + m** comparações: O(n).

</details>

**2. O cronômetro dedurou.** Um relatório leva 2 s com 1 milhão de linhas e
8 s com 2 milhões. Qual a classe O provável? Quanto ele vai levar com 4
milhões?

<details><summary>Resposta</summary>

Dobrou n, o tempo multiplicou por 4: **O(n²)**. Com 4 milhões, mais um
dobro: 8 × 4 = **32 s**. É a regra do dobro do E460 aplicada a tempo em vez de
passos.

</details>

**3. Um milhão de CPFs.** Num vetor ordenado de 1.000.000 de CPFs, quantas
comparações a busca binária faz no pior caso? E a sequencial?

<details><summary>Resposta</summary>

A binária corta pela metade a cada comparação: 2²⁰ = 1.048.576 ≥ 1.000.000,
então **20 comparações** (mais ou menos uma, conforme o detalhe da
implementação). A sequencial, no pior caso, **1.000.000**. É a tabela de
O(log n) contra O(n) do assunto 0077, com números de verdade.

</details>

**4. A conta da pergunta.** No assunto 0077: um algoritmo O(n²) leva 1 s com
10.000 pedidos. Quanto leva com 100.000? E um O(n log n) que também leva 1 s
com 10.000?

<details><summary>Resposta</summary>

O(n²): n multiplicou por 10, o tempo por 10² = **100 s**. O(n log n): o tempo
multiplica por 10 × (log 100.000 / log 10.000) = 10 × 5/4 = **12,5 s**. A base
do log não importa, porque ela se cancela na divisão.

</details>

**5. Soma dos dígitos com invariante.** Escreva uma função que soma os dígitos
de n ≥ 0 tirando o último dígito com `% 10` e `/ 10`. Enuncie o invariante e
teste com 4096.

<details><summary>Resposta</summary>

Com `m` começando em n e `soma` em 0, o invariante é
**soma + (soma dos dígitos de m) == soma dos dígitos de n**. Cada volta passa
o último dígito de `m` para `soma`, então a igualdade continua valendo. Quando
`m` chega a 0, a soma dos dígitos de `m` é 0 e `soma` é a resposta. A variante
é `m`, que cai a cada volta. Para 4096: 4 + 0 + 9 + 6 = **19**.

</details>

**6. Potência em O(log n).** Calcule 3¹³ sem fazer 12 multiplicações:
enquanto o expoente `e` for maior que 0, se `e` for ímpar multiplique o
resultado `r` pela base `b`; depois `b = b * b` e `e = e / 2`. Qual é o
invariante? Quantas voltas o laço dá?

<details><summary>Resposta</summary>

Invariante: **r · bᵉ == 3¹³** (com r = 1, b = 3 e e = 13 no começo, vale). O
expoente passa por 13, 6, 3, 1 e 0: **4 voltas**, e o resultado é
**1.594.323**. O expoente cai pela metade a cada volta, então o laço é
O(log e), contra O(e) do jeito ingênuo.

</details>

**7. Projete antes de codar.** Escreva só o `fila_senhas.h` de um TAD para as
senhas de atendimento do banco: tirar senha, chamar a próxima, ver quantas
pessoas esperam. Siga o padrão do assunto 0079, com o contrato de cada função.

<details><summary>Resposta</summary>

Uma resposta possível: `typedef struct fila_senhas FilaSenhas;`,
`FilaSenhas *fila_senhas_cria(void);` (NULL se faltar memória),
`void fila_senhas_libera(FilaSenhas *f);`,
`int fila_senhas_tira(FilaSenhas *f);` (devolve o número da nova senha),
`bool fila_senhas_chama(FilaSenhas *f, int *senha);` (false se ninguém espera)
e `int fila_senhas_esperando(const FilaSenhas *f);`. Repare que nada no `.h`
diz se é vetor ou lista: isso é problema do `.c` (e do módulo 12).

</details>

**8. O contrato fala de custo?** Duas implementações do mesmo `contador.h`:
uma guarda o valor num `int`; a outra guarda o horário de cada entrada num
vetor e, em `contador_valor`, conta as entradas. As duas cumprem o contrato?
Qual a diferença para quem usa?

<details><summary>Resposta</summary>

As duas cumprem: devolvem o mesmo valor. Mas a primeira tem `contador_valor`
em **O(1)** e a segunda em **O(n)**. Um cliente que chama `contador_valor`
dentro de um laço passa de O(n) para O(n²) sem mudar uma linha. Por isso boas
bibliotecas documentam o custo junto com o contrato.

</details>

**9. O par que soma 100.** Num vetor de n preços, você procura o primeiro par
(i < j) com `v[i] + v[j] == 100` usando dois laços e para no primeiro achado.
Qual o melhor caso, o pior caso e a classe O que se costuma dar?

<details><summary>Resposta</summary>

Melhor caso: os dois primeiros já somam 100, **1 comparação**, O(1). Pior
caso: não existe par, todos os n(n − 1)/2 pares são testados, **O(n²)**. A
classe que se dá é a do pior caso: O(n²). O `break` melhora a média, não a
garantia.

</details>

**10. Maior e menor de uma vez.** Achar o maior e o menor de n números com
dois laços separados custa 2n − 2 comparações. Existe um jeito com cerca de
3n/2: pegue os números de dois em dois, compare os dois entre si e só depois
compare o maior do par com o maior geral e o menor do par com o menor geral.
Implemente com contador e confira para n = 10.

<details><summary>Resposta</summary>

Para n = 10: o jeito separado faz **18** comparações; o de pares, **13**
(1 para o primeiro par e 3 para cada um dos outros 4 pares: 3n/2 − 2). As duas
são O(n): a notação O não enxerga a diferença, mas o contador enxerga. É o
lembrete do assunto 0076: a constante importa quando n é fixo.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Partes sobre documentação, invariantes e análise de algoritmos. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. 9: tipos abstratos de dados.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. Rio de Janeiro: Elsevier, 2004.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 1 (tipos abstratos de dados) e seção 6.1 (eficiência e notação O).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 6: busca e ordenação de vetores.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, Departamento de Eletrônica e Telecomunicações. Cap. 5: memórias e programação modular.
- CORMEN, T. H. et al. *Algoritmos: teoria e prática*. 3. ed. Rio de Janeiro: Elsevier, 2012. Cap. 2 (invariantes de laço) e cap. 3 (crescimento de funções).
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.5: arquivos de cabeçalho.
- CPPREFERENCE. *assert*. Disponível em: <https://en.cppreference.com/w/c/error/assert>.
