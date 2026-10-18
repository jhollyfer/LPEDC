// 0067 · Arquivos texto
// Exercício E402 · ★★★
//
// Lista de compras automática. O programa deve:
//
// 1. Criar /tmp/estoque.txt com estas linhas (produto e quantidade em casa):
//
//   arroz 3
//   cafe 0
//   leite 8
//   ovos 2
//   sabao 6
//
// 2. Ler o estoque e, com os DOIS arquivos abertos ao mesmo tempo, gravar em
// /tmp/comprar.txt só os produtos com menos de 5 unidades, já com quanto
// falta para chegar a 5 ("arroz 2").
// 3. Fechar tudo, reabrir /tmp/comprar.txt e mostrar:
//
//   Comprar:
//   - arroz: 2
//   - cafe: 5
//   - ovos: 3
//   3 itens na lista
//
// Se o segundo fopen falhar, feche o primeiro arquivo antes de sair.
//
// Dicas:
// 1. Abra entrada em "r" e saída em "w". Leia com
//    while (fscanf(ent, "%29s %d", nome, &qtd) == 2).
// 2. if (qtd < 5) fprintf(sai, "%s %d\n", nome, 5 - qtd);
// 3. Na hora de mostrar, leia comprar.txt também com fscanf e conte os itens.
// 4. Resposta esperada: arroz 2, cafe 5, ovos 3 e "3 itens na lista".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
