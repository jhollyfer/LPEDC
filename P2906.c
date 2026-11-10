// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2906 · ★☆☆ · Verificador de cobertura com limite
//
// A versão de decisão da cobertura de vértices pergunta: "existe uma
// cobertura com no máximo k vértices?". O certificado é a própria lista.
// Uma rede tem sete roteadores (0 a 6) e os cabos:
//
//   0-1, 0-2, 1-3, 2-3, 3-4, 4-5, 4-6, 5-6
//
// Escreva bool confere(const int c[], int tam, int k), que mostra o
// veredito e o primeiro cabo descoberto, se houver. Teste os certificados
// {0, 3, 4, 5} com k = 4, {1, 2, 4, 6} com k = 4, {0, 3, 4, 6} com k = 3 e
// {1, 2, 5, 6} com k = 4.
//
//   Saída esperada:
//   aceito
//   aceito
//   rejeitado: 4 vértices, limite 3
//   rejeitado: cabo 3-4 descoberto
//
// Dicas:
// 1. Marque os vértices do certificado num vetor bool e percorra os cabos:
//    cada um precisa de pelo menos uma ponta marcada.
// 2. Confira o tamanho antes: um certificado maior que k é rejeitado mesmo que
//    cubra tudo.
// 3. Resposta esperada: a saída acima. Conferir custa O(V + E); achar a menor
//    cobertura é NP-difícil.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
