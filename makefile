all = blackjack.x

CFLAGS = -std=c++11 -g -ggdb -c -Wall 
OBJS = blackjack.o Blackjack.o GeneralPlayer.o Player.o House.o Deck.o Hand.o Card.o
HPPS = Game.hpp Blackjack.hpp GeneralPlayer.hpp Player.hpp House.hpp Deck.hpp Hand.hpp Card.hpp

blackjack.x: $(OBJS)
	g++ $(OBJS) -o blackjack.x

blackjack.o: blackjack.cpp $(HPPS)
	g++ $(CFLAGS) blackjack.cpp -o blackjack.o

Blackjack.o: Blackjack.cpp $(HPPS)
	g++ $(CFLAGS) Blackjack.cpp -o Blackjack.o

GeneralPlayer.o: GeneralPlayer.cpp GeneralPlayer.hpp
	g++ $(CFLAGS) GeneralPlayer.cpp -o GeneralPlayer.o

Player.o: Player.cpp Player.hpp
	g++ $(CFLAGS) Player.cpp -o Player.o

House.o: House.cpp House.hpp
	g++ $(CFLAGS) House.cpp -o House.o

Deck.o: Deck.cpp Deck.hpp
	g++ $(CFLAGS) Deck.cpp -o Deck.o

Hand.o: Hand.cpp Hand.hpp
	g++ $(CFLAGS) Hand.cpp -o Hand.o

Card.o: Card.cpp Card.hpp
	g++ $(CFLAGS) Card.cpp -o Card.o

clean:
	rm -f *.[ox]
