// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2301 · ★☆☆ · Grupos do condomínio
//
// No condomínio, nove moradores (índices 0 a 8) estão em grupos de conversa:
// Ana, Bia, Caio, Duda, Edu, Fabi, Gil, Hugo e Iara. As amizades, de mão
// dupla, são:
//
//   Ana-Caio, Caio-Gil, Bia-Duda, Duda-Hugo, Edu-Fabi
//
// Escreva o programa do zero. Uma DFS dá a cada morador o número do seu
// componente (grupo[u], começando em 1, na ordem do primeiro morador de
// cada grupo). Mostre os grupos e depois responda, em O(1) cada, se estes
// pares estão no mesmo grupo: Ana e Gil, Bia e Edu, Hugo e Bia, Iara e Ana.
//
//   Saída esperada:
//   Grupo 1: Ana Caio Gil
//   Grupo 2: Bia Duda Hugo
//   Grupo 3: Edu Fabi
//   Grupo 4: Iara
//   Ana e Gil: mesmo grupo
//   Bia e Edu: grupos diferentes
//   Hugo e Bia: mesmo grupo
//   Iara e Ana: grupos diferentes
//
// Dicas:
// 1. Guarde as amizades numa matriz amigo[V][V], marcando os dois sentidos.
// 2. marca(u, g) pinta u com g e chama a si mesma para todo amigo de u
//    ainda sem grupo. O main chama marca(u, ++g) para cada u com grupo 0.
// 3. Resposta esperada: 4 grupos (Iara fica sozinha); a consulta é só
//    grupo[a] == grupo[b].
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
