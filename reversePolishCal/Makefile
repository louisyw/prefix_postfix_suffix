objects=main.o getop.o getch.o stack.o strToNum.o

calc:$(objects)
	gcc -o calc $(objects)

main.o:calc.h
getop.o:calc.h
stack.o:calc.h
getch.o:calc.h
strToNum.o:calc.h

.PHONY:clean
clean:
	rm calc $(objects)
