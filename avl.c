#include "avl.h"

int buscar(Arv* arv,  int x){

}

void inserir(Arv* arv, int x){

}

int remover(Arv** arv, int x){
    if(*arv == NULL) return;
    int res;
    if(x < (*arv)->valor){
        if((res=remover(&(*arv)->esq, x))==1){
            if(*arv->esq->h - *arv->dir->h == -2){
                if(altura((*arv)->dir->esq) <= altura((*arv)->dir->dir))
                    rotacaoSimplesEsquerda(arv);
                else
                    direitaEsquerda(arv);
            }
        }
    }
    if((*arv)->valor < x){
        if((res=remover(&(*arv)->dir, x))==1){
            if(*arv->esq->h - *arv->dir->h == 2){
                if(altura((*arv)->esq->dir) <= altura((*arv)->esq->esq))
                    rotacaoSimplesDireita(arv);
                else
                    esquerdaDireita(arv)
            }
        }
    }
    if((*arv)->valor == valor){
        if((*arv)->esq == NULL || (*arv)->dir==NULL){
            Arv* oldNode = (*arv);
            if((*arv)->esq != NULL)
                *arv = (*arv)->esq;
            else
                *arv = (*arv)->dir;
            free(oldNode);
        }else{
            struct Arv* temp = procuraMenor((*arv)->dir);
            (*arv)->valor = temp->valor;
            remover(&(*arv)->dir, (*arv)->valor);
            if((*arv)->dir->h - (*arv)->esq->h == 2){
                if(altura((*arv)->esq->dir) <= altura((*arv)->esq->esq))
                    rotacaoSimplesDireita(arv);
                else
                    esquerdaDireita(arv);
            }

        }
        return 1;
    }
    return res;
}

Arv* procuraMenor(Arv* atual){
    Arv* arv1 = atual;
    Arv* arv2 = atual->esq;
    while(arv2 != NULL){
        arv1 = arv2;
        arv2 = arv2->esq;
    }
    return arv1;
}

Arv* rotacaoSimplesDireita(Arv* r){
    Arv* aux;
    aux=r->esq;
    r->esq = aux->dir;
    aux->dir = r;
    r->h = max(altura(r->dir),  altura(r->esq))+1;
    aux->h = max(altura(aux->esq), r->h) +1;
    return aux;
}

Arv* rotacaoSimplesEsquerda(Arv* r){
    Arv* aux;
    aux=r->dir;
    r->dir=aux->esq;
    aux->esq = r;
    r->h = max(altura(r->dir),  altura(r->esq))+1;
    aux->h = max(altura(aux->dir), r->h) + 1;
    return aux;
}

Arv* esquerdaDireita(Arv* r){
    r->esq = rotacaoSimplesEsquerda(r->esq);
    return rotacaoSimplesDireita(r);
}

Arv* direitaEsquerda(Arv* r){
    r->dir = rotacaoSimplesDireita(r->dir);
    return rotacaoSimplesEsquerda(r);
}

int max (int a, int b){
    return a > b? a : b;
}

int calcula_altura(Arv* arv){
 if(arv == NULL) return 0;
 return 1 + max(calcula_altura(arv->esq), calcula_altura(arv->dir));
}

int altura(Arv** arv){
    if(*arv == NULL) return 0;
    return *arv->h;
}
int grauSub(Arv** arv){
    if(arv->esq == NULL || arv->dir == NULL){
        if(arv->esq != NULL){
            return 1;
        }
        if(arv->dir != NULL){
            return 1
        }
        return 0;
    }
    return 2;
}
