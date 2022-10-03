#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#define C 200

typedef struct Cel {
	int voto, id;
	float porcentagem;
	char Candidato[C];
	struct Cel *prox;
}Celula;

Celula* iniciaCel()
{
	Celula *Lista;
	Lista = (Celula*) malloc(sizeof(Celula));
	Lista->prox = NULL;
	return Lista;
}

void acrescentaCandidato(Celula *Lista, char Nome[C],int *X)
{
	Celula *P, *Nova;
	P=Lista;
	Nova=(Celula*)malloc(sizeof(Celula));
	Nova->prox = P->prox;
	strcpy(Nova->Candidato, Nome);
	Nova->id = ++*X;
	Nova->voto = 0;
	P->prox = Nova;
}

int votar(Celula *Lista, int Iden)
{
	Celula *P;
	P= Lista->prox;
	while(P != NULL && P->id != Iden)
		P = P->prox;
	if(P == NULL)
		return 0;	
	else{
		P->voto +=1;
		printf("Você votou no %s", P->Candidato);
		return 1;}
}

int alterar(Celula *Lista, int Iden)
{
	char MudaNome[C];
	Celula *P = Lista->prox;
	while(P != NULL && P->id != Iden)
		P = P->prox;
	if(P == NULL){
		return 0;}
	else{
		printf("Digite o novo nome:"); gets(MudaNome); fflush(stdin);
		strcpy(P->Candidato,MudaNome);
		printf("Candidato alterado com sucesso."); 
		system("pause");
		return 1;}
}

int excluir (Celula *Lista, int Iden, int *Total)
{
	Celula *P=Lista->prox, *Q=Lista;
	while(P != NULL && P->id != Iden){
		Q = P;
		P = P->prox;}
	if(P == NULL)
		return 0;
	else{
		*Total -= P->voto;
		Q->prox = P->prox;
		free (P);
		printf("Candidato apagado com sucesso");
		system("pause");
		return 1;}
}

void menuinicial(int *Valida)
{
	int Opcao, Flag=0;
	printf("                     PESQUISA DE INTENÇÃO DE VOTOS                       \n");
	printf("__________________________________________________________________________\n\n");
	printf("1- Deputado Federal\n");
	printf("2- Governador \n");
	printf("3- Senador \n");
	printf("4- SAIR \n\n");
	
	printf("DIGITE A OPCÃO QUE DESEJA:");scanf("%d", &Opcao);fflush(stdin);
	 
	while(Flag == 0){ 
		if(Opcao == 1 || Opcao == 2 || Opcao == 3 || Opcao == 4)
			Flag = 1;
		else{
			printf("\nOPÇÃO INVÁLIDA! Digite novamente: ");scanf("%d", &Opcao);fflush(stdin);}}
	*Valida = Opcao;
}

void menucandidato(int Funcao, int *Fazer){
	int Opcao, Flag=0;
	switch (Funcao){
		case 1:
			system("cls");
			printf("                          DEPUTADO FEDERAL                               \n");
			printf("__________________________________________________________________________\n\n");
			printf("1- Cadastrar candidato\n");
			printf("2- Altertar candidato\n");
			printf("3- Remover candidato\n");
			printf("4- Votar\n");
			printf("5- Exibir Resultado\n");
			printf("6- VOLTAR\n");
			printf("7- SAIR\n\n");
			
			printf("DIGITE A OPCÃO QUE DESEJA:");scanf("%d", &Opcao);fflush(stdin);
			
			while(Flag == 0){ 
				if(Opcao == 1 || Opcao == 2 || Opcao == 3 || Opcao == 4 || Opcao == 5 || Opcao == 6 || Opcao == 7)
					Flag = 1;
				else{
					printf("\nOPÇÃO INVÁLIDA! Digite novamente: ");scanf("%d", &Opcao);fflush(stdin);}}
			*Fazer = Opcao;
			break;
		case 2:
			system("cls");
			printf("                             GOVERNADOR                                  \n");
			printf("__________________________________________________________________________\n\n");
			printf("1- Cadastrar candidato\n");
			printf("2- Altertar candidato\n");
			printf("3- Remover candidato\n");
			printf("4- Votar\n");
			printf("5- Exibir Resultado\n");
			printf("6- VOLTAR\n");
			printf("7- SAIR\n\n");
			
			printf("DIGITE A OPCÃO QUE DESEJA:");scanf("%d", &Opcao);fflush(stdin);
			
			while(Flag == 0){ 
				if(Opcao == 1 || Opcao == 2 || Opcao == 3 || Opcao == 4 || Opcao == 5 || Opcao == 6 || Opcao == 7)
					Flag = 1;
				else{
					printf("\nOPÇÃO INVÁLIDA! Digite novamente: ");scanf("%d", &Opcao);fflush(stdin);}}
			*Fazer = Opcao;
			break;
		case 3:
			system("cls");
			printf("                               SENADOR                                   \n");
			printf("__________________________________________________________________________\n\n");
			printf("1- Cadastrar candidato\n");
			printf("2- Altertar candidato\n");
			printf("3- Remover candidato\n");
			printf("4- Votar\n");
			printf("5- Exibir Resultado\n");
			printf("6- VOLTAR\n");
			printf("7- SAIR\n\n");
			
			printf("DIGITE A OPCÃO QUE DESEJA:");scanf("%d", &Opcao);fflush(stdin);
			
			while(Flag == 0){ 
				if(Opcao == 1 || Opcao == 2 || Opcao == 3 || Opcao == 4 || Opcao == 5 || Opcao == 6 || Opcao == 7)
					Flag = 1;
				else{
					printf("\nOPÇÃO INVÁLIDA! Digite novamente: ");scanf("%d", &Opcao);fflush(stdin);}}
			*Fazer = Opcao;
			break;
	}		
}

void listaCandidatos(Celula *Lista)
{
	Celula *P=Lista->prox;
	system("cls");
	printf("                  		LISTA DE CANDIDATOS                                  \n");
	printf("__________________________________________________________________________\n\n");
					
	if(P == NULL)
		printf("Lista ainda vazia\n");
	else 
		while(P != NULL)
		{
			printf("%d. %s\n", P->id, P->Candidato);
			P = P->prox;
		}
						
	printf("__________________________________________________________________________\n\n");
}

void listaVotos(Celula *Lista, int Total)
{
	Celula *P=Lista->prox;
	system("cls");
	printf("                  		LISTA DE VOTOS                                     \n");
	printf("__________________________________________________________________________\n\n");
					
	if(P == NULL)
		printf("Lista ainda vazia\n");
	else{
		while(P != NULL)
		{
			printf("%d. %s - %.2f%% dos votos\n", P->id, P->Candidato, P->porcentagem);
			P = P->prox;
		}}
	printf("Total de votos: %d\n", Total);						
	printf("__________________________________________________________________________\n\n");
}

int porcentagem(Celula *Lista, int Total)
{
	Celula *P=Lista->prox;
	P = Lista->prox;
	if(P == NULL)
		return 0;
	else
		{
			while(P != NULL)
			{
				P->porcentagem = (float) P->voto * 100 / Total;
				P = P->prox;
			}
		}
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	int Opcao, Fazer=0, Candidato, Testa=0, Remove, identificadorDep=0, identificadorGov=0, identificadorSena=0, Votar, TotalVotosDep=0, TotalVotosGov=0, TotalVotosSena=0;
	char Nome[C];
	Celula *DeputFederal, *Governador, *Senador;
	DeputFederal = iniciaCel();
	Governador = iniciaCel();
	Senador = iniciaCel();
	
	do{
	menuinicial(&Opcao);	
	switch (Opcao){
		case 1:
			while (Opcao == 1){
				menucandidato(Opcao, &Fazer);
				switch (Fazer){
					case 1:
						listaCandidatos(DeputFederal);
						printf("Digite o nome do novo candidato: ");gets(Nome);fflush(stdin);
						acrescentaCandidato(DeputFederal, Nome, &identificadorDep);
						printf("INSERIDO COM SUCESSO!");
						system("pause");
						break;
					case 2:
						Testa = 0;
						listaCandidatos(DeputFederal);
						printf("Digite o número do candidato para alterar: ");scanf("%d", &Candidato);fflush(stdin);
						Testa = alterar(DeputFederal, Candidato);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Candidato);fflush(stdin);
							if(Candidato == -1)
								Testa=1;
							else
								Testa = alterar(DeputFederal, Candidato);	
						}
						Candidato = 0;
						break;
					case 3:
						Testa = 0;
						listaCandidatos(DeputFederal);
						printf("Digite o número do candidato para remover: ");scanf("%d", &Remove);fflush(stdin);
						Testa = excluir(DeputFederal, Remove, &TotalVotosDep);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Remove);fflush(stdin);
							if(Remove == -1)
								Testa=1;
							else
								Testa = excluir(DeputFederal, Remove, &TotalVotosDep);	
						}
						Remove = 0;
						break;
					case 4:
						Testa = 0;
						listaCandidatos(DeputFederal);
						printf("Digite o número do candidato para votar: ");scanf("%d", &Votar);fflush(stdin);
						Testa = votar(DeputFederal, Votar);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Votar);fflush(stdin);
							if(Votar == -1)
								Testa=1;
							else
								Testa = votar(DeputFederal, Votar);
						}
						TotalVotosDep ++; 
						Votar=0;
						break;
					case 5:
							if(TotalVotosDep != 0)
							{
								porcentagem(DeputFederal, TotalVotosDep);
								listaVotos(DeputFederal, TotalVotosDep);
								system("pause");
							}
							else 
							{
								printf("Nenhum voto computado até o momento.");
								system("pause");
							}
						break;
					case 6:
						Opcao = 0;
						break;
					case 7:
						exit(0);
						break;
				}	
			}
			break;
		case 2:
			while (Opcao == 2){
				menucandidato(Opcao, &Fazer);
				switch (Fazer){
					case 1:
						listaCandidatos(Governador);
						printf("Digite o nome do novo candidato: ");gets(Nome);fflush(stdin);
						acrescentaCandidato(Governador, Nome, &identificadorGov);
						printf("INSERIDO COM SUCESSO!");
						system("pause");
						break;
					case 2:
						Testa = 0;
						listaCandidatos(Governador);
						printf("Digite o número do candidato para alterar: ");scanf("%d", &Candidato);fflush(stdin);
						Testa = alterar(Governador, Candidato);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Candidato);fflush(stdin);
							if(Candidato == -1)
								Testa=1;
							else
								Testa = alterar(Governador, Candidato);	
						}
						Candidato = 0;
						break;
					case 3:
						Testa = 0;
						listaCandidatos(Governador);
						printf("Digite o número do candidato para remover: ");scanf("%d", &Remove);fflush(stdin);
						Testa = excluir(Governador, Remove, &TotalVotosGov);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Remove);fflush(stdin);
							if(Remove == -1)
								Testa=1;
							else
								Testa = excluir(Governador, Remove, &TotalVotosGov);	
						}
						Remove = 0;
						break;
					case 4:
						Testa = 0;
						listaCandidatos(Governador);
						printf("Digite o número do candidato para votar: ");scanf("%d", &Votar);fflush(stdin);
						Testa = votar(Governador, Votar);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Votar);fflush(stdin);
							if(Votar == -1)
								Testa=1;
							else
								Testa = votar(Governador, Votar);
						}
						TotalVotosGov ++; 
						Votar = 0;
						break;
					case 5:
							if(TotalVotosGov != 0)
							{
								porcentagem(Governador, TotalVotosGov);
								listaVotos(Governador, TotalVotosGov);
								system("pause");
							}
							else
							{
								printf("Nenhum voto computado até o momento.");
								system("pause");
							}
								
						break;
					case 6:
						Opcao = 0;
						break;
					case 7:
						exit(0);
						break;
				}	
			}	
			break;
		case 3:
			while (Opcao == 3){
				menucandidato(Opcao, &Fazer);
				switch (Fazer){
					case 1:
						listaCandidatos(Senador);
						printf("Digite o nome do novo candidato: ");gets(Nome);fflush(stdin);
						acrescentaCandidato(Senador, Nome, &identificadorSena);
						printf("INSERIDO COM SUCESSO!");
						system("pause");
						break;
					case 2:			
						Testa = 0;
						listaCandidatos(Senador);
						printf("Digite o número do candidato para alterar: ");scanf("%d", &Candidato);fflush(stdin);
						Testa = alterar(Senador, Candidato);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Candidato);fflush(stdin);
							if(Candidato == -1)
								Testa=1;
							else
								Testa = alterar(Senador, Candidato);	
						}
						Candidato = 0;
						break;
					case 3:
						Testa = 0;
						listaCandidatos(Senador);
						printf("Digite o número do candidato para remover: ");scanf("%d", &Remove);fflush(stdin);
						Testa = excluir(Senador, Remove, &TotalVotosSena);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Remove);fflush(stdin);
							if(Remove == -1)
								Testa=1;
							else
								Testa = excluir(Senador, Remove, &TotalVotosSena);	
						}
						Remove = 0;
						break;
					case 4:
						Testa = 0;
						listaCandidatos(Senador);
						printf("Digite o número do candidato para votar: ");scanf("%d", &Votar);fflush(stdin);
						Testa = votar(Senador, Votar);
						while(Testa == 0)
						{
							printf("Candidato não encontrado, tente novamente. Ou digite -1 para voltar ao Menu Anterior.\n");
							scanf("%d", &Votar);fflush(stdin);
							if(Votar == -1)
								Testa=1;
							else
								Testa = votar(Senador, Votar);
						}
							 if(Votar != -1)
							 	TotalVotosSena ++;
						Votar = 0;
						break;
					case 5:
							if(TotalVotosSena != 0)
							{
								porcentagem(Senador, TotalVotosSena);
								listaVotos(Senador, TotalVotosSena);
								system("pause");
							}
							else 
							{
								printf("Nenhum voto computado até o momento.");
								system("pause");
							}
						break;
					case 6:
						Opcao = 0;
						break;
					case 7:
						exit(0);
						break;
				}	
			}	
			break;
		case 4:	
			exit(0);
			break;
	}
	system("cls");
	}while(Opcao != 4);
	return 0;
}
