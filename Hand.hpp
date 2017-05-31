#ifndef _HAND_HPP
#define _HAND_HPP

#include "Card.hpp"

class Hand
{
public:
	Hand() 				  { cards.reserve(10); }
	virtual ~Hand() 	  { clear(); }
	void add(Card * card) { cards.push_back(card); }
	void clear();
	int total() const;
protected:
	std::vector<Card *> cards;
};

#endif