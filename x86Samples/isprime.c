#include <stdio.h>
// ebp - 4 = i
// ebp - 8 = flag
int isPrime(int n){
    int i , flag =0;

    for (i=2; i<n/2; ++i){
        if(n % i ==0){
            flag =1;
            break;
        }
    }
    return (flag == 0);
}

int main (){
    printf("Is prime 37 : %d\n",isPrime(37));
}