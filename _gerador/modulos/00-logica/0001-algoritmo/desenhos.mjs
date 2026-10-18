import { bifurcacao } from '../../../tipos/ideia.mjs'

const desenho = bifurcacao({
  inicio: { forma: 'caixinha', y: 330, nome: 'saldo', valor: 'R$ 120', tipo: 'valor = R$ 50', w: 280 },
  pergunta: ['saldo cobre', 'o valor?'],
  sim: { rotulo: 'envia', texto: ['Pix enviado!', 'Saldo: R$ 70.00'] },
  nao: { rotulo: 'avisa', texto: ['Saldo insuficiente.'], cor: 'cinza' },
})
// o exemplo não passa pelo Não
desenho.setas[2].cor = 'cinza'
export const ideia = desenho

export const fluxograma = {
  nos: [
    ['A', 'inicio', 'Início'],
    ['B', 'io', 'Ler saldo e valor'],
    ['C', 'dec', 'saldo >= valor?'],
    ['D', 'proc', 'saldo = saldo - valor'],
    ['E', 'io', 'Mostrar "Pix enviado!" e o saldo'],
    ['F', 'io', 'Mostrar "Saldo insuficiente."'],
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
  caminho: ['A', 'B', 'C', 'D', 'E', 'G'],
}
