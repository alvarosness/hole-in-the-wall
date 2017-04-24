space_impact: main.o main_menu.o single_player_mode.o
	cc main.o main_menu.o single_player_mode.o -lcurses -o space_impact

main.o: main.c
	cc -c main.c

main_menu.o: main_menu.c
	cc -c main_menu.c

single_player_mode.o:
	cc -c single_player_mode.c

clean:
	rm *.o
	rm space_impact
