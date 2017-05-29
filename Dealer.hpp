#ifndef _DEALER_HPP
#define _DEALER_HPP

#include <iostream>
#include <stack>

#include "Player.hpp"
#include "Card.hpp"

const int NUM_DECKS = 5
const int SHUFFLE_AMOUNT = 5;

class Dealer: public Player
{
	public:
		Dealer();
		void shuffle();
		void dealToPlayer(Player * player);
		char & faceUp() { return hand[2]->value(); }
		bool hit();
		bool deckIsGood() { return cardStack.size() > _shuffleLimit; }
		void makeFreshStack() { cardStack = freshStack; }
	private:
		Card _faceUp;
		int _shuffleLimit;
		std::vector<Card *> dealerCards, freshCards;
		std::stack<Card *> cardStack, freshStack;
		void initDealerCards();
		void initDealerStacks();
};

#endif