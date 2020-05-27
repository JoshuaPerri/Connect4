connect4: connect4.c 
	gcc -o connect4 connect4.c functions.c

clean:
	rm connect4

reload:
	make clean
	make connect4