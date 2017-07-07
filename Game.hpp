#ifndef _GAME_HPP
#define _GAME_HPP

#include "Deck.hpp"
#include "House.hpp"
#include "Player.hpp"

class Game
{
	public:
		Game() {}
		virtual ~Game() {}
		virtual void start() = 0;
	protected:
		std::vector<Player *> players;
};

#endif
