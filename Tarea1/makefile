TARGET=exec
C_SRCFILES=main.c parser.c lexer.c
OBJ_FILES=${C_SRCFILES:.c=.o}
.PHONY: clean run

$(TARGET): $(OBJ_FILES)
	gcc -o $@ $(OBJ_FILES)

sample1.c: lexer.l
	flex -o $@ $^

%.o: %.c 
	gcc -c -o $@ $<

run: $(TARGET)
	./$(TARGET) < input1.txt

clean:
	rm -f lexer.c
	rm -f $(TARGET)
	rm -f $(OBJ_FILES)