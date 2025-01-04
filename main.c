#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#define NUM_MAX_CAD 1024
#include<stdbool.h>

typedef struct // Cadastro fornecedor
{
    char nome[256];
    char cnpj[200];
    char endereco[256];
    char email[256];
    char telefone[200];
} cadastroFornecedor;

typedef struct // Cadastro consumidor
{
    char nome[256];
    char cpf[200];
    char endereco[256];
    char email[256];
    char telefone[200];
} cadastroConsumidor;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void salvar_cadastro_em_arquivo_fornecedor(cadastroFornecedor cadastro)// Função para salvar os dados do fornecedor em um arquivo
{
    FILE *arquivo = fopen("fornecedor.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }
    fprintf(arquivo, "%s\n%s\n%s\n%s\n%s\n", cadastro.nome, cadastro.cnpj, cadastro.endereco, cadastro.email, cadastro.telefone);
    fclose(arquivo);
}

void alterar_campos_fornecedor(char opcao, cadastroFornecedor *fornecedor) //Editar os campos de fornecedor
{
    switch(opcao)
    {
        case '1':
            printf("\nInforme um novo nome:\n");
            limparBuffer();
            fgets(fornecedor->nome, sizeof(fornecedor->nome), stdin);
            fornecedor->nome[strcspn(fornecedor->nome, "\n")] = '\0';
            break;

        case '2':
            printf("\nInforme um novo CNPJ: \n");
            limparBuffer();
            fgets(fornecedor->cnpj, sizeof(fornecedor->cnpj), stdin);
            fornecedor->cnpj[strcspn(fornecedor->cnpj, "\n")] = '\0';
            break;

        case '3':
            printf("\nInforme um novo Endereço: \n");
            limparBuffer();
            fgets(fornecedor->endereco, sizeof(fornecedor->endereco), stdin);
            fornecedor->endereco[strcspn(fornecedor->endereco, "\n")] = '\0';
            break;

        case '4':
            printf("\nInforme um novo E-mail: \n");
            limparBuffer();
            fgets(fornecedor->email, sizeof(fornecedor->email), stdin);
            fornecedor->email[strcspn(fornecedor->email, "\n")] = '\0';
            break;
        case '5':
            printf("\nInforme um novo Telefone: \n");
            limparBuffer();
            fgets(fornecedor->telefone, sizeof(fornecedor->telefone), stdin);
            fornecedor->telefone[strcspn(fornecedor->telefone, "\n")] = '\0';
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
    }
}

bool tela_cadastro_fornecedor()// Tela de cadastro fornecedor
{
    char alterar, salvar, sair, opcao;
    cadastroFornecedor cadastro;

    setlocale(LC_ALL, "Portuguese");

    printf("-----------------------------------------------------\n");
    printf("            Tela de Cadastro Fornecedor\n");
    printf("-----------------------------------------------------\n\n");

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

    printf("\n-----------------------------------------------------\n");

    do
    {
        system("pause");
        system("cls");

        printf("-----------------------------------------------------\n");
        printf("     Deseja alterar alguma informação?(S/N)\n");
        printf("-----------------------------------------------------\n\n");
        printf("Nome: %s\nCNPJ: %s\nEndereço: %s\nE-mail: %s\nTelefone: %s\n\n",
               cadastro.nome, cadastro.cnpj, cadastro.endereco, cadastro.email, cadastro.telefone);
        printf("-----------------------------------------------------\n");
        scanf(" %c", &alterar);

        if(alterar == 'n' || alterar == 'N')
        {
            do
            {
                printf("-----------------------------------------------------\n");
                printf("Deseja salvar as informações? (S/N)\n");
                printf("-----------------------------------------------------\n");
                scanf(" %c", &salvar);

                if (salvar == 's' || salvar == 'S')
                {
                    system("cls");
                    printf("---------------------------\n");
                    printf("Cadastro salvo com sucesso!\n");
                    printf("---------------------------\n");
                    salvar_cadastro_em_arquivo_fornecedor(cadastro);

                    system("pause");
                    system("cls");
                    tela_usuario_fornecedor();
                    return true;
                }
                else if (salvar != 's' && salvar != 'S' && salvar != 'n' && salvar != 'N')
                {
                    printf("\nOpção inválida!\nEscolha novamente\n\n");
                    continue;
                }

                break;

            }while(salvar != 'n' || salvar != 'N');
        }

        else if (alterar == 's' || alterar == 'S')
        {
            do
            {
                limparBuffer();

                printf("-----------------------------------------------------\n");
                printf("Selecione a opção que deseja alterar:\n");
                printf("-----------------------------------------------------\n");
                printf("1- Nome\n");
                printf("2- CNPJ\n");
                printf("3- Endereço\n");
                printf("4- E-mail\n");
                printf("5- Telefone\n");
                printf("6- Finalizar edição\n");
                scanf(" %c", &opcao);

                if (opcao == '6')
                {
                    break;
                }
                else
                {
                    alterar_campos_fornecedor(opcao, &cadastro);
                }

            } while(opcao != '6');

            do
            {
                printf("-----------------------------------------------------\n");
                printf("Deseja salvar as informações? (S/N)\n");
                printf("-----------------------------------------------------\n");
                scanf(" %c", &salvar);

                if (salvar == 's' || salvar == 'S')
                {
                    system("cls");
                    printf("---------------------------\n");
                    printf("Cadastro salvo com sucesso!\n");
                    printf("---------------------------\n");
                    salvar_cadastro_em_arquivo_fornecedor(cadastro);

                    system("pause");
                    system("cls");
                    tela_usuario_fornecedor();
                    return true;
                }
                else if (salvar != 's' && salvar != 'S' && salvar != 'n' && salvar != 'N')
                {
                    printf("\nOpção inválida!\nEscolha novamente\n\n");
                    continue;
                }

                break;

            }while(salvar != 'n' || salvar != 'N');

        }
        else if (alterar != 's' && alterar != 'S' && alterar != 'n' && alterar != 'N')
        {
            printf("\nOpção inválida!\nEscolha novamente\n\n");
            continue;
        }

        do
        {
            printf("-----------------------------------------------------\n");
            printf("Deseja sair do cadastro?(S/N)\n");
            printf("-----------------------------------------------------\n");
            scanf(" %c", &sair);

            if(sair == 's' || sair == 'S')
            {
                system("cls");
                printf("------------------------\n");
                printf("Retornando ao inicio...\n");
                printf("------------------------\n\n");
                system("pause");
                system("cls");
                main();
                break;
            }
            else if (sair != 's' && sair != 'S' && sair != 'n' && sair != 'N')
            {
                printf("\nOpção inválida!\nEscolha novamente\n\n");
                continue;
            }
            system("cls");

            break;

        }while(sair != 'n' || sair != 'N');

    } while(alterar != 's' || alterar != 'S');
}

void salvar_cadastro_em_arquivo_consumidor(cadastroConsumidor cadastro)// Função para salvar os dados do consumidor em um arquivo
{
    FILE *arquivo = fopen("consumidor.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }
    fprintf(arquivo, "%s\n%s\n%s\n%s\n%s\n", cadastro.nome, cadastro.cpf, cadastro.endereco, cadastro.email, cadastro.telefone);
    fclose(arquivo);
}

bool tela_cadastro_consumidor() //Tela de cadastro de consumidor
{
    char alterar, salvar, sair, opcao;

    setlocale(LC_ALL, "Portuguese");
    cadastroConsumidor cadastro;

    printf("-----------------------------------------------------\n");
    printf("            Tela de Cadastro Consumidor\n");
    printf("-----------------------------------------------------\n\n");

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

    printf("-----------------------------------------------------\n");

    do
    {
        system("pause");
        system("cls");

        printf("-----------------------------------------------------\n");
        printf("     Deseja alterar alguma informação?(S/N)\n");
        printf("-----------------------------------------------------\n\n");
        printf("Nome: %s\nCPF: %s\nEndereço: %s\nE-mail: %s\nTelefone: %s\n\n",
               cadastro.nome, cadastro.cpf, cadastro.endereco, cadastro.email, cadastro.telefone);
        printf("-----------------------------------------------------\n");
        scanf(" %c", &alterar);

        if(alterar == 'n' || alterar == 'N')
        {
            do
            {
                printf("-----------------------------------------------------\n");
                printf("Deseja salvar as informações? (S/N)\n");
                printf("-----------------------------------------------------\n");
                scanf(" %c", &salvar);

                if (salvar == 's' || salvar == 'S')
                {
                    system("cls");
                    printf("---------------------------\n");
                    printf("Cadastro salvo com sucesso!\n");
                    printf("---------------------------\n");
                    salvar_cadastro_em_arquivo_consumidor(cadastro);

                    system("pause");
                    system("cls");
                    tela_usuario_consumidor();
                    return true;
                }
                else if (salvar != 's' && salvar != 'S' && salvar != 'n' && salvar != 'N')
                {
                    printf("\nOpção inválida!\nEscolha novamente\n\n");
                    continue;
                }

                break;

            }while(salvar != 'n' || salvar != 'N');
        }

        else if (alterar == 's' || alterar == 'S')
        {
            do
            {
                limparBuffer();

                printf("-----------------------------------------------------\n");
                printf("Selecione a opção que deseja alterar:\n");
                printf("-----------------------------------------------------\n");
                printf("1- Nome\n");
                printf("2- CPF\n");
                printf("3- Endereço\n");
                printf("4- E-mail\n");
                printf("5- Telefone\n");
                printf("6- Finalizar edição\n");
                scanf(" %c", &opcao);

                if (opcao == '6')
                {
                    break;
                }
                else
                {
                    alterar_campos_consumidor(opcao, &cadastro);
                }

            } while(opcao != '6');

            do
            {
                printf("-----------------------------------------------------\n");
                printf("Deseja salvar as informações? (S/N)\n");
                printf("-----------------------------------------------------\n");
                scanf(" %c", &salvar);

                if (salvar == 's' || salvar == 'S')
                {
                    system("cls");
                    printf("---------------------------\n");
                    printf("Cadastro salvo com sucesso!\n");
                    printf("---------------------------\n");
                    salvar_cadastro_em_arquivo_consumidor(cadastro);

                    system("pause");
                    system("cls");
                    tela_usuario_consumidor();
                    return true;
                }
                else if (salvar != 's' && salvar != 'S' && salvar != 'n' && salvar != 'N')
                {
                    printf("\nOpção inválida!\nEscolha novamente\n\n");
                    continue;
                }

                break;

            }while(salvar != 'n' || salvar != 'N');

        }
        else if (alterar != 's' && alterar != 'S' && alterar != 'n' && alterar != 'N')
        {
            printf("\nOpção inválida!\nEscolha novamente\n\n");
            continue;
        }

        do
        {
            printf("-----------------------------------------------------\n");
            printf("Deseja sair do cadastro?(S/N)\n");
            printf("-----------------------------------------------------\n");
            scanf(" %c", &sair);

            if(sair == 's' || sair == 'S')
            {
                system("cls");
                printf("------------------------\n");
                printf("Retornando ao inicio...\n");
                printf("------------------------\n\n");
                system("pause");
                system("cls");
                main();
                break;
            }
            else if (sair != 's' && sair != 'S' && sair != 'n' && sair != 'N')
            {
                printf("\nOpção inválida!\nEscolha novamente\n\n");
                continue;
            }
            system("cls");

            break;

        }while(sair != 'n' || sair != 'N');

    }while(alterar != 's' || alterar == 'S');

    return false;
}

void alterar_campos_consumidor (char opcao, cadastroConsumidor consumidor) //Editar os campos de consumidor
{
    switch(opcao)
    {
        case '1':
            printf("\nInforme um novo nome:\n");
            limparBuffer();
            fgets(consumidor.nome, sizeof(consumidor.nome), stdin);
            consumidor.nome[strcspn(consumidor.nome, "\n")] = '\0';
            break;

        case '2':
            printf("\nInforme um novo CPF: \n");
            limparBuffer();
            fgets(consumidor.cpf, sizeof(consumidor.cpf), stdin);
            consumidor.cpf[strcspn(consumidor.cpf, "\n")] = '\0';
            break;

        case '3':
            printf("\nInforme um novo Endereço: \n");
            limparBuffer();
            fgets(consumidor.endereco, sizeof(consumidor.endereco), stdin);
            consumidor.endereco[strcspn(consumidor.endereco, "\n")] = '\0';
            break;

        case '4':
            printf("\nInforme um novo E-mail: \n");
            limparBuffer();
            fgets(consumidor.email, sizeof(consumidor.email), stdin);
            consumidor.email[strcspn(consumidor.email, "\n")] = '\0';
            break;

        case '5':
            printf("\nInforme um novo Telefone: \n");
            limparBuffer();
            fgets(consumidor.telefone, sizeof(consumidor.telefone), stdin);
            consumidor.telefone[strcspn(consumidor.telefone, "\n")] = '\0';
            break;

        default:
            printf("\nOpção inválida!\n");
            opcao = '0';
            break;
    }
}

bool carregar_dados_do_arquivo_fornecedor(cadastroFornecedor *cadastro) //Buscar dados do fornecedor
{
    FILE *arquivo = fopen("fornecedor.txt", "r");
    if (arquivo == NULL)
    {
        return false;
    }
    fgets(cadastro->nome, sizeof(cadastro->nome), arquivo);
    cadastro->nome[strcspn(cadastro->nome, "\n")] = '\0';

    fgets(cadastro->cnpj, sizeof(cadastro->cnpj), arquivo);
    cadastro->cnpj[strcspn(cadastro->cnpj, "\n")] = '\0';

    fgets(cadastro->endereco, sizeof(cadastro->endereco), arquivo);
    cadastro->endereco[strcspn(cadastro->endereco, "\n")] = '\0';

    fgets(cadastro->email, sizeof(cadastro->email), arquivo);
    cadastro->email[strcspn(cadastro->email, "\n")] = '\0';

    fgets(cadastro->telefone, sizeof(cadastro->telefone), arquivo);
    cadastro->telefone[strcspn(cadastro->telefone, "\n")] = '\0';

    fclose(arquivo);
    return true;
}

bool carregar_dados_do_arquivo_consumidor(cadastroConsumidor *cadastro) //Buscar dados do consumidor
{
    FILE *arquivo = fopen("consumidor.txt", "r");
    if (arquivo == NULL)
    {
        return false;
    }
    fgets(cadastro->nome, sizeof(cadastro->nome), arquivo);
    cadastro->nome[strcspn(cadastro->nome, "\n")] = '\0';

    fgets(cadastro->cpf, sizeof(cadastro->cpf), arquivo);
    cadastro->cpf[strcspn(cadastro->cpf, "\n")] = '\0';

    fgets(cadastro->endereco, sizeof(cadastro->endereco), arquivo);
    cadastro->endereco[strcspn(cadastro->endereco, "\n")] = '\0';

    fgets(cadastro->email, sizeof(cadastro->email), arquivo);
    cadastro->email[strcspn(cadastro->email, "\n")] = '\0';

    fgets(cadastro->telefone, sizeof(cadastro->telefone), arquivo);
    cadastro->telefone[strcspn(cadastro->telefone, "\n")] = '\0';

    fclose(arquivo);
    return true;
}

void tela_usuario_fornecedor() //Tela de usuário fornecedor
{
    char opcao, sair;

    setlocale(LC_ALL, "Portuguese");
    cadastroFornecedor cadastro;

    do
    {
        system("cls");
        limparBuffer();

        printf("---------------------------------------------------------------------------------\n");
        printf("                     Seja muito bem vindo ao DeliQuicker\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("           Agradecemos a iniciativa de tornar o mundo um lugar melhor!\n\n");
        printf("1- Usuário           2- Nossa História           3- Contato           4- Sair\n");
        scanf(" %c", &opcao);

        switch(opcao)
        {
            case '1':
                system("cls");
                printf("-----------------------------------------------------\n");
                printf("                Perfil do Usuário\n");
                printf("-----------------------------------------------------\n");

                if (!carregar_dados_do_arquivo_fornecedor(&cadastro))
                {
                    printf("Cadastro não localizado, favor entrar em contato!\n");
                }
                else
                {
                    printf("Nome: %s\nCNPJ: %s\nEndereço: %s\nE-mail: %s\nTelefone: %s\n",
                    cadastro.nome, cadastro.cnpj, cadastro.endereco, cadastro.email, cadastro.telefone);
                }
                printf("-----------------------------------------------------\n");
                printf("                    DELIQUICKER\n");
                printf("-----------------------------------------------------\n");
                system("pause");
                break;

            case '2':
                system("cls");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                           Nossa História\n");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("               De acordo com dados da Organização das Nações Unidas para Agricultura e Alimentação (FAO), cerca de\n\n"
                       "               1,3 bilhão de toneladas de alimentos são desperdiçadas anualmente em todo o mundo — o suficiente para\n"
                       "              alimentar mais de 3 bilhões de pessoas. Este desperdício ocorre em todos os níveis da cadeia de produção,\n"
                       "            desde a agricultura até os consumidores finais. No Brasil, estima-se que 26 milhões de toneladas de alimentos\n"
                       "                      são descartadas anualmente, enquanto cerca de 33 milhões de pessoas convivem com a fome.\n\n"

                       "           Foi a partir desse cenário alarmante que decidimos agir. Em um dia comum, ao presenciar o descarte de alimentos\n"
                       "           ainda frescos em um restaurante local, algo dentro de nós despertou. Como era possível que tanto alimento fosse\n"
                       "                        jogado fora, enquanto tantas pessoas ao nosso redor sofriam com a falta de comida?\n\n"

                       "          Nossa missão ficou clara: conectar o que é desperdiçado com quem mais precisa. Criamos uma plataforma digital simples\n"
                       "            e acessível, com o objetivo de facilitar a doação de alimentos excedentes. A ideia era que restaurantes, mercados,\n"
                       "                produtores e até mesmo pessoas com alimentos sobrando pudessem, com facilidade, contribuir para a causa.\n\n"

                       "        O aplicativo nasceu com a intenção de ser uma ponte, um facilitador que conectasse aqueles que podiam doar com aqueles\n"
                       "     que necessitavam. O sistema mapeia pontos de coleta e entrega, permitindo que ONGs e indivíduos em situação de vulnerabilidade\n"
                       "                         possam encontrar com facilidade locais próximos onde os alimentos estão disponíveis.\n\n"

                       "     Embora os números ainda sejam alarmantes, sabemos que cada refeição doada é um passo a mais em direção a um mundo mais justo.\n"
                       "       Acreditamos que, com a colaboração de todos, podemos diminuir os índices de desperdício e fome no Brasil, construindo um\n"
                       "                       futuro em que o excedente alimentício se transforme em uma oportunidade de solidariedade.\n\n"

                       "   Em um país onde, segundo a Pesquisa de Orçamentos Familiares (POF), 10% da população sofre com a insegurança alimentar grave,\n"
                       "                      cada ação conta. E, juntos, podemos mudar essa realidade, um prato de comida por vez.\n");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                              DELIQUICKER\n");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                system("pause");
                break;

            case '3':
                system("cls");
                printf("-----------------------------------------------\n");
                printf("                   Contato\n");
                printf("-----------------------------------------------\n");
                printf("Isabella Braga\nTelefone: (19)98860-4616\nE-mail: i.braga@aluno.ifsp.edu.br\n\n");
                printf("Julia Steiner\nTelefone: (11)98601-4592\nE-mail: julia.steiner@aluno.ifsp.edu.br\n\n");
                printf("Rafaela Brasil\nTelefone: (19)98305-9064\nE-mail: rafaela.brasil@aluno.ifsp.edu.br\n\n");
                printf("-----------------------------------------------\n");
                printf("                  DELIQUICKER\n");
                printf("-----------------------------------------------\n\n\n");
                system("pause");
                break;

            case '4':
                system("cls");
                printf("\n\nFinalizando o programa...\n\n");
                printf("-----------------------------\n");
                printf("        DELIQUICKER\n");
                printf("-----------------------------\n\n\n");
                break;
        }
    }while(opcao != '4');
}

void tela_usuario_consumidor() //Tela de usuário consumidor
{
    char opcao, sair;

    setlocale(LC_ALL, "Portuguese");
    cadastroConsumidor cadastro;

    do
    {
        system("cls");
        limparBuffer();

        printf("---------------------------------------------------------------------------------\n");
        printf("                     Seja muito bem vindo ao DeliQuicker\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("           Agradecemos a iniciativa de tornar o mundo um lugar melhor!\n\n");
        printf("1- Usuário           2- Nossa História           3- Contato           4- Sair\n");
        scanf(" %c", &opcao);

        switch(opcao)
        {
            case '1':
                system("cls");
                printf("-----------------------------------------------------\n");
                printf("                Perfil do Usuário\n");
                printf("-----------------------------------------------------\n");

                if (!carregar_dados_do_arquivo_consumidor(&cadastro))
                {
                    printf("Cadastro não localizado, favor entrar em contato!\n");
                }
                else
                {
                    printf("Nome: %s\nCNPJ: %s\nEndereço: %s\nE-mail: %s\nTelefone: %s\n",
                    cadastro.nome, cadastro.cpf, cadastro.endereco, cadastro.email, cadastro.telefone);
                }
                printf("-----------------------------------------------------\n");
                printf("                    DELIQUICKER\n");
                printf("-----------------------------------------------------\n");
                system("pause");
                break;

            case '2':
                system("cls");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                           Nossa História\n");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("               De acordo com dados da Organização das Nações Unidas para Agricultura e Alimentação (FAO), cerca de\n\n"
                       "               1,3 bilhão de toneladas de alimentos são desperdiçadas anualmente em todo o mundo — o suficiente para\n"
                       "              alimentar mais de 3 bilhões de pessoas. Este desperdício ocorre em todos os níveis da cadeia de produção,\n"
                       "            desde a agricultura até os consumidores finais. No Brasil, estima-se que 26 milhões de toneladas de alimentos\n"
                       "                      são descartadas anualmente, enquanto cerca de 33 milhões de pessoas convivem com a fome.\n\n"

                       "           Foi a partir desse cenário alarmante que decidimos agir. Em um dia comum, ao presenciar o descarte de alimentos\n"
                       "           ainda frescos em um restaurante local, algo dentro de nós despertou. Como era possível que tanto alimento fosse\n"
                       "                        jogado fora, enquanto tantas pessoas ao nosso redor sofriam com a falta de comida?\n\n"

                       "          Nossa missão ficou clara: conectar o que é desperdiçado com quem mais precisa. Criamos uma plataforma digital simples\n"
                       "            e acessível, com o objetivo de facilitar a doação de alimentos excedentes. A ideia era que restaurantes, mercados,\n"
                       "                produtores e até mesmo pessoas com alimentos sobrando pudessem, com facilidade, contribuir para a causa.\n\n"

                       "        O aplicativo nasceu com a intenção de ser uma ponte, um facilitador que conectasse aqueles que podiam doar com aqueles\n"
                       "     que necessitavam. O sistema mapeia pontos de coleta e entrega, permitindo que ONGs e indivíduos em situação de vulnerabilidade\n"
                       "                         possam encontrar com facilidade locais próximos onde os alimentos estão disponíveis.\n\n"

                       "     Embora os números ainda sejam alarmantes, sabemos que cada refeição doada é um passo a mais em direção a um mundo mais justo.\n"
                       "       Acreditamos que, com a colaboração de todos, podemos diminuir os índices de desperdício e fome no Brasil, construindo um\n"
                       "                       futuro em que o excedente alimentício se transforme em uma oportunidade de solidariedade.\n\n"

                       "   Em um país onde, segundo a Pesquisa de Orçamentos Familiares (POF), 10% da população sofre com a insegurança alimentar grave,\n"
                       "                      cada ação conta. E, juntos, podemos mudar essa realidade, um prato de comida por vez.\n");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                              DELIQUICKER\n");
                printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                system("pause");
                break;

            case '3':
                system("cls");
                printf("-----------------------------------------------\n");
                printf("                   Contato\n");
                printf("-----------------------------------------------\n");
                printf("Isabella Braga\nTelefone: (19)98860-4616\nE-mail: i.braga@aluno.ifsp.edu.br\n\n");
                printf("Julia Steiner\nTelefone: (11)98601-4592\nE-mail: julia.steiner@aluno.ifsp.edu.br\n\n");
                printf("Rafaela Brasil\nTelefone: (19)98305-9064\nE-mail: rafaela.brasil@aluno.ifsp.edu.br\n\n");
                printf("-----------------------------------------------\n");
                printf("                  DELIQUICKER\n");
                printf("-----------------------------------------------\n\n\n");
                system("pause");
                break;

            case '4':
                system("cls");
                printf("\n\nFinalizando o programa...\n\n");
                printf("-----------------------------\n");
                printf("        DELIQUICKER\n");
                printf("-----------------------------\n\n\n");
                break;
        }
    }while(opcao != '4');
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char opcao;

    printf("--------------------------------------------------\n");
    printf("       Seja muito bem vindo ao DeliQuicker\n");
    printf("--------------------------------------------------\n");
    printf("\n            Nossa missão é simples:"
           "\n  Conectar quem tem alimentos excedentes com"
           "\n              quem mais precisa.\n"
           "\n   Aqui, restaurantes, mercados e pessoas podem"
           "\n     doar alimentos que não serão consumidos,"
           "\n    enquanto ONGs e indivíduos em situação de"
           "\n   vulnerabilidade encontram pontos de coletas"
           "\n      próximos com a ajuda do nosso sistema.\n\n");

    printf("--------------------------------------------------\n\n");

    system("pause");
    system("cls");

    do
    {
        system("cls");

        printf("----------------------------------------------------------------\n");
        printf("                Selecione a opção desejada:\n");
        printf("\n 1- Cadastro Fornecedores       2- Cadastro Consumidores\n\n");
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
