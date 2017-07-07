#ifndef _CARD_HPP
#define _CARD_HPP

#include <iostream>

class Card
{
	public:
		enum RANK { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
		enum SUIT { CLUBS, DIAMONDS, HEARTS, SPADES };
		Card(RANK r, SUIT s, bool faceUp): rank(r), suit(s), isFaceUp(faceUp) {}
		int value() const;
		void flip() { isFaceUp = !(isFaceUp); }
		friend std::ostream & operator << (std::ostream & os, const Card & card);
	private:
		RANK rank;
		SUIT suit;
		bool isFaceUp;
};

#endif
