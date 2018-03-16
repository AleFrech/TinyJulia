TARGET=exec
C_SRCFILES=main.cpp parser.cpp lexer.cpp ast.cpp
OBJ_FILES=${C_SRCFILES:.cpp=.o}
.PHONY: clean run

$(TARGET): $(OBJ_FILES)
	g++ -std=c++11 -o $@ $(OBJ_FILES)

lexer.cpp: lexer.l
	flex -o $@ $^

parser.cpp: parser.y
	bison -Werror --report=all --defines=tokens.h -o $@ $<

%.o: %.cpp
	g++ -std=c++11 -c -o $@ $<

run: $(TARGET)
	./$(TARGET) samples/fac > main.S
	#nasm -f macho32 -o test.o --prefix _ main.S
	#gcc -m32 test.o -o test -Wl,-no_pie
	nasm -f elf32 -o asm.o main.S
	gcc -m32 -c -o pow.o pow.c
	gcc -m32 -o test asm.o pow.o

clean: 
	rm -f $(OBJ_FILES) tokens.h 
	rm -f $(TARGET)
	rm -f lexer.cpp parser.cpp parser.output