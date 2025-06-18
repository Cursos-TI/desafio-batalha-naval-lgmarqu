#include<stdio.h>
#include<stdlib.h>
#define linhas 10
#define colunas 10
#define tam 3
#define tamBarco 3

// Matriz para o cone
void preencherCone(int cone [tam][tam]){
     int centro = tam / 2;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j >= centro - i && j <= centro + i){
                cone[i][j] = 2;            
                }else{
                    cone[i][j] = 0;
            }
        }
    }
        
}

//Matriz para a cruz
void preencherCruz(int cruz[tam][tam]){
     int centro = tam / 2;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j ++){
            if(i == centro || j == centro){
                cruz[i][j] = 3;            
                }else{
                    cruz[i][j] = 0;
            }
        }
    }
        
}

// Matriz para o octaedro
void preencherOcta(int octa[tam][tam]){
    int centro = tam / 2;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(abs(i - centro) + abs(j - centro) <= centro){
                octa[i][j] = 4;            
                }else{
                    octa[i][j] = 0;
            }
        }
    }
}

// Função para sobrepor as matrizes menores na matriz principal
void sobreporMatriz(int tabuleiro[linhas][colunas], int habilidades[tam][tam], int offset_i, int offset_j){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(offset_i + i < linhas && offset_j + j < colunas){
                if(habilidades[i][j] != 0){
                    tabuleiro[offset_i + i][offset_j + j] = habilidades[i][j];
                }
            }
        }
    }
}


int main(){

    int tabuleiro[linhas][colunas] = {0}; // declaraçõa da matriz principal
    char letras[colunas] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // colunas delaradas em char  
    int cone[tam][tam], cruz[tam][tam], octa[tam][tam]; // declarando o tamanho das matrizes menores para chamar as funções da mesma

// chamando a posição das matrizes menores na matriz principal     
preencherCone(cone);
preencherCruz(cruz);
preencherOcta(octa);
sobreporMatriz(tabuleiro, cone, 0, 5);
sobreporMatriz(tabuleiro, cruz, 6, 1);
sobreporMatriz(tabuleiro, octa, 5, 5);


// posição dos barcos em vertical e horizontal
for(int j = 0; j < tamBarco; j++){
    tabuleiro[4][j] = 5;
}

for(int i = 0; i < tamBarco; i++){
    tabuleiro[i][3] = 5;
}

    printf("  ");

// for da coluna em char 
for(int i = 0; i < colunas; i++){
    printf("%c ", letras[i]);
}
    printf("\n");

// chamando para printar na tela, matriz final final 
for(int i = 0; i < linhas; i++){
    printf("%d ", i);
    for(int j = 0; j < colunas; j++){
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
    }
return 0;
}