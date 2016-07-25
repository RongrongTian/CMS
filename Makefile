main:main.c fun.c sort.c CMS_Utils.c
	gcc $^ -o $@
clean:
	rm *.out *.o main -f
