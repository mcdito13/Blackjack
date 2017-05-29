#ifndef _HAND_HPP
#define _HAND_HPP

#include "Card.hpp"

class Hand
{
public:
	Hand() {}
	~Hand() {}
	void add(Card * card);
	void clear()       { _hand.clear(); }
	std::string hand() { return handStr; }
	std::string upCard();
	int value()		   { return _value; }
	int upCardValue(); 
private:
	std::vector<Card *> _hand;
	int _value;
	std::string handStr;
	int intCardValue(char v);//////////////////////////////////////////////
};

#endif