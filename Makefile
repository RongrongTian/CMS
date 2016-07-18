main:main.c fun.c
	gcc $^ -o $@
clean:
	rm *.out *.o main -f
