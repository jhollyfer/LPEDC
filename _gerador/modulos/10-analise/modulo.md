# Módulo 10 · Pensar como cientista da computação

Até aqui a pergunta foi "como escrevo isso em C?". Daqui para a frente, com
listas, pilhas, árvores e grafos, ela muda para "**qual** jeito de escrever é o
certo?". Para listar pedidos dá para usar um vetor ou uma lista encadeada, e
para achar um cliente, uma busca sequencial, uma binária ou uma tabela hash.
Todas funcionam com 10 itens. Com 1 milhão, umas respondem na hora e outras
travam o servidor.

Este módulo traz as ferramentas para decidir, em três ideias que atravessam o
resto do curso: **medir o custo** contando passos e resumindo o
crescimento na notação O; **ter certeza de que está certo** com invariantes de
laço, em vez de confiar em meia dúzia de testes; e **esconder os detalhes**
atrás de um tipo abstrato de dado, para poder trocar a implementação sem
quebrar quem usa.

Você provavelmente já esbarrou nisso sem dar nome: a busca dentro de um laço
que deixou o programa lento, o módulo que esconde a implementação atrás de
funções. Aqui essas coisas ganham nome, e o C mostra o custo de cada escolha.

## O que você vai aprender

- medir a **eficiência** de um algoritmo contando passos: melhor, pior e caso médio
- ler e escrever a **notação O**: O(1), O(log n), O(n), O(n log n) e O(n²), e por que constantes somem
- enunciar **invariantes de laço** e usá-los para provar que um laço está certo (e achar bugs)
- montar um **tipo abstrato de dado** com interface (`.h`), implementação (`.c`) e tipo opaco: o padrão de todos os próximos módulos

## Antes de começar

Nos exemplos, mude o n, troque os dados, quebre um invariante de propósito e
veja o `assert` disparar. Nos desenhos de custo, verde é o que continua leve e
vermelho é o custo que explodiu.

Você vai usar tudo dos módulos anteriores, em especial funções, vetores,
ponteiros, `malloc`/`free` e `struct`. Duas novidades pequenas:

- `<assert.h>`: `assert(condicao)` para o programa na hora se a condição for
  falsa. É assim que um invariante vira código.
- **arquivos de apoio**: no assunto 0074, a pasta tem `contador.h`,
  `contador.c`, `conta.h` e `conta.c` além dos exemplos. O `rodar` compila
  junto todo `.c` da pasta que não se chama `A000.c`/`E000.c`, então basta
  rodar o exemplo, como sempre:

```bash
~/LPEDC/rodar 10-analise/0074-tad/A147.c
```

Os contadores de passos dos exemplos não medem segundos, medem trabalho: na
sua máquina, os números saem iguais aos do texto.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas que misturam os quatro assuntos, do médio ao difícil. Todos pedem
código: escreva num arquivo seu e rode com o `rodar`.

**1. Convidados em comum.** A sua lista de convidados é `{"Ana", "Bia",
"Caio", "Davi", "Edu", "Fabi"}` e a do seu amigo é `{"Bia", "Davi", "Edu",
"Gil", "Hugo"}`, as duas em ordem alfabética. Escreva um programa que mostre
quem está nas duas de dois jeitos, contando os `strcmp` numa variável: (1)
cada nome seu contra cada nome dele; (2) um índice em cada lista, como numa
intercalação, avançando o do nome menor. Imprima os nomes e o contador de
cada jeito.

<details><summary>Resposta</summary>

```
ingenuo: Bia Davi Edu (30 comparacoes)
ordenado: Bia Davi Edu (6 comparacoes)
```

Dica: no segundo jeito, `while (i < n && j < m)`; se o `strcmp` der 0,
imprima e avance os dois; se der negativo, avance `i`; senão, `j`. O
ingênuo faz sempre **n · m** comparações, O(n · m); o ordenado faz no máximo
**n + m**, porque cada comparação avança pelo menos um índice: O(n).

</details>

**2. O cronômetro dedurou.** Um relatório leva 2 s com 1 milhão de linhas e
8 s com 2 milhões. O código dele, para cada linha, compara com todas as
anteriores. Escreva `long relatorio(int n)` com esses dois laços (`j` de 0 a
`i - 1`), contando um passo por comparação. Imprima os passos para n = 1000,
2000 e 4000, a razão entre cada contagem e a anterior e, usando a última
razão, a previsão de tempo para 4 milhões de linhas (partindo dos 8 s).

<details><summary>Resposta</summary>

```
n = 1000: 499500 passos
n = 2000: 1999000 passos (razao 4.00)
n = 4000: 7998000 passos (razao 4.00)
previsao para 4 milhoes de linhas: 32 s
```

Dica: guarde a contagem anterior numa variável e divida em `double`. Dobrou
n, os passos (e o tempo) multiplicaram por 4: é **O(n²)**, a regra do dobro
do E430. Daí 8 × 4 = 32 s.

</details>

**3. Um milhão de CPFs.** Aloque com `malloc` um vetor ordenado de
1.000.000 de "CPFs" (use `v[i] = 2 * i`) e procure um valor que não está lá
(`2 * n`) com a busca binária e com a sequencial. Cada função recebe um
`int *comp` e conta uma comparação por volta do laço. Imprima os dois
contadores.

<details><summary>Resposta</summary>

```
binaria: 20 comparacoes (achou: -1)
sequencial: 1000000 comparacoes (achou: -1)
```

Dica: a binária usa `ini <= fim` e `meio = ini + (fim - ini) / 2`, e faz
`(*comp)++` no começo de cada volta. Ela corta pela metade a cada volta e
2²⁰ = 1.048.576 ≥ 1.000.000, por isso **20**: a tabela de O(log n) contra
O(n) do assunto 0072, com números de verdade.

</details>

**4. A conta da pergunta.** No assunto 0072: um algoritmo O(n²) leva 1 s com
10.000 pedidos. Escreva um programa que calcule quanto ele leva com 100.000 e
quanto leva um O(n log n) que também leva 1 s com 10.000. Faça a conta do
O(n log n) duas vezes, uma com `log2` e outra com `log10` (de `math.h`), e
imprima com uma casa.

<details><summary>Resposta</summary>

```
O(n^2):     100.0 s
O(n log n): 12.5 s (log2) e 12.5 s (log10)
```

Dica: o tempo novo é `t1 * f(n2) / f(n1)`, com `f(n) = n * n` ou
`f(n) = n * log(n)`. O O(n²) multiplica por 10² = 100; o O(n log n), por
10 × 5/4 = 12,5. As duas bases dão o mesmo resultado porque a base do log se
cancela na divisão.

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
resultado `r` pela base `b`; depois `b = b * b` e `e = e / 2`. Use
`long long`. A cada volta, imprima `r`, `b`, `e` e se o invariante
**r · bᵉ == 3¹³** continua valendo (calcule `bᵉ` e 3¹³ com uma função de
potência ingênua). No fim, mostre o resultado e quantas voltas o laço deu.

<details><summary>Resposta</summary>

```
volta 1: r = 3, b = 9, e = 6, r * b^e == 3^13? sim
volta 2: r = 3, b = 81, e = 3, r * b^e == 3^13? sim
volta 3: r = 243, b = 6561, e = 1, r * b^e == 3^13? sim
volta 4: r = 1594323, b = 43046721, e = 0, r * b^e == 3^13? sim
3^13 = 1594323 em 4 voltas
```

Dica: a potência ingênua (`r *= b` `e` vezes) serve só para conferir; ela é
O(e). O expoente passa por 13, 6, 3, 1 e 0: cai pela metade a cada volta,
então o laço rápido é O(log e). Quando `e` chega a 0, `bᵉ` é 1 e o
invariante diz que `r` é a resposta.

</details>

**7. Projete antes de codar.** Escreva o `fila_senhas.h` de um TAD para as
senhas de atendimento do banco, seguindo o padrão do assunto 0074 (tipo
opaco e contrato de cada função): `fila_senhas_cria`, `fila_senhas_libera`,
`fila_senhas_tira` (devolve o número da nova senha, começando em 1),
`bool fila_senhas_chama(FilaSenhas *f, int *senha)` (false se ninguém espera)
e `fila_senhas_esperando`. Depois escreva o `fila_senhas.c` e um `main` que
tira 3 senhas, mostra quantos esperam, chama até esvaziar, mostra quantos
esperam, tenta chamar de novo, tira mais uma e mostra quantos esperam.

<details><summary>Resposta</summary>

```
tirou a senha 1
tirou a senha 2
tirou a senha 3
esperando: 3
chamando a senha 1
chamando a senha 2
chamando a senha 3
esperando: 0
ninguem na fila
tirou a senha 4
esperando: 1
```

Dica: como as senhas saem em sequência, o `.c` nem precisa de vetor: a struct
guarda a próxima senha a tirar e a próxima a chamar, e quem espera é a
diferença entre as duas. Nada no `.h` revela isso, então trocar por uma fila
de verdade (módulo 12) não muda uma linha do `main`.

</details>

**8. O contrato fala de custo?** Escreva duas implementações de um
contador de entradas: a versão 1 guarda o valor num `int`; a versão 2 guarda
o horário de cada entrada num vetor de 1000 posições e, ao pedir o valor,
conta as entradas com um laço. Use uma variável global `passos` que soma 1 a
cada entrada registrada e a cada volta de laço (na versão 1, 1 por consulta).
Simule um cliente que registra 1000 entradas e consulta o valor depois de
cada uma, e imprima o valor final e os passos de cada versão.

<details><summary>Resposta</summary>

```
versao 1: valor 1000, 2000 passos
versao 2: valor 1000, 501500 passos
```

Dica: zere `passos` antes de cada simulação. As duas cumprem o contrato
(devolvem o mesmo valor), mas a consulta da versão 1 é O(1) e a da versão 2 é
O(n): o cliente passa de O(n) para O(n²) sem mudar uma linha (1000 +
1 + 2 + ... + 1000 = 501500). Por isso boas bibliotecas documentam o custo
junto com o contrato.

</details>

**9. O par que soma 100.** Escreva
`long par_100(const int *v, int n, int *pi, int *pj)`, que procura o primeiro
par (i < j) com `v[i] + v[j] == 100` usando dois laços, para no primeiro
achado e devolve quantas somas testou (com `-1` em `*pi` e `*pj` se não
achar). Teste com `{40, 60, 10, 20, 30}`, com `{10, 20, 30, 40, 50}` e com
um vetor de 1000 posições com `v[k] = 1000 + k`.

<details><summary>Resposta</summary>

```
melhor caso: par (0, 1) com 1 comparacoes
sem par, n = 5: 10 comparacoes
sem par, n = 1000: 499500 comparacoes
```

Dica: o `j` começa em `i + 1` e o `return` sai dos dois laços de uma vez.
Sem par, todos os n(n − 1)/2 pares são testados: o pior caso é **O(n²)**, e
essa é a classe que se informa. O `return` antecipado melhora a média, não a
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
são O(n): a notação O não enxerga a diferença, o contador enxerga. Como no
assunto 0071, a constante importa quando n é fixo.

</details>

## Questões no estilo da prova

Questões objetivas no formato da prova do mestrado do PPGI/UFAM. Resolva no
papel, marque uma letra e só depois abra o gabarito. As contagens foram
conferidas rodando os trechos (compilados com `gcc -std=c17 -Wall -Wextra`)
com um contador na linha de dentro. As definições de O, Ω e Θ seguem o
Cormen.

**Questão 1.** Quantas vezes a linha `c++` executa, em função de `n`?

```c
for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
        c++;
```

- (A) n
- (B) n²
- (C) n(n − 1)/2
- (D) n(n + 1)/2
- (E) n log₂ n

<details><summary>Gabarito</summary>

**(D)**. Com `i = 0` o laço de dentro roda n vezes, com `i = 1`, n − 1, e
assim até 1: 1 + 2 + ... + n = n(n + 1)/2. Para n = 10, 55. Essa é a
**função de custo**; a classe é Θ(n²). A (C) seria o laço com
`j = i + 1`. Veja 0071 e 0072 (e 0167 para os somatórios).

</details>

**Questão 2.** Qual a complexidade do trecho, com `n` potência de 2?

```c
for (int i = 0; i < n; i++)
    for (int j = 1; j < n; j *= 2)
        c++;
```

- (A) Θ(n)
- (B) Θ(n log n)
- (C) Θ(n²)
- (D) Θ(log n)
- (E) Θ(2ⁿ)

<details><summary>Gabarito</summary>

**(B)**. O laço de fora roda n vezes. O de dentro dobra `j` a cada volta,

log₂ n voltas. Total: n log₂ n (para n = 16, 64). Veja 0072.

</details>

**Questão 3.** Qual a complexidade do trecho, com `n` potência de 2?

```c
for (int i = 1; i < n; i *= 2)
    for (int j = 0; j < i; j++)
        c++;
```

- (A) Θ(log n)
- (B) Θ(n log n)
- (C) Θ(n²)
- (D) Θ(log² n)
- (E) Θ(n)

<details><summary>Gabarito</summary>

**(E)**. A pegadinha: multiplicar "log n voltas por até n" dá n log n, mas
é um teto frouxo. O de dentro roda 1, 2, 4, ..., n/2 vezes: a soma
geométrica dá n − 1 (para n = 64, 63). Some de verdade em vez de
multiplicar os máximos. Veja 0072 e 0167.

</details>

**Questão 4.** Qual alternativa ordena as funções da que cresce **mais
devagar** para a que cresce **mais rápido**?

- (A) log n, √n, n, n log n, n², 2ⁿ, n!
- (B) √n, log n, n, n log n, n², n!, 2ⁿ
- (C) log n, n, √n, n log n, 2ⁿ, n², n!
- (D) log n, √n, n log n, n, n², 2ⁿ, n!
- (E) 1, log n, n, n², n log n, 2ⁿ, n!

<details><summary>Gabarito</summary>

**(A)**. Qualquer potência positiva de n (até √n = n^0,5) acaba passando do
log n. n log n fica entre n e n². Toda exponencial passa qualquer
polinômio, e n! passa 2ⁿ (a partir de n = 4, n! > 2ⁿ). Veja 0072 e 0166.

</details>

**Questão 5.** Seja f(n) = 3n² + 10n. Qual afirmação é **falsa**?

- (A) f(n) = O(n³)
- (B) f(n) = Ω(n)
- (C) f(n) = O(n)
- (D) f(n) = Θ(n²)
- (E) f(n) = Ω(n²)

<details><summary>Gabarito</summary>

**(C)**. O é teto, Ω é piso, Θ é os dois. f cresce como n², então qualquer
teto de ordem n² ou maior vale (A, D) e qualquer piso de ordem n² ou menor
vale (B, E). Mas não existe c com 3n² + 10n ≤ c · n para todo n grande: n²
passa de qualquer reta. Veja 0072 e 0166.

</details>

**Questão 6.** Quantas chamadas de `f` acontecem para calcular `f(5)`, e
qual a ordem de crescimento do número de chamadas?

```c
int f(int n) {
    if (n <= 1) return 1;
    return f(n - 1) + f(n - 1);
}
```

- (A) 31 chamadas; Θ(2ⁿ)
- (B) 5 chamadas; Θ(n)
- (C) 9 chamadas; Θ(n)
- (D) 16 chamadas; Θ(2ⁿ)
- (E) 25 chamadas; Θ(n²)

<details><summary>Gabarito</summary>

**(A)**. Cada chamada com n > 1 abre duas com n − 1: a árvore de chamadas
tem 1 + 2 + 4 + 8 + 16 = 2ⁿ − 1 = 31 nós. O 16 é o **valor** devolvido, não
o número de chamadas. Guardar `f(n - 1)` numa variável e devolver o dobro
derrubaria para Θ(n) chamadas. Veja 0033, 0072 e 0114.

</details>

**Questão 7.** Na busca sequencial num vetor de n elementos distintos, com
o alvo presente e igualmente provável em qualquer posição, quantas
comparações são feitas no melhor caso, no caso médio e no pior caso?

- (A) 0, n/2 e n
- (B) 1, (n + 1)/2 e n
- (C) 1, n/2 e n − 1
- (D) 1, log₂ n e n
- (E) n, n e n

<details><summary>Gabarito</summary>

**(B)**. Melhor caso: o alvo está na posição 0, 1 comparação. Pior caso: na
última, n. Média: (1 + 2 + ... + n)/n = (n + 1)/2. As três funções são
Θ(1), Θ(n) e Θ(n). Veja 0071.

</details>

**Questão 8.** `s` é uma string de n caracteres. Qual a complexidade do
trecho?

```c
for (size_t i = 0; i < strlen(s); i++)
    if (s[i] == ' ') espacos++;
```

- (A) Θ(1)
- (B) Θ(log n)
- (C) Θ(n)
- (D) Θ(n log n)
- (E) Θ(n²)

<details><summary>Gabarito</summary>

**(E)**. O `strlen` percorre a string inteira (Θ(n)) e é chamado a cada
teste da condição, n + 1 vezes. Guardar o tamanho numa variável antes do
laço deixa o trecho Θ(n). Veja 0072.

</details>

**Questão 9.** Duas funções somam um vetor de n inteiros: uma com um `for` e
um acumulador, outra recursiva (`soma(v, n) = v[n-1] + soma(v, n-1)`).
Sobre a **complexidade espacial** (memória extra além do vetor), assinale a
correta.

- (A) As duas usam Θ(1).
- (B) As duas usam Θ(n).
- (C) A iterativa usa Θ(1); a recursiva usa Θ(n), pela pilha de chamadas.
- (D) A iterativa usa Θ(n); a recursiva usa Θ(1).
- (E) A recursiva usa Θ(log n), porque divide o problema.

<details><summary>Gabarito</summary>

**(C)**. As duas fazem Θ(n) somas (mesma complexidade temporal). Mas a
recursiva empilha n frames antes de começar a voltar; a iterativa usa só
`i` e o acumulador. A (E) valeria para uma recursão que divide o vetor ao
meio, não para esta. Veja 0168.

</details>

**Questão 10.** O `contador.h` de um TAD declara só
`typedef struct contador Contador;` e os protótipos das funções
(`contador_cria`, `contador_libera`...). Num cliente que inclui só esse
`.h`, quais linhas **compilam**?

```c
Contador *c = contador_cria(3);     /* I   */
Contador d;                         /* II  */
printf("%zu\n", sizeof(Contador));  /* III */
c->valor = 2;                       /* IV  */
```

- (A) todas
- (B) I e IV
- (C) I, II e III
- (D) apenas I
- (E) nenhuma

<details><summary>Gabarito</summary>

**(D)**. Sem os campos, `struct contador` é um **tipo incompleto** no
cliente: dá para ter ponteiro para ele, mas não variável (II), nem `sizeof`
(III), nem acesso a campo (IV). É o tipo opaco que protege o invariante do
TAD. Veja 0074.

</details>

## Para ler mais

- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Partes sobre documentação, invariantes e análise de algoritmos. Disponível em: <https://www.ime.usp.br/~pf/algoritmos/>.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, Departamento de Informática, 2002. Cap. 9: tipos abstratos de dados.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Tipos abstratos de dados e eficiência.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 1 (tipos abstratos de dados) e seção 6.1 (eficiência e notação O).
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 6: busca e ordenação de vetores.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, Departamento de Eletrônica e Telecomunicações. Cap. 5: memórias e programação modular.
- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024. Cap. 2 (invariantes de laço e análise de algoritmos) e cap. 3 (notação O, Ω e Θ). Referência do edital: em caso de divergência, siga as definições dele.
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Cap. 1: função de complexidade, melhor, pior e caso médio, notação O.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Seção 4.5: arquivos de cabeçalho.
- CPPREFERENCE. *assert*. Disponível em: <https://en.cppreference.com/w/c/error/assert>.
