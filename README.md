# sistema-de-gerenciamento-de-compras
  O projeto é um Sistema de gerenciamento das compras pagas por seus clientes (usuários), através do uso de cartões de crédito.
O sistema é capaz de cadastrar uma transação eletrônica de uma compra e as informações do pagador(nome completo, número do cartão, bandeira e código de segurança). 
  Foi desenvolvido uma estratégia para criptografar os dados do cartão de crédito do pagador e otimizar (futuramente) a busca por um histórico de pagamentos realizado por um determinado cartão de crédito. Sabendo que um cartão de crédito pode ser utilizado por diversas compras, estas deverão ser arranjadas em um conjunto em que agrupem o usuário que utilizou este cartão e os dados da compra.
  Desta forma, o sistema permitirá:
• Cadastrar compra
• Cadastrar cartões de crédito
• Cadastrar usuários
• Listar os dados de um usuário
Os usuários e os cartões de créditos são representados por diferentes estruturas do tipo tabela 
hash.
