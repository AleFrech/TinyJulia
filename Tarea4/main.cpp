#include <stdio.h>
#include "parser.h"
int pushInclude(char * fileName);

int main(int argc, char *argv[]){

    if (argc != 2) {
        fprintf(stderr, "Usage:%s <input file>\n", argv[0]);
        return 1;
    }

    int result = pushInclude(argv[1]);
    if(result != 0)
        return 1;
        
    auto parser = new Parser();
    auto st = parser->Parse();
    st->execute();
    delete st;
    delete parser;
}