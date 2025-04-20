//COMENTE SEU CODIGO!

#include <stdio.h>
#include "pontoEletronico.h"		//aspas pois é uma biblioteca local

int main(){
	PontoEletronico pEletronico;
	iniciaPontoEletronico(&pEletronico);

	registraPonto(&pEletronico, 8, 10); // Chegada ao trabalho
	registraPonto(&pEletronico, 12, 0); // Intervalo para almoco

	registraPonto(&pEletronico, 13, 10); // Volta do almoco
	registraPonto(&pEletronico, 17, 20); // Saida do trabalho

	imprimeTotalTrabalhadoDia(pEletronico); // Deve imprimir 8:0
	
	return 0;
}
