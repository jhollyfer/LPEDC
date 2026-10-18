# Módulo 06 · Ponteiros

Este é o coração do curso. Até aqui você usou variáveis pelo **nome**: o
compilador trocava cada nome por um endereço e escondia isso de você. Neste
módulo a cortina abre. Você vai ver que toda variável mora numa gaveta
numerada da memória, que dá para guardar o número dessa gaveta numa outra
variável e que, com esse número na mão, dá para ler e mudar o dado de
qualquer lugar do programa.

No C, nada acontece por baixo dos panos: se uma função
precisa mudar uma variável sua, você entrega o endereço dela. Parece
trabalho a mais, e é. Em troca, você entende exatamente o que cada linha
custa e por que o `scanf` pedia aquele `&` desde o módulo 01.

Ponteiro é o assunto que separa quem "escreve C" de quem entende C. Tudo o
que vem depois depende dele: memória dinâmica (módulo 07), structs
encadeadas (módulo 08), listas, pilhas, filas, árvores e grafos. Vá devagar,
desenhe as gavetas no papel e rode cada exemplo mais de uma vez.

## O que você vai aprender

- a memória como um **gaveteiro numerado**: endereço, `&` e `%p`
- declarar e usar **ponteiros**: `*`, desreferência e `NULL`
- **passagem por referência**: a troca (swap), funções que devolvem vários resultados e o `&` do `scanf` explicado
- **aritmética de ponteiros** e por que `v[i]` é o mesmo que `*(v + i)`
- a diferença entre `char *` e `char []`, e por que um literal de string é **só leitura**
- **ponteiro para ponteiro** (`**`) e vetor de ponteiros
- **ponteiro para função**: callbacks e o `qsort`
- **`void *`**: o ponteiro genérico, o cast e funções que servem para qualquer tipo

## Como estudar cada assunto

1. Leia o texto e olhe o **diagrama da ideia**: é o exemplo desenhado,
   quase sempre como um gaveteiro com endereços e setas.
2. Leia o código. É o mesmo exemplo, com os mesmos valores.
3. Siga o **fluxograma** com o dedo: é o caminho que o programa faz.
4. Rode os exemplos. Mude um valor, quebre de propósito, rode de novo.
5. Faça os exercícios. ★☆☆ é aquecimento, ★★☆ pede raciocínio, ★★★ é desafio.
   As dicas vêm logo abaixo do enunciado: tente antes de ler.

No meio de cada assunto tem uma **Pergunta para você**. Responda antes de rodar.

> [!NOTE]
> Os endereços dos desenhos são **fictícios** e curtos (`0x1000`, `0x1004`)
> para caber na cabeça. Os de verdade têm 12 dígitos hexa e **mudam a cada
> execução**. Por isso, nas saídas dos exemplos, os endereços que aparecem
> nos comentários são de uma execução qualquer: os seus vão ser outros. O
> que importa são as relações entre eles (iguais, 4 bytes depois etc.).

## As cores e as formas

Caixa azul é dado entrando ou saindo, roxa é o programa fazendo alguma coisa
(no gaveteiro, roxo marca os ponteiros), amarela é pergunta. Verde é o
caminho que o exemplo segue e o resultado; cinza, o que ele não usa;
vermelho, erro.

<p align="center"><img src="../legenda.svg" alt="Legenda: formas e cores do fluxograma" width="916"></p>

## Antes de começar

Você precisa dominar vetores, strings e funções (módulos 04 e 05). Os erros
de ponteiro raramente aparecem na compilação: aparecem quando o programa
roda, às vezes bem longe da linha culpada. Por isso, rode **sempre** com o
`rodar`, que liga o AddressSanitizer. Quando ele acusar algo, leia o
relatório de cima para baixo: o tipo do erro (`stack-buffer-overflow`,
`SEGV on unknown address`), a linha onde aconteceu e a variável envolvida.

Para seguir um ponteiro passo a passo, o `gdb` ajuda muito
(`print p`, `print *p`, `print &x`):

```bash
sudo pacman -S gdb          # Arch Linux
sudo apt install gdb        # Debian / Ubuntu
```

{{indice}}

---

{{assuntos}}

---

## Desafios do módulo

Problemas extras, misturando os assuntos do módulo. Resolva num arquivo seu
e rode com o `rodar`.

**1. O gaveteiro de três níveis.** Ponha num `main` as linhas
`int x = 7; int *p = &x; int **pp = &p; **pp = 9; *pp = NULL;` e, depois
delas, mostre o valor de `x`, o resultado de `p == NULL` e o de `pp == &p`.
Acrescente então `printf("%d\n", *p);`, rode com o `rodar` e veja o que
acontece. Por fim, conserte: só mostre `*p` se `p` não for `NULL`; senão,
mostre `p não aponta para nada`.

<details><summary>Resposta</summary>

Com o `printf` de `*p` solto, o AddressSanitizer derruba o programa:
`AddressSanitizer: SEGV on unknown address 0x000000000000`. Depois do
conserto:

```text
x = 9
p == NULL: 1
pp == &p: 1
p não aponta para nada
```

`**pp = 9` atravessa dois `*` e chega no `x`; `*pp = NULL` atravessa um só e
muda o ponteiro `p`, não o `x`. O `pp` continua guardando o endereço de `p`.
Desenhe sempre o que cada `*` atravessa.

</details>

**2. Minutos de academia.** Escreva
`void resumo(const int *min, int n, int *total, int *dias_acima, double *media)`
que recebe os minutos de treino da semana `{45, 0, 60, 30, 75, 0, 50}` e
devolve o total, quantos dias passaram de 40 minutos e a média dos dias em
que houve treino.

<details><summary>Resposta</summary>

Total **260**, **4** dias acima de 40 (45, 60, 75, 50) e média **52.0** (260
em 5 dias com treino). Caminho: um laço só, três ponteiros de saída; cuidado
para não dividir por zero se a semana inteira for zero.

</details>

**3. Rotação da escala.** A escala de plantão `{"ana", "bia", "caio", "davi",
"eva"}` está num `const char *escala[5]`. Escreva `void gira(const char **v,
int n)` que move todo mundo uma posição para a esquerda (o primeiro vai para
o fim), trocando só ponteiros. Gire duas vezes.

<details><summary>Resposta</summary>

Depois de duas rotações: **caio davi eva ana bia**. Guarde `v[0]` num `const
char *tmp`, ande de `i = 0` a `n - 2` fazendo `v[i] = v[i + 1]` e termine
com `v[n - 1] = tmp`. Nenhum caractere é copiado: só endereços.

</details>

**4. O meu strcat.** Escreva `char *junta(char *destino, const char
*origem)` só com ponteiros: ande até o `'\0'` do destino e copie a origem dali
em diante. Devolva `destino`. Teste com `char cidade[30] = "Campina";` e
`" Grande"`. Depois troque para `char cidade[10]`, rode de novo com o
`rodar` e veja o erro que ele mostra.

<details><summary>Resposta</summary>

Mostra **"Campina Grande"** (14 letras + `'\0'` = 15 bytes). Com `char
cidade[10]`, a cópia passa do fim e o AddressSanitizer acusa
`stack-buffer-overflow`. A função não tem como saber o tamanho do destino:
é por isso que existe `strncat`, e por isso quem chama precisa garantir o
espaço.

</details>

**5. Palavras de uma frase.** Escreva `int conta_palavras(const char *s)`
andando com ponteiro: uma palavra começa quando o caractere atual não é
espaço e o anterior era espaço (ou é o começo). Teste com
`"  pix   caiu na   conta "`.

<details><summary>Resposta</summary>

**4** palavras. Guarde um "estava em espaço?" (começando verdadeiro); a cada
caractere não espaço com a marca ligada, conte e desligue a marca; a cada
espaço, ligue de novo. Espaços repetidos e nas pontas não atrapalham.

</details>

**6. O laço que se encontra no meio.** Rode o trecho abaixo dentro de um
`main` e acrescente, dentro do laço, um `printf` que mostre a cada volta os
índices de `p` e `q` (`p - v` e `q - v`, com `%td`) e o vetor inteiro.
Depois troque a condição para `p <= q` e veja o que muda no `v[2]`.

```c
int v[5] = {1, 2, 3, 4, 5};
int *p = v, *q = v + 4;
while (p < q) {
    *p += *q;
    p++;
    q--;
}
printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);
```

<details><summary>Resposta</summary>

Duas voltas: `p=0 q=4` (vira **6** 2 3 4 5) e `p=1 q=3` (vira 6 **6** 3 4 5);
aí `p` e `q` se encontram em `v[2]` e o laço para: **6 6 3 4 5**. Com
`p <= q` há uma terceira volta com os dois em `v[2]`, que soma o elemento
com ele mesmo: **6 6 6 4 5**.

</details>

**7. Menu sem switch.** Monte um menu de conversões com um vetor de
ponteiros para função `double (*conv[3])(double)`: km para milhas (÷ 1.609),
kg para libras (× 2.205) e °C para °F. Leia a opção (0, 1 ou 2) e o valor
com `scanf`, valide a opção e chame `conv[op](valor)`. Teste com opção 0 e
10 km.

<details><summary>Resposta</summary>

10 km ≈ **6.21 milhas**. O índice lido vira direto a posição no vetor de
funções. Valide `0 <= op && op < 3` antes de chamar: um índice fora do vetor
"chama" um endereço qualquer, e aí nem o AddressSanitizer salva.

</details>

**8. qsort em dupla.** Os pedidos do restaurante estão em dois vetores
paralelos: `int mesa[6] = {4, 2, 7, 2, 4, 1}` e `int minuto[6] = {12, 5, 3,
9, 1, 20}` (minuto em que o pedido chegou). Mostre os pedidos ordenados por
mesa e, dentro da mesma mesa, por minuto, sem mexer nos vetores originais.

<details><summary>Resposta</summary>

Ordem: mesa 1 (min 20), mesa 2 (min 5), mesa 2 (min 9), mesa 4 (min 1),
mesa 4 (min 12), mesa 7 (min 3). Caminho: um vetor de índices `int
ordem[6] = {0, ..., 5}` e uma comparação que lê os vetores paralelos (que
podem ser `static` globais), ou um vetor de `const int *` para `mesa`, como
no assunto 0052, usando `p - mesa` para achar o minuto.

</details>

**9. Endianness na prática.** Escreva `bool little_endian(void)` que
descobre a ordem dos bytes da máquina olhando o primeiro byte de um `int`
que vale 1 (através de um `unsigned char *`). Depois escreva
`unsigned int inverte_bytes(unsigned int x)` que troca a ordem dos 4 bytes
usando a `troca_generica` do assunto 0051 nos bytes certos.

<details><summary>Resposta</summary>

No seu PC, `little_endian()` dá **verdadeiro**: o primeiro byte do 1 é
`01`. `inverte_bytes(0x0A0B0C0D)` dá **0x0D0C0B0A**: troque o byte 0 com o 3
e o 1 com o 2 (`troca_generica(&b[0], &b[3], 1)` e assim por diante, com `b`
sendo um `unsigned char *` para `x`). É o que as funções de rede (`htonl`)
fazem.

</details>

**10. Busca binária genérica.** Escreva `void *busca_bin(const void *chave,
void *v, size_t n, size_t tam, int (*cmp)(const void *, const void *))` que
faz busca binária num vetor já ordenado de qualquer tipo e devolve o endereço
do elemento ou `NULL`. Teste com `int cods[8] = {3, 8, 15, 21, 30, 42, 57,
60}` procurando 42 e 10, e compare com o `bsearch` da `stdlib.h`, que tem
exatamente essa assinatura.

<details><summary>Resposta</summary>

42 está no **índice 5** (subtraia o ponteiro devolvido de `cods`); 10 dá
**NULL**. O meio fica em `(unsigned char *)v + meio * tam`. Compare
`cmp(chave, meio)`: negativo, procure à esquerda; positivo, à direita; zero,
achou. A busca binária em si é o assunto 0090.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 10: ponteiros; cap. 13: ponteiro para função.
- BACKES, A. R. *Linguagem C: descomplicada*. Apostila. Uberlândia: FACOM/UFU. Capítulos de ponteiros e de recursos avançados.
- DEITEL, P. J.; DEITEL, H. M. *C: como programar*. 6. ed. São Paulo: Pearson Prentice Hall, 2011. Cap. 7: ponteiros em C.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002. Ponteiros, vetores e ordenação genérica.
- FEOFILOFF, P. *Algoritmos em linguagem C*. Rio de Janeiro: Elsevier, 2009. Apêndice D: endereços e ponteiros.
- LAUREANO, M. *Estrutura de dados com algoritmos e C*. Rio de Janeiro: Brasport, 2008. Cap. 1 e 2: ponteiros e uso de memória.
- ROCHA, A. M. A.; BORGES, A. R. O. S. *Programação, estruturas de dados e algoritmos em C*. Aveiro: Universidade de Aveiro, DETI. Ponteiros e ponteiro para função.
- HARA, C.; ZOLA, W. *Linguagem C: notas de aula*. Curitiba: UFPR, 2008. Ponteiros e passagem por referência.
- KERNIGHAN, B. W.; RITCHIE, D. M. *C: a linguagem de programação padrão ANSI*. Rio de Janeiro: Campus, 1989. Cap. 5: apontadores e vetores.
- CPPREFERENCE. *Pointer declaration*. Disponível em: <https://en.cppreference.com/w/c/language/pointer>.
- CPPREFERENCE. *qsort, qsort_s*. Disponível em: <https://en.cppreference.com/w/c/algorithm/qsort>.
- KERRISK, M. *qsort(3)*: Linux manual page. Disponível em: <https://man7.org/linux/man-pages/man3/qsort.3.html>.
