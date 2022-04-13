#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define tamMax 4
#define Vermelho "\e[1;31m"
#define Amarelo "\e[1;33m"
#define Verde "\e[1;32m"
#define Azul "\e[1;34m"
#define Roxo "\e[1;35m"
#define Ciano "\e[1;36m"
#define Branco "\e[1;37m"
#define Reset "\e[1;0m"

typedef struct TpPilha{
    int elem[tamMax];
    int topo;
}Pilha;


//////////////////////////////////////////////////////////////////////Funções de pilha///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool PilhaCheia(Pilha p){
    return p.topo == (tamMax - 1);
}

bool PilhaVazia(Pilha p){
    return p.topo == -1;
}

int Desempilha(Pilha *p){
    int x;
    if (!PilhaVazia(*p)){
        x = p->elem[p->topo];
        p->elem[p->topo] = 0;       //Elementos vazios são iguais a zero na função imprimePilha
        p->topo = p->topo - 1;
    }
    return x;
}

void Empilha(Pilha *p, int x){
    if(!PilhaCheia(*p)){
        p->topo++;
        p->elem[p->topo] = x;
    }
}


//////////////////////////////////////////////////////////////////////Funções do jogo///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void inicializaZero(Pilha *p){      //Inicializa a pilha com todos os elementos iguais a zero
    p->topo = -1;
    for(int i = 0; i < tamMax; i++)
        p->elem[i] = 0;
}

void DesempilhaEmpilha(Pilha *p, int numP){     //Seleciona os frascos a serem desempilhados e empilhados
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

void imprimePilha(Pilha *p, int numP){      //Imprime os frascos um ao lado do outro
    int j = 1, i = 0;

    printf("\n\n");

    while(j <= tamMax){     //Imprime os elementos das pilhas em sequencia
        for(i = 0; i < numP; i++){;
            if(p[i].elem[tamMax - j] == 0)          //Imprime vazio quando elem = 0
                printf("\t%c %c", 186, 186);    
            
            else if(p[i].elem[tamMax - j] == 1)     //Imprime bola vermelha quando elem = 1
                printf("\t%c" Vermelho "O" Reset "%c", 186, 186); 
              
            else if(p[i].elem[tamMax - j] == 2)     //Imprime bola amarela quando elem = 2
                printf("\t%c" Amarelo "O" Reset "%c", 186, 186); 
            
            else if(p[i].elem[tamMax - j] == 3)     //Imprime bola verde quando elem = 3
                printf("\t%c" Verde "O" Reset "%c", 186, 186); 

            else if(p[i].elem[tamMax - j] == 4)     //Imprime bola azul quando elem = 4
                printf("\t%c" Azul "O" Reset "%c", 186, 186); 

            else if(p[i].elem[tamMax - j] == 5)     //Imprime bola roxa quando elem = 5
                printf("\t%c" Roxo "O" Reset "%c", 186, 186); 

            else if(p[i].elem[tamMax - j] == 6)     //Imprime bola ciano quando elem = 6
                printf("\t%c" Ciano "O" Reset "%c", 186, 186); 
            
            else if(p[i].elem[tamMax - j] == 7)     //Imprime bola branca quando elem = 7
                printf("\t%c" Branco "O" Reset "%c", 186, 186); 
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

bool JogoAcabou(Pilha *p, int x){       //Confere se todas as pilhas cheias tem elementos iguais
    for(int i = 0; i < x; i++){
        for(int j = 1; j < tamMax; j++){
            if(p[i].elem[j] != p[i].elem[j-1])       //Compara elem com seu antecessor e retorna false se forem diferentes
                return false;
        }
    }
    printf(Verde "\n*****************FIM DE JOGO*****************\n" Reset);  //retorna true caso todos os elementos de todas as pilhas são iguais
    return true;
}

int Sorteia(int *a, int numC){      //Sorteia uma cor dentre o número de cores escolhido, desde que a cor tenha sido escolhida menos de tamMax vezes
    int k;
    k = (rand() % numC) + 1;

    switch(k){
        case 1: 
            if(a[0] == tamMax){
                return Sorteia(a, numC);
            }
            else{
                a[0]++;
                return k;
            }
        break;
        case 2:
            if(a[1] == tamMax){
                return Sorteia(a, numC);
            }
            else{
                a[1]++;
                 return k;
            }
        break;
        case 3:
            if(a[2] == tamMax){
                return Sorteia(a, numC);
            }
            else{
                a[2]++;
                return k;
            }
        break;
        case 4:
            if(a[3] == tamMax){
                return Sorteia(a, numC);
            }
            else{
                a[3]++;
                return k;
            }
        break;
        case 5:
            if(a[4] == tamMax){
                return Sorteia(a, numC);
            }
            else{
                a[4]++;
                return k;
            }
        break;
        case 6:
            if(a[5] == tamMax){
                return Sorteia(a, numC);
            }
            else{
                a[5]++;
                return k;
            }
        break;
        case 7:
            if(a[6] == tamMax){
                return Sorteia(a, numC);
            }
            else{
                a[6]++;
                return k;
            }
        break;
    }

    return 0;
}

bool ElemIguais(Pilha *p, int numP){      //Verifica se existe alguma pilha com todos os elementos iguais
    for(int i = 0; i < numP; i++){
        for(int j = 1; p[i].elem[j] == p[i].elem[j-1]; j++){
            if(j == tamMax - 1 && p[i].elem[j] != 0){
                return true;
            }
        }
    }
    return false;
}

void GeraPilhas(Pilha *p, int numP, int numC){      //Gera pilhas aleatórias com elementos distintos
    int i = 0, j = 0;                               //Variavel auxiliar para definir pilha com elementos iguais
    int a[7] = {0, 0, 0, 0, 0, 0, 0};               //Variáveis de auxílio para o sorteio
    int k, t;                                       //variáveis para definir pilhas aleatórias

    do{                                             //Escolhe 2 pilhas aleatórias para serem vazias
        k = (rand() % numP);
        t = (rand() % numP);
    }while(t == k);


    //Gera pilhas com cores aleatórias e deixa 2 vazias
    while (i < numP){
        if (i == k || i == t)
            inicializaZero(&p[i]);
        else{
            for(j = 0; j < tamMax; j++){
                p[i].elem[j] = Sorteia(a, numC);
                p[i].topo = j;
            }
        }
        i++;
    }

    if (ElemIguais(p, numP))
        GeraPilhas(p, numP, numC);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(){

    int numC;                           //Numero de cores. Deve ser entre 2 e 7

    printf("Escolha a quantidade de cores para jogar (2 a 7): ");
    scanf("%d", &numC);
    while((numC<2) || (numC>7)){
        printf("\nNumero de cores invalido! Escolha um valor de 2 a 7: ");
        scanf("%d", &numC);    
    }

    int numP = numC + 2;                //Numero de pilhas/frascos
    Pilha q[numP];                      //Declara pilha
    
    srand(time(NULL));

    GeraPilhas(q, numP, numC);

    imprimePilha(q, numP);

    while(JogoAcabou(q, numP) == false){
        DesempilhaEmpilha(q, numP);
        imprimePilha(q, numP);
    }

    getch();
    return 0;
}
