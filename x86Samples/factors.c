#include <stdio.h>

int factors (int number, int count,int f[]){
    int index =0;
    for(int i=1;i<=number;++i){
        if(number % i ==0){
            f[index++] =i;
            if(index == count)
                break;
        }
    }
    return index;
}

int main (){
    int f[10];
    int fcount  = factors(10,2,f);
    for(int i=0;i<fcount;i++){
        printf("%d\n",f[i]);
    }
}