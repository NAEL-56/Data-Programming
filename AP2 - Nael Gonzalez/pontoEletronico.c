#include <stdio.h>
#include "pontoEletronico.h"		//aspas pois � uma biblioteca local

void iniciaPontoEletronico(PontoEletronico *funcionario){		//funcao inicializa a struct zerada para ser poss�vel saber quais dados j� foram acrescentados
	funcionario->hora_chegada[0] = 0;
	funcionario->hora_chegada[1] = 0;
	funcionario->min_chegada[0] = 0;
	funcionario->min_chegada[1] = 0;
	funcionario->hora_saida[0] = 0;
	funcionario->hora_saida[1] = 0;
	funcionario->min_saida[0] = 0;
	funcionario->min_saida[1] = 0;
	
	return;
}

void registraPonto(PontoEletronico *funcionario, int hora, int min){
	if(funcionario->hora_chegada[0]){
		if(funcionario->hora_saida[0]){
			if(funcionario->hora_chegada[1]){
				funcionario->hora_saida[1] = hora;
				funcionario->min_saida[1] = min;
			}
			else{
				funcionario->hora_chegada[1] = hora;
				funcionario->min_chegada[1] = min;
			}
		}
		else{
			funcionario->hora_saida[0] = hora;
			funcionario->min_saida[0] = min;
		}
	}
	else{
		funcionario->hora_chegada[0] = hora;
		funcionario->min_chegada[0] = min;
	}
	
	return;
}

void imprimeTotalTrabalhadoDia(PontoEletronico funcionario){	//n�o � necess�rio passar o endere�o da struct, pois a fun��o n� ir� modificar seu conteudo
	int horas, minutos;
	
	if(funcionario.min_saida[0] < funcionario.min_chegada[0]){
		horas = funcionario.hora_saida[0] - funcionario.hora_chegada[0] -1;
		minutos = funcionario.min_saida[0] + 60 - funcionario.min_chegada[0];
	}
	else{
		horas = funcionario.hora_saida[0] - funcionario.hora_chegada[0];
		minutos = funcionario.min_saida[0] - funcionario.min_chegada[0];
	}
	
	if(funcionario.min_saida[1] < funcionario.min_chegada[1]){
		horas += funcionario.hora_saida[1] - funcionario.hora_chegada[1] -1;
		minutos += funcionario.min_saida[1] + 60 - funcionario.min_chegada[1];
	}
	else{
		horas += funcionario.hora_saida[1] - funcionario.hora_chegada[1];
		minutos += funcionario.min_saida[1] - funcionario.min_chegada[1];
	}
	
	if(minutos>59){		//minutos < 120, pois cada acr�scimo � de no m�ximo 59min
		minutos-=60;
		horas++;
	}
	
	printf("Tempo total trabalhado: %d:%d", horas, minutos);
	
	return;
}
