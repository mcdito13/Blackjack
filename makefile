CFLAGS = -g -c -WALL 
OBJS = Player.o Dealer.o Card.o

demo.x: demo.cpp $(OBJS)
	g++ -ggdb -o demo.x $(OBJS)

.cpp.o:
	g++ $(CFLAGS) $< -o $@

Player.o: Player.cpp
Dealer.o: Dealer.cpp
Card.o: Card.cpp
demo.o: demo.cpp

clean:
		rm -f *.[ox]
