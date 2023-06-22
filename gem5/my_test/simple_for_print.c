#include <stdio.h>

#define NUM 100000000
void main(){
        long sum = 0;
        for (int i=0; i<NUM; i++){
                sum += i;
                if (sum%200==0){
                        printf("i=%d, sum=%ld\n",i,sum);
                }
        }
}
