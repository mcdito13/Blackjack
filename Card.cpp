#include "Card.hpp"

Card & Card::operator = (const Card & other)
{
	if (this == &other)
		return * this;
	_value = other._value;
	_suit = other._suit;
	return * this;
}
