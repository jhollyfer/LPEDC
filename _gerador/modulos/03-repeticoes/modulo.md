# Módulo 03 · Laços

Sequência e decisão você já tem. Falta a **repetição**: somar 10 preços,
validar uma senha até acertar, desenhar uma tabela, sortear dados até sair
dupla. Sem laço, você copiaria o mesmo código cem vezes. Com laço, escreve uma
vez e diz **quando parar**.

O C tem cinco palavras para repetir: `while`, `do...while`, `for`, `break` e
`continue`. Todo laço é feito à mão, com contador e condição, e exige três
decisões: como começa, o que muda a cada volta e qual pergunta o termina. Errar
uma delas dá o laço infinito ou a volta a mais, os bugs mais comuns da
programação.

O módulo fecha com os **padrões de laço** (contador, acumulador, maior e menor,
flag e sentinela), que voltam no resto do curso, e com números **aleatórios**.

## O que você vai aprender

- repetir com **`while`** quando não sabe quantas voltas vai dar, e evitar o laço infinito
- usar **`do...while`** para validar entrada e montar menus
- contar com **`for`**: início, condição, passo e o erro por um
- sair de um laço com **`break`** e pular uma volta com **`continue`**
- aninhar laços: tabelas, mapas e desenhos com `*`, e o custo da multiplicação
- os cinco **padrões de laço**: contador, acumulador, maior/menor, flag e sentinela
- sortear números com **`rand`**, **`srand`** e **`time`**, e por que a semente importa

## Antes de começar

Este módulo usa o que você viu antes: `scanf` com o retorno conferido (assunto
0006), `if`, `switch` e o ternário (módulo 02) e `bool` (assunto 0012). Ele
prepara o módulo 04: o sorteio repetido do craps (0027) vira função lá. Por
ora não há funções (módulo 04) nem vetores (módulo 05), então tudo cabe no
`main`.

Para não digitar a entrada a cada teste, mande-a pelo `printf` do terminal,
um valor por linha:

```bash
gcc ~/LPEDC/material/A049.c -o ~/LPEDC/material/A049 && printf '28\n31\n36\n25\n30\n999\n' | ~/LPEDC/material/A049
```

Se um programa travar num laço infinito, `Ctrl+C` encerra. Nos fluxogramas,
toda repetição é uma seta que **volta**: conte quantas vezes você passa por
ela.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras, do médio ao difícil. Crie um arquivo seu para cada um e
compile com as flags de estudo.

**1. Os primos até 100.** Mostre todos os números primos de 2 a 100 e quantos
são. Para cada candidato, teste os divisores com um laço de dentro e saia dele
com `break` no primeiro divisor encontrado.

<details><summary>Resposta</summary>

São **25** primos, de 2 a **97**. Para ficar rápido, o laço de dentro só
precisa ir até a raiz do número: `for (d = 2; d * d <= n; d++)`. Se `n` tem
um divisor maior que a raiz, tem também um menor, que já foi testado.

</details>

**2. Fibonacci passa de mil.** A sequência começa com 1, 1, e cada termo é a
soma dos dois anteriores. Escreva um programa que mostre os termos numa linha
até o primeiro maior que 1000 e, na linha de baixo, esse termo e a posição
dele, contando as posições numa variável.

<details><summary>Resposta</summary>

```text
1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597
Primeiro acima de 1000: 1597 (posição 17)
```

É um `while (b <= 1000)`: você sabe quando parar, mas não quantas voltas são.
O truque é guardar os dois últimos: `prox = a + b; a = b; b = prox;`. A
posição começa em 2 (os dois primeiros 1 já estão contados) e sobe a cada
volta.

</details>

**3. O MDC de Euclides.** O maior divisor comum de dois números não muda se
você trocar o par `(a, b)` por `(b, a % b)`. Repita até `b` virar 0: o MDC é o
`a` que sobrou. Calcule o MDC de 1071 e 462 e conte as voltas.

<details><summary>Resposta</summary>

(1071, 462) → (462, 147) → (147, 21) → (21, 0). MDC = **21**, em **3**
voltas. O laço precisa de uma variável auxiliar: `resto = a % b; a = b; b =
resto;`. Esse algoritmo tem mais de 2.300 anos e ainda é o que se usa.

</details>

**4. Decimal para binário.** Leia um inteiro de 0 a 255 e mostre os 8 bits,
do mais significativo para o menos. Teste com 200.

<details><summary>Resposta</summary>

200 → **11001000**. Um `for` com a potência começando em 128 e dividindo por
2 a cada volta: se `n >= potencia`, mostra 1 e subtrai; senão, mostra 0. Pelo
caminho do `% 2` os bits saem ao contrário (do último para o primeiro), e
sem vetor não dá para guardar e inverter.

</details>

**5. A raiz quadrada de Herão.** Para calcular a raiz de `n`, comece com
`x = n` e repita `x = (x + n / x) / 2` até a diferença entre dois valores
seguidos ficar menor que 0,000000001. Calcule a raiz de 2 e conte as voltas.
Compare com `sqrt(2)`.

<details><summary>Resposta</summary>

**1.414213562** em **5** voltas (2 → 1,5 → 1,41667 → 1,41421569 →
1,41421356...). O número de casas certas praticamente dobra a cada volta. É um
`do...while` (calcula, depois compara com o anterior) e usa `fabs` de
`<math.h>` para a diferença.

</details>

**6. O losango.** Leia um número ímpar `n` (repita até ser ímpar, com
`do...while`) e desenhe um losango de asteriscos com `n` linhas. Com `n = 5`:

```text
  *
 ***
*****
 ***
  *
```

<details><summary>Resposta</summary>

São duas pirâmides: a de cima com `(n + 1) / 2` linhas, crescendo (como no
exercício E143), e a de baixo com as linhas restantes, encolhendo. Em cada
linha, primeiro os espaços, depois os asteriscos. Para `n = 9`, a linha do
meio tem 9 asteriscos.

</details>

**7. O craps tem truque?** Jogue 100 000 rodadas de craps (o algoritmo da
rodada do assunto 0027, sem os `printf`, dentro de um `for`) e calcule a porcentagem de
vitórias e a média de lançamentos por rodada.

<details><summary>Resposta</summary>

Perto de **49,3%** de vitórias e **3,4** lançamentos por rodada (na glibc
com semente 2026: 49,24% e 3,37). A conta exata dá 244/495, ou 49,29%. A casa
ganha 1,4% de todo o dinheiro apostado, no longo prazo. A simulação é um laço
de rodadas com o laço de relançamentos dentro: os contadores da rodada
recomeçam a cada volta de fora.

</details>

**8. Triplas pitagóricas.** Ache todas as triplas `a < b < c`, com `c` até 30,
tais que `a² + b² = c²`. Use três laços aninhados (força bruta) e conte quantas
são.

<details><summary>Resposta</summary>

São **11**: (3, 4, 5), (5, 12, 13), (6, 8, 10), (7, 24, 25), (8, 15, 17),
(9, 12, 15), (10, 24, 26), (12, 16, 20), (15, 20, 25), (18, 24, 30) e (20, 21,
29). Começando o laço de `b` em `a + 1` e o de `c` em `b + 1`, cada tripla
aparece uma vez só. Dá para tirar o terceiro laço: calcule `c * c` e teste se
é um quadrado perfeito.

</details>

**9. Contando setes.** Escreva um programa que conte quantas vezes o dígito 7
aparece quando você escreve todos os números de 1 a 1000, e mostre o total.

<details><summary>Resposta</summary>

```text
Setes de 1 a 1000: 300
```

Um laço de 1 a 1000 e, dentro, um `while` que desmonta uma **cópia** do número
com `% 10` e `/ 10` (como o A040), contando os dígitos 7. Se você desmontar o
próprio contador do `for`, o laço nunca termina. Para conferir: o 7 aparece
100 vezes na casa das unidades, 100 na das dezenas e 100 na das centenas.

</details>

**10. O computador adivinha.** Inverta o jogo do E153: você pensa num número
de 1 a 1000, e o computador chuta. A cada chute você responde 1 (mais alto),
2 (mais baixo) ou 0 (acertou). Escreva esse jogo. Depois, para achar o pior
caso, troque você por um laço que testa cada número secreto de 1 a 1000 e
calcula a resposta sozinho: conte os chutes de cada número e mostre o maior
número de chutes, o primeiro secreto que precisou dele e quantos secretos
precisaram dele.

<details><summary>Resposta</summary>

```text
Pior caso: 10 chutes (primeiro número assim: 2)
Números que precisam de 10 chutes: 489
```

O computador guarda o intervalo possível (`menor = 1`, `maior = 1000`), chuta
sempre o meio, `(menor + maior) / 2`, e corta metade a cada resposta: com 1,
`menor = chute + 1`; com 2, `maior = chute - 1`. No máximo 10 chutes, porque
2¹⁰ = 1024 ≥ 1000. É a **busca binária**, que volta no assunto 0090.

</details>

## Questões do POSCOMP

Questões reais do POSCOMP (SBC) sobre este módulo. O enunciado está no caderno oficial: abra o link, resolva e confira o gabarito.

| Ano | Questão | Assunto | Gabarito | Prova |
| --- | --- | --- | --- | --- |
| 2024 | 25 | Instruções de repetição while, do-while, for | B | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2024.pdf) |
| 2025 | 46 | Laço for com iterações conhecidas | a conferir no gabarito oficial | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2025.pdf) |

O gabarito oficial de 2025 não estava disponível quando este material foi montado.


## Questões no estilo da prova

Questões objetivas no formato da prova do PPGI: uma alternativa certa. Faça o
teste de mesa: uma linha por volta, com o valor de cada variável.

**1.** Quantas vezes o corpo do laço executa, e quanto vale `i` no fim?

```c
int i = 10, cont = 0;
while (i > 0) {
    i -= 3;
    cont++;
}
```

- (A) 3 vezes; `i` vale 1
- (B) 3 vezes; `i` vale 0
- (C) 4 vezes; `i` vale 0
- (D) 4 vezes; `i` vale -2
- (E) 10 vezes; `i` vale 0

<details><summary>Gabarito</summary>

**(D).** `i` passa por 10, 7, 4 e 1, sempre positivo na pergunta: 4 voltas.
Na última, 1 - 3 dá -2, e aí `i > 0` é falso. O `i` nunca vale 0. Veja 0020.

</details>

**2.** Sobre as estruturas de repetição do C, considere as afirmações e marque a alternativa CORRETA.

- **I.** O `do...while` executa o corpo pelo menos uma vez.
- **II.** `for (;;)` é um erro de compilação, porque falta a condição.
- **III.** O `continue` encerra o laço por completo.
- **IV.** O `break` dentro do laço mais interno de dois laços aninhados encerra só esse laço interno.

- (A) Apenas I e IV
- (B) Apenas I e II
- (C) Apenas II e III
- (D) Apenas III e IV
- (E) Apenas I, III e IV

<details><summary>Gabarito</summary>

**(A).** I é verdadeira: o teste fica no fim. II é falsa: condição omitida vale verdadeiro, e `for (;;)` é o laço infinito clássico. III é falsa: o `continue` só pula para a próxima volta. IV é verdadeira: o `break` sai do laço mais próximo. Veja 0021, 0022 e 0023.

</details>

**3.** Qual a saída?

```c
int j;
for (j = 0; j < 5; j++);
    printf("%d\n", j);
```

- (A) 0 1 2 3 4, um por linha
- (B) 4
- (C) 5
- (D) 0 1 2 3 4 5, um por linha
- (E) nada

<details><summary>Gabarito</summary>

**(C).** O `;` logo depois do `for` é um **corpo vazio**: o laço só conta de
0 até 5 e acaba. O `printf`, apesar do recuo, está fora do laço e roda uma vez,
com `j` valendo 5 (o valor que fez a condição falhar). Veja 0022.

</details>

**4.** Quantas vezes `c++` executa?

```c
int c = 0;
for (int a = 0; a < 4; a++)
    for (int b = a; b < 4; b++)
        c++;
```

- (A) 16
- (B) 4
- (C) 6
- (D) 8
- (E) 10

<details><summary>Gabarito</summary>

**(E).** O laço de dentro começa em `a`: roda 4, 3, 2 e 1 vezes, para `a`
igual a 0, 1, 2 e 3. A soma 4 + 3 + 2 + 1 é 10, ou `n (n + 1) / 2` com
`n = 4`. O 16 seria com `b` começando sempre em 0. Veja 0024.

</details>

**5.** Qual o valor de `s` no fim?

```c
int s = 0;
for (int k = 1; k <= 10; k++) {
    if (k % 3 == 0) continue;
    if (k > 7) break;
    s += k;
}
```

- (A) 55
- (B) 19
- (C) 28
- (D) 12
- (E) 37

<details><summary>Gabarito</summary>

**(B).** O `continue` pula os múltiplos de 3 (3 e 6) e vai para o `k++`. O
`break` encerra o laço no `k = 8`. Somam 1 + 2 + 4 + 5 + 7 = 19. O 28 seria a
soma de 1 a 7 sem o `continue`. Veja 0023.

</details>

**6.** Qual valor o pseudocódigo escreve?

```text
x ← 1
repita
    x ← x * 2
até x > 20
escreva x
```

- (A) 16
- (B) 20
- (C) 2
- (D) 32
- (E) 64

<details><summary>Gabarito</summary>

**(D).** `x` passa por 2, 4, 8, 16 e 32. O `repita ... até` testa no fim e
**para** quando a condição fica verdadeira: só com 32 o `x > 20` vale. Em C,
fica `do { x = x * 2; } while (!(x > 20));`. Veja 0021.

</details>

**7.** Qual a saída?

```c
int k = 0;
while (k++ < 3)
    printf("%d ", k);
printf("| %d\n", k);
```

- (A) `1 2 3 | 4`
- (B) `0 1 2 | 3`
- (C) `1 2 3 | 3`
- (D) `0 1 2 3 | 4`
- (E) `1 2 | 3`

<details><summary>Gabarito</summary>

**(A).** O `k++` compara o valor **antigo** e só depois soma 1. As
comparações são 0 < 3, 1 < 3 e 2 < 3 (verdade), e dentro do corpo o `k` já
vale 1, 2 e 3. A quarta comparação, 3 < 3, é falsa, mas o `k++` roda mesmo
assim: `k` termina em 4. Veja 0020 e 0009.

</details>

**8.** Quantas vezes o corpo do laço executa?

```c
for (unsigned u = 3; u >= 0; u--)
    printf("%u\n", u);
```

- (A) 3
- (B) 4
- (C) 0
- (D) 5
- (E) infinitas vezes

<details><summary>Gabarito</summary>

**(E).** Um `unsigned` nunca é negativo, então `u >= 0` é **sempre**
verdade. Depois do 0, `u--` dá a volta para o maior `unsigned` (4294967295
com 32 bits) e o laço segue. O `-Wextra` avisa: `comparison of unsigned
expression in '>= 0' is always true`. Veja 0022 e 0003.

</details>

**9.** Considere as afirmações sobre laços e marque a alternativa CORRETA.

- **I.** Com `n = 0`, um `for (int i = 0; i < n; i++)` executa o corpo zero vezes, e um `do...while` equivalente o executa uma vez.
- **II.** Dois `for` aninhados, ambos de 0 a `n - 1`, executam o corpo interno `n * n` vezes.
- **III.** Um `;` logo depois do `)` do `for` é erro de compilação.
- **IV.** A variável declarada no cabeçalho, em `for (int i = 0; ...)`, continua visível depois do laço.

- (A) Apenas I
- (B) Apenas I e II
- (C) Apenas II e IV
- (D) Apenas I, II e III
- (E) Apenas III e IV

<details><summary>Gabarito</summary>

**(B).** I e II são verdadeiras. III é falsa: o `;` compila e vira corpo vazio, e o `printf` seguinte roda uma vez só (veja a questão 3). IV é falsa: desde o C99, `i` morre no fim do `for`. Veja 0020, 0021, 0022 e 0024.

</details>

## Para ler mais

- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 3 e 4: estruturas de repetição; cap. 5: geração de números aleatórios e o jogo de craps.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Capítulo de controle de fluxo: `while`, `do-while`, `for`, `break` e `continue`.
- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 5: comandos de repetição.
- BACKES, A. R. *Linguagem C: descomplicada*. Apostila. Uberlândia: FACOM/UFU. Cap. 5.
- HARA, C.; ZOLA, W. *Linguagem C: notas de aula*. Curitiba: UFPR, 2008.
- LEAL, G. C. L. *Algoritmos e lógica de programação II*. Maringá: Unicesumar, 2016.
- CARVALHO, V. A. *Lógica de programação*. Colatina: IFES / e-Tec Brasil, 2010.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- MARTINS, L. G. A. *Apostila de linguagem C: conceitos básicos*. Uberlândia: FACOM/UFU.
- DORNELLES F., A. A. *Fundamentos de linguagem C*. Caxias do Sul: SENAI-RS, 1997.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Seções 3.5 a 3.8: laços, break, continue e goto.
- CPPREFERENCE. *rand*. Disponível em: <https://en.cppreference.com/w/c/numeric/random/rand>.
- LINUX MAN-PAGES PROJECT. *rand(3)*. Disponível em: <https://man7.org/linux/man-pages/man3/rand.3.html>.
