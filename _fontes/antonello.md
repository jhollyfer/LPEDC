# Fichamento — Linguagem C (Ricardo Antonello)

- **Autor:** Ricardo Antonello (IFC; www.antonello.com.br)
- **Edição:** 1ª ed., autopublicada (referências de 2018–2020), 131 p.
- **Lido:** 4705 linhas (texto integral, incluindo as listas de exercícios).

## Avaliação geral

Livro curto, informal e bem-humorado, pensado para engenharia. Tem três trunfos para o
LPEDC: (1) o capítulo de **binário e hexadecimal** com método claro e uma lista de 43
conversões; (2) **fluxogramas com o Flowgorithm** e o exemplo do cinema (mesmo problema
em três fluxogramas diferentes, discutindo trade-offs); (3) **listas enormes de exercícios**,
muitas de múltipla escolha do tipo "qual é a saída?" que testam exatamente as pegadinhas
de C (pré/pós-incremento, divisão inteira, `=` no `if`, laço que nunca termina, variável
nunca calculada). Também tem um capítulo de **operadores de bits** com máscaras e macros
SET/CLEAR/TOGGLE/READ muito aproveitável no módulo 08.

Não há gabarito (as respostas abaixo foram calculadas por mim). O histórico tem vários
erros factuais e algumas afirmações técnicas estão erradas ou simplificadas demais (ver
"Pegadinhas" e "Obsoleto"). Vários enunciados de múltipla escolha têm código com erro de
compilação "sem querer" — dá para reaproveitar como "ache o erro".

---

### logica1-algoritmo

**Conceitos-chave**
- Algoritmo = sequência finita de instruções **não ambíguas** para resolver uma tarefa.
  Cita origens antigas (crivo de Eratóstenes, algoritmo de Euclides).
- Linguagem natural é simples, mas ambígua (uma palavra muda de sentido com o contexto);
  o computador não pode "escolher" o sentido — por isso linguagens formais.
- Lista de frases fica ruim quando há muitas decisões e repetições → fluxograma.

**Analogias/explicações boas**
- Receita de bolo com quantidades e temperatura (forno a 180 °C, 50 g de manteiga, 200 g
  de açúcar, 3 ovos um a um, 80 g de chocolate, 220 g de farinha, 30 min) — exemplo de
  algoritmo concreto e não ambíguo.
- **Média com exame** em passos numerados: média das 3 notas; ≥ 7 passa; senão faz exame;
  média final = (média + exame)/2; ≥ 5 passa com exame, senão reprova. Depois acrescenta
  "1 para recalcular, 2 para sair" e "volte ao passo 1" — mostra como o texto vai ficando
  confuso e motiva o fluxograma.

**Ideias de exercícios**
- **Pedra, papel, tesoura** (2.6): algoritmo em texto que recebe as duas jogadas e diz o
  resultado (empate, jogador 1, jogador 2). Bom para decisões encadeadas.
- **IR sobre renda fixa** (2.8): poupança isenta; demais (Tesouro, CDB, fundos): até 180
  dias 22,5%; até 360, 20%; até 720, 17,5%; acima, 15%. Entrada: tipo, valor (o
  rendimento), prazo. Ex.: CDB, R$ 1000 de rendimento, 400 dias → 17,5% → R$ 175.
- Maior de três números (2.12).

### logica3-fluxograma

**Conceitos-chave**
- Fluxograma deixa o algoritmo estruturado e visual; recomenda fazer **sempre** o
  fluxograma no começo.
- Símbolos usados (padrão Flowgorithm): início/fim; **declaração** de variáveis
  (retângulo, ex. "Real nota1, nota2, nota3"); **entrada** e **saída** (paralelogramo);
  atribuição (retângulo); decisão (losango); laços.
- Ferramenta: **Flowgorithm** (gratuito) executa o fluxograma e converte para várias
  linguagens. "Nunca use uma variável antes de declará-la."

**Analogias/explicações boas**
- **Cinema — meia-entrada** (o melhor exemplo do livro para decisões): segunda-feira todos
  pagam meia; nos outros dias, crianças (≤ 12), idosos (≥ 65) e estudantes pagam meia; na
  quarta, casais também. Três propostas de fluxograma:
  1. ifs separados, perguntando um dado por vez (só pergunta o necessário);
  2. juntando idade e estudante com OU (pede dados que às vezes não seriam precisos);
  3. uma única condição gigante com tudo (pede todos os dados antes — "atrasa a fila da
     bilheteria").
  Lição: escolher entre clareza da expressão e número de perguntas é **decisão de
  projeto**; todas estão corretas.
- Temperatura em faixas (frio ≤ 20; agradável ≤ 30; quente ≤ 40; muito quente acima):
  no else-if não é preciso escrever `temp > 20 && temp <= 30`, porque quem chegou ao
  segundo teste já sabe que é maior que 20.

**Ideias de exercícios**
- Desenhar os símbolos de início/fim, entrada/saída, decisão, atribuição (2.2–2.5).
- Fluxogramas para pedra-papel-tesoura, IR de renda fixa, nota necessária no exame,
  maior de três (2.7–2.13).
- Casos de teste do cinema: (seg, 30 anos, não estudante) → meia; (ter, 70) → meia;
  (qua, 30, não estudante, casal) → meia; (qui, 30, não estudante, casal) → inteira;
  (sex, 10) → meia.

### logica4-binario

**Conceitos-chave**
- Computadores trabalham com dois estados (0/1: desligado/ligado, falso/verdadeiro);
  dois níveis de tensão são muito mais fáceis de controlar que dez.
- **Decomposição posicional:** 123 = 1×10² + 2×10¹ + 3×10⁰; trocando a base por 2 vale o
  mesmo raciocínio: 101₂ = 1×4 + 0×2 + 1×1 = 5; 111₂ = 7.
- **Binário → decimal:** multiplicar cada dígito pela potência da base e somar (tabela de
  0000 a 1111 com pesos 8-4-2-1).
- **Decimal → binário:** divisões inteiras sucessivas por 2, guardando os restos, e ler os
  restos **de baixo para cima**. 13 → 1101; 123 → 1111011.
- **Hexadecimal:** base 16, dígitos 0–9 e A–F (10–15). 0x11 = 17; 0x4FC = 4×256 + 15×16 +
  12 = 1276; volta com divisões por 16 (restos 12, 15, 4 → C, F, 4 → lidos ao contrário:
  4FC).
- Prefixos: `0b` para binário (algumas linguagens), `0x` para hexa.
- Bits numerados da direita para a esquerda a partir do **bit 0** (cap. 10).

**Analogias/explicações boas**
- "Decompor os números decimais de um jeito que você nunca viu": partir do 123 conhecido
  para depois só trocar a base. Muito eficaz.
- Uma pitada de história (Boole, Babbage, Turing, ENIAC) para motivar — mas conferir os
  fatos (ver Obsoleto).

**Pegadinhas e erros comuns**
- Ler os restos na ordem em que saíram (de cima para baixo) dá o número invertido.
- Achar que "11" é onze em qualquer base: 11₁₆ = 17, 11₂ = 3.
- Zeros à esquerda não mudam o valor: 0b001001001 = 0b1001001 = 73.
- `0b` só é padrão em C a partir do C23 (antes era extensão do GCC).

**Ideias de exercícios** (respostas conferidas)
- Decimal → binário: 7 = 111; 16 = 10000; 34 = 100010; 66 = 1000010; 127 = 1111111;
  222 = 11011110; 3000 = 101110111000; 5555 = 1010110110011; 19765 = 100110100110101.
- Decimal → hexa: 7 = 0x7; 16 = 0x10; 23 = 0x17; 66 = 0x42; 127 = 0x7F; 222 = 0xDE;
  3000 = 0xBB8; 5555 = 0x15B3; 19765 = 0x4D35.
- Hexa → decimal: 0x00001 = 1; 0x11 = 17; 0x3DF = 991; 0x350 = 848; 0x3D45A = 250970;
  0xAAA = 2730.
- Hexa → binário (cada dígito hexa = 4 bits): 0x11 = 1 0001; 0x3DF = 11 1101 1111;
  0x350 = 11 0101 0000; 0x3D45A = 11 1101 0100 0101 1010; 0xAAA = 1010 1010 1010.
- Binário → decimal: 0b111 = 7; 0b001 = 1; 0b1001001 = 73; 0b001001001 = 73;
  0b11001 = 25; 0b001111001 = 121; 0b1010101010 = 682.
- Binário → hexa: 0b111 = 0x7; 0b001 = 0x1; 0b1001001 = 0x49; 0b11001 = 0x19.
- Pesquisar a base octal (1.43).
- Programa: ler um `unsigned char` (0–255) e imprimir os 8 bits (12 → 00001100), com
  validação da faixa (4.44 / 5.20).

### logica5-compilacao

**Conceitos-chave**
- Código-fonte (texto legível, extensão .c) → compilador (pré-processamento das diretivas
  `#include`/`#define`, compilação, "linkedição") → executável em linguagem de máquina.
  Não se edita o executável: altera-se a fonte e recompila.
- Bibliotecas estáticas (entram no executável) × dinâmicas (.dll/.so, carregadas na
  execução).
- IDE junta editor, compilador e execução (sugere Code::Blocks e o repl.it on-line).
- **Depuração (debug):** executar linha a linha; recomenda depurar mesmo sem erro, só
  para ver o programa andando.
- **Erros de compilação** (nome de comando errado, variável não criada — o compilador
  aponta a linha) × **erros de execução/lógica** (compila, mas dá resultado errado ou
  trava — mais difíceis).

**Pegadinhas e erros comuns**
- O livro diz que `#include` "inclui uma biblioteca estática" — impreciso: o `#include`
  copia um **cabeçalho** (declarações); quem junta o código da biblioteca é o ligador.
  Corrigir no LPEDC.
- Diz que o executável tem extensão .EXE (só no Windows).

**Ideias de exercícios**
- Múltipla escolha 3.3 (correta: instruções de alto nível são compreensíveis por humanos).
- Classificar erros: "esqueci o `;`" (compilação) × "média dá sempre 0" (lógica).

### 0001-primeiro-programa

**Conceitos-chave**
- "Esqueleto" a usar sempre: include, `int main() {`, código, `return 0;`, `}`.
  Chaves abertas precisam ser fechadas.
- Comentários `//` (até o fim da linha) e `/* */` (várias linhas).
- `puts` (imprime string e já pula linha) e `putchar` (um caractere).

### 0002-variaveis

**Conceitos-chave**
- Motivação: acessar memória por número de célula (1, 2, 53.427...) seria complexo e
  propenso a erro; variável é um **nome dado a um espaço de memória**.
- Declarar várias numa linha, inicializar algumas (`int idade=12, idade1, idade2=35;`).
- **C não zera variáveis**: sem inicializar, a variável tem "lixo" de processamentos
  anteriores → resultados imprevisíveis.
- Escolha do tipo: temperatura como `int` pula de 22 para 23 graus; melhor `float`.
- Regras de nome: letras, dígitos e `_`; começa por letra ou `_`; sem espaços.
  Convenção: variáveis minúsculas, constantes maiúsculas.
- `char` é um **inteiro de 1 byte**; caractere é só um número exibido como símbolo
  ('A' = 65, 'a' = 97). Programa que imprime `i=%c` de 0 a 255 mostra a tabela (e apita
  no código 7!).
- `sizeof(a)`: tamanho em bytes (provavelmente 4 para `int`, mas depende do sistema).

**Pegadinhas e erros comuns**
- Ler variável não inicializada.
- `int idade = 'A'; printf("%d", idade);` imprime 65 — compila sem erro.
- O livro afirma que a tabela ASCII vai de 0 a 255 — ASCII tem 128 códigos (0–127); acima
  disso é tabela estendida dependente de sistema.

**Ideias de exercícios** (com respostas)
- **Nomes válidos** (4.13): `Variavel` válido; `nome 1` inválido (espaço); `entrada2`
  válido; `saida_2` válido; `1contador` inválido (dígito no início); `_valor_TOTAL`
  válido.
- **Todos válidos?** (4.43): a) `real$`, `errado!` inválidos; b) `olho gordo` inválido;
  c) `int` é palavra reservada; d) `case` é palavra reservada → resposta **e) nenhuma**.
- Código `a=7, b=4, soma = a+b` → **11** (4.6).

### 0003-tipos-e-limites

**Conceitos-chave**
- Tabela com `char`, `signed/unsigned char`, `int`, `short`, `long`, `unsigned`, `float`
  (~6 dígitos), `double`, `long double`, com tamanhos e faixas.
- `unsigned` usa o bit de sinal para valor (≈ dobra o máximo positivo).
- Tipos maiores ocupam mais memória e podem ser mais lentos; em dispositivos pequenos,
  escolher o menor tipo suficiente.

**Pegadinhas e erros comuns**
- A tabela mistura "tamanho típico" com "faixa mínima" do padrão (o padrão garante só
  16 bits para `int`); `long double` de 10 bytes e `double` com "dez dígitos" variam.
  Ensinar a conferir com `sizeof`/`limits.h`.
- Teste `if (num < 0)` com `unsigned int num` é sempre falso (aparece no conversor de
  binário do cap. 8) — ótima pegadinha.

### 0004-constantes

**Conceitos-chave**
- `#define NOME valor` logo após os includes, nomes em maiúsculas (`MAX 100`, `ISS 0.05`,
  `LED1 33`, mensagem de erro como string).

**Pegadinhas e erros comuns**
- O livro diz que constantes "são acessadas muito mais rápido que variáveis" — exagero;
  a vantagem real é legibilidade e um só lugar para mudar.
- Não apresenta `const` (cobrir em 0004 por outra fonte).

### 0005-printf

**Conceitos-chave**
- Primeiro argumento é a string de controle; cada `%` consome um argumento, **na ordem**.
- Inteiros: `%c` (como caractere), `%d`/`%i`, `%u`, `%o`, `%x`; `%ld` para long.
- Reais: `%f`, `%e` (científica), `%g` (o mais curto). `%s` para string.
- **Largura e precisão** — tabela de exemplos com v = 1.23 (excelente):
  `%f` → 1.230000; `%.3f` → 1.230; `%.2f` → 1.23; `%.1f` → 1.2; `%6.2f` → "  1.23"
  (6 caracteres contando o ponto); `%06.2f` → 001.23; `%+06.2f` → +01.23;
  `%+08.2f` → +0001.23. Largura negativa (`%-12d`) alinha à esquerda.
- Escapes: `\a` (bip), `\b`, `\f`, `\n`, `\r`, `\t`, `\v`, `\\`, `\'`, `\"`.
- O `%` do resto e o `%` do printf são coisas diferentes.

**Pegadinhas e erros comuns**
- O texto diz que `%06.2f` "coloca espaços" — coloca **zeros**.
- `printf("%.2f", variavelInt)` é comportamento indefinido (exercício 4.22: imprime lixo,
  geralmente 0.00 — resposta "nenhuma das alternativas").
- `printf(temp)` com string lida de arquivo (cap. 9) é perigoso: se o texto tiver `%`,
  vira formato. Usar `printf("%s", temp)` ou `fputs`.

**Ideias de exercícios** (com respostas)
- V/F sobre os especificadores (4.14: todas corretas) e sobre larguras (4.15, 4.16).
- Relatório de salário (4.32): valor-hora × horas; descontos IR 14%, INSS 11%,
  sindicato 1%. Ex.: R$ 20/h × 160 h = 3200.00; IR 448.00; INSS 352.00; sindicato 32.00;
  líquido 2368.00. Treina alinhamento com largura.
- Composição do preço do combustível (4.33): bomba R$ 3.00 → distribuição 17% 0.51; etanol
  12% 0.36; ICMS 28% 0.84; tributos 7% 0.21; refinaria 1.08 (exemplo do próprio livro).

### 0006-scanf

**Conceitos-chave**
- Especificadores de leitura (`%i` aceita octal com 0 e hexa com 0x; `%d`; `%ld`; `%lf`
  para double; `%c`; `%s`).
- O `&` informa ao scanf o endereço onde guardar.
- Truque: `scanf("%d%c%d", &v1, &op, &v2)` lê "2+3" de uma vez (usado na calculadora).
- `%s` para no primeiro espaço ("Ricardo Antonello" → "Ricardo").
- `getchar()` lê um caractere.

**Pegadinhas e erros comuns**
- O livro usa `scanf("%s", &str)` (com `&` em vetor) e recomenda `gets` — corrigir.
- Ler `double` com `%f` (precisa `%lf` no scanf).

### 0007-aritmetica / 0008-conversao

**Conceitos-chave**
- **Tipo do resultado = tipo dos operandos:** 5/2 = 2 (inteiros); 5/2.0 = 5.0/2 = 2.5.
- `30 % 7 = 2`. Precedência: `* /` antes de `+ -`; parênteses à vontade:
  `2+2*3` = 8; `(2+2)*3` = 12; `((2+2)*3)+(((5+2)-3)*7)` = 40.
- Cast: `(float)a / 2` com a=5 → 2.5; multiplicar por 1.0 também converte.
  `(int)3.5` → 3; atribuir float a int trunca automaticamente.

**Pegadinhas e erros comuns**
- `float media = soma / n;` com `soma` e `n` inteiros → já truncou antes de atribuir.
- `(float)(a/2)` ≠ `(float)a/2`.

**Ideias de exercícios** (respostas calculadas)
- **Saída?** (4.18): `(b-(c*7))/(4-(a*c*a))` com a=1,b=2,c=3 floats → (2−21)/(4−3) =
  **−19.000000**.
- **Saída?** (4.21): x=10, y=−20: z=x−y → 30; z=y+x → −10; z=z/(x/5) → −10/2 = **−5**.
- **Saída?** (4.22): `char a=97; float x=2.3; int r = x+a;` → r = 99 (truncou 99.3);
  `printf("%.2f", r)` → indefinido → **nenhuma das alternativas**.
- **Saída?** (4.24): lê 6, 8, 10 mas nunca calcula a média → **Media: 0.000000**.
  Ótimo "ache o erro".
- Quociente e resto de x por y (4.26): 17 e 5 → 3 e 2.
- Equação x = (32 − y)/(2a + b) com a=10, b=2, y=5 → 27/22 ≈ 1.227 (com inteiros daria 1 —
  pegadinha!).
- Decompor 8531 em unidade 1, dezena 3, centena 5, milhar 8 com `/` e `%` (4.39).
- **Tinta** (4.35): 1 L cobre 3 m²; lata de 18 L a R$ 80. 100 m² → 33,3 L → 2 latas,
  R$ 160 (arredondar para cima — gancho para `ceil` em 0010).
- Maçãs em caixas de 42 (4.37): 100 maçãs → 3 caixas (divisão inteira + "sobra").
- Azulejos (4.38), lâmpadas por W/m² (4.40), combustível de F1 (4.41), Bhaskara (4.36),
  conta da lanchonete (4.34), tinta com latas e galões (4.42).

### 0009-atribuicao

**Conceitos-chave**
- `=` lê-se "recebe". Tabela `x+=k`, `x-=k`, `x*=k`, `x/=k`, `x++`, `++x`.
- **Quatro exemplos de pré/pós-incremento:** isolados, `x++` e `++x` dão o mesmo; em
  `y = ++x` (x=1) → x=2, y=2; em `y = x++` → x=2, y=1.

**Ideias de exercícios** (respostas calculadas)
- **Saída?** (4.19): i=10, i2=18; `(++i + i2++)/2.0` → (11+18)/2.0 = **14.500000**.
- **Saída?** (4.20): x=7; `++x % 2` → 8 % 2 = **0**.

### 0012-relacionais / 0013-logicos

**Conceitos-chave**
- Condição = expressão lógica com resultado V/F. Operadores `> < >= <= == !=`, `&& || !`.
- Caracteres também podem ser comparados (são números).
- `3=5` não compila (não se atribui a um número); `3==5` é falso.
- Parênteses evitam ambiguidade: `(3>5) || (5==5)` → V.
- **C não tem booleano: 0 é falso, qualquer outro valor é verdadeiro.**

**Pegadinhas e erros comuns**
- **`if (a = 3)`** com a=5: atribui 3 e testa 3 → sempre verdadeiro. O certo é `==`.
  Exemplo pronto para 0015.

**Ideias de exercícios** (respostas calculadas)
- **Quais são verdadeiras?** (5.14) com x=0, y=10: a) 0<10 && 10>10 → F; b) 0<=10 &&
  10<10 → F; c) 0<0 || 10>10 → F; d) 0>0 && ... → F; e) 0<=0 || ... → **V**. Só a (e).

### 0014-if / 0015-if-else / 0016-else-if

**Conceitos-chave**
- `if` com uma instrução ou bloco; o autor sugere **usar chaves sempre** (mais seguro para
  iniciantes) e indentar.
- Maioridade: idade ≥ 18 → "pode dirigir"; senão "faltam 18 − idade anos".
- Faixas de temperatura com else-if (ver 0003).

**Ideias de exercícios** (com respostas)
- **Saída?** (5.1): resultado −19 e `if (result >= -19)` → **Ok**.
- Maior de dois reais; pode votar este ano (ano de nascimento); senha 1234 →
  "ACESSO PERMITIDO"/"NEGADO"; dia da semana 1–7 com erro fora da faixa; menor de três;
  média com exame (7 e 5); consumo km/l < 8 → "troque o carro".
- Peso ideal (homem 72,7h − 58; mulher 62,1h − 44,7).
- **Triângulo por lados** (5.11): 3,3,3 equilátero; 3,3,5 isósceles; 3,4,5 escaleno.
- **Triângulo por ângulos** (5.12): 90 → retângulo; >90 → obtusângulo; todos <90 →
  acutângulo.
- Polígono regular por nº de lados (3 triângulo + área; 4 quadrado + área; 5 pentágono;
  >5 não identificado).
- Ordenar 3 inteiros distintos (5.15).
- **Ache o erro** (5.19): programa de ordenar três números com `:` no lugar de `;` e aspas
  simples/duplas trocadas → não compila (**e**). Mesmo depois de corrigido, ele imprime em
  ordem **crescente**, e não decrescente como dizem as alternativas.

### 0017-ternario

**Conceitos-chave**
- `condição ? valor_se_V : valor_se_F` para if/else simples; envolver a condição em
  parênteses e manter os ramos curtos.
- Exemplo: `n >= 0 ? n++ : n--;`.
- Ternário aninhado (zero / positivo / negativo) funciona, mas fica confuso — evitar.

### 0018-switch

**Conceitos-chave**
- Seleção múltipla sobre valor inteiro ou caractere (`case '+':` com aspas simples);
  `break` sai; `default` para inválido. Tudo que switch faz, o if também faz.
- **Fall-through útil:** `case '*': case 'x':` executam o mesmo código; idem `'/'` e `':'`
  na calculadora. Exemplo perfeito para explicar fall-through como recurso.

**Ideias de exercícios**
- Calculadora com `+ - * / ^ r` (potência e raiz) (5.18, 6.38 com repetição até operação
  inválida).

### 0020-while / 0021-do-while / 0022-for

**Conceitos-chave**
- Os três laços fazem a mesma coisa com pequenas diferenças; exemplos imprimindo 1 a 5
  nos três, cada um com fluxograma.
- `while`: incrementar a variável de controle, senão laço infinito.
- `for(arg1; arg2; arg3)`: arg1 executa uma vez; arg2 testado antes de cada volta; arg3
  depois do bloco. Exemplo: 100 até 0 decrescente pulando 31–59 (`if (i<=30 || i>=60)`).
- `do-while`: executa ao menos uma vez.

**Pegadinhas e erros comuns** (todas com resposta calculada)
- **Quantas repetições?** (6.43): a) `i=0; while(i++<9)` → 9; b) `i=1; while(i++<9)` → 8;
  c) `i=0; while(i++<10)` → **10**; d) `i=0; while(i++<=10)` → 11; e) `i=1;
  while(++i<=10)` → 9. Resposta: **c**. Excelente exercício de pré/pós dentro da condição.
- **Média calculada dentro do if** (6.44): `if (media > 7)` com media=0 → "Reprovado.
  Media: 0.000000" (**d**).
- **Laço que nunca roda** (6.45): `for(a=7; a>8; --a)` não executa; `if (a>7)` falso →
  **nada é impresso**.
- **Laço infinito por incremento dentro do if** (6.46): `coluna++` só quando
  `linha == coluna` → imprime uma vez e trava (**c**).
- **Multiplicar por zero** (6.47): `num = num*i` com i começando em 0 → num vira 0 para
  sempre, nunca passa de 5 → sai após 10 mil voltas com "Resultado: 0" (**b**).
- **Começo deslocado** (6.48): `temp = ++n1 + 1` começa em n1+2 e altera n1 → pula o
  primeiro número do intervalo (**e**).
- **Condição impossível** (6.49): `temp==10 && temp==15` nunca é verdadeira → laço eterno
  (**e**).
- **Laço eterno com mensagem** (6.50): `temp += 2` só aumenta e a condição é `temp >= 0`;
  "Saindo..." é impresso mas nada sai do laço → **b**.
- **Curto-circuito** (6.51): `while(a++>=1 && ++b<=2)` → 1ª parte V, 2ª F (b vira 3) →
  corpo nunca executa → **0.000000**.
- **Saída?** (6.52): i=1, i2=18: 1ª volta (2+18)/2.0 = 10; 2ª (3+19)/2.0 = 11, break →
  "10.00000011.000000" (**c**).
- **Maior com valores negativos** (8.24): vetor de −1 a −10, `maior = 0` → imprime
  "**0 −55**" (**b**): maior errado por inicialização.

**Ideias de exercícios**
- 5 a 20 com for e com while; 20 a 5; intervalo entre dois números; pares de 0 a 50 e
  depois ímpares; validar divisor ≠ 0 com repetição; 1 a 100 sem o 50; 1 a 10.000 sem
  múltiplos de 10 (ou de 33); quadrado até digitar 0; soma dos n primeiros naturais
  (n=4 → 0+1+2+3 = 6 — atenção: o livro inclui o zero!); n primeiros ímpares (n=4 → 1,
  3, 5, 7); consumo com "1 para novo cálculo"; tabuada do 7 (while) e do 3 (for); laranjas
  (R$ 0,60 se < 12; R$ 0,50 se ≥ 12: 10 → 6.00; 12 → 6.00; 20 → 10.00).

### 0023-break-continue

**Conceitos-chave**
- `continue` pula o resto da volta atual; `break` encerra o laço.
- Laços "infinitos de propósito": `while(1)` e `for(;1;)` (o meio do for é a condição;
  1 e `1==1` são ambos verdadeiros) com `break` interno.
- Exemplo: somar números até digitar 0, com `while(1)` e `if (x==0) break;`.

**Ideias de exemplos**
- `for i de 0 a 10` com `if (i > 5) continue;` → imprime 0..5 (mas o laço ainda dá as 11
  voltas — discutir que `break` seria mais eficiente aqui).
- `if (i == 5) break;` → imprime 0..4.

**Ideias de exercícios**
- Ler até 5 números ou até digitar 10, o que vier primeiro (6.19) — break natural.

### 0024-lacos-aninhados

**Ideias de exercícios** (com respostas)
- Tabuadas de 1 a 10 com dois while e com dois for (6.15, 6.16).
- **Triângulo de asteriscos** (6.26): `*`, `**`, ..., `*****`.
- **Asteriscos + números** (6.27): `****1`, `***22`, `**333`, `*4444`, `55555` — dica do
  autor: gerar 1..5 para os números e 4..0 para os asteriscos.
- Matriz com moldura de zeros e miolo N+i+j (6.28): n=10 → miolo 13 14 / 14 15.
- Letras AA a ZZ como colunas de planilha (6.35).

### 0025-padroes-de-laco

**Ideias de exercícios** (com respostas)
- Contar positivos e negativos de 5 valores (6.17 / 6.53).
- Média, maior e menor de 10 reais (6.18).
- Divisores de um número (6.22); **primo** (6.29); soma dos primos entre 92 e 1478 (6.30).
- **Perfeito** (6.40): 6 = 1+2+3 → sim; 28 → sim; 12 → não.
- Fibonacci até o 17º termo (6.41): 0, 1, 1, 2, 3, 5, 8, ..., 987.
- **Leibniz para π** (6.42): π ≈ 4(1 − 1/3 + 1/5 − ...); testar 5, 10, 20, 100 termos
  e ver a convergência lenta. **Euler** e ≈ Σ 1/k! (6.32) → 2.718282.
- Múltiplos de i ou j (6.39): n=6, i=2, j=3 → 0, 2, 3, 4, 6, 8.
- Caracteres iguais em sequência até digitar 'x' (6.36, do-while).
- **Caixa eletrônico** (6.37): saldo começa em 0; consulta, saque, depósito, sair.
- x elevado a y com while (6.20); fatorial com while (6.23).

### 0026-aleatorios

**Conceitos-chave**
- `rand() % 10` dá 0 a 9; `srand(time(NULL))` inicializa a semente **uma única vez** no
  `main`, não dentro da função que sorteia. Includes `stdlib.h` e `time.h`.

### 0028-funcoes / 0029-parametros / 0030-escopo (resumo)

**Conceitos-chave**
- Função = conjunto de comandos com nome; organiza e modulariza. `void` quando não
  retorna; tipo de retorno + `return` quando retorna.
- **Analogia do chefe:** 23 relatórios com uma linha de 10 traços como separador; o chefe
  pede asteriscos. Se o separador é uma função `linha()`, muda-se um lugar só; se são
  centenas de `printf`, "muito, muito trabalho". Ótima motivação.
- Parâmetros com tipo, separados por vírgula: `repete(5, 'x')` → `xxxxx`.
- Global × local: variável local com o mesmo nome "esconde" a global só dentro daquela
  função; `f()` continua vendo a global → programa imprime "37".

**Ideias de exercícios**
- Média de dois, menor de dois, par (1/0), validar nota 0–10 (−1 se inválida),
  capturar nota com repetição, sinal (1/−1/0), potência sem `pow`, ano bissexto
  (`ano%4==0 && (ano%100!=0 || ano%400==0)`: 2000 sim, 1900 não, 2024 sim), absoluto,
  distância entre pontos, soma dos divisores (8 → 7), médias aritmética/ponderada
  (5,3,2)/harmônica, valor de prestação com multa 3% + 0,1% ao dia.

### 0037-vetores / 0039-matrizes / 0041-strings / 0042-lendo-strings (resumo)

**Conceitos-chave**
- Vetor como **uma coluna de planilha** (linhas numeradas a partir de 0); matriz como a
  planilha inteira (linhas × colunas). Lixo antes de atribuir.
- `int a[5] = {42, 42};` → o resto é preenchido com zero.
- Conversor decimal→binário com vetor de restos (4 bits e depois 32 bits — "8× mais
  trabalho, mesmo código").
- String = vetor de `char` com `'\0'` no fim; `printf("%s")` para no `'\0'`.
  `strcpy`, `strcat`, `strlen`, `strcmp` (0 se iguais, <0, >0). Atribuição com `=` só na
  declaração. Vetor de strings = matriz de `char` (`lista[5][10]`, 9 letras úteis).

**Pegadinhas e erros comuns**
- `char nome2[10] = "Meu Brasil";` tem exatamente 10 letras → **não sobra lugar para o
  `'\0'`** (o livro não percebe). Excelente pegadinha para 0041.
- A tabela do livro mostra "lixo" nas posições após o `'\0'` de `char nome[10] =
  "Brasil"`, mas com inicializador o resto é zerado (o próprio livro diz isso para `int`).
- `for (i < strlen(s))` recalcula o tamanho a cada volta.
- Exercício 8.10 diz que o método "ache o menor e ponha na frente" é inserção direta — é
  **seleção**. E a saída esperada contém um 4 que não está no vetor.

**Ideias de exercícios**
- `cincoPalavras[2][2]` com JESUS na linha 2 → 'S' (8.22).
- Contar letras 's' numa frase; inverter três palavras; **cifra +1** ('a'→'b') (8.20);
  matriz transposta; soma de matrizes; A(i,j) = 3i + j².

### 0065-bits

**Conceitos-chave**
- Uso real: microcontroladores — 8 bits de um byte podem ligar/desligar 8 LEDs ou motores.
- `>>` divide por 2 (9 >> 1 = 4); `<<` multiplica por 2 (5 << 1 = 10); `1 << 2` = 4.
- **Máscaras:** AND desliga (49 & 0b11011111 = 17); OR liga (`x | (1<<4)` = 16);
  XOR inverte (49 ^ (1<<1) = 51; x ^ x = 0); NOT gera a máscara de desligar
  (`x & ~(1<<5)`). Testar bit: `if (PORTA & (1<<2))`.
- Macros SET, CLEAR, TOGGLE, READ e função `imprimeBin`. Sequência: 0b00001111 → liga
  bit 6 → 0b01001111 → desliga bit 2 → 0b01001011 → inverte bit 0 → 0b01001010.

**Pegadinhas e erros comuns**
- Comentários do livro repetem "imprime 0b00001111" em todas as linhas (copiar-colar).
- Macros sem parênteses em volta dos argumentos (`1 << y`): ensinar a forma segura
  `(1u << (y))`.

**Ideias de exercícios** (com respostas)
- Bits pares ligados de 73 (0100 1001) → 2. Embaralhar bits na ordem (7,5,3,1,6,4,2,0):
  73 → 0010 1001 = 41. Zerar bits 3 e 4 e inverter 0 e 7, mostrar em hexa. Rotação sem
  perder bits; pisca-pisca 01010101/10101010.

### 0067-arquivos-texto (resumo)

- `FILE *fp`; `fopen` com modos r, r+, w, w+, a, a+ (tabela clara); checar `NULL`;
  `fclose` retorna 0 se deu certo. Tabela de correspondência: putchar/fputc,
  puts/fputs, printf/fprintf; getchar/fgetc, gets/fgets, scanf/fscanf.
- Leitura correta linha a linha com `while (fgets(temp, 255, fp) != NULL)`.
- Exercícios: gravar/ler palavra, matriz 3×3 em "mat.txt", médias de "notas.txt",
  frequência de letras, relatório de uso de disco a partir de "login;bytes".

---

## Obsoleto / evitar

- Histórico com erros: Colossus atribuído a Turing (foi Tommy Flowers); "Basic" chamado de
  sistema operacional; tear de Jacquard atribuído a "um costureiro"; ANSI C datado de
  1985 (foi 1989); "C++ é a mesma linguagem C com orientação a objetos"; "computadores
  ainda usam a arquitetura de Turing". Não reaproveitar sem checar.
- `gets()`; `scanf("%s", &vetor)`; `printf(string_variavel)`.
- `#include` descrito como inclusão de biblioteca estática.
- `windows.h`/`Sleep()` nos exercícios de bits (usar alternativa portável ou omitir).
- ASCII "de 0 a 255".
- repl.it (mudou de modelo) e Code::Blocks como única recomendação.

## Extras que não cabem no sumário

- Flowgorithm como ferramenta de apoio ao módulo 00 (executa e traduz fluxogramas).
- Bibliotecas estáticas × dinâmicas (.so/.dll): nota opcional em 0005 ou 0034.
- Depuração passo a passo como hábito desde o início (gdb ou depurador da IDE).
- Tensores/deep learning e IoT como motivação para matrizes (curiosidade).
- Formatos de arquivo texto (CSV, JSON) como contexto em 0067.
- Apêndice de filmes (Jogo da Imitação, Piratas do Vale do Silício) — material de
  motivação, fora do conteúdo.
