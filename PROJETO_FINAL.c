                             //PROJETO FINAL L�GICA DA PROGRAMA��O
                             //INTEGRANTES: VITOR MANUEL P. DOS SANTOS
                                          //JOICE CLARA SOUZA DA SILVA
                                          //INSIRA AQUI SEU NOME
                                          //INSIRA AQUI SEU NOME
                                          //INSIRA AQUI SEU NOME
//Data: 17/06/2023 adicionadas as fun��es de leitura do nome da seguradora e dados da corretora 
//Data: 18/06/2023 feitas altera��es nas fun��es para funcionar corretamente e adicionado a fun��o para os dados do proponente

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_AGE 100 //n�mero m�ximo de agendamentos - Linhas da matriz
#define MAX_DADOS_AGEN 4

typedef struct{
    
    char seguradora[20];
    //Dados do corretor

    char motivoVist[20];
    char periodo[20];
    int dia, mes, ano;

    long long int dadosCorretora[MAX_AGE][MAX_DADOS_AGEN]; //N�mero SUSEP Corretora e Telefones 
    char nomeCorretora[50];
    //Dados do proponente //Apatir de pesquisas descobri que int n armazena mais 10 e por isso o uso do long long

    char nomeProponente[50];
    long long int dadosProponente[MAX_AGE][MAX_DADOS_AGEN]; //CPF e telefones do proponente  
    //Dados do ve�culo

    char modeloVeic[50], 
    placaVeic[8], 
    chassis[17]; //toda placa tem 7 caracteres e todo chassis de veiculos apartir de 81 tem 17 
    long long int anoVeic[MAX_AGE][2]; //ano de fabrica��o e ano do modelo

    char observacoes[300];

} Agendamento;

FILE* arquivo;

void exibirMenu() {
    printf("\n--- Vistoria Prévia ---\n");
    printf("\n--- Agendamento ---\n");
    printf("1. Cadastrar agendamento\n");
    printf("2. Pesquisar agendamento\n");
    printf("3. Listar Agendamentos\n");
    printf("4. Gerar arquivo de agendamentos\n");
    printf("5. Ler arquivo de agendamentos\n");
    printf("6. Sair\n");
}

void agendar(Agendamento* agendamento)
{
    printf("\n-----------SEGURADORA-----------\n"); //Este switch case serve para o usu�rio escolher qual seguradora �
    printf("Para qual a seguradora o servi�o ser� prestado?\n");
    printf("1. Tokio Marine\n");
    printf("2. HDI Seguros\n");
    printf("3. Allianz\n");
    printf("4. Mapfre\n");
    printf("5. BB Seguros - Banco do Brasil\n");
    printf("6. Porto Seguro\n");
    printf("7. Liberty Seguros\n");
    int escolha;
    printf("Digite aqui: ");
    scanf("%d", &escolha);
    setbuf(stdin, NULL);
    switch (escolha)
    {
    case 1:
      strcpy(agendamento->seguradora, "Tokio Marine"); //dessa forma, ao escolher, com a fun��o strcpy a seguradora escolhida ser� armazenada na variavel seguradora
      break;
    case 2:
      strcpy(agendamento->seguradora, "HDI Seguros");
      break;
    case 3:
      strcpy(agendamento->seguradora, "Allianz");
      break;
    case 4:
      strcpy(agendamento->seguradora, "Mapfre");
      break;
    case 5:
      strcpy(agendamento->seguradora, "BB Seguros - Banco do Brasil");
      break;
    case 6:
      strcpy(agendamento->seguradora, "Porto Seguro");
      break;
    case 7:
      strcpy(agendamento->seguradora, "Liberty Seguros");
      break;
        
    default:
      break;
    }
    system("cls");
    printf("\n-----------Motivo da vistoria-----------\n"); 
    printf("1. Seguro Novo\n");
    printf("2. Renova��o\n");
    int mot;
    printf("Digite aqui: ");
    scanf("%d", &mot);
    setbuf(stdin, NULL);
    switch (mot)
    {
    case 1:
      strcpy(agendamento->motivoVist, "SEGURO NOVO");
      break;
    case 2:
      strcpy(agendamento->motivoVist, "Renova��o");
      break;
        
    default:
      break;
    }
    system("cls");
    system("cls");
    printf("\n-----------Per�odo-----------\n"); 
    printf("1. Comercial (8:00 as 18:00)\n");
    printf("2. Manh�(8:00 as 12:00)\n");
    printf("3. Tarde(13:00 as 18:00)\n");
    int per;
    printf("Digite aqui: ");
    scanf("%d", &per);
    setbuf(stdin, NULL);
    switch (per)
    {
    case 1:
      strcpy(agendamento->periodo, "Comercial");
      break;
    case 2:
      strcpy(agendamento->periodo, "Manha");
      break;
    case 3:
      strcpy(agendamento->periodo, "Tarde");
      break;        
    default:
      break;
    }
    system("cls");
printf("\nQual a data do agendamento?\n");
printf("Ano: ");
scanf("%d", &agendamento->ano);
setbuf(stdin, NULL);
printf("\n");
printf("M�s: "); 
scanf("%d", &agendamento->mes);
setbuf(stdin, NULL);
printf("\n");
printf("Dia: "); 
scanf("%d", &agendamento->dia); 
setbuf(stdin, NULL);
system("cls");          

printf("\n-----DADOS DA CORRETORA-------\n");
printf("\nNome da Corretora: ");
scanf(" %[^\n]s", agendamento->nomeCorretora); //padr�o para leitura de strings, nesse caso � o nome da corretora mas pode ser adaptada pra qualquer informa��o dada a variavel especifica
setbuf(stdin, NULL); 

printf("\tDigite o c�digo SUSEP: ");
scanf("%lld", &agendamento->dadosCorretora[0][0]); //O c�digo SUSEP ser� sempre armazenado na linha 0 coluna 0 
setbuf(stdin, NULL);

for (int i = 1; i < MAX_DADOS_AGEN; i++) 
  {
    printf("Telefone para contato %d:\n", i);
    printf("\tTelefone: ");
    scanf("%lld", &agendamento->dadosCorretora[i][0]); //na matriz dados, os telefones est�o limitados 3 
    setbuf(stdin, NULL);

    printf("Deseja adicionar outro n�mero para contato? (S/N): ");
    char opcao;
    scanf("%c", &opcao);
    setbuf(stdin, NULL);

    if (opcao == 'N' || opcao == 'n') 
    {
      break;
    }
  }  
system("cls");
printf("\n-----DADOS DO PROPONENTE-------\n");
printf("\nNome do Proponente: ");
scanf(" %[^\n]s", agendamento->nomeProponente);
setbuf(stdin, NULL);

printf("\tDigite o CPF ou CNPJ do proponente: ");
scanf("%lld", &agendamento->dadosProponente[0][0]);
setbuf(stdin, NULL);

for (int i = 1; i < MAX_DADOS_AGEN; i++) 
  {
    printf("Telefone para contato %d:\n", i);
    printf("\tTelefone: ");
    scanf("%lld", &agendamento->dadosProponente[i][0]);
    setbuf(stdin, NULL);

    printf("Deseja adicionar outro n�mero para contato? (S/N): ");
    char opcao;
    scanf("%c", &opcao);
    setbuf(stdin, NULL);

    if (opcao == 'N' || opcao == 'n') 
    {
      break;
    }
  }
system("cls");
printf("\n-----DADOS DO VE�CULO-------\n");
printf("\nModelo do Ve�culo: ");
scanf(" %[^\n]s", agendamento->modeloVeic);
setbuf(stdin, NULL);

printf("\nDigite a placa do ve�culo: ");
scanf(" %[^\n]s", agendamento->placaVeic);
setbuf(stdin, NULL);

printf("\nChassis do ve�culo(At� 17 caracteres): ");
scanf(" %[^\n]s", agendamento->chassis);
setbuf(stdin, NULL);

printf("\nAno de Fabrica��o: ");
scanf("%lld", &agendamento->anoVeic[0][0]);

printf("\nAno do Modelo: ");
scanf("%lld", &agendamento->anoVeic[0][1]);


system("cls");
printf("Alguma observa��o(S/N)? ");
    char opcao;
    scanf("%c", &opcao);
    setbuf(stdin, NULL);

    if (opcao == 'S' || opcao == 's') 
    {
          printf("\nObserva��es(300 caracteres): ");
      scanf(" %[^\n]s", agendamento->observacoes);
      setbuf(stdin, NULL);
    }    
}

void gerarArquivoAgendamentos(Agendamento* agendamento, int qtdAgendamentos) {
    arquivo = fopen("Agendamentos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    for (int i = 0; i < qtdAgendamentos; i++) {
        fprintf(arquivo, "=============================================================\n");
        fprintf(arquivo, "                       AGENDAMENTO %d\n", i + 1);
        fprintf(arquivo, "=============================================================\n\n");
        fprintf(arquivo, "Seguradora: %s\n", agendamento[i].seguradora);
        fprintf(arquivo, "Motivo da Vistoria: %s\n", agendamento[i].motivoVist);
        fprintf(arquivo, "Data: %d/%d/%d", agendamento[i].dia,agendamento[i].mes,agendamento[i].ano);
        fprintf(arquivo, "- %s\n", agendamento[i].periodo);
        fprintf(arquivo, "=============================================================\n");
        fprintf(arquivo, "                       CORRETORA\n");
        fprintf(arquivo, "=============================================================\n\n");
        fprintf(arquivo, "Corretora: %s\n", agendamento[i].nomeCorretora);
        fprintf(arquivo, "SUSEP: %lld\n", agendamento[i].dadosCorretora[0][0]);

        for (int j = 1; j < MAX_DADOS_AGEN; j++) {
            if (agendamento[i].dadosCorretora[j][0] != 0) {
                fprintf(arquivo, "Dados de contato %d:\n", j);
                fprintf(arquivo, "\tTelefone: %lld\n", agendamento[i].dadosCorretora[j][0]);
            }
        }
        fprintf(arquivo, "=============================================================\n");
        fprintf(arquivo, "                       PROPONENTE\n");
        fprintf(arquivo, "=============================================================\n\n");
        fprintf(arquivo, "Nome: %s\n", agendamento[i].nomeProponente);
        fprintf(arquivo, "CPF/CNPJ: %lld\n", agendamento[i].dadosProponente[0][0]);        
        for (int j = 1; j < MAX_DADOS_AGEN; j++) {
            if (agendamento[i].dadosProponente[j][0] != 0) {
                fprintf(arquivo, "Dados de contato %d:\n", j);
                fprintf(arquivo, "\tTelefone: %lld\n", agendamento[i].dadosProponente[j][0]);
            }
        }

        fprintf(arquivo, "=============================================================\n");
        fprintf(arquivo, "                       DADOS DO VE�CULO\n");
        fprintf(arquivo, "=============================================================\n\n");
        fprintf(arquivo, "%s\n", agendamento[i].modeloVeic);
        fprintf(arquivo, "Placa: %s - ", agendamento[i].placaVeic);
        fprintf(arquivo, "Ano/Modelo: %lld/", agendamento[i].anoVeic[0][0]);
        fprintf(arquivo, "%lld\n", agendamento[i].anoVeic[0][1]);       
        fprintf(arquivo, "Chassis: %s\n", agendamento[i].chassis);
        fprintf(arquivo,"\n");

        fprintf(arquivo, "=============================================================\n");
        fprintf(arquivo, "                       OBSERVA��ES\n");
        fprintf(arquivo, "=============================================================\n\n");
        fprintf(arquivo, "%s\n", agendamento[i].observacoes);
    }



    fclose(arquivo);
    printf("Arquivo 'Agendamentos.txt' gerado com sucesso.\n");
}

int carregarAgendamentos(Agendamento* agendamentos) {
    arquivo = fopen("Agendamentos.txt", "r");
    if (arquivo == NULL) {
        return 0; // Arquivo n�o encontrado
    }

    int quantidade = 0;

    while (!feof(arquivo) && quantidade < MAX_AGE) {
        fscanf(arquivo, "=============================================================\n");
        fscanf(arquivo, "                       AGENDAMENTO %*d\n"); // L� e descarta o n�mero do agendamento
        fscanf(arquivo, "=============================================================\n\n");
        fscanf(arquivo, "Seguradora: %[^\n]\n", agendamentos[quantidade].seguradora);
        fscanf(arquivo, "Motivo da Vistoria: %[^\n]\n", agendamentos[quantidade].motivoVist);
        fscanf(arquivo, "Data: %d/%d/%d %[^\n]\n", &agendamentos[quantidade].dia, &agendamentos[quantidade].mes, &agendamentos[quantidade].ano, agendamentos[quantidade].periodo);
        fscanf(arquivo, "=============================================================\n");
        fscanf(arquivo, "                       CORRETORA\n");
        fscanf(arquivo, "=============================================================\n\n");
        fscanf(arquivo, "Corretora: %[^\n]\n", agendamentos[quantidade].nomeCorretora);
        fscanf(arquivo, "SUSEP: %lld\n", &agendamentos[quantidade].dadosCorretora[0][0]);

        for (int j = 1; j < MAX_DADOS_AGEN; j++) {
            if (fscanf(arquivo, "Dados de contato %*d:\n\tTelefone: %lld\n", &agendamentos[quantidade].dadosCorretora[j][0]) != 1) {
                agendamentos[quantidade].dadosCorretora[j][0] = 0;
            }
        }

        fscanf(arquivo, "=============================================================\n");
        fscanf(arquivo, "                       PROPONENTE\n");
        fscanf(arquivo, "=============================================================\n\n");
        fscanf(arquivo, "Nome: %[^\n]\n", agendamentos[quantidade].nomeProponente);
        fscanf(arquivo, "CPF/CNPJ: %lld\n", &agendamentos[quantidade].dadosProponente[0][0]);

        for (int j = 1; j < MAX_DADOS_AGEN; j++) {
            if (fscanf(arquivo, "Dados de contato %*d:\n\tTelefone: %lld\n", &agendamentos[quantidade].dadosProponente[j][0]) != 1) {
                agendamentos[quantidade].dadosProponente[j][0] = 0;
            }
        }

        fscanf(arquivo, "=============================================================\n");
        fscanf(arquivo, "                       DADOS DO VE�CULO\n");
        fscanf(arquivo, "=============================================================\n\n");
        fscanf(arquivo, "%[^\n]\n", agendamentos[quantidade].modeloVeic);
        fscanf(arquivo, "Ano/Modelo: %lld/%lld\n", &agendamentos[quantidade].anoVeic[0][0],&agendamentos[quantidade].anoVeic[0][1]);
        fscanf(arquivo, "%[^\n]\n", agendamentos[quantidade].chassis);
        fscanf(arquivo, "=============================================================\n");
        fscanf(arquivo, "                       OBSERVAC�ES\n");
        fscanf(arquivo, "=============================================================\n\n");
        fscanf(arquivo, "%*[^\n]\n", agendamentos[quantidade].observacoes);

        quantidade++;
    }

    fclose(arquivo);
    return quantidade;
}

Agendamento* pesquisarAgendamento(Agendamento* agendamento, int qtdAgendamentos , char* placaPesquisa) {
    for (int i = 0; i < qtdAgendamentos; i++) {
        if (strcmp(agendamento[i].placaVeic, placaPesquisa) == 0) {
            printf("\nAgendamento encontrado:\n");

            printf("Seguradora: %s\n", agendamento[i].seguradora);
            printf("Motivo da Vistoria: %s\n", agendamento[i].motivoVist);
            printf("Data: %d/%d/%d", agendamento[i].dia,agendamento[i].mes,agendamento[i].ano);
            printf("- %s\n", agendamento[i].periodo);

            printf("=============================================================\n");
            printf("                       CORRETORA\n");
            printf("=============================================================\n\n");
            printf("Corretora: %s\n", agendamento[i].nomeCorretora);
            printf("SUSEP: %lld\n", agendamento[i].dadosCorretora[0][0]);
            for (int j = 1; j < MAX_DADOS_AGEN; j++) {
                if (agendamento[i].dadosCorretora[j][0] != 0) {
                    printf("Telefone: %lld\n", agendamento[i].dadosCorretora[j][0]);
                }
            }
            printf("=============================================================\n");
            printf("                       PROPONENTE\n");
            printf("=============================================================\n\n");
            printf("Nome: %s\n", agendamento[i].nomeProponente);
            printf("CPF/CNPJ: %lld\n", agendamento[i].dadosProponente[0][0]); 
            for (int j = 1; j < MAX_DADOS_AGEN; j++) {
                if (agendamento[i].dadosCorretora[j][0] != 0) {
                    printf("Telefone: %lld\n", agendamento[i].dadosProponente[j][0]);
                }
            }
            printf("=============================================================\n");
            printf("                       DADOS DO VE�CULO\n");
            printf("=============================================================\n\n");
            printf("%s\n", agendamento[i].modeloVeic);
            printf("Placa: %s - ", agendamento[i].placaVeic); 
            for (int j = 0; j < 2; j++) {
                if (agendamento[i].anoVeic[j][0] != 0) {
                    printf("Ano/Modelo: %lld/%lld\n", agendamento[i].anoVeic[0][0],agendamento[i].anoVeic[0][1]);
                }
            } 
            printf("Chassis: %s\n", agendamento[i].chassis);
            printf("=============================================================\n");
            printf("                       OBSERVA��ES\n");
            printf("=============================================================\n\n");
            printf("%s\n", agendamento[i].observacoes);                                   

            printf("\n\n");
            printf("A vistoria j� foi realizada?\n");
            printf("Lembrete: O agendamento ser� exclu�do.\n");
            printf("Digite (S/N):");
            char opcao;
            scanf(" %c", &opcao);
            setbuf(stdin, NULL);

            if (opcao == 'S' || opcao == 's') {
                // Remover contato da agenda, utilizando o conceito de fila
                for (int j = i; j < qtdAgendamentos - 1; j++) {
                    agendamento[j] = agendamento[j + 1];
                }
                qtdAgendamentos--;
                printf("\nAgendamento Removido.\n");
                system("cls");
            } else {
                printf("\nAgendamento Mantido.\n");
            }

            return &agendamento[i];
        }
    }

    return NULL;
}

/*A fun��o pesquisarContato() recebe tr�s par�metros: um ponteiro para o array de Agendamentos agendamento, a quantidade de agendamentos qtdeAgendamentos e uma string placaPesquisa que representa a placa do carro a ser pesquisado.
A fun��o percorre a lista de agendamentos usando um loop for, verificando se a placa de cada agendamento � igual � string de pesquisa utilizando a fun��o strcmp().
Se um agendamento com a placa pesquisada for encontrado, a fun��o retorna um ponteiro para o agendamento encontrado (&agendamentos[i]).
Caso nenhum agendamento com a placa pesquisada seja encontrado ap�s percorrer todos os agendamentos, a fun��o retorna NULL.*/
void listarAgendamentos(Agendamento* agendamento, int qtdAgendamentos) 
{
    for (int i = 0; i < qtdAgendamentos; i++) {
            printf("\nAgendamento encontrado:\n");

            printf("Seguradora: %s\n", agendamento[i].seguradora);
            printf("Motivo da Vistoria: %s\n", agendamento[i].motivoVist);
            printf("Data: %d/%d/%d", agendamento[i].dia,agendamento[i].mes,agendamento[i].ano);
            printf("- %s\n", agendamento[i].periodo);

            printf("=============================================================\n");
            printf("                       CORRETORA\n");
            printf("=============================================================\n\n");
            printf("Corretora: %s\n", agendamento[i].nomeCorretora);
            printf("SUSEP: %lld\n", agendamento[i].dadosCorretora[0][0]);
            for (int j = 1; j < MAX_DADOS_AGEN; j++) {
                if (agendamento[i].dadosCorretora[j][0] != 0) {
                    printf("Telefone: %lld\n", agendamento[i].dadosCorretora[j][0]);
                }
            }
            printf("=============================================================\n");
            printf("                       PROPONENTE\n");
            printf("=============================================================\n\n");
            printf("Nome: %s\n", agendamento[i].nomeProponente);
            printf("CPF/CNPJ: %lld\n", agendamento[i].dadosProponente[0][0]); 
            for (int j = 1; j < MAX_DADOS_AGEN; j++) {
                if (agendamento[i].dadosCorretora[j][0] != 0) {
                    printf("Telefone: %lld\n", agendamento[i].dadosProponente[j][0]);
                }
            }
            printf("=============================================================\n");
            printf("                       DADOS DO VE�CULO\n");
            printf("=============================================================\n\n");
            printf("%s\n", agendamento[i].modeloVeic);
            printf("Placa: %s - ", agendamento[i].placaVeic); 
            for (int j = 0; j < 2; j++) {
                if (agendamento[i].anoVeic[j][0] != 0) {
                    printf("Ano/Modelo: %lld/%lld\n", agendamento[i].anoVeic[0][0],agendamento[i].anoVeic[0][1]);
                }
            } 
            printf("Chassis: %s\n", agendamento[i].chassis);
            printf("=============================================================\n");
            printf("                       OBSERVA��ES\n");
            printf("=============================================================\n\n");
            printf("%s\n", agendamento[i].observacoes);                                   
      }
}      

int main() {
    
    system("cls");

    Agendamento Agendamentos[MAX_AGE];
    int qtdAgendamentos = 0;

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao) {
            case 1: //CADASTRAR AGENDAMENTO
                agendar(&Agendamentos[qtdAgendamentos]);
                qtdAgendamentos++;
                printf("\n------Agendamento realizado com sucesso!-----\n");
                break;
            case 4: //GERAR ARQUIVO .TXT
                    if (qtdAgendamentos > 0) {
                    gerarArquivoAgendamentos(Agendamentos, qtdAgendamentos);
                } else {
                    printf("\nN�o h� agendamentos.\n");
                }
                break;
            case 2: //PESQUISA A PATIR DA PLACA
                if (qtdAgendamentos > 0) {
                    char placaPesquisa[100];
                    printf("\nDigite a placa do agendamento: ");
                    scanf(" %[^\n]s", placaPesquisa);
                    setbuf(stdin, NULL);

                    Agendamento* agendamentoEncontrado = pesquisarAgendamento(Agendamentos, qtdAgendamentos, placaPesquisa);
                    if (agendamentoEncontrado == NULL) {
                    printf("\nAgendamento n�o encontrado.\n");
                    }
                } else {
                    printf("\nN�o h� agendamentos.\n");
                }
                    break;
            case 3: //LISTAR AGENDAMENTOS NO TERMINAL
                if (qtdAgendamentos > 0) {
                    listarAgendamentos(Agendamentos, qtdAgendamentos);
                } else {
                    printf("\nN�o h� agendamentos.\n");
                }
                break;
            case 5: //LER ARQUIVO .TXT
                if (qtdAgendamentos == 0) {
                    printf("Nenhum agendamento encontrado no arquivo.\n");
                } else {
                    printf("Agendamentos carregados com sucesso.\n");
                }
                break;                                                      
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
                break;
        }
    } while (opcao != 6);

setlocale(LC_ALL, "portuguese_brazil");

    return 0;
}
/*Na linha do c�digo, agendar(&Agendamentos[qtdAgendamentos]); est� sendo passado o endere�o de mem�ria da posi��o qtdAgendamentos do array Agendamentos para a fun��o agendar().
A raz�o para passar o endere�o de mem�ria � permitir que a fun��o agendar() possa modificar diretamente o elemento do array Agendamentos. Ao passar o endere�o de mem�ria, a fun��o pode acessar e atualizar os valores do elemento correspondente no array.
Sem o uso do operador de endere�o (&), seria passada uma c�pia do valor do elemento do array para a fun��o agendar(). Qualquer modifica��o feita dentro da fun��o seria aplicada apenas � c�pia local e n�o afetaria o array original.
Portanto, usar agendar(&Agendamentos[qtdAgendamentos]); permite que a fun��o agendar() trabalhe diretamente com o elemento correto do array Agendamentos e atualize seus valores de acordo com as necessidades do programa.*/



/*a exclus�o � implementada atrav�s do deslocamento dos contatos subsequentes na lista, preenchendo o espa�o vago.
Quando um contato � removido da agenda, os contatos subsequentes s�o movidos 
uma posi��o para tr�s na lista. Isso significa que o 9� contato ocupar� a 
posi��o do 8�, o 10� ocupar� a posi��o do 9�, e assim por diante. 
O �ltimo contato da lista ser� duplicado no pen�ltimo espa�o, 
mas isso n�o causar� um erro, 
j� que a quantidade de contatos (qtdeContatos) � decrementada em 1, refletindo a remo��o do contato.*/