#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBinaria
{
    int elem;
    struct arvoreBinaria *esq, *dir;
} arvoreBinaria;

arvoreBinaria *insere(arvoreBinaria *a, int el);
arvoreBinaria *remover(arvoreBinaria *a, int el);
arvoreBinaria *menorNo(arvoreBinaria *a);
void liberaArvore(arvoreBinaria *a);

void preOrdem(arvoreBinaria *a);
void emOrdem(arvoreBinaria *a);
void posOrdem(arvoreBinaria *a);

void mostraMenu(void);

int main(void)
{
    arvoreBinaria *raiz = NULL;
    int x;
    char op;

    do
    {
        mostraMenu();
        scanf(" %c", &op);

        switch (op)
        {
        case '1':
            printf("\nValor? ");
            scanf("%d", &x);
            raiz = insere(raiz, x);
            break;

        case '2':
            if (raiz == NULL)
            {
                printf("\nArvore vazia.\n");
            }
            else
            {
                printf("\nDigite um valor: ");
                scanf("%d", &x);
                raiz = remover(raiz, x);
            }
            break;

        case '3':
            printf("\nPre-ordem: ");
            preOrdem(raiz);
            printf("\n");
            break;

        case '4':
            printf("\nEm ordem: ");
            emOrdem(raiz);
            printf("\n");
            break;

        case '5':
            printf("\nPos-ordem: ");
            posOrdem(raiz);
            printf("\n");
            break;

        case '6':
            printf("\nSaindo...\n");
            break;

        default:
            printf("\nOpcao invalida.\n");
        }
    } while (op != '6');

    liberaArvore(raiz);
    return 0;
}

void mostraMenu(void)
{
    printf("\n===== ARVORE BINARIA =====\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Pre-ordem\n");
    printf("4 - Em ordem\n");
    printf("5 - Pos-ordem\n");
    printf("6 - Sair\n");
    printf("> ");
}

arvoreBinaria *insere(arvoreBinaria *a, int el)
{
    if (a == NULL)
    {
        a = (arvoreBinaria *)malloc(sizeof(arvoreBinaria));
        if (a == NULL)
        {
            printf("\nErro: sem memoria.\n");
            return NULL;
        }
        a->elem = el;
        a->esq = a->dir = NULL;
        printf("\nInserido.\n");
    }
    else if (el < a->elem)
    {
        a->esq = insere(a->esq, el);
    }
    else if (el > a->elem)
    {
        a->dir = insere(a->dir, el);
    }
    else
    {
        printf("\nElemento ja existe na arvore.\n");
    }
    return a;
}

arvoreBinaria *menorNo(arvoreBinaria *a)
{
    while (a->esq != NULL)
        a = a->esq;
    return a;
}

arvoreBinaria *remover(arvoreBinaria *a, int el)
{
    if (a == NULL)
    {
        printf("\nElemento nao encontrado.\n");
        return NULL;
    }

    if (el < a->elem)
    {
        a->esq = remover(a->esq, el);
    }
    else if (el > a->elem)
    {
        a->dir = remover(a->dir, el);
    }
    else
    {

        if (a->esq == NULL)
        {
            arvoreBinaria *temp = a->dir;
            free(a);
            printf("\nRemovido.\n");
            return temp;
        }
        if (a->dir == NULL)
        {
            arvoreBinaria *temp = a->esq;
            free(a);
            printf("\nRemovido.\n");
            return temp;
        }

        arvoreBinaria *temp = menorNo(a->dir);
        a->elem = temp->elem;
        a->dir = remover(a->dir, temp->elem);
    }
    return a;
}

void liberaArvore(arvoreBinaria *a)
{
    if (a != NULL)
    {
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
}

void preOrdem(arvoreBinaria *a)
{
    if (a != NULL)
    {
        printf("%d ", a->elem);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void emOrdem(arvoreBinaria *a)
{
    if (a != NULL)
    {
        emOrdem(a->esq);
        printf("%d ", a->elem);
        emOrdem(a->dir);
    }
}

void posOrdem(arvoreBinaria *a)
{
    if (a != NULL)
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->elem);
    }
}