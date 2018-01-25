TARGET=sample1
C_SRCFILES=main.c expr_parser.c sample1.c
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
	rm -f sample1.c
	rm -f $(TARGET)
	rm -f $(OBJ_FILES)