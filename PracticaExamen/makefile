TARGET=exec
C_SRCFILES=main.cpp lexer.cpp
OBJ_FILES=${C_SRCFILES:.cpp=.o}
.PHONY: clean run

$(TARGET): $(OBJ_FILES)
	g++ -std=c++11 -o $@ $(OBJ_FILES)

lexer.cpp: lexer.l
	flex -o $@ $^

%.o: %.cpp
	g++ -std=c++11 -c -o $@ $<

run: $(TARGET)
	./$(TARGET) input1.txt

clean: 
	rm -f $(OBJ_FILES)
	rm -f $(TARGET)
	rm -f lexer.cpp