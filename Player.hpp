#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "GeneralPlayer.hpp"

class Player : public GeneralPlayer
{
public:
	Player(const string & n, int buyIn): GeneralPlayer(n), cash(buyIn) {}
	virtual ~Player() {}
	virtual bool isHitting() const { total() >= 17 ? STAY : HIT; }
private:
	int cash, bet;
};

#endif