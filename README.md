# Sistema de Gerenciamento de Compras

## Descrição
Este projeto consiste em um Sistema de Gerenciamento de Compras, focado no registro e organização das transações efetuadas por clientes (usuários) por meio de cartões de crédito.

## Funcionalidades
O sistema oferece as seguintes funcionalidades:

1. **Cadastro de Transações Eletrônicas:**
   - Permite o registro de uma transação de compra, incluindo informações essenciais como nome completo do pagador, número do cartão, bandeira e código de segurança.

2. **Criptografia de Dados do Cartão de Crédito:**
   - Implementa uma estratégia de criptografia para proteger os dados sensíveis do cartão de crédito do pagador, garantindo a segurança das informações.

3. **Otimização da Busca por Histórico de Pagamentos:**
   - Prevê uma otimização futura para facilitar a busca por um histórico de pagamentos realizados por um determinado cartão de crédito. As compras efetuadas com um mesmo cartão são organizadas em conjuntos que agrupam o usuário que utilizou o cartão e os detalhes da compra.

4. **Funcionalidades Futuras:**
   - Possibilidade de cadastrar compras, cartões de crédito e usuários.
   - Listagem dos dados de um usuário específico.

## Estrutura de Dados
O sistema utiliza estruturas de tabela hash para representar tanto os usuários quanto os cartões de crédito. Essa abordagem visa a eficiência na busca e manipulação dos dados, proporcionando uma organização eficaz das informações.

## Utilização
Para utilizar o sistema, basta seguir as operações disponíveis:
- Cadastrar uma compra.
- Cadastrar cartões de crédito.
- Cadastrar usuários.
- Listar os dados de um usuário específico.

Este projeto visa fornecer uma solução robusta para o gerenciamento de transações de compra, com foco na segurança dos dados e eficiência na organização das informações.
