#ifndef _GENERALPLAYER_HPP
#define _GENERALPLAYER_HPP

#include "Card.hpp"
#include "Hand.hpp"

class GeneralPlayer : public Hand
{
public:
	enum { STAY = 0, HIT = 1 };
	GeneralPlayer(const string & n): name(n) {}
	virtual ~GeneralPlayer() {}
	virtual bool isHitting() const = 0;
	bool isBusted() const { return total() > 21; }
	friend ostream & operator << (ostream & os, const GeneralPlayer & player);
protected:
	std::string name;
};

#endif