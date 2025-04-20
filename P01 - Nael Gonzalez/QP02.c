void separaParesEImparesEOrdenaDeque(Deque *deque){
	Deque *dequeImpar = criaDeque(), *dequePar = criaDeque();
	Nodo *aux = deque->ini;
	int info;
	
	while(aux!=NULL){
		if(aux->info %2) insereFimDeque(dequeImpar, aux->info);
		else insereFimDeque(dequePar, aux->info);
		
		info = removeInicioDeque(deque);
		
		aux = aux->prox;
	}
	
	aux = dequeImpar->ini;
	while(aux != NULL){
		insereInicioDeque(deque, aux->info);
		aux = aux->prox;
	}
		
	aux = dequePar->ini;
	while(aux != NULL){
		insereFimDeque(deque, aux->info);
		aux = aux->prox;
	}

	destroiDeque(dequePar);
	destroiDeque(dequeImpar);
}
