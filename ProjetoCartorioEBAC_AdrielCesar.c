
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int cabecalho()
{
		//Cabe�alho
	printf(" <<<<<< CART�RIO >>>>>> \n");
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
	printf("Essa op��o n�o est� dispon�vel. Selecione outra! \n\n");
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
	printf("##N�o foi poss�vel localizar o CPF## \n\n");

}


int registrar() //Funcao responsavel por cadastras os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio da cria��o de variaveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("<<<REGISTRAR NOMES>>> \n\n");
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	
	FILE *file; //cria o arquivo
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
		
	system("pause");
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
	
	printf("\n--Informa�oes do usu�rio--\n");
	
	if(file == NULL)
	{
		erronome();
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	fclose(file);
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	char conteudo[200];
		
	printf("<<<DELETAR USU�RIOS>>> \n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	printf("\n  ##USU�RIO DELETADO##\n");
	
	if(file == NULL)
	{
		erronome();
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}

	fclose(file);

	printf("\n\n");
	remove(cpf);
	
	system("pause");
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int x=1;
	for(x=1;x=1;)
	{
		system("cls");//Limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
			//In�cio do Menu Inicial
		
		cabecalho();
	
			//Op��es
		printf(" ESCOLHA UMA DAS OP��ES ABAIXO: \n");
		printf("\t 1 - Registrar Nomes \n");
		printf("\t 2 - Consultar Nomes \n");
		printf("\t 3 - Deletar Nomes \n");
			//Fim do Menu Inicial
			
		printf("Opc�o: ");
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
			
		system("cls");//Limpar a tela
	
			//Inic�o da sele��o
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
						
			default:
			erro();
			break;
			
		}
			//Fim da sele��o
	}
}
