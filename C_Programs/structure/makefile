all:app exe
app:app.c fundef.c
	gcc -c app.c fundef.c 
exe:app.o fundef.o
	gcc app.o fundef.o -o exe
	./exe
clean:
	rm -rf app.o fundef.o exe
