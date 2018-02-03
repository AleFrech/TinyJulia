#include <stdio.h>
#include <list>
using namespace std;
int pushInclude(char * fileName);
extern list<int> spaces;
int yyparse();

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Usage:%s <input file>\n", argv[0]);
        return 1;
    }

    int result = pushInclude(argv[1]);
    if(result != 0)
        return 1;
    spaces.push_back(0);
    yyparse();
}