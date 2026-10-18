// 0031 · A pilha de chamadas
// Exercício E186 · ★★★
//
// Meça a altura da pilha. Use duas globais, "altura" e "maior_altura". Toda
// função, ao entrar, chama entrar() (que soma 1 em altura e atualiza
// maior_altura) e, antes de sair, chama sair() (que diminui 1). O main também
// conta: ele chama entrar() no começo.
//
// Monte estas chamadas: main chama checkout e frete; checkout chama
// cupom e pagamento; pagamento chama antifraude; frete não chama ninguém.
// No fim, o main mostra a maior altura e a altura atual (antes do sair dele).
//
//   Saída esperada:
//   Maior altura: 4
//   Altura agora: 1
//
// Dicas:
// 1. void entrar(void) { altura++; if (altura > maior_altura) maior_altura = altura; }
// 2. O caminho mais fundo é main -> checkout -> pagamento -> antifraude.
//    entrar e sair também são funções, mas não se contam (é só um contador seu).
// 3. Resposta esperada: maior altura 4, altura no fim 1 (só o main). Se
//    alguma função esquecer o sair(), a altura no fim passa de 1: é assim que
//    se caça esse tipo de erro.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
