#ifndef _DECK_HPP
#define _DECK_HPP

#include "Hand.hpp"
#include "GeneralPlayer.hpp"

const int LIMIT = 20;

class Deck : pubic Hand
{
public:
	Deck() 			{ cards.reserve(52); init();}
	virtual ~Deck() {}
	void init();
	void shuffle()  { random_shuffle(cards.begin(), cards.end()); }
	void deal(Hand & hand);
	void dealAdditionalCards(GeneralPlayer & player);
};

#endif