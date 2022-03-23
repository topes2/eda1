//
//  Complete o programa para que seja possível, ler uma
//  expressão em infix e fazer a conversão para postfix
//  usando o algoritmo dexcrito nas aulas teóricas
//
//
//  Created by Ligia Ferreira on 12/03/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fatal.h"

int priority(char c);
char* ler_input();
int isNumber(char *token);
char *tostring(char x);
void conversion(char input[], char output[]);
char intopost(char *postfix,int size);
int isOperator(char *token);

/*
Ordem de funcionamento pelo o que percebi:
1-main, onde se cria a char* infix , chama a ler input para poder ter o valor, e a post fix, chama se a conversion and faz se print do post fix
*/
int main(int argc, const char * argv[]) {
  
    char* infix = ler_input();
    
    char postfix[strlen(infix)];
    conversion(infix, postfix);
    intopost(postfix,strlen(infix));
    printf("postfix-> %s\n",postfix);
    
    return 0;
}

char intopost(char *postix, int size){
    char temp[size];
}

int priority(char c){

    return 1;
}

char* ler_input(){
    static char name[100];
    printf("Os tokens devem aprearecer separados por espaço \n");
    printf("Exemplo ( 2 + 6 ) * 10 \n");
    printf("infix : ");
    scanf("%[^\n]s",name);
    return name;
}

int isNumber(char *token){
    if (isdigit(*token))
        return 1;
    else
        return 0;
}

int isOperator(char *token){
    
}

char *tostring(char x){
    static char toReturn[2];
    toReturn[0]=x;
    toReturn[1]='\0';
    return toReturn;
}

// usar strtok para tokenizar a string input
// usar strcat para concatenar strings

void conversion(char input[], char output[]){
    
    char* token;
    output[0]='\0';

    token = strtok(input," "); // o " " é o que vai servir como separador de cada parte do string

    while (token !=NULL){
        printf("token %s\n",token);
        if (token != " "){
            strcat(output, token);
        }
        token=strtok(NULL," ");
    }
}