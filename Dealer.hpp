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
		Dealer() { _hand = new Hand(); deck = new Deck(); }
		~Dealer() {}
		void dealToPlayer(Player * player);
		void dealToSelf();
		std::string upCard() { return _hand->upCard(); }
		bool hit(int opponentCardsValue);
		bool deckIsGood() { return deck->isGood(); }
	private:
		Hand * _hand;
		Deck * deck;
};

#endif