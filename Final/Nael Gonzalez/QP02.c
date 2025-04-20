void esvaziaLista(Lista *lista){ //funcao destroiLista adaptada para devolver vazia
   NodoLista *aux = lista->prim;
   while(aux != NULL){
       NodoLista *tmp = aux->prox;
       free(aux); 
       aux = tmp;
   }
   //free(lista);
}

Lista* mesclaOrdenadaLista(Lista *lista1, Lista *lista2){
   NodoLista *nodoL1 = lista1->prim;
   NodoLista *nodoL2 = lista2->prim;
   
   Lista *listaRes = criaLista();
   
   while(nodoL1 != NULL || nodoL2 != NULL){
   	
		if(nodoL1->info > nodoL2->info || nodoL2 == NULL){
			insereInicioLista(listaRes, nodoL1->info);
			nodoL1 = nodoL1->prox;
		}
		else{
			insereInicioLista(listaRes, nodoL2->info);
			nodoL2 = nodoL2->prox;
		}		
   }
   
   esvaziaLista(lista1);
   esvaziaLista(lista2);   
   
   return listaRes;
}
