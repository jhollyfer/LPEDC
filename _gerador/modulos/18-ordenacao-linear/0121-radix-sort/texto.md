## 0121 · Radix sort

O counting sort do assunto 0120 é linear, mas só para chaves num intervalo
curto. Números de pedido de 0 a 999 já pedem 1000 contadores; CPFs pediriam
centenas de bilhões. O radix sort contorna o problema quebrando cada número em
dígitos, e cada dígito tem só 10 valores possíveis.

A ideia vem de antes dos computadores. Nos censos antigos, cada pessoa virava
um cartão perfurado, e uma máquina **classificadora** jogava cada cartão num
de 10 escaninhos, do 0 ao 9, conforme o furo de uma coluna. O operador juntava
os escaninhos na ordem, sem misturar, e passava o maço de novo pela coluna
seguinte. Ele começava pela coluna **menos** significativa (KNUTH, 1998).

O **radix sort**, ou ordenação digital, faz o mesmo com números: ordena todos
pelo dígito das unidades, depois pelo das dezenas, depois pelo das centenas,
até o dígito mais alto do maior número. Cada passada olha um único dígito
(CORMEN et al., 2024, cap. 8). Começar pelo dígito menos significativo se
chama **LSD**, do inglês *least significant digit*.

Cada passada é um counting sort com chaves de 0 a 9. Falta só extrair o
dígito. O dígito de `x` na casa `exp`, que vale 1, 10, 100 e assim por diante,
é `(x / exp) % 10`: a divisão inteira joga fora as casas da direita, e o resto
por 10 guarda só a última que sobrou. Para `x = 251` e `exp = 10`, `251 / 10`
dá 25, e `25 % 10` dá 5, o dígito das dezenas (SEDGEWICK, 1998, cap. 10).

O que faz tudo funcionar é a estabilidade. Cada passada **precisa ser estável**:
números com o mesmo dígito na passada atual têm de ficar na ordem que a
passada anterior deu a eles (CORMEN et al., 2024, cap. 8). Veja o 807 e o 830.
Na passada das dezenas, o 807 (dezena 0) fica antes do 830 (dezena 3). Na
passada das centenas, os dois têm 8. A estabilidade mantém o 807 na frente, e
o resultado sai certo. Se a passada não fosse estável, ela poderia desfazer o
trabalho das anteriores. O counting sort com o laço de distribuição de trás
para a frente garante isso.

O custo se conta por passada. Com `d` dígitos e base `b` (10, no caso
decimal), cada passada é um counting sort de custo O(n + b), e o total é
**O(d · (n + b))**. Para números de tamanho fixo, `d` é uma constante, e o
radix sort é linear (CORMEN et al., 2024, cap. 8). O Cormen vai além e mostra
que, para chaves de `b` bits (aqui `b` conta bits, não é a base) quebradas em
dígitos de `r` bits, o custo é Θ((b/r)(n + 2^r)), e a melhor escolha de `r`
fica perto de log₂ n.

A base não precisa ser 10. Em C, a escolha natural é a **base 256**, em que
cada "dígito" é um byte. O byte número `b` de `x` sai com os operadores bit a
bit do assunto 0065: `(x >> 8 * b) & 0xFF`, que desloca o byte desejado para
a direita e apaga o resto. Um `int` de 32 bits tem 4 bytes, e o radix sort
faz só 4 passadas, cada uma com `c[256]` (KERNIGHAN; RITCHIE, 1989).

Em nenhum momento o radix sort pergunta se um número é menor que outro: ele
só lê dígitos e os usa como índice. Por isso escapa do limite de n log n da
ordenação por comparação (SZWARCFITER; MARKENZON, 2010).

> [!WARNING]
> Se a passada distribuir da frente para trás, os empates se invertem e o
> resultado sai fora de ordem, sem erro. O número de passadas vem do **maior**
> elemento, não do primeiro.

{{exemplo}}

Oito números de pedido, de 047 a 830, ordenados em três passadas. Em amarelo,
o 807 e o 830: a passada das dezenas põe o 807 na frente, e a das centenas
respeita essa ordem:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %03d", v[i]);
    }
    printf("\n");
}

// counting sort estável de v pelo dígito (v[i] / exp) % 10
void passada(int v[], int aux[], int n, int exp) {
    int c[10] = {0};
    for (int i = 0; i < n; i++) {
        c[(v[i] / exp) % 10]++;
    }
    for (int d = 1; d < 10; d++) {
        c[d] += c[d - 1];
    }
    for (int i = n - 1; i >= 0; i--) {      // de trás para a frente
        int d = (v[i] / exp) % 10;
        c[d]--;
        aux[c[d]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
}

void radix_sort(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    int *aux = malloc(n * sizeof(int));
    if (aux == NULL) {
        return;
    }
    for (int exp = 1; maior / exp > 0; exp *= 10) {  // um dígito por passada
        passada(v, aux, n, exp);
        printf("exp = %3d:", exp);
        mostra(v, n);
    }
    free(aux);
}

int main(void) {
    int pedidos[] = {251, 47, 830, 509, 74, 216, 553, 807};
    int n = 8;

    printf("início:   ");
    mostra(pedidos, n);
    radix_sort(pedidos, n);
    return 0;
}
// Saída:
// início:    251 047 830 509 074 216 553 807
// exp =   1: 830 251 553 074 216 047 807 509
// exp =  10: 807 509 216 830 047 251 553 074
// exp = 100: 047 074 216 251 509 553 807 830
```

O laço para quando `exp` passa do maior número: com 830, são três passadas
(`exp` = 1, 10, 100), e `830 / 1000` dá 0:

{{fluxograma}}

### Passo a passo

A passada das dezenas (`exp = 10`) recebe o vetor da passada anterior. O
dígito de cada número é `(x / 10) % 10`:

| número | 830 | 251 | 553 | 074 | 216 | 047 | 807 | 509 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| dígito | 3 | 5 | 5 | 7 | 1 | 4 | 0 | 0 |

Contagem por dígito: 0 → 2, 1 → 1, 3 → 1, 4 → 1, 5 → 2, 7 → 1. Os blocos
na saída ficam `807 509 | 216 | 830 | 047 | 251 553 | 074`. No bloco do 0, o
807 vem antes do 509 porque já vinha antes.
