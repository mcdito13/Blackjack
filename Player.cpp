#include "Player.hpp"

const char * Player::cash() {
	std::string cash = std::to_string(_currentCash);
	const char * c = cash.c_str();
	return c;
}

bool Player::hit(int opponentCardsValue) {
	if(opponentCardsValue <= 8)
		return HIT;
	return STAY;
}