TARGET=exec
TESTS=Arithmetic Arrays Bitwise BubbleSort comments Factorial functions helloworld if printFormat QuickSort recursion Relational several while_break while
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
	./$(TARGET) samples/comments > main.S
	#nasm -f macho32 -o test.o --prefix _ main.S
	#gcc -m32 test.o -o test -Wl,-no_pie
	nasm -f elf32 -o asm.o main.S
	gcc -m32 -c -o util.o util.c
	gcc -m32 -o test asm.o util.o


check: $(TARGET) $(TESTS)

$(TESTS):
	./$(TARGET) UnitTesting/tests/$@.jl > run.asm
	nasm -felf run.asm
	gcc -m32 -c -o util.o util.c
	gcc -m32 -o run run.o util.o
	./run > UnitTesting/generated/$@
	./UnitTesting/compare.o UnitTesting/results/$@ UnitTesting/generated/$@
	rm -f run.asm run.o run
	rm -f UnitTesting/generated/$@

clean: 
	rm -f $(OBJ_FILES) tokens.h 
	rm -f $(TARGET)
	rm -f lexer.cpp parser.cpp parser.output