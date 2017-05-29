#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <iostream>
#include "Card.hpp"
#include "Hand.hpp"

class Player
{
	public:
		enum { STAY = 0, HIT = 1 };
		Player(): _startCash(0), _currentCash(0), _endCash(0) {}
		~Player() {}

		void buyIn(int cash) 					{ _startCash = cash, _currentCash = cash; }
		void addToHand(Card * card) 			{ _hand.add(card); }
		void clearHand() 						{ _hand.clear(); }
		void collectWinnings(int winnings)		{ _currentCash += winnings; }

		int cashValue()							{ return _currentCash; }
		int bet(int amount)						{ _currentCash -= amount; return amount; }

		bool busted()      { return _hand->value() > 21; } 

		std::string hand() { return _hand->hand(); }
		int handValue()    { return _hand->value(); }

		const char * cashStr();
		
		virtual bool hit(int opponentCardsValue);

	private:
		int _startCash, _currentCash, _endCash;
	
	protected:	
		Hand * _hand;
};

#endif