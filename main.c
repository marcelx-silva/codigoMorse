#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
#define ALPHABET_SIZE 37

void exibirTabela(char* const alpha[][2]);
void morseToPtbr(char text[MAX], char* const alpha[][2]);
void ptbrToMorse(char text[MAX], char* const alpha[][2]);

int main(void){
    char *morseAlphabet[ALPHABET_SIZE][2] = {
        {"a",".-"},
        {"b","-..."},
        {"c","-.-."},
        {"d","-.."},
        {"e","."},
        {"f","..-."},
        {"g","--."},
        {"h","...."},
        {"i",".."},
        {"j",".---"},
        {"k","-.-"},
        {"l",".-.."},
        {"m","--"},
        {"n","-."},
        {"o","---"},
        {"p",".--."},
        {"q","--.-"},
        {"r",".-."},
        {"s","..."},
        {"t","-"},
        {"u","..-"},
        {"v","...-"},
        {"w",".--"},
        {"x","-..-"},
        {"y","-.--"},
        {"z","--.."},
        {"1",".----"},
        {"2","..---"},
        {"3","...--"},
        {"4","....-"},
        {"5","....."},
        {"6","-...."},
        {"7","--..."},
        {"8","---.."},
        {"9","----."},
        {"0","-----"},
        {" ","   "},
        
    };
    char text[MAX];
    char chr;
    int i = 0;
    printf("%s\n%s\n","Tradutor de Codigo Morse:\nEste programa traduz do Morse para o PT-BR e vice-versa.","Logo Abaixo esta a tabela do alfabeto com os seus respectivos valores em Codigo Morse");
    exibirTabela(morseAlphabet);
    //printf("Digite a opcao que desaeja:\n0 - PT-BR para Morse\n1- Morse para PT-BR\nOpcao: ");
    
    while((chr=getchar())!='\n'){
        text[i++] = chr;
    }
    text[i] = '\0';
    return 0;
}




void ptbrToMorse(char text[MAX],char * const alpha[][2]){
   
        int j = 0, i = 0;
        char *morseText[MAX];
        while(text[i]!='\0'){ //texto = 5
            j = 0;
            while(j<ALPHABET_SIZE){
                if(strchr(alpha[j][0],tolower(text[i]))){
                    morseText[i] = alpha[j][1];
                    j = ALPHABET_SIZE;
                }
           j++;
       }
       i++;
    }
            int a = 0;
            while(morseText[a]!='\0'){
            printf("%s",morseText[a]);
             a++;
        }
}


void morseToPtbr(char text[MAX], char* const alpha[][2]){

    int i=0, j=0;
    char *ptbrText[MAX];
    char *textToken;
    textToken = strtok(text," ");
    while(textToken){
        j = 0;
        while(j<ALPHABET_SIZE){
            if(!strcmp(alpha[j][1],textToken)){
                ptbrText[i] = alpha[j][0];
                
                i++;
                j = ALPHABET_SIZE;
            }
           j++; 
        }
       
        textToken = strtok(NULL," ");
    
    }
    ptbrText[i] = '\0';
        
            int a = 0;
            while(ptbrText[a]!='\0'){
            printf("%s",ptbrText[a]);
            a++;
        }
    
}

void exibirTabela(char* const alpha[][2]){
    for(int i = 0; i<ALPHABET_SIZE;i++){
        printf("%2s |%s \n",alpha[i][0],alpha[i][1]);
        printf("==========\n");
    }
}