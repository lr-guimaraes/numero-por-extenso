#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Cabeçario das funções
char EscreveNum(int , int []);
char Unidades(int );
char Dezenas(int );
char DezeUm(int );
char Centenas(int );

int main(){
    int num,N[3],i,j; //Valor fornecido pelo usuario
    char NumStr[20];
    i = 0;

    do{
        printf("Digite um numero entre 1 e 999: ");
        scanf("%s",NumStr);
        num = atoi(NumStr);//salva o valor digitado pelo usuario em INT

        // VERIFICAÇÃO DOS PARAMETROS    
        if (num > 0 && num < 1000 ){
            i++;
        }else{
            printf("Valor fornecido fora dos limites operacinais\n");
        }
     //Conveter para vetor INT
        for (j = 0; j < strlen(NumStr); j++){   
             N[j] = NumStr[j] - 48;
        }
    }while (i == 0);
    EscreveNum(strlen(NumStr),N);
   
    return 0;
}


char EscreveNum(int x, int N[]){
    if( x == 1){
        Unidades(N[0]);
    }
    if( x == 2){  
        if(N[0] > 1){
            if(N[1] > 0){
                Dezenas(N[0]),printf("e"),Unidades(N[1]);
            }else{
                Dezenas(N[0]),Unidades(N[1]);
            }
        }
        else{
            DezeUm(N[1]);
        }      
    }
    if( x == 3){
        if(N[0] == 1 && N[1] == 0 && N[2] == 0){
            printf("Cem");
        }
        else{
            Centenas(N[0]);
            if (N[1] == 1){
                printf("e"),DezeUm(N[1]);
            } 
            else{
                if(N[1] != 0 && N[2] != 0){
                     printf("e"),Dezenas(N[1]),printf("e"),Unidades(N[2]);
                }else if (N[1] == 0){
                    printf("e"),Unidades(N[2]);
                }else if ( N[2] == 0){
                    printf("e"),Dezenas(N[1]);
                }   
            }
        }
    }
}

char Unidades(int N){
    char *U[] = {" ", " um", " dois"," tres"," quatro"," cinco"," seis"," sete"," oito"," nove"};
    int i, cont;
    i = 0;
    cont = 0;

    while (cont <1){
        if(i == N){
            printf("%s",U[i]);
            cont ++;
        }else{
            i++;
        }
    }       
}

char DezeUm(int N){
    char *D[] = {" Dez "," Onze ", " Doze ", " treze ", " quatorze "," quinze ", " dezesseis ", " dezessete ", " dezoito "," dezenove "};
    int i, cont;
    cont = i = 0;

    while (cont< 1){
        if (i == N){
            printf("%s",D[i]);
            cont++;
        }else{
            i++;
        }
    } 
}

char Dezenas(int N){
    char *D[] =  { " "," vinte ", " trinta ", " quarenta ", " cinquenta ", " secenta "," setenta "," ointenta "," noventa "};
    int i,cont;
    i = 1;
    cont = 0;

    while ( cont <1){
        if(i == N){
            printf("%s",D[i-1]);
            cont ++;
        }else{
            i++;
        }
    }
}

char Centenas(int x){
    char *C[] =  {"Cento ", "Duzentos ","trezentos ","Quatrocentos ","Quinhentos ","Seicentos ","Setecentos ","Oitocentos ","Novencentos "};
    int i, cont;
    i = cont = 0;

    while (cont< 1){
        if(i == x){
            printf("%s",C[i-1]);
            cont++;
        }else{
            i++;
        }
    }
}
