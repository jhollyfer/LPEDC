// cardapio.h · os itens da lanchonete (preços em centavos)
#ifndef CARDAPIO_H
#define CARDAPIO_H

void mostrar_cardapio(void);
int preco_centavos(int codigo);   // 0 se o código não existe
void mostrar_item(int codigo);    // escreve o nome do item
int itens_vendidos(void);         // quantos itens válidos já foram pedidos

#endif
