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
    int f[5];
    int fcount  = factors(10,5,f);
    for(int i=0;i<fcount;i++){
        printf("%d\n",f[i]);
    }
}