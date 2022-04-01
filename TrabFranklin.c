#include <stdio.h>
#include <stdbool.h>
#define tamMax 4

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

void DesempilhaEmpilha(Pilha *p){
    int a, b, x;
    printf("\nescolha o frasco de onde deseja remover: ");
    scanf("%d", &a);
    printf("\nescolha o frasco onde deseja colocar: ");
    scanf("%d", &b);

    a--;b--;    //Pilha 1 = p[0]

    if(!PilhaVazia(p[a]) && !PilhaCheia(p[b]) && ((p[a].elem[p[a].topo] == p[b].elem[p[b].topo]) || (p[b].elem[0] == 0))){
        x = Desempilha(&p[a]);
        Empilha(&p[b], x);
    }
    else{
        printf("\nNAO PODE FDP\n");
        DesempilhaEmpilha(p);
    }
        
}

void imprimePilha(Pilha p){
    for(int i = tamMax - 1; i >= 0; i--){
            printf("%d\n", p.elem[i]);
    }
    printf("\n");
}

/*bool JogoAcabou(){
    for(int i = 0; i < tamMax; i++){

    }
}*/

int main(){
    Pilha q[2];

    //Pilha 1
    inicializaPilha(&q[0]);
    q[0].elem[0] = 1;
    q[0].elem[1] = 1;
    q[0].elem[2] = 1;
    q[0].topo = 2;
    imprimePilha(q[0]);

    //Pilha 2
    inicializaPilha(&q[1]);
    q[1].elem[0] = 1;
    q[1].topo = 0;
    imprimePilha(q[1]);

    DesempilhaEmpilha(q);

    imprimePilha(q[0]);
    imprimePilha(q[1]);

    /*while(JogoAcabou() == false){
        DesempilhaEmpilha(q);

        imprimePilha(q[0]);
        imprimePilha(q[1]);

        JogoAcabou();
    }*/

    return 0;
}