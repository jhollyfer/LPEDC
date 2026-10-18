# Fichamento — Algoritmos e Estruturas de Dados 1 (Castilho, Silva, Weingaertner — UFPR)

- **Autores:** Marcos A. Castilho, Fabiano Silva, Daniel Weingaertner (DINF/UFPR, disciplina CI1055).
- **Edição:** recurso eletrônico, Curitiba, 2020, 345 p. Licença CC BY-NC-ND 2.5 BR (não pode ser copiado nem adaptado para
  fins derivados: aproveitar **ideias**, não texto).
- **Linguagem dos exemplos:** Free Pascal (tudo precisa ser traduzido para C).
- **Lido:** 9926 linhas (integral: capítulos 1–13, exercícios, apêndices e referências).

## Avaliação geral

O melhor material do acervo para **lógica de programação pura**. É um livro de *algoritmos*, não de linguagem: quase só
inteiros, um único laço (`while`) na parte 1, e os mesmos problemas reaparecem com foco novo (o "ler até o zero" vira
contador, acumulador, menor, histograma). Trunfos: (1) **cap. 6**, que dá nome aos padrões de raciocínio (espinha dorsal do
0030); (2) **cap. 7**, em que a primeira solução é ruim e vai sendo melhorada com custo comparado (inverter número,
fatorial, primos); (3) **banco de exercícios** em ordem de dificuldade, quase todos com casos de teste. Fracos: Pascal em
linha corrida (conversão do PDF), figuras e fórmulas perdidas, e **muitos bugs/inconsistências** em códigos e enunciados —
anotados nas "Pegadinhas" e em "Obsoleto"; rendem bons exercícios de "ache o erro".

---

### 0001-algoritmo

**Conceitos-chave**
- Um problema admite várias soluções; a melhor depende do critério (exatidão, conhecimento prévio, equipamento, escala).
- **Problema × instância:** "contar elementos de um conjunto" × "contar os alunos desta sala hoje". Computação estuda o
  processo, não o 2+2=4.
- Algoritmo = passos precisos escritos por um e executados por outro: imperativos, em ordem, repetição explícita, **nada
  implícito**. Programa = algoritmo detalhado até o nível do executor (o algoritmo pode ser genérico, o programa não).

**Explicações boas**
- **Contar os presentes (7 soluções):** um a um; carteiras vazias; área × densidade (inexato); catraca; filas × alunos por
  fila; cada primeiro de fila conta a sua (paralelo); **todos com 1, juntam-se em pares, somam, um senta** — ~log₂(n)
  rodadas (1000 → 10; 1 milhão → 20). Eficiência e paralelismo sem fórmula.
- **Receita de bolo** no "formato padrão" (uma ação por linha, em ordem, tudo explícito) e o "algoritmo das claras em neve"
  para o novato: o detalhe depende de quem executa ("como separar a clara?"). Vago ("aos poucos", "até ficar homogêneo") não
  serve para máquina.

**Ideias de exercícios**
- Algoritmo para trocar pneu de carro/bicicleta, e para cada uma das 7 contagens (critério: nenhuma ação implícita, laço com
  condição explícita, ex. "enquanto houver alguém de pé com par...").

### 0002-pseudocodigo

**Conceitos-chave**
- **Teste de mesa:** acompanhar o programa linha a linha anotando, numa tabela, o valor de cada variável a cada passo
  (colunas: situação, variáveis, comentário). Começa com "indefinido" (lixo) antes de qualquer atribuição.
- Pseudocódigo como ferramenta de **refinamentos sucessivos**: escreve-se o laço de controle com o miolo ainda em português
  (`se {i e j são primos entre si} então imprime`) e só depois se resolve o subproblema.

**Explicações boas**
- Teste de mesa do "conta até o zero" (5 8 3 9 0) com o teste do laço como linha própria ("5≠0, entra no laço"). A tabela
  do livro tem um erro (n=5 onde deveria ser 8): "ache o erro no teste de mesa".
- Maior segmento crescente em 6 versões incrementais (ler; lembrar anterior; contar; memorizar; guardar máximo; testar o
  último) — modelo de construção gradual.

**Ideias de exercícios**
- Teste de mesa de `y=0; m=1; enquanto x>0 { y += (x%2)*m; x /= 2; m *= 10 }` para x = 0, 10, −1. **Resposta:** 0; 1010;
  0 (nem entra). Escreve o binário de x "em dígitos decimais".

### 0004-binario

**Conceitos-chave**
- Decimal → binário por divisões sucessivas por 2: os restos saem **ao contrário**.
- Segundo método, pela definição: começar pela maior potência de 2 (128 para 0..255), testar se `n - pot ≥ 0` (bit 1 e
  desconta) ou não (bit 0), e dividir a potência por 2 até zerar. Imprime na ordem certa sem inverter.
- Binário → decimal separando dígitos com `%10` e `/10` e acumulando potências de 2.

**Explicações boas**
- 22 = 1·2⁴ + 0·2³ + 1·2² + 1·2¹ + 0·2⁰ = 10110₂, percorrido passo a passo com as diferenças.
- Inverter a saída dos restos usando a técnica de "multiplicar por 10 e somar" (a mesma de inverter número) — reaproveita
  padrão.

**Pegadinhas**
- O laço `enquanto n≠0 imprime n%2; n/=2` imprime 01101 para 22 (invertido) e **nada** para 0.
- Representar binário em `int` decimal (10110) estoura rápido: 32 bits já não cabe num `int`.

**Ideias de exercícios**
- Só dígitos 0/1? Se sim, imprimir o decimal (10011 → 19; 1210 → "nao eh binario"; 101010101 → 341).
- Base B: dígito fora de [0, B−1] → −1. Base 3, dígitos 2 1 0 1 → 64 (o livro diz 65: erro); base 2, dígitos 3 5 → −1.
- "Notação UMC": o i-ésimo dígito da direita vale dᵢ·i! (719 → 53; 15 → 7; 110 → 8; 102 → 8).

### 0005-compilacao

**Conceitos-chave**
- **Von Neumann:** programa e dados juntos na memória; um ciclo fixo lê a instrução em [p], executa e avança p. O hardware
  só sabe um repertório pequeno. Distinguir **endereço × conteúdo** ([p]).
- Alto nível = sucessão de **abstrações** sobre a mesma memória: separar a "tripa" por instrução → tirar endereços →
  mnemônicos → notação x ← [y]+[z] → **nomes (variáveis)** → fórmula → compilador. "O computador não mudou."
- Ciclo **editar → compilar → executar → testar**: erro de compilação × erro de lógica.

**Explicações boas**
- Computador fictício da *Big Computer Company* com **9 instruções** (load, add, sub, mult, div, sqrt, read, write, stop),
  cada uma ocupando 2, 3 ou 4 posições conforme os operandos. Uma "fotografia" de 63 posições é um programa que resolve x² −
  bx + c = 0 por Bhaskara; o aluno faz o papel do computador e descobre a "meta-regra" que a máquina nunca descobre. (Não
  trata Δ < 0.)

**Ideias de exemplos**
- Simulador da BCC em C: `int mem[64]`, `while (mem[p] != 9) switch (mem[p]) {...}` — `switch`, vetor e "código é dado".

**Ideias de exercícios**
- Executar a memória à mão com b=5, c=6. **Resposta:** escreve 2 e 3. Adaptar para ax² + bx + c = 0.
- Programa BCC que lê dois números e imprime a média. **Resposta:** read 40; read 41; load 42 2; add 43 40 41; div 44 43 42;
  write 44; stop.

### 0007-variaveis

**Conceitos-chave**
- Variável = endereço de memória com nome e tipo (o tipo diz como ler os bits); a declaração reserva o espaço antes de
  executar. Só se chega à memória por variáveis, declaradas ao escrever o código: não existe "uma variável por número lido".

**Explicações boas**
- Lendo 5 8 3 9 0 sempre em `n`, cada leitura apaga a anterior; o humano "vê" 4 números, o computador vê um por vez. Motiva
  todo o capítulo 6. (Do cap. 5: editor de texto puro, nada de "firulas" de interface.)

### 0012-aritmetica

**Conceitos-chave**
- `div` e `mod` (em C: `/` entre inteiros e `%`) são as ferramentas para separar dígitos: `n % 10` dá o último dígito; `n /
  10` tira o último dígito.
- Precedência: `b + c/2` ≠ `(b + c)/2`.

**Pegadinhas**
- `i = i + 1` não é equação: calcula-se o lado direito com o valor antigo e só depois se guarda.
- `sqrt` de negativo (Bhaskara com Δ<0) dá erro/NaN: testar Δ antes. No laço do primo, preferir `i*i <= n` a recalcular
  `sqrt(n)` a cada volta.

**Ideias de exercícios** (todos com casos de teste no livro)
- Somar horas (12 52 + 7 13 → 20:05); segundos → graus, min, s (3500 → 0,58,20; 7220 → 2,0,20); h:m → minutos desde 0:00
  (23 55 → 1435); notas de R$100 num troco (958 → 9); dígitos de uma placa de 4 algarismos (2569 → 9, 6, 5, 2).
- `N mod M` só com subtração (30 7 → 2). Trocar duas variáveis com e sem auxiliar (`a=a+b; b=a-b; a=a-b`; em C, risco de
  overflow).
- Fórmulas: termo da PA (8 1 3 → 10; 100 10 1 → 991), soma de Gauss (100 1 100 → 5050), gorjeta de 10% (75 → 82,50),
  comissão de 20% + R$5 por par (50000, 100 → 10500).

### 0013-conversao

**Conceitos-chave**
- Divisão real × inteira; o tipo do resultado depende dos operandos.

**Ideias de exercícios**
- "Qual o tipo correto de A..E?" com `A = 1+2*3; B = 1+2*3/7; C = 1+2*3 div 7; D = 3 div 3*4.0; E = A+B*C-D`. Em C
  (adaptado): `1+2*3/7` vale 1 com `int` e ≈1,857 com `1+2*3/7.0`; `3/3*4.0` vale 4.0 (double). Resposta: A e C podem ser
  int; B depende da divisão; D e E precisam ser double.

### 0017-relacionais

**Pegadinhas**
- `3 <= a <= 5` não significa "a no intervalo" (em Pascal nem compila; em C compila e está errado: vira `(3<=a) <= 5`,
  sempre verdadeiro). Escrever `a >= 3 && a <= 5`.
- Comparar reais com `==` (busca de `x` real no vetor, teste de inversa de matriz).

**Ideias de exercícios** (calculados por mim; o livro não traz gabarito)
- Com a=6, b=9.5, z=6.0, p=4, q=5, sim=V: `sim && q>=p` → V; `0<=b && z>a || a==b` → F; `0<=b && (z>a || a==b)` → F; `0<=b
  || (z>a && a==b)` → V.
- Com a=5, b=3, d=7, p=4, q=5, r=2, x=8, y=4, z=6 (inteiros, em C): `(z/a + b*a) - d/2` → 13; `p / r % q - q / 2` → 0 (em
  Pascal nem compila: `mod` sobre real); `(z/y + 1 == x) && sim || (y >= x)` → falso (0).

### 0018-logicos

**Conceitos-chave**
- Negação da condição de parada: "parar quando n = 0" vira `enquanto n ≠ 0`. O laço repete enquanto a condição for
  verdadeira, então a condição é o **contrário** da parada.
- Parar o laço por dois motivos: `enquanto (i <= n) && !achou`.

**Pegadinhas**
- Condição de fim "dois zeros" é `(a != 0) || (b != 0)` (continua se *algum* não é zero) — muitos escrevem `&&` e param no
  primeiro zero.

### 0019-if

**Ideias de exercícios** (5.11.2, todos com casos de teste)
- Positivo/negativo/nulo; divisível por 3 **e** 7 (21 → sim; 7 → nao; −42 → sim); por 10, 5, 2 ou nenhum (10 → "10 5 2";
  7 → "nenhum"); prestação ≤ 30% do salário (500, 200 → nao); entre 20 e 90 exclusivo (20 → nao).

### 0020-if-else

**Pegadinhas**
- Em Pascal não se põe `;` antes de `else`; em C a armadilha análoga é `if (x); {...}`.

**Ideias de exercícios**
- Raiz quadrada se ≥ 0, quadrado se negativo (4 → 2.00; −5 → 25.00).
- Soma > 20 → soma+8; senão soma−5. **Resposta:** 13.14 e 5 → 13.14; −3 e −4 → −12.00; 16 e 5 → 29.00 (o livro imprime 20.00
  — erro do caso de teste).

### 0021-else-if

**Conceitos-chave**
- **Árvore de decisão:** prever todos os caminhos antes de conhecer os dados. No "menor de três", se a<b e a<c, a é o menor
  sem saber nada de b × c.
- **A ordem das perguntas simplifica as condições:** no histograma por idade, depois de `idade <= 2` falso, já se sabe que
  idade ≥ 3, então o próximo teste é só `idade <= 12`; o último `else` nem precisa de teste.

**Explicações boas**
- No menor de três, quando `a >= b` e depois `b < c` é falso, imprimir c funciona mesmo com empates "porque no pior caso são
  iguais" — inferência lógica com igualdade.

**Ideias de exercícios**
- Triângulo inválido/equilátero/isósceles/escaleno (7 7 5 → ISOSCELES; 5 4 15 → INVALIDO); média de 2 notas (≥7 APROVADO,
  <3 REPROVADO, senão EXAME: 10 e 0 → EXAME); classe eleitoral (16 → facultativo; 18 → obrigatório); categoria de natação
  (4 → INVÁLIDO; 13 → Juvenil A); crédito por faixa de saldo (571 → 171,30; 3001,20 → 1500,60).

### 0023-switch

**Conceitos-chave**
- O `case` do Pascal aceita **faixas** (`0..2: bebe++`); o `switch` de C não — faixas exigem `if/else if` (ou `case 0: case
  1: case 2:`).

**Ideias de exercícios**
- Dia da semana 1..7 (0 e 8 → INEXISTENTE).

### 0025-while

**Conceitos-chave**
- Laço controlado por **variável de controle** que aparece do lado esquerdo de uma atribuição dentro do laço (senão o laço
  nunca termina).
- O teste vem antes: com valor inicial já falso, o corpo nunca executa (`i = 6; while (i<=5)`).
- **Dois jeitos de saber quando parar:** quantidade conhecida (contador até 30, ou lê N primeiro) ou **condição
  alternativa** (sentinela: "termina quando ler zero"). Se o enunciado diz só "vários números", ele está incompleto.
- **Leitura antecipada:** com sentinela, ler o primeiro valor antes do laço e ler o próximo no **fim** do corpo; assim o
  teste sempre vê um valor recém-lido e o zero não é processado.

**Explicações boas**
- "Imprimir de 1 a 5" com 5 `writeln` → de 1 a 10 → de 1 a 100 milhões: o computador passa a atrapalhar; o raciocínio tem
  que deixar o trabalho repetitivo para a máquina.
- Duas versões lado a lado do "somar vários pares": com contador e com sentinela — o miolo (ler e somar) é idêntico; só muda
  o controle do laço.

**Ideias de exercícios**
- Ler pares até zero e imprimir o sucessor par (12 → 12 14).
- Para cada par A B (até 0 0), imprimir de min(A,B) a max(A,B) (2 −3 → −3 −2 −1 0 1 2).

### 0026-do-while

**Conceitos-chave**
- `repeat ... until` (= `do ... while` com condição negada) é o laço natural para **validar entrada**: ler n até n > 0; ler
  a, b, c até a ≠ 0 (garante equação do 2º grau).

**Pegadinhas**
- `until cond` do Pascal para quando a condição fica verdadeira; `do {} while (cond)` de C continua enquanto é verdadeira —
  inverter a condição ao traduzir.

**Ideias de exercícios**
- Ler A e B até serem diferentes; se A<B somar ímpares de A a B, senão média dos múltiplos de 3 entre B e A. **Resposta:** 3
  3, 4 4, 3 5 → 8; 9 1 → 6.00.

### 0028-break-continue

**Conceitos-chave**
- O livro **não usa break**: para sair cedo, usa uma **flag booleana** na condição (`while (i <= n-1) && eh_primo`). No
  LPEDC, mostrar as duas formas e discutir legibilidade.

**Pegadinhas**
- Depois de sair por flag, o índice já foi incrementado: a busca simples devolve `i - 1`.
- (`for`) Em Pascal a variável do `for` fica indefinida após o laço — o livro usa `j` assim em `imprimir_transposta` (bug).
  O `for` só aparece na parte de vetores.

### 0029-lacos-aninhados

**Conceitos-chave**
- Tabuada do 7 (um laço) → tabuadas de 1 a 10 (dois laços: o 7 vira i). O comando interno roda 100 vezes, o externo 10 —
  primeira menção a custo **quadrático**.
- **Cuidado ao "colocar um laço dentro de outro" sem pensar:** fatorial de 1 a n com laço aninhado recalcula 2×1 seis vezes,
  3×2 cinco vezes... A versão esperta usa fat(n+1) = (n+1)·fat(n) e um só laço (linear).

**Explicações boas**
- Gerar palíndromos de 1 a 1000 por **formato** (9 de um dígito; 11·i; i·100 + j·10 + i com dois laços) em vez de testar
  todos — contadores em vários níveis.
- Primos entre si para 2 ≤ a ≤ 100, a ≤ b ≤ 100: primeiro escrever os dois laços com o teste em pseudocódigo, depois
  "encaixar" Euclides.

**Ideias de exercícios**
- Imprimir a pirâmide 1 / 121 / 12321 / ... / 12345678987654321 com **no máximo três** comandos de impressão; depois com
  **exatamente dois** laços; depois centralizada. **Resposta esperada:** laço externo i=1..9; laço de 1 a i e de i−1 a 1 (ou
  um laço só).
- Para M dado, imprimir os ímpares consecutivos cuja soma é n³, n=1..M. **Resposta:** o primeiro ímpar de n é n²−n+1 (1; 3
  5; 7 9 11; 13 15 17 19).
- Ler N e imprimir N, 2N, ..., 5N; para cada um de N números positivos, seus 5 primeiros múltiplos.

### 0030-padroes-de-laco

Assunto central do livro (cap. 6 nomeia, cap. 7 aplica).

**Conceitos-chave**
1. **Contador:** começa em 0, +1 por item válido (começar em 1 obriga a imprimir `cont-1`; o zero digitado de cara mostra
   por quê).
2. **Acumulador:** inicializar com o **elemento neutro** (0 na soma, 1 no produto).
3. **Árvore de decisão** (0021): só quando a quantidade de dados é fixa e pequena.
4. **Definir a priori e corrigir ("chute"):** o primeiro lido **é** o menor "dos lidos até agora"; a cada novo valor,
   corrigir. Tratar entrada vazia. Mesmo padrão: flag `eh_primo = 1` corrigida ao achar divisor; `maiortam = 0`.
5. **Lembrar de duas informações:** Fibonacci (último, penúltimo — a ordem da atualização importa); Euclides.
6. **Processar parte dos dados** (`if` no corpo) e **parte de um jeito, parte de outro** (`if/else`): o controle do laço não
   muda — "dois subproblemas".
7. **Múltiplos acumuladores:** histograma por faixa etária, um contador por faixa.
8. **Lembrar o anterior:** `anterior = atual` no **fim** do corpo; antes do laço, valor seguro (0 para naturais).
9. **Destruir uma cópia** (contar dígitos) e **construir enquanto destrói** (`inv = inv*10 + n%10; n /= 10`).
10. **Novo termo a partir do anterior** (séries): atualizar numerador (`num *= x*x`), denominador (`fat *= 2i(2i+1)`) e
    sinal (`s = -s`) em vez de recalcular.
11. **Parada por convergência:** |novo − anterior| < ε **ou** máximo de iterações (avisar se saiu pelo máximo).

**Explicações boas**
- "Quantos números foram digitados?" intriga calouros ("quantas variáveis declaro?"): se soubéssemos, não precisaríamos do
  programa. Uma variável basta.
- Inverter número de 3 dígitos: centena/dezena/unidade → para 4 dígitos muda tudo → laço de 3 voltas → contar dígitos antes
  → `while (n != 0)`. Generalizar a solução, não a instância.
- Seno construído sobre a série de e em três passos (sinal, fatorial de 2 em 2, numerador xⁿ): "qual é a novidade de cada
  termo?"
- Maior segmento crescente: variáveis de **estado** (`tamanho`, `maiortam`) e um `if` **depois do laço**, porque o último
  segmento nunca passa pelo `else`.

**Pegadinhas**
- Esquecer o último grupo após o laço; produto iniciado em 0; `ultimo = atual; penultimo = ultimo` (ordem errada).
- Fibonacci estoura cedo (o livro avisa: precisa de `longint`); em C, `int` estoura em F(47).
- Segmento crescente com `anterior = 0`: um primeiro valor 0 não conta.

**Ideias de exemplos**
- Mesmo esqueleto com leitura antecipada e quatro corpos: contar, somar, menor, histograma (sentinela 0 ou −1).
- Número áureo por razões Fₙ₊₁/Fₙ até diferença < 10⁻¹⁴; e = Σ 1/k! com 9 termos e com ε = 10⁻⁴ + limite.

**Ideias de exercícios** (respostas conferidas)
- Soma dos pares e dos ímpares até o zero (1..9 0 → 20 e 25). Múltiplos de 7 ímpares (7 14 15 21 18 35 70 → 7 21 35).
- Os dois maiores (1 2 3 4 5 6 0 → 6 5). Maior potência de p que divide n (3, 45 → 9; não divide → 1).
- Populações com crescimento anual inteiro desde 2009: a menor alcança a maior? quando? **Livro:** 100 80 2 3 → 2036; 100 20
  10 50 → 2015; 100 20 50 10 → nao. **Atenção:** 2036 sai com `enquanto menor < maior`; com "ultrapassar" (`<=`) dá 2037;
  com contas reais, 2032 — discutir enunciado.
- K primeiros perfeitos (6 28 496 8128). Histograma 4 faixas (347 200 3 32000 400 10 20 25 0 → 4 1 2 1).
- Segmentos de iguais consecutivos (2 2 3 3 5 1 1 1 → 4). Maior segmento crescente (5 10 3 2 4 7 9 8 5 → 4).
- k-alternante (k=2: 1 3 6 8 9 11 2 4 1 7 6 8 → é; 1 2 3 3 4 6 3 2 → não). Amigos quadráticos (13 16 → sim).
- Fatorar em primos (56 → 2 2 2 7). Posição no conjunto dos números de 4 algarismos distintos em ordem crescente (1026 → 4;
  1243 → 72; 9876 → 4536). Par (x,y) que maximiza xy − x² + y (4 4 → 2 4 8).

### 0031-aleatorios

**Conceitos-chave**
- Gerar uma permutação aleatória de 1..n, em 4 versões cada vez melhores:
  1. sortear o vetor inteiro e testar se é permutação — "infernalmente" lento a partir de n≈14;
  2. sortear cada posição e repetir se já existe — ok até ~30 mil;
  3. partir da identidade e fazer de 0 a 999 trocas aleatórias — rápido, **mas enviesado**;
  4. vetor auxiliar com os números restantes; sorteia um **índice** do auxiliar, copia o último para o buraco e diminui o
     tamanho — é o **Fisher–Yates**: linear e uniforme.
- Espalhar minas sem repetir: sortear (x, y) até cair numa casa vazia.

**Pegadinhas**
- A versão 3 **não** é uniforme (com 0 trocas devolve a identidade), mas o livro a apresenta como boa. Sortear casa até
  achar livre entra em laço infinito se minas > casas. `randomize` a cada chamada (em C: `srand(time(NULL))` uma vez só).

**Ideias de exercícios**
- Desafio "tabela hash didática": inserir n valores aleatórios em posições aleatórias; se a posição estiver ocupada,
  procurar a próxima livre circularmente — é **sondagem linear** (liga com 0112).

### 0033-funcoes

**Conceitos-chave**
- Três motivações: **modularidade** (trocar a entrada textual por gráfica sem que os cálculos percebam),
  **reaproveitamento** (código quase igual repetido é sinal de função) e **legibilidade** (`if eh_par(a)` lê melhor que `a
  mod 2 = 0`).
- Protótipo = **contrato**: nome, parâmetros tipados e tipo de retorno. Com o protótipo já se escreve o programa principal;
  o corpo vem depois.
- Função se comporta como expressão (pode ir dentro de um `printf`); procedimento (em C, função `void`) se comporta como
  comando.

**Explicações boas**
- **Oito maneiras de escrever `eh_par`** (if/else com `=0`, `<>0`, `<>1`, `=1`; "assume falso e corrige"; "assume verdadeiro
  e corrige"...) — todas equivalentes; ótimo para mostrar que o contrato importa mais que o corpo (em C: `return n % 2 ==
  0;`).
- Dígito verificador: o programa principal fica "em alto nível" (ler, separar número e DV, calcular o correto, comparar) e
  cada passo é uma função curta.
- MDC pela definição (fatoração) ocupa duas páginas com 4 trechos quase iguais → motiva funções `num_vezes_que_divide`,
  `potencia`, `menor`. "Mas lembre-se: Euclides é melhor."

**Ideias de exercícios**
- `contrario(123, 321)` → sim; `eh_anterior(d1,m1,a1,d2,m2,a2)` (ano, depois mês, depois dia); aumento percentual
  (10 15 → 0.50).
- Média ponderada 1,2,3 (inteira) + `aprovado(media)` com corte 50: 100 40 5 → 32 reprovado; 5 40 100 → 64 aprovado.
- seno/cosseno por série (7 termos) e `existe_tangente(x, &tg)` que devolve booleano e o valor.

### 0034-parametros

**Conceitos-chave**
- **Por valor = cópia** (feita na pilha): alterar o parâmetro não altera a variável de quem chamou. Por isso `calcula_dv(n)`
  pode destruir `n` dividindo por 10 sem estragar o original.
- **Por referência** (Pascal `var`; em C, ponteiro): a função mexe na variável original. Obrigatório para **ler** dentro de
  uma função e para "devolver mais de um resultado".
- Função que devolve **quantas** raízes há (0, 1 ou 2) e as raízes por referência — padrão "retorno = status, saída por
  parâmetro" (em C, como `scanf`).

**Pegadinhas**
- Efeito colateral escondido: `num_vezes_que_divide(p, &n)` também divide `n` (o próprio livro critica).
- "Passe vetores sempre por referência para não copiar" é regra de Pascal: em C o vetor já vai como ponteiro (o que se
  copia é a `struct` que o contém). O `var` de Pascal confunde com declaração — em C, o `*` da declaração × o do uso.

**Ideias de exercícios**
- `incrementa(&n)` usada num laço que imprime de 1 a 10 (resposta: `void incrementa(int *n){(*n)++;}`).
- Trocar x e y com procedimento — e depois testar passando por valor para ver que não troca.
- (0035) O `temp` global da troca "não faz sentido": subprograma não deve depender de globais; vira local.

### 0038-recursao-na-pratica

(O livro deixa recursão para AED2, mas o **flood fill** e o "abrir vizinhos" do campo minado, feitos com pilha explícita,
são alvos naturais para a versão recursiva — ver 0116.)

**Explicações boas**
- **Euclides em grade:** escrever a e b, anotar quociente em cima e resto embaixo, copiar o resto para a direita e repetir
  até resto 0; o MDC é o último divisor (135, 72 → restos 63, 9, 0 → MDC 9). Funciona também com a < b (a primeira rodada só
  troca os dois).
- Comparação com o MDC pela fatoração (72 = 2³·3², 135 = 3³·5 → 3² = 9): Euclides não precisa de primos nem de fatoração.

- Pegadinha: Euclides com entrada 0 dá divisão por zero no `mod`; o livro testa antes.

### 0042-vetores

**Conceitos-chave**
- Motivação: imprimir na ordem inversa é **impossível** com uma variável — quando se lê o segundo, o primeiro foi perdido.
  Vetor = muitas posições com um só nome + deslocamento.
- Endereço do elemento = início + índice × tamanho do tipo (explicado em bytes).
- **Tamanho alocado × tamanho útil:** declara-se 200, usam-se 10; o resto é lixo. Não deixar "buracos". O tamanho máximo é
  decidido em tempo de compilação ("apostas da megassena: 15 bastam; clientes de banco: estimar e testar").
- **Índice × conteúdo:** imprimir os elementos *pares* ≠ imprimir os elementos de *índices pares* (12 2 0 18 × 12 23 2 18 21
  no exemplo).
- Copiar vetor é copiar elemento por elemento.

**Pegadinhas**
- `v[201]` num vetor de 200: Pascal acusa; **C não confere** — cai no 0042.
- `v[v[13]]` só é válido se o conteúdo for inteiro e um índice válido.
- O livro usa vetores começando em 1 e posições extras (0 ou n+1) para **sentinela** — em C, reservar `MAX+1`.

**Ideias de exercícios**
- Índices pares recebem o dobro do índice, ímpares o triplo (base 1, n=5 → 3 4 9 8 15).
- |soma dos positivos / soma dos negativos| com "divisao por zero" e "vetor vazio" (−2 −7 7 2 → 1.00; o livro imprime
  −1.00).
- Ler até zero e responder "pertence"/"nao pertence" a consultas; está ordenado? (1 3 4 8 8 10 15 → sim); repetidos (3 1 7 3
  4 5 7 3 3 2 → 3 7) e frequência de cada distinto; concatenar duas sequências num terceiro vetor.

### 0043-vetores-e-funcoes

**Conceitos-chave**
- Passar o vetor **e o tamanho útil**; a leitura recebe o tamanho por referência (lê `tam` dentro do procedimento).
- `struct { int tam; T dados[MAX]; }` — "o vetor que sabe o próprio tamanho" (seção 11.2).

**Ideias de exercícios**
- Remover a posição p de vetor **não ordenado** em O(1): copiar o último para p. **Resposta:** 1 3 4 8 8 10 15, p=4 → 1 3 4
  15 8 10. (O caso de teste do livro remove o *valor* 4, que está na posição 3 — confusão índice × conteúdo; e o primeiro
  caso saiu embaralhado na extração.)
- Mesmo problema com vetor ordenado: deslocar para trás (1 3 4 8 10 15).
- Soma e produto escalar de vetores (o livro: produto escalar do exemplo = 28).

### 0044-matrizes

**Conceitos-chave**
- Matriz = vetor de vetores; fixar uma linha é trabalhar com um vetor. Laço duplo: linha fora, coluna dentro.
- Transposta impressa trocando i e j só na impressão (a memória não muda).
- Multiplicação: cada elemento é o produto escalar de uma linha de A por uma coluna de B (A n×m · B m×p = n×p); três laços.
- Inserir uma coluna k: deslocar as colunas m..k uma para a direita (da última para a k).
- Repetidos numa matriz com 4 laços aninhados = O(n⁴) para matriz n×n.
- **Borda artificial:** acrescentar linha/coluna 0 e n+1 com valor especial elimina os `if`s de canto ao olhar vizinhos
  (campo minado, flood fill).

**Explicações boas**
- **Imagens PGM** (P2, largura altura, valor máximo, pixels 0..255): imagem é matriz de inteiros. Três operações visuais:
  - clarear: somar constante e saturar no máximo;
  - **zoom ½:** cada bloco 2×2 vira a média (canto do bloco = (2i−1, 2j−1)); recalcular o máximo;
  - **detectar bordas:** gradiente = |4·p − (cima+baixo+esq+dir)|; acima do limiar = borda. Exemplo do quadrado de 50 no
    meio de valores 0..6: pixel (2,4) dá 96, pixel (4,2) dá 6.

**Pegadinhas**
- `imprimir_transposta` do livro usa a variável do `for` fora dele (bug).
- O texto diz que borda vira 0 (preto) e não-borda 255, o código faz o contrário.
- Clarear com constante negativa precisa saturar em 0 também.
- Em C, matriz em função exige a 2ª dimensão fixa (`int m[][MAX]`).

**Ideias de exercícios** (com respostas)
- B = Aᵀ? (1 2 / 3 4 / 5 6 e 1 3 5 / 2 4 6 → sim). Matriz de permutação (um único 1 por linha e coluna). B é inversa de A?
  (2 1 / 4 3 e 1.5 −0.5 / −2 1 → sim; cuidado com `==` em reais). x resolve Ax = y? (1 2 / 2 1, y = −3 0, x = 1 −2 → sim).
- Linhas e colunas nulas (exemplo → 2 1). Soma dos 8 vizinhos (0 1 / 2 0 → 3 2 / 1 3). Quadrado mágico (8 0 7 / 4 5 6 / 3 10
  2 → sim, soma 15). Custo de itinerário pela matriz de custos (exemplo → 417).
- Caça-palavras numérico nas 4 direções; maior sequência de repetidos em linha/coluna; matriz "inca" (espiral horária de
  consecutivos); maior submatriz quadrada só de 1s (exemplo 6×6 → (2,2)–(4,4), programação dinâmica); posições não cobertas
  por retângulos num tabuleiro W×H; ordenar datas numa matriz n×3.
- Triângulo de Pascal com exatamente dois vetores (atual e anterior); linha 10 = 1 9 36 84 126 126 84 36 9 1.

### 0046-strings

**Conceitos-chave**
- O livro quase não trata strings (só `string[50]` em registros e a leitura de "P2"). Vale como analogia: "busca de uma
  sequência dentro de outra" e "localizar e substituir" são feitos com **vetores de inteiros** — os mesmos algoritmos servem
  para `char[]`.

**Ideias de exercícios**
- Onde a sequência 2 começa na 1 (1 2 3 4 5 6 / 3 4 5 6 → 3; ausente → 0); todas as ocorrências com sobreposição
  (padrão 1 8 1 em 30 números → 4 vezes: 1, 11, 26, 28); localizar e substituir (5 9 5 6 7 8 4 0 1 3, trocar 7 8 4 0 1 3
  por 1..8 → 5 9 5 6 1 2 3 4 5 6 7 8).

### 0064-struct

**Conceitos-chave**
- Registro = estrutura **heterogênea** (campos de tipos diferentes); vetor/matriz são homogêneos. Acesso por
  `variavel.campo`; combinação `v[i].cpf`, `v.dados[i]`.
- **Chave:** o campo usado para buscar/ordenar (CPF) pode ser diferente do que se imprime (telefone).
- Ao ordenar vetor de registros, **trocar o registro inteiro** — trocar só a chave mistura dados de clientes.

**Pegadinhas**
- Usar um tipo antes de declará-lo (`corte: Tamanho` antes de `Tamanho = (mini,medio,maxi)`) — em C também é erro.
- Campo com mesmo nome de variável é permitido (escopos diferentes).

**Ideias de exercícios**
- Nome/DDD/telefone: imprimir os de DDD 41 ou 21; com data de nascimento (struct aninhada), o mais jovem (exemplo: Fulano,
  2001 — o livro diz Beltrano, errado); ordenar por nome imprimindo `nome, DDD, tel, d/m/aaaa`; inserir mantendo a ordem.
- (0066) Busca por CPF imprimindo o telefone; seleção pela chave CPF. Imagem PGM como struct (lin, col, maior, matriz):
  binarizar pela média e compactar sequências de 1s em contagens (run-length).

### 0076-eficiencia

**Conceitos-chave**
- "Custa caro" = o comando executado mais vezes. Contar comparações no pior caso.
- Analisar melhor caso, pior caso e (informalmente) caso médio.

**Explicações boas**
- Tabela de comparações no pior caso: busca simples com flag 2n, com sentinela n, em vetor ordenado n, binária ~log₂n (n=10⁸
  → 200 milhões × 19).
- Primos: testar até n−1, só ímpares (n/2) ou até √n — para n = 10¹² são 10¹² contra 10⁶.
- Fatorial de 1..n: aninhado (quadrático) × reaproveitando o anterior (linear).

### 0077-big-o

**Explicações boas**
- Seleção: (N−1)+(N−2)+...+1 = N(N−1)/2 comparações, com a dedução de Gauss (somar a sequência com ela invertida); o termo
  N² domina, constantes e termos menores somem.
- "Contar presentes em pares" e busca binária: dividir por 2 a cada passo → logarítmico.

### 0078-invariantes

**Conceitos-chave** (o livro não usa a palavra "invariante", mas as frases estão lá)
- "De todos os números lidos **até agora**, `menor` é o menor" — invariante do padrão chute.
- Seleção: ao fim da etapa i, as i primeiras posições estão na ordem **final** (definitiva).
- Inserção: ao fim da etapa i, as i primeiras estão ordenadas **entre si** (relativa).
- Busca binária: se x existe, está entre `inicio` e `fim`; quando `fim < inicio`, não existe.

### 0079-tad

**Conceitos-chave**
- TAD = definir **o que** as operações fazem (protótipos + semântica), não **como**. Primeiro a interface, depois **usar** o
  TAD para resolver problemas, só no fim implementar — e mostrar mais de uma implementação com custos diferentes.
- TAD **conjunto**: vazio, cardinalidade, inserir, remover, união, interseção, diferença, pertence, iguais, contido, copiar;
  para percorrer: `retirar_um_elemento` (destrutivo) ou **iterador** (`iniciar_iterador` + `incrementar_iterador(c, &x)` que
  devolve falso no fim).
- Funções internas (busca binária) que não fazem parte da interface pública.
- Implementação 1 (vetor ordenado): pertence O(log n); união/interseção/diferença/contido O(n) por **fusão** com dois
  índices; inserir/remover O(n). Implementação 2 (não ordenado): inserir O(n) só por causa do teste de repetição; operações
  de conjunto viram O(n²).

**Explicações boas**
- **Megassena:** acertos = `cardinalidade(interseccao(sorteio, aposta))`; 6 sena, 5 quina, 4 quadra. O programa principal
  fica trivial sem saber como o conjunto é feito.
- **Celebridade** (conhecida por todos, não conhece ninguém, talvez ausente): pôr todos num conjunto/pilha, tirar dois (a,
  b): se a conhece b, a não é celebridade (devolve b); senão b não é (devolve a). Sobra um candidato em O(n); confirmar com
  um laço O(n). Com matriz seria O(n²).

**Pegadinhas**
- O registro declara `tam` e o código usa `c.card`; a celebridade chama `inserir_do_conjunto` — inconsistências do livro.
- A pilha é melhor que o conjunto na celebridade porque não paga o teste de repetição.

**Ideias de exercícios**
- TAD racional com resultado sempre simplificado (6/4 → 3/2) e sem divisão por zero.
- TAD polinômio (ler, valor em x, derivada, soma, produto).

### 0080-vetor-dinamico

**Conceitos-chave**
- `struct { int tam; T dados[MAX]; }` é o embrião da lista sequencial; o livro reconhece a limitação do tamanho fixo
  ("estimar o máximo, testar, recompilar") — motivação perfeita para `realloc` (0060).

**Ideias de exercícios**
- TAD lista: inserir no início/fim/posição p, remover, tamanho, vazia/cheia, imprimir, imprimir ordenada, fundir,
  intercalar, pesquisar posição p, copiar.

### 0081-lista-encadeada

**Ideias de exercícios**
- **Lista encadeada em vetor (cursores):** arquivo de funcionários com campo `proximo` (índice do próximo do mesmo
  departamento, −1 no fim) e tabela de departamentos com `inicio`. Vendas = registros 0 → 5 → 9 → 10 → 1. Operações:
  admitir, demitir, mudar de departamento sem reorganizar o arquivo. Ponte excelente entre vetor e ponteiro.

### 0087-pilha

**Conceitos-chave**
- LIFO; topo no **fim** do vetor (`ini` = quantidade): todas as operações O(1). Topo no início obrigaria deslocar tudo
  (O(n)).
- Operação extra `pilha_unitaria` (útil na celebridade e em jogos de cartas).
- Pegadinha: o livro não verifica pilha cheia/vazia ao empilhar/desempilhar (deixa como exercício).

### 0089-pilha-aplicacoes

**Explicações boas**
- **Parênteses balanceados com números:** ( [ { = 1 2 3; fechamentos negativos. Positivo empilha; negativo exige pilha não
  vazia e topo igual ao módulo. No fim, bem formada **e** pilha vazia. Exemplos bons: `({[]})[(){}]` ok; `({)` e `}{` erro.
- Pilha como "memória de decisões" no labirinto (empilhar a escolha; no beco sem saída, desempilhar e tentar a outra) e
  `begin`/`end` do compilador.
- **Pilha de coordenadas** para abrir as casas vazias do campo minado e para o flood fill — é DFS iterativa.

**Ideias de exercícios**
- Testar com 1 2 3 −3 −2 −1 2 1 −1 3 −3 −2 0 → bem formada; 1 3 −1 0 → não.

### 0090-fila

**Ideias de exercícios**
- TAD fila (FIFO, "fila da padaria"): criar, inserir, remover, tamanho, vazia/cheia, imprimir, frente com/sem remoção.
- Rodovia de mão única (carro 1 casa, caminhão 2, sem ultrapassar; saídas t=8 35, t=9 27, t=10 16) e com faixa de
  ultrapassagem (t=6 27, t=8 35, t=10 16).

### 0094-busca-sequencial

**Conceitos-chave**
- Versão 1 (`for` até o fim) sempre faz n comparações e devolve a **última** ocorrência.
- Versão 2 (`while` com flag) para na primeira, mas faz 2 testes por volta.
- **Sentinela:** colocar x em v[n] (posição extra) garante que o laço para; um teste por volta; depois ver se parou numa
  posição válida.
- Vetor ordenado: parar ao achar elemento **maior** que x (melhora o caso médio, não o pior).

- Pegadinha: sentinela exige posição reservada (tipo com `MAX+1`) e não pode ser usada em vetor passado como `const`.

### 0095-busca-binaria

**Explicações boas**
- Dicionário: abrir no meio e "rasgar" metade (500 → 250 → 125 → ~70 páginas).
- Rastreamento com I, M, F procurando 53 (inexistente) num vetor de 16: 4 etapas até F < I; quando os três apontam para a
  mesma casa, "Efeito Gita" (Raul Seixas: "eu sou o início, o fim e o meio").

**Pegadinhas**
- Só funciona em vetor ordenado — e ordenar/manter ordenado tem custo.
- O livro compara reais com `<>` na binária.

**Ideias de exercícios**
- Variante que devolve o **menor índice** onde x ocorre (−2 −7 2 2 7 → ordena → 2 está na posição 3; 1 8 8 8 8 10 15, x=8 →
  2).

### 0097-selection-sort

**Conceitos-chave**
- Etapa i: achar o **índice** do menor de i..n e trocar com i; N−1 etapas; comparações sempre N(N−1)/2; trocas no laço
  externo.

**Ideias de exercícios** (respostas calculadas)
- Quantas trocas a seleção faz em cada vetor de 10? Contando só trocas efetivas (posição ≠ i): 10..1 → 5; 5 4 3 2 1 10 9 8 7
  6 → 4; 10 1 9 2 8 3 7 4 6 5 → 7; 2..10 1 → 9; 1 10 2 9 3 8 4 7 5 6 → 8. (Se contar a troca consigo mesmo, como o livro,
  sempre 9.)
- Estabilidade: em 5 4 3 9 1 5 9 8 8 6 com cores, a seleção **inverte** os dois 9 (não estável).

### 0098-insertion-sort

**Conceitos-chave**
- Como ordenar cartas na mão: o elemento i é encaixado entre os i−1 primeiros, deslocando para a direita os maiores enquanto
  procura o lugar (abre espaço e busca ao mesmo tempo).
- Dois testes no laço interno (não passar do início; `v[j] > aux`). Inserção em vetor ordenado com **sentinela em v[0]**
  elimina o primeiro teste.
- Pior caso quadrático (ordem inversa), mas na prática costuma ganhar da seleção.

- Pegadinha: com `>=` no lugar de `>` a inserção deixa de ser estável.

### 0099-merge-sort

**Conceitos-chave**
- **Fusão (merge)** de dois vetores ordenados com três índices i, j, k; quando um acaba, copia o resto do outro (só um dos
  dois `for` finais executa). Linear. É a base do merge sort e da união/interseção/diferença do TAD conjunto.

### 0100-quick-sort

**Ideias de exercícios**
- Desafio de partição: usar v[1] como pivô e rearranjar menores à esquerda, maiores ou iguais à direita (13 32 99 2 26 12 →
  2 12 13 32 99 26). É o passo do quicksort.

### 0101-comparando

**Conceitos-chave**
- Trade-off central: vetor **não ordenado** → inserir e remover O(1), buscar O(n); vetor **ordenado** → buscar O(log n),
  inserir e remover O(n). "Nenhuma estrutura é melhor em geral; depende de haver mais buscas ou mais inserções."

### 0114-grafos

**Ideias de exercícios**
- Cidades com estradas de mão única em matriz 0/1 (L[i][i] = 1): estradas que saem/chegam de k; cidade com mais chegadas;
  ligações de mão dupla; quem chega a k; isoladas, sem saída, sem entrada; roteiro possível (3 4 3 2 1 → impossível no
  exemplo); dá para ir de k a p? (BFS); ciclo hamiltoniano partindo de k (difícil).
- Celebridade com matriz "i conhece j".

### 0116-dfs

(Serve também de ponte para 0115-bfs: trocar a pilha por fila na mesma grade.)

**Explicações boas**
- **Flood fill** (jogo da inundação): começa no canto (1,1), troca a cor velha pela nova em todos os vizinhos de 4 direções,
  usando pilha de coordenadas. Truque: como a cor muda ao empilhar, nenhuma casa entra duas vezes; borda de zeros dispensa
  testes de limite.
- **Campo minado:** clicar numa casa com 0 vizinhos-mina empilha a casa e abre a região, marcando `revelado` ao empilhar
  para não repetir.

**Pegadinhas**
- Campo minado: `zerar_campo` só percorre 1..x, então a borda **nunca** recebe BORDA; GANHOU/PERDEU × VITORIA/DERROTA.
- **Bug sério no flood fill:** `ler_cor` aceita a cor atual; se nova == velha, casas "pintadas" continuam `== cor_velha` e
  são reempilhadas para sempre (laço infinito). Correção: se `cor_nova == cor_velha`, não fazer nada.

---

### NOVO: séries numéricas e convergência

**Conceitos-chave**
- Séries (e, seno, cosseno, φ por frações contínuas) = acumulador + "novo termo a partir do anterior" + parada por erro e
  por máximo de iterações (ver 0030).

**Ideias de exercícios**
- cos(x) até |termoₖ − termoₖ₋₁| < 10⁻⁸; φ com N frações 1 + 1/(1 + 1/(...)); comparar com `math.h` (9 termos de seno
  para |x| ≤ π erram < 10⁻⁶).

### NOVO: números e dígitos (dígito verificador, palíndromo, base)

**Conceitos-chave**
- Família de problemas resolvidos com `%10` e `/10`: contar dígitos, inverter, palíndromo, binário, soma dos dígitos, dígito
  verificador.

**Ideias de exercícios**
- DV de 3 dígitos: (d1 + 3·d2 + 5·d3) % 7. **Resposta:** 123 → 1231; 001 → 0015; 101 → 1016.
- DV "módulo 10 com pesos 2,1" somando os dígitos dos produtos (estilo Luhn): 261533 → 4; ler números até zero e imprimir os
  mal formados (2615334 ok, 2615332 inválido).
- DV com pesos 1,2 repetido até sobrar um dígito (o do livro): 261533 → 26 → 10 → 2.
- Maior divisor de N que é potência de um primo da fatoração. **Resposta:** 45 → 9; 5616 → 27. (O enunciado diz 145 = 5²·7 →
  25, mas 145 = 5·29: a resposta correta é 29.)

### NOVO: polinômios em vetores

**Conceitos-chave**
- Polinômio de grau n = vetor de n+1 coeficientes, `p[i]` = coeficiente de xⁱ.
- Valor em x acumulando a potência (`potx *= x`) — ou Horner; derivada `d[i] = (i+1)p[i+1]`; valor da derivada sem montar o
  vetor; soma com graus diferentes; produto `m[i+j] += p[i]*q[j]` com o vetor zerado antes.

**Ideias de exercícios**
- P(x) = 5 − 2x + x², P(1) = 4. Método de Newton xₙ₊₁ = xₙ − p(xₙ)/p'(xₙ) com ε e máximo de iterações (para x² − 2 a partir
  de 1 → 1.41421).

### NOVO: permutações

**Conceitos-chave**
- Permutação de {1..n} representada por vetor. Testar validade em O(n²) (procurar cada i) ou O(n) com vetor auxiliar de
  marcação (ideia de um aluno).
- Potência Pᵏ, identidade, **ordem** = menor k com Pᵏ = ID = MMC dos comprimentos dos ciclos; MMC via MDC (mmc(a,b) =
  a·b/mdc(a,b)). Exemplo: P = 4 1 5 2 3 tem ciclos (1 4 2) e (3 5) → ordem 6.

**Pegadinhas**
- O teste O(n²) do livro lê `v[n+1]` quando não acha (fora do vetor).
- A "conjectura" dos alunos (soma = n(n+1)/2 e produto = n! ⇒ permutação) é **falsa**: contraexemplo n = 9, vetor 1 2 4 4 4
  5 7 9 9 (soma 45, produto 362880 = 9!). Ótimo exercício.
- Exemplo do livro "P(5) = 2" repete o 2 (não é permutação; erro de digitação).

### NOVO: refinamentos sucessivos (top-down) e projeto de jogo

**Conceitos-chave**
- Escrever primeiro o programa principal com funções que ainda não existem (`inicializar; imprimir; repetir ler_jogada;
  executar_jogada; imprimir até ganhou ou perdeu`) e ir decidindo a estrutura de dados (registro por casa com `info` e
  `revelado`; registro do jogo com dimensões, total de minas, `falta_abrir`, `status`).
- Guardar contadores (`falta_abrir`) para não varrer a matriz a cada jogada.
- Constantes nomeadas (MINA = −1, BORDA = −2, símbolos de impressão).

**Ideias de exercícios**
- Jogo da vida (vizinhos vivos 3 → nasce; 2 → mantém; resto → morre; usar duas matrizes e **trocar** em vez de copiar — em
  C, trocar ponteiros).
- Jogo da velha; batalha naval; gotas de chuva descendo na janela; flood fill com jogador automático (escolher a cor mais
  frequente na fronteira).
- Desenhar conexões entre pares de pontos com `+ - | x` minimizando cruzamentos (aberto).

---

## Obsoleto / evitar

- **Pascal em tudo:** `:=`, `begin/end`, `div/mod`, `writeln(x:0:2)`, `var` em parâmetro, retorno atribuindo ao nome da
  função, `repeat/until` (condição invertida), `case` com faixas, `with`, `string[50]`, índices arbitrários (`[-99..100]`,
  base 1), atribuição de vetor inteiro (em C não compila; para struct, sim). Traduzir para C, base 0.
- `integer` de 16 bits e "integer tem 2 bytes"; biblioteca CRT (`clrscr`, `textbackground`, `delay`); `randomize`; `goto` (o
  próprio livro desaconselha).
- Regras de Pascal ditas como gerais: "vetor sempre por referência", "array como parâmetro exige `type`"; e "recursão fora
  do escopo", "não há algoritmo eficiente para MMC" (há: via MDC, como o próprio livro faz).
- Links datados: Light-bot em Flash, vídeos do YouTube, animações de Carleton, `.pas` do site da disciplina.
- **Erros a não copiar** (bons para "ache o erro"): teste de mesa com n=5 no lugar de 8; base 3 "2101 → 65" (é 64); "145 =
  5²·7" (é 5·29); "mais jovem = Beltrano" (é Fulano); |pos/neg| impresso −1.00; soma 16+5 → "20.00" (é 29); `zerar_campo`
  sem borda; `imprimir_transposta` com `j` fora do `for`; texto × código invertidos nas bordas; `tam` × `card` no TAD
  conjunto; população dependente de interpretação; permutação por trocas aleatórias apresentada como boa (é enviesada);
  flood fill em laço infinito quando a cor escolhida é a atual; teste de permutação lendo `v[n+1]`.
- Casos de teste das listas complementares (5.11) e de vários exercícios de vetores saíram embaralhados na extração:
  conferir antes de reaproveitar.

## Recomendações

1. **Cap. 6 como roteiro do 0030**, com os padrões nomeados no curso; repetir o "esqueleto até o zero" com corpos
   diferentes, como o livro.
2. **Método "ingênuo → melhor, com custo comparado"** (inverter número, fatorial, primos, buscas, permutação) para os pares
   A(2N−1)/A(2N).
3. **Saquear o banco de exercícios** com casos de teste para os E-exercícios dos módulos 01–05 e 13, conferindo as respostas
   (há erros; as conferidas estão acima).
4. "Juntando tudo" visuais: **simulador BCC** (0005), **imagens PGM** (0044/0048), **flood fill e campo minado** com pilha
   explícita e depois recursivos (0089/0116).
5. TAD como no livro: **interface → uso (megassena, celebridade) → implementações com custos** (0079–0091).
6. Bugs do livro como "ache o erro"; a conjectura falsa das permutações como exercício de contraexemplo.
7. Licença ND: não copiar texto; reescrever e traduzir para C idiomático.
