#include<stdio.h>
#include "avl.h"
#include<stdlib.h>
#include<locale.h>
#include "imprimeArvore.c"
void limparTela(){
    system("cls");
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int controle;
    int valor;
    No* arv = NULL;
    int executando = 1;


    while(executando){
        printf("�rvore AVL - Estrutura de dados 2\n\n");
        printf("1 - Inserir.\n");
        printf("2 - Remover.\n");
        printf("3 - Buscar.\n");
        printf("4 - Imprimir.\n");
        printf("5 - Grau de um n�.\n");
        printf("6 - Grau da �rvore.\n");
        printf("7 - Filhos de um n�.\n");
        printf("8 - Altura da �rvore.\n");
        printf("9 - Resetar �rvore.\n");
        printf("0 - Sair.\n");
        scanf("%d", &controle);

        switch(controle){
            case 1:
                printf("Insira o valor: ");
                scanf("%d", &valor);
                inserir(arv, valor);
            break;
            case 2:
                printf("Insira o valor: ");
                scanf("%d", &valor);
                int sucesso = remover(&arv, valor);
                if(sucesso)
                    printf("N� %d removido com sucesso.\n");
                else
                    printf("N� n�o encontrado.\n");
            break;
            case 3:
                printf("Insira o valor: ");
                scanf("%d", &valor);
                buscar(arv, valor);

            break;
            case 4:
               print_ascii_tree(arv);
            break;
             case 5:
                 printf("Insira o valor: ");
                scanf("%d", &valor);
                int grau = grauSub(&arv, valor);
                if(grau >= 0)
                    printf("O grau do n� %d � %d.\n", valor, grau);
                else
                    printf("N� n�o encontrado.\n");

            break;
             case 6:
                grauArv(arv);
            break;
             case 7:

            break;
            case 8:
                printf("A altura da �rvore � %d.\n", calcula_altura(arv));
            break;
            case 9:
                resetar(arv);
            break;
            case 0:
                executando = 0;
            break;
        }
        system("pause");
        limparTela();
    }

}
