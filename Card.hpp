#ifndef _CARD_HPP
#define _CARD_HPP

#include <iostream>
#include <fstream>

class Card
{
	public:
		Card(char s, char v): _suit(s), _value(v) {}
		~Card () {}
		Card & operator = (const Card & other);
		//void suit(char s);
		char suit() { return _suit; }
		//void value(char v);
		char value() { return _value; }
	private:
		char _suit, _value;
};

#endif
