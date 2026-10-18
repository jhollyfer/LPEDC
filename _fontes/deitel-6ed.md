# Fichamento — Deitel & Deitel, *C: Como Programar* ("6ª edição" no nome do arquivo)

**Autores:** Paul J. Deitel e Harvey M. Deitel. Tradução brasileira, arquivo .md de 17.211 linhas
(caps. 1–13 + Apêndices A–D), vindo de OCR com muitos erros de digitação.

**Avaliação geral.** Apesar do nome do arquivo, o conteúdo **não é a 6ª edição**: é a edição
ANSI C89 do começo dos anos 90 (provavelmente a 2ª ed. traduzida). As evidências: `main()` sem tipo,
`int` de 2 bytes, Borland C++ e MS-DOS, "C++ será dominante no fim dos anos 90", Concurrent C, `__DATE__ = Sep 08 1993`,
bibliografia até 1992. Por isso falta tudo o que é C99/C11: `//`, `stdbool.h`, `stdint.h`, declarações
no meio do bloco, `for (int i...)`, `long long`, VLA, `snprintf`, `fgets` no lugar de `gets`. Também
**não há argc/argv**, nem lista dupla/circular, insertion/merge sort, AVL, heap, hash ou grafos.
- **Pontos fortes (melhores que em muitas edições novas):** (1) um **banco de exercícios** enorme e criativo: Simpletron (montar seu próprio computador), compilador da linguagem "Simples", passeio do cavalo com heurística, oito damas, gráficos da tartaruga, corrida lebre × tartaruga, craps, proteção de cheques, valor por extenso, Morse, gerador de palavras de telefone, simulação de supermercado. (2) Método de **refinamento top-down** com pseudocódigo, bem desenvolvido. (3) Caixas de "Erro comum", "Boa prática", "Portabilidade" e "Desempenho" em todo o livro. (4) Muitos exercícios do tipo "encontre o erro" e "o que este programa imprime?".
- **Pontos fracos:** práticas obsoletas, figuras sem código (6.15–6.22 aparecem só como legenda), respostas e textos com **erros de fato** (lista na seção "Obsoleto / evitar"). Para o LPEDC, use o livro como **mina de exercícios e pegadinhas**, não como referência de C moderno.

---

## 00 — Lógica

### 0001-algoritmo
- **Conceitos-chave:** um algoritmo é um procedimento definido por duas coisas: *quais ações* e *em que ordem*. "Controle do programa" é justamente especificar essa ordem.
- **Analogia boa:** a rotina "acordar e ir trabalhar" (levantar, tirar o pijama, tomar banho, vestir-se, tomar café, sair). Se trocar "vestir-se" e "banho" de lugar, o executivo chega molhado ao trabalho. As ações são as mesmas; só a ordem mudou e o resultado ficou errado.
- **Ideia de exercício:** dar 6 passos embaralhados de uma tarefa doméstica e pedir a ordem correta. Depois pedir uma ordem que "funciona mas tem efeito ruim".

### 0002-pseudocodigo
- **Conceitos-chave:** pseudocódigo é uma linguagem informal, só de texto, que não executa. Contém só *ações*: declarações não entram, porque são mensagens ao compilador. **Refinamento top-down por etapas:** comece com uma frase só (o "topo"), que já é uma especificação completa. Cada refinamento continua completo, só que mais detalhado. Pare quando der para traduzir linha a linha para C.
- **Explicação boa:** muitos programas têm três fases: **inicialização** (zerar total e contador), **processamento** (ler e acumular) e **terminação** (calcular e imprimir).
- **Estudos de caso (excelentes para aulas):**
  1. Média de 10 notas com contador (repetição definida).
  2. Média com número arbitrário de notas e sentinela −1 (repetição indefinida). Inclui o teste de divisão por zero quando nenhuma nota foi digitada.
  3. Resultados de exame (1 = aprovado, 2 = reprovado) para 10 alunos. Contar cada tipo e, se mais de 8 passaram, imprimir "Cobrar taxa escolar". É o if/else aninhado dentro do while.
- **Pegadinhas:** só contadores e totais precisam de inicialização. Variáveis que recebem leitura não precisam (o livro chama isso de "leitura destrutiva").
- **Exercícios bons (3.17–3.21, sempre com sentinela −1):** km/litro por tanque e média geral (12.8 L, 287 km → 22.42); limite de crédito (saldo + cobranças − créditos > limite?); comissão de $200 + 9% das vendas ($5000 → $650); juros simples `capital*taxa*dias/365` (1000, 0.1, 365 → 100); salário com hora extra 1,5× acima de 40 h (41 h a $10 → $415). Para cada um, pedir pseudocódigo com 2 refinamentos antes do C.

### 0003-fluxograma
- **Conceitos-chave:** símbolos: elipse (início/fim), retângulo (ação), losango (decisão), pequeno círculo (conector) e setas (linhas de fluxo). Teorema de Böhm–Jacopini: qualquer programa pode ser escrito com **sequência, seleção e repetição**. C tem 7 estruturas (sequência, 3 de seleção, 3 de repetição), todas de **entrada única e saída única**. Elas só se combinam de duas formas: **empilhamento** e **aninhamento**.
- **Analogias boas:** (1) as "sete latas" com estruturas de controle vazias: o programador as empilha ou aninha e depois preenche retângulos e losangos. (2) As 4 regras para formar fluxogramas estruturados: comece pelo fluxograma mais simples; troque um retângulo por dois em sequência; troque um retângulo por qualquer estrutura; repita. Para saber se um fluxograma é estruturado, **aplique as regras ao contrário** até chegar ao fluxograma mais simples. Blocos **sobrepostos** só aparecem com goto.
- **Explicação boa:** basta `if` para obter qualquer seleção, e basta `while` para qualquer repetição.
- **Exercício:** dar um fluxograma com uma seta cruzada (não estruturado) e pedir a redução pelas regras.

### 0004-binario (Apêndice D)
- **Conceitos-chave:** base, valor posicional (potências da base a partir de 0 na direita), dígitos de 0 até base−1, hexadecimal com A–F. Octal e hexa existem para **abreviar binário**, porque 8 e 16 são potências de 2 (agrupar 3 ou 4 bits). Para converter para decimal, some dígito × valor posicional. Para converter de decimal, use o método "colunas de valor posicional": descarte a coluna maior que o número e vá dividindo da esquerda para a direita. **Complemento de dois:** inverta os bits (`~`) e some 1. Verificação: x + (−x) dá tudo zero, porque o "vai-um" final é descartado.
- **Exemplos prontos:** 100011010001₂ = 4321₈ = 8D1₁₆; 653₈ = 110 101 011; FAD5₁₆ = 1111 1010 1101 0101; 110101₂ = 53; 7614₈ = 3980; AD3B₁₆ = 44347; 57 = 111001₂; 103 = 147₈; 375 = 177₁₆; 13 → −13 em 32 bits; 27 − 13 calculado como 27 + (~13 + 1) = 14.
- **Exercícios (com resposta):** 110101011000₂ → octal 6530, hexa D58; FACE → 1111101011001110; 7316₈ → 111011001110; 4FEC → octal 47754; 1101110₂ → 110; 317₈ → 207; EFD4 → 61396; 177 → 10110001₂ / 261₈ / B1₁₆; quanto dá um número somado ao seu complemento de um? (tudo 1s). Ainda: base 12 (qual o menor e o maior dígito? quais os valores posicionais?); complemento de dois de −1 em 32 bits (32 uns).
- **Exercícios de programa:** 3.36 lê um "binário" como inteiro (só 0s e 1s) e imprime o decimal usando `%` e `/` (1101 → 13). 4.25/4.33 imprimem tabela decimal/binário/octal/hexa de 1 a 256.

### 0005-compilacao
- **Conceitos-chave:** seis fases: **edição → pré-processamento → compilação → ligação (linking) → carga (loader) → execução**. O código-objeto tem "lacunas" para as funções da biblioteca, e o ligador as preenche. `cc arquivo.c` gera `a.out`. Linguagem de máquina × assembly × alto nível, com o mesmo cálculo de folha de pagamento nas três (`+1300042774…`, `LOAD BASE / ADD EXTRA / STORE BRUTO`, `Bruto = Base + Extra`). Fluxos stdin, stdout e stderr.
- **Explicação boa (rara):** **por que digitar `print` no lugar de `printf` é pego pelo ligador e não pelo compilador:** as funções da biblioteca não fazem parte da linguagem, então o compilador só reserva a chamada.
- **Exercício:** classificar como hardware ou software (CPU, compilador, ALU, editor); verdadeiro ou falso sobre tradutores ("linguagem de máquina exige tradução antes de executar?" → falso). O Simpletron (7.18–7.19) e o compilador Simples (12.26–12.27) são o melhor material "do .c ao executável" do livro. Ver "Extras".

---

## 01 — Fundamentos

### 0006-primeiro-programa
- **Conceitos-chave:** comentários `/* */`, `#include <stdio.h>`, `main` como função onde a execução começa, bloco `{}`, instrução termina em `;`, `\n`, `return 0` como sinal de sucesso para o sistema.
- **Pegadinhas (erros comuns 2.1–2.4):** comentário não fechado; abrir com `*/`; `print` no lugar de `printf`; `Main` com maiúscula. Um `printf` continua de onde o anterior parou, e várias linhas podem sair de um único `printf`.
- **Exercícios bons:** 2.17 imprimir 1 2 3 4 de três formas (um printf sem conversões, um com `%d`, quatro printfs); 2.21 desenhar retângulo, elipse, seta e losango com `*`; 2.25 iniciais com a própria letra; 2.27 tabuleiro de `*` com o **menor número de printfs**; 2.22 "o que imprime `printf("*\n**\n***\n")`".

### 0007-variaveis
- **Conceitos-chave:** toda variável tem **nome, tipo e valor** e corresponde a um local na memória. **Leitura destrutiva:** gravar substitui o valor antigo. **Leitura não destrutiva:** ler preserva o valor. Diagramas de "caixinhas" mostram os estados antes e depois de cada linha do programa de soma (45, 72, 117). Regras de identificador; C diferencia maiúsculas de minúsculas.
- **Pegadinhas:** `a1` e `A1` são diferentes; nomes que começam com dígito são inválidos.
- **Exercícios:** 2.10 V/F: quais nomes são válidos (`_barra_inferior`, `m928134`, `3g`, `67h2`, `2h`…). 2.13: quais instruções envolvem leitura destrutiva (o `scanf` e a atribuição sim; `printf` não).

### 0008-tipos-e-limites
- **Conceitos-chave:** `short` (±32767 no mínimo), `long` (±2147483647), `int` entre os dois, `unsigned`, `char` (±127). Tabela de `sizeof` (char 1, short 2, int 2, long 4, float 4, double 8, long double 10, no Borland). `limits.h` e `float.h` no Apêndice A.14 com os **mínimos garantidos** pelo padrão. Use `sizeof` em vez de supor tamanhos.
- **Pegadinhas:** `printf("%u", -455)` imprime 65081 numa máquina de 16 bits. O fatorial estoura rápido: "que problema impede calcular 20!?" (4.14). Fibonacci: "qual o maior que seu sistema imprime? Troque para double" (5.38b).
- **Exercício:** 11.16 imprimir a tabela de `sizeof` de todos os tipos num arquivo.
- **Atualizar no curso:** hoje `int` tem 4 bytes; use `stdint.h`, que o livro não tem.

### 0009-constantes
- **Conceitos-chave:** tabela completa de escapes (`\n \t \r \a \\ \" \' \? \b \f \v`); `#define TAMANHO 10` com nome em MAIÚSCULAS; `const` em parâmetros; constante de caractere `'A'` × string `"A"`.
- **Pegadinhas:** `#define` com `;` final (o `;` entra na substituição); `#define PI = 3.14159` (o `=` entra no texto); atribuir a uma constante simbólica é erro, porque não é variável; aspas duplas em constante de caractere geram uma string de 2 bytes.
- **Exercício:** 9.14 testar cada escape imprimindo um caractere antes e outro depois. 9.15/9.19: `?` precisa de `\?`?

### 0010-printf (Cap. 9 — o melhor do livro sobre o assunto)
- **Conceitos-chave:** especificadores `d i o u x X e E f g G c s p n %`; modificadores `h l L`; **largura** (alinha à direita e cresce se o valor não couber), **precisão** (inteiros: mínimo de dígitos com zeros; `e`/`f`: casas decimais; `g`: dígitos significativos; `s`: máximo de caracteres), `*` para largura ou precisão vindas de argumentos (`%*.*f`, 7, 2, 98.736 → `  98.74`). Flags `- + espaço # 0`. Regra do `%g`: usa notação `e` se o expoente < −4 ou ≥ precisão (0.0000875 → 8.75e−05, 8750000.0 → 8.75e+06). `printf` **retorna** o número de caracteres impressos; `%n` guarda essa contagem.
- **Analogia boa:** o problema do dinheiro em float: 14.234 + 18.673 aparecem como 14.23 + 18.67 = **32.91**. A soma "visível" não fecha. É a melhor motivação para usar centavos em inteiros (4.23).
- **Pegadinhas:** `%c` com string, `%s` com char (violação de acesso), `%` sozinho, `%d` com 10.987, esquecer o argumento, vírgula dentro das aspas, precisão no `scanf`.
- **Exercícios (com resposta):** 4.3b `333.546372` com `%-15.1f`…`%-15.5f` → 333.5 / 333.55 / 333.546 / 333.5464 / 333.54637; `%.2f` de 123.4567 → 123.46; `pow(2.5,3)` com `%10.2f` → 15.63; `%+09d` de 452 → +00000452; `%#o` de 1427 → 02623; `%#x` → 0x593; `%.4d` de 873 → 0873; `%.11s` de "Happy Birthday" → "Happy Birth". 9.5: prever a saída de `%-10d`, `%#X`, `% ld`, `%10.2E`, `%10.2g`. 9.20: 9876.12345 com `%g` e precisões de 1 a 9. 9.7: usar `%n` para totalizar caracteres impressos.

### 0011-scanf
- **Conceitos-chave:** o `&` diz "onde guardar" (a explicação completa vem nos ponteiros). Arrays vão sem `&`. `%lf` para double (no printf é `%f`, tabela da Fig. 5.5). `%i` aceita 070 (octal → 56) e 0x70 (hexa → 112). **Conjunto de varredura** `%[aeiou]` e invertido `%[^aeiou]`; **largura** `%2d%d` com "123456" → 12 e 3456; **supressão** `%*c` para ler a data 11-18-71 ou 11/18/71 com o mesmo formato; literais no formato (`"%d-%d-%d"`, `"%f%%"`). `scanf` retorna o número de itens atribuídos ou EOF (Apêndice A).
- **Pegadinhas:** esquecer o `&` (falha de segmentação); `&` no `printf`; vírgulas entre especificadores; `%s` lê só até o espaço ("Hello there" → "Hello") e **não limita o tamanho**; ler `100 A` com `scanf("%d")` seguido de `getchar()` pega o espaço (exercício 4.4c); `scanf("\n%c")` para pular o `\n` que ficou no buffer (usado nos programas de lista e fila).
- **Exercícios:** 9.3f ler até achar um não-dígito → `%[^0123456789]`; 9.4g ler hh:mm:ss com e sem `%*c`; 9.8 comparar `%i` e `%d` com 10, −10, 010, 0x10; 9.18 as aspas fazem parte da string lida?

### 0012-aritmetica
- **Conceitos-chave:** divisão inteira (7/4 = 1, 17/5 = 3), `%` só para inteiros (7%4 = 3, 17%5 = 2), precedência e associatividade, expressões em "linha reta". Polinômio `y = a*x*x + b*x + c` calculado **passo a passo** (a=2, b=3, c=7, x=5 → 72).
- **Pegadinhas:** `a + b + c + d + e / 5` × `(a + ... + e) / 5`; não há operador de potência; divisão por zero é erro fatal; erro fatal × não fatal (2.28: por que preferir o fatal?).
- **Exercícios (com resposta):** 2.15 `x = 7 + 3*6/2 - 1` → 15; `2%2 + 2*2 - 2/2` → 3; `(3*9*(3+(9*3/(3))))` → 324. 2.14 quais expressões equivalem a y = ax³ + 7 (a, d, e). 2.30 separar 42339 em `4   2   3   3   9` (`/` e `%`). 2.24 par ou ímpar. 2.26 múltiplo.

### 0013-conversao
- **Conceitos-chave:** cast `(float) total / contador` cria uma **cópia temporária**; promoção implícita para o "maior" tipo da expressão; hierarquia long double > double > float > unsigned long > long > unsigned > int > short > char. O protótipo **converte argumentos** (`sqrt(4)` funciona).
- **Pegadinhas:** `square(4.5)` com parâmetro int retorna **16**, não 20.25. Converter para um tipo menor trunca. 3.3 hoje é atribuído `x = y` (float para int) e impresso como `(float)x`.
- **Exemplo:** média 817/10 dá 81 com int; com cast, 81.70.

### 0014-atribuicao
- **Conceitos-chave:** `+= -= *= /= %=` (tabela com c=3, d=5, e=4, f=6, g=12 → 10, 1, 20, 2, 3); pré e pós-incremento (programa 5 5 6 / 5 6 6); isolados, os dois são equivalentes; `++` só em nome de variável (`++(x+1)` é erro); `a = b = c = 0` funciona porque a atribuição tem valor e associa da direita para a esquerda.
- **Pegadinhas:** usar a mesma variável incrementada duas vezes na expressão (o livro adverte, mas veja abaixo).
- **Exercícios:** 3.2 quatro formas de somar 1 a x. 3.3 `z = x++ + y`; `total -= --x`; `total += x--`. 3.5a `produto *= x++` com tudo valendo 5 → produto 25, x 6. ⚠ 3.5b `resultado = ++x + x`: o livro responde 12, mas é **comportamento indefinido**. Use como pegadinha.

### 0015-math
- **Conceitos-chave:** tabela de sqrt, exp, log, log10, fabs, ceil, floor, pow, fmod, sin, cos, tan (tudo em double); incluir `math.h`. Arredondamento com `floor(x + .5)` e casas com `floor(x*100+.5)/100`.
- **Pegadinhas:** `ceil(-9.8)` = −9 e `floor(-9.8)` = −10. Esquecer o `math.h` (sem protótipo, `pow` recebia int). ⚠ A Fig. 5.2 tem erros (ver Obsoleto).
- **Exercícios:** 5.8 valores de `fabs(7.5)`, `floor(7.5)`, `ceil(-6.4)` e `ceil(-fabs(-8+floor(-5.5)))` (→ −14). 5.11 quatro funções `arredondaPara{Inteiro,Decimos,Centesimos,Milesimos}`. 5.15 hipotenusa de (3,4), (5,12), (8,15). 5.45 distância entre pontos. 9.11 100.453627 arredondado em 5 níveis.

### 0016-juntando-tudo
- **Ideias de projeto do módulo:** 3.35 palíndromo de 5 dígitos (12321); 3.46 **criptografia** de 4 dígitos (cada dígito vira (d+7)%10, depois troca o 1º com o 3º e o 2º com o 4º) e o programa que decifra; 2.19 soma, média, produto, menor e maior de três inteiros (13 27 14 → 54, 18, 4914, 13, 27); 2.31 tabela de quadrados e cubos; 3.42 círculo (diâmetro, circunferência, área).

---

## 02 — Condicionais

### 0017-relacionais
- **Conceitos-chave:** `== != < > <= >=`; os relacionais têm precedência maior que os de igualdade; qualquer expressão serve de condição (0 é falso, não zero é verdadeiro); comparações resultam em 0 ou 1.
- **Pegadinhas:** espaço dentro de `= =`; `=!`, `=>`, `=<` invertidos; ler `==` como "é igual a" e `=` como "recebe".
- **Exemplo:** Fig. 2.13: seis `if` comparando dois números (3 7 / 22 12 / 7 7).

### 0018-logicos
- **Conceitos-chave:** `&&`, `||`, `!`, tabelas-verdade com "diferente de zero", **curto-circuito**, `&&` tem precedência maior que `||`. O padrão só garante ordem de avaliação para `&& || ?: ,`.
- **Dica boa:** em `&&`, ponha à esquerda a condição mais provavelmente falsa; em `||`, a mais provavelmente verdadeira.
- **Exercícios (com resposta):** 4.24 com i=1, j=2, k=3, m=2: `i == 1` → 1; `j == 3` → 0; `m <= 99 && k < m` → 0; `k + m < j || 3 - j >= k` → 0; `!m` → 0; `!(j - m)` → 1; `!(k > m)` → 0. 4.29 **De Morgan**: reescrever `!(x < 5) && !(y >= 7)` etc. e provar a equivalência com um programa. ⚠ O enunciado do livro escreve a segunda lei errado (`!(a||b) == !a || !b`); corrigir para `!a && !b`.

### 0019-if
- **Conceitos-chave:** seleção simples; corpo com uma instrução ou instrução composta `{}`; instrução vazia `;`.
- **Pegadinhas:** `if (c < 7);` faz o printf rodar sempre (resposta 2.6c explica que o `;` é uma instrução vazia).

### 0020-if-else
- **Conceitos-chave:** seleção dupla; recuo nos dois ramos; esquecer as chaves faz a 2ª linha do else rodar sempre ("Você deve fazer este curso novamente").
- **Seção-destaque (4.11):** troca de `==` por `=`: `if (codigoPagamento = 4)` dá bônus a **todos**. Truque: escrever `7 == x` para o compilador acusar o erro. Explica **lvalue × rvalue**. O inverso (`x == 1;` como instrução) compila e não faz nada.
- **Pegadinha:** `;` depois do if num if/else é erro de sintaxe; `;` depois do `else` é erro lógico (3.8c).

### 0021-else-if
- **Conceitos-chave:** if/else aninhado para notas A ≥ 90, B ≥ 80, C ≥ 70, D ≥ 60, F; as duas formas de recuo são equivalentes para o compilador.
- **Exercícios excelentes ("else oscilante"):** 3.31 determinar a saída com o código **sem recuo** para x=9, y=11 e x=11, y=9. 3.32 inserir **apenas chaves** no mesmo código para produzir quatro saídas diferentes (@@@@@ / $$$$$ / &&&&&). O compilador associa o else ao if anterior mais próximo.

### 0022-ternario
- **Conceitos-chave:** único operador ternário; pode retornar valor (`printf("%s\n", grau >= 60 ? "Aprovado" : "Reprovado")`) ou executar ações.
- **Exercícios:** 3.29 o que imprime `contador % 2 ? "****" : "++++++++"` num laço; 3.30 o mesmo com `<` e `>` em laços aninhados.

### 0023-switch
- **Conceitos-chave:** só funciona com **expressão constante inteira**; vários `case` juntos (`'A'` e `'a'`); `break`; `default` por último (boa prática); `default` final não exige break.
- **Exemplo-destaque:** Fig. 4.7 conta conceitos A–F lidos com `while ((grau = getchar()) != EOF)`, ignora `'\n'` e `' '` com cases vazios e usa `int` porque EOF é int.
- **Pegadinhas:** esquecer o break (4.4c: case 1 cai no case 2); `switch (valor % 2)` sem break imprime "par" e "ímpar" (exercício 4.4b); não tratar o `\n` ao ler caractere por caractere.
- **Exercícios:** 4.19 loja com 5 produtos (preços 2.98, 4.50, 9.98, 4.49, 6.87) lê pares (produto, quantidade) e soma o total com switch; 4.30 reescrever o switch da Fig. 4.7 com if/else e depois só com ifs (mostra que o switch é uma conveniência); 4.39 remover os breaks.

### 0024-juntando-tudo
- **Projeto:** 4.28 folha de pagamento com 4 códigos (gerente fixo; horista com 1,5× acima de 40 h; comissionado $250 + 5,7%; por peça), usando switch e sentinela.

---

## 03 — Repetições

### 0025-while
- **Conceitos-chave:** condição testada antes; o corpo deve tornar a condição falsa em algum momento.
- **Exemplo:** primeira potência de 2 maior que 1000 (`produto = 2; while (produto <= 1000) produto *= 2;` → 1024), com o rastro 4, 8, …, 1024.
- **Pegadinhas:** `While` com maiúscula; `while (z >= 0) soma += z;` vira laço infinito (3.9); `;` depois do while; esquecer as chaves faz só a 1ª linha repetir (Fig. 3.8 "interpretada errado").
- **Exercícios:** 3.11 achar erros (total não inicializado; `++y` num laço `y > 0`); 3.13 "o que imprime" (soma de quadrados, com erros de sintaxe propositais); 3.37 contar até 3.000.000 e cronometrar cada milhão; 3.41 laço infinito de potências de 2: o que acontece? (overflow).

### 0026-do-while
- **Conceitos-chave:** testa depois, então executa pelo menos uma vez; use chaves para não confundir `while (cond);` com um while de corpo vazio.
- **Exercícios:** 3.28 **validar** entrada 1/2 até ser válida; 4.34 converter do/while em while e vice-versa (que estrutura extra é necessária?).

### 0027-for
- **Conceitos-chave:** os 4 elementos da repetição por contador (nome, valor inicial, incremento, condição final); equivalência for ↔ while (com uma exceção, o continue); as três expressões são opcionais; operador vírgula; incremento negativo; o corpo pode nem executar.
- **Pegadinhas (catálogo ótimo):** **off-by-one** (`< 10` × `<= 10`; recomenda usar o valor final com `<=`); controlar o laço com float (`for (y = .1; y != 1.0; y += .1)` nunca termina; correção: contador inteiro e `(float)y/10`); vírgulas no lugar de `;`; `;` depois do cabeçalho; modificar a variável de controle no corpo; `for (x = 999; x >= 1; x += 2)`; `for (x = 100, x >= 1, x++)` (4.4a).
- **Exemplos:** soma dos pares de 2 a 100 = 2550; juros compostos `a = p(1+r)^n` com p = 1000, r = 5%, 10 anos (1050.00 … 1628.89) usando `pow`, `%4d%21.2f`; versão em centavos inteiros (4.23); variar a taxa de 5% a 10% (4.15).
- **Exercícios (com resposta):** 4.6 quais valores imprimem `for(x=2;x<=13;x+=2)` (2..12), `for(x=5;x<=22;x+=7)` (5,12,19), `for(x=1;x<=5;x+=7)` (1), `for(x=12;x<=2;x-=3)` (nada). 4.7 escrever `for` para 3,8,13,18,23 e 19,27,35,43,51. 4.3d imprimir 1..20 com 5 por linha usando `x % 5`. 4.26 aproximar π por 4 − 4/3 + 4/5 − …: quantos termos até 3.14? 3.14159? 3.47 fatorial e a série de *e* e de *eˣ*.

### 0028-break-continue
- **Conceitos-chave:** `break` sai do laço ou do switch (Fig. 4.11: 1 2 3 4, sai em x == 5); `continue` pula para a próxima iteração (Fig. 4.12: 1..10 sem o 5). **No for, o continue executa o incremento; no while, não**. É por isso que for e while não são 100% equivalentes.
- **Exercícios:** 4.36/4.38 remover break e continue de forma estruturada (flag na condição).

### 0029-lacos-aninhados
- **Exercícios-destaque:** 4.16 quatro triângulos de `*` (dois exigem espaços à esquerda) com um único `printf("*")`; 4.40 **losango** com o mínimo de printfs e 4.31 losango de tamanho ímpar lido; 3.33/3.34 quadrado cheio e **vazado** de lado 1–20; 3.40 tabuleiro usando só `printf("* ")`, `printf(" ")` e `printf("\n")`; 4.18 histograma de 5 números; 4.27 **ternos pitagóricos** < 500 por **força bruta** com 3 for aninhados (e a discussão de por que a força bruta importa); 4.37 "o que faz" (3 laços imprimindo blocos de `*`); 4.8 retângulo de `@` x por y.

### 0030-padroes-de-laco
- **Conceitos-chave:** contador × total (acumulador); sentinela que **não** pode ser um dado válido (−1 para notas); repetição definida × indefinida; quando usar sentinela (número desconhecido + leitura a cada volta); mensagem de prompt informando a sentinela; dado inicial com a contagem ("5 100 200 300 400 500").
- **Exercícios:** 3.24 maior de 10 (variáveis contador, num, maior); 3.27 **os dois maiores** (cada número lido uma única vez); 4.9 primeiro valor = quantidade; 4.10 sentinela 9999; 4.11 menor; 3.38 100 asteriscos com `\n` a cada 10; 3.39 contar dígitos 7 de um inteiro; 5.26 números perfeitos até 1000 (6 = 1+2+3); 5.27 primos até 10.000 com o teste até √n (por quê?); 5.28 inverter os dígitos (7631 → 1367).

### 0031-aleatorios
- **Conceitos-chave:** `rand()` vai de 0 a RAND_MAX (no mínimo 32767); **fator de escala** e **deslocamento**: `n = a + rand() % b`; números pseudoaleatórios: a mesma sequência a cada execução ajuda a depurar; `srand(semente)` e `srand(time(NULL))`; Apêndice A traz uma implementação portátil (gerador congruente linear `next = next*1103515245 + 12345`).
- **Exemplos:** 20 lançamentos de dado; 6000 lançamentos com contagem de faces (primeiro com switch, depois com array, mostrando a melhoria); **craps** completo (`rollDice`, `gameStatus` 0/1/2, ponto).
- **Pegadinhas:** usar `srand` no lugar de `rand`; `int randomNumber = srand();` (5.50c).
- **Exercícios-destaque:** 5.13 escrever a expressão para os intervalos 1–2, 1–100, 0–9, 1000–1112, −1–1, −3–11; 5.14 sortear de **conjuntos não consecutivos** {2,4,6,8,10}, {3,5,…,11}, {6,10,…,22} (resposta: `2 + 2*(rand()%5)` etc.); 5.31 moeda com 100 jogadas; 5.32–5.34 **CAI de tabuada** (comentários aleatórios para acerto e erro, ajuda abaixo de 75%); 5.35–5.36 **adivinhe o número** de 1 a 1000 (por que 10 palpites bastam? → busca binária); 5.51 craps com apostas e saldo; 6.19 soma de dois dados 36.000 vezes (7 deve sair cerca de 1/6 das vezes); 6.20 1000 partidas de craps com estatísticas; 7.17 **corrida da lebre e da tartaruga** (tabela de probabilidades, 70 casas, "OUCH!!!").

---

## 04 — Funções

### 0033-funcoes
- **Conceitos-chave:** dividir para conquistar; função definida pelo programador × biblioteca; formato da definição; `return;` × `return expr;` × fim pela chave; **protótipo** (o compilador verifica tipo de retorno, quantidade, tipos e ordem dos argumentos).
- **Analogia boa:** **chefe e subordinado**. O chefe pede a tarefa e não sabe como o subordinado a fez; o subordinado pode ter seus próprios subordinados (Fig. 5.1). Isso motiva ocultação de informação.
- **Boas práticas:** uma função faz uma tarefa e o nome a expressa; se não achar um nome curto, ela faz coisas demais; muitos parâmetros indicam o mesmo problema; função de meia página.
- **Pegadinhas:** `;` depois do cabeçalho da definição; definir uma função dentro de outra; redeclarar parâmetro como local; retornar valor de função void; esquecer o return em função não void.
- **Exercícios:** 5.4/5.5 escrever cabeçalhos e protótipos (hipotenusa, menor de 3, instrucoes, intToFloat); 5.7 e 5.50 "encontre o erro" (função h dentro de g, soma sem return, recursão sem return, `void f(float a); {float a;...}`); 5.9 **estacionamento** ($2 até 3 h, +$0,50 por hora ou fração, máximo $10; tabela 1.5 h → 2.00, 4.0 → 2.50, 24.0 → 10.00, total 14.50); 5.17 múltiplo; 5.18 par; 5.23 segundos desde a última "hora cheia"; 5.24 celsius/fahrenheit; 5.30 pontos de qualificação (4..0).

### 0034-parametros
- **Conceitos-chave:** em C **toda chamada é por valor**; a "referência" é simulada com ponteiros (cap. 7); arrays são passados como endereço.
- **Pegadinha obsoleta:** `float x, y` na lista de parâmetros deixava `y` como int (C89 com "int implícito"). Hoje é erro de compilação; vale como curiosidade.

### 0035-escopo
- **Conceitos-chave:** atributos de um identificador: classe de armazenamento, duração, escopo e ligação; `auto`, `register`, `extern`, `static`; duração automática × estática; static local mantém o valor e é zerado se não for inicializado; **4 escopos**: função (só rótulos), arquivo, bloco, protótipo.
- **Exemplo-destaque (Fig. 5.12):** x global = 1; x local de main = 5; bloco interno com x = 7; função a() com x automático = 25 (reinicia a cada chamada); b() com static x = 50 (51, 52…); c() usa o global (×10). É ótimo para teste de mesa. Saída: 5 7 5 | 25 26 | 50 51 | 1 10 | 25 26 | 51 52 | 10 100 | 5.
- **Exercício:** 5.2 dar o escopo de cada identificador num programa curto (`y` no protótipo tem escopo de protótipo).
- **Pegadinha:** sombreamento acidental de nome do bloco externo.

### 0036-pilha-de-chamadas
- **O que o livro tem:** as Figs. 7.8/7.9 mostram, em 5 quadros, chamada por valor × por referência (variáveis de main e da função, "não definido" antes e depois). O Cap. 12 explica que a pilha guarda endereços de retorno e variáveis automáticas (LIFO).
- **Exercício:** 5.41 **visualizar a recursão** imprimindo o parâmetro com recuo crescente a cada nível.

### 0037-recursao
- **Conceitos-chave:** caso base; o passo recursivo é "um pouco menor" e deve convergir; a sequência de retornos acontece em ordem inversa (Fig. 5.13: 5! = 5×24 … com setas de ida e volta); recursão × iteração (ambas repetem e testam o término; a recursão custa chamadas e memória; qualquer recursão pode virar iteração).
- **Exercícios-destaque:** 5.47 "mistério" (`a + misterio(a, b-1)` = multiplicação) e 5.48 aceitar b negativo; 5.46 `main` recursiva que imprime a entrada **ao contrário** com getchar; 5.43 `main` pode ser recursiva? (static contagem); 6.17 soma recursiva de array; 6.18 imprimir array de trás para frente com `&b[1]`; 6.37–6.39 imprimir array, string invertida, mínimo recursivo; 6.33 palíndromo recursivo ignorando espaços.

### 0038-recursao-na-pratica
- **Conteúdo:** fatorial com long; Fibonacci (a seção de texto falta no arquivo, mas a dica de desempenho 5.4 adverte para a "explosão exponencial"); **Torres de Hanói** com o algoritmo em 3 passos (mover n−1 para o auxiliar, mover o maior, mover n−1 para o destino) e a saída para 3 discos (1→3 1→2 3→2 1→3 2→1 2→3 1→3); 5.40 Hanói iterativa; **MDC de Euclides** recursivo (5.42: se y == 0, mdc = x; senão mdc(y, x%y)) e iterativo (5.29); 5.37 potência recursiva. A Fig. 5.17 lista os **31 exemplos de recursão** do livro (labirinto, quicksort, oito damas, busca binária, lista e árvore).

### 0039-modulos
- **Conceitos-chave:** `#include "square.h"` (procura primeiro no diretório do fonte) × `<...>`; cabeçalho com structs, enums e protótipos comuns; `cc main.c square.c`; um protótipo **dentro** de uma função limita quem pode chamá-la (swap dentro de classBolha, que o livro trata como privilégio mínimo).
- **Falta:** include guards (`#ifndef X_H`) não aparecem para esse fim; completar com outra fonte.

### 0040-preprocessador (Cap. 13)
- **Conceitos-chave:** macros com argumentos e **parênteses em cada uso e em volta de tudo** (`AREA_CIRCULO(c + 2)` sem parênteses vira `3.14159*c+2*c+2`); a macro avalia o argumento duas vezes (não passe `x++`); `#undef`; continuação com `\`; `#if !defined(NULL)`, `#ifdef`/`#ifndef`, `#elif`/`#else`; **`#if 0 … #endif` para "comentar" código que já tem `/* */`**; `#ifdef DEBUG` com printf de depuração (dentro de `{}` para não alterar o fluxo); `#error`, `#pragma`; `#` (vira string) e `##` (concatena tokens); `#line`; `__LINE__ __FILE__ __DATE__ __TIME__ __STDC__`; `assert` e `NDEBUG`; `getchar()` costuma ser uma macro de `getc(stdin)`.
- **Pegadinha boa:** ⚠ a própria resposta 13.3h define `VOLUME_CUBO(x) (x)*(x)*(x)` **sem parênteses externos**. Peça ao aluno para achar o caso que quebra (`1/VOLUME_CUBO(2)`).
- **Exercícios:** 13.4 volume da esfera (raios 1–10); 13.6/13.7 `MINIMUM2` e `MINIMUM3` usando a primeira; 13.9/13.10 macro que imprime ou soma um array; 13.3e–g diretivas condicionais (redefinir VERDADE com e sem `#ifdef`).

### 0041-juntando-tudo
- **Projeto:** craps com apostas (5.51) ou CAI completo (5.44: nível de dificuldade e tipo de operação 1–5 com mistura aleatória).

---

## 05 — Vetores e strings

### 0042-vetores
- **Conceitos-chave:** índices de 0 a n−1; "sétimo elemento" (c[6]) × "elemento sete" (c[7]); `[]` é operador; inicializadores (os que faltam viram 0; `int n[10] = {0}`; inicializadores demais são erro; tamanho omitido é deduzido); `#define TAMANHO` torna o programa "escalável"; **C não verifica limites**; array static local é zerado uma vez e mantém valores (Fig. 6.11 compara static × automático).
- **Exemplo-destaque:** pesquisa da cantina: 40 respostas de 1 a 10, `++frequencia[respostas[i]]` com frequencia[11] ignorando o índice 0 (clareza vale mais que economizar 1 elemento). Um dado inválido como 13 escreveria fora do array. Também: histograma com `*`; dado 6000× com array em vez de switch.
- **Pegadinhas:** `for (i = 0; i <= 10; i++)` em b[10]; supor que um static local é zerado a cada chamada.
- **Exercícios:** 6.10 vendedores por **faixa salarial** ($200–299 … $1000+) com array de contadores; 6.15 ler 20 números de 10 a 100 e imprimir **sem duplicatas** com o menor array possível; 6.28 idem com aleatórios; 6.21 **reserva de assentos** em avião de 10 lugares (dois setores, oferecer o outro setor quando um enche); 6.30 **crivo de Eratóstenes** até 999; 6.3 tarefas sobre `fracoes[TAMANHO]` com respostas.

### 0043-vetores-e-funcoes
- **Conceitos-chave:** passe o nome e o tamanho; o nome do array é `&a[0]` (Fig. 6.12 imprime os dois com `%p`); a função altera o original; um **elemento** isolado vai por valor (Fig. 6.13: `modificaArray` dobra tudo, `modificaElemento(a[3])` não altera a[3]); `const int b[]` impede alteração (erro "Cannot modify a const object"); "dá para passar um array por valor colocando-o dentro de uma struct".
- **Exercício:** prever a saída da Fig. 6.13 (0 1 2 3 4 → 0 2 4 6 8; a[3]: 6, 12, 6).

### 0044-matrizes
- **Conceitos-chave:** `a[i][j]` com linha e coluna; inicialização por linhas (`{{1},{3,4}}` → 1 0 / 3 4); armazenamento **linha após linha**; no parâmetro, só a 1ª dimensão pode ser omitida (`int a[][3]`), porque o compilador precisa saber quantos elementos pular por linha; `a[i]` é o endereço da linha (passar uma linha a uma função 1D); `a[x, y]` é erro (operador vírgula).
- **Exemplo:** notas de alunos (linhas) × provas (colunas) com mínimo, máximo e média por aluno.
- **Exercícios:** 6.9 matriz 2×5 t (lista de 14 tarefas: nomes da 2ª linha, 3ª coluna, zerar sem laço, menor valor, tabela formatada); 6.16 ordem em que for aninhado zera `vendas[3][5]`; 6.22 vendas 4 vendedores × 5 produtos com **totais de linha e coluna**; 6.4 `tabela[3][3] = {{1,8},{2,4,6},{5}}` (prever a saída); 6.23 **gráficos da tartaruga** (plano 50×50, comandos 1–6 e 9, quadrado 12×12); 6.24 **passeio do cavalo** (vetores `horizontal[]`/`vertical[]`, heurística de acessibilidade 2/3/4/6/8 e desempate olhando um passo à frente); 6.26 **oito damas** (heurística dos "22 eliminados" no canto); 6.25/6.27 versões força bruta; 6.29 passeio fechado.

### 0045-caracteres
- **Conceitos-chave:** char é um inteiro pequeno (`printf("%c %d", 'a', 'a')` → a 97); variável que recebe `getchar()` deve ser **int** por causa do EOF; tabela de ctype (isdigit, isalpha, isalnum, isxdigit, islower, isupper, tolower, toupper, isspace, iscntrl, ispunct, isprint, isgraph); maiúscula = minúscula − 32 em ASCII; ASCII × EBCDIC.
- **Explicação boa:** a tabela ASCII do Apêndice C usa linha = dezenas e coluna = unidades ('F' = 70, '&' = 38). É uma boa forma de ensinar a ler a tabela.
- **Exercícios:** 2.29 imprimir os códigos de A B C a b c 0 1 2 $ * + / e espaço; 8.22 V/F sobre a ordem ASCII (dígitos antes das letras? ')' antes de '('?); 8.26 **reescrever as funções de ctype**; 8.25 imprimir os caracteres de 000 a 255.

### 0046-strings
- **Conceitos-chave:** string é um array de char terminado em `'\0'`; "primeiro" ocupa 9 bytes; o valor de uma string é o endereço do 1º caractere; inicialização com literal ou com lista de chars. Biblioteca completa em quadros: strcpy/strncpy/strcat/strncat, strcmp/strncmp, strchr/strrchr/strstr/ strpbrk/strspn/strcspn/strtok, memcpy/memmove/memcmp/memchr/memset, strlen, strerror, atof/atoi/atol, strtod/strtol/strtoul (com ponteiro para o "resto" e base 0/2–36), sprintf/sscanf.
- **Pegadinhas (as melhores):** **strncpy não coloca '\0'** se n ≤ comprimento (8.4a: `strncpy(s, "hello", 5)`); **strcmp retorna 0 quando são iguais** (8.4d: `if (strcmp(a,b))` testa *diferença*); **strtok modifica a string** (faça cópia); só memmove é seguro com sobreposição (`memmove(x, &x[4], 8)` em "Lar Doce Lar" → "Doce Lar Lar"); `printf("%s", 'a')`; array sem espaço para o '\0' (8.4c: `char s[12]` para "Bem-vindo ao Lar"); "string" sem terminador.
- **Exercícios (com resposta):** 8.3 com s1 = "jack", s2 = "jill": `toupper(s1[0])` + `&s1[1]` → Jack; `strcat(strcat(strcpy(s3,s1)," e "),s2)` → "jack e jill"; `strlen(s1)+strlen(s2)` → 8. 8.1 escrever 23 chamadas (strrchr, strpbrk, strtok com vírgula, sprintf com `%7d`…). 8.28/8.30/8.33 implementar strcpy, strcat, strcmp e strlen em **duas versões, com índice e com ponteiro**. 8.31/8.32 reimplementar as funções de busca e de memória.
- **Exercícios de aplicação:** 8.13 "**latim pobre**" (salto → altosai) com strtok; 8.14 telefone "(555) 555-5555" → código de área int + número long; 8.11 frases aleatórias com arrays artigo, substantivo, verbo e preposição; 8.19 frequência de letras com strchr; 8.21 ordenar nomes de cidades com strcmp + bubble.

### 0047-lendo-strings
- **O que o livro faz:** usa **`gets`** (Fig. 8.13 e exercícios 8.1e e 8.6) e `scanf("%s")` sem limite, avisando apenas que é "responsabilidade do programador". A alternativa segura que ele mostra é o laço `while ((c = getchar()) != '\n') s[i++] = c; s[i] = '\0';` (Fig. 8.14, também sem checar limite). `fgets` só aparece nos arquivos e no Apêndice A, que descreve corretamente que ele **retém o '\n'**.
- **Uso no curso:** ótimo **contraexemplo**: pedir ao aluno para explicar por que a Fig. 8.13 é perigosa e reescrevê-la com fgets, tirando o '\n'.

### 0048-juntando-tudo
- **Projetos:** 8.37 **proteção de cheques** (`***99.87` em 9 posições); 8.38 **valor por extenso** (112.43 → "CENTO E DOZE e 43/100"); 8.36 data 21/07/55 → "21 de julho de 1955"; 8.39 **Morse** nos dois sentidos (1 espaço entre letras, 3 entre palavras; a tabela vem pronta); 8.34 **análise de texto** (frequência de letras, histograma de tamanhos de palavra, contagem de palavras distintas); 8.35 **justificação** em 65 colunas; 8.40 conversor de unidades que rejeita conversões sem sentido; 8.41 cartas de cobrança com 5 níveis de severidade.

---

## 06 — Ponteiros

### 0049-memoria
- **Conceitos-chave:** referência direta (pelo nome) × indireta (pelo ponteiro), Fig. 7.1; diagrama com endereços (y em 600000, yPtr em 500000 guardando 600000); `%p`; `&` e `*` se complementam (`&*aPtr` == `*&aPtr`).
- **Exercício:** 7.4 sequência com `fPtr`, `numero1 = 7.3`, imprimir `&numero1` e `fPtr` e comparar.

### 0050-ponteiros
- **Conceitos-chave:** `int *contPtr, cont;` declara só um ponteiro; sufixo `Ptr` como convenção; inicializar com 0, NULL ou um endereço (0 é o único inteiro atribuível); `&` não se aplica a constantes, expressões nem variáveis `register`.
- **Pegadinhas:** desreferenciar ponteiro não inicializado (7.23a `int *number; printf("%d", *number)`); `char *s; printf("%s", s)` (7.23g); `float xPtr = &x` sem `*` (7.23f).
- **Exercícios (com resposta):** 7.6 encontre o erro (zPtr não inicializado; `numero = zPtr` sem `*`; `*zPtr[2]`; laço até 5; `*sPtr` com void*; `++z` em nome de array). 7.2 V/F sobre `&` e void*.

### 0051-passagem-por-referencia
- **Conceitos-chave:** `cuboPorValor` (retorna) × `cuboPorReferencia(&numero)` (altera `*nPtr`); `int b[]` e `int *b` são intercambiáveis como parâmetro; regra: use por valor a menos que a função *precise* alterar; com um só valor alterado, prefira o retorno; para alterar vários, use ponteiros. **As 4 combinações de const** (não const/não const, Fig. 7.10 `converteParaMaiusculas`; ponteiro para dado const, Fig. 7.11 `imprimeCaracteres`; ponteiro const, Fig. 7.13; ambos const, Fig. 7.14), lidas **da direita para a esquerda**.
- **Exemplo-destaque:** bubble sort com `swap(&array[j], &array[j+1])` (Fig. 7.15) mostra que a função não "enxerga" o array e mesmo assim troca os elementos via ponteiros.
- **Dica boa:** passar uma struct grande por `const T *` dá desempenho de referência com a segurança de valor.
- **Exercício:** 7.5 cabeçalho e protótipo de `exchange(float *x, float *y)` e de `evaluate(int x, int (*poly)(int))`.

### 0052-ponteiros-e-vetores
- **Conceitos-chave:** aritmética de ponteiros escalada pelo tamanho do tipo (`vPtr += 2` de 3000 vai a 3008 com int de 4 bytes ou 3004 com 2); subtrair ponteiros dá o número de elementos; só tem sentido no mesmo array; **quatro notações** (Fig. 7.20): `b[i]`, `*(b + i)`, `bPtr[i]`, `*(bPtr + i)`; o nome do array é um ponteiro constante (`b += 3` é erro); `*bPtr + 3` × `*(bPtr + 3)`; `sizeof(array)/sizeof(tipo)` conta elementos; `sizeof` é operador de tempo de compilação (parênteses obrigatórios com tipo).
- **Exercícios (com resposta):** 7.3 array `numeros[10]` em 1002500 com float de 4 bytes: `nPtr + 8` → 1002532 (valor 8.8); `nPtr` em numeros[5] menos 4 → 1002504 (valor 1.1); escrever o elemento 4 nas 4 notações. 7.9 o mesmo com unsigned de 2 bytes.

### 0053-ponteiros-e-strings
- **Conceitos-chave:** `char cor[] = "azul"` (array de 5, modificável) × `char *corPtr = "azul"` (o literal pode ficar em memória não gravável). `copy1` (índice) × `copy2` (ponteiro: `for ( ; *s1 = *s2; s1++, s2++);`), com o 2º parâmetro `const char *`.
- **Exercícios:** 7.21 "mystery1" = strcat; 7.22 "mystery2" = strlen; 7.30 "mystery3" = compara strings (cuidado: retorna 1 se uma for prefixo da outra; boa discussão); 7.23d `s++` num array (erro).

### 0054-ponteiro-para-ponteiro
- **O que o livro tem:** `insert(LISTNODEPTR *sPtr, …)` e `push(STACKNODEPTR *topPtr, …)`: passar o endereço do ponteiro da lista para poder alterar o início ("dupla referência indireta"). `char *naipe[4]` como array de ponteiros (Fig. 7.22) × matriz de char (desperdício de memória com strings de tamanhos diferentes).

### 0055-ponteiro-para-funcao
- **Conceitos-chave:** o nome da função é o endereço do código; `int (*compare)(int, int)` × `int *compare(int, int)` (precedência); chamar com `(*compare)(a, b)` ou `compare(a, b)`. O livro prefere a 1ª forma porque deixa claro que é ponteiro.
- **Exemplos-destaque:** bubble sort genérico com `ascendente`/`descendente` (Fig. 7.26); **menu com array de ponteiros para função** `void (*f[3])(int)` e chamada `(*f[opcao])(opcao)` (Fig. 7.28).
- **Exercício:** 7.28 reescrever o programa de notas como menu com `processarGraus[4]` (exige que todas as funções tenham a mesma assinatura). qsort e bsearch só aparecem no Apêndice A.11.

### 0056-void-generico
- **Conceitos-chave:** `void *` recebe qualquer ponteiro e é atribuído a qualquer ponteiro sem cast; não pode ser desreferenciado (o compilador não sabe quantos bytes); correção `*(int *)sPtr`; as funções mem* usam void* e um tamanho; malloc retorna void*.

### 0057-juntando-tudo
- **Projeto:** baralho (Fig. 7.24) com refinamento top-down em 3 níveis, depois pôquer (7.12–7.15: par, dois pares, trinca, quadra, flush, sequência, comparar mãos, banca automática). 7.16 trocar o embaralhamento com **adiamento indefinido** por permutas e parar a busca ao achar a carta. 7.25–7.27 **labirinto** com "mão direita na parede" recursivo, gerador aleatório e tamanho qualquer.

---

## 07 — Memória dinâmica

### 0058-pilha-e-heap
- **Pouco conteúdo:** só a menção de que arrays têm tamanho fixo em compilação e listas crescem até acabar a memória (física ou virtual). Usar outra fonte.

### 0059-malloc-free
- **Conceitos-chave:** `newPtr = malloc(sizeof(struct node))`; testar NULL e avisar; `free` assim que não precisar mais; o tamanho de uma struct **não é** a soma dos membros (alinhamento), então use sizeof.
- **Pegadinhas (lista do Cap. 12):** vazamento de memória; free em memória não obtida com malloc; usar memória já liberada; não pôr NULL no último link.
- **Exercício:** 12.4e laço que libera a lista inteira com `atualPtr` e `tempPtr`, depois zera o início.

### 0060-calloc-realloc
- Só descrição no Apêndice A.11 (calloc zera os bits; realloc preserva o conteúdo até o menor tamanho, com `ptr` NULL age como malloc e tamanho 0 libera). Não há exemplo de "vetor que cresce".

### 0062-erros-de-memoria
- Lista acima (0059). Não há valgrind nem ASan. O livro só diz que o efeito de acessar fora do array "depende do sistema".

---

## 08 — Structs

### 0064-struct
- **Conceitos-chave:** tag; membros; struct auto-referenciada (só ponteiro para si mesma); a definição não reserva memória; variáveis declaradas junto da definição; inicialização por lista (os membros que faltam viram 0/NULL); operações válidas: atribuir struct de mesmo tipo, `&`, acesso a membros e sizeof. **Não se comparam structs com `==`** por causa dos "buracos" de alinhamento (Fig. 10.1: `char c; int i;` com byte indefinido); `.` × `->`; `aPtr->naipe` == `(*aPtr).naipe`; `*aPtr.naipe` é erro.
- **Pegadinhas:** `;` final esquecido (10.4d); `copas.face` sem índice (10.4b); `*cPtr->face` sem parênteses (10.4a); atribuir struct de tipo diferente (10.4f); espaço entre `-` e `>`.
- **Exercícios:** 10.6 escrever 16 expressões de acesso a `registroCliente.pessoal.numeroFone` e via `clientePtr->pessoal.numeroFone`; 10.5 definir inventario, endereco e aluno (struct dentro de struct).

### 0065-typedef
- **Conceitos-chave:** cria **sinônimo**, não tipo novo; nome com inicial maiúscula; `typedef struct {…} Carta;`; portabilidade (alias `Integer` para inteiro de 4 bytes).
- **Pegadinha:** `pessoal d;` sem `struct` e sem typedef (10.4e).

### 0066-vetor-de-structs
- **Exemplo:** `Carta baralho[52]` preenchido com `face[i % 13]` e `naipe[i / 13]`; embaralhar trocando cada posição com uma aleatória (⚠ viesado, ver Obsoleto); distribuir em uma passada.

### 0067-ponteiro-para-struct
- **Conceitos-chave:** structs e seus membros vão **por valor** (cópia inteira); para alterar ou ganhar desempenho, passe o endereço (`const` se for só leitura); arrays de structs vão como endereço.
- **Pegadinha:** achar que struct vai por referência como array (erro comum 10.7).

### 0068-enum
- **Conceitos-chave:** constantes inteiras começando em 0, ou no valor dado e +1 a partir daí; podem repetir valores; nomes em MAIÚSCULAS; não podem ser reatribuídas.
- **Exemplo:** `enum meses {JAN = 1, …, DEZ}` com `nomeMes[mes]` e `nomeMes[0] = ""`.

### 0069-union
- **Conceitos-chave:** membros compartilham o mesmo espaço (tamanho ≥ o maior membro); só um membro é válido por vez; só se inicializa com o tipo do **1º membro** (`union numero v = {1.43}` é inválido); não se comparam unions; ler um membro diferente do último gravado depende da implementação (Fig. 10.5: float 100.0 lido como int → 17096).
- **Exercícios:** 10.8/10.9 união integer (char/short/int/long) e floatingPoint: os valores saem certos?

### 0070-bits
- **Conceitos-chave:** `& | ^ << >> ~` com tabelas-verdade; **máscara** (`valor & mascara ? '1' : '0'` com deslocamento a cada passo, a função `exibeBits`); OR liga bits (15 | 241 = 255); XOR (139 ^ 199 = 76); complemento (21845 → 43690); `960 << 8` = 49152 e `960 >> 8` = 3; deslocar de valor negativo ou ≥ número de bits é indefinido; `>>` em signed depende da máquina; operadores de atribuição bit a bit; **campos de bits** (`unsigned face:4, naipe:2, cor:1`), campo anônimo para preenchimento e `:0` para alinhar; campos de bits não têm endereço nem são arrays de bits; economizam espaço mas o acesso é mais lento.
- **Pegadinhas:** `&&` × `&` e `||` × `|`.
- **Exercícios-destaque (com resposta):** 10.19 **mistério**: a função testa se os 10 bits menos significativos são zero, logo X = **1024**. 10.20 mistério: conta bits 1 e retorna 1 se a quantidade for par (**paridade**). 10.12 `numero * 2^pot` com `<<`; 10.13/10.14 **empacotar** dois chars num unsigned e desempacotar com as máscaras 65280 e 255; 10.15/10.16 o mesmo com 4 chars; 10.17 **inverter a ordem dos bits**; 10.18 tornar `exibeBits` portátil com sizeof.

### 0071-juntando-tudo
- **Projeto:** baralho com campos de bits (Fig. 10.16) + embaralhamento eficiente + cor (10.7).

---

## 09 — Arquivos

### 0072-arquivos-texto
- **Conceitos-chave:** hierarquia de dados (bit → caractere → campo → registro → arquivo → banco de dados) e campo-chave; C vê o arquivo como fluxo de bytes com marca de fim; `FILE *`, descritor e tabela de arquivos abertos (Fig. 11.5, ótimo diagrama); modos r, w, a, r+, w+, a+ (e os binários no Apêndice); fopen testando NULL; fprintf/fscanf; feof; rewind; fclose; teclas de EOF por sistema.
- **Explicação boa:** **por que não se atualiza um arquivo-texto "no lugar"**: trocar "White" por "Worthington" sobrescreve o registro seguinte, porque os campos formatados têm tamanho variável. É preciso copiar o arquivo inteiro.
- **Exemplos:** criar clientes.dat (conta, nome, saldo) lendo até EOF; listar; **consulta de crédito** com menu (saldo zero, credor, devedor) e `rewind` entre consultas.
- **Pegadinhas:** abrir com "w" apaga o conteúdo sem aviso (11.4d/e); ponteiro FILE errado (11.4c); `open` × `fopen`; modo errado.
- **Exercícios:** 11.7–11.10 **casamento de arquivos mestre × transações** (oldmast + trans → newmast; transação sem mestre gera mensagem; várias transações por conta), com dados de teste prontos (11.8); 11.15 modificar a Fig. 8.14 para ler e gravar arquivos escolhidos.

### 0073-arquivos-binarios
- **Conceitos-chave:** registros de **tamanho fixo** permitem calcular a posição pela chave (`(conta - 1) * sizeof(struct)`); fwrite/fread com (endereço, tamanho, quantidade, FILE*); `fseek(fp, offset, SEEK_SET/SEEK_CUR/SEEK_END)`; inicializar 100 registros vazios antes de usar; dados "brutos" × legíveis (`fprintf("%d")` usa de 1 a 11 caracteres; fwrite sempre usa 4 bytes).
- **Analogia boa:** arquivo de acesso aleatório = **trem de carga** com vagões do mesmo tamanho, uns vazios e outros cheios.
- **Exemplo-destaque:** **sistema bancário de transações** (Fig. 11.16, 5 opções: gerar contas.txt, atualizar, inserir, excluir zerando o registro, sair) aberto em "r+".
- **Pegadinha:** ⚠ Fig. 11.15/11.16 usam `while (!feof(fp)) { fread(...); processa; }`, que **processa o último registro duas vezes**. Ótimo exercício de depuração (correção: testar o retorno de fread).
- **Exercícios:** 11.12 **loja de ferragens** com 100 registros (dados prontos: lixa elétrica 7 × 57.98…); 11.11 nomeidad.dat; 11.13 **palavras de telefone** (todas as 3⁷ = 2187 combinações de um número de 7 dígitos gravadas em arquivo) e 11.14 checar num dicionário; 11.17 Simpletron lendo o programa de um arquivo.

### 0074-argumentos
- **Não coberto** (argc/argv não aparece no livro).

---

## 10 — Análise

### 0076-eficiencia / 0077-big-o
- **Não há notação O**, mas há muita intuição de custo para aproveitar:
  - busca linear compara em média metade dos elementos; **busca binária: 1024 → 10 comparações, 2²⁰ → 20, um bilhão → 30**, contra 500 milhões em média na linear. Regra: o máximo de comparações é o expoente da primeira potência de 2 maior que n;
  - BST "bem compactada" tem log₂ n níveis (1000 → 10, 1.000.000 → 20);
  - Fibonacci recursivo explode exponencialmente; recursão tem custo de chamadas;
  - bubble: 6.11 cortar uma comparação por passada e parar se não houve troca;
  - bucket sort (6.31) como **troca de espaço por tempo**; campos de bits como troca inversa;
  - **adiamento indefinido** no embaralhamento ingênuo (7.24 × 7.16 × 10.3);
  - primos testando até √n × n/2 (5.27c: estimar o ganho);
  - força bruta × heurística (passeio do cavalo, oito damas, 4.27).
- **Exercício:** 12.18 eliminar duplicatas com array × com BST: comparar o desempenho.

### 0078-invariantes
- Não coberto.

### 0079-tad
- **Pouco:** funções predicado (`isEmpty`), `const` como privilégio mínimo, protótipos em cabeçalho. Não há separação interface/implementação para TADs.

---

## 11 — Listas

### 0081-lista-encadeada / 0082-lista-busca-remocao / 0083-lista-ordenada
- **Conceitos-chave:** nó auto-referenciado; o último link é NULL; acesso pelo ponteiro do início; vantagens e desvantagens frente ao array (tamanho dinâmico × sem acesso direto; inserção sem deslocar × ponteiros ocupam espaço).
- **Exemplo-destaque:** lista de **chars em ordem alfabética** (Fig. 12.3) com `insert` (previousPtr e currentPtr, caso "inserir no início" via `*sPtr`), `delete` (caso do 1º nó separado), `isEmpty` e `printList`, explicados em passos numerados com diagramas antes e depois (Figs. 12.5/12.6).
- **Pegadinha:** a `delete` do livro acessa `(*sPtr)->data` sem testar a lista vazia (o main testa antes). Bom para discutir a quem cabe validar.
- **Exercícios:** 12.4 inserir "Alves", "Torres" e "Pereira" numa lista Jarbas→Silva, dizendo para onde previousPtr e currentPtr apontam em cada caso (com resposta); 12.6 concatenar duas listas; 12.7 **intercalar duas listas ordenadas**; 12.8 25 aleatórios em ordem com soma e média; 12.9 cópia invertida; 12.20 imprimir ao contrário de forma recursiva; 12.21 busca recursiva.

### 0084/0085 (dupla, circular)
- Não cobertos.

---

## 12 — Pilhas e filas

### 0088-pilha-encadeada
- **Conceitos-chave:** LIFO; topo; push em 3 passos e pop em 5 passos, com diagramas (Figs. 12.10/12.11); aplicações: endereços de retorno e variáveis automáticas na chamada de funções, compiladores.

### 0089-pilha-aplicacoes
- **Exercícios-destaque:** 12.12 **infixa → pós-fixa** com o algoritmo completo (empilhar '(', acrescentar ')' ao fim, desempilhar enquanto a precedência for ≥, …) e as 8 funções pedidas: `(6 + 2) * 5 - 8 / 4` → `6 2 + 5 * 8 4 / -`; 12.13 **avaliar a pós-fixa** (nota sobre a ordem `y op x` em `-` e `/`); 12.14 operandos de vários dígitos; 12.10 inverter uma linha; 12.11 palíndromo com pilha.
- **Falta:** parênteses balanceados (pode ser derivado do 12.12).

### 0091-fila-encadeada
- **Conceitos-chave:** FIFO; headPtr e tailPtr; enqueue (3 passos) e dequeue (6 passos), com diagramas; aplicações: spool de impressão, pacotes em roteadores, processos.
- **Pegadinha valiosa:** ⚠ na Fig. 12.13, o `dequeue` faz `tailPtr = NULL;` em vez de `*tailPtr = NULL;`. O texto descreve o certo, mas o código só zera a cópia local. Excelente exercício "ache o bug": a fila esvazia e depois o enqueue escreve num nó liberado.
- **Exercício:** 12.15 **simulação de caixa de supermercado** (chegadas e atendimentos aleatórios de 1–4 min, 720 min; pergunta qual a maior fila, qual a maior espera e o que muda se as chegadas forem de 1–3 min).

### 0087-pilha / 0090-fila / 0092-deque
- Versões com vetor e deque não aparecem.

---

## 13 — Busca e ordenação

### 0094-busca-sequencial / 0095-busca-binaria
- **Conceitos-chave:** linear para arrays pequenos ou desordenados; binária só em array ordenado, com `menor`, `maior` e `meio`, reduzindo à metade (a figura de código falta no arquivo, mas o texto descreve a função de 4 parâmetros que imprime o subarray marcando o meio com `*`).
- **Exercícios:** 6.34/6.35 versões **recursivas** (retornam o índice ou −1); 5.35 o jogo de adivinhar como intuição da busca binária.

### 0096-bubble-sort
- **Conceitos-chave:** passadas comparando pares vizinhos; o maior "afunda" até o fim a cada passada (n−1 passadas); a troca precisa da variável `hold` (com duas atribuições, `a[i] = a[i+1]; a[i+1] = a[i];` perde o 7); é simples de escrever, mas lento.
- **Exercício:** 6.11 as duas otimizações.

### 0097-selection-sort
- 6.32 **selection sort recursivo** (descrição do algoritmo).

### 0100-quick-sort
- **Exercício 7.24:** partição pelo 1º elemento com rastro passo a passo em `37 2 6 4 89 8 10 12 68 45` → `12 2 6 4 10 8 37 89 68 45`. Bom para teste de mesa.

### 0101-comparando
- qsort e bsearch só no Apêndice A.11 (qsort **não é estável**: "a ordem de elementos iguais fica indefinida"). **Bucket sort** (6.31, radix por dígito com matriz 10×n).
- **Estudo de caso:** **média, mediana e moda** de 99 respostas (6.7). A mediana exige ordenar; o exercício 6.14 pede tratar empate na moda e mediana com n par. 6.7f V/F: 1,2,5,6,7,7,7 tem média 5, mediana 6, moda 7.

### 0098/0099 (insertion, merge)
- Não cobertos.

---

## 14 — Árvores

### 0102-arvores / 0103-arvore-binaria / 0104-bst-busca-insercao
- **Conceitos-chave:** raiz, filho esquerdo e direito, subárvores, irmãos, folha; árvore desenhada de cabeça para baixo; BST sem duplicatas (insere só como folha); o percurso **em ordem imprime ordenado** ("binary tree sort"); duplicatas são descartadas naturalmente (o programa imprime "dup"); a forma da árvore depende da ordem de inserção.
- **Exemplo:** Fig. 12.19 insere 10 aleatórios de 0–14 com `insertNode(&((*treePtr)->leftPtr), v)` recursivo e mostra pré, em e pós-ordem.
- **Exercícios (com resposta):** 12.5 percursos da árvore de 15 nós (49; 28 83; 18 40 71 97; …) e na Fig. 12.21 (27 13 42 6 17 33 48: em ordem 6 13 17 27 33 42 48, pré 27 13 6 17 42 33 48, pós 6 17 13 33 48 42 27); 12.19 contar **níveis**; 12.23 busca na BST retornando o ponteiro; 12.24 **percurso por nível com fila** (algoritmo dado); 12.25 **imprimir a árvore deitada** (em ordem invertida, direita primeiro, +5 espaços por nível); 12.17 BST de palavras com strtok; 12.16 aceitar duplicatas.

### 0105-bst-remocao
- **Exercício 12.22:** algoritmo completo dos 3 casos (folha, um filho, dois filhos), usando como substituto o **maior da subárvore esquerda** e com subcasos (substituto folha ou com filho à esquerda) em passos numerados.

### 0106–0108 (AVL, heap, heapsort), 15 (hash), 16 (grafos)
- Não cobertos.

---

## Obsoleto / evitar

**Práticas C89 e dos anos 90, que não devem ser ensinadas como estão:**
- `main()` sem `int` (a boa prática 5.4 diz para omitir!) e programas sem `return 0`.
- Declarações obrigatoriamente no início do bloco (erro comum 2.5 diz que misturar "é erro de sintaxe"); hoje é permitido e recomendado declarar perto do uso.
- Identificadores com só 31 caracteres significativos; recuo de "3 espaços ou 1/4 de polegada".
- `int` implícito (`float x, y` em parâmetro; função sem protótipo assumida como int); `auto` e `register`.
- **`gets`** (removido no C11) e `scanf("%s")` sem largura; `scanf("%d%s", &a.partNome)` com `&` em array (10.3d).
- `while (!feof(fp))` com a leitura no fim ou no meio do laço (11.15/11.16).
- `int` de 16 bits em todo o livro: `exibeBits` com `1 << 15`, `unsigned 65081`, `sizeof(int) = 2`, "RAND_MAX = 32767", "10.11 Se seu computador usa inteiros de 4 bits" (sic).
- EOF com Ctrl-Z no DOS/VMS; mensagens do Borland; `cc` e `a.out` sem gcc.
- **"Dicas de desempenho" falsas hoje:** "`c += 3` compila mais rápido que `c = c + 3`", "inicializar na declaração reduz o tempo de execução", "notação de ponteiro economiza tempo de compilação", "torne o array local `static` para ganhar velocidade", usar `register`. Os compiladores modernos tornam tudo isso irrelevante.
- Embaralhamento da Fig. 10.3 (`j = rand() % 52` para todo i) é **enviesado**; ensinar Fisher–Yates (`j` em [i, 51]).
- Fumantes e não fumantes no avião (6.21); previsões sobre C++, Ada e Concurrent C.

**Erros de fato no texto (bons como "encontre o erro" para o aluno):**
1. Resposta 2.4e/2.5: o "produto" é calculado com `x + y + z`.
2. Fig. 3.7 (1º texto): "Se o contador for **igual** a zero, definir a média…" (deveria ser diferente).
3. 4.6b: `for (i = 100; i >= 100; i--)` para contar de 100 a 1 (roda uma vez só).
4. Fig. 5.2: `sqrt(9.0)` "é 10", `log10(100.0)` "é 10.0"; `ceil` descrito como "menor inteiro **maior** que x" (o certo é "não menor"). A resposta 5.3 mostra os valores certos.
5. "RAND_MAX deve ser **menor** que 32767" (o certo é no mínimo 32767) e "`rand() % 6` produz inteiros de 1 a 5" (o certo é de 0 a 5).
6. "`char string1[] = "primeiro"` contém na verdade **seis** elementos" (são 9).
7. Resposta 3.5b `++x + x = 12`: é comportamento indefinido.
8. Fig. 7.7: a função se chama `cuboPorValor` mas recebe `&numero` e é atribuída mesmo sendo void.
9. Fig. 12.13: `tailPtr = NULL` no dequeue (deveria ser `*tailPtr`).
10. 13.3h: `VOLUME_CUBO(x) (x)*(x)*(x)` sem parênteses externos.
11. A.2: `size_t` "tipo inteiro **com sinal**" (é sem sinal; o próprio A.10 corrige).
12. 4.29: a 2ª lei de De Morgan escrita com `||` dos dois lados.
13. Fig. 6.5 sem `main()` e com `printf("%13s", s[j])` para int.
14. Resposta 12.5 usa 92 onde a figura tem 95; respostas do Apêndice D com numeração deslocada.
15. Saída da Fig. 8.21 mostra `strcmp` retornando exatamente 1/−1 (o padrão só garante o sinal).

---

## Extras que não cabem no sumário

- **Simpletron (7.18–7.19, 7.29, 11.17):** computador decimal com acumulador, 100 palavras de 4 dígitos com sinal e 12 opcodes (READ 10, WRITE 11, LOAD 20, STORE 21, ADD 30, SUBTRACT 31, DIVIDE 32, MULTIPLY 33, BRANCH 40, BRANCHNEG 41, BRANCHZERO 42, HALT 43). Inclui exemplos (soma; maior de dois), ciclo busca-decodifica-executa (`opcode = reg / 100; operando = reg % 100`), *dump* de registradores e memória e erros fatais (divisão por zero, overflow ±9999, opcode inválido). É excelente para 0005, 0012, 0023 (switch) e 0042 (array como memória). Pode virar projeto de fim de módulo.
- **Compilador "Simples" (12.26–12.30):** linguagem estilo BASIC (rem, input, let, print, goto, if/goto, end) compilada em **duas passadas** para o Simpletron. Usa tabela de símbolos (C/L/V), array `flags` para referências futuras, dados alocados de 99 para baixo, let via infixa → pós-fixa → código, otimização load/store redundante (25% menos memória) e interpretador como alternativa. Bom projeto final que integra pilhas, strings, arquivos e structs.
- **Problemas clássicos de "jogo" com heurística × força bruta:** passeio do cavalo (incluindo passeio fechado), oito damas, labirinto, tartaruga.
- **Funções da biblioteca pouco vistas em cursos:** `strtol` com base e ponteiro de resto, `strspn`/`strcspn`/ `strpbrk`, `sprintf`/`sscanf` (montar e desmontar strings), `%n`, scansets, `setjmp`/`longjmp`, `signal`/ `raise`, `stdarg` (`va_start`/`va_arg`/`va_end`), `locale.h` (`localeconv`), `time.h` (`struct tm`, `strftime` com todos os `%`, `clock`/`CLOCKS_PER_SEC`, `difftime`), `atexit`, `exit` com `EXIT_SUCCESS`, `div`/`ldiv`, `getenv`, `system`, `tmpfile`, `ungetc`, `perror`, `errno`.
- **Diagrama FILE* → estrutura FILE → descritor → tabela de arquivos abertos → FCB** (Fig. 11.5).
- **Alinhamento e preenchimento de struct** com figura de bytes (Fig. 10.1).
- **Gerador congruente linear** portátil de `rand`/`srand` (Apêndice A.11), útil para explicar o que é "pseudoaleatório".
- **Projetos de texto:** palavras cruzadas (8.42), limericks (8.12), redações aleatórias (8.11).
