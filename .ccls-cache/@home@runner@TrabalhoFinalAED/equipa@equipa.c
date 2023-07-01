#include "equipa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

listaEquipas *criaListaEquipas(int capacity) {
  listaEquipas *list = (listaEquipas *)malloc(sizeof(listaEquipas));
  if (list == NULL) {
    return NULL;
  }
  list->equipa = (equipa **)malloc(capacity * sizeof(equipa *));
  if (list->equipa != NULL) {
    list->size = 0;
    list->capacity = capacity;
  } else {
    free(list);
    return NULL;
  }
  return list;
}

/**
 * Destroi a lista de equipas libertando a memoria reservada
 * bem como a memoria de cada elemento da lista
 */
void destroiListaEquipas(listaEquipas *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->equipa[i]->nome);
    free(list->equipa[i]);
  }
  free(list->equipa);
  free(list);
}

/**
 * Adiciona um nova equipa a lista
 * Se a lista tiver na sua capacidade maxima impede de adicionar
 */
void addEquipa(listaEquipas *list, equipa *equipa) {
  
}
