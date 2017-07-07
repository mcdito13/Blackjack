#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "GeneralPlayer.hpp"

class Player : public GeneralPlayer
{
	public:
		Player(const std::string & n, int buyIn): GeneralPlayer(n), cash(buyIn) {}
		virtual ~Player() {}
		virtual bool isHitting() const;
		void collect(int winnings)     { cash += winnings; }
		int bet(int amount) 	       { cash -= amount; return amount; }
	private:
		int cash;
};

#endif
