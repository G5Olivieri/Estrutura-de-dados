#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int valor;
    int tamanho;
    struct arvore* direita;
    struct arvore* esquerda;
}no, *pno;

void inicia(pno a);
int insereRoot(pno a, int valor);
int inserir(pno a, int valor);
void percorrer(pno a);
void percorrerPreOrdem(pno a);
void remover(pno a, int valor);
pno minimo(pno a);

int main()
{
    return 0;
}

void inicia(pno a)
{
    a->direita = a->esquerda = NULL;
    a->tamanho = 0;
}

int insereRoot(pno a, int valor)
{
    pno ptr = (pno)malloc(sizeof(no));
    if(ptr) return -1;
    else
    {
        a->valor = valor;
        a->direita = NULL;
        a->esquerda = NULL;
        a->tamanho++;
        return 0;
    }
}

int inserir(pno a, int valor)
{
    pno ptr = (pno)malloc(sizeof(no));
    pno atual = a;
    if(ptr) return -1;
    else
    {
        ptr->valor = valor;
        if(ptr->valor > atual->valor)
        {
            while(atual->valor < ptr->valor) && (!atual->direita)
            {
                atual = atual->direita;
            }
            atual->direita = ptr;
            atual->direita->direita = NULL;
            atual->direita->esquerda = NULL;
            
            if(atual->valor > ptr->valor)
                atual->esquerda = ptr;
        }
        else
        {
            while(atual->valor > ptr->valor) && (!atual->esquerda)
            {
                atual = atual->esquerda;
            }
            atual->esquerda = ptr;
            atual->esquerda->direita = NULL;
            atual->esquerda->esquerda = NULL;
            
            if(atual->valor < ptr->valor)
                atual->direita = ptr;
        }
        a->tamanho++;
        return 0;
    }
}

void percorrer(pno a)
{
    if(a)
    {
        percorrer(a->esquerda);
        printf("%d ", a->valor);
        percorrer(a->direita);
    }
}

void percorrerPreOrdem(pno a)
{
    if(a)
    {
        printf("%d ", a->valor);
        percorrer(a->esquerda);
        percorrer(a->direita);
    }
}

void remover(pno a, int valor)
{
    pno aux;
    if(a)
    {
        if(valor > a->valor)
        {
            remover(a->direita, valor);
        }
        else
        {
            if(valor < a->valor)
            {
                remover(a->esquerda, valor);
            }
            else
            {
                if((a->esquerda) && (a->direita))
                {
                    aux = minimo((*a)->direita);
                    a->valor = aux->valor;
                    remover(a->direita, a->valor);
                }
                else
                {
                    aux = *a;
                    if(!a->esquerda)
                    {
                        a = a->direita;
                    }
                    else
                    {
                        *a->direita = *a->esquerda;
                    }
                    free(aux);
                    a->tamanho--;
                }
            }
        }
    }
}

pno minimo(pno a)
{
    if(!a) return NULL;
    else if(!a->esquerda) return a;
    else minimo(a->esquerda);
}

