#ifndef H_EQUIPA
#define H_EQUIPA

typedef struct _equipa{
char *nome;
int posicao;
int pontos;
}equipa;

typedef struct _listaEquipas{
equipa **equipa; 
int size;
int capacity;
}listaEquipas;

listaEquipas *criaListaEquipas(int capacity);
void addEquipa(listaEquipas *list, equipa *equipa);
void destroiListaEquipas(listaEquipas *list);




#endif