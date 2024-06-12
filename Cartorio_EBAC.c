#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //Bilbioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo que foi criado anteriormente
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar() //Fun��o responsavel para consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf); //Armazenando a variavel "cpf" utilizado a fun��o string "%s"
  	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo CPF e "R" de read (ler) a informa��o
  	
	if(file == NULL) //Se a informa��o n�o existir apresenta a seguinte mensagem
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Armazena informa��o em conteudo se for diferente de NULL
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		
		token = strtok(conteudo, ","); //Variavel utilizada para dividir a string em linhas
		printf("CPF: %s\n", token); //Informa��o a aparecer antes do dados do CPF
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Nome: %s\n", token); //Informa��o a aparecer antes do dados do nome
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Sobrenome: %s\n", token); //Informa��o a aparecer antes do dados do sobrenome
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Cargo: %s\n", token); //Informa��o a aparecer antes do dados do Cargo
	}
  	
  	printf("\n"); //Comando para pular uma linha
  	
	system ("pause");
	
}

int deletar() //Fun��o responsavel de deletar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); 
	scanf("%s", cpf);
	
	FILE *file; //Abrindo o arquivo
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O CPF digitado n�o foi encontrado no sistema!. \n"); //Em caso de numero digitado n�o encontrado no arquivo
		system("pause");
		return 0; //Comando que faz o usuario retornar a tela inicial
	}
	
	fclose(file); //Fecha o arquivo
	
	printf("Deseja deletar este usu�rio do sistema?"); //Confirmando a escolha sobre deletar o usu�rio
	printf("%s",cpf);
	printf("\nDigite (s) para sim ou digite (n) para n�o! \n\n"); //Dando escolhas de caracteres para deletar
	
	getchar(); //Fun�ao para capturar a entrada do usu�rio
	
	char opcao; //Criando a variavel opcao
	opcao = getchar(); //Definindo a variavel que sera referente ao getchar
	
	if(opcao == 's' || opcao == 'S')
	{
	if(remove(cpf) == 0) //Remove o usuario e confirma que foi removido
	{
		printf("Usu�rio deletado com sucesso! \n");
	}
		system("pause");
 	}
	
	
	else if(opcao == 'n' || opcao == 'N') //Mensagem mostrado ao usu�rio caso n�o queira deletar
	{
		printf("Retorne ao menu principal. \n");
		system("pause");
	}
	
	else
	{
		printf("Op��o invalida.\n"); //Caso o CPF inserido seja invalido
		system("pause");
	}

}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	while(1) //Inicio do loop de valida��o de senha
	{
		
		printf("Login de administrador! \n\nDigite a sua senha: ");
		scanf("%s", senhadigitada); //Armazena a senha na variavel
	
		comparacao = strcmp(senhadigitada, "admin");//Compara a variavel que o usuarioa digitou com a senha esperada
		if(comparacao == 0)
		{
			printf("Acesso Permitido!\n");
			break;
		}
		else
		{
			printf("Senha Incorreta! Tente novamente.\n");
			system("pause");
		}
	}
	
		while(1)
		{
			system("cls"); //Responsavel por limpar a tela		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar alunos e funcionarios\n");
			printf("\t2 - Consultar alunos e funcionarios\n");
			printf("\t3 - Deletar alunos e funcionarios\n\n");
			printf("\t4 - Sair do sistema\n");
			printf("Op��o: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenamento a escolha do usu�rio
	
			system("cls"); //Responsavel por limpar a tela
		
			switch(opcao) //Inicio da sele��o do menu
				{
					case 1:
					registro(); //Chamada da fun��o
					break;
			
					case 2:
					consultar();
					break;
			
					case 3:
					deletar();
					break;
			
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;

					default:
					printf("Essa op��o n�o est� disponivel!\n");
					system("pause");
					break;
				} //Fim da sele��o		
		}
	return 0;
}
