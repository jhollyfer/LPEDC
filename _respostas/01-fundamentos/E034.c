// 0006 · O primeiro programa
// Exercício E034 · ★★☆
//
// Resposta: a) algumas centenas de linhas (uns 700 a 900, depende do
// sistema): é o conteúdo do stdio.h, e dos arquivos que ele inclui, colado no
// lugar do #include; os comentários somem. b) puts: o texto é fixo e termina
// em \n, então o compilador troca printf por puts, que é mais simples.
// c) Com printf("Bom dia %d\n", 7) o .s volta a chamar printf, porque agora
// é preciso formatar o número. d) E034.s (assembly, texto), E034.o (código
// objeto, binário) e bomdia (o executável; é o único que roda).

#include <stdio.h>

int main(void) {
    printf("Bom dia\n");
    return 0;
}
