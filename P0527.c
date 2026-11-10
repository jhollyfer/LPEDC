// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0527 · ★★★ · A lista de chamada em ordem
//
// A professora digitou a lista de chamada fora de ordem:
//
//   char nomes[7][20] = {"Thiago", "Ana Clara", "Bruno", "Yasmin",
//                        "Ana Beatriz", "Davi", "Larissa"};
//
// Escreva void ordenar(char v[][20], int n), que põe os nomes em ordem
// alfabética com o método da bolha (compare vizinhos com strcmp e troque com
// strcpy e uma string auxiliar). Depois escreva int buscar(char v[][20], int
// n, const char nome[]), uma busca binária que devolve a posição do nome ou
// -1. Mostre a lista numerada e procure "Davi" e "Carla":
//
//   Saída esperada:
//   1. Ana Beatriz
//   2. Ana Clara
//   3. Bruno
//   4. Davi
//   5. Larissa
//   6. Thiago
//   7. Yasmin
//   Davi: número 4 da chamada
//   Carla: não está na lista
//
// Dicas:
// 1. Bolha: para cada passada, compare v[j] com v[j + 1]; se
//    strcmp(v[j], v[j + 1]) > 0, troque as duas strings (aux = v[j], v[j] =
//    v[j + 1], v[j + 1] = aux, cada atribuição com strcpy).
// 2. Não dá para trocar strings com =: o nome de um vetor não é uma variável
//    que se possa atribuir.
// 3. Na busca binária, strcmp(nome, v[meio]) negativo manda para a metade de
//    baixo; positivo, para a de cima; zero, achou.
// 4. Resposta esperada: a saída acima ("Ana Beatriz" vem antes de "Ana Clara"
//    porque 'B' < 'C').
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {
    char nomes[7][20] = {"Thiago", "Ana Clara", "Bruno", "Yasmin",
                         "Ana Beatriz", "Davi", "Larissa"};
    (void) nomes; // apague esta linha quando escrever

    return 0;
}
