hole.wall: main.o main_menu.o single_player_mode.o create_map.o set_ticker.o credits.o
	cc -g main.o main_menu.o single_player_mode.o create_map.o set_ticker.o credits.o -lcurses -o hole.wall

main.o: main.c
	cc -g -c main.c

main_menu.o: main_menu.c
	cc -g -c main_menu.c

single_player_mode.o: single_player_mode.c
	cc -g -c single_player_mode.c

create_map.o: create_map.c
	cc -g -c create_map.c

set_ticker.o: set_ticker.c
	cc -g -c set_ticker.c

credits.o: credits.c
	cc -g -c credits.c
	
clean:
	rm *.o
	rm hole.wall
run:
	./hole.wall
