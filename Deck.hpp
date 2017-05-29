#ifndef _DECK_HPP
#define _DECK_HPP

#include "Card.hpp"

const int NUM_DECKS = 5
const int SHUFFLE_AMOUNT = 5;

class Deck
{
	public:
		Deck();
		~Deck() {}
		Card * topCard();
		bool isGood();
		void makeFresh();

	private:
		int limit;
		std::vector<Card *> currentCards, freshCards;
		std::stack<Card *> currentStack, freshStack;

		void initDeck();
		void initStack();
		void shuffle();
};

#endif