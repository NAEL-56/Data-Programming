/* COMENTE SEU CODIGO! */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define QUANT_PARTIDOS 4

int vencedor(int *votos, int *idxVencedor, float *percentual);
//int segundo_turno(winner, i);
int segundo_empate(int *votos, int *idxVencedor, int total, float *percentual);

int main(){

   int opcao;
   
   int votos[QUANT_PARTIDOS] = {0};
   int numeros[QUANT_PARTIDOS] = {4, 2, 9, 5};
   char partidos[QUANT_PARTIDOS][10] = {"Partido A", "Partido B", "Partido C", "Partido D"};
   
   do{
      printf("----- MENU -----\n");
      printf("1 - Votar \n");
      printf("2 - Numeros e Partidos \n");
      printf("3 - Votos Validos e Invalidos \n");
      printf("4 - Encerrar Votacao \n");
      printf("----- ---- -----\n");
      printf("Informe uma opcao: ");
      scanf("%d", &opcao);
      switch(opcao){
         case 1:
            printf("Votar \n");
            break;
         case 2:
            printf("Numeros e Partidos \n");
            break;
         case 3:
            printf("Votos Validos e Invalidos \n");
            break;
         case 4:
            printf("Encerrar Votacao \n");
            break;
         default:
            printf("Opcao invalida!");
      }
   }while(opcao != 4);

   return 0;
}

int vencedor(int *votos, int *idxVencedor, float *percentual){
    
    int i, winner = 0, total = votos[0], empate = 0, random_N;	// Valores iniciais escolhids poupam processamento.
    
    for (i=1; i < QUANT_PARTIDOS; i++){				//declaro i=1 aqui para facilitar leitura do valor inicial de i. Loop come�a em 1 pois os valores iniciais cobrem i=0.
        if(votos[winner] < votos[i]) winner = i;
        
        total += votos[i];
    }
    for (i=0; i < QUANT_PARTIDOS; i++){				//necess�rio contabilizar empates ap�s saber o vencedor, ou poderiam ser contados empates entre perdedores
        if(votos[winner] == votos[i]){
        	empate++;								//Note que ao comparar o vencedor consigo mesmo, haver� 1 empate somado.
		}
    }
    
    switch(empate){
    	case 1:										//se n�o houver empate aka h� um vencedor
    		*idxVencedor = winner;         
        	*percentual = votos[winner]*100/total;		//multiplica��o antes da divis�o para diminuir erros de arredondamento 
         
        	return 1;
        	break;
    	case 2:										//se s� houve um empate simples
    		for(i=0; i<QUANT_PARTIDOS; i++){
    			if(votos[i] == votos[winner] && i != winner){		//busca o outro vencedor e chama o 2
					//segundo_turno(i, winner); 	/fun��o que ir� contabilizar, exibir e verificar a vota��o no 2o turno, adaptando as fun��es do main
				}
			}
			return 0;
			break;
		default:									//se houver empate m�ltiplo
			srand(time(NULL));
			
			random_N = rand()%empate;
			for(i=0; random_N >= 0; i++){
				if(votos[i] == votos[winner]) random_N--;		//salva o n-�simo vencedor como 1o selecionado, onde n � pseudo-aleat�rio
			}
			winner=i-1;		//necess�rio o -1 pq o passo final � o incremento i++
			 
			random_N = rand()%(empate-1);			//a variedade de escolhas diminuiu pois um foi selecionado acima
			for(i=0; random_N >= 0; i++){			//conta entre os vencedores at� um n pseudo-aleat�rio (random_N � o n�mero de passos, para otimizar o uso de mem�ria)
				if(votos[i] == votos[winner]){
					if(i != winner) random_N--;		//garante de s� dar um passo se o n�mero de votos seja o mesmo, e o concorrente seja diferente
				}					
			}
			//segundo_turno(winner, i);			Envia o vencedor escolhido no primeiro la�o  e no �ltimo passo (vencedor n) do loop acima para o segundo turno, e chama segundo_empate
			return 0;
	}
}

int segundo_empate(int *votos, int *idxVencedor, int total, float *percentual){
	int i, random_N = rand()%2, winner=0;
	
	for (i=1; i < QUANT_PARTIDOS; i++){				//declaro i=1 aqui para facilitar leitura do valor inicial de i. Loop come�a em 1 pois os valores iniciais cobrem i=0.
        if(votos[winner] < votos[i]) winner = i;
    }
	for (i=0; random_N >= 0; i++){
		if(votos[i] == votos[winner]) random_N--;		//salva o n-�simo vencedor como 1o selecionado, onde n � pseudo-aleat�rio
	}
	winner=i-1;
	
	*idxVencedor = winner;         
    *percentual = votos[winner]*100/total;
	
	return 0;
}
