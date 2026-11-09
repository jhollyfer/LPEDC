// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1816 · ★★☆ · Os rios do Amazonas ordenados pelo tamanho do nome
//
// Um app de geografia quer mostrar os rios do esqueleto agrupados pelo
// NÚMERO DE LETRAS do nome, do mais curto para o mais longo, e, dentro de
// cada tamanho, na ordem em que estão na lista.
//
// Ordene o vetor de strings (const char *) com counting sort estável pela
// chave strlen(nome). Os nomes têm até 12 letras. Mostre os grupos com o
// tamanho na frente e, depois, o vetor C como fica no fim da colocação:
// com os decrementos, cada C[x] passa a apontar o INÍCIO do bloco x.
//
//   Saída esperada:
//   3 letras: Ica
//   5 letras: Negro Purus Jurua
//   6 letras: Japura Javari Uatuma
//   7 letras: Madeira Tapajos
//   8 letras: Solimoes
//   9 letras: Trombetas
//   C (depois da colocação, início de cada bloco): 0 0 0 0 1 1 4 7 9 10 11 11 11
//
// Dicas:
// 1. Ordene os PONTEIROS, não as letras: saida[--c[strlen(v[i])]] = v[i]
//    copia só o endereço da string, 8 bytes, seja ela longa ou curta.
// 2. Calcule cada strlen uma vez e guarde num vetor tam[]: strlen percorre a
//    string inteira toda vez que é chamada.
// 3. Estável: Negro e Purus têm 5 letras, e Negro vem antes porque está antes
//    na lista.
// 4. Resposta esperada: 3 letras: Ica; 5: Negro Purus Jurua; 6: Japura
//    Javari Uatuma; 7: Madeira Tapajos; 8: Solimoes; 9: Trombetas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define N 11
#define MAXLEN 12

int main(void) {
    const char *rio[N] = {"Solimoes", "Madeira", "Negro", "Purus", "Japura", "Jurua",
                          "Tapajos", "Trombetas", "Javari", "Ica", "Uatuma"};

    for (int i = 0; i < N; i++) printf("%s ", rio[i]);
    printf("\n");
    return 0;
}
