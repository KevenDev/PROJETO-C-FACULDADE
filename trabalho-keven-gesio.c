#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int matricula;
	float notas[3];
	int faltas;
} Aluno;

int num_alunos = 0;
int quantidadeAulas = 45;

void menu(Aluno *alunos);
void cadastrar(Aluno *alunos);
void alterarDados(Aluno *alunos);
void listarAlunos(Aluno *alunos);
void aprovados(Aluno *alunos);
void reprovadosMedia(Aluno *alunos);
void reprovadosFalta(Aluno *alunos);
int verificaMatricula(Aluno *alunos, int matricula);
float calcularMedia(Aluno aluno);
float calcularFrequencia(Aluno aluno);

int main(){
	Aluno alunos[50];
	menu(alunos);
}

void menu(Aluno *alunos){
	
	int op;
	do{
		printf("\nCadastro dos Alunos:\n");
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
			case 4: aprovados(alunos);
				break;
			case 5: reprovadosMedia(alunos);
				break;
			case 6: reprovadosFalta(alunos);
				break;
			default: printf("\nOPCAO INVALIDA\n");
		}
	}while(op != 0);	
}

void cadastrar(Aluno *alunos){
	int matricula;
	float notas[3];
	int faltas;
	int op;
	do{
		printf("\nQual a matricula: ");
		scanf("%d", &matricula);
		
		if(verificaMatricula(alunos, matricula) == 0){
			do{
				printf("Qual a primeira nota: ");
				scanf("%f", &notas[0]);
				if(notas[0] > 10) printf("Nota invalida\n");
			}while(notas[0] > 10);
			do{
				printf("Qual a segunda nota: ");
				scanf("%f", &notas[1]);
				if(notas[1] > 10) printf("Nota invalida\n");
			}while(notas[1] > 10);
			do{
				printf("Qual a terceira nota: ");
				scanf("%f", &notas[2]);
				if(notas[2] > 10) printf("Nota invalida\n");
			}while(notas[2] > 10);

		
			
			do{
				printf("Qual a quantidade de faltas do aluno: ");
				scanf("%d", &faltas);
	
				if (num_alunos < 50 && faltas <= quantidadeAulas) {
		    		alunos[num_alunos].matricula = matricula; 
		    		alunos[num_alunos].notas[0] = notas[0];
		    		alunos[num_alunos].notas[1] = notas[1]; 
		    		alunos[num_alunos].notas[2] = notas[2]; 
		    		alunos[num_alunos].faltas = faltas;
		    		num_alunos++;
				}else{
					printf("\nQuantidade de faltas invalida. Por favor inserir uma quantidade menor ou igual a 45.\n");
				}
			}while(faltas > quantidadeAulas);
			printf("====================\n");
			printf("Aluno Cadastrado com sucesso\n");
			printf("====================\n");
			printf("1- Continuar cadastro\n");
			printf("0- Sair \n");
			scanf("%d", &op);
			
		}else{
			printf("Essa matricula ja existe. Insira outra.");
		}
	}while(op!=0);
}
void alterarDados(Aluno *alunos){
	int op;
	int matricula;
	if(num_alunos == 0){
		printf("====================\n");
		printf("Nao existe alunos cadastrados\n");
		printf("====================\n");
	}else{
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
	
}
			

void listarAlunos(Aluno *alunos){
	int op;
	if(num_alunos == 0){
		printf("======================\n");
		printf("Nao existe alunos cadastrados\n");
		printf("======================\n");
	}else{
		do{
	printf("Alunos Cadastrados \n");
	for(int i=0; i<num_alunos; i++){
		printf("\nMatricula: %d ", alunos[i].matricula);
		printf("Nota 1 : %.1f ", alunos[i].notas[0]);
		printf("Nota 2 : %.1f ", alunos[i].notas[1]);
		printf("Nota 3 : %.1f ", alunos[i].notas[2]);
		printf("Faltas : %d ", alunos[i].faltas);
		printf("======================\n");	
		}
		printf("\nDigite 0 para sair \n");
		scanf("%d", &op);
	}while(op!=0);
	}
}
void aprovados(Aluno *alunos){
	int contador = 0;
	if(num_alunos == 0){
		printf("====================\n");
		printf("Nao existe alunos cadastrados\n");
		printf("====================\n");
	}else{
			for(int i = 0; i < num_alunos; i++){
		if(calcularMedia(alunos[i]) >= 6 && calcularFrequencia(alunos[i]) >= 75){
			printf("\nALUNOS APROVADO");
			printf("\nMatricula: %d ", alunos[i].matricula);
			printf("Nota 1 : %.1f ", alunos[i].notas[0]);
			printf("Nota 2 : %.1f ", alunos[i].notas[1]);
			printf("Nota 3 : %.1f ", alunos[i].notas[2]);
			printf("Faltas : %d ", alunos[i].faltas);
			printf("\n====================");
			contador++;
		}
	}
	
	if(contador = 0){
		printf("NENHUM ALUNO APROVADO");
	}
  }
}
void reprovadosMedia(Aluno *alunos){
	if(num_alunos == 0){
		printf("======================\n");
		printf("Nao existe alunos cadastrados\n");
		printf("======================\n");
	}else{
		printf("\nALUNOS REPROVADOS POR MEDIA:");
	for(int i = 0; i < num_alunos; i++){
		if(calcularMedia(alunos[i]) < 6){
			printf("\nMatricula: %d ", alunos[i].matricula);
			printf("Nota 1 : %.1f ", alunos[i].notas[0]);
			printf("Nota 2 : %.1f ", alunos[i].notas[1]);
			printf("Nota 3 : %.1f ", alunos[i].notas[2]);
			printf("Faltas : %d ", alunos[i].faltas);
			printf("\n====================");
		}
	}
  }
}

void reprovadosFalta(Aluno *alunos){
	if(num_alunos == 0){
		printf("====================\n");
		printf("Nao existe alunos cadastrados\n");
		printf("====================\n");
	}else{
		printf("\nALUNOS REPROVADOS POR FALTA:");
		for(int i = 0; i < num_alunos; i++){
		if(calcularFrequencia(alunos[i]) < 75){
			printf("\nMatricula: %d ", alunos[i].matricula);
			printf("Nota 1 : %.1f ", alunos[i].notas[0]);
			printf("Nota 2 : %.1f ", alunos[i].notas[1]);
			printf("Nota 3 : %.1f ", alunos[i].notas[2]);
			printf("Faltas : %d ", alunos[i].faltas);
			printf("\n====================");
		}
	}
  }
}

int verificaMatricula(Aluno *alunos, int matricula){
	for(int i = 0; i < num_alunos; i++){
		if(alunos[i].matricula == matricula){
			return 1;
		}
	}
	return 0;
}

float calcularMedia(Aluno aluno){
	float soma = aluno.notas[0] + aluno.notas[1] + aluno.notas[2];
	
	float media = soma / 3;
	
	return media;
}

float calcularFrequencia(Aluno aluno){
	float aulasFrequentadas = quantidadeAulas - aluno.faltas;
	float frequencia = (aulasFrequentadas / quantidadeAulas) * 100;
	
	return frequencia;
}