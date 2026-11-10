// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2828 · ★★★ · A tabela do campeonato em duas passadas
//
// A liga do bairro tem os times em ordem alfabética, com pontos (0 a 30) e
// saldo de gols (-10 a 10): Aleixo 13 +4, Betânia 16 -1, Coroado 13 +4, Dom
// Pedro 16 +6, Educandos 9 -3, Flores 13 -2, Glória 16 -1. A classificação é
// por pontos, depois saldo (os dois do maior para o menor) e, no empate
// total, nome. Faça com duas passadas de pigeonhole estável, esvaziando as
// casas da maior para a menor: primeiro pelo saldo (21 casas), depois pelos
// pontos (31 casas). Mostre a tabela.
//
//   Saída esperada:
//   1. Dom Pedro: 16 pontos, saldo +6
//   2. Betânia: 16 pontos, saldo -1
//   3. Glória: 16 pontos, saldo -1
//   4. Aleixo: 13 pontos, saldo +4
//   5. Coroado: 13 pontos, saldo +4
//   6. Flores: 13 pontos, saldo -2
//   7. Educandos: 9 pontos, saldo -3
//
// Dicas:
// 1. O saldo s vai para a casa s + 10.
// 2. Como a entrada já está em ordem alfabética, a estabilidade cuida do
//    desempate pelo nome sem nenhuma comparação.
// 3. A última passada é a da chave principal: os pontos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
