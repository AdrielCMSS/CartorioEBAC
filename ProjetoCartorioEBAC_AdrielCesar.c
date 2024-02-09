
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int cabecalho()
{
		//Cabeçalho
	printf(" <<<<<< CARTÓRIO >>>>>> \n");
	printf(" ####  ####  ####  #### \n");
	printf(" #     #  #  #  #  # \n");
	printf(" ###   ###   ####  # \n");
	printf(" #     #  #  #  #  # \n");
	printf(" ####  ####  #  #  ####");
	printf("\n\n\n");
}

int erro()
{		//Erro de menu
	printf(" <<<<<<<< ERRO >>>>>>>> \n");
	printf(" ####  ####  ####  #### \n");
	printf(" #     #  #  #  #  #  # \n");
	printf(" ###   ###   ###   #  # \n");
	printf(" #     #  #  #  #  #  # \n");
	printf(" ####  #  #  #  #  ####");
	printf("\n\n\n");
	printf("Essa opção não está disponível. Selecione outra! \n\n");
	system("pause");
}


int erronome()
{		//Erro quando nao encontrar cpf
	printf("  ####  ####  ####  #### \n");
	printf("  #     #  #  #  #  #  # \n");
	printf("  ###   ###   ###   #  # \n");
	printf("  #     #  #  #  #  #  # \n");
	printf("  ####  #  #  #  #  ####");
	printf("\n");
	printf("##Não foi possível localizar o CPF## \n\n");

}


int registrar() //Funcao responsavel por cadastras os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
	//início da criação de variaveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("<<<REGISTRAR NOMES>>> \n\n");
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string


	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		printf("Esse CPF já existe no sistema!\n");
		fclose(file);
	}
	
	else
	{
		fclose(file);
	
		file = fopen(arquivo,"w"); // W significa cria o arquivo
		fprintf(file,"CPF: ");
		fprintf(file,cpf); //salvo o valor da variavel
		fprintf(file,"\n");
		fclose(file); //fecha o arquivo


		printf("Digite o NOME a ser cadastrado:");
		scanf("%s",nome);
	
		file = fopen(arquivo, "a");//A significa alterar arquivo
		fprintf(file,"Nome: ");
		fprintf(file,nome);
		fprintf(file,"\n");
		fclose(file);
	
		
		printf("Digite o SOBRENOME a ser cadastrado:");
		scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,"Sobrenome: ");
		fprintf(file,sobrenome);
		fprintf(file,"\n");
		fclose(file);
	
	
		printf("Digite o CARGO a ser cadastrado:");
		scanf("%s",cargo);

		file = fopen(arquivo, "a");
		fprintf(file,"Cargo: ");
		fprintf(file,cargo);
		fprintf(file,"\n");
		fclose(file);	
	}	
	voltar1();
}


int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[200];

	printf("<<<CONSULTA DE NOMES>>> \n\n");
	
	printf("Informe o CPF para consulta:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	printf("\n--Informaçoes do usuário--\n");
	
	if(file == NULL)
	{
		erronome();
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	fclose(file);
	
	voltar2();
}

int deletar()
{
	char cpf[40];
	char conteudo[200];
		
	printf("<<<DELETAR USUÁRIOS>>> \n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	printf("\n  ##USUÁRIO DELETADO##\n");
	
	if(file == NULL)
	{
		erronome();
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	fclose(file);

	remove(cpf);
	
	voltar3();
}

int voltar1()
{
	int op;
	
	printf("\n\n");
	printf("Deseja registrar outro usuário?? Sim(1) Não(2) \n");
	printf("Opção: ");
	scanf("%d", &op);
	
	switch(op)
	{
		case 1:
		system("cls");
		cabecalho();
		registrar();
		break;
		
		case 2:
		main();
		break;
		
		default:
		voltar1();
		break;
	}
}

int voltar2()
{
	int op;
	
	printf("\n\n");
	printf("Deseja consultar outro usuário?? Sim(1) Não(2) \n");
	printf("Opção: ");
	scanf("%d", &op);
	
	switch(op)
	{
		case 1:
		system("cls");
		cabecalho();
		consultar();
		break;
		
		case 2:
		main();
		break;
		
		default:
		voltar2();
		break;
	}
}

int voltar3()
{
	int op;
	
	printf("\n\n");
	printf("Deseja deletar outro usuário?? Sim(1) Não(2) \n");
	printf("Opção: ");
	scanf("%d", &op);
	
	switch(op)
	{
		case 1:
		system("cls");
		cabecalho();
		deletar();
		break;
		
		case 2:
		main();
		break;
		
		default:
		voltar3();
		break;
	}
}

int main()
{
	int opcao; //Definindo variáveis
	
	system("cls");//Limpar a tela
		
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//Início do Menu Inicial
		
	cabecalho();
	
		//Opções
	printf(" ESCOLHA UMA DAS OPÇÕES ABAIXO: \n");
	printf("\t 1 - Registrar Nomes \n");
	printf("\t 2 - Consultar Nomes \n");
	printf("\t 3 - Deletar Nomes \n");
	printf("\t 4 - Fechar o sistema \n");
		//Fim do Menu Inicial
			
	printf("Opcão: ");
	scanf("%d", &opcao);//Armazenando a escolha do usuário
	
			
	system("cls");//Limpar a tela
	
		//Inicío da seleção
	switch(opcao)
	{
		case 1:
		cabecalho();
		registrar();
		break;
			
		case 2:
		cabecalho();
		consultar();
		break;
			
		case 3:
		cabecalho();
		deletar();
		break;
			
		case 4:
		cabecalho();
		printf("<<<Obrigado por utilizar o sistema>>> \n\n");
		return 0;
		break;
						
		default:
		erro();
		main();
		break;
	}	//Fim da seleção			
}
