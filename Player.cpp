#include "Player.hpp"

bool Player::busted() {
	for(auto card : _hand)

}


const char * Player::hand() {
	std::string hand;
	for(auto card : _hand)
		hand += card->value() + card->suit() + ' ';
	const char * h = hand.c_str();
	return h;
}

const char * Player::cashStr() {
	std::string cash = std::to_string(_currentCash);
	const char * c = cash.c_str();
	return c;
}