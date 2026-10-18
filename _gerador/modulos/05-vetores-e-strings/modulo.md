# Módulo 05 · Vetores, matrizes e strings

Até aqui, cada variável guardava um valor. Para guardar as notas de uma turma,
os passos de um mês ou as poltronas de um cinema, você precisaria de dezenas
de variáveis. Este módulo traz a primeira **estrutura de dados** do curso: o
**vetor**, várias variáveis do mesmo tipo com um nome só, lado a lado na
memória.

No TypeScript, o array é um objeto esperto: cresce com `push`, sabe o próprio
`length`, devolve `undefined` fora dos limites. No C, o vetor é só um bloco de
bytes. Tamanho fixo, nenhum `length`, nenhuma conferência de índice. Parece
pouco, e é justamente por isso que é rápido: acessar a posição 999 custa o
mesmo que acessar a 0.

E o texto? No C não existe um tipo string. Uma string é um vetor de `char`
que termina num byte zero, o `'\0'`. Entender isso explica metade das falhas
de segurança da história do software, e é o que separa quem "usa C" de quem
entende o que o C faz.

## O que você vai aprender

- declarar, inicializar e percorrer **vetores**, e por que o índice começa em 0
- passar vetores para **funções** (vai o endereço, não uma cópia) e proteger com `const`
- **matrizes**: linhas, colunas e a memória contínua por baixo
- **caracteres** como números: a tabela ASCII e o `<ctype.h>`
- **strings**: o `'\0'`, o `<string.h>` e o estouro de buffer
- **ler texto** do teclado com segurança: `fgets`, o `'\n'` e por que o `gets` foi banido

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado, com os
   mesmos valores do código.
2. Leia o código e rode. Mude um valor, um tamanho, um índice. Quebre de
   propósito e veja o que o AddressSanitizer diz.
3. Siga o **fluxograma** com o dedo: quase todo assunto aqui é um laço.
4. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é
   desafio. As dicas ficam escondidas: abra só se travar.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa,
amarela é pergunta. Verde é o caminho que o exemplo segue e o resultado;
cinza, o que ele não usa; vermelho, erro. Nos vetores, cada gaveta tem o
índice embaixo, em cinza.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você vai usar tudo dos módulos anteriores, principalmente laços (`for` e
laços aninhados), os padrões contador, acumulador e maior/menor, e funções com
parâmetros. Ponteiros ainda não apareceram: quando o texto disser "vai o
endereço do vetor", guarde a ideia, que o módulo 06 mostra a sintaxe.

Neste módulo o **AddressSanitizer** do `rodar` vira seu melhor amigo. O C não
confere índice nem tamanho de string, mas o sanitizer confere enquanto o
programa roda. Quando aparecer `stack-buffer-overflow` ou `index out of
bounds`, leia a linha indicada: é quase sempre um `<=` no lugar de `<` ou um
`'\0'` que ficou sem lugar.

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras para treinar, misturando os assuntos do módulo. Resolva num
arquivo seu e rode com o `rodar`.

**1. Segundo maior.** Dado `int v[] = {14, 9, 27, 3, 27, 18};`, ache o segundo
maior valor **diferente** do maior, numa passada só, sem ordenar.

<details><summary>Resposta</summary>

O maior é 27 e o segundo maior é **18** (o outro 27 não conta). Guarde
`maior` e `segundo`. Para cada item: se for maior que `maior`, o antigo
`maior` desce para `segundo`; senão, se for menor que `maior` e maior que
`segundo`, ele vira o `segundo`. Comece os dois com o menor `int` possível
(`INT_MIN`, de `<limits.h>`).

</details>

**2. Remover duplicados de um vetor ordenado.** `int v[] = {2, 2, 3, 5, 5, 5,
8, 9, 9};` Deixe cada valor uma vez só, **no próprio vetor**, e devolva o novo
tamanho.

<details><summary>Resposta</summary>

Fica `2 3 5 8 9` e o tamanho **5**. Use dois índices: `escrita` começa em 1;
`leitura` anda de 1 até o fim e, sempre que `v[leitura] != v[escrita - 1]`,
copia para `v[escrita]` e avança `escrita`. Uma passada só, sem vetor extra.
As posições depois do novo tamanho continuam com valores velhos: quem chama
passa a usar só o tamanho devolvido.

</details>

**3. Juntar duas listas ordenadas.** `a = {1, 4, 9, 12}` e `b = {2, 3, 10}`.
Monte `c` com os 7 valores em ordem, sem ordenar `c` depois.

<details><summary>Resposta</summary>

`1 2 3 4 9 10 12`. Um índice em cada vetor: compare `a[i]` com `b[j]`, copie
o menor para `c[k]` e avance quem foi copiado. Quando um acabar, copie o
resto do outro. É o coração do *merge sort* (assunto 0099).

</details>

**4. Girar a matriz.** Gire `{{1, 2, 3}, {4, 5, 6}}` (2×3) 90° no sentido
horário, gerando uma 3×2.

<details><summary>Resposta</summary>

Resultado: `4 1 / 5 2 / 6 3`. A regra é `g[c][L - 1 - l] = m[l][c]`, com
`L` = número de linhas da original (2). Confira com a célula do 6: na
original está em `[1][2]`, na girada vai para `[2][0]`.

</details>

**5. Quadrado mágico?** Escreva `bool eh_magico(int m[][4])` para uma matriz
4×4: todas as linhas, colunas e as duas diagonais com a mesma soma. Teste com
`{{16, 3, 2, 13}, {5, 10, 11, 8}, {9, 6, 7, 12}, {4, 15, 14, 1}}`.

<details><summary>Resposta</summary>

É mágico: tudo soma **34**. Calcule a soma da primeira linha como referência
e compare as outras 9 somas (3 linhas, 4 colunas, 2 diagonais) com ela. Na
primeira diferente, devolva `false`.

</details>

**6. Anagramas.** "Roma" e "amor" são anagramas (mesmas letras, outra ordem).
Escreva `bool anagramas(const char a[], const char b[])` sem ordenar nada,
ignorando maiúsculas.

<details><summary>Resposta</summary>

Um vetor `int conta[26] = {0}`: cada letra de `a` soma 1 em
`conta[tolower(c) - 'a']`, cada letra de `b` subtrai 1. São anagramas se,
no fim, as 26 posições forem zero. "Roma" e "amor": **sim**. Antes de usar
o caractere como índice, confira com `isalpha`: um espaço ou um byte de "ã"
daria um índice fora do vetor.

</details>

**7. Achar uma palavra dentro da outra.** Sem usar `strstr`, escreva
`int posicao(const char texto[], const char busca[])` que devolve onde
`busca` começa em `texto`, ou -1.

<details><summary>Resposta</summary>

`posicao("banana split", "na")` é **2**; `posicao("banana", "uva")` é **-1**.
Para cada `i` do texto, compare `texto[i + k]` com `busca[k]` enquanto forem
iguais e `busca[k] != '\0'`. Se chegou ao `'\0'` da busca, achou em `i`. Não
precisa de cuidado extra com o fim do texto: o `'\0'` do texto é diferente
de qualquer letra da busca, e a comparação para ali.

</details>

**8. Somar números gigantes.** `long long` vai até uns 9 × 10¹⁸. Some
`"98765432109876543210"` com `"12345678901234567890"` guardando os números
como strings, dígito a dígito, como na escola.

<details><summary>Resposta</summary>

**111111111011111111100**. Ande do último dígito para o primeiro nas duas
strings, some `(a[i] - '0') + (b[j] - '0') + vai_um`, guarde
`soma % 10` e leve `soma / 10`. O resultado sai de trás para frente: inverta
no fim (ou escreva de trás para frente num vetor com uma posição extra para o
último "vai um").

</details>

**9. Cifra de Vigenère.** É a César com um deslocamento diferente para cada
letra, dado por uma chave que se repete. Com a chave "LIMAO", cifre
"ATACARAGORA" (A = 0, B = 1, ..., L = 11...).

<details><summary>Resposta</summary>

Resultado: **LBMCOCISOFL**. A letra `i` do texto anda `chave[i % 5] - 'A'`
posições: A + L = L, T + I = B, A + M = M, C + A = C, A + O = O, R + L = C, e
assim por diante, sempre com `% 26`. Para decifrar, ande `26 - desloc`.

</details>

**10. Jogo da vida, uma geração.** Numa matriz 5×5 de 0 e 1, cada célula
viva com 2 ou 3 vizinhas vivas continua viva; uma morta com exatamente 3
vizinhas nasce; o resto morre ou fica morto. Calcule a próxima geração de um
"pisca-pisca": uma linha de três vivas no meio (`m[2][1]`, `m[2][2]`,
`m[2][3]`).

<details><summary>Resposta</summary>

Ela vira uma **coluna** de três: `[1][2]`, `[2][2]`, `[3][2]`. Na geração
seguinte, volta a ser linha. O cuidado: calcule tudo numa **segunda matriz**.
Se você atualizar a original enquanto conta, as células já mudadas atrapalham
a contagem das vizinhas. A contagem de vizinhas é a do campo minado (E264).

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Caps. 6 (vetores e matrizes), 7 (strings) e 9 (passagem de vetores para funções).
- BACKES, A. *Linguagem C: apostila*. Uberlândia: UFU, [s.d.]. Seções de vetores, matrizes e strings.
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Caps. 6 (arrays) e 8 (caracteres e strings).
- DEITEL, P.; DEITEL, H. *C: how to program*. 7. ed. Boston: Pearson, 2013. Caps. 6 e 8.
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>. Cap. 8.
- LEAL, G. C. L. *Algoritmos e lógica de programação II*. Maringá: Unicesumar, 2016. Unidades de vetores, matrizes e strings.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Caps. 1.6, 1.9 e 5.
- CPPREFERENCE. *Null-terminated byte strings*. Disponível em: <https://en.cppreference.com/w/c/string/byte>.
- LINUX MAN-PAGES PROJECT. *fgets(3)*, *string(3)*, *ctype(3)*. Disponível em: <https://man7.org/linux/man-pages/>.
- SPAFFORD, E. H. The Internet worm program: an analysis. *ACM SIGCOMM Computer Communication Review*, v. 19, n. 1, p. 17-57, 1989.
