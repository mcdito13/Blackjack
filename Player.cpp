#include "Player.hpp"

bool Player::isHitting() const { 
	char choice = ' ';
	std::cin >> choice;
	return choice == 'y' ? true : false; }
//return total() >= 17 ? false : true; }
