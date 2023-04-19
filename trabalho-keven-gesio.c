#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int matricula;
	float nota1;
	float nota2;
	float nota3;
	int faltas;
} Aluno;

Aluno turma[3];

void cadastrarAluno(Aluno *turma){

    for(int i = 0;  i < 1; i++){

    printf("\nInsira a matricula do Aluno: ");
    scanf("%d", &turma[i].matricula);

    printf("\nInsira a primeira nota do Aluno: ");
    scanf("%f", &turma[i].nota1);

    printf("\nInsira a segunda nota do Aluno: ");
    scanf("%f", &turma[i].nota2);

    printf("\nInsira a terceira nota do Aluno: ");
    scanf("%f", &turma[i].nota3);

    printf("\nInsira a quantidade de faltas do Aluno: ");
    scanf("%d", &turma[i].faltas);
    }
    
    printf("Aluno cadastrado.\n");

}

void listarAlunos(Aluno *turma){	
	printf("Lista de alunos cadastrados:\n");
	
    for (int i = 0; i < 1; i++) {
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Nota 1: %.1f\n", turma[i].nota1);
        printf("Nota 2: %.1f\n", turma[i].nota2);
        printf("Nota 3: %.1f\n", turma[i].nota3);
        printf("Faltas: %d\n", turma[i].faltas);
    }
}
    
    



void optionMenu(int op){
	
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
		
		if(op == 1){
			cadastrarAluno(turma);
		}	
	    else if(op == 2){
			printf("\nAlterar aluno");
		}
		else if(op == 3){
			listarAlunos(turma);
		}
		else if(op == 4){
			printf("\nAlterar aluno");
		}
		else if(op == 5){
			printf("\nAlterar aluno");
		}
		else if(op == 6){
			printf("\nAlterar aluno");
		}
		else if(op == 0){
			printf("\nVoce saiu do programa");
		}
		else{
			printf("\nOpcao invalida, digite outra opcao:\n ");
		}
	}while(op != 0);	
}



int main(){
	int op;
	Aluno turma[3];
	optionMenu(&op);
}


