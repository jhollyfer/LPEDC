# Fichamento — Deitel & Deitel, *C: Como Programar* (parte 1: caps. 1 a 6)

- **Obra:** Paul Deitel e Harvey Deitel, *C: Como Programar*. Trad. Daniel Vieira, rev. téc. César Caetano. São Paulo: Pearson Prentice Hall.
- **Atenção à edição:** o arquivo se chama "7ed", mas o texto lido é a **6ª edição** (Pearson BR 2011, original de 2010, 2ª reimpressão de 2014). O código foi testado em Visual C++ 2008 e GCC 4.3.
- **Trecho lido:** linhas 1 a 13034 do `.md`, lidas inteiras, mais algumas linhas além, até o começo do cap. 7. O trecho cobre a capa, o prefácio e os caps. 1 (computadores e linguagens), 2 (introdução a C), 3 (programação estruturada, if/else, while), 4 (for, switch, do-while, break/continue, operadores lógicos), 5 (funções, rand, escopo, recursão) e 6 (arrays, ordenação, busca, matrizes). Também passa pelos exercícios de cada capítulo.
- **Avaliação geral:**
  - *Pontos fortes:* todo conceito vem com um programa completo e a saída real da execução ("código vivo"). Os exemplos têm valores concretos e fáceis de reaproveitar em teste de mesa. As caixas "Erro comum de programação" formam um catálogo valioso de pegadinhas. O refinamento top-down vem com pseudocódigo (média com contador, com sentinela e com estruturas aninhadas). O livro distingue ordem de avaliação de precedência. Os exercícios são muitos e graduados, de "ache o erro" até o passeio do cavalo, as oito rainhas e o crivo.
  - *Obsoleto ou fraco:* a base é o C89. O C99 fica num apêndice opcional por causa do MSVC. Daí vem a regra "declare tudo no início do bloco". O livro não usa `for (int i...)` nem `stdbool.h` e recomenda `register`. Os nomes misturam inglês e português, e o código usa identificadores com acento (`número`, `média`). A tradução tem **erros dentro do código**: vírgula decimal (`3,446`), aspas tipográficas (“ ”) e saídas impressas como `82,50`. Há bugs de digitação nos exemplos: `aCont` declarado e `aCount` usado; `n == 0 | n == 1`; `nota` inteira impressa com `%f`. A quantidade de propaganda e links da Deitel é grande. A parte de "tendências" do cap. 1 está datada (Visual Basic, .NET, Java criando páginas dinâmicas). Strings e `fgets` só aparecem no cap. 8 (fora deste trecho). Aqui as strings são lidas com `scanf("%s")`.

---

## 00-logica

### 0001-algoritmo
**Conceitos-chave**
- Algoritmo = *ações* + *ordem* em que são executadas. Especificar essa ordem é o "controle do programa".
- Antes de codificar, é preciso entender o problema e planejar a solução. O livro defende que a parte difícil é chegar ao algoritmo certo, e que a tradução para C vem quase direto depois disso.
- Teorema de Böhm-Jacopini (1966): todo programa pode ser escrito só com três estruturas — sequência, seleção e repetição. Daí veio o movimento "programar sem `goto`".
- C tem 7 estruturas: sequência, `if`, `if…else`, `switch`, `while`, `do…while` e `for`. Todas têm entrada única e saída única. Elas se combinam de só **dois** jeitos: empilhamento (uma depois da outra) e aninhamento (uma dentro da outra).
- Em tese, `if` basta para qualquer seleção e `while` basta para qualquer repetição. Então sequência + `if` + `while` cobrem tudo.

**Analogias/explicações boas**
- **Rotina matinal com a ordem trocada:** a pessoa levanta, tira o pijama, *veste a roupa e depois toma banho* e chega encharcada ao trabalho. Mostra que os mesmos passos em outra ordem dão outro resultado.
- **Caixa de peças de montar vazias:** o programador recebe "moldes" vazios das 7 estruturas e só pode encaixá-los empilhando ou aninhando. Depois preenche os retângulos (ações) e os losangos (decisões). Blocos sobrepostos não existem em programa estruturado.
- **Lista de compras:** "enquanto houver itens na lista, compre o próximo e risque-o". Serve de ponte para o `while`.

**Ideias de exemplos**
- Pedir ao aluno que reordene passos de uma tarefa doméstica e explique o efeito de cada troca.
- Mostrar o mesmo problema (média da turma) resolvido de três formas: 10 notas fixas, número arbitrário de notas com sentinela, e contagem de aprovados e reprovados.

**Ideias de exercícios**
- Escrever em linguagem natural o algoritmo de um procedimento manual. No livro: substituir palavras com gênero num texto e decidir o que fazer com "super-homem". Resposta: discutir que substituir só a palavra inteira evita estragar palavras compostas.
- V/F: "a parte mais difícil é produzir o programa em C funcional". Resposta: falso, a parte difícil é o algoritmo.

### 0002-pseudocodigo
**Conceitos-chave**
- Pseudocódigo é uma linguagem informal, parecida com a fala do dia a dia, usada para *pensar* o programa. Não é executada.
- Contém só ações executáveis. Declarações de variáveis não são ações: são recados para o compilador. Alguns programadores listam as variáveis no topo com o propósito de cada uma.
- **Refinamento sucessivo top-down:**
  - O topo é uma frase que descreve o programa inteiro.
  - O 1º refinamento quebra o topo em tarefas, em sequência.
  - O 2º refinamento introduz as variáveis e as estruturas de controle.
  - O processo para quando já dá para traduzir linha a linha para C.
  - Cada nível é uma descrição *completa*; só muda o grau de detalhe.
- Muitos programas têm 3 fases: inicialização, processamento e finalização.

**Analogias/explicações boas**
- Recuar o corpo do "enquanto"/"se" no pseudocódigo, em vez de usar chaves, deixa a estrutura visível.

**Pegadinhas**
- Só contadores e totais precisam de inicialização. Variáveis que recebem leitura (nota, média) são sobrescritas antes do uso.

**Ideias de exemplos (com teste de mesa)**
- Média com contador: notas 98 76 71 87 83 90 57 79 82 94 → soma 817 → média inteira 81 (a real seria 81,7). Use isso para motivar o `float`.
- Média com sentinela −1: 75 94 97 88 70 64 83 89 → 82.50. Se o primeiro valor já for −1, imprime "nenhuma nota".
- Exame de corretores: 10 resultados (1 = passou, 2 = reprovou). Com mais de 8 aprovados, imprime "bônus para o instrutor". Saídas: 6/4, e 9/1 com bônus.

**Ideias de exercícios**
- Pseudocódigo para: ler 2 números e mostrar a soma; mostrar o maior ou "iguais"; somar positivos até a sentinela −1.
- Fazer o teste de mesa do loop "primeira potência de 3 maior que 100": produto = 3, 9, 27, 81, 243. Resposta: 243.

### 0003-fluxograma
**Conceitos-chave**
- Símbolos:
  - retângulo = ação (cálculo ou E/S);
  - losango = decisão, com duas saídas (verdadeiro/falso);
  - elipse = início/fim do algoritmo completo;
  - pequeno círculo = conector, usado em trechos;
  - setas = linhas de fluxo.
- Regras para gerar só fluxogramas estruturados:
  1. Comece pelo fluxograma mínimo (um retângulo).
  2. Troque um retângulo por dois em sequência (empilhamento).
  3. Troque um retângulo por qualquer estrutura de controle (aninhamento).
  4. Repita as regras 2 e 3 à vontade.
- Para saber se um fluxograma é estruturado, aplique as regras ao contrário até chegar no mínimo.

**Ideias de exercícios**
- Desenhar o fluxograma do `for (c = 1; c <= 10; c++)`. Deve aparecer que a inicialização roda uma vez e que o incremento vem depois do corpo.
- Mostrar um fluxograma com blocos sobrepostos e pedir que o aluno diga por que ele não é estruturado.

### 0004-binario
**Conceitos-chave** (o tema aparece pouco aqui; o apêndice C fica fora do trecho)
- `%p` costuma mostrar endereços em hexadecimal. Hexa usa os dígitos 0–9 e as letras A–F (10–15).
- Valor posicional: em decimal, 234 = 4·1 + 3·10 + 2·100. Em binário as casas valem 1, 2, 4, 8…

**Ideias de exercícios**
- Ler um "inteiro binário" (só 0s e 1s) e imprimir o decimal, separando os dígitos com `% 10` e `/ 10`. Exemplo: 1101 → 13.
- Tabela dos equivalentes binário, octal e hexa de 1 a 256.

### 0005-compilacao
**Conceitos-chave**
- Três níveis de linguagem, com o **mesmo cálculo** em cada um. Ótimo exemplo para reaproveitar:
  - máquina: números que somam hora extra ao salário;
  - assembly: `load salario` / `add horaExtra` / `store valorTotal`;
  - alto nível: `valorTotal = salario + horaExtra;`.
- O assembler traduz assembly; o compilador traduz linguagem de alto nível. O interpretador executa sem compilar, porém mais devagar.
- As 6 fases do livro: editar → pré-processar → compilar → ligar → carregar → executar.
  - O pré-processador obedece às linhas com `#`: inclui arquivos e substitui texto.
  - O compilador gera código objeto, que fica com "buracos" nas chamadas a funções de biblioteca.
  - O ligador (linker) preenche esses buracos e gera o executável.
  - O carregador põe o executável na memória.
  - A CPU executa uma instrução por vez.
- `cc arquivo.c` gera `a.out` e `./a.out` executa. Use `-lm` para ligar a biblioteca matemática.
- Fluxos padrão: `stdin` (teclado), `stdout` (tela) e `stderr` (erros). Dá para redirecionar `stdout` e manter os erros na tela.
- História: BCPL (1967) → B (Thompson, sem tipos, uma "palavra" por dado) → C (Ritchie, 1972, PDP-11, acrescentou tipos). Depois vieram o K&R (1978), o ANSI (1989) e o C99.

**Analogias/explicações boas**
- **Erro de digitação em `printf` (escrito `print`) é pego pelo linker, não pelo compilador.** O compilador só reserva espaço para "chamar algo". Quem procura a função na biblioteca é o ligador. Ótimo para ensinar a separar as fases. Nota moderna: o gcc atual já avisa "implicit declaration" na compilação.
- Tipos de erro: sintaxe/compilação (o compilador acusa); execução, que pode ser fatal (aborta, como a divisão por zero) ou não fatal (roda e dá resultado errado). O livro defende que o erro fatal é preferível, porque aparece.
- **"O compilador é um bom professor":** na dúvida sobre um recurso, escreva um programa pequeno e veja o que acontece.

**Ideias de exercícios**
- Associar cada fase ao programa responsável: editor, pré-processador, compilador, ligador, carregador.
- Explicar por que alguém escreveria em linguagem dependente de máquina. Resposta esperada: acesso direto ao hardware e desempenho.

---

## 01-fundamentos

### 0006-primeiro-programa
**Conceitos-chave**
- Esqueleto: comentário, `#include <stdio.h>`, `int main(void) { … return 0; }`.
- `#include` traz para o arquivo o cabeçalho com as informações (protótipos) que o compilador usa para conferir as chamadas a `printf`.
- `int` antes de `main` diz que ela devolve um inteiro ao sistema operacional (0 = sucesso). `void` diz que ela não recebe nada.
- Toda instrução termina em `;`. As chaves delimitam o corpo, que é um bloco.
- Comentários `/* */`. O `//` veio do C++ e entrou no C99. Comentários não geram código.
- `printf` continua de onde o cursor parou. Dois `printf` podem montar uma linha só; um `printf` com vários `\n` imprime várias linhas.
- Biblioteca padrão: aprender C é aprender a linguagem *e* a biblioteca. Reaproveite em vez de "reinventar a roda".
- Palavras-chave são todas minúsculas. Tabela do C89 mais as do C99: `_Bool _Complex _Imaginary inline restrict`.

**Pegadinhas e erros comuns**
- Esquecer de fechar `*/`, ou escrever `*/ … /*` invertido.
- Escrever `Main` ou `While` com maiúscula, já que C diferencia maiúsculas de minúsculas.
- Colocar `\n` fora das aspas.

**Ideias de exercícios**
- Imprimir os números de 1 a 4 na mesma linha de 3 jeitos: um `printf` sem especificadores, um `printf` com 4 `%d`, e 4 `printf`.
- V/F: "um programa que imprime 3 linhas precisa de 3 `printf`". Resposta: falso.
- Desenhar formas com asteriscos (retângulo, oval, seta, losango) usando só `printf`. Prever a saída de `printf("*\n**\n***\n****\n*****\n")`.
- Imprimir as próprias iniciais em letras grandes formadas pela própria letra.

### 0007-variaveis
**Conceitos-chave**
- Variável = posição de memória com **nome, tipo e valor**.
- Identificador: letras, dígitos e `_`, sem começar por dígito. O C89 só garante 31 caracteres significativos.
- Evite nomes que começam com `_`, porque a implementação usa esses nomes. Prefira camelCase ou `com_sublinhado` e nomes que se explicam sozinhos.
- `int`, `float` (cap. 3), `double` (cap. 4: mais faixa e mais precisão), `char` (cap. 4).

**Analogias/explicações boas**
- **Escrita destrutiva, leitura não destrutiva:** colocar um valor numa posição apaga o anterior; ler não altera nada. Com as "caixinhas" `inteiro1 = 45`, `inteiro2 = 72` e `soma = 117`, ler 45 e 72 para somar não os destrói. Ótima imagem para a aula.

**Pegadinhas**
- Variável não inicializada contém **lixo**: o último valor que ocupava aquela memória.
- O livro manda declarar tudo antes de qualquer instrução, uma regra do C89. Em C99+ pode-se declarar perto do uso. Avisar o aluno.

**Ideias de exercícios**
- Classificar identificadores como válidos ou inválidos. `_sub_barra_`, `m928134`, `t5`, `j7`, `suas_vendas`, `z2` são válidos. `3g`, `87`, `67h2` e `2h` são inválidos. **`h22` é válido** — essa é a pegadinha do item.
- V/F: "`numero` e `NuMeRo` são a mesma variável". Resposta: falso.

### 0008-tipos-e-limites
**Conceitos-chave**
- Faixas mínimas garantidas pelo padrão:
  - `short`: −32768..32767;
  - `long`: −2147483648..2147483647;
  - `short ≤ int ≤ long`;
  - `signed char`: −128..127;
  - `unsigned` de 2 bytes: 0..65535; de 4 bytes: 0..4294967295.
- O tamanho exato depende da máquina. O cabeçalho `<limits.h>` traz os limites e `<float.h>` traz os do ponto flutuante (citados na tabela de cabeçalhos).
- O fatorial estoura rápido. O livro usa `long` com `%ld` para 0! a 10! (10! = 3628800) e comenta que nem `long` resolve por muito tempo.

**Ideias de exercícios**
- "Que dificuldade impede calcular 20!?" Resposta: overflow.
- Loop infinito imprimindo 2, 4, 8, 16… e perguntar o que acontece. Resposta: o valor estoura e vira negativo ou zero; ótimo gancho para o overflow.
- Fibonacci com `int` e depois com `double`, até falhar.

### 0009-constantes
**Conceitos-chave**
- Sequências de escape: `\n`, `\t`, `\a` (alerta sonoro), `\\` e `\"`.
- `#define TAMANHO 10` cria uma constante simbólica. O pré-processador **troca o texto** antes de compilar; a constante não ocupa memória.
- Usar uma constante para o tamanho torna o programa "escalável": muda-se num lugar só. A convenção é MAIÚSCULAS, com `_` entre palavras.
- Constante de caractere vai entre apóstrofos (`'A'`). Entre aspas é string (`"A"`).

**Pegadinhas**
- `#define SIZE 10;`: o `;` vira parte do texto substituído e quebra o código em lugares inesperados. O mesmo vale para `#include <stdio.h>;`.
- `#define VALOR = 120` está errado: não leva `=`.
- `SIZE = 10;` no meio do código é erro, porque a constante não é variável.

### 0010-printf
**Conceitos-chave**
- A string de formato mistura texto literal e especificadores, e cada especificador consome um argumento.
- Especificadores: `%d`; `%f` (precisão padrão de 6 casas); `%.2f` arredonda **só na exibição**, sem mudar o valor na memória; `%c`; `%s`; `%p`; `%u`; `%ld`; `%hd`; `%Lf`.
- Largura: `%21.2f` alinha à direita num campo de 21. Com `-` alinha à esquerda (`%-6d`, `%-8s`, `%-15.2f`). Útil para tabelas com pontos decimais alinhados.

**Pegadinhas**
- Colocar `&` antes da variável no `printf` está errado (no `scanf` é o contrário).
- Vírgula dentro das aspas; esquecer o `%`; especificador sem argumento correspondente.

**Ideias de exercícios (com resposta)**
- `printf("%.2f", 123.4567)` → `123.46`; `"%.3f"` de 3.14159 → `3.142`.
- 333.546372 com `%-15.1f` até `%-15.5f` → 333.5, 333.55, 333.546, 333.5464, 333.54637.
- `printf("%10.2f", pow(2.5, 3))` → `15.63`.
- Com x = 2 e y = 3, o que cada linha imprime: `"%d"` → x; `"x="` → texto; `"%d = %d", x+y, y+x` → `5 = 5`; `z = x + y;` → nada; um `printf` comentado → nada.
- Tabela de quadrados e cubos de 0 a 10 com `\t`, e tabela N, 10N, 100N, 1000N.

### 0011-scanf
**Conceitos-chave**
- `scanf("%d", &x)`: o `&` informa **onde** guardar o valor. A explicação completa fica para os ponteiros.
- Vários valores numa chamada: `"%d%d%d"`.
- A tabela de conversões mostra que `double` se lê com **`%lf`** e se imprime com `%f`. Ótimo para avisar o aluno.
- Nota de rodapé: `scanf` devolve um valor que diz se a leitura deu certo, e em código de produção esse retorno deve ser testado.

**Pegadinhas**
- Esquecer o `&` provoca falha de segmentação ou violação de acesso.
- Usar precisão no `scanf` (`"%.4f"`) está errado: precisão só existe no `printf`.
- Vírgulas entre os especificadores do `scanf`.
- **Sobra no buffer:** ler um inteiro com `scanf` e depois um caractere com `getchar` (usuário digita `100 A`) faz o `getchar` pegar o espaço ou o `\n`, não o `A` (exercício 4.5c). No `switch` de notas, o livro trata `'\n'`, `'\t'` e `' '` com `case` próprios para não exibir "nota inválida" a cada Enter.

### 0012-aritmetica
**Conceitos-chave**
- Operadores `+ - * / %`. Divisão entre inteiros **trunca**: 7/4 = 1 e 17/5 = 3. `%` dá o resto e só vale para inteiros: 7%4 = 3 e 17%5 = 2.
- Expressões em formato de linha: `ab` vira um identificador, então escreva `a * b`. Não existe operador de potência.
- Precedência: `()` primeiro; depois `* / %` da esquerda para a direita; depois `+ -`. A atribuição vem por último e associa da direita para a esquerda.
- Parênteses redundantes são bem-vindos quando deixam a expressão mais clara.

**Analogias/explicações boas**
- Polinômio `y = a*x*x + b*x + c` com a = 2, b = 3, c = 7, x = 5, passo a passo: 2·5 = 10, 10·5 = 50, 3·5 = 15, 50 + 15 = 65, 65 + 7 = 72. Mostrar a ordem numerada de cada operador.
- Média de 5 termos: sem parênteses, `a+b+c+d+e/5` divide só o `e`.

**Pegadinhas**
- Divisão por zero normalmente é erro fatal. Teste antes de dividir (o livro checa `contador != 0`).

**Ideias de exercícios (com resposta)**
- `x = 7 + 3 * 6 / 2 - 1` → 15; `x = 2 % 2 + 2 * 2 - 2 / 2` → 3; `x = (3 * 9 * (3 + (9 * 3 / (3))))` → 324.
- Para y = ax³ + 7, quais formas estão certas? `a*x*x*x+7`, `(a*x)*x*x+7` e `a*(x*x*x)+7` estão; as que põem `(x+7)` ou `(x*x+7)` não.
- Separar os dígitos de um número de 5 dígitos com `/` e `%`: 42139 → `4   2   1   3   9`. Também: testar palíndromo de 5 dígitos (12321, 55555, 45554, 11611); contar quantos 7 um número tem; inverter dígitos (7631 → 1367).
- Par ou ímpar com `%`; "o 1º é múltiplo do 2º?".
- Ler 3 inteiros e mostrar soma, média, produto, menor e maior. Com 13 27 14: soma 54, média 18, produto 4914, menor 13, maior 27. Usar só `if` simples.
- Criptografia de 4 dígitos: troque cada dígito por (dígito + 7) % 10, depois troque o 1º com o 3º e o 2º com o 4º. Fazer também o decodificador.

### 0013-conversao
**Conceitos-chave**
- `int/int` dá `int` mesmo que o resultado vá para um `float`: o truncamento acontece antes da atribuição.
- Cast `(float) total / contador` cria uma cópia temporária em float. A variável original não muda.
- Promoção implícita: em expressões de tipo misto, os operandos sobem para o tipo "maior". A hierarquia é: long double > double > float > unsigned long > long > unsigned > int > unsigned short > short > char.
- O cast é unário e tem precedência maior que `* / %`.
- **Coerção de argumentos** pelo protótipo: `sqrt(4)` funciona e dá 2.000. Já `quadrado(4.5)`, com parâmetro `int`, devolve 16 e não 20.25. Conversão para um tipo "menor" perde informação.

**Pegadinhas**
- O ponto flutuante é aproximado. Não compare com `==` e não controle loops com float: `for (y = .1; y != 1.0; y += .1)` pode nunca parar. Corrija com contador inteiro e `(float) i / 10`.
- **Dinheiro em float/double:** 14.234 + 18.673 aparecem como 14.23 + 18.67 = 32.91, quando a soma dos valores exibidos daria 32.90. A sugestão do livro é trabalhar em centavos inteiros e usar `/` e `%` para separar reais e centavos (exercício 4.23).
- Outros exemplos do livro: 10/3 = 3,333… não cabe em espaço finito; o termômetro marca "36,7" mas o valor real é 36,6999…

### 0014-atribuicao
**Conceitos-chave**
- `x op= expr` equivale a `x = x op expr`. Com c = 3, d = 5, e = 4, f = 6, g = 12: `c += 7` → 10; `d -= 4` → 1; `e *= 5` → 20; `f /= 3` → 2; `g %= 9` → 3.
- Pré-incremento (`++c`) incrementa e depois usa o valor; pós-incremento (`c++`) usa o valor e depois incrementa. Sozinhos numa linha, os dois têm o mesmo efeito.
- Toda atribuição tem um valor, por isso `a = b = c = 0` funciona (associa da direita para a esquerda).
- lvalue (o que pode ficar à esquerda do `=`) e rvalue.

**Exemplo canônico (com saída)**
- `c = 5`; imprime `c` (5), `c++` (5), `c` (6). Depois `c = 5`; imprime `c` (5), `++c` (6), `c` (6).

**Pegadinhas**
- `++(x + 1)` é erro: `++` só se aplica a variável.
- **Ordem de avaliação não especificada:** não use a mesma variável incrementada duas vezes na mesma expressão. O padrão só garante a ordem dos operandos de `&&`, `||`, `?:` e vírgula. As vírgulas que separam argumentos de função *não* são o operador vírgula.

**Ideias de exercícios (com resposta)**
- Quatro formas de somar 1 a x: `x = x + 1`, `x += 1`, `++x` e `x++`.
- `z = x++ + y;` · `total -= --x;` · `total += x--;` · `q %= divisor`.
- produto = 5 e x = 5; depois de `produto *= x++;` → produto 25, x 6.

### 0015-math
**Conceitos-chave**
- `#include <math.h>` e, no Linux, `-lm`. As funções recebem e devolvem `double`.
- Tabela de casos de teste com valores:
  - `sqrt(900.0)` = 30; `exp(1.0)` = 2.718282; `log(7.389056)` = 2; `log10(100)` = 2;
  - `fabs(-13.5)` = 13.5;
  - `ceil(9.2)` = 10 e `ceil(-9.8)` = −9; `floor(9.2)` = 9 e `floor(-9.8)` = −10;
  - `pow(2,7)` = 128; `pow(9,.5)` = 3; `fmod(13.657, 2.333)` ≈ 1.992;
  - `sin`, `cos` e `tan` trabalham em radianos.
- `sqrt(c1 + d*f)` com 13 + 3·4 = 25 → 5.00: o argumento pode ser uma expressão.
- Arredondar: `floor(x + .5)`; até centésimos, `floor(x * 100 + .5) / 100`. O exercício 5.11 do livro tem um erro de digitação: `x*10+5`.

**Pegadinhas**
- O livro diz que, sem `math.h`, "o linker não acharia `pow`". A explicação é imprecisa: o cabeçalho dá o **protótipo** (tipos e conversão de `int` para `double`), e quem resolve a ligação é o `-lm`. Ensinar a versão correta.
- Os valores negativos em `ceil` e `floor` são o ponto que o aluno erra.

**Ideias de exercícios (com resposta)**
- `x = ceil(-fabs(-8 + floor(-5.5)))` → floor(−5.5) = −6; −8 − 6 = −14; fabs = 14; com o sinal, −14; ceil(−14) = **−14**.
- Juros compostos: R$ 1000 a 5% ao ano por 10 anos, com `pow(1.0 + taxa, ano)`. Ano 1 = 1050.00 … ano 10 = 1628.89. Variar a taxa de 5% a 10%.
- Hipotenusa: (3,4) → 5; (5,12) → 13; (8,15) → 17. Distância entre dois pontos.

### 0016-juntando-tudo (ideias de programa de módulo)
- Calculadora de IMC (peso / altura²) com a tabela de faixas: abaixo de 18,5; 18,5–24,9; 25–29,9; 30 ou mais.
- Custo diário do carro para avaliar carona solidária: km por dia, preço do litro, km/l, estacionamento e pedágio.
- Círculo: diâmetro, circunferência e área com π = 3.14159.
- Tabela de códigos de caracteres: `printf("%d", 'A')` para A B C a b c 0 1 2 $ * + / e espaço.

---

## 02-condicionais

### 0017-relacionais
**Conceitos-chave**
- Operadores `== != > < >= <=`. Os relacionais têm precedência maior que os de igualdade, e todos associam da esquerda para a direita.
- Em C, a condição é qualquer expressão: 0 é falso e qualquer outro valor é verdadeiro. Comparações e operações lógicas **produzem 0 ou 1**.
- Programa-modelo: ler dois números e aplicar 6 `if`. Entradas: 3 7 → "não é igual", "é menor", "é menor ou igual"; 22 12; 7 7.

**Pegadinhas**
- Espaço dentro do operador (`= =`) e operador invertido (`=!`, `=>`, `=<`) dão erro de sintaxe.

**Ideias de exercícios (com resposta)**
- Com i = 1, j = 2, k = 3, m = 2: `i == 1` → 1; `j == 3` → 0; `i >= 1 && j < 4` → 1; `m <= 99 && k < m` → 0; `j >= i || k == m` → 1; `k + m < j || 3 - j >= k` → 0; `!m` → 0; `!(j - m)` → 1; `!(k > m)` → 0; `!(j > k)` → 1.

### 0018-logicos
**Conceitos-chave**
- `&&`, `||` e `!` com tabelas-verdade de 0 / "não zero". `&&` tem precedência maior que `||`. `!` é unário, com precedência alta, e por isso pede parênteses: `!(nota == sentinela)`. Muitas vezes dá para trocar por `!=`.
- **Curto-circuito:** a avaliação para assim que o resultado é conhecido.
- Dica de desempenho do livro: em `&&`, ponha à esquerda a condição mais provável de ser falsa; em `||`, a mais provável de ser verdadeira.
- Exemplos: `sexo == 1 && idade >= 65` conta idosas; `mediaSemestre >= 90 || exameFinal >= 90` dá conceito A.

**Ideias de exercícios**
- Leis de De Morgan: reescrever e testar por programa `!(x < 5) && !(y >= 7)`, `!(a == b) || !(g != 5)`, `!((x <= 8) && (y > 4))` e `!((i > 4) || (j <= 6))`.
- Completar as tabelas-verdade de `&&`, `||` e `!`.
- Triângulo: três lados (diferentes de zero) formam triângulo? E triângulo retângulo?

### 0019-if / 0020-if-else
**Conceitos-chave**
- `if` = seleção única; `if…else` = seleção dupla. Sem chaves, o corpo é **uma** instrução. Um bloco `{}` vale como uma instrução em qualquer lugar.
- Instrução vazia: um `;` sozinho.
- Recuo consistente; o livro sugere 3 espaços.

**Analogias/explicações boas**
- Leia `=` como "recebe" e `==` como "é igual a" (ou "dois iguais").

**Pegadinhas e erros comuns** (seção inteira do livro só sobre `==` e `=`)
- `if (codPgto = 4)` compila, sempre dá "bônus" e ainda altera `codPgto`. O motivo: atribuição tem valor e qualquer valor diferente de zero é verdadeiro.
- O truque de pôr a constante à esquerda (`7 == x`) faz o erro virar erro de compilação.
- O contrário também engana: `x == 1;` sozinho não faz nada. O valor se perde, e alguns compiladores avisam.
- Dica do livro: depois de escrever o programa, procure cada `=` e confira.
- `;` logo após `if (cond)`: o corpo vira a instrução vazia e o `printf` seguinte roda sempre. No `if` simples é erro de lógica; com `else` vira erro de sintaxe.
- Esquecer as chaves no `else`: só a primeira instrução fica dentro. Exemplo do livro: "Reprovado." e "Você precisa refazer o curso." — a segunda frase sairia sempre.
- Dica: digite `{` e `}` antes de escrever o conteúdo.

**Ideias de exercícios**
- Achar e corrigir os erros: `if (c < 7);{…}`, `if (c => 7)`, `if (idade >= 65); … else …`, `if (x = y);`.
- Maior de dois números, ou "esses números são iguais", usando só `if`. Maior e menor de 5 números só com `if`.

### 0021-else-if
**Conceitos-chave**
- Notas 90/80/70/60 → A/B/C/D/F. A versão em escada aninhada e a forma `else if` são equivalentes para o compilador. A segunda evita o recuo que empurra o código para a direita.
- Se a nota é ≥ 90, as 4 condições são verdadeiras, mas só o primeiro ramo executa.
- **Else pendurado:** o `else` sempre se liga ao `if` anterior mais próximo, e o recuo não muda isso. Só as chaves mudam.

**Ideias de exercícios (com resposta)**
- Exercício 3.31: prever a saída de
  `if (x < 10) if (y > 10) printf("*****\n"); else printf("#####\n"); printf("$$$$$\n");`
  e da versão com chaves, para (x = 9, y = 11) e (x = 11, y = 9).
  - Sem chaves: x = 9, y = 11 imprime `*****` e `$$$$$`; x = 11, y = 9 imprime só `$$$$$`.
  - Com chaves no `else` do `if` externo: x = 9, y = 11 imprime `*****`; x = 11, y = 9 imprime `#####` e `$$$$$`.
- Exercício 3.32: inserir chaves num `if (y == 8) if (x == 5) … else …` para obter 4 saídas pedidas: `@@@@@ $$$$$ &&&&&`, só `@@@@@`, `@@@@@ &&&&&`, e com y = 7 `##### $$$$$ &&&&&`.
- Função `qualityPoints`: média 90–100 → 4, 80–89 → 3, 70–79 → 2, 60–69 → 1, abaixo de 60 → 0.

### 0022-ternario
**Conceitos-chave**
- É o único operador ternário. `printf("%s\n", nota >= 60 ? "Aprovado" : "Reprovado");` cabe onde um `if` não cabe (dentro de uma expressão). Os operandos também podem ser ações: `cond ? printf(...) : printf(...)`.
- Garante a ordem: avalia a condição primeiro e depois **só um** dos ramos.

**Ideias de exercícios**
- Prever a saída de `printf("%s\n", contador % 2 ? "****" : "++++++++");` com o contador indo de 1 a 10: as linhas se alternam.
- Laço aninhado com `linha % 2 ? "<" : ">"` (exercício 3.30).

### 0023-switch
**Conceitos-chave**
- Uma expressão de controle comparada com rótulos `case`, que só aceitam **expressão inteira constante** (constantes de caractere valem). `default` é opcional e recomendado por último; nele o `break` é opcional.
- Vários `case` empilhados compartilham as mesmas ações (`case 'A': case 'a':`). Não precisa de chaves para várias ações num `case`.
- `break` sai do `switch`. Sem ele, a execução **cai** nos `case` seguintes (fall-through). O livro brinca que isso só serve para canção cumulativa.
- Exemplo central: contar conceitos A–F lidos com `getchar` até EOF, ignorando `\n`, `\t` e espaço.
  - Entrada `a b c C A d f C E D A b` → A 3, B 2, C 3, D 2, F 1, com uma mensagem de nota inválida para o `E`.
  - Atenção: o código do livro declara `aCont` e incrementa `aCount` — bug de tradução.
- Na seção de aleatórios, o `switch` de 6 casos para contar faces do dado vira, no cap. 6, `++frequencia[face]`. Ótimo "antes e depois".

**Pegadinhas**
- Esquecer o `break` é erro de lógica. Exercício: no `switch (valor % 2)` sem `break`, o caso par imprime também "ímpar".

**Ideias de exercícios**
- Vendas: preço por produto (1 a 5: 2,98; 4,50; 9,98; 4,49; 6,87) escolhido no `switch`, somando a quantidade vendida.
- Folha de pagamento por código: gerente (fixo); horista (1,5× acima de 40 h); comissionado (250 + 5,7%); por peça.
- Reescrever o `switch` de notas com `if…else` aninhado e depois só com `if` (o `default` fica mais difícil). Mostra que o `switch` é conveniência.

### 0024-juntando-tudo (ideias)
- Programa de notas por conceito (o do `switch`) mais a média da turma (exercício 4.22).
- Calculadoras do cap. 3, todas com sentinela −1:
  - consumo de combustível: litros e km por tanque, mais o consumo geral (287 km / 25,6 l = 11,21 km/l…);
  - limite de crédito: saldo + encargos − créditos, comparado ao limite;
  - comissão: 200 + 9% das vendas (5000 → 650; 1234,56 → 311,11);
  - juros simples: principal·taxa·dias/365 (1000; 0,1; 365 → 100);
  - salário com hora extra: 39 h → 390; 40 h → 400; 41 h → 415, a R$ 10/h.

---

## 03-repeticoes

### 0025-while
**Conceitos-chave**
- Repete enquanto a condição for verdadeira. Algo no corpo precisa tornar a condição falsa, senão o loop é infinito.
- Repetição controlada por contador (definida) e por sentinela (indefinida).
- Contador exige 4 coisas: nome, valor inicial, incremento e condição de valor final.
- Forma condensada `while (++contador <= 10) printf(...)`: funciona, mas o livro admite que fica enigmática.

**Pegadinhas**
- Sem chaves no `while` da média com sentinela, só a soma fica no loop, a nova leitura fica fora, e o loop vira infinito.
- `;` logo depois de `while (x <= 10);` produz loop infinito.
- `while (z >= 0) soma += z;` sem decrementar `z`.
- `while (y > 0) { …; ++y; }` anda na direção errada.

**Ideias de exercícios**
- Soma de 1 a 10 com `while`. Potência x^y com `while` (o exercício 3.8 já traz a solução).
- Prever a saída do programa que imprime os quadrados de 1 a 10 e o total, 385.

### 0026-do-while
**Conceitos-chave**
- Testa no fim, então executa pelo menos uma vez. Use sempre chaves, para que o `while (cond);` final não pareça um `while` com corpo vazio.

**Ideias de exercícios**
- Validação: refazer o programa do exame de corretores aceitando só 1 ou 2, repetindo a pergunta até vir um valor válido (exercício 3.28).
- Converter `do…while` em `while` e vice-versa. Que problema aparece quando a condição é falsa logo de início? Resposta: o `do…while` executaria o corpo uma vez a mais; é preciso um `if` antes.

### 0027-for
**Conceitos-chave**
- `for (expr1; expr2; expr3)` equivale a `expr1; while (expr2) { corpo; expr3; }`. A exceção é o `continue`: no `for` ele executa o incremento; numa tradução literal em `while` ele pula o incremento.
- As 3 expressões são opcionais; sem `expr2` o loop é infinito. As expressões podem ser aritméticas: com x = 2 e y = 10, `for (j = x; j <= 4*x*y; j += y/x)` é o mesmo que `for (j = 2; j <= 80; j += 5)`.
- Operador vírgula: avalia da esquerda para a direita e vale o último valor. Serve para duas variáveis de controle. O livro desaconselha encher o cabeçalho com o corpo do laço.
- Se a condição já começa falsa, o corpo não executa.
- Evite alterar a variável de controle dentro do corpo.

**Pegadinhas**
- **Erro de diferença por um (off-by-one):** `< 10` em vez de `<= 10`. O livro sugere usar o valor final com `<=`.
- Vírgula no lugar de `;` no cabeçalho. `;` logo após `for(...)` deixa o corpo vazio.

**Ideias de exercícios (com resposta)**
- Escrever os cabeçalhos: 1..100; 100..1; 7..77 de 7 em 7; 20..2 de −2 em −2; 2, 5, 8, …, 17; 44, 33, …, 0.
- O que estes laços imprimem: `x = 2; x <= 13; x += 2` → 2 4 6 8 10 12; `x = 5; x <= 22; x += 7` → 5 12 19; `x = 3; x <= 15; x += 3` → 3 6 9 12 15; `x = 1; x <= 5; x += 7` → 1; `x = 12; x >= 2; x -= 3` → 12 9 6 3.
- Gerar as sequências 1..7; 3, 8, …, 23; 20, 14, …, −10; 19, 27, …, 51.
- Soma dos pares de 2 a 100 = 2550; pares de 2 a 30 = 240; produto dos ímpares de 1 a 15 = 2027025; ímpares de 1 a 99 com `for`.
- Achar os erros: `For (x = 100, x >= 1, x++)`; `for (x = 999; x >= 1; x += 2)` (infinito); `for (x = 100; x <= 150; x++); { total += x; }`.

### 0028-break-continue
**Conceitos-chave**
- `break` num laço com `x == 5` imprime `1 2 3 4` e "saiu em x == 5". `continue` com `x == 5` imprime `1 2 3 4 6 7 8 9 10`.
- O livro registra que há quem considere `break` e `continue` não estruturados. Exercícios 4.35 e 4.37: removê-los usando uma flag na condição do laço.

### 0029-lacos-aninhados
**Ideias de exemplos e exercícios**
- Retângulo de `@` com x colunas e y linhas (exercício 4.8). Quadrado cheio de lado 1..20 e quadrado só com a borda.
- Os 4 triângulos de `*` só com `printf("*")` e espaços. Losango de 9 linhas e losango de tamanho ímpar lido.
- Tabuleiro de xadrez com só 3 `printf` (`"* "`, `" "`, `"\n"`). Cem asteriscos com quebra a cada 10 (`% 10`).
- Histograma: para cada número lido de 1 a 30, uma barra de `*` daquele tamanho.
- Força bruta: triplas pitagóricas até 500 com três `for` aninhados.

### 0030-padroes-de-laco
**Conceitos-chave**
- **Contador** começa em 0 ou 1 conforme o uso. **Total (acumulador)** começa em 0; se não for inicializado, carrega o lixo da memória.
- **Sentinela:** precisa ser um valor impossível nos dados (−1 para notas, 9999 no exercício 4.10). O prompt deve **lembrar** ao usuário qual é a sentinela. "Ler a primeira antes do laço e a próxima no fim do corpo" é o padrão de leitura antecipada.
- **Maior e menor:** variáveis `contador`, `numero` e `maior` (exercício 3.24). Dois maiores entre 10 números lendo cada um só uma vez (exercício 3.27).
- Primeiro valor lido indicando quantos vêm depois: entrada `5 100 200 300 400 500` → soma.
- Média com sentinela: `10 8 11 7 9 9999` → 9.

**Analogias**
- Termos do livro: valor sentinela = "sinalizador" ou "flag".

### 0031-aleatorios
**Conceitos-chave**
- `rand()` (em `<stdlib.h>`) devolve de 0 a `RAND_MAX`, que vale pelo menos 32767.
- Escala e deslocamento: `n = a + rand() % b`, com `a` = primeiro valor da faixa e `b` = largura da faixa. Dado: `1 + rand() % 6`.
- Os números são **pseudoaleatórios**: sem semente, a sequência é a mesma a cada execução. Isso é útil para depurar.
- `srand(semente)` recebe um `unsigned` (lido com `%u`); a mesma semente repete a sequência (67 → mesma sequência). `srand(time(NULL))` usa os segundos desde 1/1/1970 (`<time.h>`).
- 6000 lançamentos dão cerca de 1000 por face.

**Pegadinhas**
- Usar `srand` no lugar de `rand`, ou `int r = srand();` (`srand` é `void`). Chame `srand` uma vez só, no começo.

**Ideias de exercícios (com resposta)**
- Faixas: 1..2 → `1 + rand() % 2`; 1..100; 0..9 → `rand() % 10`; 1000..1112 → `1000 + rand() % 113`; −1..1 → `-1 + rand() % 3`; −3..11 → `-3 + rand() % 15`.
- Conjuntos: {2,4,6,8,10} → `2 + 2 * (rand() % 5)`; {3,5,7,9,11} → `3 + 2 * (rand() % 5)`; {6,10,14,18,22} → `6 + 4 * (rand() % 5)`.
- Moeda com função `flip()` lançada 100 vezes (cerca de 50/50). Dois dados 36.000 vezes: a soma 7 aparece em cerca de 1/6, conforme a tabela 6×6 de combinações.
- "Adivinhe o número" de 1 a 1000 com "muito alto/baixo": com boa estratégia, 10 tentativas bastam porque 2¹⁰ = 1024. É a busca binária intuitiva.
- Treino de tabuada com mensagens variadas escolhidas por `rand()` dentro de `switch`, 75% de acerto para "passar de nível", níveis de dificuldade e tipos de operação (exercícios 5.50–5.54).

### 0032-juntando-tudo (ideias)
- **Craps** como projeto do módulo:
  - Regras: 7 ou 11 no 1º lançamento vence; 2, 3 ou 12 perde; outra soma vira o "ponto", e o jogador relança até tirar o ponto (vence) ou 7 (perde).
  - Estrutura: `enum Status {CONTINUE, WON, LOST}`, uma função que lança os dois dados, um `switch` para o 1º lançamento e um `while` para os seguintes.
  - Extensões: apostas com banca de 1000 e mensagens de "conversa" (exercício 5.47); 1000 partidas automáticas com estatísticas — em que lançamento ganha ou perde, média de lançamentos, chance de vitória (exercício 6.20).

---

## 04-funcoes

### 0033-funcoes
**Conceitos-chave**
- Motivos para modularizar: dividir para conquistar, reutilizar, abstrair (usar sem saber como funciona por dentro) e evitar código repetido.
- Uma função faz **uma** tarefa, e o nome a descreve. Se não dá para achar um nome curto, ela está fazendo coisas demais: decomponha. O livro sugere funções de até meia página e cabeçalho numa linha; muitos parâmetros indicam tarefa demais. `main` deve ser basicamente uma sequência de chamadas.
- Definição: `tipo nome(parâmetros) { declarações; instruções }`. Três formas de voltar: chegar à `}`, `return;` e `return expr;`.
- **Protótipo:** diz o tipo de retorno e o número, os tipos e a ordem dos parâmetros. O compilador confere as chamadas por ele, e chamadas que não batem dão erro.
  - Os nomes no protótipo são opcionais; o livro prefere colocá-los para documentar.
  - Sem protótipo, o compilador "inventa" um a partir do primeiro uso.
  - Um protótipo dentro de uma função só vale ali.
  - O livro conta que o protótipo veio do C++.
- Exemplos: `quadrado` de 1 a 10 (1 4 9 … 100); `maximo(22, 85, 17)` em qualquer ordem dá 85; `rolarDados(void)` chamada de dois lugares.

**Analogias/explicações boas**
- **Chefe e trabalhadoras:** a função chamadora pede uma tarefa, a chamada executa e "presta contas" (retorna). O chefe não sabe *como* foi feito, e uma trabalhadora pode delegar a outras. Ocultação de informação.

**Pegadinhas e erros comuns**
- Esquecer o `return` numa função não `void` (comportamento indefinido). Devolver valor numa função `void`.
- Parâmetros escritos `double x, y` (cada parâmetro precisa do próprio tipo).
- `;` depois do `)` na definição. Esquecer o `;` no protótipo.
- Redeclarar um parâmetro como variável local. Definir uma função dentro de outra.
- Protótipo diferente da definição (por exemplo, `void` × `int`).

**Ideias de exercícios**
- Escrever cabeçalhos e protótipos: `double hipotenusa(double l1, double l2)`, `int menor(int x, int y, int z)`, `void instrucoes(void)`, `float intParaFloat(int n)`.
- Funções curtas:
  - `potenciaInt(base, exp)` com `for`; `multiplo(a, b)` e `par(n)` devolvendo 1 ou 0; quadrado de caractere preenchido com `side` e `fillCharacter`;
  - segundos desde as 12h; Celsius↔Fahrenheit; menor de 3 floats;
  - número perfeito (6, 28, 496); primo testando até √n e não até n/2 (por quê?); MDC;
  - estacionamento: R$ 2 até 3 h, mais R$ 0,50 por hora ou fração, teto de R$ 10. 1,5 h → 2,00; 4 h → 2,50; 24 h → 10,00; total 14,50.

### 0034-parametros
**Conceitos-chave**
- Em C **toda passagem é por valor**: o parâmetro recebe uma cópia, e mexer nela não afeta o original. A "referência" se simula com ponteiros (cap. 7).
- Use passagem por valor sempre que a função não precisar alterar o original; isso evita efeitos colaterais.
- `void` na lista indica que a função não tem parâmetros.
- Prefira nomes diferentes para o argumento e o parâmetro, para não confundir.

### 0035-escopo
**Conceitos-chave**
- Atributos de um identificador: classe de armazenamento, duração, escopo e vinculação.
- Duração automática: a variável nasce ao entrar no bloco e morre ao sair (locais e parâmetros). Duração estática: existe do início ao fim do programa (globais e `static` locais).
- Escopo e duração são coisas diferentes. Uma `static` local vive o programa todo, mas só é visível no bloco.
- 4 escopos: de função (só rótulos, como `inicio:` e `case`), de arquivo (globais, funções, protótipos), de bloco (locais) e de protótipo (nomes na lista de parâmetros do protótipo).
- Um identificador num bloco interno **oculta** o de mesmo nome do bloco externo (sombreamento).
- Estáticos numéricos não inicializados começam em zero. Automáticos começam com lixo.
- Evite globais: qualquer função pode alterá-las sem querer. Princípio do menor privilégio.

**Exemplo canônico (prever a saída)**
- Global `x = 1`; em `main`, `x = 5`; num bloco interno, `x = 7`. Três funções chamadas duas vezes cada:
  - `usaLocal` (local 25 → 26) imprime 25→26 nas duas chamadas;
  - `usaStaticLocal` (static 50) imprime 50→51 e depois 51→52;
  - `usaGlobal` (`x *= 10`) imprime 1→10 e depois 10→100.
  - No fim, o `x` de `main` continua 5.
- Excelente exercício de teste de mesa.

**Obsoleto**
- `auto` é redundante. `register` é só uma sugestão, e os compiladores atuais ignoram ou otimizam sozinhos.

### 0036-pilha-de-chamadas
**Conceitos-chave**
- A pilha de execução guarda, a cada chamada, um **registro de ativação** (quadro): o endereço de retorno e as variáveis locais. Ele é empilhado na chamada e desempilhado no retorno, e por isso as locais "somem".
- A memória é finita: chamadas demais causam estouro de pilha (stack overflow). Ligar com a recursão infinita.

**Analogias**
- **Pilha de pratos:** coloca-se e tira-se sempre do topo (LIFO). Push = empilhar e pop = desempilhar.

**Ideias de exercícios**
- Desenhar os quadros da pilha durante `fatorial(5)`, ou durante `main → maximo`.

### 0037-recursao
**Conceitos-chave**
- A função só sabe resolver diretamente o **caso base**. No resto, divide o problema numa parte que sabe resolver e numa versão menor do mesmo problema, chama a si mesma com essa versão e combina os resultados no `return`.
- A sequência de chamadas precisa **convergir** para o caso base.
- Fatorial iterativo (`for` decrescente multiplicando) e recursivo (`n * fat(n-1)`, base `n <= 1`). A figura mostra a descida 5! → 4! → … → 1 e a volta 1 → 2 → 6 → 24 → 120.
- Comparação com a iteração:
  - ambas repetem e ambas têm teste de término;
  - ambas podem ser infinitas;
  - a iteração usa estrutura de repetição; a recursão usa seleção e chamadas;
  - a recursão tem custo de chamadas e memória.
  - Escolha a recursão quando ela espelha o problema com mais clareza.

**Pegadinhas**
- Esquecer o `return` no ramo recursivo (`else { n + soma(n - 1); }`).
- Não reduzir o problema (`soma(n)` chamando `soma(n)`), o que dá recursão infinita.
- Uma função "comum" chamar a si mesma sem querer, direta ou indiretamente.

**Ideias de exercícios (com resposta)**
- `misterio(a, b)` = `a + misterio(a, b-1)` com base `b == 1` → calcula a·b por somas. Depois adaptar para b negativo.
- Soma recursiva dos elementos de {1..10} → 55. Função que imprime o array de trás para frente: {8,3,1,2,6,0,9,7,4,5} → `5 4 7 9 0 6 2 1 3 8`.
- `main` recursiva com `getchar` imprime a entrada invertida. `main` recursiva com `static int count`: o que acontece? (Estoura a pilha.)
- `potencia(b, e)` recursiva com base `e == 1`. Visualizar a recursão imprimindo com recuo proporcional à profundidade.
- Funções recursivas sobre arrays: imprimir; menor elemento; palíndromo ("radar"), ignorando espaços e pontuação; string invertida; busca linear e busca binária.

### 0038-recursao-na-pratica
**Conceitos-chave**
- **Fibonacci** 0, 1, 1, 2, 3, 5, 8…: fib(10) = 55, fib(20) = 6765, fib(30) = 832040, fib(35) = 9227465. Cada chamada gera **duas**, então o custo é da ordem de 2ⁿ (fib(20) ≈ um milhão de chamadas, fib(30) ≈ um bilhão). Árvore de chamadas de fib(3). Razão áurea ≈ 1,618.
- Em `fib(n-1) + fib(n-2)` a ordem das duas chamadas não é garantida. Não faz diferença aqui, mas faria se houvesse efeitos colaterais.
- **Hanói:** mova n−1 discos da origem para o auxiliar, mova o maior para o destino, mova os n−1 do auxiliar para o destino. Base: n = 1. Para 3 discos: 1→3, 1→2, 3→2, 1→3, 2→1, 2→3, 1→3. Versão iterativa como desafio.
- **Euclides:** `mdc(x, y) = (y == 0) ? x : mdc(y, x % y)`.

**Pegadinhas**
- O código de Fibonacci do livro usa `n == 0 | n == 1`, com OU bit a bit — erro de digitação. Usar `||`.

**Ideias de exercícios**
- Fibonacci iterativo e "até onde dá" com `int` e `double`. Pesquisar a recursão de cauda.

### 0039-modulos
- Pouco conteúdo neste trecho. Cada biblioteca padrão tem um cabeçalho com os protótipos, os tipos e as constantes dela. Seus próprios cabeçalhos usam `.h` e são incluídos com aspas: `#include "quadrado.h"`. A compilação separada fica no cap. 14 (fora do trecho).
- Tabela de cabeçalhos útil para a aula: `assert ctype errno float limits locale math setjmp signal stdarg stddef stdio stdlib string time`.

### 0040-preprocessador
- Neste trecho: `#include`, `#define` para constantes simbólicas, a armadilha do `;` no fim e o lembrete de que o pré-processador não é C, só manipula texto. Macros com parâmetros ficam no cap. 13 (fora do trecho).

### 0041-juntando-tudo (ideias)
- Craps (ver 0032) ou o treino de tabuada (IAC) com funções separadas. Testador da biblioteca matemática imprimindo tabelas de valores.

---

## 05-vetores-e-strings

### 0042-vetores
**Conceitos-chave**
- Array = posições contíguas com o mesmo nome e o mesmo tipo. O índice começa em 0, e o i-ésimo elemento é `c[i-1]`.
- O índice pode ser uma expressão inteira: com a = 5 e b = 6, `c[a+b] += 2` mexe em `c[11]`. `[]` é um operador com a mesma precedência da chamada de função. `c[i]` é um lvalue.
- Inicialização:
  - `{32, 27, 64, …}`;
  - com menos valores que o tamanho, o resto vira 0, então `int n[10] = {0};` zera tudo;
  - sem tamanho, `int n[] = {1,2,3,4,5}` tem 5 elementos;
  - mais valores que o tamanho é erro.
- **Arrays locais não são zerados sozinhos.** Arrays `static` são zerados uma vez e mantêm os valores entre chamadas.
  - Demo: `static` 0,0,0 → +5 → na 2ª chamada entra 5 e sai 10; automático `{1,2,3}` sempre sai 6,7,8.
- Tamanho com `#define TAMANHO` torna o programa fácil de escalar.
- **C não confere limites:** acessar fora do array não dá aviso.

**Analogias/explicações boas**
- **"Sétimo elemento" é `c[6]`; "elemento sete" é `c[7]`, o oitavo.** É a fonte clássica do erro de diferença por um.
- **Vetor de frequência:** usar o próprio valor como índice, `++freq[resposta]`.
  - Pesquisa da cantina com 40 notas de 1 a 10, ignorando `freq[0]`. Resultado: 1:2, 2:2, 3:2, 4:2, 5:5, 6:11, 7:5, 8:7, 9:1, 10:3.
  - Uma resposta inválida como 13 escreveria fora do array. Validar a entrada.
  - Dado 6000 vezes com `++freq[face]` substitui o `switch` de 26 linhas.

**Pegadinhas**
- `for (i = 0; i <= 10; i++) b[i] = 1;` com `int b[10]` escreve fora do array.
- `int n[5] = {32, 27, 64, 18, 95, 14};` tem inicializadores demais.
- Supor que um array `static` é zerado a cada chamada.

**Ideias de exemplos e exercícios (com resposta)**
- Soma de {1,3,5,4,7,2,99,16,45,67,89,45} = 383. Preencher `s[j] = 2 + 2*j`, que dá 2..20.
- Histograma de {19,3,15,7,11,9,13,5,17,1} com `for` aninhado.
- `fracoes` com `TAMANHO` 10: quarto elemento `[3]`, "elemento 4" `[4]`, `fracoes[9] = 1.667`, sétimo elemento `fracoes[6] = 3.333`. `"%.2f"` desses dois imprime 3.33 e 1.67.
- Comissões: 200 + 9% das vendas (3000 → 470), com contadores por faixa de salário de 200–299 até 1000 ou mais.
- Eliminar duplicatas: 20 números entre 10 e 100, imprimindo cada um só na primeira vez, com o menor array possível.
- Crivo de Eratóstenes com 1000 posições.
- Reserva de passagens aéreas: 10 assentos (1–5 primeira, 6–10 econômica), 0 = livre e 1 = ocupado, oferecendo a outra classe quando uma enche.

### 0043-vetores-e-funcoes
**Conceitos-chave**
- Passe o **nome** (sem colchetes) e o **tamanho**, porque arrays não-string não têm terminador. O nome vale o endereço do 1º elemento: imprimir `array`, `&array[0]` e `&array` com `%p` dá o mesmo valor.
- Por isso a função **altera o original**. Demo: {0,1,2,3,4} vira {0,2,4,6,8}.
- Um elemento isolado (escalar) vai por valor. Demo: `a[3]` = 6, a função imprime 12, e `a[3]` continua 6.
- No parâmetro, `int b[]`: se houver tamanho entre os colchetes, ele é ignorado.
- `const int b[]` impede a alteração. O compilador acusa com algo como "l-value specifies const object" (menor privilégio).

**Pegadinhas**
- Na análise de média, mediana e moda do livro, `mediana` ordena o array do chamador como efeito colateral. Bom para discutir quando usar `const` ou copiar o array antes.

### 0044-matrizes
**Conceitos-chave**
- `a[linha][coluna]`; um array m×n tem m·n elementos.
- Inicialização por linhas: `{{1,2},{3,4}}`; `{{1},{3,4}}` deixa `b[0][1] = 0`. Sem as chaves internas, os valores preenchem linha por linha.
  - Demo: `{1,2,3,4,5}` em 2×3 → `1 2 3 / 4 5 0`; `{{1,2},{4}}` → `1 2 0 / 4 0 0`.
- **Armazenamento contínuo, linha após linha.** No parâmetro, a 1ª dimensão é opcional e as demais são obrigatórias (`const int a[][3]`), porque o compilador precisa saber quantos elementos pular. Exemplo: `a[1][2]` pula os 3 elementos da linha 0.
- Uma linha `notas[aluno]` pode ser passada como vetor 1D (função média).
- Exemplo das notas de 3 alunos × 4 provas {{77,68,86,73},{96,87,89,78},{70,90,86,81}}: menor 68, maior 96, médias 76.00, 87.50 e 81.75. Mínimo começando em 100 e máximo em 0.

**Pegadinhas**
- **`a[x, y]` compila e significa `a[y]`** (operador vírgula). Erro silencioso clássico.

**Ideias de exercícios**
- Array `t` 2×5: nomes dos elementos da 2ª linha e da 3ª coluna; zerar sem laço e com laço; menor valor; soma da 4ª coluna; imprimir com cabeçalhos de linha e coluna.
- `tabela[x][y] = x + y` com 3×3. Prever a impressão da inicialização `{{1,8},{2,4,6},{5}}`: linhas `1 8 0`, `2 4 6`, `5 0 0`.
- Vendas: 4 vendedores × 5 produtos, com totais por linha e por coluna.
- Gráficos de tartaruga: piso 50×50 com comandos 1 (caneta para cima), 2 (caneta para baixo), 3 (direita), 4 (esquerda), "5,n" (andar n), 6 (imprimir) e 9 (fim).
- Passeio do cavalo com vetores `horizontal[]` e `vertical[]` e heurística de acessibilidade (2 nos cantos, 8 no centro). Oito rainhas (uma rainha no canto "elimina" 22 casas). Sudoku 9×9.

### 0045-caracteres
**Conceitos-chave**
- `char` é um inteiro pequeno, de 1 byte. Um caractere cabe em qualquer tipo inteiro.
- `printf("(%c) vale %d", 'a', 'a')` mostra `a` e 97 (ASCII). `scanf` com `%c`.
- `getchar()` devolve `int` porque precisa representar `EOF`, um inteiro negativo que não é necessariamente −1, definido em `<stdio.h>`. Compare sempre com `EOF`, não com −1.
- EOF pelo teclado: Ctrl+D numa linha vazia (Linux/macOS) ou Ctrl+Z e Enter (Windows).
- O padrão `while ((c = getchar()) != EOF)` funciona porque a atribuição tem valor.
- `<ctype.h>` aparece só na tabela de cabeçalhos.

### 0046-strings
**Conceitos-chave**
- Uma string é um array de `char` terminado em `'\0'`. `char s[] = "first";` tem 6 posições e equivale a `{'f','i','r','s','t','\0'}`. `s[3]` é `'s'`.
- Percorrer até o terminador: `for (i = 0; s[i] != '\0'; i++)`.
- `printf("%s")` imprime até o `'\0'`, sem conferir o tamanho.
- O livro diz que a string literal é um "array static". A questão de ela ser somente leitura fica para o cap. 7/8.
- `strlen`, `strcpy` e as outras funções de `string.h` ficam no cap. 8 (fora do trecho).

### 0047-lendo-strings
**Conceitos-chave**
- `scanf("%s", s)` vai **sem `&`**, porque o nome já é um endereço. Para no primeiro espaço.
- `char s[20]` guarda no máximo 19 caracteres e o `'\0'`. Use **`%19s`** para limitar.
- Digitar mais do que cabe destrói dados e é porta para ataques de worms e vírus (buffer overflow).
- O livro diz no prefácio que trocou `gets` por `fgets` por segurança, mas `fgets` só aparece no cap. 8.

**Pegadinhas**
- `char str[5]` lendo "olá": cabe na contagem de letras, mas em UTF-8 o "á" ocupa 2 bytes. Bom gancho moderno.

### 0048-juntando-tudo (ideias)
- **Análise de pesquisa com 99 respostas de 1 a 9:** média 681/99 = 6.8788; mediana (ordenar e pegar `[n/2]`) = 7; moda = 8 (27 vezes), com histograma. Desafios: mediana com n par (média dos dois do meio) e empate na moda.
- Boletim de notas com matriz e funções de mínimo, máximo e média.

---

## 06-ponteiros (só os ganchos deste trecho)

### 0049-memoria
- `%p` imprime endereços. O `&` do `scanf` "diz onde está a variável". O nome do array é o endereço do 1º elemento.
- O livro adia a explicação para o cap. 7, que começa na linha ~13034 e fica com o outro agente.
- Esquecer o `&` no `scanf` causa violação de acesso ("acessar memória sem permissão").

---

## 10-analise (ganchos)

### 0076-eficiencia / 0077-big-o
- Busca linear: em média, compara com metade dos elementos.
- Busca binária: o máximo de comparações é o expoente da primeira potência de 2 maior que n. 1023 elementos → 10; 2²⁰ → 20; um bilhão → 30, contra 500 milhões em média na linear.
- Fibonacci recursivo é exponencial, ~2ⁿ chamadas.
- Bubble sort é lento porque cada troca move o elemento uma posição só. Algoritmos simples costumam ser os mais lentos, mas são fáceis de escrever e testar.
- Trade-off que o livro repete: boa engenharia (muitas funções) × desempenho (custo das chamadas).

---

## 13-busca-e-ordenacao

### 0094-busca-sequencial
- `buscaLinear(const int v[], int chave, int n)` devolve o índice ou −1. Demo: `v[x] = 2*x` com 100 elementos; a chave 36 está no índice 18; 37 não é encontrada.
- Exercício: versão recursiva.

### 0095-busca-binaria
- Só funciona em array ordenado. `baixo`, `alto`, `meio = (baixo + alto) / 2`. Se a chave é menor, `alto = meio - 1`; se é maior, `baixo = meio + 1`. O laço roda `while (baixo <= alto)`.
- Demo visual excelente: 15 elementos 0, 2, …, 28, imprimindo o subarray de cada passo com o meio marcado por `*`.
  - Chave 25: meios 14 → 22 → 26 → 24, não encontrada.
  - Chave 8: 14 → 6 → 10 → 8, índice 4.
  - Chave 6: 14 → 6, índice 3.
- Pegadinha moderna (não está no livro): `(baixo + alto) / 2` pode estourar para arrays enormes. Prefira `baixo + (alto - baixo) / 2`.
- Exercício: versão recursiva com índices inicial e final.

### 0096-bubble-sort
- Várias passadas; cada uma compara vizinhos e troca os que estão fora de ordem. O maior "afunda" até o fim, e por isso n−1 passadas bastam. O livro também chama de *sinking sort*.
- Demo: {2,6,4,8,10,12,89,68,45,37} → 2 4 6 8 10 12 37 45 68 89.
- **A troca precisa de variável auxiliar.** Com `a[i] = 7` e `a[i+1] = 5`, fazer só `a[i] = a[i+1]; a[i+1] = a[i];` deixa os dois valendo 5.
- Otimizações (exercício 6.11):
  - (a) cada passada compara um par a menos (8, 7, … comparações);
  - (b) parar quando uma passada não fizer nenhuma troca (flag).

---

## Obsoleto / evitar
- **Regra C89 de declarar tudo no topo do bloco.** Em C99+ declare perto do uso e use `for (int i = 0; …)`. O livro evita C99 por causa do MSVC 2008.
- **`register` e `auto`:** inúteis hoje. `register` é ignorado pelos otimizadores, e `auto` em C23 virou dedução de tipo.
- Os "31 caracteres significativos" de identificador valem só para o C89.
- **Identificadores com acento** (`número`, `média`, `estaVariável`) no código do livro: não são portáveis e muitos compiladores rejeitam. Use só ASCII.
- **Vírgula decimal e aspas tipográficas no código traduzido** (`printf("%.2f", 3,446)`, `“…”`). Em C, `3,446` vira dois argumentos. A saída real é `82.50`, não `82,50`, a menos que se use `setlocale`.
- `scanf("%s")` sem largura: sempre `%Ns`, e preferir `fgets` para linhas. O livro já renega `gets`.
- Ferramentas: Visual C++ 2008 Express e GCC 4.3. O Allegro aparece como biblioteca de jogos, e há a recomendação de Cygwin/MinGW. Para o curso: gcc ou clang atuais com `-Wall -Wextra`.
- Visão "OOP resolve tudo" e tendências do cap. 1 (Java para páginas web, .NET, Lei de Moore): datadas e fora do escopo.
- Explicação de que "o linker não acha `pow` sem `math.h`": incorreta (ver 0015).
- Erros de digitação em exemplos: `aCont`/`aCount`; `n == 0 | n == 1`; `nota` (int) impressa com `%f`; `x*10+5` no arredondamento; a figura do `while` com `<= 1000` e `2*produto`, que não bate com o texto (`<= 100`, `3*produto`). A tabela de precedência diz que o pós-fixo associa da direita para a esquerda, mas é da esquerda para a direita.
- Algumas dicas de desempenho envelheceram: "inicializar na declaração ocorre em tempo de compilação" (falso para variáveis locais); a ordem dos operandos no `&&` como otimização (vale mais pela legibilidade e pela segurança).

## Extras que não cabem no sumário
- **Seções "Erro comum de programação" e "Dica de prevenção de erro" como checklist:** dá para montar um cartão "10 erros que o compilador não pega" (`=` vs `==`, `;` após `if`/`for`/`while`, `break` faltando, `a[x,y]`, diferença por um, float no `==`, `&` esquecido, variável não inicializada, `#define` com `;`, ordem de avaliação).
- **Exercícios "Fazendo a diferença"** (temas sociais, adaptáveis ao contexto brasileiro): calculadora de pegada de carbono, crescimento populacional (ano em que a população dobra), frequência cardíaca alvo (220 − idade, faixa de 50–85%), imposto sobre consumo (FairTax → simular um imposto brasileiro), quiz sobre aquecimento global, instrução auxiliada por computador.
- **Força bruta × heurística** (passeio do cavalo, oito rainhas, triplas pitagóricas): boa discussão de pensamento algorítmico antes do módulo 10.
- **Medir velocidade da máquina:** contar até 300 milhões e cronometrar cada 100 milhões. Uma introdução lúdica à noção de custo.
- **Série de Leibniz para π:** quantos termos para chegar a 3,14? A 3,141? Exercício de convergência numérica.
- Números romanos de 1 a 100; tabela de conversão de bases de 1 a 256.
- Apêndices citados mas fora do trecho: depuradores gdb e Visual Studio (H/I), C99 (G), ordenações avançadas e Big O (F). Podem render uma aula extra de "como depurar".
