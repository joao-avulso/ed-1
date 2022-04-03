#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define tamMax 4
#define Vermelho "\e[1;31m"
#define Amarelo "\e[1;33m"
#define Verde "\e[1;32m"
#define Reset "\e[1;0m"

typedef struct TpPilha{
    int elem[tamMax];
    int topo;
}Pilha;

void inicializaPilha(Pilha *p){
    p->topo = -1;
    for(int i = 0; i < tamMax; i++){
        p->elem[i] = 0;
    }
}

bool PilhaCheia(Pilha p){
    return p.topo == (tamMax - 1);
}

bool PilhaVazia(Pilha p){
    return p.topo == -1;
}

int Sorteia(int *x, int *y, int *z){
    int k;
    k = (rand() % 3) + 1; 

    switch(k){
        case 1: 
            if(*x == 4){
               return Sorteia(x, y, z);
            }
            else{
                *x = *x+1;
                return k;
            }
        break;
        case 2:
            if(*y == 4){
                return Sorteia(x, y, z);
            }
            else{
                *y=*y+1;
                return k;
            }
        break;
        case 3:
            if(*z == 4){
                return Sorteia(x, y, z);
            }
            else{
                *z=*z+1;
                return k;
            }
        break;
    }
}

int Desempilha(Pilha *p){
    int x = p->elem[p->topo];
    p->elem[p->topo] = 0;
    p->topo = p->topo - 1;
    return x;
}

void Empilha(Pilha *p, int x){
    p->topo++;
    p->elem[p->topo] = x;
}

void DesempilhaEmpilha(Pilha *p, int numP){
    int a, b, x;
    
    do{
    printf("\n  Escolha o frasco de onde deseja remover: ");
    scanf("%d", &a);
    printf("  Escolha o frasco onde deseja colocar: ");
    scanf("%d", &b);
    
    a--;b--;    //Pilha 1 = p[0]
    
    if ((a<0) || (a>=numP) || (b<0) || (b>=numP)) 
        printf(Vermelho"\n**TENTE NOVAMENTE**\n" Reset);
    
    } while ((a<0) || (a>=numP) || (b<0) || (b>=numP));     //Repete a pergunta se os frascos escolhidos não existem



    if(!PilhaVazia(p[a]) && !PilhaCheia(p[b]) && ((p[a].elem[p[a].topo] == p[b].elem[p[b].topo]) || (p[b].elem[0] == 0))){      //Confere se é possível empilhar p[a] em p[b]
        x = Desempilha(&p[a]);
        Empilha(&p[b], x);
    }
    else{
        printf(Vermelho "\n**TENTE NOVAMENTE**\n" Reset);
        DesempilhaEmpilha(p, numP);
    }
        
}

void imprimePilha(Pilha *p,int numP){
    int j = 1, i = 0;

    printf("\n\n");

    while(j <= tamMax){     //Printa os elementos das pilhas em sequencia
        for(i = 0; i < numP; i++){;
            if(p[i].elem[tamMax - j] == 0)          //Printa vazio quando elem = 0
                printf("\t%c %c", 186, 186);    
            
            else if(p[i].elem[tamMax - j] == 1)     //Printa bola vermelha quando elem = 1
                printf("\t%c" Vermelho "O" Reset "%c", 186, 186); 
              
            else if(p[i].elem[tamMax - j] == 2)     //Printa bola amarela quando elem = 2
                printf("\t%c" Amarelo "O" Reset "%c", 186, 186); 
            
            else if(p[i].elem[tamMax - j] == 3)     //Printa bola verde quando elem = 3
                printf("\t%c" Verde "O" Reset "%c", 186, 186); 
        }
        printf("\n");
        j++;
    }

    for(i = 0; i < numP; i++)       //Fundo do frasco
        printf("\t%c%c%c", 200, 205, 188);

    printf("\n");

    for(i = 0; i < numP; i++)       //Numeração do frasco
        printf("\t %d", (i + 1));
}

bool JogoAcabou(Pilha *p, int x){
    for(int i = 0; i < x; i++){
        for(int j = 1; j < tamMax; j++){
            if(p[i].elem[j] != p[i].elem[j-1])       //Compara elem com seu antecessor e retorna false se forem diferentes
                return false;
        }
    }
    printf(Verde "\n*****************FIM DE JOGO*****************\n" Reset);  //retorna true caso todos os elementos de todas as pilhas são iguais
    return true;
}

int main(){
    int numP = 5;                  //Numero de pilhas/frascos
    Pilha q[numP];                //Declara pilha
    int a[3] = {0, 0, 0};       //Variáves de auxílio para o sorteio
    srand(time(NULL));

    //Vermelho = 1
    //Amarelo = 2
    //Verde = 3

    //Pilha 1
    inicializaPilha(&q[0]);
    q[0].elem[0] = Sorteia(&a[0], &a[1], &a[2]);
    q[0].elem[1] = Sorteia(&a[0], &a[1], &a[2]);
    q[0].elem[2] = Sorteia(&a[0], &a[1], &a[2]);
    q[0].elem[3] = Sorteia(&a[0], &a[1], &a[2]);
    q[0].topo = 3;

    //Pilha 2
    inicializaPilha(&q[1]);
    q[1].elem[0] = Sorteia(&a[0], &a[1], &a[2]);
    q[1].elem[1] = Sorteia(&a[0], &a[1], &a[2]);
    q[1].elem[2] = Sorteia(&a[0], &a[1], &a[2]);
    q[1].elem[3] = Sorteia(&a[0], &a[1], &a[2]);
    q[1].topo = 3;

    //Pilha 3
    inicializaPilha(&q[2]);
    q[2].elem[0] = Sorteia(&a[0], &a[1], &a[2]);
    q[2].elem[1] = Sorteia(&a[0], &a[1], &a[2]);
    q[2].elem[2] = Sorteia(&a[0], &a[1], &a[2]);
    q[2].elem[3] = Sorteia(&a[0], &a[1], &a[2]);
    q[2].topo = 3;

    //Pilha 4
    inicializaPilha(&q[3]);

    //Pilha 5
    inicializaPilha(&q[4]);


    imprimePilha(q, numP);


    while(JogoAcabou(q, numP) == false){
        DesempilhaEmpilha(q, numP);
        imprimePilha(q, numP);
    }

    getch();
    return 0;
}
