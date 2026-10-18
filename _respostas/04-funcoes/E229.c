// 0039 · Módulos: .h, .c e compilação separada
// Exercício E229 · ★☆☆
//
// Resposta:
// a) frete.h: o protótipo é o contrato.
// b) frete.c: o corpo da função.
// c) frete.h: abre o include guard (com #define FRETE_H e, no fim, #endif).
// d) frete.c: função interna, static, invisível para quem usa.
// e) frete.c (o próprio módulo inclui o seu .h, para o compilador conferir) e
//    também o programa que usa o módulo.
// f) nenhum dos dois: o main fica no programa que usa o módulo.
// g) frete.h, se quem usa precisa conhecer o valor; senão, no frete.c.
// h) nenhum: nunca se inclui um .c.
