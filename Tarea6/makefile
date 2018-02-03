TARGET=exec
C_SRCFILES=parser.cpp lexer.cpp main.cpp ast.cpp
OBJ_FILES=${C_SRCFILES:.cpp=.o}
.PHONY: clean run

$(TARGET): $(OBJ_FILES)
	g++ -std=c++11 -o $@ $(OBJ_FILES)

lexer.cpp: lexer.l
	flex -o $@ $^

parser.cpp: parser.y
	bison --defines=tokens.h -o $@ $<

%.o: %.cpp
	g++ -std=c++11 -c -o $@ $<

run: $(TARGET)
	./$(TARGET) /home/alejandrofrech/Desktop/compiladores2/Tarea6/samples/ArithOperators.py

clean:
	rm -f lexer.cpp parser.cpp tokens.h
	rm -f $(TARGET)
	rm -f $(OBJ_FILES)