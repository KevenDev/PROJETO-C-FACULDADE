#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int matricula;
	float nota1;
	float nota2;
	float nota3;
	int faltas;
} Aluno;


/*void cadastrarAluno(Aluno *alunos, int *ptrPosicaoAtual){
	
	/*int posicaoVazia = -1;
	
	for(int i = 0; i < 3; i++){
		if(verificaValorVazio(turma) == 0){
			posicaoVazia = i;
			break;
		}
	}
	
    //for(int i = 0;  i < 1; i++){
		
	if(*ptrPosicaoAtual == 3){
		printf("Numero maximo de alunos atingido");
	}else{
		Aluno aluno;
		
    	printf("\nInsira a matricula do Aluno: ");
    	scanf("%d", &aluno.matricula);

    	printf("\nInsira a primeira nota do Aluno: ");
    	scanf("%f", &aluno.nota1);

    	printf("\nInsira a segunda nota do Aluno: ");
    	scanf("%f", &aluno.nota2);

    	printf("\nInsira a terceira nota do Aluno: ");
    	scanf("%f", &aluno.nota3);

    	printf("\nInsira a quantidade de faltas do Aluno: ");
    	scanf("%d", &aluno.faltas);
    	
    	alunos[*ptrPosicaoAtual] = aluno;
		*ptrPosicaoAtual++;
	}
	
    //}
    
    printf("Aluno cadastrado.\n");

}*/

int verificaMatricula(Aluno *alunos, int matricula){
	for(int i = 0; i < 3; i++){
		if(alunos[i].matricula == matricula){
			return 1;
		}
	}
	return 0;
}

void cadastrarAlunos(Aluno *alunos){
	
	for (int i = 0; i < 3; i++) {
		
		int matricula = 0;
		
        printf("\nDigite a matricula do %d aluno: ", i+1);
        scanf("%d", &matricula);
        
        if(verificaMatricula(alunos, matricula) == 0){
        
        alunos[i].matricula = matricula;
        
        printf("\nDigite a primeira nota do %d aluno: ", i+1);
        scanf("%f", &alunos[i].nota1);
        
        printf("\nDigite a segunda nota do %d aluno: ", i+1);
        scanf("%f", &alunos[i].nota2);
        
        printf("\nDigite a terceira nota do %d aluno: ", i+1);
        scanf("%f", &alunos[i].nota3);
        
        int faltas;
		
		//FUTURAMENTE TENTAR TRANSFORMAR ESSA LÓGICA EM UMA FUNÇÃO
        do{
        	printf("\nDigite quantidade de faltas do %d aluno: ", i+1);
        	scanf("%d", &faltas);
        	
        	if(faltas <= 45){
        	alunos[i].faltas = faltas;
			}else{
				printf("Por favor inserir a quantidade de faltas menor ou igual a 45");
			}
        
		}while(faltas > 45);
		}else{
			printf("Essa matricula ja existe, por favor insira novamente");
			i--;
		}
        
    }
}

void listarAlunos(Aluno *turma){	
	printf("Lista de alunos cadastrados:\n");
	
    for (int i = 0; i < 3; i++) {
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Nota 1: %.1f\n", turma[i].nota1);
        printf("Nota 2: %.1f\n", turma[i].nota2);
        printf("Nota 3: %.1f\n", turma[i].nota3);
        printf("Faltas: %d\n", turma[i].faltas);
    }
}
    
 
 int verificaValorVazio(Aluno *turma){
 	for(int i = 0; i < 3; i++){
 		if(turma[i].matricula == 0){
 			return 0;
		 }
	 }
	 return -1;
 }   



void optionMenu(int op, Aluno *turma, int *ptrPosicaoAtual){
	
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
			cadastrarAlunos(turma);
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
	int op = -1, *ptrPosicaoAtual, quantidadeAulas = 45;
	Aluno turma[3];
	int posicaoAtual = 0;
	*ptrPosicaoAtual = &posicaoAtual;
	
	/*for (int i = 0; i < 3; i++) {
        turma[i].matricula, 0;
        turma[i].nota1, 0,0;
    }*/
	
	optionMenu(op, turma, &posicaoAtual);
}


