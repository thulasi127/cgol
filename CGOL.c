#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZEX 20
#define SIZEY 40

/*
 *   Program name: CGOL.c
 *   Author: Thulasi Jothiravi
 *   Last Update: November 25, 2019
 *   Function: Run the Conway's Game of Life program
 *   Compilation: gcc -ansi -o CGOL CGOL.c
 *   Execution: ./CGOL
 */



int main(int argc, char *argv[]) {

  FILE *input;

  int i, j, k;
  int tick = 0;
  int tickTotal = 50;
  int neighbours = 0;

  char nextGen[20][40];
  char current[20][40];
  char seed[51];
  char question[20];
  char question2[20];

  if (argc < 2 || argc > 3){
    printf("Usage: ./CGOL fileName.seed <tick>\n");
    return (1);
  } else if (argc == 3){
    for(j=0; j<51; j++){
      seed[j] = argv[1][j];
    }
    tickTotal = atoi(argv[2]);
  } else{
    for(j=0; j<51; j++){
      seed[j] = argv[1][j];
    }
  }

  if ((input = fopen(seed, "r"))!= NULL){
    printf(" ----------------------------------------\n");
    for (i = 0; i < SIZEX; i++){
      printf("|");
      for (j = 0; j < SIZEY; j++){
        fscanf(input,"%d", &current[i][j]);


        if (current[i][j] == 1) {
          printf("X");
        } else if (current[i][j] == 0) {
          printf(" ");
        }
      }
      printf("|\n");
    }
  }
  printf(" ---------------------------------------%d\n", tick);
  tick++;
  fclose(input);

while (strcmp(question2,"n")!=0){
  printf("Start? (y or n)\n");
  scanf("%s",question);

  if (strcmp(question,"n")==0 || strcmp(question,"N")==0) {
    printf("Program Terminated\n");
    exit(1);
  } else if (strcmp(question,"y")==0 || strcmp(question,"Y")==0){


    for(k = tick; k <= tickTotal; k++) {
      for (i = 0; i < SIZEX; i++){
        for (j = 0; j < SIZEY; j++){
          neighbours = 0;
          if (j < SIZEX){
            if (!((i-1<0) || (j-1<0))){
              if (current[i-1][j-1]==1){
                neighbours++;
              }
            }
            if (!(i-1<0)){
              if (current[i-1][j]==1){
                neighbours++;
              }
            }
            if (!((i-1 < 0) || (j+1 > SIZEY))){
              if (current[i-1][j+1]==1){
                neighbours++;
              }
            }
            if (!(j-1<0)){
              if (current[i][j-1]==1){
                neighbours++;
              }
            }
            if(!(j+1 > SIZEY)){
              if(current[i][j+1]==1){
                neighbours++;
              }
            }
            if (!((i+1 < 0)||(j + 1<0))){
              if (current[i+1][j-1]==1){
                neighbours++;
              }
            }
            if (!(i+1<0)){
              if(current[i+1][j]==1){
                neighbours++;
              }
            }
            if (!((i+1<0)||(j+1>SIZEY))){
              if (current[i+1][j+1]==1){
                neighbours++;
              }
            }
          }

      if (current[i][j] == 1 && neighbours < 2){
        nextGen[i][j] = 0;
      } else if (current[i][j] == 1 && (neighbours == 2 || neighbours == 3)){
          nextGen[i][j] = 1;
      } else if (current[i][j] == 1 && neighbours > 3){
          nextGen[i][j] = 0;
      } else if (current[i][j] == 0 && neighbours == 3){
          nextGen[i][j] = 1;
      }
        else {
          nextGen[i][j]=0;
        }
      }
    }
    i = 0;
    j = 0;

  system("clear");

  printf(" ----------------------------------------\n");
  for (i = 0; i < SIZEX; i++){
    printf("|");
    for (j = 0; j < SIZEY; j++){
      current[i][j]= nextGen[i][j];


      if (current[i][j] == 1) {
        printf("X");
      } else if (current[i][j] == 0) {
        printf(" ");
      }
    }
    printf("|\n");
   }
   printf(" ---------------------------------------%d\n", tick);
    system("sleep 0.25");
    tick++;

  }

  printf("Continue? (y or n)\n");
  scanf("%s",question2);

  if (strcmp(question2,"y")==0 || strcmp(question2,"Y")==0){
    tickTotal = tickTotal+atoi(argv[2]);
  } else if (strcmp(question2,"n")==0 || strcmp(question2,"N")==0) {
    printf("Program Terminated\n");
    exit(1);
  }
}
}
  return (0);
}
