#ifndef _BLACKJACK_HPP
#define _BLACKJACK_HPP

#include "Card.hpp"
#include "Hand.hpp"
#include "Deck.hpp"
#include "GeneralPlayer.hpp"
#include "Player.hpp"
#include "House.hpp"
#include "Game.hpp"

const int MIN_BET = 10;

class Game;

class Blackjack : public Game
{
	public:
		Blackjack();	
		virtual ~Blackjack() {}
		void addPlayer(const std::string & playerName, int buyIn);
		virtual void start();
		void playRound();
	private:
		Deck * deck;
		House * house;
};

#endif
