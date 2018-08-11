#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
int codigo;
char nome[10];
struct no *next,*back;
}no;

struct no*corrente,*topo;
int c;
c=0;

void enterdata()
{
printf("Digite o Codigo\n");
scanf("%d",& corrente -> codigo);
printf("Digite o Nome\n");
scanf("%s",& corrente -> nome);
}
 int push (no**lista)
{
       if(topo==NULL)
            {
                topo = (no*)malloc(sizeof(no));
                topo -> back = NULL;
                topo -> next = NULL;
                corrente = topo;
                c++;
                enterdata();
            }
            else
            {
               if(c<10)
               {
                   topo = (no*)malloc(sizeof(no));
                   corrente -> next = topo;
                   topo -> back = corrente;
                   corrente = topo;
                   topo -> next = NULL;
                   c++;
                   enterdata();
            }
            else{
printf("Pilha Cheia ...\n");
system("pause");
            }}}

int pop (no**lista)
{
    if(topo==NULL)
    {
        printf("Pilha Vazia...\n");
        system("pause");
    }
    if(topo -> next == NULL && topo -> back == NULL)
        {
            printf("Removido o Ultimo Elemento da Pilha...\n");
            system("pause");
            free(topo);
            topo = NULL;
            corrente = NULL;
            c=0;
        }else
        {
            corrente = topo;
            topo = topo -> back;
            free(corrente);
            printf("Removido com SUCESSO ...\n");
            system("pause");
            c--;
        }
    }

int top (no**lista)
{
    if(topo==NULL)
    {
        printf("Pilha Vazia...\n");
        system("pause");
    }
        printf("codigo %d",topo -> codigo);
        printf("nome %s",topo ->nome);
}

int main ()

{
    corrente=NULL;
    topo=NULL;
    int op;
    do
    {
        printf("1 - Inserir Registro\n");
        printf("2 - Remover Registro\n");
        printf("3 - Consultar o Topo\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Informe a Opcao\n");
        scanf("%d",& op);
        switch(op)
        {
            case 1:push(& topo);break;
            case 2:pop(& topo);break;
            case 3:top(& topo);break;
            case 0:exit(0);
            default:
            printf("FINAL DE PROCESSAMENTO\n");

        }
    }while(op!=0);
}
