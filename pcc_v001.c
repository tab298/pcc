#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true 0
#define false -1
#define ARRAY_H  4
#define ARRAY_V 8
#define CODE_NUMBER 8

#define ARRAY_4  4
#define ARRAY_8 8

int array[4][8] = {
  {1,0,1,0,0,1,0,1},
  {0,0,1,1,0,1,1,0},
  {1,1,0,0,1,1,0,0},
  {1,0,1,0,1,0,1,1},
};

int array2[4][8] = {
  {1,0,1,0,0,1,0,0},
  {0,0,1,1,0,1,1,0},
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

void horizontal_odd_code(int *parray,int *odd_code){

  int ti,tj;
  int *ptmp;
  printf("horizontal---->>>>\n");
  int t_code[8];
  ptmp = parray;
  for(ti = 0 ; ti < ARRAY_4 ; ti++){
    t_code[ti] = 0;
    for(tj = 0 ; tj < ARRAY_8 ; tj++){
      if(*(ptmp + tj ) == 1){
        t_code[ti]++;
      }
    }

    ptmp += 8;
    if(t_code[ti] % 2 != 0){
      t_code[ti] = 0;
    }else{
      t_code[ti] = 1;
    }
    printf("%d ",t_code[ti]);
    *(odd_code+ti) = t_code[ti];
  }
  printf("\n");

}

int is_equal_two_array(int *src1,int *src2,int size){
  int ti;
  for(ti  = 0 ; ti < size ; ti ++){
    if(*(src1 + ti ) == *(src2 + ti)){
      continue;
    }else{
      break;
    }
  }
  if(ti == size){
    return 0;
  }else{
    return -1;
  }
}
int main(void){
  int odd_code_h[4];
  int odd_err_code_h[4];
  printf("产生垂直校验码\n");
  vertical_odd_code();
  printf_odd_vertical();

  printf("检验垂直校验码 \r\n");
  printf("正确原码--->>>");

  vertical_odd_decode(array,odd_pcc);

  printf("错误原码----->>>");
  vertical_odd_decode(array2,odd_pcc);

  printf("产生水平校验码\n");
  horizontal_odd_code(array,odd_code_h);

  printf("检验水平校验码 \r\n");
  horizontal_odd_code(array,odd_err_code_h);
  if(is_equal_two_array(odd_err_code_h,odd_code_h,4) == 0){
    printf("检验水平校验码 相等 \r\n");
  }else{
    printf("检验水平校验码 错误 \r\n");
  }
  return 0;
}
