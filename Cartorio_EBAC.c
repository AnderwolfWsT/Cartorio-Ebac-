#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memoria
#include <locale.h> //Bilbioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
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

int consultar() //Função responsavel para consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf); //Armazenando a variavel "cpf" utilizado a função string "%s"
  	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo CPF e "R" de read (ler) a informação
  	
	if(file == NULL) //Se a informação não existir apresenta a seguinte mensagem
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Armazena informação em conteudo se for diferente de NULL
	{
		printf("\nEssas são as informações do usuário:\n");
		
		token = strtok(conteudo, ","); //Variavel utilizada para dividir a string em linhas
		printf("CPF: %s\n", token); //Informação a aparecer antes do dados do CPF
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Nome: %s\n", token); //Informação a aparecer antes do dados do nome
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Sobrenome: %s\n", token); //Informação a aparecer antes do dados do sobrenome
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Cargo: %s\n", token); //Informação a aparecer antes do dados do Cargo
	}
  	
  	printf("\n"); //Comando para pular uma linha
  	
	system ("pause");
	
}

int deletar() //Função responsavel de deletar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); 
	scanf("%s", cpf);
	
	FILE *file; //Abrindo o arquivo
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O CPF digitado não foi encontrado no sistema!. \n"); //Em caso de numero digitado não encontrado no arquivo
		system("pause");
		return 0; //Comando que faz o usuario retornar a tela inicial
	}
	
	fclose(file); //Fecha o arquivo
	
	printf("Deseja deletar este usuário do sistema?"); //Confirmando a escolha sobre deletar o usuário
	printf("%s",cpf);
	printf("\nDigite (s) para sim ou digite (n) para não! \n\n"); //Dando escolhas de caracteres para deletar
	
	getchar(); //Funçao para capturar a entrada do usuário
	
	char opcao; //Criando a variavel opcao
	opcao = getchar(); //Definindo a variavel que sera referente ao getchar
	
	if(opcao == 's' || opcao == 'S')
	{
	if(remove(cpf) == 0) //Remove o usuario e confirma que foi removido
	{
		printf("Usuário deletado com sucesso! \n");
	}
		system("pause");
 	}
	
	
	else if(opcao == 'n' || opcao == 'N') //Mensagem mostrado ao usuário caso não queira deletar
	{
		printf("Retorne ao menu principal. \n");
		system("pause");
	}
	
	else
	{
		printf("Opção invalida.\n"); //Caso o CPF inserido seja invalido
		system("pause");
	}

}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	while(1) //Inicio do loop de validação de senha
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
			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar alunos e funcionarios\n");
			printf("\t2 - Consultar alunos e funcionarios\n");
			printf("\t3 - Deletar alunos e funcionarios\n\n");
			printf("\t4 - Sair do sistema\n");
			printf("Opção: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenamento a escolha do usuário
	
			system("cls"); //Responsavel por limpar a tela
		
			switch(opcao) //Inicio da seleção do menu
				{
					case 1:
					registro(); //Chamada da função
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
					printf("Essa opção não está disponivel!\n");
					system("pause");
					break;
				} //Fim da seleção		
		}
	return 0;
}
