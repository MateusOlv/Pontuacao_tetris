#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Jogador{
	char nome[16]; 
	int pontuacao[12];
	int totalpts;
	int maior;
	int menor;
};

int main(){
	setlocale(LC_ALL, "portuguese_brazil");
	
	struct Jogador jogador[1000];
	int i, j, n, cont_teste;
	
	cont_teste = 0;
	
	printf("\t\t\t\t\t\t---- PONTUAÇÃO TETRIS ----\n\n");
	printf("Digite o número de jogadores: ");
	scanf("%d", &n);
	
	while(n < 0 || n > 1000){
		system("cls");
		printf("\t\t\t\t\t\t---- PONTUAÇÃO TETRIS ----\n\n");
		
		printf("Número inválido! O número deve estar dentro do intervalo 0 <= x <= 1000.\n");
		printf("Digite o número de jogadores: ");
		scanf("%d", &n);
	}
	
	while(n != 0){
		system("cls");
		
		cont_teste++;
		
		printf("\t\t\t\t\t\t---- PONTUAÇÃO TETRIS ----\n\n");
		
		for(i = 0; i < n; i++) jogador[i].maior = 0;
		for(i = 0; i < n; i++) jogador[i].menor = 1000; 
		
		for(i = 0; i < n; i++){
		fflush(stdin);
		printf("Digite o nome do jogador %d: ", i + 1);
		fgets(jogador[i].nome, 16, stdin);
			for(j = 0; j < 12; j++){
				fflush(stdin);
				printf("Digite a pontuação na rodada %d: ", j + 1);
				scanf("%d", &jogador[i].pontuacao[j]);
				while(jogador[i].pontuacao[j] < 0 || jogador[i].pontuacao[j] > 1000){
					system("cls");
					printf("\t\t\t\t\t\t---- PONTUAÇÃO TETRIS ----\n\n");
					
					printf("Número inválido! O número deve estar dentro do intervalo 0 <= x <= 1000.\n");
					printf("Digite a pontuação na rodada %d do jogador %d: ", j + 1, i + 1);
					scanf("%d", &jogador[i].pontuacao[j]);
					
					system("cls");
					printf("\t\t\t\t\t\t---- PONTUAÇÃO TETRIS ----\n\n");
				}
			}
			system("cls");
			printf("\t\t\t\t\t\t---- PONTUAÇÃO TETRIS ----\n\n");
		}
		
		for(i = 0; i < n; i++){
			for(j = 0; j < 12; j++){
				if(jogador[i].pontuacao[j] > jogador[i].maior) jogador[i].maior = jogador[i].pontuacao[j];
				if(jogador[i].pontuacao[j] < jogador[i].menor) jogador[i].menor = jogador[i].pontuacao[j]; 
			}
		}
		
		
		for(i = 0; i < n; i++) jogador[i].totalpts = 0;
		
		for(i = 0; i < n; i++){
			for(j = 0; j < 12; j++){
				jogador[i].totalpts += jogador[i].pontuacao[j];
			}
		}
		
		for(i = 0; i < n; i++) jogador[i].totalpts -= (jogador[i].maior + jogador[i].menor);
		
		
		system("cls");
		printf("\t\t\t\t\t\t---- PONTUAÇÃO TETRIS ----\n\n");
		
		printf("Resultado:\n");
		for(j = 0; j < n; j++){
			if(jogador[j].totalpts == jogador[j-1].totalpts){
				printf("%d %d %s\n", j, jogador[j].totalpts, jogador[j].nome);
			} 
			else{
				printf("%d %d %s\n", j + 1 , jogador[j].totalpts, jogador[j].nome);	
			}				
		}
	
		printf("Se quiser continuar, digite o número de jogadores, se quiser parar, digite 0: ");
		fflush(stdin);
		scanf("%d", &n);
		
		while(n < 0 || n > 1000){
			printf("Número inválido! O número deve estar dentro do intervalo 0 <= x <= 1000.");
			scanf("%d", &n);
		}
			
 	}
	return 0;
}

