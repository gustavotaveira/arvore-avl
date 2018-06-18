#include "avl.h"

//PROTOTIPOS DAS FUNÃ‡Ã•ES
No *novoNo(int valor);
No *rodarDireita(No *no);
No *rodarEsquerda(No *no);
int altura(No *no);
void atualizarAltura(No *arv);
No *inserir(No *arv,  int x);
//-----------------------------------------



No *inserir(No *arv,  int x)
{
  printf("Inserindo %d\n", x);
  if(arv == NULL)
  {
    return novoNo(x);
  }
  if(arv->valor < x)
  {
    arv->dir = inserir(arv->dir, x);
  }
  if(arv->valor > x)
  {
    arv->esq = inserir(arv->esq, x);
  }
  if(arv->valor == x)
  {
    return arv;
  }

  arv->h = 1 + max(altura(arv->dir), altura(arv->esq));

  int fatorBalanceamento = altura(arv->esq) - altura(arv->dir);
  printf("Fator de Balanceamento: %d\n", fatorBalanceamento);
  if(fatorBalanceamento > 1 && x < arv->esq->valor)
  {
    printf("Rodando a direita\n");
    return rodarDireita(arv);
  }

  if(fatorBalanceamento < -1 && x > arv->dir->valor)
  {
    printf("Rodando a esquerda\n");
    return rodarEsquerda(arv);
  }
  if (fatorBalanceamento > 1 && x > arv->esq->valor)
  {
    printf("Rodando a esquerda direita\n");
    (arv)->esq = rodarEsquerda((arv)->esq);
    return rodarDireita(arv);
  }

  if (fatorBalanceamento < -1 && x < arv->dir->valor)
  {
    printf("Rodando a direita esquerda\n");
    (arv)->dir = rodarDireita((arv)->dir);
    return rodarEsquerda(arv);
  }
  return arv;
}


int remover(No** arv, int x){
    if(*arv == NULL) return 0;
    int res;
    if(x < (*arv)->valor){
        if((res=remover(&(*arv)->esq, x))==1){
            if((*arv)->esq->h - (*arv)->dir->h == -2){
                if(altura((*arv)->dir->esq) <= altura((*arv)->dir->dir))
                    rotacaoSimplesEsquerda(arv);
                else
                    direitaEsquerda(arv);
            }
        }
    }
    if((*arv)->valor < x){
        if((res=remover(&(*arv)->dir, x))==1){
            if((*arv)->esq->h - (*arv)->dir->h == 2){
                if(altura((*arv)->esq->dir) <= altura((*arv)->esq->esq))
                    rotacaoSimplesDireita(arv);
                else
                    esquerdaDireita(arv);
            }
        }
    }
    if((*arv)->valor == x){
        if((*arv)->esq == NULL || (*arv)->dir==NULL){
            No* oldNode = (*arv);
            if((*arv)->esq != NULL)
                *arv = (*arv)->esq;
            else
                *arv = (*arv)->dir;
            free(oldNode);
        }else{
            No* temp = procuraMenor((*arv)->dir);
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

No* procuraMenor(No** atual){
    No* arv1 = (*atual);
    No* arv2 = (*atual)->esq;
    while(arv2 != NULL){
        arv1 = arv2;
        arv2 = arv2->esq;
    }
    return arv1;
}

No* rotacaoSimplesDireita(No* r){
    No* aux;
    aux=r->esq;
    r->esq = aux->dir;
    aux->dir = r;
    r->h = max(altura(r->dir),  altura(r->esq))+1;
    aux->h = max(altura(aux->esq), r->h) +1;
    return aux;
}

No* rotacaoSimplesEsquerda(No* r){
    No* aux;
    aux=r->dir;
    r->dir=aux->esq;
    aux->esq = r;
    r->h = max(altura(r->dir),  altura(r->esq))+1;
    aux->h = max(altura(aux->dir), r->h) + 1;
    return aux;
}

No* esquerdaDireita(No* r){
    r->esq = rotacaoSimplesEsquerda(r->esq);
    return rotacaoSimplesDireita(r);
}

No* direitaEsquerda(No* r){
    r->dir = rotacaoSimplesDireita(r->dir);
    return rotacaoSimplesEsquerda(r);
}

int maxi (int a, int b){
    return a > b? a : b;
}

int calcula_altura(No* arv){
 if(arv == NULL) return 0;
 return 1 + maxi(calcula_altura(arv->esq), calcula_altura(arv->dir));
}

int alturah(No** arv){
    if((*arv) == NULL) return 0;
    return (*arv)->h;
}
int grauSub(No** arv, int valor){
   if((*arv) == NULL){
    return -1;
   }
   if((*arv)->valor == valor){
    if((*arv)->esq == NULL || (*arv)->dir == NULL){
        if((*arv)->esq != NULL)
            return 1;
        if((*arv)->dir != NULL)
            return 1;
        return 0;
    }else{
        return 2;
    }
   }
   if(valor < (*arv)->valor)
    return grauSub((*arv)->esq, valor);
   if(valor > (*arv)->valor)
    return grauSub((*arv)->dir, valor);
}


//FUNÃ‡Ã•ES AUXILIARES DO VITOR
//
//-----------------------------------------
//
No *novoNo(int valor)
{
  No *novo = (No*)malloc(sizeof(No));
  novo->valor = valor;
  novo->h = 1;
  novo->dir = NULL;
  novo->esq = NULL;
  return novo;
}

No *rodarDireita(No *no)
{
  No *temp = no->esq;
  No *temp2 = temp->dir;
  temp->dir = no;
  no->esq = temp2;

  no->h = 1 + max(altura(no->dir), altura(no->esq));
  temp->h = 1 + max(altura(temp->dir), altura(temp->esq));

  return temp;
}

No *rodarEsquerda(No *no)
{
  No *temp = no->dir;
  No *temp2 = temp->esq;
  temp->esq = no;
  no->dir = temp2;
  no->h = 1 + max(altura(no->dir), altura(no->esq));
  temp->h = 1 + max(altura(temp->dir), altura(temp->esq));
  return temp;
}

int altura(No *no)
{
  if(no == NULL)
    return 0;
  return no->h;
}

void buscar(No* arv, int x){
   if (arv == NULL){
        printf("Elemento não existe na árvore\n");
         return;
    }

    if (x == arv->valor) {
       printf("O valor %d está na árvore\n", x);
         return;
   }

    if (x < arv->valor){
        buscar(arv->esq, x);
   }else{
       if(x > arv->valor) {
            buscar(arv->dir, x);
        }
    }
}

void grauArv(No* arv){
   if (arv == NULL)
        printf("\nÁrvore não existe\n");
   else if(arv->esq==NULL && arv->dir!=NULL || arv->esq!=NULL && arv->dir==NULL)
               printf("\nÁrvore tem grau 1\n");
        else if(arv->esq!= NULL && arv->dir!=NULL)
                    printf("\nÁrvore tem grau 2\n");
}

void resetar(No* arv){
        if(arv != NULL){
            resetar(arv->esq);
            resetar(arv->dir);
            if(arv->esq==NULL && arv->dir==NULL){
               free(arv);
               arv = NULL;
           }
        }
        printf("Árvore excluída\n");
}
