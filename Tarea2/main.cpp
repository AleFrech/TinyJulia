#include <stdio.h>
#include "parser.h"
int main(){
    auto parser = new Parser();
    auto st = parser->Parse();
    st->execute();
    delete st;
    delete parser;
}