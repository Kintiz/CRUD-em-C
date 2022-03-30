#include <stdio.h> 
#include <stdlib.h> //system("pause"); system("cls");
#include <locale.h> //setlocale(LC_ALL, "Portuguese");
#include <conio.h> // getch();
#include <string.h>
#include <time.h>
#define termino "nao" || "n�o" //do while
#define outro "sim" //do while

typedef struct tmo {
	
int sec, min, hour, dia, mes, ano; 

}tmo;

typedef struct tCadastro {  //ESTRUTURA DE DADOS DO CADASTRO

	int a, sw, remove, id;
	int idade, cpf;	
	float salario;
	char curso [70];
	char nome [50];
	char ter [5];
	char iu [5];
	FILE *arq;
	
}tCadastro;

/*void tela_cadastro () {
	
	tCadastro cadastro;
	
	system("cls");
			
	printf("Informe o nome do funcion�rio: ");
	fflush(stdin);
	gets(cadastro.nome);
		
	printf("Informe a idade do funcion�rio: ");
	scanf("%d", &cadastro.idade);
			
	printf("Informe o CPF do funcionario: ");
	scanf("%d", &cadastro.cpf);	
			
	printf("Informe o n�vel de escolaridade do funcion�rio: ");
	fflush(stdin);
	gets (cadastro.curso);
			
	printf("Informe o salario do funcionario: ");
	scanf("%f", &cadastro.salario);
        	
	system("cls");
				
	printf("\n\n----------- Funcion�rio ------------\n\n");
	printf("Nome: %s \n", cadastro.nome);
	printf("Idade: %d \n", cadastro.idade);
	printf("CPF: %d \n", cadastro.cpf);
	printf("Escolaridade: %s \n", cadastro.curso);
	printf("Sal�rio: %.2f \n", cadastro.salario);
	
	printf("\n\nFuncion�rio Cadastrado! \n\n");			
				
}*/

int main () {
	
	int i = 1;
	
	setlocale(LC_ALL, "Portuguese");
	
	tCadastro cadastro;
	
	tCadastro **c;
	
	tmo *atual;     
	time_t segundos;
	time(&segundos);
	atual = localtime(&segundos);
	
	for(i=0;i<10;i++){
		printf("/");
		system("color CF");
		system("cls");
		printf("|");
		system("color AF");
		system("cls");
		printf("\\");
		system("color 3F");
		system("cls");
		printf("-");
		system("color 7F");
		system("cls");
	}
	
	
	
     
	do {
		
	/*system("cls");
	printf("1 - Cadastro de funcion�rio                                                                    %d:%d:%d  %d/%d/%d \n", atual->hour, atual->min, atual->sec, atual->dia, atual->mes, atual->ano+1900);
	printf("2 - Lista de funcion�rios cadastrados \n");
	printf("3 - Deletar um cadastro de funcionario \n");
	printf("4 - Pesquisar o cadastro de um funcion�rio \n");
	printf("5 - Modificar informa��es sobre cadastro de um funcion�rio \n");
	printf("0 - Sair: \n");
	scanf("%d", &cadastro.sw);*/
	
	switch (cadastro.sw) {
		
		case 1: //SOLICITA E ARMAZENA NO ARQUIVO.TXT OS DADOS

		do  {
			//tela_cadastro;
			
			printf("Deseja adicionar outro cadastro? ");
			fflush(stdin);
			scanf("%s", &cadastro.iu);
				
		} while (strcmp(outro, cadastro.iu) == 0);
				
			system("cls");
		break;
		
		
		case 2:  //IMPRIME OS CADASTROS PRESENTES NO ARQUIVO.TXT	
			
			system("cls");
			
			cadastro.arq = fopen ("binario.bin", "rb");
			
			if (cadastro.arq == NULL) {
				printf("Arquivo n�o abriu \n");
			}
			
			//for(i=0;i<quant;i++){
				while (fread(&cadastro, sizeof(tCadastro), 1, cadastro.arq)){
				printf("\n--------- Funcion�rio ---------\n\n");
				printf("Nome: %s \n", cadastro.nome);
				printf("Idade: %d \n", cadastro.idade);
				printf("CPF: %d \n", cadastro.cpf);
				printf("Escolaridade: %s \n", cadastro.curso);
				printf("Sal�rio: %.2f \n\n", cadastro.salario);
			}
			
			fclose (cadastro.arq);	
							
		break;
			
		case 3: //DELETA UM CADASTRO
			break;
			
		case  4: //PROCURA UM CADASTRO
		
			break;
			
			
		case 5: //MODIFICA OS DADOS DO ARQUIVO.TXT

			cadastro.arq = fopen("binario.bin", "ab+");
			
			if (cadastro.arq) {
				
				system("cls");
				
				while (fread(&cadastro, sizeof(tCadastro), 1, cadastro.arq)){
					printf("\n--------- %d Funcion�rio ---------\n\n", i);
					printf("Nome: %s \n", cadastro.nome);
					printf("Idade: %d \n", cadastro.idade);
					printf("CPF: %d \n", cadastro.cpf);
					printf("Escolaridade: %s \n", cadastro.curso);					
					printf("Sal�rio: %.2f \n\n", cadastro.salario);
					i++;
				}
				
				printf("Informe o id do funcionario: ");
				scanf("%d", &i);
				getchar();
				
				if( i >= 0 && i < cadastro.id - 1){									
					printf("Informe o nome do funcion�rio: ");
					fflush(stdin);
					gets(cadastro.nome);
			
					printf("Informe a idade do funcion�rio: ");
					scanf("%d", &cadastro.idade);
					
					printf("Informe o CPF do funcionario: ");
					scanf("%d", &cadastro.cpf);	
						
					printf("Informe o n�vel de escolaridade do funcion�rio: ");
					fflush(stdin);
					gets(cadastro.curso);
						
					printf("Informe o salario do funcionario: ");
					scanf("%f", &cadastro.salario);
					
					fseek(cadastro.arq, i * sizeof(tCadastro), SEEK_SET);
					fwrite(&cadastro, sizeof(tCadastro), 1, cadastro.arq);
					
				} fclose(cadastro.arq);
				
			} else printf("Arquivo n�o abriu \n");
			
			break;
			
			default: 
			printf("Programa Finalizado! ");
			return 0;
	}
	
	printf("Deseja Finalizar o programa? ");
	scanf("%s", &cadastro.ter);
	
	} while (strcmp(termino, cadastro.ter) == 0);
	
return 0;
}

