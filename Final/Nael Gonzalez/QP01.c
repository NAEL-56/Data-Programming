void imprimeAlternadoLista2(Lista2 *lista){
	NodoLista2* inicial = lista->prim;
	
   NodoLista2* final = lista->prim;
   while(final->prox != NULL) final = final->prox;
   
   while(1){   	
	   if(inicial != final){   	
			printf("%d ", inicial->info);
			inicial = inicial->prox;
	   }

   		printf("%d ", final->info);
   		if(inicial != final){
   			final = final->ant;
		}
		else break;
	}
}
