// Lista · Módulo 06 · Ponteiros
// Exercício P0614 · ★★☆ · A extensão do arquivo
//
// O sistema de upload precisa da extensão de cada arquivo. Escreva
//
//   const char *extensao(const char *nome);
//
// que devolve um ponteiro para o texto DEPOIS do último ponto do nome (dentro
// da própria string, sem copiar nada). Se não houver ponto, ou se o único
// ponto for o primeiro caractere (arquivo oculto, como ".bashrc"), devolve um
// ponteiro para o '\0' do fim (string vazia). Teste:
//
//   const char *arquivos[5] = {"relatorio.final.pdf", "foto.JPG", "LEIAME",
//                              ".bashrc", "backup.tar.gz"};
//
// Mostre cada nome, a extensão entre colchetes e em que posição do nome ela
// começa (diferença de ponteiros):
//
//   Saída esperada:
//   relatorio.final.pdf  [pdf] posição 16
//   foto.JPG             [JPG] posição 5
//   LEIAME               [] posição 6
//   .bashrc              [] posição 7
//   backup.tar.gz        [gz] posição 11
//
// Dicas:
// 1. Ande com um ponteiro p do começo até o '\0', guardando em ultimo o
//    endereço do último '.' visto (comece com ultimo = NULL).
// 2. No fim, p aponta para o '\0': é ele que você devolve quando não há
//    extensão. Se ultimo for NULL ou igual a nome, return p.
// 3. Senão, return ultimo + 1 (o caractere logo depois do ponto).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    const char *arquivos[5] = {"relatorio.final.pdf", "foto.JPG", "LEIAME",
                               ".bashrc", "backup.tar.gz"};
    (void) arquivos; // apague esta linha quando escrever

    return 0;
}
