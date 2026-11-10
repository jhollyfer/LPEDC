// Lista · Módulo 08 · Tipos compostos
// Exercício P0803 · ★☆☆ · O estoque baixo da farmácia
//
// Crie o tipo Remedio (codigo int, nome com até 23 letras, estoque int,
// minimo int) e guarde os 6 remédios abaixo num vetor de structs:
//
//   101 Dipirona 40 20      102 Amoxicilina 8 15     103 Losartana 22 25
//   104 Omeprazol 60 30     105 Insulina 3 10        106 Paracetamol 35 20
//
// Escreva int buscar(const Remedio *v, int n, int codigo), que devolve o
// índice do remédio (ou -1). Mostre os remédios com estoque abaixo do
// mínimo e quanto falta comprar, e depois procure os códigos 105 e 110:
//
//   Saída esperada:
//   Comprar:
//     Amoxicilina  faltam 7
//     Losartana    faltam 3
//     Insulina     faltam 7
//   Código 105: Insulina, estoque 3
//   Código 110: não cadastrado
//
// Dicas:
// 1. Inicialize o vetor direto: Remedio v[6] = {{101, "Dipirona", 40, 20},
//    ...}; os campos vão na ordem da struct.
// 2. Falta comprar = minimo - estoque.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
