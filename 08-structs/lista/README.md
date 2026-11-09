<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 08 · Tipos compostos

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/08-structs/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0801** · ★☆☆ · A distância entre as paradas

No mapa da linha de ônibus, cada parada tem coordenadas (x, y) em km.
Crie typedef struct { double x, y; } Ponto; e escreva:


```text
double distancia(Ponto a, Ponto b);   // sqrt((bx - ax)² + (by - ay)²)
Ponto meio(Ponto a, Ponto b);         // o ponto médio, para o abrigo
```


Para as paradas abaixo, mostre a distância de cada trecho, o total do
percurso e o ponto médio entre a primeira e a última:


```text
Ponto paradas[4] = {{0.0, 0.0}, {3.0, 4.0}, {6.0, 8.0}, {6.0, 11.5}};
```



```text
Saída esperada:
Parada 1 -> 2: 5.00 km
Parada 2 -> 3: 5.00 km
Parada 3 -> 4: 3.50 km
Total: 13.50 km
Abrigo no meio: (3.00, 5.75)
```

**Dicas:**

1. Uma struct pode ser parâmetro e retorno, como um int: a função recebe
   uma cópia e devolve uma struct nova.
2. No meio: return (Ponto) {(a.x + b.x) / 2, (a.y + b.y) / 2}; (literal
   composto) ou declare um Ponto m e preencha os campos.
3. sqrt está no math.h.
4. Resposta esperada: a saída acima (13.50 km no total).

```bash
~/LPEDC/rodar 08-structs/lista/P0801.c
```

---

**Exercício P0802** · ★☆☆ · A que horas o voo chega

Crie typedef struct { int h, m; } Horario; e escreva


```text
Horario somar(Horario ini, int minutos, int *dias);
```


que devolve o horário depois de passar minutos, sempre normalizado (m de 0
a 59, h de 0 a 23), e guarda em *dias quantas vezes passou da meia-noite.
Teste os três voos:


```text
Manaus 22:45 + 230 min (3h50)
Belém 06:10 + 95 min
Rio Branco 23:30 + 1500 min (uma viagem com conexões)
```



```text
Saída esperada:
Manaus 22:45 + 230 min = 02:35 (+1 dia)
Belém 06:10 + 95 min = 07:45
Rio Branco 23:30 + 1500 min = 00:30 (+2 dias)
```

**Dicas:**

1. Converta tudo para minutos desde 00:00: total = ini.h * 60 + ini.m +
   minutos.
2. *dias = total / (24 * 60); o resto da divisão por 1440 dá os minutos
   do dia, que viram h e m com / 60 e % 60.
3. Mostre com %02d para sair 02:35 e não 2:35.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0802.c
```

---

**Exercício P0803** · ★☆☆ · O estoque baixo da farmácia

Crie o tipo Remedio (codigo int, nome com até 23 letras, estoque int,
minimo int) e guarde os 6 remédios abaixo num vetor de structs:


```text
101 Dipirona 40 20      102 Amoxicilina 8 15     103 Losartana 22 25
104 Omeprazol 60 30     105 Insulina 3 10        106 Paracetamol 35 20
```


Escreva int buscar(const Remedio *v, int n, int codigo), que devolve o
índice do remédio (ou -1). Mostre os remédios com estoque abaixo do
mínimo e quanto falta comprar, e depois procure os códigos 105 e 110:


```text
Saída esperada:
Comprar:
  Amoxicilina  faltam 7
  Losartana    faltam 3
  Insulina     faltam 7
Código 105: Insulina, estoque 3
Código 110: não cadastrado
```

**Dicas:**

1. Inicialize o vetor direto: Remedio v[6] = {{101, "Dipirona", 40, 20},
   ...}; os campos vão na ordem da struct.
2. Falta comprar = minimo - estoque.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0803.c
```

---

**Exercício P0804** · ★☆☆ · O carro e o tanque

Crie typedef struct { char modelo[16]; double tanque, capacidade,
km_por_litro, odometro; } Carro; e escreva duas funções que recebem um
PONTEIRO para o carro e mexem nele com ->:


```text
double abastecer(Carro *c, double litros);  // devolve quanto entrou
double rodar(Carro *c, double km);          // devolve quanto rodou
```


abastecer não passa da capacidade; rodar gasta km / km_por_litro litros
e, se o combustível acabar antes, roda só o que der. Comece com um Mobi
(tanque 5 L, capacidade 47 L, 13.5 km/L, odômetro 10230) e faça: abastecer
50 L, rodar 300 km, rodar 400 km, abastecer 20 L.


```text
Saída esperada:
Abasteceu 42.00 L
  Mobi: tanque 47.00 L, odômetro 10230.0 km
Rodou 300.0 km
  Mobi: tanque 24.78 L, odômetro 10530.0 km
Rodou 334.5 km
  Mobi: tanque 0.00 L, odômetro 10864.5 km
Abasteceu 20.00 L
  Mobi: tanque 20.00 L, odômetro 10864.5 km
```

**Dicas:**

1. c->tanque é o mesmo que (*c).tanque.
2. Em abastecer: cabe = c->capacidade - c->tanque; entra o menor entre
   litros e cabe.
3. Em rodar: o máximo possível é c->tanque * c->km_por_litro.
4. Escreva void painel(const Carro *c) para mostrar o estado depois de
   cada operação.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0804.c
```

---

**Exercício P0805** · ★☆☆ · Quantos dias tem o mês

Crie typedef enum { JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT,
NOV, DEZ } Mes; e escreva:


```text
bool bissexto(int ano);
int dias_no_mes(Mes m, int ano);
```


Use um switch no dias_no_mes (fevereiro depende do ano). Mostre os dias de
fevereiro em 2024, 2026, 1900 e 2000, e o total de dias de 2026 somando os
12 meses num laço que anda pelo enum:


```text
Saída esperada:
fev/2024: 29 dias
fev/2026: 28 dias
fev/1900: 28 dias
fev/2000: 29 dias
2026: 365 dias
```

**Dicas:**

1. Bissexto: divisível por 4 e não por 100, ou divisível por 400. Por
   isso 1900 não é e 2000 é.
2. No switch, vários case podem levar ao mesmo return: case ABR: case
   JUN: case SET: case NOV: return 30;
3. Um enum é um int: for (Mes m = JAN; m <= DEZ; m++) funciona.
4. Para o nome do mês, um vetor de strings indexado por m - 1.
5. Resposta esperada: a saída acima (2026 tem 365 dias).

```bash
~/LPEDC/rodar 08-structs/lista/P0805.c
```

---

**Exercício P0806** · ★☆☆ · As permissões do arquivo

No Linux, as permissões de um arquivo são 9 bits: rwx do dono, rwx do
grupo e rwx dos outros, do bit 8 ao bit 0 (r vale 4, w vale 2 e x vale 1
dentro de cada trio). Por isso chmod 754 é 111 101 100 em binário.
Escreva void mostrar(const char *rotulo, unsigned modo), que mostra o
rótulo, o número em octal (%o) e as letras (com '-' no lugar do bit
desligado), e teste com 0754 e 0644.
Depois, partindo de 0644, ligue o x do dono, desligue o r dos outros e
INVERTA o w do grupo, mostrando o modo depois de cada passo:


```text
Saída esperada:
chmod 754:             754 rwxr-xr--
chmod 644:             644 rw-r--r--
liga x do dono:        744 rwxr--r--
desliga r dos outros:  740 rwxr-----
inverte w do grupo:    760 rwxrw----
```

**Dicas:**

1. Em C, 0754 (com zero na frente) é um número OCTAL: cada dígito é
   exatamente um trio de bits.
2. Para as letras, ande do bit 8 ao 0: (modo >> b) & 1 diz se o bit b
   está ligado. A letra do bit b é "rwx"[(8 - b) % 3].
3. Ligar: modo |= 1u << 6. Desligar: modo &= ~(1u << 2). Inverter:
   modo ^= 1u << 4.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0806.c
```

---

**Exercício P0807** · ★☆☆ · O endereço IP em 32 bits

Um endereço IPv4 como 192.168.10.42 são 4 bytes, e cabe num uint32_t
(do stdint.h), com o primeiro número nos 8 bits de cima. Escreva:


```text
uint32_t montar(int a, int b, int c, int d);
void mostrar(const char *rotulo, uint32_t ip);  // os 4 bytes: >> e & 0xFF
```


A máscara de rede /24 tem os 24 bits de cima ligados: 0xFFFFFF00. A REDE
de um IP é ip & mascara, e o número do computador na rede é ip & ~mascara.
Mostre o IP, em hexa e em pontos, a rede e o computador, para /24 e /16:


```text
Saída esperada:
192.168. 10. 42  0xC0A80A2A  IP
Com /24:
255.255.255.  0  0xFFFFFF00  máscara
192.168. 10.  0  0xC0A80A00  rede
  0.  0.  0. 42  0x0000002A  máquina
Com /16:
255.255.  0.  0  0xFFFF0000  máscara
192.168.  0.  0  0xC0A80000  rede
  0.  0. 10. 42  0x00000A2A  máquina
```

**Dicas:**

1. montar: ((uint32_t) a << 24) | (b << 16) | (c << 8) | d — o cast vem
   antes do << para a conta ser feita em 32 bits sem sinal.
2. mostrar: (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF e
   ip & 0xFF.
3. Máscara /n: os n bits de cima ligados: 0xFFFFFFFFu << (32 - n) (vale
   para n de 1 a 31).
4. Para mostrar um uint32_t em hexa: printf("%08X", (unsigned) ip).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0807.c
```

---

**Exercício P0808** · ★☆☆ · Conserte o cadastro do sócio

O clube quer dar 20% de desconto na mensalidade dos sócios com mais de 10
anos de casa. O programa abaixo tem DOIS erros de propósito: o gcc avisa de
um (leia o warning); o outro é de lógica: o desconto é calculado, mas não
chega no sócio. Conserte os dois. O programa deve mostrar:


```text
Saída esperada:
Seu Lourival  23 anos: R$ 120.00
Kelly          4 anos: R$ 150.00
Dona Ivete    11 anos: R$ 96.00
```

**Dicas:**

1. %d é para int; para double, %.2f. Um formato errado mostra lixo.
2. A função recebe uma CÓPIA da struct: mudar a cópia não muda o sócio do
   main. Passe o endereço (Socio *) e use ->.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0808.c
```

---

**Exercício P0809** · ★☆☆ · O mais velho da família

Crie typedef struct { int dia, mes, ano; } Data; e typedef struct { char
nome[20]; Data nascimento; } Pessoa; (uma struct dentro da outra). Escreva
int compara_data(Data a, Data b), que devolve negativo se a vem antes de
b, 0 se são iguais e positivo se a vem depois. Com a família abaixo,
mostre o mais velho, o mais novo e quem faz aniversário em março:


```text
Pessoa familia[5] = {{"Vó Nazaré", {12, 3, 1941}},
                     {"Tio Edu", {30, 11, 1968}},
                     {"Mãe", {5, 3, 1972}},
                     {"Lucas", {19, 7, 2001}},
                     {"Bia", {2, 1, 2009}}};
```



```text
Saída esperada:
Mais velho: Vó Nazaré (1941)
Mais novo: Bia (2009)
Aniversário em março: Vó Nazaré (dia 12) Mãe (dia 5)
```

**Dicas:**

1. Compare o ano; se for igual, o mês; se for igual, o dia:
   if (a.ano != b.ano) return a.ano - b.ano; ...
2. O mais velho nasceu ANTES: é o de menor data.
3. Para chegar no mês: familia[i].nascimento.mes (dois pontos seguidos).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0809.c
```

---

**Exercício P0810** · ★☆☆ · A configuração com campos nomeados

O som do carro tem uma struct de configuração com vários campos:


```text
typedef struct {
    int volume, graves, agudos, balanco;
    bool loudness;
    char fonte[12];
} Config;
```


Com os inicializadores designados do C99, você escreve só os campos que
importam, em qualquer ordem, e o resto vira zero (false, "" para a
string): Config c = {.fonte = "Bluetooth", .volume = 18};. Monte os três
perfis abaixo assim e mostre cada um com uma função
void mostrar(const char *nome, const Config *c):
- padrao: nada informado (tudo zero);
- estrada: volume 22, graves 3, loudness ligado, fonte "Radio FM";
- show: fonte "Pendrive", agudos 4, graves 5, volume 30, balanco -2.


```text
Saída esperada:
padrao   vol  0, graves 0, agudos 0, balanço  0, loudness não, fonte ""
estrada  vol 22, graves 3, agudos 0, balanço  0, loudness sim, fonte "Radio FM"
show     vol 30, graves 5, agudos 4, balanço -2, loudness não, fonte "Pendrive"
```

**Dicas:**

1. Config padrao = {0}; zera tudo. Nos outros, use .campo = valor.
2. A ordem dos .campo não precisa seguir a da struct.
3. Mostre a string vazia entre aspas para ver que ela está lá: "%s".
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0810.c
```

## ★★☆ Para pensar

**Exercício P0811** · ★★☆ · O cardápio em duas ordens

A lanchonete guarda o cardápio num vetor de structs:


```text
typedef struct { char nome[24]; double preco; int calorias; } Item;
```



```text
X-Caboquinho      22.90  780 kcal     Tapioca           12.00  420 kcal
Pastel de carne    9.50  510 kcal     Açaí 500 ml       18.00  640 kcal
Suco de cupuaçu    8.00  190 kcal     Misto quente       9.50  380 kcal
```


(o vetor já está pronto no esqueleto). Ordene com qsort duas vezes: primeiro
em ordem alfabética do nome; depois
pelo preço (do mais barato ao mais caro; no empate, o de menos calorias
primeiro). Mostre as duas listas:


```text
Saída esperada:
Por nome:
  R$ 18.00  640 kcal  Açaí 500 ml
  R$  9.50  380 kcal  Misto quente
  R$  9.50  510 kcal  Pastel de carne
  R$  8.00  190 kcal  Suco de cupuaçu
  R$ 12.00  420 kcal  Tapioca
  R$ 22.90  780 kcal  X-Caboquinho
Por preço:
  R$  8.00  190 kcal  Suco de cupuaçu
  R$  9.50  380 kcal  Misto quente
  R$  9.50  510 kcal  Pastel de carne
  R$ 12.00  420 kcal  Tapioca
  R$ 18.00  640 kcal  Açaí 500 ml
  R$ 22.90  780 kcal  X-Caboquinho
```

**Dicas:**

1. A comparação recebe o endereço de cada Item: const Item *a = pa;
   e compara a->nome, a->preco...
2. Para double, não devolva a->preco - b->preco: a conversão para int
   corta a diferença (0.50 vira 0). Use (a->preco > b->preco) -
   (a->preco < b->preco).
3. qsort(cardapio, 6, sizeof cardapio[0], por_nome); — o qsort move a
   struct inteira (36 ou 40 bytes) a cada troca.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0811.c
```

---

**Exercício P0812** · ★★☆ · Ordenar os ponteiros, não as fichas

As fichas dos pacientes são grandes (cada uma tem um histórico de 200
caracteres), e mover uma ficha inteira a cada troca do qsort custa caro.
Crie as fichas no heap e um vetor de PONTEIROS para elas, e ordene os
ponteiros pela idade (do mais velho para o mais novo). As fichas não saem
do lugar:


```text
typedef struct { char nome[20]; int idade; char historico[200]; } Ficha;
```


Escreva Ficha *nova_ficha(const char *nome, int idade, const char *hist),
que aloca e preenche uma ficha (antes do strcpy, confira com strlen se o
texto cabe no campo; se não couber, devolva NULL). Crie as 4 fichas abaixo,
ordene e
mostre; mostre também quantos bytes cada troca move no qsort de ponteiros e
quantos moveria no de fichas. Libere tudo:


```text
Raimundo 58 "hipertensão"    Jéssica 31 "asma"
Benedito 74 "diabetes tipo 2"    Karina 45 "nenhum"
```



```text
Saída esperada:
1. 74 anos: Benedito (diabetes tipo 2)
2. 58 anos: Raimundo (hipertensão)
3. 45 anos: Karina (nenhum)
4. 31 anos: Jéssica (asma)
A ficha do Raimundo continua no mesmo endereço, agora na posição 2
Bytes por troca: 8 (ponteiro) contra 224 (ficha)
```

**Dicas:**

1. Ficha *f = malloc(sizeof *f); e preencha f->nome, f->idade,
   f->historico.
2. O vetor é Ficha *fichas[4]. Cada elemento é um ponteiro: o qsort recebe
   sizeof fichas[0] (8 bytes) e a comparação recebe um Ficha ** disfarçado:
   const Ficha *a = *(Ficha * const *) pa;
3. Para provar que a ficha não se moveu, guarde o endereço de fichas[0]
   (o Raimundo) antes do qsort e, depois, procure em que posição do vetor
   esse mesmo endereço foi parar.
4. Resposta esperada: a saída acima (os bytes por troca: 8 e 224).

```bash
~/LPEDC/rodar 08-structs/lista/P0812.c
```

---

**Exercício P0813** · ★★☆ · Pix, cartão ou dinheiro

O caixa da loja aceita três formas de pagamento, e cada uma tem dados
diferentes. Represente com uma union etiquetada:


```text
typedef enum { PIX, CARTAO, DINHEIRO } Forma;
typedef struct {
    Forma forma;   // a etiqueta: diz qual campo da union vale
    double valor;
    union {
        char chave[40];                              // PIX
        struct { char final[5]; int parcelas; } cartao; // CARTAO
        double recebido;                             // DINHEIRO
    } dados;
} Pagamento;
```


Escreva void recibo(const Pagamento *p), que usa um switch na etiqueta e
mostra o que vale para aquela forma (no dinheiro, o troco; no cartão, o
valor de cada parcela). Mostre os recibos dos três pagamentos abaixo e o
sizeof da union e do Pagamento:


```text
Saída esperada:
PIX de R$ 87.50 para loja@exemplo.com.br
Cartão final 4467: R$ 359.70 em 3x de R$ 119.90
Dinheiro: R$ 42.30, recebido R$ 50.00, troco R$ 7.70
sizeof da union: 40 bytes; sizeof do Pagamento: 56 bytes
```

**Dicas:**

1. Inicialize com campos nomeados: {.forma = CARTAO, .valor = 359.70,
   .dados.cartao = {"4467", 3}}.
2. Num Pagamento, só UM campo da union guarda dado de verdade. Ler outro
   (dados.recebido de um PIX) mostra os bytes da chave lidos como double:
   lixo. Por isso a etiqueta.
3. O tamanho da union é o do maior campo (a chave, 40 bytes).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0813.c
```

---

**Exercício P0814** · ★★☆ · A cor em 16 bits

Telas pequenas (como a de uma maquininha de cartão) guardam cada cor em 16
bits no formato RGB565: 5 bits de vermelho (bits 15 a 11), 6 de verde (10 a
5) e 5 de azul (4 a 0). Partindo de uma cor de 8 bits por canal (0 a 255),
escreva:


```text
uint16_t para_565(int r, int g, int b);   // guarda os bits mais altos
void de_565(uint16_t c, int *r, int *g, int *b);  // volta para 0..255
```


Para converter, jogue fora os bits de baixo: r >> 3 (fica com 5 bits),
g >> 2 (6 bits), b >> 3. Para voltar, desloque para a esquerda e repita os
bits de cima nos de baixo: r8 = (r5 << 3) | (r5 >> 2) (e g8 = (g6 << 2) |
(g6 >> 4)). Converta as cores abaixo, mostrando o valor em hexa e a cor
recuperada (repare que algumas perdem um pouco de precisão):


```text
laranja (255, 136, 0), verde-bandeira (0, 156, 59), branco (255, 255, 255)
```



```text
Saída esperada:
laranja        (255, 136,   0) -> 0xFC40 -> (255, 138,   0)
verde-bandeira (  0, 156,  59) -> 0x04E7 -> (  0, 158,  57)
branco         (255, 255, 255) -> 0xFFFF -> (255, 255, 255)
```

**Dicas:**

1. Montar: (uint16_t) (((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3)).
2. Separar: r5 = (c >> 11) & 0x1F; g6 = (c >> 5) & 0x3F; b5 = c & 0x1F.
3. 0x1F são 5 bits ligados (31) e 0x3F são 6 (63).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0814.c
```

---

**Exercício P0815** · ★★☆ · O estoque por categoria

Uma loja de material de construção tem produtos de quatro categorias:


```text
typedef enum { HIDRAULICA, ELETRICA, PINTURA, FERRAGEM,
               N_CATEGORIAS } Categoria;
```


O último nome do enum (N_CATEGORIAS) vale 4 e serve de tamanho para vetores
indexados pela categoria. Com os produtos abaixo (nome, categoria,
quantidade, preço), calcule, num vetor de N_CATEGORIAS posições, quantos
itens e quanto dinheiro há em estoque em cada categoria, e mostre a
categoria com mais dinheiro parado:


```text
Tubo PVC 25mm      HIDRAULICA  40  12.90
Fio 2,5mm (rolo)   ELETRICA    15  189.00
Tinta 18L          PINTURA      8  329.90
Registro 3/4       HIDRAULICA  22  45.50
Disjuntor 20A      ELETRICA    30  28.00
Parafuso (cento)   FERRAGEM    60  9.80
Rolo de lã         PINTURA     25  24.90
```



```text
Saída esperada:
 62 itens  R$  1517.00  Hidráulica
 45 itens  R$  3675.00  Elétrica
 33 itens  R$  3261.70  Pintura
 60 itens  R$   588.00  Ferragem
Mais dinheiro parado: Elétrica
```

**Dicas:**

1. typedef struct { char nome[20]; Categoria cat; int qtd; double preco; }
   Produto;
2. int itens[N_CATEGORIAS] = {0}; double valor[N_CATEGORIAS] = {0}; e,
   para cada produto, itens[p.cat] += p.qtd.
3. Os nomes vêm de um vetor de strings na mesma ordem do enum:
   const char *nome_cat[N_CATEGORIAS] = {"Hidráulica", ...};
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0815.c
```

---

**Exercício P0816** · ★★☆ · Batalha naval

O tabuleiro de batalha naval é uma matriz 5x5 de structs:


```text
typedef struct { bool navio; bool atingida; } Casa;
```


Os navios ocupam as casas marcadas com '#' no mapa abaixo. Monte a matriz a
partir do mapa (as linhas são strings), dispare os tiros da lista e mostre,
para cada tiro, "água", "fogo!" ou "repetido". No fim, mostre o tabuleiro
('X' navio atingido, 'o' tiro na água, '#' navio intacto, '.' nada) e
quantas casas de navio sobraram:


```text
const char *mapa[5] = {".##..", ".....", "#...#", "#...#", "#...."};
int tiros[7][2] = {{0, 1}, {2, 2}, {0, 2}, {3, 0}, {0, 1}, {4, 4}, {2, 4}};
```



```text
Saída esperada:
Tiro (0, 1): fogo!
Tiro (2, 2): água
Tiro (0, 2): fogo!
Tiro (3, 0): fogo!
Tiro (0, 1): repetido
Tiro (4, 4): água
Tiro (2, 4): fogo!
.XX..
.....
#.o.X
X...#
#...o
Sobram 3 casas de navio
```

**Dicas:**

1. Casa t[5][5]; e t[i][j].navio = (mapa[i][j] == '#'); t[i][j].atingida =
   false;
2. Escreva const char *atirar(Casa t[5][5], int l, int c), que devolve a
   frase e marca a casa como atingida.
3. Um tiro numa casa já atingida é "repetido", tenha navio ou não.
4. Resposta esperada: a saída acima (sobram 3 casas de navio).

```bash
~/LPEDC/rodar 08-structs/lista/P0816.c
```

---

**Exercício P0817** · ★★☆ · Conserte a promoção da vitrine

O programa abaixo deveria dar 15% de desconto em todos os produtos da
vitrine e mostrar o total. Ele tem DOIS erros de propósito: um faz a
promoção não chegar nos produtos (o programa roda e mostra o preço
antigo); o outro o AddressSanitizer acusa quando roda. O gcc não avisa de
nenhum. Conserte os dois. O programa deve mostrar:


```text
Saída esperada:
Rede de dormir     R$ 102.00
Cuia pintada       R$  29.75
Colar de sementes  R$  40.80
Farinha 1 kg       R$  11.90
Total              R$ 184.45
```

**Dicas:**

1. Produto p = v[i]; cria uma CÓPIA da struct. Mexer em p não mexe em
   v[i]. Use um ponteiro: Produto *p = &v[i]; e p->preco.
2. p <= v + n passa uma casa do fim: v + n é o endereço logo depois do
   último produto.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0817.c
```

---

**Exercício P0818** · ★★☆ · Os números complexos

Crie typedef struct { double re, im; } Complexo; e escreva soma,
multiplica (as duas devolvem um Complexo novo), double modulo(Complexo z)
e void mostrar(const char *rotulo, Complexo z), que mostra no formato
"a + bi" ou "a - bi". Com z = 1 + 2i e w = 3 - i, mostre z + w, z * w e
|z * w|. Depois mostre as potências de i, de i¹ a i⁸, multiplicando uma de
cada vez:


```text
Saída esperada:
z + w = 4 + 1i
z * w = 5 + 5i
|z * w| = 7.0711
i^1 = 0 + 1i
i^2 = -1 + 0i
i^3 = 0 - 1i
i^4 = 1 + 0i
i^5 = 0 + 1i
i^6 = -1 + 0i
i^7 = 0 - 1i
i^8 = 1 + 0i
```

**Dicas:**

1. (a + bi)(c + di) = (ac - bd) + (ad + bc)i.
2. |a + bi| = sqrt(a² + b²).
3. No mostrar, se z.im < 0, mostre " - " e o valor absoluto (fabs).
4. As potências de i se repetem a cada 4: i, -1, -i, 1.
5. Na conta de i³, a parte real sai como -0 (o double tem zero com sinal:
   -1 * 0 = -0) e o printf mostra "-0". Teste z.re == 0 (que vale para os
   dois zeros) e mostre 0.
6. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0818.c
```

---

**Exercício P0819** · ★★☆ · A senha escondida com XOR

O operador ^ (ou exclusivo) tem uma propriedade útil: (x ^ k) ^ k == x.
Aplicar a mesma chave duas vezes devolve o original. Escreva void
cifrar(char *s, size_t n, unsigned char chave), que aplica ^ chave em cada
um dos n bytes de s, e void hexa(const char *s, size_t n), que mostra os n
bytes em hexadecimal. Cifre a mensagem com a chave 0x5A, mostre os bytes,
decifre e mostre de novo. Depois conte quantos bits a chave tem ligados e
mostre a chave em binário:


```text
char msg[] = "Encontro no Teatro Amazonas, 19h";
```



```text
Saída esperada:
Cifrada:
1F 34 39 35 34 2E 28 35 7A 34 35 7A 0E 3F 3B 2E
28 35 7A 1B 37 3B 20 35 34 3B 29 76 7A 6B 63 32
Decifrada: Encontro no Teatro Amazonas, 19h
Chave 0x5A = 01011010 (4 bits ligados)
```

**Dicas:**

1. Depois de cifrar, a mensagem pode ter um byte 0 no meio (quando o
   caractere é igual à chave): por isso a função recebe n e não usa o
   '\0'. Guarde n = strlen(msg) ANTES de cifrar.
2. Em hexa: printf("%02X ", (unsigned char) s[i]).
3. Para contar bits: while (x) { cont += x & 1; x >>= 1; }
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0819.c
```

---

**Exercício P0820** · ★★☆ · A série do tamanho certo

Desde o C99, o ÚLTIMO campo de uma struct pode ser um vetor sem tamanho (o
"membro flexível"): typedef struct { char nome[16]; int n; double v[]; }
Serie;. O sizeof da struct não conta o vetor, e você aloca a struct junto
com quantas posições quiser, num bloco só:


```text
Serie *s = malloc(sizeof *s + n * sizeof s->v[0]);
```


Escreva Serie *nova_serie(const char *nome, const double *dados, int n), e
crie duas séries de chuva (em mm), uma de 3 dias e outra de 7. Mostre cada
série, a média, o sizeof da struct e quantos bytes cada bloco tem. Libere
com UM free por série:


```text
Belém: 12.5 30.0 8.0
Manaus: 0.0 4.5 22.0 18.0 0.0 6.5 11.0
```



```text
Saída esperada:
sizeof(Serie) = 24 bytes
Belém (3 dias): 12.5 30.0  8.0
  média 16.83 mm, bloco de 48 bytes
Manaus (7 dias):  0.0  4.5 22.0 18.0  0.0  6.5 11.0
  média 8.86 mm, bloco de 80 bytes
```

**Dicas:**

1. sizeof(Serie) conta nome (16) e n (4), mais o preenchimento que
   alinha o double: 24 bytes. O vetor v não entra.
2. Depois do malloc, preencha s->n e copie os dados para s->v[i].
3. Como é um bloco só, um free(s) libera a struct e o vetor juntos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0820.c
```

## ★★★ Desafio

**Exercício P0821** · ★★★ · O catálogo ordenado por três chaves

O catálogo de uma loja de eletrônicos é um vetor de structs:


```text
typedef enum { CELULAR, NOTEBOOK, FONE } Categoria;
typedef struct {
    char nome[24]; Categoria cat; double preco; int estoque;
} Produto;
```


Ordene com qsort por uma chave COMPOSTA: primeiro a categoria (na ordem do
enum), depois o preço (do mais barato ao mais caro) e, no empate, o nome
(ordem alfabética). Depois mostre o catálogo agrupado, com um cabeçalho por
categoria e, no fim de cada grupo, o valor do estoque (preço x estoque) da
categoria:


```text
Saída esperada:
== Celulares ==
  Celular Lite       R$   999.00  x18
  Celular Alfa       R$  1899.00  x 4
  Celular Mega 5G    R$  1899.00  x10
  Estoque: R$ 44568.00
== Notebooks ==
  Notebook Basic     R$  2499.00  x 7
  Notebook Ultra 14  R$  4299.00  x 3
  Notebook Pro 16    R$  8999.00  x 1
  Estoque: R$ 39389.00
== Fones ==
  Fone com fio       R$    39.90  x60
  Fone Bluetooth X   R$   199.90  x25
  Fone Gamer         R$   199.90  x12
  Estoque: R$ 9790.30
```

**Dicas:**

1. Uma comparação com três critérios: if (a->cat != b->cat) return
   (int) a->cat - (int) b->cat; depois o preço com (x > y) - (x < y);
   por fim, strcmp dos nomes.
2. Para agrupar depois de ordenar, basta perceber quando a categoria muda
   de um produto para o próximo: aí fecha o grupo anterior e abre outro.
3. Os nomes das categorias: const char *nome_cat[] = {"Celulares",
   "Notebooks", "Fones"};
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0821.c
```

---

**Exercício P0822** · ★★★ · O conjunto de bits dos assentos

Um ônibus de viagem tem 100 lugares (0 a 99), e cada lugar vendido é um
bit: 100 bits cabem em 13 bytes (unsigned char v[13]). Crie


```text
typedef struct { unsigned char bits[13]; } Conjunto;
```


e escreva inserir, remover, contem (bool), tamanho (quantos bits ligados),
uniao e intersecao (as duas devolvem um Conjunto novo) e mostrar (lista os
números). Dois aplicativos venderam lugares sem conversar entre si:


```text
app A: 3 7 12 40 41 42 77 98
app B: 7 15 40 63 98 99
```


Mostre os vendidos de cada app, a união (todos os vendidos), a interseção
(lugares vendidos DUAS vezes: problema!) e quantos lugares ainda estão
livres. Depois o app A cancela o lugar 7; mostre a nova interseção:


```text
Saída esperada:
App A (8): 3 7 12 40 41 42 77 98
App B (6): 7 15 40 63 98 99
Vendidos (11): 3 7 12 15 40 41 42 63 77 98 99
Vendidos duas vezes (3): 7 40 98
Livres: 89 de 100 (em 13 bytes)
Depois do cancelamento, duas vezes (2): 40 98
```

**Dicas:**

1. O número k mora no byte k / 8, bit k % 8: ligar é bits[k / 8] |= 1u <<
   (k % 8); testar é (bits[k / 8] >> (k % 8)) & 1.
2. União e interseção são feitas BYTE a BYTE: r.bits[i] = a.bits[i] |
   b.bits[i] (ou &). São 13 operações para 100 números.
3. Conjunto vazio: Conjunto c = {0};
4. Livres = 100 - tamanho(união).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0822.c
```

---

**Exercício P0823** · ★★★ · Do CSV para o vetor de structs

O formulário de inscrição da corrida de rua exportou um CSV, uma pessoa por
linha (nome;idade;cidade), e algumas linhas vieram com defeito:


```text
const char *linhas[7] = {"Ana Paula;34;Manaus", "Joel;abc;Parintins",
                         "Rosa;52;Manaus", "Iuri;19;Itacoatiara",
                         "Sem cidade;40", "Marta;27;Parintins",
                         "Caio;61;Manaus"};
```


Crie typedef struct { char nome[24]; int idade; char cidade[16]; } Atleta;
e escreva bool ler_atleta(const char *linha, Atleta *a), que separa os
três campos (com strchr ou andando com um ponteiro), confere se a idade é
só de dígitos, se há exatamente 3 campos e se cada texto cabe no seu
campo, e preenche *a. Guarde as linhas boas num vetor de Atleta, mostre as
recusadas e, das aceitas, a média de idade, o mais velho e quantos atletas
há por cidade:


```text
Saída esperada:
Recusada: "Joel;abc;Parintins"
Recusada: "Sem cidade;40"
Aceitas: 5
Média de idade: 38.6
Mais velho: Caio, 61 anos
Manaus: 3
Itacoatiara: 1
Parintins: 1
```

**Dicas:**

1. strchr(s, ';') devolve o endereço do próximo ';' (ou NULL). A
   distância (p - s) é o tamanho do campo: copie com memcpy e feche com
   '\0' (confira antes se cabe).
2. Para a contagem por cidade, um segundo vetor de structs { char
   cidade[16]; int total; } que cresce quando aparece cidade nova (procure
   com strcmp).
3. Converta a idade com a sua própria conta (o atoi aceitaria "abc" e
   devolveria 0 sem avisar).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0823.c
```

---

**Exercício P0824** · ★★★ · Matriz esparsa vezes vetor

A rede de distribuição de água de um bairro tem 6 reservatórios, e a
matriz A diz quanto (em mil litros) cada reservatório j manda para o
ponto i. Quase tudo é zero, então A é guardada só pelos termos não nulos:


```text
typedef struct { int l, c; double v; } Termo;
```



```text
Termo a[7] = {{0, 0, 2.0}, {0, 3, 1.5}, {1, 1, 4.0}, {2, 5, 0.5},
              {3, 0, 1.0}, {3, 2, 3.0}, {5, 4, 2.5}};
```


Escreva void mult(const Termo *t, int k, const double *x, double *y,
int linhas), que calcula y = A x passando UMA vez pelos k termos (sem
montar a matriz 6x6): cada termo (l, c, v) soma v * x[c] em y[l]. Com o
vetor x de horas de bomba ligada abaixo, mostre y, quantas multiplicações
foram feitas e quantas a matriz cheia faria. Depois calcule a transposta
(troque l e c de cada termo) e mostre Aᵀ x:


```text
double x[6] = {3, 1, 2, 4, 2, 6};
```



```text
Saída esperada:
A x = 12.0 4.0 3.0 9.0 0.0 5.0
Multiplicações: 7 (a matriz cheia faria 36)
At x = 10.0 4.0 12.0 4.5 15.0 1.0
```

**Dicas:**

1. Zere y antes: for (int i = 0; i < linhas; i++) y[i] = 0;
2. Depois: for (int p = 0; p < k; p++) y[t[p].l] += t[p].v * x[t[p].c];
3. Matriz cheia: 6 x 6 = 36 multiplicações; esparsa: só k = 7.
4. Na transposta, monte um Termo tt[7] com tt[p].l = a[p].c e tt[p].c =
   a[p].l. A ordem dos termos não importa para a multiplicação.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0824.c
```

---

**Exercício P0825** · ★★★ · Conserte o painel de sensores

O painel de uma estufa lê sensores de tipos diferentes, guardados numa
union etiquetada, e cada sensor tem flags de estado em bits. O programa
tem TRÊS erros de propósito: o gcc avisa de dois (leia os warnings) e o
terceiro é de lógica (o programa roda, mas mostra coisa errada).
Conserte os três. O programa deve mostrar:


```text
Saída esperada:
Estufa 1: 38.5 graus
  ALERTA
Estufa 2: 81% de umidade
Depósito: porta aberta
  bateria fraca
```

**Dicas:**

1. == tem precedência MAIOR que &: flags & ALERTA == ALERTA é lido como
   flags & (ALERTA == ALERTA), ou seja, flags & 1. Use parênteses.
2. Um case sem break "cai" no próximo: o sensor de umidade mostra duas
   linhas.
3. A etiqueta tem que bater com o campo da union que foi preenchido: ler
   .graus de um sensor que guardou .porcento interpreta os bytes errados.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0825.c
```

---

**Exercício P0826** · ★★★ · Os conflitos da agenda

A agenda de uma fisioterapeuta está fora de ordem e tem compromissos que se
sobrepõem. Crie:


```text
typedef enum { SEG, TER, QUA, QUI, SEX } Dia;
typedef struct { int h, m; } Horario;
typedef struct { char titulo[24]; Dia dia; Horario ini, fim; } Compromisso;
```


Ordene com qsort por dia e, no mesmo dia, pelo horário de início. Depois
mostre a agenda e, para cada par de compromissos SEGUIDOS (na ordem) do
mesmo dia que se sobrepõem, uma linha de conflito com quantos minutos se
cruzam. Encostar (um termina 10:00 e o outro começa 10:00) não é conflito:


```text
Saída esperada:
seg 08:00-09:15 RPG Larissa
seg 09:00-10:00 Hidroterapia Seu Juca
seg 14:30-15:30 Avaliação Sr. Moacir
qua 09:00-10:00 Pilates Dona Cleide
qua 09:40-11:00 Reunião da clínica
qua 11:00-11:30 Retorno Paulinho
sex 18:00-20:00 Curso online
Conflito (seg): "RPG Larissa" e "Hidroterapia Seu Juca", 15 min
Conflito (qua): "Pilates Dona Cleide" e "Reunião da clínica", 20 min
```

**Dicas:**

1. int minutos(Horario t) { return t.h * 60 + t.m; } simplifica tudo.
2. Na comparação: primeiro a->dia - b->dia; depois minutos(a->ini) -
   minutos(b->ini).
3. Depois de ordenar, o compromisso i e o i + 1 do mesmo dia se cruzam se
   minutos(v[i + 1].ini) < minutos(v[i].fim). Os minutos cruzados são
   (o menor dos dois fins) - (início do segundo).
4. Resposta esperada: a saída acima (dois conflitos).

```bash
~/LPEDC/rodar 08-structs/lista/P0826.c
```

---

**Exercício P0827** · ★★★ · O crivo de primos em bits

O crivo de Eratóstenes marca os números compostos até N. Com um bool por
número, N = 1000 gasta 1001 bytes; com um BIT por número, gasta 126. Crie


```text
typedef struct { int n; unsigned char bits[126]; } Crivo;
```


em que o bit k ligado quer dizer "k é composto". Escreva void
montar(Crivo *c, int n), bool eh_primo(const Crivo *c, int k) e use-as
para mostrar quantos primos há até 1000, os primos entre 900 e 1000, o
maior intervalo entre dois primos seguidos até 1000 e a memória usada:


```text
Saída esperada:
Primos até 1000: 168
Entre 900 e 1000: 907 911 919 929 937 941 947 953 967 971 977 983 991 997
Maior intervalo: 20 (de 887 a 907)
Memória: 126 bytes de bits (com bool seriam 1001)
```

**Dicas:**

1. Ligue os bits de 0 e 1 (não são primos). Para cada i com i * i <= n
   que ainda é primo, marque i * i, i * i + i, i * i + 2i, ... como
   compostos.
2. Ligar o bit k: c->bits[k / 8] |= 1u << (k % 8). Testar: (c->bits[k /
   8] >> (k % 8)) & 1.
3. Para o maior intervalo, guarde o primo anterior enquanto anda de 2 a
   1000.
4. Resposta esperada: a saída acima (168 primos).

```bash
~/LPEDC/rodar 08-structs/lista/P0827.c
```

---

**Exercício P0828** · ★★★ · O cabeçalho do pacote em 32 bits

Um protocolo de sensores sem fio manda, antes de cada pacote, um cabeçalho
de 32 bits com quatro campos:


```text
bits 31-28: versão (4 bits)    bits 27-24: tipo (4 bits)
bits 23-16: tamanho (8 bits)   bits 15-0:  id (16 bits)
```


Crie typedef struct { unsigned versao, tipo, tamanho, id; } Cabecalho; e
escreva:


```text
bool empacotar(const Cabecalho *c, uint32_t *saida); // false: não cabe
Cabecalho desempacotar(uint32_t x);
```


Empacote os três cabeçalhos abaixo, mostre em hexa, desempacote e confira
que voltou igual. O terceiro tem tamanho 300, que não cabe em 8 bits:
empacotar recusa. Por fim, compare com uma struct de CAMPOS DE BITS
(unsigned versao : 4; ...), em que o compilador faz os deslocamentos, e
mostre o sizeof das duas:


```text
{2, 5, 64, 1027}   {15, 0, 255, 65535}   {1, 3, 300, 7}
```



```text
Saída esperada:
{2, 5, 64, 1027} -> 0x25400403 -> {2, 5, 64, 1027} ok
{15, 0, 255, 65535} -> 0xF0FFFFFF -> {15, 0, 255, 65535} ok
{1, 3, 300, 7} -> recusado: campo grande demais
Campos de bits: {2, 5, 64, 1027}
sizeof(Cabecalho) = 16, sizeof(Compacto) = 4
```

**Dicas:**

1. Empacotar: ((uint32_t) v << 28) | ((uint32_t) t << 24) | ((uint32_t)
   tam << 16) | id. Antes, recuse se v > 0xF, t > 0xF, tam > 0xFF ou id >
   0xFFFF.
2. Desempacotar: versao = (x >> 28) & 0xF; tipo = (x >> 24) & 0xF;
   tamanho = (x >> 16) & 0xFF; id = x & 0xFFFF.
3. Campos de bits: typedef struct { unsigned id : 16; unsigned tamanho : 8;
   unsigned tipo : 4; unsigned versao : 4; } Compacto; A ordem dos bits
   dentro da palavra depende do compilador: para mandar pela rede, as
   contas com << e >> são as que você controla.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0828.c
```

---

**Exercício P0829** · ★★★ · A multa da biblioteca

A biblioteca municipal empresta livros por 14 dias e cobra R$ 1,50 por dia
de atraso. Crie typedef struct { int dia, mes, ano; } Data; e
typedef struct { char titulo[32]; char leitor[16]; Data saida, devolucao; }
Emprestimo;. Escreva long dias_desde_inicio(Data d), que conta os dias de
01/01/0001 até d (somando 365 ou 366 por ano completo e os dias dos meses
completos do ano de d), e use a diferença entre duas datas para achar o
atraso. Mostre, para cada empréstimo, os dias com o livro, o atraso e a
multa, e o total arrecadado:


```text
Saída esperada:
Dois Irmãos (Clarice): 9 dias, atraso 0, multa R$ 0.00
Vidas Secas (Otávio): 21 dias, atraso 7, multa R$ 10.50
Macunaíma (Fabiana): 32 dias, atraso 18, multa R$ 27.00
O Cortiço (Ramon): 21 dias, atraso 7, multa R$ 10.50
Total: R$ 48.00
```

**Dicas:**

1. Reaproveite o bissexto e o dias_no_mes do P0805.
2. dias = soma, de 1 até ano - 1, de (bissexto(a) ? 366 : 365) + soma
   dos meses de 1 até mes - 1 + dia. Para datas próximas, só a DIFERENÇA
   importa: o número em si é grande, use long.
3. Atraso = dias com o livro - 14, se for positivo; senão, 0.
4. Atenção às viradas: 20/12/2025 a 10/01/2026 são 21 dias, e 2028 é
   bissexto (29/02 existe).
5. Resposta esperada: a saída acima (total R$ 48.00).

```bash
~/LPEDC/rodar 08-structs/lista/P0829.c
```

---

**Exercício P0830** · ★★★ · A fila da triagem

No pronto-socorro, a triagem classifica cada paciente por cor, e a fila de
atendimento é ordenada pela gravidade (vermelho antes de laranja, antes de
amarelo, antes de verde) e, na mesma cor, pela ordem de chegada:


```text
typedef enum { VERDE, AMARELO, LARANJA, VERMELHO } Cor;
typedef struct { char nome[16]; Cor cor; int chegada; } Paciente;
```


A fila é um vetor de Paciente mantido SEMPRE em ordem: escreva
bool entrar(Paciente *fila, int *n, int cap, Paciente p), que encaixa o
paciente no lugar certo (como no P0514, empurrando quem tem prioridade
menor), e Paciente atender(Paciente *fila, int *n), que tira o primeiro.
Simule os eventos abaixo, na ordem, mostrando a fila depois de cada um
(chegada é o minuto em que o paciente chegou):


```text
chega Josué (verde, 0)    chega Ana (amarelo, 2)   chega Rui (verde, 3)
atende                    chega Lia (vermelho, 7)  chega Téo (amarelo, 8)
atende                    atende
```



```text
Saída esperada:
Chega Josué (verde, min 0)
  fila: Josué(verde)
Chega Ana (amarelo, min 2)
  fila: Ana(amarelo) Josué(verde)
Chega Rui (verde, min 3)
  fila: Ana(amarelo) Josué(verde) Rui(verde)
Atende Ana
  fila: Josué(verde) Rui(verde)
Chega Lia (vermelho, min 7)
  fila: Lia(vermelho) Josué(verde) Rui(verde)
Chega Téo (amarelo, min 8)
  fila: Lia(vermelho) Téo(amarelo) Josué(verde) Rui(verde)
Atende Lia
  fila: Téo(amarelo) Josué(verde) Rui(verde)
Atende Téo
  fila: Josué(verde) Rui(verde)
```

**Dicas:**

1. Escreva bool antes(const Paciente *a, const Paciente *b): a tem
   prioridade se a cor for MAIOR (o enum vai de VERDE = 0 a VERMELHO = 3)
   ou, na mesma cor, se a chegada for menor.
2. Em entrar: i = *n - 1; enquanto i >= 0 e antes(&p, &fila[i]), empurre
   fila[i] para fila[i + 1]. Uma struct se copia com = inteira.
3. Em atender: guarde fila[0], puxe todos uma casa para a frente e faça
   (*n)--.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 08-structs/lista/P0830.c
```
