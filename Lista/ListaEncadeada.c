#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista
{
    int dado;
    struct lista *link;
} no;

no *crialista(int n);
void escrevelista(no *p);
void liberalista(no *p);

int main()
{
    no *primeira;
    int n;

    setlocale(LC_ALL, "Portuguese");

    printf("Criando uma lista encadeada! \n");

    do
    {
        printf("\nEntre com o número de nós: ");
        scanf("%d", &n);
    } while (n < 0);

    primeira = crialista(n);

    if (primeira != NULL)
    {
        printf("\nLista Criada");
        printf("\n");
        escrevelista(primeira);
    }
    else
    {
        printf("\nLista Vazia!");
    }

    liberalista(primeira);

    return (0);
}

no *crialista(int n)
{
    no *ini, *p, *ult;
    int valor;
    ini = ult = NULL;

    for (int i = 1; i <= n; i++)
    {
        printf("\nDigite o valor %d da lista: ", i);
        scanf("%d", &valor);

        p = (no *)malloc(sizeof(no));
        if (p == NULL)
        {
            printf("\nErro de memória!");
            exit(1);
        }

        p->dado = valor;
        p->link = NULL;

        if (ult != NULL)
        {
            ult->link = p;
        }
        else
        {
            ini = p;
        }
        ult = p;
    }

    return ini;
}

void escrevelista(no *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->dado);
        p = p->link;
    }
}

void liberalista(no *p)
{
    no *prox;

    while (p != NULL)
    {
        prox = p->link;
        free(p);
        p = prox;
    }
}