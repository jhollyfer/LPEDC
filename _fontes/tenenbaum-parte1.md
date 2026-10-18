# Fichamento — Tenenbaum, Langsam, Augenstein, *Estruturas de Dados Usando C* (parte 1)

- **Obra:** *Estruturas de Dados Usando C* (orig. *Data Structures Using C*, Prentice Hall, 1989). Tradução de Teresa C. F. de Souza; revisão técnica de Roberto C. Mayer. MAKRON Books, 1995.
- **Autores:** Aaron M. Tenenbaum, Yedidyah Langsam, Moshe J. Augenstein.
- **Trecho lido:** linhas 1–9590 do .md (prefácio; cap. 1 Introdução / vetores / estruturas; cap. 2 Pilha e notações infixa/posfixa/prefixa; cap. 3 Recursividade, incluindo simulação com pilha e eficiência; cap. 4 Filas e listas, incluindo simulação de banco; cap. 5 Árvores, incluindo Huffman, listas como árvores, árvores gerais e árvores de jogos). Parei no início do cap. 6 (Classificação).

## Avaliação geral

Livro clássico, denso e muito bom de **conceito**: separa sempre o TDA (o que a estrutura faz)
da implementação (como é feita), mostra duas ou três implementações da mesma ideia e discute
os compromissos de tempo e espaço. Os traços passo a passo (pilha de avaliação posfixa,
conversão infixa→posfixa, pilha de recursão do fatorial e do Fibonacci, eliminação de
recursão) são excelentes e valem ser adaptados.

O que é **datado**: C de K&R (1ª edição) com parâmetros declarados fora dos parênteses,
`extern char *malloc()`, structs nunca passadas por valor nem atribuídas, `#define TRUE 1`,
`return(x)` com parênteses, `goto` nas simulações, uso de `exit(1)` dentro de rotinas de
biblioteca. A versão .md tem **muitos erros de OCR** (`l` no lugar de `1`, `—` no lugar de
`--`, `1=` no lugar de `!=`) e alguns **bugs reais de código e de tradução** (listados abaixo,
em cada assunto e na seção final). Use o livro para ideias e exercícios, nunca para copiar código.
A terminologia também difere da usada hoje ("completa" e "quase completa", "linha" para
*thread*, "classificação" para ordenação, "espalhamento" para hashing).

---

### 0004-binario

**Conceitos-chave**
- Um bit é a menor unidade: uma escolha entre duas possibilidades exclusivas. `n` chaves liga/desliga distinguem `2^n` estados; 3 bits bastam para 8 posições de um seletor.
- **Um padrão de bits não tem significado próprio**: é a interpretação que dá significado. O mesmo `00100110` pode ser 38 (binário puro), 26 (BCD) ou o caractere `'&'` (em certa tabela). "Tipo de dado" é justamente um **método de interpretar** bits.
- Binário posicional: cada posição vale uma potência de 2, a da direita é 2^0.
- Negativos: **complemento de um** (inverte todos os bits; tem +0 e −0) e **complemento de dois** (complemento de um + 1; um só zero; faixa assimétrica de −2^(n−1) a 2^(n−1)−1).
- **BCD**: cada grupo de 4 bits é um dígito decimal; códigos 1010–1111 são inválidos.
- Ponto flutuante (modelo didático do livro, não IEEE): mantissa × base^expoente. A precisão é limitada pelos bits da mantissa: 10.000.001 vira 10.000.000 se faltar bit.
- Caracteres: cada caractere é um padrão de bits combinado por convenção; "tamanho do byte" é o número de bits usado por caractere (7, 8, 10 bits em máquinas diferentes).

**Analogias/explicações boas**
- Interruptor de luz = 1 bit; seletor de 8 posições = 3 bits. Quantas chaves preciso para imitar um seletor de 8 posições? Pergunta ótima para abrir a aula.
- O hardware "sabe" que um padrão é inteiro do mesmo jeito que a lâmpada "sabe" que está acesa: foi construído para reagir assim. Quem escolhe a interpretação é a instrução usada.

**Pegadinhas**
- Achar que o computador "guarda números": ele guarda bits, e o tipo decide a leitura.
- Em complemento de dois, o menor negativo não tem positivo correspondente (−128 em 8 bits).
- Zero negativo existe em complemento de um, mas não em complemento de dois.

**Ideias de exemplos**
- Tabela de um byte lido de três jeitos: `00100110` → 38 / 26 (BCD) / `'&'`.
- Passo a passo de −38 em 8 bits: 38 = 00100110 → C1 = 11011001 → C2 = 11011010.

**Ideias de exercícios** (adaptados do 1.1.4)
- Interprete cada padrão como binário sem sinal, complemento de dois e BCD:
  - `10011001` → 153 / −103 / 99
  - `1001` → 9 / −7 (em 4 bits) / 9
  - `000100010001` → 273 / 273 / 111
  - `01110111` → 119 / 119 / 77
  - `100000010101` → 2069 / −2027 (em 12 bits) / 815
- Quantos bits são necessários para `m` estados? (resposta: ⌈log2 m⌉).
- "Computador ternário": como seria a numeração com *trits*? Converter binário↔ternário.

---

### 0007-variaveis e 0008-tipos-e-limites

**Conceitos-chave**
- Uma declaração faz duas coisas: (1) reserva uma quantidade de memória e (2) diz como interpretar esses bits. O identificador é um apelido conveniente para um endereço.
- O operador `+` é **genérico**: o compilador escolhe soma inteira ou de ponto flutuante olhando os tipos dos operandos.
- `short`, `long` e `unsigned` mudam o tamanho e a faixa; o tamanho real depende da máquina. `unsigned` segue aritmética módulo 2^n.
- Nenhuma implementação representa "o inteiro matemático", apenas "inteiro entre x e y".

**Analogia boa**
- A declaração funciona como um molde ou gabarito colocado sobre um trecho da memória.

**Pegadinhas**
- O livro assume `int` de 4 bytes e `float` de 8 bytes nos exemplos; hoje `float` tem 4. Use `sizeof` e não números fixos.

**Ideia de exercício**
- Mostrar com `printf` que os mesmos 4 bytes lidos como `int` e como `float` (via `union` ou `memcpy`) dão valores totalmente diferentes.

---

### 0009-constantes

**Conceitos-chave**
- Use `#define NUMELTS 100` para o tamanho do vetor: muda-se num só lugar (declaração e laço).
- Sequências de escape: `\0`, `\n`, `\t`, `\b`, `\"`, `\\`, `\'`, `\r`, `\f`.
- A string `"HELLO THERE"` ocupa 12 posições (11 caracteres + `'\0'`).

**Pegadinha**
- Esquecer de contar o `'\0'` ao calcular o tamanho de uma string literal.

---

### 0012-aritmetica e 0013-conversao

**Pegadinha real do livro (ótimo exemplo de "ache o erro")**
- No programa de média e desvios, `total` é `int`, `NUMELTS` é inteiro e o código faz `avg = total / NUMELTS;` com `avg` `float`: a divisão é **inteira** antes da conversão. Além disso, imprime `avg` e `diff` (floats) com `%d`. Corrigir: `(float) total / NUMELTS` e `%f`.
- Exemplo dos racionais: 1/3 + 1/3 em decimal aproximado dá .666666 e 2/3 dá .666667, então o teste de igualdade falha. Serve para mostrar o limite do ponto flutuante.

---

### 0030-padroes-de-laco

**Conceitos-chave**
- Por que guardar as entradas num vetor, mas a diferença numa variável simples? Porque cada número precisa ser revisitado depois que a média é conhecida, e cada diferença é usada uma vez e descartada. Regra prática: **guarde só o que você vai precisar ler de novo.**
- Índice direto evita `switch` gigante: `scanf("%d%d", &ano, &vendas[ano])` em vez de dez variáveis `s0..s9`.

**Ideias de exercícios**
- Mediana e moda de um vetor (moda inexistente se houver empate).
- Temperaturas por latitude (−90..90): média por latitude, "sem dados" quando vazia, média dos hemisférios como média das médias e hemisfério mais quente usando só latitudes com par.

---

### 0034-parametros

**Conceitos-chave**
- Passagem por valor: o parâmetro é uma cópia. Exemplo clássico: `x = 5; funct(x);` em que `funct` incrementa e imprime 6, mas `x` continua 5 no chamador.
- Para alterar a variável do chamador, passe `&x` e use `*py` dentro da função.

**Ideia de exemplo**
- O traço linha a linha 5 → 6 → 5 (por valor) contra 5 → 6 → 6 (por ponteiro), com os mesmos números de linha nos dois programas.

---

### 0035-escopo (e um pouco de 0039-modulos)

**Conceitos-chave**
- Variáveis **automáticas**: parâmetros e locais, criadas na chamada e destruídas no retorno. Um bloco interno pode redeclarar e esconder um nome externo.
- **Externas/globais**: definidas fora de funções, existem o programa todo, visíveis do ponto da declaração até o fim do arquivo.
- `extern` em outro arquivo **declara sem alocar**; o tamanho do vetor aparece só na definição.
- `static` local: guarda o valor entre chamadas (contador de chamadas).
- `register`: sugestão de otimização (hoje obsoleta na prática).
- Estáticas e externas não inicializadas valem 0; automáticas têm lixo.

**Ideia de exemplo (excelente para teste de mesa)**
- Programa em dois arquivos com globais `x, y, z`; `func1` atribui 1, 2, 3 e locais a=1, b=2; `func2` tem local `a=5`; `func3` incrementa `y` e um `static b`; `func4` declara `x, y, z` locais 10, 20, 30. Saída esperada, linha a linha: `1 2 3 1 2` / `1 2 3` / `1 2 3 5` / `1 3 3 1` / `1 4 3 2` / `10 20 30` / `1 4 3`. Peça ao aluno para prever antes de rodar.

**Pegadinha do livro**
- O exemplo faz `#include <file1.c>`. Incluir `.c` é má prática; mostre o jeito certo com `.h` e compilação separada.

---

### 0036-pilha-de-chamadas

**Conceitos-chave** (seção 3.4, muito boa)
- Uma chamada de função faz três coisas: passa argumentos (cópias), aloca locais e temporárias, e transfere o controle **depois de guardar o endereço de retorno**.
- O retorno: recupera o endereço de retorno, libera a área de dados e desvia para lá; o valor de retorno vai para um lugar seguro (geralmente um registrador).
- Os endereços de retorno de `main → b → c → d` formam uma **pilha**: o último a entrar é o primeiro a sair.
- Na recursão, cada **chamada** (e não cada função) ganha a sua própria área de dados (frame). Só a do topo é visível.
- Temporárias também ocupam espaço: em `x = a*f(b) + c*f(d)` o valor de `a*f(b)` precisa sobreviver à chamada `f(d)`.

**Analogia/figura boa**
- Desenhar "pilhas de n, x, y" para `fact(4)` com asterisco para valor não inicializado, quadro a quadro: (a) vazia, (b) fact(4), (c) fact(3) ... (g) y = fact(0) ... (k) printf.

**Ideia de exercício**
- Desenhar os frames de `fib(6)` até o ponto em que `fib(5)` chama `fib(3)` e completar o resto.

---

### 0037-recursao

**Conceitos-chave**
- Uma definição recursiva define um objeto em termos de um caso **mais simples** dele mesmo. `n! = 1` se `n == 0`; `n! = n * (n−1)!` se `n > 0`. Não é circular, é um jeito compacto de escrever infinitas equações (0!, 1! = 1·0!, 2! = 2·1!, ...).
- Ingredientes: (1) caso trivial resolvido sem recursão; (2) um jeito de reduzir o caso complexo a um mais simples; (3) a redução **tem que chegar** no caso trivial.
- Multiplicação por soma: `a*b = a` se `b == 1`; `a*b = a*(b−1) + a`.
- Recursão indireta ("cadeia recursiva"): `a` chama `b`, que chama `a`.

**Analogias/explicações boas**
- "Suponha que a função já está escrita e use-a na própria definição; só garanta que as chamadas terminem."
- Definições **válidas mas inúteis**: `n! = (n+1)!/(n+1)` e `a*b = a*(b+1) − a` são identidades verdadeiras, mas nunca alcançam um caso base. Ótimo para mostrar que verdade matemática não basta.

**Pegadinhas**
- `fact(-1)` sem teste de entrada desce para sempre (−2, −3, ...) até estourar a pilha, sem mensagem útil. O livro acrescenta a verificação `n < 0`.
- O .md traz `if (n <= 1); return (n);` no `fib`: o `;` solto após o `if` faz a função sempre retornar `n`. Excelente "ache o bug".
- A versão compacta `return n == 0 ? 1 : n * fact(n-1);` ainda cria temporárias em cada frame.

**Ideias de exercícios**
- Escrever recursivamente: máximo, mínimo, soma, produto e média de um vetor.
- `a + b` só com `succ(x)`.
- O que `func(n) = n + func(n−1)`, com `func(0) = 0`, calcula? (soma 1..n). Fazer a versão iterativa.
- Contar sequências de n bits sem dois 1s seguidos (resposta: Fibonacci deslocado, f(n) = f(n−1) + f(n−2)).
- Comissões: `comm(n,k) = comm(n−1,k) + comm(n−1,k−1)` (triângulo de Pascal).

---

### 0038-recursao-na-pratica

**Conceitos-chave**
- **Fibonacci**: a definição chama a si mesma duas vezes e recalcula muito (em `fib(6)`, `fib(3)` é calculado 3 vezes). A versão iterativa com `lofib`/`hifib` é muito mais barata. Em fatorial e multiplicação o número de operações é o mesmo nas duas versões; em Fibonacci não.
- **Hanói** (n discos de A para C usando B): 1. se n == 1, mova o disco e pare; 2. mova n−1 de A para B usando C; 3. mova o maior de A para C; 4. mova n−1 de B para C usando A. O número de movimentos é 2^n − 1.
- Por que `towers` precisa de `frompeg`, `topeg`, `auxpeg`: nas chamadas recursivas os papéis das estacas trocam. Mesmo motivo dos parâmetros `low` e `high` na busca binária.
- **Euclides** para simplificar frações: troque (a, b) por (b, a % b) até b == 0.
- **Prefixa → posfixa recursiva**: se for uma letra, ela mesma; senão, o operador, o 1º operando convertido, o 2º operando convertido, e o operador no fim. A função `find` acha o tamanho da maior expressão prefixa no início da string (e prova que ela é única).
- Reconhecedor recursivo de expressões (expr → termo [+ termo]; termo → fator [* fator]; fator → letra | (expr)): três funções mutuamente recursivas. Ótimo exemplo de recursão indireta.

**Explicações boas**
- Projetar entrada e saída faz parte da solução: numerar os discos 1..n com o menor = 1 simplifica o programa. "A conveniência de programação pode decidir a representação."
- Recursão não é sempre lenta: quando não há trabalho repetido e a pilha não pode ser eliminada (Hanói, percurso de árvore), a versão recursiva pode ser tão rápida quanto a iterativa ou mais.

**Ideias de exemplos**
- Saída de Hanói para n = 4 (15 movimentos), começando com "disco 1 de A para B", "disco 2 de A para C", "disco 1 de B para C", ...
- Euclides em 1032/1976: restos 944, 88, 64, 24, 16, 8, 0 → MDC 8 → 129/247.
- Prefixa ↔ posfixa: `+A*BC` ↔ `ABC*+`; `*A+BC` ↔ `ABC+*`; `+*ABC` ↔ `AB*C+`.

**Ideias de exercícios**
- MDC recursivo pela definição do livro e versão iterativa.
- Ackermann: mostrar que a(2,2) = 7 e discutir por que não há laço simples.
- Contar quantas somas são feitas em `fib(n)` para n = 0..10 nas duas versões e observar o padrão.
- Oito rainhas com *backtracking* (função `try(n)` que coloca uma rainha na fileira n, testa, chama `try(n+1)` e desfaz) e labirinto 10×10 de 0s e 1s.
- Determinante por cofatores (recursão sobre a "menor" da matriz).
- Subvetor contíguo de soma máxima dividindo o vetor em metades.

---

### 0042-vetores

**Conceitos-chave**
- Vetor (abstrato) é um conjunto **finito, ordenado e homogêneo**. Duas operações: extrair (`a[i]`) e armazenar (`a[i] = x`). Antes de armazenar, o valor é indefinido.
- Limite mínimo (sempre 0 em C), limite máximo e faixa = máx − mín + 1. Os limites não mudam durante a execução.
- Implementação: `endereço(b[i]) = base(b) + i * esize`. Em C, `b[i]` é `*(b + i)`.
- Vetor de elementos de tamanho variável: guardar **endereços** num vetor contíguo (um acesso indireto a mais) ou guardar a parte fixa (ex.: o tamanho) junto ao endereço, como "cabeçalho".

**Pegadinhas**
- "Vetor é ponteiro" é simplificação do livro: `int b[100]` reserva 100 inteiros; `int *b` não reserva nada. Hoje dizemos que o nome do vetor *decai* para ponteiro na maioria dos usos.
- C não confere limites: `s.items[-1]` ou `s.items[100]` dão comportamento indefinido silencioso.

**Ideia de exemplo**
- Média e desvios de 100 números (corrigido) e vendas por ano via índice direto.

---

### 0043-vetores-e-funcoes

**Conceitos-chave**
- O parâmetro vetor não aloca memória nova: refere-se ao vetor original. Por isso a faixa precisa ser passada separadamente (`avg(a, size)`) e alterações na função valem no chamador.
- Vantagem: não copia o vetor (tempo e espaço).
- Tabelas grandes únicas às vezes viram globais para evitar passar parâmetros (o livro defende; hoje é discutível).

**Ideia de exercício**
- `float media(float a[], int n)`; depois mostrar `b[i] = x` dentro da função mudando `a[i]`.

---

### 0044-matrizes

**Conceitos-chave**
- Matriz é uma visão **lógica**; a memória é **linear**. Armazenamento por linha (row-major): `endereço(ar[i1][i2]) = base + (i1*r2 + i2) * esize`.
- Generalização para n dimensões (regra de Horner): `offset = 0; para j: offset = r[j]*offset + i[j];`.
- O último índice varia mais rápido, como um **odômetro** de carro.
- Alternativa: vetor de ponteiros para linhas (mais simples de pensar, mas gasta o vetor de ponteiros e um acesso extra).
- Número de elementos = produto das faixas (`int b[3][2][4]` tem 24).

**Analogia boa**
- O odômetro, para a ordem dos elementos de uma matriz multidimensional na memória.

**Ideias de exercícios**
- Endereços com `esize` 4 e base 100 (adaptado do 1.2.6): `int a[100]`, `a[10]` → 140; `int a[200]`, `a[100]` → 500; `int a[10][20]`: `a[0][0]` → 100, `a[2][1]` → 264, `a[5][1]` → 504, `a[1][10]` → 220, `a[2][10]` → 300, `a[5][3]` → 512, `a[9][19]` → 896.
- Matriz triangular inferior guardada num vetor de n(n+1)/2 posições: fórmula de acesso `i*(i+1)/2 + j` para i ≥ j. Variações: estritamente triangular e tridiagonal.
- Tabela de vendas 20 filiais × 10 itens com totais por linha e por coluna.
- Imprimir uma matriz grande em páginas de 50 linhas × 20 colunas.

---

### 0046-strings

**Conceitos-chave**
- Duas representações de string de tamanho variável: (a) **prefixada pelo tamanho** (1º byte = comprimento, máximo 255 caracteres); (b) **terminada em `'\0'`** (a de C): sem limite, mas descobrir o tamanho exige percorrer.
- Implementações à mão de `strlen`, `strpos` (busca de substring), `strcat` e `substr`.

**Explicação boa**
- Comparar as duas versões de MOVEVAR/CONCATVAR: a de tamanho prefixado sabe quanto copiar; a de C copia até achar `'\0'`. Bom para mostrar que uma escolha de representação muda todas as operações.

**Pegadinhas**
- Concatenar strings prefixadas cuja soma passa de 255: o resultado é indefinido e quem implementa decide (truncar, recusar, avisar).
- `strpos` do livro tem condição de laço confusa (`j2 <= len2`); bom exercício de revisão.

**Ideias de exercícios**
- Escrever `meu_strpos` (−1 se não achar) e testar com "abcde"/"cd" → 2.
- Implementar string como lista de caracteres com nó de cabeçalho guardando o tamanho.

---

### 0049-memoria, 0050-ponteiros, 0052-ponteiros-e-vetores

**Conceitos-chave**
- `&x` é o endereço (ponteiro) de x; `*pi` é o objeto apontado. Todo ponteiro tem um **tipo base**: `int *` e `float *` são tipos diferentes.
- Aritmética depende do tipo base: com `int` de 4 bytes e `pi == 100`, `pi+1 == 104` e `pi-1 == 96`; com `char *pc == 100`, `pc+1 == 101`.
- `*pi + 1` (soma 1 ao valor) é diferente de `*(pi + 1)` (o próximo inteiro).

**Ideia de exercício**
- Tabela com endereços para `pi`, `pi+1`, `pi+2`, `pc+1` partindo de 100.

---

### 0059-malloc-free e 0062-erros-de-memoria

**Conceitos-chave**
- `malloc(sizeof(T))` cria uma variável dinâmica sem nome; só se chega a ela por ponteiro.
- Dois ponteiros com o mesmo valor apontam para o **mesmo** objeto: atribuir a `*p` muda `*q`.
- Chamar `malloc` duas vezes guardando no mesmo ponteiro perde o primeiro bloco (vazamento), e ele não pode nem ser liberado.
- Depois de `free(p)`, `p` continua com o endereço antigo: é um **ponteiro perdido** (*dangling*). O livro recomenda `p = NULL` logo após o `free`.

**Ideias de exemplos (traços curtos e ótimos)**
- `p = malloc; *p = 3; q = p; printf(*p,*q)` → 3 3; `*q = 7` → 7 7; `p = malloc; *p = 5` → 5 7.
- `p=malloc;*p=5; q=malloc;*q=8; free(p); p=q; q=malloc;*q=6;` → imprime 8 6.

**Pegadinhas**
- `evaltree` do livro faz `return(p->val); free(p);`: o `free` nunca roda (código morto).
- Código antigo faz cast do retorno de `malloc` e declara `extern char *malloc()`; hoje se inclui `<stdlib.h>` e não precisa de cast em C.

---

### 0064-struct, 0065-typedef, 0066-vetor-de-structs, 0067-ponteiro-para-struct

**Conceitos-chave**
- Struct = itens heterogêneos com nomes (membros); acesso com `.`; structs aninhadas (`nmad1.name.midinit`).
- Três formas de declarar: struct anônima com variáveis; struct com rótulo (`struct nametype`); `typedef`. O livro recomenda sempre dar nome.
- Mesmo nome de membro em structs diferentes não gera ambiguidade.
- Implementação: cada membro tem um **deslocamento** fixo; endereço do membro = base + deslocamento. Vetor e struct usam a mesma ideia (base + deslocamento); no vetor o deslocamento vem do índice, na struct vem do nome.
- **Alinhamento**: membros podem precisar começar em endereço múltiplo do tamanho, criando bytes desperdiçados (*padding*).
- `p->x` equivale a `(*p).x`.
- Ligar tabelas por índice (`s[e[i].sindex].credits`) em vez de comparar nomes.

**Ideias de exemplos**
- Struct {int 4; float 8; char[10]} = 22 bytes sem alinhamento e 26 com alinhamento (a partir do endereço 200, o float começa em 208).
- `rr[14].field3[6]` com base 400: 400 + 14·22 + 12 + 6 = 726; com elementos de 24 bytes, 754. (Ótimo para mostrar `sizeof` maior que a soma dos membros. Refazer com tamanhos atuais.)
- Aumento de 10% para funcionários com mais de 10 anos, 5% para os outros (vetor de structs).

**Pegadinhas**
- **Bug real do livro:** compara nomes com `e.nameaddr.name.first == s.nmad.name.first`. Em C isso compara **endereços** de vetores de char, não o conteúdo; tem que usar `strcmp`. O próprio livro avisa que structs não se comparam com `==`, mas erra nos campos string.
- O livro diz que structs não podem ser atribuídas nem passadas por valor (verdade só no C de K&R). Hoje podem; passar ponteiro continua mais barato para structs grandes.

**Ideias de exercícios**
- Endereços em `struct person p[100]` (com nametype de 31 bytes, int 4) a partir de 100: `p[10]`, `p[20].income`, `p[5].parents[1].last[10]`.
- Dar aumento a funcionários que têm registro de estudante com média > 3.0, com os dois vetores ordenados por nome (algoritmo de intercalação).
- Número racional como struct: somar, subtrair, multiplicar, dividir, sempre reduzindo.
- Comparar `equal` por redução contra `equal2` por produto cruzado (o produto pode estourar `int`).

---

### 0069-union

**Conceitos-chave**
- Union = vários "mapas" para a mesma área de memória; o tamanho é o do maior membro.
- Só um membro é válido por vez; quem controla é o programador. Boa prática: um campo **etiqueta** fixo (`kind`, `utype`, `etype`) dizendo qual alternativa está em uso.
- Usos no livro: apólices de seguro (vida/auto/residência), pilha heterogênea, nós de árvore com operador ou operando.

**Exemplo bom**
- `struct policy` com parte fixa (número, nome, endereço, valor, prêmio, `kind`) e parte variável em union. Aumentar 5% o prêmio de seguros de vida e de casas construídas antes de 1950.

**Pegadinha**
- C não impede ler o membro errado; o resultado é lixo reinterpretado.

---

### 0076-eficiencia (e 0077-big-o, de leve)

**Conceitos-chave**
- Eficiência tem duas faces, tempo e espaço, e quase sempre há troca entre elas.
- Custo médio de inserir numa lista ordenada (inserção aleatória, n+1 posições equiprováveis): cerca de (n+2)/2, ou seja ≈ n/2 nós acessados.
- Fila de prioridade em lista ordenada: inserir ≈ n/2, remover 1. Em lista desordenada: inserir 1, remover n.
- Lista representada como árvore: achar o k-ésimo elemento em ≤ log2 n + 1 visitas, contra k na lista ligada (1000 elementos → no máximo 11 nós).
- Árvore binária completa de profundidade d tem 2^(d+1) − 1 nós; d = log2(n+1) − 1.

**Ideia de exercício**
- Contar nós acessados ao buscar numa lista desordenada, ordenada, vetor desordenado e vetor ordenado (busca binária).

---

### 0079-tad

**Conceitos-chave**
- TDA = conjunto de valores + operações, definido sem pensar em eficiência. Duas partes: **definição de valor** (com cláusula de condição) e **definição de operadores** (cabeçalho, pré-condição opcional, pós-condição).
- TDA RACIONAL: denominador ≠ 0; igualdade definida por produto cruzado (1/2 == 2/4 mesmo com componentes diferentes). A especificação diz **o que** resulta, não **como** calcular.
- TDA de pilha e de fila definidos com notação de sequências (`first`, `sub`, `len`, `+`).
- **Modularização**: escrever `empty(&s)` em vez de `s.top == -1`; se a implementação mudar, só a função muda.

**Explicação boa**
- O "computador virtual": hardware + rotinas que implementam tipos novos formam uma máquina "melhor", e quem a usa não precisa saber dos detalhes.
- Clareza x truque: `return (ps->top == -1);` é equivalente ao `if/else`, mas o livro prefere o legível. Bom gancho para discutir estilo.

**Ideias de exercícios**
- Especificar um TDA de número complexo (soma, produto, negação, módulo) e depois implementá-lo com struct.
- Especificar o TDA fila de prioridade.

---

### 0081-lista-encadeada

**Conceitos-chave**
- Nó = `info` + `next`; ponteiro externo `list` para o primeiro; `NULL` no último; lista vazia é `list == NULL`.
- Notação algorítmica `node(p)`, `info(p)`, `next(p)` antes do C. Bom para pseudocódigo.
- Inserir no início: `p = getnode(); info(p) = x; next(p) = list; list = p;` (funciona com lista vazia).
- Remover do início: `p = list; list = next(p); x = info(p); freenode(p);`.
- `getnode`/`freenode`: no mundo ideal haveria nós infinitos; no real, uma **lista livre** (pilha de nós disponíveis) com `avail`. Esgotou → estouro.
- Implementação em **vetor de nós** (índices como ponteiros, −1 como nulo) contra **dinâmica** (`malloc`). A dinâmica não reserva espaço antes e acessa `*p` sem somar base.

**Analogias/figuras boas**
- Sequência de 6 figuras (a)–(f) mostrando cada atribuição na inserção do 6 em 5→3→8.
- Figura do vetor `node` com 4 listas embaralhadas no mesmo vetor (list1 começa em 16, list2 em 4...). Ótimo para mostrar que a ordem está nos ponteiros e não na posição.

**Pegadinhas**
- Usar `p` depois de `freenode(p)`.
- Esquecer de atualizar o ponteiro externo (precisa passar `NODEPTR *plist`, ponteiro para ponteiro).

**Ideias de exercícios**
- Lista de operações (do 4.2.3): inserir no fim, concatenar, liberar tudo, inverter, remover o último, remover o n-ésimo, intercalar duas ordenadas, união, interseção, contar, somar, copiar, remover um a cada dois.

---

### 0082-lista-busca-remocao

**Conceitos-chave**
- Não se insere **antes** de um nó nem se remove um nó dado só o ponteiro para ele: falta o predecessor. Daí `insafter(p,x)` e `delafter(p,&x)`.
- Truques: inserir antes = inserir depois e trocar os `info`; remover o próprio nó = copiar o sucessor e remover o sucessor (não serve para o último).
- **Dois ponteiros em fila** (`q` atrás de `p`) para remover todas as ocorrências de um valor.
- `search(list, x)` devolve ponteiro ou `NULL`.

**Ideia de exemplo**
- Remover todos os 4 de 4→7→4→4→9: passo a passo, mostrando o caso especial do primeiro nó.

---

### 0083-lista-ordenada

**Conceitos-chave**
- `place(&list, x)`: avança enquanto `x > p->info` guardando o anterior; se não há anterior, insere no início (`push`); senão `insafter(q, x)`.
- Custo médio ≈ n/2 (ver 0076).

---

### 0084-lista-dupla

**Conceitos-chave**
- Nó com `left` e `right`; propriedade `left(right(p)) == p == right(left(p))` (lista circular).
- Permite remover o próprio nó (`delete(p)`) e andar nos dois sentidos.
- `insertright(p, x)` religa quatro ponteiros.
- Truque de espaço: guardar só a soma (ou o XOR) dos endereços vizinhos num campo; com dois nós adjacentes conhecidos, recupera-se o outro vizinho. (Avançado; XOR é a forma comum.)

**Ideia de exemplo forte**
- Inteiros longos com sinal em lista circular duplamente ligada com cabeçalho: o cabeçalho guarda a contagem de nós com o sinal do número; comparar valores absolutos exige andar do mais significativo para o menos significativo (sentido inverso ao da soma), por isso a lista dupla. Remover zeros à esquerda depois da subtração.

---

### 0085-lista-circular

**Conceitos-chave**
- Último nó aponta para o primeiro. Convenção: o ponteiro externo aponta para o **último** nó; o primeiro é `next(list)`. Assim inserir no início e no fim custa O(1).
- Fila com um único ponteiro: inserir no fim = inserir no início e avançar o ponteiro.
- Concatenar duas listas circulares sem percorrer: troca de dois ponteiros.
- Liberar uma lista circular inteira de uma vez quando se gerencia a própria lista livre.
- Nó de cabeçalho com valor especial marca o fim do percurso.

**Exemplo clássico: Josephus**
- n = 3, soldados A B C D E, começando em A: saem C, A, E, B; **D escapa**.
- Variação (cada eliminado dita o próximo passo): A..E escolhem 3, 4, 6, 2, 7; passo inicial 2 → saem B, A, E, C; sobra D.

**Exemplo: inteiro positivo longo em lista circular com cabeçalho**
- Cinco dígitos por nó, do menos para o mais significativo; cabeçalho com `info = -1`. 459763497210698463 → nós 98463, 72106, 76349, 459. Soma com `% 100000` e vai-um `/ 100000`.

**Pegadinha**
- O `push` circular do livro tem `else` sem chaves: a última linha roda sempre. Funciona por acaso (no caso vazio faz `p->next = p`), mas é armadilha de leitura; peça para reescrever com chaves.

**Ideias de exercícios**
- Josephus com vetor e comparar com a lista circular.
- Imprimir o 100º número de Fibonacci com inteiros longos em lista.
- Polinômio em x, y, z como lista circular: somar, multiplicar, derivar, avaliar.

---

### 0087-pilha

**Conceitos-chave**
- Pilha = conjunto ordenado com inserção e remoção numa só ponta (topo); LIFO. `push`, `pop`, `empty`, `stacktop` (que é um `pop` seguido de `push`).
- A pilha **não tem memória do passado**: estados (a) e (i) da sequência de figuras são indistinguíveis.
- Vetor **não é** pilha: é "a casa" da pilha. `struct stack { int top; int items[STACKSIZE]; }`, vazia com `top == -1`.
- `pop` não apaga `items[top]`; só decrementa `top`. O valor antigo continua lá, mas não faz mais parte da pilha.
- **Underflow** (pop em pilha vazia) é erro lógico do algoritmo, e nenhuma implementação corrige. **Overflow** só existe por causa do vetor finito; às vezes aumentar `STACKSIZE` resolve, mas muitas vezes indica laço infinito empilhando.
- Variantes que não abortam: `popandtest(&s, &x, &und)` e `pushandtest`.
- Pilha heterogênea com union e etiqueta.

**Explicação boa**
- Filme de quadros (a)–(o) com push G, H, I, J, quatro pops etc. Reproduzir como animação.

**Ideias de exercícios**
- Com só push/pop/empty/stacktop: pegar o 2º do topo (removendo ou não), o n-ésimo, o do fundo (com pilha auxiliar).
- Duas pilhas num vetor crescendo uma em direção à outra (`push1`, `push2`...).
- Pilha com `s[0]` guardando o topo.
- Estacionamento de uma alameda com uma única entrada/saída (pilha de 10 carros); contar quantas vezes cada carro foi manobrado.
- Critério para uma sequência de push/pop não dar underflow (nunca mais pops que pushes em nenhum prefixo).

---

### 0088-pilha-encadeada

**Conceitos-chave**
- Topo = primeiro nó; push = inserir no início; pop = remover do início. Overflow só quando `getnode` falha.
- Vantagem: todas as pilhas e filas do programa compartilham o mesmo estoque de nós.
- Custo: um ponteiro por elemento (pouco, se o elemento for grande) e o trabalho de pegar e devolver nós.
- Versão como lista circular (ponteiro no último nó).

---

### 0089-pilha-aplicacoes

**Conceitos-chave**
- **Parênteses**: com um só tipo basta um contador (nunca negativo, termina em 0). Com `()[]{}` é preciso **pilha**, porque o fechamento tem que casar com o tipo da última abertura.
- **Notações**: infixa `A+B`, prefixa `+AB`, posfixa `AB+`. Posfixa e prefixa dispensam parênteses; a ordem dos operadores já é a ordem de execução. A prefixa não é o espelho da posfixa (`A+B-C` → `-+ABC` e `AB+C-`).
- Precedência do livro: `$` (potência) > `* /` > `+ -`; mesma precedência associa à esquerda, exceto `$`, que associa à direita (`A$B$C = A$(B$C)`).
- **Avaliação posfixa**: operando → empilha; operador → desempilha `opnd2` **primeiro** e depois `opnd1`, calcula, empilha o resultado.
- **Infixa → posfixa** com pilha de operadores e função `prcd(topo, símbolo)`; parênteses tratados por convenções de `prcd` (abre-parêntese sempre empilha; fecha-parêntese desempilha até o abre e descarta os dois).
- Invariante útil: na pilha de operadores, cada operador tem precedência menor que os de cima.

**Explicação boa**
- Por que converter é mais difícil que avaliar: a conversão vai de uma ordem de precedência para a ordem natural de execução, enquanto a avaliação já recebe tudo na ordem certa. A pilha "lembra" os operadores em vez de voltar atrás na string.

**Pegadinhas**
- Inverter `opnd1` e `opnd2` (dá erro em `-`, `/` e `$`).
- O programa do livro só aceita operandos de **um dígito**: `12` vira dois operandos; um sinal de menos para negativo vira operador. Sobra na pilha no fim = expressão inválida não detectada.
- Converter de dígito para número: `c - '0'`.

**Ideias de exemplos (com valores)**
- Avaliar `6 2 3 + - 3 8 2 / + * 2 $ 3 +` → **52** (tabela symb/opnd1/opnd2/value/pilha; pilha nunca passa de 4 elementos embora haja 8 operandos).
- Com A=3, B=4, C=5: `ABC*+` = 23 e `AB+C*` = 35.
- Traço de conversão de `A+B*C` → `ABC*+`, `(A+B)*C` → `AB+C*` e `((A-(B+C))*D)$(E+F)` → `ABC+-D*EF+$`.
- Tabela de conversões do livro: `(A+B)*(C-D)` → `AB+CD-*`; `A$B*C-D+E/F/(G+H)` → `AB$C*D-EF/GH+/+`; `A-B/(C*D$E)` → `ABCDE$*/-`.

**Ideias de exercícios (com respostas)**
- Simular o verificador em `(A+B})`, `{[A+B]-[(C-D)]`, `(A+B)-{C+D}-[F+G]`, `((H)*{([J+K])})`, `(((A))))` (só a 3ª e a 4ª são válidas).
- `A+B-C` → pré `-+ABC`, pós `AB+C-`.
- `(A+B)*(C-D)$E*F` → pós `AB+CD-E$*F*`, pré `**+AB$-CDEF`.
- `(A+B)*(C$(D-E)+F)-G` → pós `AB+CDE-$F+*G-`, pré `-*+AB+$C-DEFG`.
- Com A=1, B=2, C=3: `AB+C-BA+C$-` = −27; `ABC+*CBA-+*` = 20.
- Reconhecer strings `xCy` com y = reverso de x (pilha), e sequências delas separadas por `D`.
- Posfixa → infixa totalmente parentetizada (`AB+C-` → `((A+B)-C)`).
- Gerar código para máquina de um registrador (LD/ST/AD/SB/ML/DV) a partir da posfixa.

---

### 0090-fila

**Conceitos-chave**
- Fila: remove numa ponta (início), insere na outra (final); FIFO.
- Vetor com `front`/`rear` "andando" esgota o vetor mesmo com a fila vazia (situação absurda).
- Deslocar tudo a cada remoção resolve, mas custa O(n).
- **Fila circular**: `front` aponta para a posição **anterior** ao primeiro; vazia quando `front == rear`; inicialização `front = rear = MAXQUEUE-1`.
- Cheia e vazia ficariam iguais (`front == rear`); solução do livro: **sacrificar uma posição** (capacidade MAX−1). Alternativa (exercício): um campo `qempty` ou um contador.
- Na inserção o teste de estouro vem **depois** de avançar `rear`; na remoção o de underflow vem **antes** de avançar `front`.

**Pegadinha de tradução**
- O .md diz que `insert` coloca no "início" e `remove` tira o "último": está **invertido** em relação à definição dada uma linha antes. Avisar o aluno ou não usar esse parágrafo.

**Ideias de exercícios**
- Sequência de inserções/remoções que faz a fila linear "estourar" estando vazia.
- Adiar o deslocamento até `rear` chegar ao fim do vetor: vantagens e desvantagens.
- Fila com `queue[0]` = início, `queue[1]` = final e o resto para os itens.
- Fila de pilhas, pilha de filas, fila de filas.
- Estacionamento com entrada ao sul e saída ao norte (com fila de espera).

---

### 0091-fila-encadeada

**Conceitos-chave**
- Ponteiros `front` e `rear`; inserir no fim, remover do início.
- Ao remover o último elemento, **zerar também `rear`**.
- Com nó de cabeçalho cujo `info` aponta para o último, basta um ponteiro externo.
- Lado a lado, as versões em vetor de nós e dinâmica do `insert`/`remove` (só muda a referência aos campos).

---

### 0092-deque

**Conceitos-chave** (só em exercícios)
- Deque: insere e remove nas duas pontas (`insrtleft`, `insrtright`, `remvleft`, `remvright`).
- Deque de entrada restrita e de saída restrita; mostrar como cada um imita pilha e fila.

---

### 0095-busca-binaria

**Conceitos-chave**
- Analogia da lista telefônica: abrir no meio e descartar metade.
- Recursiva: `low > high` → −1; `mid = (low+high)/2`; igual → mid; menor → metade inferior; maior → metade superior. Os limites viram parâmetros.
- Variante com `a` e `x` globais para não empilhar o que não muda (o livro defende; hoje preferimos passar parâmetros).

**Ideias de exemplos**
- Vetor 1, 3, 4, 5, 17, 18, 31, 33 procurando 17: mid 3 (5) → mid 5 (18) → mid 4 → acha no índice 4.
- Procurando 2: mid 3 → mid 1 → mid 0 → low 1 > high 0 → −1.

**Pegadinha**
- `(low+high)/2` pode estourar em vetores enormes; a forma segura é `low + (high-low)/2` (o livro não fala disso).

**Exercícios**
- Versão iterativa mexendo em `low`/`high`.
- Número máximo de chamadas para n elementos (≈ ⌊log2 n⌋ + 1).

---

### 0102-arvores

**Conceitos-chave**
- Árvore binária: vazia, ou raiz + subárvore esquerda + subárvore direita (disjuntas).
- Pai, filho esquerdo/direito, folha, ancestral, descendente (e descendente esquerdo/direito), irmãos. Raiz no topo, "descer" vai para as folhas.
- **Nível**: raiz = 0, filho = nível do pai + 1. **Profundidade** da árvore (para o livro) = maior nível de uma folha. Hoje se chama **altura**.
- **Estritamente binária**: todo nó interno tem dois filhos; com n folhas tem 2n−1 nós.
- **Completa** de profundidade d (no livro): estritamente binária com todas as folhas no nível d; tem 2^(d+1) − 1 nós e 2^d folhas. **Quase completa**: folhas nos níveis d e d−1 e preenchida "da esquerda". Numeração: raiz 1, filhos 2i e 2i+1.
- Árvore **geral**: não vazia, número qualquer de filhos; **grau** = número de filhos; **árvore ordenada** (filhos em ordem; mais velho e mais novo); **floresta** = sequência de árvores.
- Árvore binária não é caso particular de árvore geral com "no máximo 2 filhos": numa binária o filho único é esquerdo **ou** direito.

**Pegadinha central de terminologia**
- O próprio livro avisa: o que ele chama de "completa", outros livros chamam de cheia ou perfeita; o que ele chama de "quase completa", outros (e o uso atual) chamam de **completa**; e "estritamente binária" é chamada de "cheia" em outros textos. Defina no curso uma única convenção e alerte para as outras.

**Ideias de exercícios**
- Provar que a estritamente binária com n folhas tem 2n−1 nós.
- Quantos ancestrais tem um nó no nível n? (n).
- Profundidade da quase completa com tn nós = ⌊log2 tn⌋ (4–7 nós → 2; 8–15 → 3).
- Testar se uma árvore é estritamente binária, completa, quase completa.

---

### 0103-arvore-binaria

**Conceitos-chave**
- Operações: `info`, `left`, `right`, `father`, `brother`, `isleft`, `isright`; construção com `maketree`, `setleft`, `setright`.
- Representação **ligada** (vetor de nós com lista livre, ou nós dinâmicos) e **sequencial** implícita em vetor: com índice a partir de 0, filhos em `2p+1` e `2p+2`, pai em `(p-1)/2`, filho esquerdo se `p` é ímpar. Árvore não quase completa: estender até uma quase completa e marcar posições vazias (`used`).
- Sequencial economiza ponteiros, mas desperdiça muito se a árvore for torta: com entrada crescente numa BST, só as posições 0, 2, 6, 14, 30... são usadas (16 números em 500 posições).
- Nós internos e externos (folhas sem ponteiros) para economizar espaço.
- **Percursos** recursivos: pré-ordem (raiz, esq, dir), em ordem/simétrica (esq, raiz, dir), pós-ordem (esq, dir, raiz).
- Percurso em ordem **iterativo** com pilha explícita; o livro mostra que ele é **mais lento** que o recursivo (chamadas de push/pop, testes de estouro), contra a "sabedoria popular".
- **Árvores encadeadas à direita** (*threaded*; o livro chama o ponteiro de "linha"): o `right` nulo aponta para o sucessor em ordem; com o campo `rthread`, o percurso em ordem dispensa pilha.
- Percurso sem pilha usando campo `father`, e técnica de **inverter ponteiros** na descida e restaurar na subida (não serve se várias pessoas usam a árvore ao mesmo tempo).
- **Árvores de expressão**: pré-ordem → prefixa, pós-ordem → posfixa, em ordem → infixa **sem parênteses** (perde a precedência forçada).
- Árvore heterogênea (union operador/operando) e avaliação recursiva `evalbintree`.
- Árvore geral como binária (filho mais velho = `left`, próximo irmão = `right`), e floresta inteira numa binária.

**Ideias de exemplos**
- Árvore A(B(D(–,G)), C(E(H,I), F)): pré **ABDGCEHIF**, em **DGBAHEICF**, pós **GDBHIEFCA**.
- `A+(B-C)*D$(E*F)`: prefixa `+A*-BC$D*EF`, posfixa `ABC-DEF*$*+`.
- Árvore `3 + 4*(6-7)/5 + 3` com folhas numéricas e nós operadores.

**Pegadinhas**
- O livro chama a pré-ordem de "percurso em profundidade": impreciso, já que DFS pode ser pré, em ou pós-ordem. Corrigir na aula.
- **Bug clássico do livro:** o laço do `intrav2` termina com `while (!empty(s) && p != NULL)`; o certo é `||`. Com `&&`, uma raiz cuja subárvore esquerda já acabou e que só tem filho direito para o percurso no meio. Ótimo exercício de depuração.
- `setleft` em nó que já tem filho esquerdo é "inserção incorreta".

**Ideias de exercícios**
- Contar nós, somar conteúdos, calcular profundidade (recursivo e iterativo).
- Árvores semelhantes e semelhantes espelhadas; imagem espelhada de uma árvore.
- Reconstruir a árvore a partir de pré-ordem + em ordem (e discutir pré + pós).
- Infixa com só os parênteses necessários a partir da árvore de expressão.
- Hanói como árvore binária completa cujo percurso em ordem dá os movimentos.

---

### 0104-bst-busca-insercao

**Conceitos-chave**
- Aplicação de abertura do livro: achar números repetidos. Cada número desce comparando (menor → esquerda, maior → direita); se achar igual, é repetido; se cair num vazio, insere.
- Para **ordenar**, os repetidos também entram (maior **ou igual** → direita); percurso em ordem imprime em ordem crescente (*tree sort*).

**Ideias de exemplos**
- Entrada 14 15 4 9 7 18 3 5 16 4 20 17 9 14 5: repetidos detectados 4, 9, 14 e 5. Desenhar a árvore (raiz 14; 4 e 15; 3, 9, 18; 7, 16, 20; 5, 17).
- Mesma entrada aceitando repetidos: em ordem dá 3 4 4 5 5 7 9 9 14 14 15 16 17 18 20.

**Ideias de exercícios**
- Experimento: inserir 100 aleatórios, medir diferença entre folha mais funda e mais rasa, repetir 50 vezes e tabelar.
- Fila de prioridade ascendente sobre BST (`pqinsert`, `pqmindelete`) e observar que remoções ficam mais baratas e inserções mais caras com o tempo (a árvore "pende" para a direita).

---

### 0107-heap (só a parte de fila de prioridade)

**Conceitos-chave**
- Fila de prioridade **ascendente** (remove o menor) e **descendente** (remove o maior). Pilha e fila são casos particulares, com o tempo de inserção como prioridade.
- Implementações em vetor, todas insatisfatórias: marcar posições vazias e compactar de vez em quando; inserir na primeira vaga; compactar a cada remoção; vetor ordenado circular (transfere o custo para a inserção, que pode usar busca binária).
- Em lista ordenada: inserir ≈ n/2, remover 1. O heap fica para o cap. 6 (outra parte).

**Ideia de exercício**
- Ordenar números usando só `pqinsert`/`pqmindelete` (ponte para o heapsort).

---

## Obsoleto / evitar

- **Sintaxe K&R**: `f(a, b) int a, b; { ... }`, funções sem tipo de retorno (int implícito), `extern char *malloc();`, cast do retorno de `malloc`, `free((char *) p)`, `#define NULL 0`, `#define TRUE 1`. Usar protótipos, `<stdlib.h>`, `<stdbool.h>`.
- **Structs nunca passadas por valor nem atribuídas**: restrição do C antigo. Hoje é permitido; passar ponteiro continua sendo o normal para structs grandes.
- `register`, `goto` nas simulações (bom como passo intermediário didático, não como estilo final), `exit(1)` dentro de rotinas de biblioteca (melhor devolver código de erro), `isdigit` reescrita à mão (existe em `<ctype.h>`), `#include <file1.c>`.
- Leitura com `while ((expr[pos++] = getchar()) != '\n');` sem limite de tamanho (estouro de buffer) e `scanf("%s", &symb)` com `symb` sendo um `char` (estouro garantido).
- Globais como otimização (passar `a` e `x` como globais na busca binária, tabelas globais).
- Modelo de ponto flutuante didático (mantissa de 24 bits, base 10): não é o IEEE 754.
- Tamanhos supostos (`float` de 8 bytes) nos exemplos de deslocamento.
- **Bugs a não copiar** (bons para exercícios de "ache o erro"):
  - comparação de strings com `==` em structs (`e.nameaddr.name.first == s.nmad.name.first`);
  - `avg = total / NUMELTS` com inteiros e `printf("%d", float)`;
  - `if (n <= 1);` no `fib` (pode ser OCR, mas é um erro clássico);
  - `intrav2` com `&&` no lugar de `||`;
  - Huffman em C: `p = 1;` no lugar de `p = i;` e `node[i].isleft` no lugar de `node[p].isleft` ao subir a árvore; `nodes[i]` no lugar de `node[i]`;
  - `evaltree`: `return` antes de `free` (código morto);
  - `follower` (Josephus em árvore) usa `k` em vez de `*pk`;
  - `remove` da fila e textos com início/final trocados na tradução;
  - `push(&s, &currarea.x)` na simulação do fatorial (deveria empilhar a área inteira).
- O .md tem muito ruído de OCR (`1=` por `!=`, `—` por `--`, `l` por `1`, `prdc` por `prcd`); qualquer código tirado dele precisa ser reescrito e compilado.

## Extras que não cabem no sumário (candidatos a assuntos bônus)

### Simulação e eliminação da recursão (seção 3.4) — bônus muito bom
Mostra **como o compilador implementa a recursão** e como transformá-la em iteração:
1. Defina uma `struct dataarea` com parâmetros, locais e **endereço de retorno** (codificado como inteiro 1, 2, 3...), e uma pilha dessas áreas.
2. "Chamar" = empilhar a área atual, preencher os novos parâmetros, marcar o endereço de retorno e `goto start`. "Retornar" = guardar o resultado, ler o endereço de retorno, desempilhar e usar um `switch` de `goto`s para o rótulo certo.
3. Enxugar: só empilhar variáveis cujo valor é **reusado depois** da chamada (no fatorial, só `n`; `x` e `y` não). O retorno ao chamador externo pode ser detectado por **underflow** (`popandtest`), eliminando um rótulo; com um único rótulo restante, o endereço de retorno nem precisa ir para a pilha.
4. Juntar variáveis que nunca convivem, trocar `goto` por dois `while` (um que desce empilhando, outro que sobe multiplicando) e perceber que a pilha é desnecessária: chega-se ao fatorial iterativo comum.
5. Em Hanói, a 2ª chamada é a **última instrução** (recursão de cauda): não precisa salvar nada, basta trocar os parâmetros e voltar ao início. Resultado: um `while(TRUE)` com uma pilha só para a 1ª chamada.
Lições finais (3.5): recursão custa empilhar coisas que o compilador não sabe que são
descartáveis; porém push/pop explícitos com testes de estouro podem custar **mais** que a
recursão nativa. Estratégia recomendada: escreva recursivo, simule, depois elimine o supérfluo.
Exercícios: simular `binsrch` e `fib`; esquema geral de recursão de cauda
`rec(n){ if(!f(n)){ S; rec(g(n)); } }` → `while(!f(n)){ S; n = g(n); }`; e a versão com duas
chamadas virando pilha de `h(n)`.

### Algoritmo de Huffman (seção 5.3)
- Código de tamanho variável **livre de prefixo**: nenhum código é prefixo de outro, senão a decodificação da esquerda para a direita fica ambígua.
- Exemplo: `ABACCDA`. Código fixo de 3 bits → 21 bits; de 2 bits → 14 bits; Huffman (A=0, C=10, B=110, D=111) → **13 bits** (`0110010101110`).
- Construção: junte repetidamente os dois símbolos de **menor frequência** num novo nó com a soma das frequências (B1 + D1 → BD2; C2 + BD2 → CBD4; A3 + CBD4 → ACBD7). Fila de prioridade ascendente de raízes parciais.
- Código de cada símbolo: subir da folha à raiz, acrescentando 0 (veio da esquerda) ou 1 (da direita) **à esquerda** do código. Decodificação: descer da raiz, 0 = esquerda, 1 = direita, até uma folha.
- Árvore de Huffman é estritamente binária: n símbolos → 2n−1 nós, cabe num vetor; folhas em `node[0..n-1]`, internos em `node[n..2n-2]`; o campo `father` das raízes serve para encadear a fila de prioridade.
- Exemplo maior da figura (9 símbolos, frequências A15 B6 C7 D12 E25 F4 G6 H1 I15): E=10, I=00, A=111, D=011 etc.
- Exercícios: `encode`, `decode`, duas árvores de Huffman diferentes para as mesmas frequências (empates), comprimento ponderado do caminho mínimo, árvore de Fibonacci.

### Árvores de jogos e minimax (seção 5.6)
- Função de avaliação **estática** (jogo da velha: linhas, colunas e diagonais ainda abertas para mim menos as abertas para o adversário; +9 vitória, −9 derrota) não prevê o futuro e pode errar (quatro jogadas empatadas em 2, mas só uma garante vitória).
- **Árvore do jogo** até um nível de previsão (*look-ahead*); nós "mais" (eu jogo) e "menos" (adversário). Avalie as folhas e suba: nó mais = máximo dos filhos; nó menos = mínimo. Com previsão 2, a melhor abertura de X é o centro.
- Estruturas: nó com tabuleiro 3×3, `turn` (+1/−1), `son` e `next` (árvore geral como binária). Funções `buildtree`/`expand` (gera filhos recursivamente até a profundidade) e `bestbranch`.
- Truque **negamax**: `min(x,y) = -max(-x,-y)`, então um único laço de máximo serve para os dois tipos de nó, trocando o sinal nos nós menos.
- Exercícios: gerar a árvore e avaliar ao mesmo tempo, liberando nós; **poda alfa-beta**; kalah; jogo das varetas (tirar 1 ou 2; quem tira a última perde); como lidar com sorte (gamão).

### Simulação orientada a eventos: banco com 4 caixas (seção 4.4)
- Cada cliente chega com (hora de chegada, duração). Quatro filas (vai para a menor) e uma **lista de eventos** = fila de prioridade ascendente por hora, com no máximo 5 eventos (1 próxima chegada + 1 saída por caixa).
- Laço: tira o próximo evento; se for chegada, insere o cliente na menor fila, agenda a saída se ele for o único da fila e lê/agenda a próxima chegada; se for saída, soma o tempo no banco ao total, remove da fila e agenda a saída do próximo daquela fila.
- Um só tipo de nó (time, duration, type, next) para clientes e eventos, para não duplicar rotinas (type −1 = chegada, 0..3 = saída do caixa i).
- Exercícios: tamanho médio das filas, desvio-padrão, fila única para 4 caixas (comparar), troca de fila quando uma passar a outra em mais de 2, durações aleatórias uniformes e "quase normais" (soma de 15 uniformes), fábrica com máquinas de polimento.

### Inteiros arbitrariamente longos em listas (seção 4.5)
- Circular simples com cabeçalho (só positivos) e circular dupla (com sinal, contagem no cabeçalho, subtração com "empresta-um" e remoção de zeros à esquerda). Excelente projeto integrador de listas. Exercícios: multiplicação, 100º Fibonacci.

### Lista representada como árvore binária (seção 5.4)
- Elementos nas folhas, da esquerda para a direita; cada nó interno guarda `lcount` (folhas à esquerda). Achar o k-ésimo: se `r <= lcount` desce à esquerda; senão `r -= lcount` e desce à direita. Custo ≈ profundidade, contra k na lista ligada.
- Remoção ajusta `lcount` dos ancestrais e sobe a folha irmã; construção em vetor sequencial (árvore estritamente binária quase completa com 2n−1 nós).
- Josephus revisitado: próxima posição = `1 + (k - 2 + m) % size`; custo ≈ (n−1)·log2 n contra (n−1)·m da lista circular. Precursor de árvores de ordem estatística.

### Outros extras curtos
- **Reconhecedor recursivo** expr/termo/fator (descida recursiva) e **árvore sintática** (exercício 5.5.9) — semente de compiladores.
- **Árvores encadeadas** (*threaded*) e percurso por inversão de ponteiros (Deutsch–Schorr–Waite).
- **Expressões gerais** como árvores ordenadas (operadores de qualquer aridade, `f(g,h,i,j)`) com `replace`/`evaltree` e as operações `setsons`/`addson` (lista de filhos do mais novo para o mais velho deixa `addson` O(1)).
- **Backtracking**: oito rainhas e labirinto (exercícios 3.3.10 e 3.3.11).
- **Ackermann** (exercício 3.1.7) como exemplo de recursão que não vira laço simples.
- **Duas pilhas num vetor** e **várias pilhas/filas num vetor** (exercícios 2.2.7 e 4.2.1).
- **Lista com ponteiro-soma/XOR** e árvore com `fleft`/`fright` em XOR (exercício 5.2.10).

