// 0075 · Juntando tudo
// Exercício E450 · ★★★
//
// Faça um "grep" simplificado:
//
//   rodar E450.c [-c] <palavra> <arquivo>
//
// Sem -c, mostra cada linha do arquivo que contém a palavra, com o número da
// linha, e no fim quantas linhas casaram. Com -c, mostra só a contagem. O
// código de saída é 0 se achou alguma linha e 1 se não achou (como o grep de
// verdade). Erros: argumentos errados mostram o uso em stderr; arquivo que
// não abre usa perror. Nos dois casos, devolva 2.
//
// Para testar:
//
//   $ printf 'arroz 5kg\nfeijao\narroz integral\ncafe\n' > /tmp/lista.txt
//   $ rodar E450.c arroz /tmp/lista.txt
//   1: arroz 5kg
//   3: arroz integral
//   2 linhas
//   $ rodar E450.c -c arroz /tmp/lista.txt
//   2
//   $ rodar E450.c leite /tmp/lista.txt; echo "código: $?"
//   0 linhas
//   código: 1
//
// Dicas:
// 1. Com 3 argumentos (argc == 4), o primeiro precisa ser "-c". Com 2
//    (argc == 3), não tem opção. Calcule os índices da palavra e do arquivo
//    conforme o caso.
// 2. strstr(linha, palavra) de <string.h> devolve um ponteiro para onde a
//    palavra aparece na linha, ou NULL se não aparece.
// 3. Leia com fgets numa linha de 256 caracteres. A linha já vem com '\n',
//    então imprima com "%d: %s".
// 4. Resposta esperada: as saídas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
