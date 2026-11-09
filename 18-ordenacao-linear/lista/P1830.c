// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1830 · ★★★ · O log do servidor: IPs ordenados por radix base 256
//
// O servidor do portal da prefeitura registrou os IPs de 16 acessos, como
// strings "a.b.c.d". Para achar quem mais acessou, ordene os IPs e conte as
// repetições, que ficam juntas.
//
// Um IPv4 são 4 bytes: guarde cada um num unsigned de 32 bits
// ((a << 24) | (b << 16) | (c << 8) | d) e ordene com radix LSD em base 256,
// 4 passadas, uma por byte, do menos significativo (d) para o mais (a).
// Escreva:
//
//   unsigned ip_de(const char *s);          // com sscanf("%u.%u.%u.%u")
//   void ip_para(unsigned ip, char s[16]);  // de volta para "a.b.c.d"
//   void radix256(unsigned v[], int n);
//
// Mostre os IPs distintos em ordem com o número de acessos e o IP que mais
// acessou. Compare com a ordem das STRINGS: "10.0.0.9" vem depois de
// "10.0.0.10" no strcmp, mas antes na ordem numérica.
//
//   Saída esperada:
//   8.8.8.8         1 acesso
//   10.0.0.9        2 acessos
//   10.0.0.10       3 acessos
//   172.16.0.1      2 acessos
//   192.168.1.3     1 acesso
//   192.168.1.20    4 acessos
//   200.17.5.3      2 acessos
//   200.17.5.30     1 acesso
//   Distintos: 8 | quem mais acessou: 192.168.1.20 (4)
//   strcmp("10.0.0.9", "10.0.0.10") > 0: sim
//
// Dicas:
// 1. Byte da passada p: (ip >> (8 * p)) & 255. São 4 passadas com C de 256
//    posições: Θ(4(n + 256)).
// 2. Confira o retorno do sscanf: tem de ser 4. Cada parte tem de ser <= 255.
// 3. Depois de ordenar, um laço conta as repetições: enquanto v[j] == v[i],
//    j++. O total de acessos de v[i] é j - i.
// 4. Resposta esperada: 8 IPs distintos; 10.0.0.9 antes de 10.0.0.10 e
//    192.168.1.20 com 4 acessos é quem mais acessou.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 16

int main(void) {
    const char *registro[N] = {"192.168.1.20", "10.0.0.10", "200.17.5.3", "10.0.0.9",
                               "192.168.1.20", "172.16.0.1", "10.0.0.10", "192.168.1.3",
                               "200.17.5.3", "192.168.1.20", "8.8.8.8", "10.0.0.9",
                               "192.168.1.20", "172.16.0.1", "10.0.0.10", "200.17.5.30"};

    for (int i = 0; i < N; i++) printf("%s\n", registro[i]);
    return 0;
}
