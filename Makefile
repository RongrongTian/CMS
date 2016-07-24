main:main.c fun.c sort.c
	gcc $^ -o $@
clean:
	rm *.out *.o main -f
