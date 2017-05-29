#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <iostream>
#include "Card.hpp"

class Player
{
	public:
		Player(): _startCash(0), _currentCash(0), _endCash(0) {}
		void buyIn(int cash) 					{ _startCash = cash, _currentCash = cash; }
		void addToHand(Card * card) 			{ hand.push_back(card); }
		virtual bool hit(char dealersCard);
		void clearHand() 						{ hand.clear(); }
		int numCards()							{ return hand.size(); }
		const char * hand();
		int cashValue()							{ return _currentCash; }
		const char * cashStr();
		int bet(int amount)						{ _currentCash -= amount, return amount; }
		void collectWinnings(int winnings)		{ _currentCash += winnings; }
		bool busted(); // did player get over 21 in their hand?

	private:
		int _startCash, _currentCash, _endCash;
	
	protected:	
		std::vector<Card*> hand;
};

#endif