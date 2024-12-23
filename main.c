#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#define NUM_MAX_CAD 1024
#include<stdbool.h>

typedef struct //Cadastro fornecedor
{
	char nome[256];
	char cnpj[20];
	char endereco[256];
	char email[256];
	char telefone [20];

} cadastroFornecedor;

typedef struct //Cadastro consumidor
{
    char nome[256];
	char cpf[20];
	char endereco[256];
	char email[256];
	char telefone [20];

} cadastroConsumidor;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {

    }
}

bool tela_cadastro_fornecedor() //Tela de cadastro fornecedor
{
    char alterar, salvar, sair, opcao;

    setlocale(LC_ALL, "Portuguese");
    cadastroFornecedor cadastro;

    printf("Nome do fornecedor: \n");
    limparBuffer();
    fgets(cadastro.nome, sizeof(cadastro.nome), stdin);
    cadastro.nome[strcspn(cadastro.nome, "\n")] = '\0';

    printf("CNPJ: \n");
    fgets(cadastro.cnpj, sizeof(cadastro.cnpj), stdin);
    cadastro.cnpj[strcspn(cadastro.cnpj, "\n")] = '\0';

    printf("Endereço: \n");
    fgets(cadastro.endereco, sizeof(cadastro.endereco), stdin);
    cadastro.endereco[strcspn(cadastro.endereco, "\n")] = '\0';

    printf("E-mail: \n");
    fgets(cadastro.email, sizeof(cadastro.email), stdin);
    cadastro.email[strcspn(cadastro.email, "\n")] = '\0';

    printf("Telefone: \n");
    fgets(cadastro.telefone, sizeof(cadastro.telefone), stdin);
    cadastro.telefone[strcspn(cadastro.telefone, "\n")] = '\0';

    do
    {
        system("pause");
        system("cls");

        printf("-----------------------------------------------\n");
        printf("Deseja alterar alguma informação?(S/N)\n\n");
        printf("Nome: %s\nCNPJ: %s\nEndereço: %s\nE-mail: %s\nTelefone: %s\n\n",
               cadastro.nome, cadastro.cnpj, cadastro.endereco, cadastro.email, cadastro.telefone);
        printf("-----------------------------------------------\n");
        scanf(" %c", &alterar);

        if(alterar == 'n')
        {
            printf("\nDeseja salvar as informações? (S/N)\n");
            scanf(" %c", &salvar);

            if (salvar == 's')
            {
                //Criar uma função de salvar o cadastro e ir para a tela de usuário
                printf("\nCadastro salvo com sucesso!");
                return true;
            }
        }
        else if (alterar == 's')
        {
            do
            {
                limparBuffer();

                printf("\nSelecione a opção que deseja alterar:\n");
                printf("1- Nome\n");
                printf("2- CNPJ\n");
                printf("3- Endereço\n");
                printf("4- E-mail\n");
                printf("5- Telefone\n");
                printf("6- Sair\n");
                scanf(" %c", &opcao);

                if (opcao == '6')
                {
                    break;
                }
                else
                {
                    alterar_campos_fornecedor (opcao, cadastro);
                }

            }while(opcao != '6');

            printf("\nDeseja salvar as informações? (S/N)\n");
            scanf(" %c", &salvar);

            if (salvar == 's')
            {
                //Criar uma função de salvar o cadastro e ir para a tela de usuário
                printf("\nCadastro salvo com sucesso!");
                return true;
            }

        }
        else
        {
            printf("\nOpção inválida!\nEscolha novamente\n");
            continue;
        }
        printf("\nDeseja sair?(S/N)\n");
        scanf(" %c", &sair);

        if(sair == 's')
        {
            break;
        }
    }while(sair != 's');

    return false;
}

void alterar_campos_fornecedor (char opcao, cadastroFornecedor fornecedor) //Editar os campos de fornecedor
{
    switch(opcao)
    {
        case '1':
            printf("\nInforme um novo nome:\n");
            limparBuffer();
            fgets(fornecedor.nome, sizeof(fornecedor.nome), stdin);
            fornecedor.nome[strcspn(fornecedor.nome, "\n")] = '\0';
            break;

        case '2':
            printf("\nInforme um novo CNPJ: \n");
            fgets(fornecedor.cnpj, sizeof(fornecedor.cnpj), stdin);
            fornecedor.cnpj[strcspn(fornecedor.cnpj, "\n")] = '\0';
            break;

        case '3':
            printf("\nInforme um novo Endereço: \n");
            fgets(fornecedor.endereco, sizeof(fornecedor.endereco), stdin);
            fornecedor.endereco[strcspn(fornecedor.endereco, "\n")] = '\0';
            break;

        case '4':
            printf("\nInforme um novo E-mail: \n");
            fgets(fornecedor.email, sizeof(fornecedor.email), stdin);
            fornecedor.email[strcspn(fornecedor.email, "\n")] = '\0';
            break;

        case '5':
            printf("\nInforme um novo Telefone: \n");
            fgets(fornecedor.telefone, sizeof(fornecedor.telefone), stdin);
            fornecedor.telefone[strcspn(fornecedor.telefone, "\n")] = '\0';
            break;

        default:
            printf("\nOpção inválida!\n");
            opcao = '0';
            break;
    }
}

cadastroConsumidor tela_cadastro_consumidor() //Tela de cadastro de consumidor - incompleto
{
    setlocale(LC_ALL, "Portuguese");
    cadastroConsumidor cadastro;

    printf("Nome: \n");
    limparBuffer();
    fgets(cadastro.nome, sizeof(cadastro.nome), stdin);
    cadastro.nome[strcspn(cadastro.nome, "\n")] = '\0';

    printf("CPF: \n");
    fgets(cadastro.cpf, sizeof(cadastro.cpf), stdin);
    cadastro.cpf[strcspn(cadastro.cpf, "\n")] = '\0';

    printf("Endereço: \n");
    fgets(cadastro.endereco, sizeof(cadastro.endereco), stdin);
    cadastro.endereco[strcspn(cadastro.endereco, "\n")] = '\0';

    printf("E-mail: \n");
    fgets(cadastro.email, sizeof(cadastro.email), stdin);
    cadastro.email[strcspn(cadastro.email, "\n")] = '\0';

    printf("Telefone: \n");
    fgets(cadastro.telefone, sizeof(cadastro.telefone), stdin);
    cadastro.telefone[strcspn(cadastro.telefone, "\n")] = '\0';

    system("cls");

    printf("-----------------------------------------------\n");
    printf("Deseja alterar alguma informação?(S/N)\n\n");
    printf("Nome: %s\nCPF: %s\nEndereço: %s\nE-mail: %s\nTelefone: %s\n\n",
           cadastro.nome, cadastro.cpf, cadastro.endereco, cadastro.email, cadastro.telefone);
    printf("-----------------------------------------------\n");

    return cadastro;
}

void alterar_campos_consumidor (char opcao, cadastroConsumidor consumidor) //Editar os campos de consumidor - incompleto
{

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char opcao;

    printf("-----------------------------------------------\n");
    printf("      Seja muito bem vindo ao DeliQuicker\n");
    printf("-----------------------------------------------\n");
    printf("\n            Nossa missão é simples:"
           "\n  Conectar quem tem alimentos excedentes com"
           "\n              quem mais precisa.\n"
           "\n   Aqui, restaurantes, mercados e pessoas podem"
           "\n     doar alimentos que não serão consumidos,"
           "\n    enquanto ONGs e indivíduos em situação de"
           "\n   vulnerabilidade encontram pontos de coletas"
           "\n      próximos com a ajuda do nosso sistema.\n\n");

    system("pause");
    system("cls");

    do
    {
        system("cls");

        printf("----------------------------------------------------------------\n");
        printf("                Selecione a opção desejada:\n");
        printf("\n 1- Cadastro Fornecedores       2- Cadastro Consumidores\n");
        printf("----------------------------------------------------------------\n");
        scanf("%s", & opcao);

        system("cls");

        switch (opcao)
        {
            case '1':
                tela_cadastro_fornecedor();
                break;

            case '2':
                tela_cadastro_consumidor();
                break;

            default:
                printf("\nOpcao inválida\n");
                opcao = '0';
                system("pause");
                break;
        }

    }while (opcao !='1' && opcao != '2');


}
