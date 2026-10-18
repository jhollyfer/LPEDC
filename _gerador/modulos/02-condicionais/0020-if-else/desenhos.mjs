import { bifurcacao } from '../../../tipos/ideia.mjs'

const desenho = bifurcacao({
  inicio: { forma: 'caixinha', y: 330, nome: 'saldo', valor: 'R$ 3.50', tipo: 'tarifa = R$ 5.00', w: 280 },
  pergunta: ['saldo >= tarifa ?'],
  sim: { rotulo: 'if: libera', texto: ['Catraca liberada', 'saldo = saldo - 5'], cor: 'cinza' },
  nao: { rotulo: 'else: barra', texto: ['Saldo insuficiente.', 'Faltam R$ 1.50'], cor: 'verde' },
})
// o exemplo segue pelo Não (o else)
desenho.setas[1].cor = 'cinza'
desenho.setas[2].cor = 'verde'
export const ideia = desenho

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler saldo (3.50)'],
    ['C', 'dec', 'saldo >= tarifa?'],
    ['D', 'proc', 'saldo = saldo - tarifa'],
    ['E', 'io', 'Mostrar "Catraca liberada"'],
    ['F', 'io', 'Mostrar "Saldo insuficiente" e quanto falta'],
    ['G', 'inicio', 'Fim'],
  ],
  setas: [
    ['A', 'B'],
    ['B', 'C'],
    ['C', 'D', 'Sim'],
    ['D', 'E'],
    ['C', 'F', 'Não'],
    ['E', 'G'],
    ['F', 'G'],
  ],
  caminho: ['A', 'B', 'C', 'F', 'G'],
}
