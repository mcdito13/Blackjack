#ifndef _DECK_HPP
#define _DECK_HPP

#include "Hand.hpp"
#include "GeneralPlayer.hpp"
#include <vector>
#include <algorithm>

const int LIMIT = 20, NUM_DECKS = 5;

class Deck : public Hand
{
	public:
		Deck():Hand()	{ cards.reserve(52 * NUM_DECKS); init();}
		virtual ~Deck() {}
		void init();
		void shuffle()  { random_shuffle(cards.begin(), cards.end()-1); }
		void deal(Hand & hand);
		void dealAdditionalCards(GeneralPlayer & player);
};

#endif
