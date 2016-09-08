//
//  p1.c
//  p1_Aconti
//
//  Created by Arianna on 9/2/15.
//  Copyright (c) 2015 Arianna. All rights reserved.
//

#include <stdio.h>
#include "tools.h"
#define N 80        //max array slots

void textCheck(char *num, char text[]); //Read and Process Array
void dance(char text[], char num);      //Dance Type
void steps(char text[], int step);      //changes case of character
int arrayLength(char text[]);           //Length of array used

int main(void) {
    banner();
    char num, input[N]={0};
    printf("\nRhythm is an important part of dancing.  ");
    printf("A dancer sets\na rhythm (strong and weak beats) and sticks to it.\n");
    printf("This program will take an inputted statement and set\nthe selected rhythm to it.\n");
    printf("2: 2-step\n3: waltz\n4: march\n##: Exit program");
    do{
        textCheck(&num,input);
        dance(input, num);
    }while(num!='#');
    bye();
    return 0;
}
//Prompt------------------------------------------------------------------------
void
textCheck(char *num, char text[]){
    printf("\n\nEnter a number to select the ryhthm type, followed by\nthe word or statement you");
    printf(" would like to see dance!(Please\ndo not include spaces in word/statement):\n");
    scanf(" %c %80s", num, text);
}
//sends inputted dance type to steps function-----------------------------------
void
dance(char text[], char num){
    int step = 0;
    switch (num){
        case '2':
            step = 2;
            steps(text, step);
            break;
        case '3':
            step = 3;
            steps(text, step);
            break;
        case '4':
            step = 4;
            steps(text, step);
            break;
        case '#':
            break;
        default:
            printf("\nIncorrect dance type.");
            break;
    }
}
//changes lower/upper case of char in array-------------------------------------
void
steps(char text[], int step){
    int length, k;
    length = arrayLength(text);
    for(k = 0; k<length;k++){
        if ( k % step == 0){
            text[k]= toupper(text[k]);
        }else text[k] = tolower(text[k]);
    }
    for(k = 0; k<length;k++){
        printf("%c",text[k]);
    }
}
//returns how much of the array is used-----------------------------------------
int
arrayLength(char text[]){
    int length;
    for(int k = 0 ; k <= N ; k++){
        if (text[k] == 0){
            length=k;
            break;
        }
    }
    return length;
}
