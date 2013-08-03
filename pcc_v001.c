n

#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true 0
#define false -1
#define ARRAY_H  4
#define ARRAY_V 8
#define CODE_NUMBER 8

int array[4][8] = {
    {1,0,1,0,0,1,0,1},
    {0,0,1,1,0,1,1,0},
    {1,1,0,0,1,1,0,0},
    {1,0,1,0,1,0,1,1},
  };

int array2[4][8] = {
    {1,0,1,0,0,1,0,0},
    {1,0,1,1,0,1,1,0},
    {1,1,0,0,1,1,0,1},
    {1,0,1,0,1,0,1,1},
  };
int odd_pcc[8] = {0};
bool vertical_odd_code(){
  int i,j;

    for( j = 0 ;  j < ARRAY_V ; j ++){
      for( i = 0 ; i < ARRAY_H ; i ++){
        if(array[i][j] == 1){
          odd_pcc[j] ++;
        }
      }
      if(odd_pcc[j] %2 != 0 ){
        odd_pcc[j] = 0;
      }else{
        odd_pcc[j] = 1;
      }
    }
}

void printf_odd_vertical(){
  int i;
  printf("odd_vertical_code \r\n");
  for(i = 0 ; i < CODE_NUMBER ; i ++){
    printf("%d ",odd_pcc[i]);
  }
  printf("\n");
}
void vertical_odd_decode(int *parray,int *odd_code){
  int ti,tj;
  printf("\n");
  int toddcode[8];
  int *tmpp;
  tmpp = parray;
  for(ti = 0 ;  ti < ARRAY_V ; ti ++){
    toddcode[ti] = 0;
    for(tj = 0 ; tj < ARRAY_H ; tj ++ ){
      if(*(tmpp+tj*8 ) == 1){
        toddcode[ti] ++;
      }
    }
    if(toddcode[ti] % 2 != 0){
      toddcode[ti] = 0;
    }else{
      toddcode[ti] = 1;
    }
    tmpp +=1;
    if(toddcode[ti] == *(odd_code+ti)){
      continue;
    }else{
      break;
    }
  }

  if(ti == ARRAY_V ){
    printf("odd_is ok \r\n");
  }else{
    printf("odd_is err \r\n");
  }
  //printf("\n");
}
int main(void){
  vertical_odd_code();
  printf_odd_vertical();
  vertical_odd_decode(array,odd_pcc);
  vertical_odd_decode(array2,odd_pcc);
  return 0;
}
