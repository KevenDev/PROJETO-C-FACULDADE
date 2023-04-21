#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int matricula;
	float notas[3];
	int faltas;
} Aluno;

int num_alunos = 0;

void menu(Aluno *alunos);
void cadastrar(Aluno *alunos);
void alterarDados(Aluno *alunos);
void listarAlunos(Aluno *alunos);
void aprovados();
void reprovadosMedia();
void reprovadosFalta();

int main(){
	Aluno alunos[50];
	menu(alunos);
}

void menu(Aluno *alunos){
	
	int op;
	do{
		printf("Cadastro dos Alunos:\n");
        printf("Digite o numero de uma das opcoes: \n");
        printf("1- Cadastrar aluno \n");
        printf("2- Alterar dados do alunos \n");
        printf("3- Listar alunos cadastrados \n");
        printf("4- Listar Aluno Aprovados \n");
        printf("5- Listar Aluno Reprovados por media \n");
        printf("6- Listar Aluno Reprovados por falta \n");
        printf("0- Sair \n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &op);
		switch(op){
			case 1: 
				cadastrar(alunos);
			break;
			case 2:
				alterarDados(alunos);
			break;
			case 3: listarAlunos(alunos);
			break;
		}
	}while(op != 0);	
}

void cadastrar(Aluno *alunos){
	int matricula;
	float notas[3];
	int faltas;
	int op;
	do{
		printf("Qual a matricula: ");
		scanf("%d", &matricula);
		printf("Qual a primeira nota: ");
		scanf("%f", &notas[0]);
		printf("Qual a segunda nota: ");
		scanf("%f", &notas[1]);
		printf("Qual a terceira nota: ");
		scanf("%f", &notas[2]);
		printf("Qual a quantidade de faltas do aluno: ");
		scanf("%d", &faltas);
	
		if (num_alunos < 50) {
		    alunos[num_alunos].matricula = matricula; 
		    alunos[num_alunos].notas[0] = notas[0];
		    alunos[num_alunos].notas[1] = notas[1]; 
		    alunos[num_alunos].notas[2] = notas[2]; 
		    alunos[num_alunos].faltas = faltas;
		    num_alunos++;
		}
		
		printf("1- Continuar cadastro\n");
		printf("0- Sair \n");
		scanf("%d", &op);
	}while(op!=0);
}
void alterarDados(Aluno *alunos){
	int op;
	int matricula;
	printf("Digite uma matricula para alterar \n");
	scanf("%d", &matricula);
		
		while (1) { 
        for (int i = 0; i < num_alunos; i++) {
            if (alunos[i].matricula == matricula) {
                printf("Alterar primeira nota: \n");
                scanf("%f", &alunos[i].notas[0]); 
                printf("Alterar segunda nota: ");
                scanf("%f", &alunos[i].notas[1]);   
                printf("Alterar terceira nota:: ");
                scanf("%f", &alunos[i].notas[2]);
                printf("Alterar quantidade de faltas do aluno: ");
                scanf("%d", &alunos[i].faltas);
                return; 
            }
        }
        
        printf("Matricula invalida. Digite novamente: \n");
        scanf("%d", &matricula);
    }
}
			

void listarAlunos(Aluno *alunos){
	int op;
	do{
	printf("Alunos Cadastrados \n");
	for(int i=0; i<num_alunos; i++){
		printf("\nMatricula: %d ", alunos[i].matricula);
		printf("Nota 1 : %.1f ", alunos[i].notas[0]);
		printf("Nota 2 : %.1f ", alunos[i].notas[1]);
		printf("Nota 3 : %.1f ", alunos[i].notas[2]);
		printf("Faltas : %d ", alunos[i].faltas);	
		}
		printf("\nDigite 0 para sair \n");
		scanf("%d", &op);
	}while(op!=0);
}
void aprovados(){
	
}
void reprovadosMedia(){
	
}
void reprovadosFalta(){
	
}