#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


typedef struct{
	int id;
	char nome[50];
	int datadenascimento;
	float salario;
	float cargahoraria;
}funcionario;


int BuscarFuncionarios(funcionario funcionarios[], int nFuncionarios, int id){
	
int i;
		for(i=0; i<nFuncionarios; i++){
			if(id == funcionarios[i].id){
					return i;
			}
		}
		return -1;
	}


int InserirFuncionario(funcionario funcionarios[], int *nFuncionarios, int tam){
		
		
		int id,valor;
		printf("Qual o id?\n");
		scanf("%d", &id);
		valor =  BuscarFuncionarios(funcionarios, *nFuncionarios,  id);
		
	if(valor == -1){
	
		if(*nFuncionarios<tam){

		funcionarios[*nFuncionarios].id = id;
		
		printf("Qual a data de nascimento?\n");
		scanf("%d", &funcionarios[*nFuncionarios].datadenascimento);
		
		printf("Qual o salario?\n");
		scanf("%f", &funcionarios[*nFuncionarios].salario);
		
		printf("Qual a carga horaria?\n");
		scanf("%f", &funcionarios[*nFuncionarios].cargahoraria);
		
		printf("Qual o nome do funcionario?\n");
		scanf("%s", funcionarios[*nFuncionarios].nome);
		
		
		printf("\nFuncionario adicionado com sucesso!\n");
	
		*nFuncionarios = *nFuncionarios + 1;
		return 1;
	}

	
	else{
		printf("todas as vagas estao ocupadas \n");
		return 0;
	}
}
	if(valor != -1){
		printf("Ja temos registrado um funcionario com esse id\n");
		return 0;
	}
		
		
}


int RemoveFuncionarios(funcionario funcionarios[], int *nFuncionarios){
	int i;
	if(*nFuncionarios<=0){
		printf("Nao ha funcionarios para remover\n");
	}
	else if(*nFuncionarios>0){
	int busca;
	int id;
	printf("Digite o id que deseja remover:\n");
	scanf("%d", &id);
	busca = BuscarFuncionarios(funcionarios, *nFuncionarios,  id);
	
	if(busca!=-1){
		funcionarios[busca].id = funcionarios[*nFuncionarios-1].id;
		funcionarios[busca].datadenascimento = funcionarios[*nFuncionarios-1].datadenascimento;
		funcionarios[busca].salario = funcionarios[*nFuncionarios-1].salario;
		funcionarios[busca].cargahoraria = funcionarios[*nFuncionarios-1].cargahoraria;
		*nFuncionarios = *nFuncionarios - 1;
		printf("Usuario REMOVIDO COM SUCESSO\n");
		return 1;
	}
}
	
	return 0;
}


int AumentaSalario(funcionario funcionarios[], int nFuncionarios, int id){
	int i;
		if(nFuncionarios<=0){
		printf("Nao ha funcionarios para aumentar o salario\n");
	}
	int busca;
	busca = BuscarFuncionarios(funcionarios, nFuncionarios,  id);
	
	if(busca!=-1){
		float salarionovo;
		printf("Digite o novo salario:\n");
		scanf("%f", &salarionovo);
		funcionarios[busca].salario = salarionovo;
		printf(" AUMENTO SALARIAL COM SUCESSO\n");
		return 1;
	}
	else {
		printf("Funcionario nao encontrado \n");
	}
}





int main(){
	
	
	
	funcionario funcionarios[50];
	int tam;
	tam = 50;
	int contador;
	contador =0;
	int decisao;
	int id,busca;
	

	
	while(decisao!=5){
		
		printf("\n\nO que deseja fazer?\n\n");
        printf("1.Adicionar um funcionario\n");
        printf("2.Buscar um funcionario\n");
        printf("3.Remover um funcionario\n");
        printf("4. Aumento salarial\n");
        printf("5.Encerrar o programa\n\n");
		scanf("%d", &decisao);
		
		switch(decisao){
			case 1:
				
					InserirFuncionario(funcionarios, &contador, tam);
				
				break;
				
			case 2:
					if(contador!=0){
					printf("Qual o id?\n");
					scanf("%d", &id);
					busca = BuscarFuncionarios(funcionarios, contador,  id);
					
					if(busca != -1){
					printf("DATA DE NASCIMENTO: %d\n",funcionarios[busca].datadenascimento);
					printf("SALARIO: %f\n",funcionarios[busca].salario);
					printf("CARGA HORARIA: %f \n",funcionarios[busca].cargahoraria);
					printf("NOME: %s \n",funcionarios[busca].nome);
				}
				if(busca == -1){
						printf("\n NAO ENCONTRADO \n");
				}
			}
			else{
				printf("Nao ha funcionarios registrados\n");
			}
				
			break;
			
			case 3:
				RemoveFuncionarios(funcionarios, &contador);
			break;
			
			case 4:
				printf("Digite o id: \n");
				scanf("%d", &id);
				AumentaSalario(funcionarios, contador,  id);
				break;
		}
	}

	
	


	
	
	
	
}
