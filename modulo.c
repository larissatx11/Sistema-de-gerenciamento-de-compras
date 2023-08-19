#include "lib.h"
Clista *tabelaC[MAX];
Ulista *tabelaU[MAX];
int ProxId = 1;
int cont = 0, num, adc = 0;
Cartao *aux;

//hashing
int hashing(int num){
    return num % MAX;
}

// Criar lista vazia retornando seu endereco
Clista* criarListaC(){
    Clista *c = malloc(sizeof(Clista));
    c->inicio = NULL;
    c->tam = 0;
    return c;
}
//Inicializacao da tabela
void inicializarC(){
    int i;
    for(i=0; i < MAX; i++){
        tabelaC[i] = criarListaC();
    }
}

//Inserir valores na variavel tipo Cartao
Cartao criarCartao(){
    Cartao c;
    printf("Informe o numero do cartao: ");
    scanf("%d", &c.numUnico);
    printf("Informe o nome do titular: ");
    scanf("%*c");
    fgets(c.nome, 100, stdin);
    printf("Informe a data de validade do cartao (mm aa): ");
    scanf("%d %d", &c.dataMes, &c.dataAno);
    c.a = NULL;
    return c;
}

//Inserir no inicio da lista
void inserirInicioC(Cartao c, Clista *lista){
    Cno *no = malloc(sizeof(Cno));
    no->cartao = c;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

//Inserir na tabela de cartoes
void inserirTabelaC(DadoCompra dado){
    Cartao car = criarCartao();
    int indice = hashing(car.numUnico);
    inserirInicioC(car, tabelaC[indice]);
}

//Buscar um cartao do vetor de cartoes do usuario
Cno* buscarNo(int num, Cno *inicio){
    while(inicio != NULL) {
        if(inicio->cartao.numUnico == num)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL; //Caso o cartao nao for encontrada
}

//Buscar um cartao na tabela
Cartao* buscarCartaoTabela(int num){
    int indice = hashing(num);
    Cno *no = buscarNo(num, tabelaC[indice]->inicio);
    if(no)
        return &no->cartao;
    else
        return NULL;
}

void imprimirCartao(Cartao c){
    printf("\t\t    ^\n\t    Nome: %s\t    Numero unico: %d\n\t    Data de validade: %d/%d \n\n", c.nome, c.numUnico,c.dataMes, c.dataAno);
}

void imprimirListaC(Cno *inicio){
    while(inicio != NULL) {
        imprimirCartao(inicio->cartao);
        inicio = inicio->proximo;
    }
}

//Imprimir tabela
void imprimirTabelaC(){
    int i;
    printf("\n----------------- Tabela ---------------------\n\n");
    for(i=0; i < MAX; i++){
        printf("\t\tIndice %d\n", i);
        imprimirListaC(tabelaC[i]->inicio);
    }
    printf("\n---------------- FIM Tabela --------------------\n");
}

Ulista* criarListaU(){
    Ulista *u = malloc(sizeof(Ulista));
    u->inicio = NULL;
    u->tam = 0;
    return u;
}

void inicializarU(){
    int i;
    for(i=0; i < MAX; i++){
        tabelaU[i] = criarListaU();
    }
}

//Inserir no inicio da lista encadeada de usuarios
void inserirInicioU(Usuario u, Ulista *lista){
    Uno *no = malloc(sizeof(Uno));
    no->usuario = u;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

Usuario criarUsuario(){
    Usuario u;
    Cartao *aux;
    int n, op = 1;
    printf("Informe o cpf: ");
    scanf("%d", &u.cpf);
    printf("Informe o nome: ");
    scanf("%*c");
    fgets(u.nome, 100, stdin);
    printf("Informe o endereco: ");
    fgets(u.endereco, 200, stdin);
    do{
        printf("Informe o numero do cartao que deseja vincular: ");
        scanf("%i", &n);
        aux = buscarCartaoTabela(n);
        u.cartoes[adc] = aux;
        if(aux == NULL){
            printf("Cart�o inexistente!\n");
        }else{
            printf("Deseja inserir outro cartao? (0 - Nao, 1 - Sim)  ");
            scanf("%d", &op);
            adc++;
        }
    }while(op == 1);
    u.tam = adc;
    adc = 0;
    return u;
}

void inserirTabelaU(){
    cont = 0;
    for(int i = 0; i < MAX; i++){
        if(buscarCartaoTabela(i) != NULL){
            cont++;
        }
    }
    if(cont != 0){
        Usuario usu = criarUsuario();
        int indice = hashing(usu.cpf);
        inserirInicioU(usu, tabelaU[indice]);
    } else {
        printf("Nao existe nenhum cartao cadastrado!\n");
        return;
    }
}

Uno* buscarNoUsu(int num, Uno *inicio){
    while(inicio != NULL) {
        if(inicio->usuario.cpf == num)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL; //Caso o usuario nao for encontrado
}

Usuario* buscarUsuarioTabela(int num){
    int indice = hashing(num);
    Uno *no = buscarNoUsu(num, tabelaU[indice]->inicio);
    if(no)
        return &no->usuario;
    else
        return NULL;
}

void imprimirUsuario(Usuario u){
    printf("\t\t    \n\t    Nome: %s\t    CPF: %d\n\t    Endereco: %s", u.nome, u.cpf, u.endereco);
    printf("\tCartoes vinculados: \n");
    for(int i = 0; i < u.tam; i++){
        printf("\tNumero: %d, Titular: %s\tData de validade: %d/%d \n", u.cartoes[i]->numUnico, u.cartoes[i]->nome, u.cartoes[i]->dataMes, u.cartoes[i]->dataAno);
    }
}

void imprimirListaU(Uno *inicio){
    while(inicio != NULL) {
        imprimirUsuario(inicio->usuario);
        inicio = inicio->proximo;
    }
}

//Imprimir tabela
void imprimirTabelaU(){
    int i;
    printf("\n----------------- Tabela ---------------------\n\n");
    for(i=0; i < MAX; i++){
        printf("\t\tIndice %d\n", i);
        imprimirListaU(tabelaU[i]->inicio);
    }
    printf("\n---------------- FIM Tabela --------------------\n");
}


// Fun��o para adicionar uma compra � �rvore AVL do cart�o
void adicionarCompra(Cartao* cartao, DadoCompra dado) {
        cartao->a = inserirCompra(cartao->a, dado);
}

Compra* criarCompra(Compra *a, DadoCompra dado){
    cont = 0;
    for(int i = 0; i < MAX; i++){
        if(buscarUsuarioTabela(i) != NULL){
            cont++;
        }
    }
      if(cont != 0){
         do{
            printf("Informe o CPF do usuario que realizou a compra: ");
            scanf("%d", &num);
            dado.usuario = buscarUsuarioTabela(num);
            if(dado.usuario == NULL){
                printf("Usuario inexistente, tente novamente!\n");
            }
        }while(dado.usuario == NULL);

        do{
            printf("Informe o numero do cartao utilizado na compra: ");
            scanf("%d", &num);
            aux = buscarCartaoTabela(num);
                if(aux != NULL){
                    printf("Informe o valor da compra: ");
                    scanf("%f", &dado.valor);
                    printf("Informe os itens da compra: ");
                    scanf("%*c");
                    fgets(dado.descricao, 200, stdin);
                    adicionarCompra(aux, dado);
                }else{
                    printf("Esse cartao nao esta vinculado a esse usuario, tente novamente!\n");
                }
        }while(aux == NULL);
        } else {
            printf("Nao existe nenhum usuario cadastrado!\n");
        }
}

// Fun��o para buscar um n� em uma �rvore AVL
Compra* buscar(Compra* no, int codigo) {
    if (no == NULL || no->dado.id == codigo){
        return no;
    }
    if (codigo < no->dado.id){
        return buscar(no->esq, codigo);
    }else{
        return buscar(no->dir, codigo);
    }
}

// Fun��o para buscar uma compra em um cart�o
Compra* buscarCompra(Cartao* cartao, int codigo) {
    if (cartao != NULL && cartao->a != NULL) {
        return buscar(cartao->a, codigo);
    }
    return NULL;
}

Compra* criarCompraNo(DadoCompra dado) {
    Compra* novoNo = (Compra*)malloc(sizeof(Compra));
    novoNo->dado = dado;
    novoNo->dado.id = ProxId++;
    novoNo->dado.valor = dado.valor;
    novoNo->dado.usuario = dado.usuario;
    novoNo->fator_b = 0;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

Compra* inserirCompra(Compra* a, DadoCompra dado){
	if(a == NULL){
        return criarCompraNo(dado);
	} else {
		if(dado.id < a->dado.id){
			a->esq = inserirCompra(a->esq, dado);
			a = balanceamento(a);
		}else{
            a->dir = inserirCompra(a->dir, dado);
            a = balanceamento(a);
		}
        return a;
	}
}

int altura_AVL(Compra* a){
	int alt_esq = 0, alt_dir = 0;
	if(a==NULL)
		return 0;
	else{
		alt_esq = altura_AVL(a->esq);
		alt_dir = altura_AVL(a->dir);

		if(alt_esq > alt_dir)
			return (1+ alt_esq);
		else
			return (1+alt_dir);
	}
}

int calcula_FB(Compra* a){
    return (altura_AVL(a->esq) - altura_AVL(a->dir));
}

Compra* rotacao_simples_esquerda(Compra* a){
    Compra *aux;
    aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a = aux;
    return a;
}

Compra* rotacao_simples_direita(Compra* a){
    Compra *aux;
    aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a = aux;
    return a;
}

Compra* balanceamento(Compra* a){
    int fator = calcula_FB(a);
    if(fator > 1){
        return balanceio_esquerda(a);
    }
        else if(fator < -1 ){
            return balanceio_direita(a);
        }
        return a;
}

Compra *balanceio_direita(Compra *a){
    int fator = calcula_FB(a->dir);
    if(fator < 0){
        return rotacao_simples_esquerda(a);
    }
    else if(fator > 0){
        a->dir = rotacao_simples_direita(a->dir);
        a = rotacao_simples_esquerda(a);
        return a;
    }else{
        return a;
    }
}

Compra *balanceio_esquerda(Compra *a){
    int fator = calcula_FB(a->esq);
    if(fator < 0){
        return rotacao_simples_direita(a);
    }
    else if(fator > 0){
        a->dir = rotacao_simples_esquerda(a->dir);
        a = rotacao_simples_direita(a);
        return a;
    }else{
        return a;
    }
}

// Fun��o para percorrer em ordem a �rvore AVL de compras
void imprimirArvoreCompras(Compra* a) {
    if (a == NULL){
		return;
	}
    printf("ID da compra: %d \n",a->dado.id);
    printf("Nome do usuario: %s", a->dado.usuario->nome);
    printf("Valor: %.2f \n", a->dado.valor);

    if(a->esq != NULL)
        printf("(E:%d )\t",a->esq->dado.id);
    if(a->dir != NULL)
        printf("(D:%d )",a->dir->dado.id);
    printf("\n");

    imprimirArvoreCompras(a->esq);
    imprimirArvoreCompras(a->dir);
}

// Fun��o para imprimir a �rvore de compras de um cart�o
void imprimirArvoreComprasDoCartao(int numeroCartao) {
    Cartao* cartao = buscarCartaoTabela(numeroCartao);
    if (cartao != NULL && cartao->a != NULL) {
        printf("Arvore de compras do cartao %d:\n", cartao->numUnico);
        imprimirArvoreCompras(cartao->a);
    } else {
        printf("Cart�o nao encontrado ou sem compras.\n");
    }
}
