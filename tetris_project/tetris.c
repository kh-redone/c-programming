#include "tetris.h"
#include<unistd.h>
#include"liste_simple.h"

int placePiece(piece P, map *M, int x, int y){ //x moves up and down, y moves right and left
    start: ;
    if(x>M->column - P.row || y>M->column-P.column){
        printf("out of bounds.\n");
        return 0;
    }
    map backup = creerMap(M->column);
    map_copy(*M,&backup);
    for(int i=0;i<P.row;i++){
        for(int j=0;j<P.column;j++){
            if(M->head[x+i][y+j] == 0 || (M->head[x+i][y+j] != 0 && P.head[i][j] == 0))
                M->head[x+i][y+j] += P.head[i][j];
            else{
                map_copy(backup,M);
                return 0;
            }
        }
    }
    libererMap(backup); //freeing memory
    return 1;
}

int id(int x, int y){ //return 2^x * 3^y
    int res=1;
    for(int i=0;i<x;i++) res = res*2;
    for(int i=0;i<y;i++) res = res *3;
    return res;
}
void placePieceSmart(piece* P,map *M,int n){
    int X, Y;
    int x = 0, y = 0, count = 0, k=1;
    map* backup = (map*)malloc(n*sizeof(map)); 
    for(int i=0;i<n;i++) backup[i] = creerMap(M->column);
    liste* solutions = (liste*)malloc(n*sizeof(liste));
    for(int i=0;i<n;i++) solutions[i] = NULL;
    for(int i=0;i<n;i++){
        X = M->column - P[i].row; Y = M->column - P[i].column;
        map_copy(*M,&backup[i]);
        if( recherche(id(x,y),solutions[i])==NULL && placePiece(P[i],M,x,y)  == 1 ){
            ajoutDebut(id(x,y),&solutions[i]); 
            x = 0; y = 0; 
        }
        else{
            if(x<X) x++;
            else{if(x==X){ x=0;y++; }}
            if(y>Y){ 
                count++;
                if(count == (X+1)*(Y+1)) {
                    k++; count=0;
                }
                x=0; y=0;
                map_copy(backup[i-k],M);
                i=i-k;
                if(i<0){printf("Impossible to solve!! \n"); exit(EXIT_FAILURE);}
            }
            i--; 
        }
 
        ecrire_map(*M);
    }
    //freeing memory.
    for(int i=0;i<n;i++) libererMap(backup[i]);
    free(backup);
    for(int i=0;i<n;i++) liberer(&solutions[i]);
    free(solutions);
    return;
}


int main(){
    map M = creerMap(3);
    int n = 3;
    piece* L = (piece*)malloc(n*sizeof(piece));
    for(int i=0;i<n;i++){
        L[i] = creerPiece(2,2);
        printf("Enter your piece\n");
        lire_piece(&L[i]);
        ecrire_piece(L[i]);
    }
    placePieceSmart(L,&M,n);
    ecrire_map(M);
    //freeing memory.
    for(int i=0;i<n;i++) libererPiece(L[i]);
    free(L);
    libererMap(M);
    return 0;
}



