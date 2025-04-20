int ehPalindromoLista(Lista *lista){
	int i=0, size = 1;
	
	if(lista->prim != NULL){
		Nodo *aux1 = lista->prim, *aux2 = lista->prim;
		
		while(aux2->prox != NULL){
			size++;
			aux2 = aux2->prox;
		}
		
		size/=2; //equivalente a começar com size=0 e fazer while(i <= (size+1)/2 )
		while(i <= size){
			if(aux1->info != aux2->info) return 0;
			
			aux1 = aux1->prox;
			aux2 = aux2->ant;
		}
		
		return 1;
	}
}
