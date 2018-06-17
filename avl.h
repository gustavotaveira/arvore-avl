#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _Arv{
    int valor;
    int h;
    struct _Arv *esq;
    struct _Arv *dir;
}No;

int buscar(No* arv, int x);
No *inserir(No* arv,  int x);
int remover(No** arv, int x);

//Função de impressão criada apartir de um codigo encontrado em:
//http://web.archive.org/web/20110814175926/http://openasthra.com:80/c-tidbits/printing-binary-trees-in-ascii
extern void print_ascii_tree(No *t);
#define max(x,y) ((x)>(y)?x:y)

#endif // AVL_H
