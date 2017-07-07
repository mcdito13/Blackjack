#include "Blackjack.hpp"
#include "Game.hpp"
#include "GeneralPlayer.hpp"
#include "Player.hpp"
#include "House.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Card.hpp"

int main() {

	Blackjack * blackjack = new Blackjack();
	blackjack->addPlayer("Mike", 50);
	blackjack->start();

	return 0;
}

