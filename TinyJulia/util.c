int power(int a, int b) {
    int res = 1;
    for (int i = 0; i < b; i++, res *= a);
    return res;
}

int shiftR(int x, int y){
    return x >> y;
}

int shiftL(int x, int y){
    return x << y;
}