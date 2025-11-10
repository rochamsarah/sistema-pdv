#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 100

typedef struct Produto {
    char nome[50];
    float precoKg, quantidade;
} produto;

produto produtos[MAX_PRODUTOS];
int tamanho = 0;


void cadastroProduto();
void exibirProdutos();
void salvarProdutos();
void carregarProdutos();
void realizarVenda();
void atualizarEstoque();

int main() {
    setlocale(LC_ALL, "Portuguese");

    carregarProdutos();

    char opcao, continuar;
    do {
        printf("\n-------------------------");
        printf("\n--- Menu Principal ---\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Exibir Produtos\n");
        printf("3 - Realizar Venda\n");
        printf("4 - Atualizar Estoque\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                do {
                    cadastroProduto();
                    printf("Deseja cadastrar outro produto? (s/n) ");
                    scanf(" %c", &continuar);
                } while (continuar == 's');
                salvarProdutos();
                break;
            case '2':
                exibirProdutos();
                break;
            case '3':
                realizarVenda();
                salvarProdutos();
                break;
            case '4':
                atualizarEstoque();
                salvarProdutos();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != '0');

    return 0;
}

void cadastroProduto() {
    if (tamanho >= MAX_PRODUTOS) {
        printf("Limite de produtos alcançado.\n");
        return;
    }

    printf("\nInforme o nome do produto: ");
    fflush(stdin);
    fgets(produtos[tamanho].nome, sizeof(produtos[tamanho].nome), stdin);
    produtos[tamanho].nome[strcspn(produtos[tamanho].nome, "\n")] = 0;

    printf("Preço: ");
    if (scanf("%f", &produtos[tamanho].precoKg) != 1) {
        printf("Erro ao ler preço.\n");
        return;
    }

    printf("Quantidade: ");
    if (scanf("%f", &produtos[tamanho].quantidade) != 1) {
        printf("Erro ao ler quantidade.\n");
        return;
    }

    tamanho++;
    printf("Produto cadastrado com sucesso!\n");
}

void exibirProdutos() {
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d - %s | Preço: R$ %.2f | Quantidade em estoque: %.2f\n",
               i + 1, produtos[i].nome, produtos[i].precoKg, produtos[i].quantidade);
    }
}

void salvarProdutos() {
    FILE *arquivo;
    arquivo = fopen("produtos.txt", "w");
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%s %.2f %.2f\n",
                produtos[i].nome, produtos[i].precoKg, produtos[i].quantidade);
    }
    fclose(arquivo);
}

void carregarProdutos() {
    FILE *arquivo;
    arquivo = fopen("produtos.txt", "r");
    if (arquivo != NULL) {
        while (fscanf(arquivo, "%49s %f %f\n",
                      produtos[tamanho].nome, &produtos[tamanho].precoKg, &produtos[tamanho].quantidade) == 3) {
            tamanho++;
        }
        fclose(arquivo);
    }
}

void realizarVenda() {
    int escolha;
    float quantidade, total = 0;
    int maisItens = 1;
    int formaPagamento;
    float valorPago, troco;

    printf("\nLista de itens disponíveis:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d - %s | Preço: R$ %.2f | Disponível: %.2f \n", 
               i + 1, produtos[i].nome, produtos[i].precoKg, produtos[i].quantidade);
    }

    printf("---------------------------------------------------");
    printf("\n\n--- SEJA BEM-VINDO AO HORTIFRUTI! ---\n");
    do {
        printf("\nEscolha o produto (0 para finalizar compra): ");
        scanf("%d", &escolha);

        if (escolha == 0) break;

        if (escolha < 1 || escolha > tamanho) {
            printf("Produto inválido.\n");
            continue;
        }

        printf("Quantidade em Kg: ");
        scanf("%f", &quantidade);

        if (quantidade > produtos[escolha - 1].quantidade) {
            printf("Quantidade indisponível.\n");
            continue;
        }

        float subtotal = quantidade * produtos[escolha - 1].precoKg;
        total += subtotal;
        produtos[escolha - 1].quantidade -= quantidade;

        printf("Subtotal para %s: R$ %.2f\n", produtos[escolha - 1].nome, subtotal);
        printf("Deseja adicionar outro item? (1 - Sim | 0 - Não): ");
        scanf("%d", &maisItens);
    } while (maisItens != 0);

    printf("---------------------------------------------------\n");
    printf("Total da Compra: R$ %.2f\n", total);

    printf("Selecione a forma de pagamento:\n");
    printf("1 - PIX\n2 - Crédito\n3 - Débito\n4 - Dinheiro\n");
    scanf("%d", &formaPagamento);

    if (formaPagamento == 4) {
        printf("Valor dado pelo cliente: R$ ");
        scanf("%f", &valorPago);
        troco = valorPago - total;
        if (troco < 0) {
            printf("Valor insuficiente! Falta R$ %.2f.\n", -troco);
            return;
        } else {
            printf("Troco: R$ %.2f\n", troco);
        }
    } else {
        printf("Realize o pagamento na máquina.\n");
    }

    printf("Compra finalizada. Obrigado pela preferência!\n");


    salvarProdutos();
}


void atualizarEstoque() {
    char nome[50];
    float quantidade;
    int encontrado = 0;

    printf("Informe o nome do produto para atualizar estoque: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            encontrado = 1;
            printf("Quantidade atual: %.2f\n", produtos[i].quantidade);
            printf("Insira a quantidade: ");
            if (scanf("%f", &quantidade) == 1) {
                produtos[i].quantidade += quantidade;
                printf("Estoque atualizado com sucesso!\n");
            } else {
                printf("Erro ao ler a quantidade.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

