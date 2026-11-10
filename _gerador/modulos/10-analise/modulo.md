# Módulo 10 · Pensar como cientista da computação

Até aqui a pergunta foi "como escrevo isso em C?". Daqui em diante, com
listas, pilhas, árvores e grafos, passa a ser "**qual** jeito de escrever é o
certo?". Vetor ou lista encadeada, busca sequencial, binária ou hash: todos
funcionam com 10 itens. Com 1 milhão, uns respondem na hora e outros travam o
servidor.

Três ideias, que atravessam o resto do curso: **medir o custo** contando
passos e resumindo o crescimento na notação O; **ter certeza de que está
certo** com invariantes de laço, em vez de meia dúzia de testes; e **esconder
os detalhes** atrás de um tipo abstrato de dado, para trocar a implementação
sem quebrar quem usa.

Usa o que veio antes: funções, vetores, ponteiros, `malloc`/`free` e `struct`
(os arquivos do módulo 09 já mostraram o ganho do acesso direto, que aqui vira
a notação O). Prepara os módulos 11 a 16: cada estrutura será medida em O e
construída como TAD.

## O que você vai aprender

- medir a **eficiência** contando passos: melhor, pior e caso médio
- ler e escrever a **notação O**: O(1), O(log n), O(n), O(n log n) e O(n²), e por que constantes somem
- enunciar **invariantes de laço** e usá-los para provar um laço (e achar bugs)
- montar um **tipo abstrato de dado** com interface (`.h`), implementação (`.c`) e tipo opaco: o padrão dos próximos módulos

## Antes de começar

Nos exemplos, mude o n, troque os dados, quebre um invariante de propósito e
veja o `assert` disparar. Nos desenhos de custo, verde é o que continua leve e
vermelho, o que explodiu. Os contadores de passos medem trabalho, não
segundos: os números saem iguais aos do texto na sua máquina.

Novidades pequenas:

- `<assert.h>`: `assert(condicao)` para o programa na hora se a condição for
  falsa. É assim que um invariante vira código.
- **arquivos de apoio**: no 0074, a pasta tem `contador.h`, `contador.c`,
  `conta.h` e `conta.c`. O comando do exemplo compila junto todo `.c` da pasta
  que não se chama `A000.c`/`E000.c`:

```bash
gcc ~/LPEDC/A147.c ~/LPEDC/0074-conta.c ~/LPEDC/0074-contador.c -o ~/LPEDC/A147 && ~/LPEDC/A147
```

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas dos quatro assuntos, do médio ao difícil. Todos pedem código:
escreva num arquivo seu e compile com as flags de estudo.

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

Formato da prova do mestrado do PPGI/UFAM. Resolva no papel, marque uma letra
e só depois abra o gabarito. Nas questões de contagem, o resultado foi
conferido rodando o trecho em C (`gcc -std=c17 -Wall`) com um contador. As
definições de O, Ω e Θ seguem o Cormen. Desconfie de "sempre", "com certeza"
e "nunca": quase sempre derrubam a afirmação.

**Questão 1.** Seja f(n) = 3n² + 40n + 7. Marque a alternativa **INCORRETA**.

- (A) f(n) é O(n²).
- (B) f(n) é Θ(n³).
- (C) f(n) é O(n³).
- (D) f(n) é Ω(n).
- (E) f(n) é Θ(n²).

<details><summary>Gabarito</summary>

**(B)**. Θ é teto e piso ao mesmo tempo. Como f cresce como n², o teto n³ é
folgado (C é verdadeira) e o piso n é folgado (D é verdadeira), mas n³ nunca
serve de piso: f não é Ω(n³), logo não é Θ(n³). Só n² é teto e piso juntos
(A e E). Veja 0072.

</details>

**Questão 2.** Sobre a busca em um vetor de `n` inteiros, considere as afirmações:

I. A busca sequencial tem melhor caso O(1), mesmo com o vetor desordenado.
II. A busca binária funciona em qualquer vetor, desde que `n` seja potência de 2.
III. No pior caso, a busca binária examina ⌊log₂ n⌋ + 1 elementos.
IV. A busca binária é, com certeza, mais rápida que a sequencial para qualquer chave.

- (A) Apenas I.
- (B) Apenas II e III.
- (C) Apenas III e IV.
- (D) Todas estão corretas.
- (E) Apenas I e III.

<details><summary>Gabarito</summary>

**(E)**. I é verdadeira: se a chave está na posição 0, a sequencial pára no
primeiro exame. II é falsa: o que a binária exige é o vetor **ordenado**, não
um tamanho especial. III é verdadeira (para n = 1000, são 10 exames no pior
caso). IV é falsa por causa do "com certeza": para uma chave que está na
posição 0, a sequencial faz 1 comparação e a binária, 3 ou mais. Veja 0071
e 0072 (e 0090 para a busca binária).

</details>

**Questão 3.** O vetor ordenado abaixo tem 12 posições. A busca binária usa
`meio = (ini + fim) / 2` e conta **uma comparação por elemento `v[meio]`
examinado** (acertou ou errou). Quantas comparações, no total, são feitas ao
buscar em sequência as chaves 4, 82 e 50?

```c
int v[] = {4, 9, 15, 22, 27, 31, 38, 44, 53, 61, 70, 82};
```

- (A) 9
- (B) 10
- (C) 11
- (D) 12
- (E) 13

<details><summary>Gabarito</summary>

**(C)**. Chave 4: examina `v[5]` = 31, `v[2]` = 15, `v[0]` = 4: 3
comparações. Chave 82: `v[5]`, `v[8]` = 53, `v[10]` = 70, `v[11]` = 82: 4.
Chave 50 (não existe): `v[5]`, `v[8]` = 53, `v[6]` = 38, `v[7]` = 44, e
então `ini` passa de `fim`: 4. Total 3 + 4 + 4 = 11. Com 12 elementos o máximo
é ⌊log₂ 12⌋ + 1 = 4 por busca. Veja 0090.

</details>

**Questão 4.** Quantas vezes a linha `c++` executa para `n = 81`?

```c
long c = 0;
for (int i = 1; i <= n; i *= 3)
    for (int j = 0; j < i; j++)
        c++;
```

- (A) 40
- (B) 81
- (C) 120
- (D) 121
- (E) 243

<details><summary>Gabarito</summary>

**(D)**. `i` assume 1, 3, 9, 27 e 81 (o 243 já passa de `n`), e a cada valor
o laço de dentro roda `i` vezes: 1 + 3 + 9 + 27 + 81 = 121. É uma soma
geométrica, dominada pelo último termo, então o custo é Θ(n). A (C) esquece
o 1 da primeira volta. Veja 0071 e 0072.

</details>

**Questão 5.** Considere as afirmações sobre invariantes de laço:

I. O invariante precisa valer antes da primeira iteração e continuar valendo
depois de cada iteração.
II. Quando o laço termina, o invariante, junto com a negação da condição do
laço, deve implicar que o resultado está correto.
III. Um invariante verdadeiro garante, sempre, que o algoritmo está correto,
não importando o que o laço faz ao terminar.

- (A) Apenas I e II.
- (B) Apenas II e III.
- (C) Apenas I e III.
- (D) Apenas III.
- (E) Todas estão corretas.

<details><summary>Gabarito</summary>

**(A)**. I e II são as etapas de início, manutenção e término da prova por
invariante. III é falsa: o invariante `i >= 0` vale em quase todo laço e não
prova nada. Ele só serve se, no término, junto com a condição de parada,
levar ao resultado que a função promete. Veja 0073.

</details>

**Questão 6.** A função abaixo deveria devolver o maior elemento de `v` (com
`n >= 1`). O programador quer manter o invariante "no começo de cada volta,
`m` é um máximo de `v[0..i-1]`". Qual afirmação sobre o código é **correta**?

```c
int maior(int v[], int n) {
    int m = v[0];
    for (int i = 1; i <= n; i++) {
        if (v[i] > m)
            m = v[i];
    }
    return m;
}
```

- (A) `m` deveria começar em 0, senão o invariante não vale antes da primeira volta.
- (B) O laço deveria começar em `i = 0`, porque `v[0]` ainda não foi comparado.
- (C) A condição `i <= n` faz a última volta ler `v[n]`, fora do vetor, e o resultado pode ficar errado.
- (D) O código está correto: `v[n]` existe, e o `>` já garante o máximo.
- (E) O código devolve o menor elemento, pois o invariante está invertido.

<details><summary>Gabarito</summary>

**(C)**. Com `i = n`, a função lê `v[n]`, uma posição que não existe (um
vetor de `n` posições vai de 0 a `n - 1`). O comportamento é indefinido: com o
vetor `{3, 9, 4}` e `n = 3`, o AddressSanitizer acusa `heap-buffer-overflow`
ao ler a quarta posição. A (A) está errada porque `m = v[0]` já faz o
invariante valer com `i = 1`; começar em 0 quebraria o caso de vetor só de
negativos. B só repete uma comparação, e E confunde o sentido do `>`. O
laço correto é `i < n`. Veja 0073 e 0054.

</details>

**Questão 7.** Quantas vezes a função `t` é chamada ao executar `t(8)`,
contando a chamada inicial?

```c
void t(int n) {
    if (n > 2) {
        t(n - 2);
        t(n - 3);
    }
}
```

- (A) 8
- (B) 13
- (C) 15
- (D) 21
- (E) 24

<details><summary>Gabarito</summary>

**(B)**. Seja C(n) o número de chamadas: C(n) = 1 quando n ≤ 2 e
C(n) = 1 + C(n − 2) + C(n − 3) quando n > 2. Daí C(3) = 3, C(4) = 3,
C(5) = 5, C(6) = 7, C(7) = 9 e C(8) = 1 + C(6) + C(5) = 1 + 7 + 5 = 13.
Conferido rodando o programa com um contador. Veja 0071 e 0032.

</details>

**Questão 8.** Um algoritmo de custo Θ(n²) leva 2 segundos para processar
uma entrada de tamanho n = 2000. Desprezando os termos menores, quanto
tempo ele leva, aproximadamente, para n = 10000?

- (A) 10 s
- (B) 20 s
- (C) 25 s
- (D) 40 s
- (E) 50 s

<details><summary>Gabarito</summary>

**(E)**. O tamanho foi multiplicado por 5, e o custo, que cresce com n²,
é multiplicado por 5² = 25: 2 s × 25 = 50 s. A (A) seria o raciocínio de um
algoritmo linear. A (C) esquece de multiplicar pelos 2 s originais. Veja
0072.

</details>

**Questão 9.** Considere as afirmações sobre tipos abstratos de dados (TAD)
em C:

I. Num tipo opaco, o `.h` declara apenas `typedef struct pilha Pilha;` e a
definição da `struct` fica no `.c`.
II. Com um tipo opaco, é possível trocar a implementação (por exemplo, de
vetor para lista encadeada) sem alterar o código de quem usa o TAD.
III. Quem usa um TAD opaco pode acessar `p->topo` diretamente, desde que
inclua o `.h`.
IV. O TAD define **o que** cada operação faz; **como** ela faz, e portanto o
seu custo, depende da implementação escolhida.

- (A) Apenas I e II.
- (B) Apenas II e III.
- (C) Apenas III e IV.
- (D) Apenas I, II e IV.
- (E) Todas estão corretas.

<details><summary>Gabarito</summary>

**(D)**. I, II e IV descrevem o TAD como o curso o usa. III é falsa: com o
tipo opaco o compilador só conhece o nome, e `p->topo` dá erro de "tipo
incompleto". É justamente isso que protege o invariante da estrutura. Veja
0074.

</details>

**Questão 10.** Um vetor tem 100 chaves distintas, e a chave buscada está
no vetor, com a mesma probabilidade em cada posição. Na busca sequencial, o
número médio de comparações é:

- (A) 50,5
- (B) 50
- (C) 51
- (D) 99,5
- (E) 100

<details><summary>Gabarito</summary>

**(A)**. Achar a chave na posição k custa k comparações, com k de 1 a 100,
todas igualmente prováveis. A média é (1 + 2 + ... + 100) / 100 = (n + 1) / 2
= 50,5. O pior caso (100, alternativa E) e o melhor (1) são os
extremos; a média fica no meio. Veja 0071.

</details>

## Questões de provas do PPGI

Questões reais das provas de conhecimento do PPGI/UFAM, na íntegra e com o gabarito oficial. Resolva no papel, em 3 minutos por questão, e só depois abra o gabarito.

**Edital 060/2019 · Questão 03**

Qual a alternativa que completa corretamente a seguinte frase: Um algoritmo que possui número de operações _______________ em função de uma entrada de tamanho n é linear.

- a) n³ + 9
- b) 3n² + 3n + 2
- c) 6
- d) 2n + 1
- e) n² + 1

<details><summary>Gabarito</summary>

**D.** 2n+1 é linear. Assunto 0071.

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
