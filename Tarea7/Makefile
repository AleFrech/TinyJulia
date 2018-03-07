TARGET=gcsample3
EXPR_PARSER_SRC=expr_parser.cpp
EXPR_LEXER_SRC=expr_lexer.cpp
SRCFILES=$(EXPR_PARSER_SRC) $(EXPR_LEXER_SRC) ast.cpp main.cpp
OBJ_FILES=${SRCFILES:.cpp=.o}
.PHONY: clean
.SUFFIXES:

$(TARGET): $(OBJ_FILES)
	g++ -g -o $@ $(OBJ_FILES)

$(EXPR_LEXER_SRC): expr.l
	flex -o $@ $^

$(EXPR_PARSER_SRC): expr.y
	bison -rall --defines=tokens.h -o $@ $<

%.o:%.cpp
	g++ -std=c++11 -g -c -o $@ $<

run: $(TARGET)
	./$(TARGET) input1.txt > main.S
	nasm -f elf32 -o asm.o main.S
	gcc -m32 -o test asm.o

clean:
	rm -f $(EXPR_PARSER_SRC) $(EXPR_LEXER_SRC)
	rm -f *.o
	rm -f tokens.h
	rm -f *.output
	rm -f $(TARGET)
