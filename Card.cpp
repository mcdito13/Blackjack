#include "Card.hpp"

int Card::value() const {
	int v = 0; // face down card is 0
	if(isFaceUp){
		v = rank;
		if(v > 10)
			v = 10;
	}
	return v;
}

std::ostream & operator << (std::ostream & os, const Card & card) {
	const std::string ranks[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", 
		"10", "J", "Q", "K" };
	const std::string suits[] = { "C", "D", "H", "S" };

	if(card.isFaceUp)
		os << ranks[card.rank] << suits[card.suit];
	else
		os << "XX";

	return os;
}
