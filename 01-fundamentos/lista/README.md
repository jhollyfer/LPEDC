<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 01 · Fundamentos de C

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/01-fundamentos/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0101** · ★☆☆ · O plano trimestral da academia

A academia do bairro cobra R$ 119.90 por mês e uma matrícula de R$ 49.90,
paga uma vez só. Escreva um programa que guarde esses dois valores e o número
de meses (3) em variáveis e mostre o resumo do plano trimestral:


```text
Saída esperada:
Mensalidade: R$ 119.90
Meses: 3
Total do plano: R$ 409.60
```

**Dicas:**

1. Preço é double; quantidade de meses é int.
2. O total é mensalidade * meses + matricula. O int vira double sozinho na
   conta.
3. Resposta esperada: Total do plano: R$ 409.60.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0101.c
```

---

**Exercício P0102** · ★☆☆ · Gasolina até Itacoatiara

De Manaus a Itacoatiara são 176 km pela AM-010. O carro faz 11.5 km por litro
e a gasolina custa R$ 6.79. Escreva um programa que calcule quantos litros a
viagem de ida gasta e quanto custa, com duas casas decimais:


```text
Saída esperada:
Distância: 176 km
Litros: 15.30
Custo da ida: R$ 103.92
```

**Dicas:**

1. litros = distancia / consumo. Como consumo é double, a divisão é real.
2. custo = litros * preco. Guarde o valor inteiro de litros; só o printf
   arredonda para mostrar.
3. Resposta esperada: 15.30 litros e R$ 103.92.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0102.c
```

---

**Exercício P0103** · ★☆☆ · Minutos do plano de celular

A fatura do celular diz que você falou 437 minutos no mês. Complete o
programa: troque os dois zeros pelas contas certas, usando só / e %, para
mostrar o tempo em horas e minutos:


```text
Saída esperada:
437 minutos = 7 h e 17 min
```

**Dicas:**

1. Uma hora tem 60 minutos. A divisão inteira diz quantas horas cabem.
2. O resto da divisão (%) diz quantos minutos sobram.
3. Resposta esperada: 7 h e 17 min.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0103.c
```

---

**Exercício P0104** · ★☆☆ · O termômetro importado

O termômetro que veio de fora mostra 98.6 °F. O programa abaixo deveria
converter para Celsius com C = 5 / 9 × (F − 32), mas mostra 0.0. O erro está
na conta, de propósito. Conserte só a linha da conversão:


```text
Saída esperada:
98.6 F = 37.0 C
```

**Dicas:**

1. Calcule na mão quanto vale 5 / 9 em C quando os dois são int.
2. Basta um dos lados ser double: 5.0 / 9 já dá 0.5555...
3. Resposta esperada: 98.6 F = 37.0 C.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0104.c
```

---

**Exercício P0105** · ★☆☆ · O painel de senhas do banco

O painel do banco está na senha 41. Escreva um programa com int senha = 41;
e, nesta ordem: guarde em chamada o valor de senha++; depois guarde em
proxima o valor de ++senha. Mostre as três variáveis:


```text
Saída esperada:
Chamada: 41
Próxima: 43
Senha no painel: 43
```

**Dicas:**

1. senha++ entrega o valor antigo e só depois soma 1.
2. ++senha soma 1 primeiro e entrega o valor novo.
3. Resposta esperada: 41, 43 e 43.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0105.c
```

---

**Exercício P0106** · ★☆☆ · Ônibus da excursão

A escola vai levar 158 alunos ao Museu da Amazônia em ônibus de 44 lugares.
Escreva um programa que mostre quantos ônibus saem lotados, quantos alunos vão
no último ônibus e quantos ônibus a escola precisa alugar. Sem if: só / e %.


```text
Saída esperada:
Ônibus lotados: 3
Alunos no último: 26
Ônibus para alugar: 4
```

**Dicas:**

1. Lotados é a divisão inteira; quem sobra é o resto.
2. Para arredondar a divisão para cima sem if, some 43 (lugares - 1) antes de
   dividir: (alunos + lugares - 1) / lugares.
3. Resposta esperada: 3, 26 e 4.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0106.c
```

---

**Exercício P0107** · ★☆☆ · Os cocos da feira

Na feira, três cocos a R$ 7.99 dão R$ 23.97. O feirante só aceita reais
inteiros e quer ver quatro jeitos de chegar num valor sem centavos. Mostre o
total e o resultado de (int), round, floor e ceil sobre ele:


```text
Saída esperada:
Total: R$ 23.97
(int):  23
round:  24
floor:  23
ceil:   24
```

**Dicas:**

1. round, floor e ceil estão no math.h e devolvem double: mostre com %.0f.
2. O (int) corta a parte decimal, como o floor faz com números positivos.
3. Resposta esperada: 23, 24, 23 e 24.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0107.c
```

---

**Exercício P0108** · ★☆☆ · O Pix do país inteiro

Suponha que 160 milhões de pessoas façam, cada uma, um Pix de R$ 25 no mesmo
dia. Escreva um programa que mostre o maior int, o total em reais guardado
num long long e quantas vezes o total é maior que o INT_MAX (divisão inteira):


```text
Saída esperada:
Maior int: 2147483647
Total do dia: R$ 4000000000
O total é 1 vez(es) o INT_MAX
```

**Dicas:**

1. INT_MAX vem de limits.h. A conta 160000000 * 25 entre dois int estoura:
   escreva 160000000LL * 25 para a conta já acontecer em long long.
2. long long se mostra com %lld.
3. Resposta esperada: Total do dia: R$ 4000000000.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0108.c
```

---

**Exercício P0109** · ★☆☆ · Quadro de partidas da rodoviária

O painel da rodoviária mostra destino, horário e preço. Guarde cada hora e
cada minuto em int (9 e 5, 13 e 40, 22 e 0) e monte o quadro com os destinos
alinhados à esquerda em 12 colunas, as horas com dois dígitos e os preços
alinhados à direita em 7 colunas:


```text
Saída esperada:
Destino     Hora   Preço
Manacapuru  09:05   25.50
Iranduba    13:40    9.80
Presidente  22:00  112.00
```

**Dicas:**

1. %-12s alinha o texto à esquerda em 12 colunas; %02d põe o zero na frente.
2. %7.2f ocupa 7 colunas com duas casas.
3. Resposta esperada: as três linhas acima, com 09:05, 13:40 e 22:00.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0109.c
```

---

**Exercício P0110** · ★☆☆ · Açaí no quilo

A barraca vende açaí no quilo. Escreva um programa que leia o peso em kg e o
preço do quilo e mostre quanto a pessoa paga. Um exemplo de interação:


```text
Saída esperada:
Peso (kg): 1.5
Preço do quilo: 28.00
Total: R$ 42.00
```

**Dicas:**

1. Leia os dois com %lf, num double, e não esqueça o &.
2. O total é peso * preco.
3. Resposta esperada: com 1.5 e 28.00, Total: R$ 42.00.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0110.c
```

## ★★☆ Para pensar

**Exercício P0111** · ★★☆ · Quanto tempo leva o backup

O backup das fotos da família vai levar 200000 segundos. Escreva um programa
que mostre esse tempo em dias, horas, minutos e segundos, só com / e %:


```text
Saída esperada:
200000 s = 2 dia(s), 7 h, 33 min e 20 s
```

**Dicas:**

1. Um dia tem 86400 s, uma hora 3600 s. Depois de tirar os dias, trabalhe
   com o resto.
2. Faça em cascata: dias = total / 86400; resto = total % 86400; e assim por
   diante.
3. Resposta esperada: 2 dia(s), 7 h, 33 min e 20 s.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0111.c
```

---

**Exercício P0112** · ★★☆ · Os dígitos do medidor de luz

O medidor de luz da casa marca 4827 kWh. Escreva um programa que separe os
quatro dígitos só com / e % e mostre cada um, a soma e o produto deles:


```text
Saída esperada:
Dígitos: 4 8 2 7
Soma: 21
Produto: 448
```

**Dicas:**

1. O milhar é n / 1000. A centena é n / 100 % 10. A dezena é n / 10 % 10.
2. A unidade é n % 10.
3. Resposta esperada: soma 21 e produto 448.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0112.c
```

---

**Exercício P0113** · ★★☆ · A média ponderada do concurso

No concurso, a prova objetiva tem peso 2 e a discursiva tem peso 3. Com 6.0 e
8.0, a média deveria ser (6.0 × 2 + 8.0 × 3) / 5 = 7.2, mas o programa abaixo
mostra 16.8. O erro é de precedência e está lá de propósito. Conserte só com
parênteses:


```text
Saída esperada:
Média final: 7.2
```

**Dicas:**

1. Em C, * e / são feitos antes de +. Quem está sendo dividido por 5 hoje?
2. A soma inteira dos pesos tem que acontecer antes da divisão.
3. Resposta esperada: Média final: 7.2.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0113.c
```

---

**Exercício P0114** · ★★☆ · O barco para Parintins

De Manaus a Parintins o barco percorre 369 km a 25 km/h. Escreva um programa
que calcule o tempo em horas (double), converta para minutos arredondando com
round e mostre em horas e minutos:


```text
Saída esperada:
Tempo: 14.76 h
Em minutos: 886
Chegada em 14 h e 46 min de viagem
```

**Dicas:**

1. horas = 369.0 / 25. Os minutos totais são round(horas * 60), convertidos
   para int com um cast.
2. Depois é / 60 e % 60 nos minutos totais.
3. Resposta esperada: 886 minutos, 14 h e 46 min.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0114.c
```

---

**Exercício P0115** · ★★☆ · O pace da corrida de rua

Você correu os 10 km da corrida de rua em 52 min e 30 s. Escreva um programa
que mostre o pace (tempo por km) no formato m:ss e a velocidade média em km/h:


```text
Saída esperada:
Tempo total: 3150 s
Pace: 5:15 por km
Velocidade: 11.43 km/h
```

**Dicas:**

1. Passe tudo para segundos: 52 * 60 + 30. O pace em segundos é o total
   dividido pela distância.
2. A velocidade é distancia / (segundos / 3600.0). Use 3600.0 para a divisão
   não ser inteira.
3. Resposta esperada: Pace: 5:15 e 11.43 km/h.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0115.c
```

---

**Exercício P0116** · ★★☆ · O centavo que sumiu

O caixa da padaria guarda o preço em reais (double) e converte para centavos
inteiros antes de mandar para a maquininha. Com o pão a R$ 4.35, a maquininha
recebe 434 centavos. O programa abaixo tem esse erro de propósito: conserte a
conversão para a maquininha receber 435, e mostre os dois valores:


```text
Saída esperada:
Preço: R$ 4.35
Centavos com (int): 434
Centavos com round: 435
```

**Dicas:**

1. 4.35 não cabe exato em binário: 4.35 * 100 dá 434.99999999999994, e o
   (int) corta tudo depois da vírgula.
2. Arredonde antes de converter: (int)round(preco * 100), com math.h.
3. Resposta esperada: 434 com (int) e 435 com round.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0116.c
```

---

**Exercício P0117** · ★★☆ · O ângulo dos ponteiros

Num relógio de ponteiros, o das horas anda 30 graus por hora e mais 0.5 grau
por minuto; o dos minutos anda 6 graus por minuto. Escreva um programa que
mostre o ângulo entre os ponteiros às 14:20 e às 9:45, usando fabs:


```text
Saída esperada:
14:20 -> 50.0 graus
09:45 -> 22.5 graus
```

**Dicas:**

1. Ponteiro das horas: 30 * (h % 12) + 0.5 * m. Dos minutos: 6 * m.
2. O ângulo é fabs(horas - minutos). Use 0.5 (double) para a conta não virar
   inteira.
3. Resposta esperada: 50.0 e 22.5 graus.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0117.c
```

---

**Exercício P0118** · ★★☆ · A playlist da viagem

Três músicas da playlist duram 3:45, 4:12 e 5:03 (minutos:segundos). Guarde
cada minuto e cada segundo num int e mostre a duração total e a média por
música, as duas no formato m:ss:


```text
Saída esperada:
Total: 13:00
Média por música: 4:20
```

**Dicas:**

1. Passe cada música para segundos, some e só depois volte para m:ss.
2. A média em segundos é o total / 3 (divisão inteira).
3. Resposta esperada: Total 13:00 e média 4:20.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0118.c
```

---

**Exercício P0119** · ★★☆ · A caixa d'água da casa

A caixa d'água cilíndrica tem raio de 0.6 m e altura de 1.2 m. A casa gasta
180 litros por dia. Escreva um programa com const double PI = 3.14159265; que
mostre o volume em m³, a capacidade em litros inteiros (corte com cast), por
quantos dias completos a caixa cheia dura e quantos litros sobram:


```text
Saída esperada:
Volume: 1.3572 m3
Capacidade: 1357 litros
Dura 7 dias completos e sobram 97 litros
```

**Dicas:**

1. Volume do cilindro: PI * r * r * h. Um m³ tem 1000 litros.
2. Com os litros em int, dias = litros / 180 e sobra = litros % 180.
3. Resposta esperada: 1357 litros, 7 dias e 97 litros de sobra.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0119.c
```

---

**Exercício P0120** · ★★☆ · A média da ida e volta

Você vai de carro ao sítio, 120 km, a 60 km/h, e volta pelos mesmos 120 km a
40 km/h. Muita gente diz que a média foi 50 km/h. Escreva um programa que
calcule o tempo de cada trecho, o tempo total e a velocidade média de verdade
(distância total / tempo total):


```text
Saída esperada:
Ida: 2.0 h
Volta: 3.0 h
Total: 240 km em 5.0 h
Velocidade média: 48.0 km/h
```

**Dicas:**

1. Tempo = distância / velocidade, em double.
2. A média é 240 / 5, não (60 + 40) / 2: você passa mais tempo no trecho
   lento.
3. Resposta esperada: Velocidade média: 48.0 km/h.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0120.c
```

## ★★★ Desafio

**Exercício P0121** · ★★★ · Os dígitos verificadores do CPF

O CPF tem 9 dígitos e 2 verificadores. O 1º verificador: multiplique os 9
dígitos pelos pesos 10, 9, 8, ..., 2, some e pegue o resto r da divisão por
11; se r < 2 o dígito é 0, senão é 11 − r. O 2º usa os 9 dígitos mais o 1º
verificador, com pesos 11, 10, ..., 2, e a mesma regra. Escreva um programa
que, sem if, calcule os verificadores de 123456789 e mostre o CPF formatado:


```text
Saída esperada:
Soma 1: 210, resto 1, dígito 0
Soma 2: 255, resto 2, dígito 9
CPF: 123.456.789-09
```

**Dicas:**

1. Separe os dígitos com / e % (d1 = n / 100000000, d2 = n / 10000000 % 10,
   ... d9 = n % 10).
2. Truque sem if: (11 - r) % 11 % 10. Com r = 0 dá 0, com r = 1 dá 10 % 10 =
   0, e com r de 2 a 10 dá 11 − r.
3. Para formatar: n / 1000000, n / 1000 % 1000 e n % 1000, com %03d.
4. Resposta esperada: CPF: 123.456.789-09.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0121.c
```

---

**Exercício P0122** · ★★★ · Em que dia da semana cai a prova

Dá para descobrir o dia da semana de qualquer data só com contas inteiras.
Com a = (14 − mês) / 12, y = ano − a e m = mês + 12a − 2, o dia da semana é
(dia + y + y/4 − y/100 + y/400 + 31m/12) % 7, com 0 = domingo, 1 = segunda,
..., 6 = sábado. Escreva um programa que mostre o número do dia da semana da
prova do PPGI (27/11/2026) e do Natal de 2026 (25/12/2026):


```text
Saída esperada:
27/11/2026 -> dia 5 da semana (0 = domingo)
25/12/2026 -> dia 5 da semana (0 = domingo)
```

**Dicas:**

1. Todas as divisões são inteiras, e é isso que faz a fórmula
   funcionar. O a vale 1 em janeiro e fevereiro e 0 nos outros meses.
2. Repita as contas para a segunda data, com variáveis próprias.
3. Resposta esperada: as duas datas caem numa sexta-feira (5).

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0122.c
```

---

**Exercício P0123** · ★★★ · Quantos dias faltam para a prova

Para contar os dias entre duas datas, transforme cada uma num número de dias
desde uma data fixa e subtraia. Com a = (14 − mês) / 12, y = ano − a e m =
mês + 12a − 3, o número do dia é dia + (153m + 2)/5 + 365y + y/4 − y/100 +
y/400. Escreva um programa que mostre quantos dias há de 15/08/2026 até a
prova, em 27/11/2026, e quantas semanas completas e dias isso dá:


```text
Saída esperada:
De 15/08/2026 a 27/11/2026: 104 dias
São 14 semanas e 6 dias
```

**Dicas:**

1. Calcule o número do dia para cada data, com variáveis separadas, e
   subtraia: o resultado é a distância em dias.
2. Semanas é a diferença / 7; o resto é a diferença % 7.
3. Resposta esperada: 104 dias, 14 semanas e 6 dias.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0123.c
```

---

**Exercício P0124** · ★★★ · O dígito do código de barras

O código de barras dos produtos (EAN-13) tem 12 dígitos e um verificador.
Multiplique os dígitos, da esquerda para a direita, alternando os pesos 1 e 3;
o verificador é (10 − soma % 10) % 10. Escreva um programa que guarde
789123456789 num long long, calcule o verificador sem if e mostre o código
completo:


```text
Saída esperada:
Soma ponderada: 135
Verificador: 5
Código: 7891234567895
```

**Dicas:**

1. 12 dígitos não cabem num int: use long long e o sufixo LL.
2. O 1º dígito é n / 100000000000 % 10, o último é n % 10. Pesos: 1, 3, 1,
   3, ... (o 1º dígito tem peso 1).
3. O código completo é n * 10 + verificador, mostrado com %lld.
4. Resposta esperada: Código: 7891234567895.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0124.c
```

---

**Exercício P0125** · ★★★ · O byte escrito com zeros e uns

O manual do sensor diz que o registro de configuração deve receber o byte
10110110. Guarde isso num int como se fosse decimal (int bits = 10110110;),
separe cada "dígito" com / e % por 10, monte o valor de verdade com os pesos
128, 64, ..., 1 e mostre em decimal, hexadecimal e octal:


```text
Saída esperada:
Bits: 10110110
Decimal: 182
Hexadecimal: 0xB6
Octal: 0266
```

**Dicas:**

1. O bit mais à esquerda é bits / 10000000 % 10 e vale 128; o mais à direita
   é bits % 10 e vale 1.
2. %X mostra em hexadecimal maiúsculo e %o em octal.
3. Resposta esperada: 182, 0xB6 e 0266.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0125.c
```

---

**Exercício P0126** · ★★★ · Previsão da maratona

A fórmula de Riegel prevê o tempo numa prova mais longa a partir de uma mais
curta: T2 = T1 × (D2 / D1) elevado a 1.06. Você correu 10 km em 50 min.
Escreva um programa que preveja o tempo na maratona (42.195 km), arredonde
para segundos inteiros e mostre no formato h:mm:ss, além do pace previsto:


```text
Saída esperada:
Previsão: 13801 s
Maratona em 3:50:01
Pace previsto: 5:27 por km
```

**Dicas:**

1. T1 = 50 * 60 segundos. pow(42.195 / 10, 1.06) vem do math.h.
2. Converta com (int)round(...) e depois use / e % por 3600 e por 60.
3. O pace é o total em segundos / 42.195, cortado para int.
4. Resposta esperada: Maratona em 3:50:01.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0126.c
```

---

**Exercício P0127** · ★★★ · Fibonacci sem laço

Na sequência de Fibonacci (0, 1, 1, 2, 3, 5, 8, ...), o termo n é o inteiro
mais perto de φⁿ / √5, onde φ = (1 + √5) / 2 é a razão áurea (fórmula de
Binet). Escreva um programa que calcule φ com sqrt e mostre os termos 10, 30
e 40 com pow e round, guardando cada um num long:


```text
Saída esperada:
phi = 1.6180339887
F(10) = 55
F(30) = 832040
F(40) = 102334155
```

**Dicas:**

1. const double raiz5 = sqrt(5.0); e phi = (1 + raiz5) / 2.
2. F(n) = (long)round(pow(phi, n) / raiz5). Mostre long com %ld.
3. Resposta esperada: 55, 832040 e 102334155.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0127.c
```

---

**Exercício P0128** · ★★★ · De Manaus a Belém em linha reta

A distância em linha reta entre dois pontos da Terra sai da fórmula de
haversine. Com as latitudes e longitudes em radianos, faça
a = sin²(Δlat/2) + cos(lat1)·cos(lat2)·sin²(Δlon/2) e
d = 2 · R · asin(√a), com R = 6371 km. Manaus fica em (−3.1190, −60.0217) e
Belém em (−1.4558, −48.4902), em graus. Escreva um programa, com
#define PI 3.14159265358979, que mostre a distância arredondada para km:


```text
Saída esperada:
Manaus: -3.1190, -60.0217
Belém: -1.4558, -48.4902
Distância: 1294 km
```

**Dicas:**

1. Para converter graus em radianos: graus * PI / 180. sin, cos, asin e
   sqrt estão no math.h.
2. sin² de x é sin(x) * sin(x), ou pow(sin(x), 2).
3. Mostre com %.0f. Resposta esperada: Distância: 1294 km.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0128.c
```

---

**Exercício P0129** · ★★★ · A data da Páscoa

A data da Páscoa muda todo ano, mas sai de uma receita só de contas inteiras
(algoritmo de Meeus). Para o ano A: a = A % 19, b = A / 100, c = A % 100,
d = b / 4, e = b % 4, f = (b + 8) / 25, g = (b − f + 1) / 3,
h = (19a + b − d − g + 15) % 30, i = c / 4, k = c % 4,
l = (32 + 2e + 2i − h − k) % 7, m = (a + 11h + 22l) / 451,
mês = (h + l − 7m + 114) / 31 e dia = (h + l − 7m + 114) % 31 + 1.
Escreva um programa que mostre a Páscoa de 2026 e de 2027:


```text
Saída esperada:
Páscoa de 2026: 05/04
Páscoa de 2027: 28/03
```

**Dicas:**

1. Siga a receita na ordem, com uma variável para cada letra. Todas as
   divisões são inteiras.
2. Para o segundo ano, repita com outro conjunto de variáveis (ou reaproveite
   as mesmas com atribuição).
3. Resposta esperada: 05/04 em 2026 e 28/03 em 2027.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0129.c
```

---

**Exercício P0130** · ★★★ · Os quatro bytes de um int

Um int de 4 bytes guarda o número 305419896. Sem nenhum operador de bits, só
com / e % por 256, separe os quatro bytes (do mais significativo para o
menos), mostre cada um em decimal e em hexadecimal com dois dígitos, e depois
remonte o número a partir dos bytes para conferir:


```text
Saída esperada:
Número: 305419896 (0x12345678)
Bytes: 18 52 86 120
Em hexa: 12 34 56 78
Remontado: 305419896
```

**Dicas:**

1. O byte mais baixo é n % 256. O seguinte é n / 256 % 256, depois
   n / 65536 % 256, e o mais alto é n / 16777216.
2. %02X mostra um byte com dois dígitos hexadecimais.
3. Para remontar: b3 * 16777216 + b2 * 65536 + b1 * 256 + b0.
4. Resposta esperada: 18 52 86 120, ou 12 34 56 78 em hexa.

```bash
~/LPEDC/rodar 01-fundamentos/lista/P0130.c
```
