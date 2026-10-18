# Módulo 00 · Lógica antes do código

Antes de escrever uma linha de C, vale relembrar o que é **programar**: quebrar
um problema em passos tão claros que até uma máquina, que não pensa nada,
consegue seguir.

Você já programa em TypeScript, então muito disto vai soar familiar. A
diferença é o nível. No JS, o Node esconde a memória, os bits e a compilação.
No C, nada fica escondido. Por isso o módulo termina olhando para dentro do
computador: como ele guarda números (binário) e como o seu `.c` vira um
programa que roda.

## O que você vai aprender

- o que é um **algoritmo** e as três peças que montam qualquer programa: sequência, decisão e repetição
- escrever **pseudocódigo** e conferir à mão com o **teste de mesa**
- desenhar e ler **fluxogramas**
- contar em **binário** e **hexadecimal**, e o que são bit e byte
- o caminho do arquivo `.c` até o executável: **pré-processador, compilador, montador e ligador**

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude um valor, quebre de propósito, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas ficam escondidas: abra só se travar.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

> [!NOTE]
> Neste módulo os exemplos já aparecem em C, mas você **não precisa entender a
> sintaxe ainda**: ela começa no módulo 01. Repare só nos passos. Nos
> exercícios de algoritmo, pseudocódigo e fluxograma, a resposta vai como
> comentário dentro do arquivo `.c`.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue; cinza, o que ele não
usa.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você precisa do `gcc` e, para os módulos de memória, do `valgrind`:

```bash
sudo apt install build-essential gdb valgrind   # Ubuntu / Debian
```

Para rodar qualquer arquivo do curso, use o `rodar`, que está na raiz do
projeto. Ele compila com todos os avisos ligados e com o **AddressSanitizer**,
um detetive de erros de memória. Depois roda o programa:

```bash
~/LPEDC/rodar 00-logica/0001-algoritmo/A001.c
```

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas para resolver no papel (ou como comentário num arquivo seu). Use
pseudocódigo, fluxograma ou os dois.

**1. O caixa do mercado.** Escreva o pseudocódigo que lê o preço de 3 produtos,
soma, aplica 10% de desconto se o total passar de R$ 100 e mostra o valor a
pagar. Faça o teste de mesa com R$ 40, R$ 35 e R$ 30.

<details><summary>Resposta</summary>

Total 105, passa de 100, desconto de 10,50: paga **R$ 94,50**. A decisão vem
**depois** da soma: primeiro some, depois pergunte.

</details>

**2. Ano bissexto.** Um ano é bissexto se for divisível por 4 e não por 100, ou
se for divisível por 400. Desenhe o fluxograma e teste com 1900, 2000 e 2024.

<details><summary>Resposta</summary>

1900 **não** (divisível por 100 e não por 400), 2000 **sim** (divisível por
400), 2024 **sim**. Dá para fazer com losangos encadeados ou com uma pergunta só
usando E/OU.

</details>

**3. Adivinhe o número.** Uma pessoa pensa num número de 1 a 100 e responde só
"maior", "menor" ou "acertou". Escreva um algoritmo que sempre acerta em, no
máximo, 7 perguntas.

<details><summary>Resposta</summary>

Chute sempre o **meio** do intervalo que sobrou (50, depois 25 ou 75...). Cada
pergunta corta o intervalo pela metade: 100 → 50 → 25 → 13 → 7 → 4 → 2 → 1.
São 7 cortes, porque 2⁷ = 128 ≥ 100. É a **busca binária** (assunto 0095).

</details>

**4. Troco com o mínimo de notas.** Com notas de 100, 50, 20, 10, 5 e 2,
escreva o pseudocódigo que dá um troco de R$ 186 com o menor número de notas.

<details><summary>Resposta</summary>

100 + 50 + 20 + 10 + 2 + 2 + 2 = 186, **7 notas**. A ideia: para cada nota,
da maior para a menor, `quantidade ← troco div nota` e `troco ← troco mod nota`.

</details>

**5. Teste de mesa com repetição.** Faça o teste de mesa:

```text
x ← 1
enquanto x < 50 faça
    x ← x * 3
fimenquanto
escreva(x)
```

<details><summary>Resposta</summary>

x passa por 1, 3, 9, 27, 81. Quando vira 81, a pergunta `81 < 50` é falsa e o
laço para. Mostra **81**. A pergunta foi feita 5 vezes.

</details>

**6. Binário de cabeça.** Sem calculadora: quanto é `0b11001000` em decimal? E
em hexadecimal?

<details><summary>Resposta</summary>

128 + 64 + 8 = **200**. Separando em grupos de 4 bits: `1100` = C e `1000` = 8,
então **0xC8**.

</details>

**7. Quantos bits?** Um sensor mede temperaturas inteiras de -40 °C a 85 °C.
Quantos bits, no mínimo, para guardar qualquer leitura?

<details><summary>Resposta</summary>

São 126 valores diferentes (de -40 a 85). 2⁶ = 64 não basta e 2⁷ = 128 basta:
**7 bits**. Na prática você usaria um byte inteiro (8 bits).

</details>

**8. Qual etapa reclama?** Para cada erro, diga se aparece no pré-processador,
no compilador, no ligador ou só na execução: (a) `#include <stdoi.h>`; (b)
esquecer um `;`; (c) chamar `calcular()` que não existe em lugar nenhum; (d)
dividir por uma variável que vale zero.

<details><summary>Resposta</summary>

(a) **pré-processador**: arquivo não encontrado; (b) **compilador**: erro de
sintaxe; (c) **ligador**: `undefined reference to 'calcular'` (o compilador só
avisa); (d) **execução**: o programa compila, mas quebra ou dá resultado errado
quando roda.

</details>

## Para ler mais

- CARVALHO, V. A. *Lógica de programação*. Colatina: IFES / e-Tec Brasil, 2010.
- LEAL, G. C. L. *Algoritmos e lógica de programação II*. Maringá: Unicesumar, 2016.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- FORBELLONE, A. L. V.; EBERSPÄCHER, H. F. *Lógica de programação: a construção de algoritmos e estruturas de dados*. 3. ed. São Paulo: Pearson Prentice Hall, 2005.
- BÖHM, C.; JACOPINI, G. Flow diagrams, Turing machines and languages with only two formation rules. *Communications of the ACM*, v. 9, n. 5, p. 366-371, 1966.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Apêndice: sistemas de numeração.
- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 1: a compilação do programa.
- GNU. *Using the GNU Compiler Collection (GCC)*: Overall options. Disponível em: <https://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html>.
