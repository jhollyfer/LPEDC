# Módulo 07 · Memória dinâmica

Até aqui, todo vetor do curso tinha tamanho decidido na hora de escrever o
código. `int notas[50]` é uma aposta: se a turma tiver 12 alunos, você
desperdiça; se tiver 51, estoura. Programas de verdade não sabem quantos dados
vão chegar. Este módulo ensina a pedir memória **enquanto o programa roda**, do
tamanho exato, e a devolvê-la quando acabar.

No C, nenhum vetor cresce sozinho e nenhum coletor de lixo apaga o que
ninguém usa. Quem faz as duas coisas é você. Isso dá poder
(você decide quanto, quando e por quanto tempo) e dá responsabilidade: memória
esquecida vaza, memória devolvida e usada de novo corrompe o programa.

O módulo é a ponte para a segunda metade do curso. Toda estrutura de dados que
vem depois (listas, pilhas, filas, árvores, tabelas hash, grafos) é feita de
blocos pedidos ao heap e ligados por ponteiros. Quem domina `malloc`, `free` e
`realloc` aqui, e sabe ler um relatório do AddressSanitizer, escreve essas
estruturas sem medo.

## O que você vai aprender

- as quatro regiões da memória de um programa: **código, dados, heap e pilha**, e quanto tempo vive cada coisa
- pedir e devolver memória com **`malloc`** e **`free`**, sempre conferindo o `NULL`
- **`calloc`** (memória zerada) e **`realloc`**, para fazer um vetor crescer conforme os dados chegam
- montar **matrizes dinâmicas**: bloco único com `i * colunas + j` ou vetor de ponteiros com `m[i][j]`
- reconhecer **vazamento, ponteiro solto, free duplo e estouro**, e caçá-los com o **AddressSanitizer** e o **valgrind**
- juntar tudo num programa com vetores que crescem e strings de tamanho exato, sem deixar nada para trás

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com a
   memória à mostra.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude um valor, apague um `free`, quebre de propósito e
   leia o que o `rodar` responde.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

> [!NOTE]
> Neste módulo, muitos exercícios são de **achar o erro**: o arquivo vem com o
> bug de propósito, e o enunciado avisa. Rodar e ler o relatório do
> AddressSanitizer faz parte do exercício. A resolução de cada um roda limpa.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue e o resultado;
cinza, o que ele não usa; vermelho, erro. Nos diagramas deste módulo, o verde
costuma ser o bloco que mora no heap.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você precisa estar à vontade com ponteiros (módulo 06): `&`, `*`, `NULL`,
`a[i] == *(a + i)`, `char *` e `**`. Se `int **m` ainda assusta, releia os
assuntos 0047 e 0049 antes.

O `rodar` já compila com o **AddressSanitizer**, que vigia a memória enquanto
o programa roda e avisa de vazamentos no fim. Para o assunto 0057, instale
também o **valgrind**:

```bash
sudo pacman -S valgrind        # Arch Linux
sudo apt install valgrind      # Debian / Ubuntu
```

E rode qualquer arquivo com ele assim (sem AddressSanitizer, dentro do
valgrind):

```bash
~/LPEDC/rodar --valgrind 07-memoria-dinamica/0057-erros-de-memoria/A114.c
```

A regra do módulo inteiro cabe numa linha: **todo `malloc` tem um `free`, e
nenhum ponteiro é usado depois dele**.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver num arquivo seu, rodando com o `rodar` (e com
`rodar --valgrind` quando quiser a segunda opinião). Todos precisam terminar
sem nenhum relatório de erro.

**1. Apagar do caderno.** No caderninho de fiado do texto do assunto 0058,
escreva `int remover(char **nomes, int *centavos, int *qtd, const char *nome)`,
que apaga a linha do cliente e puxa as de baixo para cima. Teste removendo
"Seu Jorge" e mostre o caderno.

<details><summary>Resposta</summary>

Ficam Dona Cida (17.20), Bia (20.00), Tonho (3.15) e Rosa (5.60), total
R$ 45.95. O caminho: ache o índice `i`, faça `free(nomes[i])` (o nome é um
bloco), depois copie `nomes[k] = nomes[k + 1]` e `centavos[k] = centavos[k + 1]`
para `k` de `i` até `qtd - 2` e faça `(*qtd)--`. Um `free` só: os ponteiros
puxados continuam apontando para os mesmos blocos.

</details>

**2. A matriz de dois mallocs.** Escreva `int **criar_matriz(int l, int c)`
que usa só dois `malloc`: um bloco com os `l * c` inteiros e um vetor de `l`
ponteiros com `m[i] = bloco + i * c`. Escreva também o `liberar`. Teste com
uma matriz 3 x 4 preenchida com `i * 4 + j` e mostre `m[2][3]`.

<details><summary>Resposta</summary>

`m[2][3]` vale **11**. Para liberar: `free(m[0])` (é o endereço do bloco de
dados) e `free(m)`. Dois `malloc`, dois `free`, dados contíguos e a notação
`m[i][j]` preservada. Cuidado: `free(m[1])` seria um erro, porque `m[1]` não
veio de um `malloc`.

</details>

**3. Matriz simétrica econômica.** Numa tabela de distâncias entre 4
cidades, `d[i][j] == d[j][i]` e a diagonal é 0. Guarde só o triângulo de baixo
(com a diagonal) num vetor de `n * (n + 1) / 2` posições, com o elemento
`(i, j)`, `i >= j`, em `i * (i + 1) / 2 + j`. Quantas posições para n = 4? Em
que índice fica `(3, 1)`? E `(1, 3)`?

<details><summary>Resposta</summary>

**10** posições (contra 16 da matriz cheia). `(3, 1)` fica em 3 * 4 / 2 + 1 =
**7**. Para `(1, 3)`, troque i e j, porque `i < j`: é o mesmo índice 7. Com
n = 1000, a economia passa de 499 mil posições.

</details>

**4. O gerente do heap.** O heap tem dois blocos livres, de 120 e de 60 bytes,
e chegam três pedidos: 30, 80 e 55. Simule duas estratégias: **first fit**
(usa o primeiro bloco que serve, olhando o de 120 antes) e **best fit** (usa o
menor bloco que serve). Alguma delas falha?

<details><summary>Resposta</summary>

First fit: 30 sai do 120 (sobra 90), 80 sai do 90 (sobra 10), 55 sai do 60
(sobra 5): **atende os três**. Best fit: 30 sai do 60 (sobra 30), 80 sai do
120 (sobra 40), e 55 **falha** (sobram 40 e 30). Escolher "o mais justo" nem
sempre é o melhor: deixa sobras pequenas demais. Os `malloc` reais usam
variações de first fit com listas por tamanho.

</details>

**5. Tem memória, mas não cabe.** Um heap de 1000 bytes recebe A = 300, B = 200
e C = 400 (sobram 100 no fim). Depois `free(B)`. Há 300 bytes livres. Por que
um pedido de 250 bytes falha?

<details><summary>Resposta</summary>

Os livres são **dois pedaços separados**, de 200 (onde era B) e de 100 (no
fim), e um bloco do `malloc` precisa ser contíguo. Isso é **fragmentação
externa**. Se C fosse liberado, os 200 de B, os 400 de C e os 100 do fim se
juntariam num bloco de 700 e o pedido passaria.

</details>

**6. Repetir texto.** Escreva `char *repetir(const char *s, int n)` que
devolve uma string nova com `s` repetida `n` vezes. Quantos bytes
`repetir("ab", 3)` pede? E `repetir("ab", 0)`?

<details><summary>Resposta</summary>

`"ababab"` precisa de 2 * 3 + 1 = **7** bytes. Com n = 0, 1 byte só com o
`'\0'`: uma string vazia válida, que quem chama também precisa liberar.
Monte com `strcpy` no primeiro e `strcat` nos seguintes, ou copiando com um
índice.

</details>

**7. O vetor que encolhe.** Um vetor dinâmico começa com capacidade 1, dobra
quando enche e **corta pela metade** quando a quantidade fica menor que um
quarto da capacidade. Você insere 9 elementos e depois remove 6. Qual a
capacidade depois das inserções? E no fim?

<details><summary>Resposta</summary>

Inserindo: 1 → 2 → 4 → 8 → 16, então **16** com 9 elementos. Removendo:
com 3 elementos, 3 < 16 / 4 = 4, e a capacidade cai para **8**. O "um quarto"
(e não "metade") evita o vai e vem: se encolhesse com metade, um push e um
pop alternados na fronteira fariam um `realloc` a cada operação.

</details>

**8. Dois nomes, um bloco.** Preveja:

```c
int *a = malloc(3 * sizeof *a);
int *b = a;
b[0] = 5;
free(a);
a = NULL;
printf("%d\n", b == NULL);
```

O que aparece? O `b[0]` ainda é seguro?

<details><summary>Resposta</summary>

Mostra **0**: `a = NULL` muda só a variável `a`. `b` continua guardando o
endereço do bloco liberado: é um ponteiro solto, e `b[0]` é uso depois do
`free` (o ASan acusa `heap-use-after-free`). O hábito de zerar o ponteiro
ajuda, mas não substitui saber **quem é o dono** do bloco.

</details>

**9. O vazamento a conta-gotas.** Uma função é chamada 1000 vezes. Em cada
chamada ela faz um `malloc` de 24 bytes, mas só dá `free` quando o número da
chamada é par. Quanto vaza? O que o LeakSanitizer mostra?

<details><summary>Resposta</summary>

500 chamadas ímpares * 24 = **12000 bytes** em 500 blocos:
`Direct leak of 12000 byte(s) in 500 object(s)`, com a linha do `malloc`. Num
servidor que roda essa função 1 milhão de vezes por dia, são 12 MB por dia:
é assim que o sistema da padaria trava no sábado.

</details>

**10. Frase ao contrário.** Use o `dividir` do E348 e uma função de juntar
para inverter a ordem das palavras: "o rato roeu a roupa" vira
"roupa a roeu rato o". A frase resultante deve ser um bloco novo, do tamanho
exato.

<details><summary>Resposta</summary>

`dividir` com `' '` dá 5 pedaços. O tamanho final é a soma dos `strlen` (15)
mais 4 espaços mais o `'\0'`: **20 bytes**, o mesmo tamanho da frase original.
Monte percorrendo os pedaços do último para o primeiro. No fim, libere os 5
pedaços, o vetor deles e a frase nova.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 11: alocação dinâmica.
- BACKES, A. *Linguagem C descomplicada*. Apostila. Uberlândia: FACOM/UFU. Capítulo de alocação dinâmica.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Alocação dinâmica e matrizes dinâmicas.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 12: estruturas de dados (alocação dinâmica).
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Apêndice F: alocação dinâmica de memória.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Cap. 2: uso de memória.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro. Apostila da disciplina Programação II.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 9: gerenciamento de armazenamento.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 8.7: um alocador de memória.
- CPPREFERENCE. *Dynamic memory management*. Disponível em: <https://en.cppreference.com/w/c/memory>.
- LINUX MAN-PAGES. *malloc(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/malloc.3.html>.
- GOOGLE. *AddressSanitizer*. Disponível em: <https://github.com/google/sanitizers/wiki/AddressSanitizer>.
- VALGRIND DEVELOPERS. *Valgrind user manual: Memcheck*. Disponível em: <https://valgrind.org/docs/manual/mc-manual.html>.
