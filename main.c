#include "lib.h"

// Tabela que um vetor de ponteiros para listas

int main() {
    int opcao, num, cod;
    Cartao *c;
    inicializarC();
    Usuario *u;
    inicializarU();
    DadoCompra dado;
    Compra *a;

    do{
        printf("\t\t\tEditor de listas\n\t0 - Sair\n\t1 - Inserir novo cartao\n\t2 - Inserir novo usuario\n\t"
               "3 - Inserir nova compra\n\t4 - Buscar cartao\n\t5 - Buscar usuario\n\t6 - Buscar compra\n\t7 - Imprimir tabela de cartoes\n\t8 - Imprimir tabela de usuarios\n\t9 - Imprimir compras de um cartao\n");
        scanf("%d", &opcao);
        switch(opcao){
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            inserirTabelaC(dado);
            break;
        case 2:
            inserirTabelaU();
            break;
        case 3:
           a = criarCompra(a, dado);
            break;
        case 4:
            printf("Qual o numero do cartao a ser buscado? ");
            scanf("%d", &num);
            c = buscarCartaoTabela(num);
            if(c) {
                printf("\tCartao encontrado! \nNumero do Cartao: %d \nNome do titular: %sData de validade: %d/%d\n\n", c->numUnico, c->nome, c->dataMes, c->dataAno);
            }
            else
                printf("Cartao nao encontrado!\n");
            break;
        case 5:
            printf("Qual o CPF do usuario a ser buscado? ");
            scanf("%d", &num);
            u = buscarUsuarioTabela(num);
            if(u) {
                printf("\tUsuario encontrado! \nCPF do Usuario: %d \nNome: %sEndereco: %s\n\n", u->cpf, u->nome, u->endereco);
            }
            else
                printf("Usuario nao encontrado!\n");
            break;
        case 6:
            printf("Informe o numero do cartao: ");
            scanf("%d", &num);
            printf("Informe o ID da compra: ");
            scanf("%d", &cod);

            Cartao* cartao = buscarCartaoTabela(num);
            if (cartao != NULL) {
                Compra* compra = buscarCompra(cartao, cod);
                if (compra != NULL) {
                    printf("Compra encontrada:\n");
                    printf("Codigo: %d\n", compra->dado.id);
                    printf("Valor: %.2f\n", compra->dado.valor);
                } else {
                    printf("Compra nao encontrada.\n");
                }
            } else {
                printf("Cartao nao encontrado.\n");
            }
            break;
        case 7:
            imprimirTabelaC();
            break;
        case 8:
            imprimirTabelaU();
            break;
        case 9:
            printf("Informe o numero do cartao: ");
            scanf("%d", &num);
            imprimirArvoreComprasDoCartao(num);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}
