#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
    {
        char codigo_produto[10] , nome_produto[40];
        float preco_produto;
    };
struct pedido
    {
        char numero_pedido[10] , data_pedido[11] , codigo_comprador[10] , codigo_produto_pedido[10];   
        int quantidade_pedido_feitos , cont_pedido;
        float total_pedido;
    };
struct cliente
    {
        char codigo_cliente[10] , razao[40] , cnpj[19] , inscricao_estadual[15] , endereco[25] , telefone[12] , email[20];
        struct pedido pedido_do_cliente , lista_interna[100];
        int cont_pedido_cliente , soma_quant_produtos;
        float soma_quant_total;
    };


void criaFileCliente(struct cliente c , struct cliente lista_cliente[] , int quantidade_cliente){
    
    scanf("%*c");
    printf("Digite o codigo do cliente: ");
    fgets(c.codigo_cliente , 10 , stdin);

    printf("Digite a razao social do cliente: ");
    fgets(c.razao , 40 , stdin);

    printf("Digite o CNPJ do cliente: ");
    fgets(c.cnpj , 19 , stdin);

    printf("Digite a inscricao estadual do cliente (se nao possuir, digite 0.): ");
    fgets(c.inscricao_estadual, 15, stdin);

    printf("Digite o endereco do cliente: ");
    fgets(c.endereco , 25 , stdin);

    printf("Digite o telefone do cliente: ");
    fgets(c.telefone , 12 , stdin);

    printf("Digite o email do cliente: ");
    fgets(c.email , 20 , stdin);

    lista_cliente[quantidade_cliente] = c;
    lista_cliente[quantidade_cliente].cont_pedido_cliente = 0;
}
void salvarNoArquivoCliente(struct cliente lista_cliente[] , int iterador){
    FILE *arq = fopen("cliente.txt" , "a");
    int i;
    if (arq)
    {
        for (i = iterador ; i < 1 ; i++){
            fprintf(arq , "%s" , lista_cliente[i].codigo_cliente);
            fprintf(arq , "%s" , lista_cliente[i].razao);
            fprintf(arq , "%s" , lista_cliente[i].cnpj);
            if (strcmp(lista_cliente[i].inscricao_estadual, "0\n") == 0) {
                fprintf(arq, "ISENTO\n");
            } else {
                fprintf(arq, "%s", lista_cliente[i].inscricao_estadual);
            }
            fprintf(arq , "%s" , lista_cliente[i].endereco);
            fprintf(arq , "%s" , lista_cliente[i].telefone);
            fprintf(arq , "%s\n" , lista_cliente[i].email);
        }
        fclose(arq);
    }
    else{
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
    printf("\nArquivo salvo com sucesso.\n");
}
void salvarNoArquivoBinarioCliente(struct cliente lista_cliente[] , int quantidade_cliente){
    FILE *arq = fopen("clienteBinario.dat" , "wb");
    if (arq){
        fwrite(lista_cliente , sizeof(struct cliente) , quantidade_cliente , arq);
    }
    else{
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
    printf("\nArquivo salvo com sucesso.\n");
}
void lerDoArquivoBinarioCliente(int quantidade_cliente){
    struct cliente lista_cliente[100];
    FILE *arq;
    arq = fopen("clienteBinario.dat", "rb");
    if (arq){
        fread(lista_cliente, sizeof(struct cliente), 100 , arq);
    } else{
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);

    for (int i = 0; i < quantidade_cliente; i++) {
        printf("\n\n-=-=-=-=- Cliente %i -=-=-=-=-\n" , i + 1);
        if (lista_cliente[i].codigo_cliente != 0) {
            printf("%s" , lista_cliente[i].codigo_cliente);
            printf("%s" , lista_cliente[i].razao);
            printf("%s" , lista_cliente[i].cnpj);
            if (strcmp(lista_cliente[i].inscricao_estadual, "0\n") == 0) {
                printf("ISENTO\n");
            } else {
                printf("%s", lista_cliente[i].inscricao_estadual);
            }
            printf("%s" , lista_cliente[i].endereco);
            printf("%s" , lista_cliente[i].telefone);
            printf("%s\n" , lista_cliente[i].email);
        }
    }
}

void imprimirVetor(struct cliente lista_cliente[] , int quantidade_cliente){
    int i;
    for (i = 0 ; i < quantidade_cliente ; i++){
        printf("\n%s" , lista_cliente[i].codigo_cliente);
        printf("%s" , lista_cliente[i].razao);
        printf("%s" , lista_cliente[i].cnpj);
        if (strcmp(lista_cliente[i].inscricao_estadual, "0\n") == 0) {
            printf("ISENTO\n");
        } else {
            printf("%s", lista_cliente[i].inscricao_estadual);
        }
        printf("%s" , lista_cliente[i].endereco);
        printf("%s" , lista_cliente[i].telefone);
        printf("%s" , lista_cliente[i].email);
        }
}
void selecionaPrintaCliente(struct cliente lista_cliente[], int tamanho){
    char codigo[10];
    int posicao = -1;

    printf("Digite o codigo do cliente para mostrar as informacoes: ");
    scanf("%s" , codigo);

    for (int i = 0; i < tamanho; i++) {
        if ((strncmp(lista_cliente[i].codigo_cliente, codigo, strlen(codigo)) == 0)){
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        printf("\nCodigo: %s", lista_cliente[posicao].codigo_cliente);
        printf("Razao social: %s", lista_cliente[posicao].razao);
        printf("CNPJ: %s", lista_cliente[posicao].cnpj);
        printf("Inscricao estaudal: %s", lista_cliente[posicao].inscricao_estadual);
        printf("Endereco: %s", lista_cliente[posicao].endereco);
        printf("Telefone: %s", lista_cliente[posicao].telefone);
        printf("Email: %s\n", lista_cliente[posicao].email);
    } else {
        printf("Cliente nao encontrado.\n");
    }
}


void criaFileProduto(struct produto p , struct produto tabela[] , int quantidade_produto){

    scanf("%*c");
    printf("Digite o codigo do produto (maior que 0): ");
    fgets(p.codigo_produto , 10 , stdin);

    printf("Digite o nome do produto: ");
    fgets(p.nome_produto , 40 , stdin);

    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco_produto);

    tabela[quantidade_produto] = p;
}
void salvarNoArquivoTextoProduto(struct produto tabela[] , int quantidade_produto , int iterador){
    FILE *arq = fopen("produto.txt" , "a");
    int i;

    if (arq){
        for (i = iterador ; i < quantidade_produto ; i++){
            fprintf(arq , "%s" , tabela[i].codigo_produto);
            fprintf(arq , "%s" , tabela[i].nome_produto);
            fprintf(arq , "%.2f\n\n" , tabela[i].preco_produto);
        }
    } else{
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
    printf("\nArquivo salvo com sucesso.\n");
}
void salvarNoArquivoBinarioProduto(struct produto tabela[] , int quantidade_produto) {
    FILE *arq = fopen("produtoBinario.dat" , "wb");
    if (arq){
        fwrite(tabela , sizeof(struct produto) , quantidade_produto , arq);
    } else {
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
    printf("\nArquivo salvo com sucesso.\n");
}
void lerArquivoBinarioProduto(int quantidade_produto) {
    struct produto tabela[100];
    FILE *arq = fopen("produtoBinario.dat" , "rb");
    if (arq) {
        fread(tabela, sizeof(struct produto), quantidade_produto, arq);
    } else {
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);

    printf("\n\n-=-=-=-=- Produtos -=-=-=-=-\n");
    for (int i = 0; i < quantidade_produto; i++) {
        if (tabela[i].codigo_produto != 0){
            printf("\n\n-=-=- Produto %d -=-=-\n" , i + 1);
            printf("\nCodigo: %s", tabela[i].codigo_produto);
            printf("Nome: %s", tabela[i].nome_produto);
            printf("Preco: %.2f\n", tabela[i].preco_produto);
        }
    }
}


void criaFilePedido(struct cliente lista_cliente[] , struct produto tabela[] , int tamanho){
    int posicaoCliente , op = 1 , posicao_pedido = 0;
    float preco;
    char codigo_pedido[10] , codigo_cliente[10];

    printf("Repita o codigo do cliente: ");
    scanf("%s", codigo_cliente);

    for (int k = 0; k < tamanho; k++) {
        if ((strncmp(lista_cliente[k].codigo_cliente, codigo_cliente, strlen(codigo_cliente)) == 0)){
            posicaoCliente = k;
            break;
        }
    }
    while (op == 1){
        for (int i = posicaoCliente; i < tamanho; i++) {
            if ((strncmp(lista_cliente[i].codigo_cliente, codigo_cliente, strlen(codigo_cliente)) == 0)){
                
                strcpy(lista_cliente[i].pedido_do_cliente.codigo_comprador, codigo_cliente);

                scanf("%*c");
                printf("Digite o numero do pedido: ");
                fgets(lista_cliente[i].pedido_do_cliente.numero_pedido , 10 , stdin);

                printf("Digite a data do pedido(formato: dd/mm/aaaa): ");
                fgets(lista_cliente[i].pedido_do_cliente.data_pedido , 11 , stdin);

                printf("Digite o codigo do produto (insira algum codigo da lista de produtos): ");
                scanf("%s", codigo_pedido);

                strcpy(lista_cliente[i].pedido_do_cliente.codigo_produto_pedido, codigo_pedido);

                for (int j = 0; j < tamanho ; j++) {
                    if ((strncmp(tabela[j].codigo_produto, codigo_pedido, strlen(codigo_pedido)) == 0)){
                        preco = tabela[j].preco_produto;
                        break;
                    }
                }
                printf("Digite a quantidade de produtos desejados: ");
                scanf("%i", &lista_cliente[i].pedido_do_cliente.quantidade_pedido_feitos);

                lista_cliente[i].soma_quant_produtos += lista_cliente[i].pedido_do_cliente.quantidade_pedido_feitos;
                lista_cliente[i].soma_quant_total += lista_cliente[i].pedido_do_cliente.quantidade_pedido_feitos * preco;

                lista_cliente[i].pedido_do_cliente.total_pedido = lista_cliente[i].pedido_do_cliente.quantidade_pedido_feitos * preco;
                printf("O total do pedido sera %.2f reais.\n " , lista_cliente[i].pedido_do_cliente.total_pedido);

                lista_cliente[posicaoCliente].lista_interna[posicao_pedido] = lista_cliente[posicaoCliente].pedido_do_cliente;
                lista_cliente[posicaoCliente].cont_pedido_cliente++;
                break;
            }
        }
        printf("\n1 - continue colocando pedidos para esse cliente\nQualquer tecla - mude o cliente\n");
        scanf("%d" , &op);
        if (op != 1){
            break;
        } else{
            posicao_pedido++;
        }
    }
}

int contadorProdutos(int soma_quant_produtos , struct cliente lista_cliente[] , int tamanho){
    char data_inserir_pedido[11];

    printf("Digite a data para ver a quantidade de itens vendidos nesta data: ");
    scanf("%s", data_inserir_pedido);
    
    for (int k = 0; k < tamanho; k++) {
        for (int j = 0; j < lista_cliente[k].cont_pedido_cliente; j++){
            if ((strncmp(lista_cliente[k].lista_interna[j].data_pedido, data_inserir_pedido, strlen(data_inserir_pedido)) == 0)){
                soma_quant_produtos += lista_cliente[k].lista_interna[j].quantidade_pedido_feitos;
            }
        }
    }
    if (soma_quant_produtos == 0){
        printf("Essa data nao foi cadastrada.");
    }
    return soma_quant_produtos;
}
float contadorPrecos(float soma_quant_total , struct cliente lista_cliente[] , int tamanho){
    char data_inserir_pedido[11];

    printf("Digite a data para ver o total arrecadado nesta data: ");
    scanf("%s", data_inserir_pedido);
    
    for (int k = 0; k < tamanho; k++) {
        for (int j = 0; j < lista_cliente[k].cont_pedido_cliente; j++){
            if ((strncmp(lista_cliente[k].lista_interna[j].data_pedido, data_inserir_pedido, strlen(data_inserir_pedido)) == 0)){
                soma_quant_total += lista_cliente[k].lista_interna[j].total_pedido;
            }
        }
    }
    if (soma_quant_total == 0){
        printf("Essa data nao foi cadastrada.");
    }
    return soma_quant_total;
}

void printarPedidos(struct cliente lista_cliente[] , int tamanho){
    char codigo_cliente[10];
    int posicaoCliente;

    printf("Digite o codigo do cliente que deseja ver a nota fiscal e salvar no arquivo: ");
    scanf("%s", codigo_cliente);

    for (int k = 0; k < tamanho; k++) {
        if ((strncmp(lista_cliente[k].codigo_cliente, codigo_cliente, strlen(codigo_cliente)) == 0)){
            posicaoCliente = k;
            break;
        }
    }

    printf("\n-=-=-=-=-=-=-=-= Cliente %d -=-=-=-=-=-=-=-=\n\n", posicaoCliente + 1);
    printf("Codigo: %s\n", lista_cliente[posicaoCliente].codigo_cliente);
    printf("Razao social: %s\n", lista_cliente[posicaoCliente].razao);
    printf("CNPJ: %s\n", lista_cliente[posicaoCliente].cnpj);
    printf("Inscricao estadual: %s\n", lista_cliente[posicaoCliente].inscricao_estadual);
    printf("Endereco: %s\n", lista_cliente[posicaoCliente].endereco);
    printf("Telefone: %s\n", lista_cliente[posicaoCliente].telefone);
    printf("Email: %s\n", lista_cliente[posicaoCliente].email);

    for (int j = 0; j < lista_cliente[posicaoCliente].cont_pedido_cliente; j++) {
        printf("\n-=-=-=-=-=- Pedido %d -=-=-=-=-=-\n", j + 1);
        printf("Numero do pedido: %s", lista_cliente[posicaoCliente].lista_interna[j].numero_pedido);
        printf("Data do pedido: %s\n", lista_cliente[posicaoCliente].lista_interna[j].data_pedido);
        printf("Codigo do produto: %s\n", lista_cliente[posicaoCliente].lista_interna[j].codigo_produto_pedido);
        printf("Quantidade de produtos: %d\n", lista_cliente[posicaoCliente].lista_interna[j].quantidade_pedido_feitos);
        printf("Total do pedido: %.2f\n", lista_cliente[posicaoCliente].lista_interna[j].total_pedido);
    }
}


void salvarNoArquivoTextoPedido(struct cliente lista_cliente[] , int tamanho){
    FILE *arq = fopen("pedido.txt" , "a");
    int i , posicaoCliente;
    char codigo_cliente[10];

    printf("\nRepita o codigo do cliente que deseja salvar no arquivo: ");
    scanf("%s", codigo_cliente);

    for (int k = 0; k < tamanho; k++) {
        if ((strncmp(lista_cliente[k].codigo_cliente, codigo_cliente, strlen(codigo_cliente)) == 0)){
            posicaoCliente = k;
            break;
        }
    }

    if (arq){
        for (i = posicaoCliente ; i < tamanho ; i++){
            fprintf(arq , "\n-=-=-=-=-=-=-=-= Cliente %d -=-=-=-=-=-=-=-=\n\n", i + 1);
            fprintf(arq , "%s" , lista_cliente[i].codigo_cliente);
            fprintf(arq , "%s" , lista_cliente[i].razao);
            fprintf(arq , "%s" , lista_cliente[i].cnpj);
            fprintf(arq , "%s" , lista_cliente[i].inscricao_estadual);
            fprintf(arq , "%s" , lista_cliente[i].endereco);
            fprintf(arq , "%s" , lista_cliente[i].telefone);
            fprintf(arq , "%s", lista_cliente[i].email);

            for (int j = 0; j < lista_cliente[i].cont_pedido_cliente; j++) {
            fprintf(arq , "\n-=-=-=-=-=- Pedido %d -=-=-=-=-=-\n", j + 1);
            fprintf(arq , "%s", lista_cliente[i].lista_interna[j].numero_pedido);
            fprintf(arq , "%s", lista_cliente[i].lista_interna[j].data_pedido);
            fprintf(arq , "%s\n", lista_cliente[i].lista_interna[j].codigo_produto_pedido);
            fprintf(arq , "%d\n", lista_cliente[i].lista_interna[j].quantidade_pedido_feitos);
            fprintf(arq , "%.2f", lista_cliente[i].lista_interna[j].total_pedido);
            }
            break;
        }    
    } else{
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
    printf("\nArquivo salvo com sucesso.\n");
}
void salvarNoArquivoBinarioPedido(struct cliente lista_cliente[]) {
    FILE *arq = fopen("pedidoBinario.dat", "ab");
    
    char codigo_cliente[10];
    int posicao;

    printf("\nRepita o codigo do cliente: ");
    scanf("%s", codigo_cliente);

    for (int k = 0; k < 100; k++) {
        if ((strncmp(lista_cliente[k].codigo_cliente, codigo_cliente, strlen(codigo_cliente)) == 0)){
            posicao = k;
            break;
        }
    }
    if (arq) {
        for (int i = 0; i < lista_cliente[posicao].cont_pedido_cliente; i++){
            if (lista_cliente[posicao].cont_pedido_cliente > 0) {
                fwrite(&lista_cliente[posicao].lista_interna[i], sizeof(struct pedido), lista_cliente[posicao].cont_pedido_cliente, arq);
            }
        }
    } else {
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
    printf("\nArquivo salvo com sucesso.\n");
}


void localizarProdutoNaTabela(struct produto tabela[], int tamanho){
    char codigo[10];
    int posicao = -1;

    printf("Digite o codigo do produto para encontra-lo: ");
    scanf("%s" , codigo);

    for (int i = 0; i < tamanho; i++) {
        if ((strncmp(tabela[i].codigo_produto, codigo, strlen(codigo)) == 0)){
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        printf("Nome do produto: %s", tabela[posicao].nome_produto);
        printf("Codigo do produto: %s", tabela[posicao].codigo_produto);
        printf("Preco do produto: R$ %.2f\n", tabela[posicao].preco_produto);

    } else {
        printf("Produto nao encontrado.\n");
    }
}

void printarTabela(struct produto tabela[], int quantidade_produto){
    for (int i = 0 ; i < quantidade_produto ; i++){
            printf("Nome: %s" , tabela[i].nome_produto);
            printf("Codigo: %s" , tabela[i].codigo_produto);
            printf("Preco: %.2f\n\n" , tabela[i].preco_produto);
        }
}


void trocarProdutos(struct produto *a, struct produto *b){
    struct produto temp = *a;
    *a = *b;
    *b = temp;
}

void inserirOrdenadamente(struct produto novaTabela[], int quantidade_produto){
    for (int i = 0; i < quantidade_produto - 1; i++){
        for (int j = i + 1; j < quantidade_produto; j++){
            int codigoI = atoi(novaTabela[i].codigo_produto);
            int codigoJ = atoi(novaTabela[j].codigo_produto);

            if (codigoI > codigoJ){
                trocarProdutos(&novaTabela[i], &novaTabela[j]);
            }
        }
    }
}

void removerProdutodaTabela(struct produto tabela[], int *quantidade_produto){
    char codigo[10];
    int posicao = -1;
    printf("Digite o codigo do produto que quer remover: ");
    scanf("%s" , codigo);

    for (int i = 0; i < *quantidade_produto ; i++) {
        if ((strncmp(tabela[i].codigo_produto, codigo, strlen(codigo)) == 0)){
            posicao = i;
            break;
        }
    }

    for (int j = posicao; j < *quantidade_produto ; j++){
        tabela[j] = tabela[j + 1];
    }
    (*quantidade_produto)--;
}

void reescreverArquivotxt(struct produto tabela[] , int quantidade_produto){
    FILE *arq = fopen("produto.txt" , "w");
    int i;

    if (arq)
    {
        for (i = 0 ; i < quantidade_produto ; i++){
            fprintf(arq , "%s" , tabela[i].codigo_produto);
            fprintf(arq , "%s" , tabela[i].nome_produto);
            fprintf(arq , "%.2f\n\n" , tabela[i].preco_produto);
        }
    } else{
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
}

void reescreverArquivoBinario(struct produto tabela[] , int quantidade_produto){        //REVISAR
    FILE *arq = fopen("produtoBinario.dat" , "wb");
    if (arq){
        fwrite(tabela , sizeof(struct produto) , quantidade_produto , arq);
    } else{
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
}

void modificarItemTabela(struct produto p , struct produto tabela[] , int tamanho){     //CASE 5 - PRONTO
    char codigo[10];
    int posicao = -1;

    printf("Digite o codigo do produto para encontra-lo e modifica-lo: ");
    scanf("%s" , codigo);

    for (int i = 0; i < tamanho; i++) {
        if ((strncmp(tabela[i].codigo_produto, codigo, strlen(codigo)) == 0)){
            posicao = i;
            break;
        }
    }
    if (posicao != -1) {
        scanf("%*c");
        printf("Digite o codigo do produto (maior que 0): ");
        fgets(p.codigo_produto , 10 , stdin);

        printf("Digite o nome do produto: ");
        fgets(p.nome_produto , 40 , stdin);

        printf("Digite o preco do produto: ");
        scanf("%f", &p.preco_produto);

        tabela[posicao] = p;

    } else {
        printf("Produto nao encontrado.\n");
    }
}


int main()
{
    int quantidade_produto = 0, quantidade_cliente = 0, iteradorProduto = 0, iteradorCliente = 0;
    int escolha , vetorProdutoCheio = 0 , vetorPedidoCheio = 0 , soma_quant_produtos = 0;
    int tamanho = 100;                          //máximo de clientes , pedidos e produtos possíveis de se cadastrar
    float soma_quant_total = 0;
    struct cliente c , lista_cliente[tamanho];
    struct produto p , tabela[tamanho] , novaTabela[tamanho];

    do{
        printf("\n\nMODO DE USAR\n\n");
        printf("PARA PODER USAR AS FUNCOES 2 , 3 , 4 , 5 , 6 , 7 , 8 , 10 , PRIMEIRO EH NECESSARIO CADASTRAR OS PRODUTOS E OS CLIENTES NAS OPCOES 1 E 9.\n");
        printf("\nOU SEJA , PRIMEIRO USE AS FUNCOES 1 PARA CADASTRAR PRODUTOS E 9 PARA CADASTRAR CLIENTES. ASSIM, O RESTO DO PROGRAMA PODERA SER USADO NORMALMENTE.");
        printf("\nSEMPRE ESCOLHA CÓDIGOS DIFERENTES PARA AS COISAS, NÃO DIGITE CÓDIGOS IGUAIS.");
        printf("\nOBSERVACAO: CASO QUEIRA SALVAR EM TXT , EXECUTE TODOS OS COMANDOS ESCOLHENDO APENAS A OPCAO .TXT");
        printf("\nOBSERVACAO: CASO QUEIRA SALVAR EM BINARIO , EXECUTE TODOS OS COMANDOS ESCOLHENDO APENAS A OPCAO EM BINARIO\n");

        printf("\n1 - Cadastrar Produtos\n2 - Localizar Produto na Tabela\n3 - Mostra Produtos Ordenados na Tabela");
        printf("\n4 - Remover Produto da Tabela\n5 - Modificar Informacoes sobre um Produto na Tabela\n6 - Listar Tabela no Video");
        printf("\n7 - Listar os dados de um cliente juntamente com os seus pedidos\n8 - Gerar a Nota Fiscal das Compras e salvar o pedido\n9 - Gerar Cliente");
        printf("\n10 - Listar Mensagem sobre o Total Arrecadado pelo Supermercado e o Numero de Itens Vendidos em um dia qualquer\n");
        printf("0 - Sair do programa\n");
        scanf("%d" , &escolha);

        switch(escolha){
            case 0:
                printf("Sistema finalizado.\n");
                break;
            case 1:
                printf("\nCadastrar Produtos");
                printf("\n1 - Cadastrar Arquivo de produtos em txt\n2 - Cadastrar Arquivo de produtos em binario\n3 - Ler do arquivo .dat\n");
                scanf("%d" , &escolha);
                switch (escolha) {
                    case 1: {                                       //CASE 1 - TXT
                            criaFileProduto(p , tabela , quantidade_produto);
                            quantidade_produto++;
                            salvarNoArquivoTextoProduto(tabela , quantidade_produto , iteradorProduto);
                            iteradorProduto++;
                            vetorProdutoCheio = 1;
                        break;
                        }
                    case 2:{                                        //CASE 1 - DAT
                            criaFileProduto(p , tabela , quantidade_produto);
                            quantidade_produto++;
                            salvarNoArquivoBinarioProduto(tabela , quantidade_produto);
                            vetorProdutoCheio = 1;
                        break;
                        }
                    case 3:
                        lerArquivoBinarioProduto(quantidade_produto);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Escolha invalida.");
                        break;
                    }
                break;
            case 2:
                localizarProdutoNaTabela(tabela , tamanho);     //CASE 2
                break;
            case 3:
                printf("\nMostrar ordenado");
                printf("\n1 - Inserir ordenadamente em txt\n2 - Inserir ordenadamente em binario\n");
                scanf("%d" , &escolha);
                switch (escolha){
                    case 1:{                                       //CASE 3 - TXT
                        if (vetorProdutoCheio == 1){
                            for (int i = 0; i < tamanho; i++) {
                                strcpy(novaTabela[i].codigo_produto, tabela[i].codigo_produto);
                                strcpy(novaTabela[i].nome_produto, tabela[i].nome_produto);
                                novaTabela[i].preco_produto = tabela[i].preco_produto;
                            } 
                            inserirOrdenadamente(novaTabela , quantidade_produto);
                            printf("\nTabela ordenada:\n");
                            reescreverArquivotxt(novaTabela , quantidade_produto);
                            printarTabela(novaTabela , quantidade_produto);
                            
                        } else {
                            printf("A tabela nao foi preenchida.\n");
                        }
                        break;
                    }
                    case 2:{                                        //CASE 3 - DAT
                        if (vetorProdutoCheio == 1){
                            for (int i = 0; i < tamanho; i++) {
                                strcpy(novaTabela[i].codigo_produto, tabela[i].codigo_produto);
                                strcpy(novaTabela[i].nome_produto, tabela[i].nome_produto);
                                novaTabela[i].preco_produto = tabela[i].preco_produto;
                            } 
                            inserirOrdenadamente(novaTabela , quantidade_produto);
                            printf("\nTabela ordenada:\n");
                            reescreverArquivoBinario(novaTabela , quantidade_produto);
                            printarTabela(novaTabela , quantidade_produto);
                            
                        } else {
                            printf("A tabela nao foi preenchida.\n");
                        }
                        break;
                    }
                    case 0:
                        break;
                    default:
                        printf("Escolha invalida.");
                        break;
                }
                break;
            case 4:
                printf("\nRemover produto");
                printf("\n1 - Remover produto em txt\n2 - Remover produto em binario\n");
                scanf("%d" , &escolha);
                switch (escolha) {
                    case 1: {                                       //CASE 4 - TXT
                            removerProdutodaTabela(tabela , &quantidade_produto);
                            printf("Tabela apos a remocao:\n");
                            printarTabela(tabela , quantidade_produto);
                            reescreverArquivotxt(tabela , quantidade_produto);
                            break;
                        }
                    case 2:{                                        //CASE 4 - DAT
                            removerProdutodaTabela(tabela , &quantidade_produto);
                            printf("Tabela apos a remocao:\n");
                            printarTabela(tabela , quantidade_produto);
                            reescreverArquivoBinario(tabela , quantidade_produto);
                            break;
                        }
                    case 0:
                        break;
                    default:
                        printf("Escolha invalida.");
                        break;
                    }
                break;
            case 5:
                printf("\nModificar produto");
                printf("\n1 - Modificar produto em txt\n2 - Modificar produto em binario\n");
                scanf("%d" , &escolha);
                switch (escolha) {
                    case 1: {                                       //CASE 5 - TXT
                            modificarItemTabela(p , tabela , quantidade_produto);
                            printarTabela(tabela , quantidade_produto);
                            reescreverArquivotxt(tabela , quantidade_produto);
                            break;
                        }
                    case 2:{                                        //CASE 5 - DAT
                            modificarItemTabela(p , tabela , quantidade_produto);
                            printarTabela(tabela , quantidade_produto);
                            reescreverArquivoBinario(tabela , quantidade_produto);
                            break;
                        }
                    case 0:
                        break;
                    default:
                        printf("Escolha invalida.");
                        break;
                    }
                break;
            case 6:             //CASE 6
                if (vetorProdutoCheio == 1){
                    printarTabela(tabela , quantidade_produto);
                } else {
                    printf("A tabela nao foi preenchida.\n");
                }
                break;
            case 8:             //CASE 8
                selecionaPrintaCliente(lista_cliente, tamanho);
                criaFilePedido(lista_cliente , tabela , tamanho);
                vetorPedidoCheio = 1;
                break;
            case 7:
                printf("\nGerar a Nota Fiscal das Compras e salvar o pedido\n");
                printf("\n1 - Carregar Arquivo de pedidos em txt\n2 - Carregar Arquivo de pedidos em binario\n");
                scanf("%d" , &escolha);
                switch (escolha) {
                    case 1: {                                       //CASE 7 - TXT
                        if (vetorPedidoCheio == 1){
                            printarPedidos(lista_cliente , tamanho);
                            salvarNoArquivoTextoPedido(lista_cliente , tamanho);
                        } else {
                            printf("O(s) pedido(s) nao foi(ram) preenchido(s).\n");
                        }
                        break;
                        }
                    case 2:{                                        //CASE 7 - DAT
                        if (vetorPedidoCheio == 1){
                            printarPedidos(lista_cliente , tamanho);
                            salvarNoArquivoBinarioPedido(lista_cliente);
                        } else{
                            printf("O(s) pedido(s) nao foi(ram) preenchido(s).\n");
                        }
                        break;
                        }
                    case 0:
                        break;
                    default:
                        printf("Escolha invalida.");
                        break;
                    }
                break;
            case 9:                                                 //CASE 9
                printf("\nGerar clientes");
                printf("\n1 - Carregar Arquivo de clientes em txt\n2 - Carregar Arquivo de clientes em binario\n3 - Ler do arquivo .dat\n");
                scanf("%d" , &escolha);
                switch (escolha) {
                    case 1: {                                       //CASE 9 - TXT
                            criaFileCliente(c, lista_cliente , quantidade_cliente);
                            quantidade_cliente++;
                            salvarNoArquivoCliente(lista_cliente , iteradorCliente);
                            iteradorCliente++;
                        break;
                        }
                    case 2:{                                        //CASE 9 - DAT
                            criaFileCliente(c, lista_cliente , quantidade_cliente);
                            quantidade_cliente++;
                            salvarNoArquivoBinarioCliente(lista_cliente , quantidade_cliente);
                        break;
                        }
                    case 3:
                        lerDoArquivoBinarioCliente(quantidade_cliente);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Escolha invalida.");
                        break;
                    }
                    break;
            case 10:{
                int prod = contadorProdutos(soma_quant_produtos , lista_cliente , tamanho);
                float pre = contadorPrecos(soma_quant_total , lista_cliente , tamanho);
                printf("\nNumero de itens vendidos: %d\n" , prod);
                printf("Total arrecadado pelo supermercado: %.2f\n" , pre);
                break;
            }
            default:
                printf("Escolha invalida.");
                break;
        }
        } while (escolha != 0);
    
    return 0;
}
