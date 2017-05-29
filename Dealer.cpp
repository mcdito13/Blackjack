#include "Dealer.hpp"

void Dealer::dealToPlayer(Player * player) {
	Card * card = deck->topCard();
	player->addToHand(card);
}

bool Dealer::hit(int opponentCardsValue) {
	if(handValue() < opponentCardsValue)
		return HIT;
	return STAY;
}