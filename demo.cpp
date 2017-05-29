#include <iostream>
#include "Card.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"

const int MINIMUM_BET = 10;

int main() {

	Player * player1 = new Player();
	Dealer * dealer = new Dealer();

	player1->buyIn(500);

	int _round = 0;
	
	while(player1->cashValue() > MINIMUM_BET) {
		_rount++;
		std::cout << "ROUND : " << _round << std::endl;
		int pot = player1->bet(MINIMUM_BET);

		dealer->dealToPlayer(player1);
		dealer->dealToSelf();
		dealer->dealToPlayer(player1);
		dealer->dealToSelf();

		int upCardValue = dealer->upCardValue()

		std::cout << "Dealers upCard : " << dealer->upCard() << std::endl;
		std::cout << "Player 1 cards : " << player1->hand() << std::endl;
		std::cout << "Player 1 cash  : " << player1->cashValue() << std::endl;

		//  player hits 1st
		while(player1->hit(upCardValue)) {
			dealer->dealToPlayer(player1);
			std::cout << "Player 1 hits, hand : " << player1->hand() << std::endl;
		}
		// if player didn't bust, the dealer shows hand
		if( ! player1->busted()) {
			std::cout << "Player 1 holds.\n"
			std::cout << "Dealer shows hand : " << dealer->hand() << std:endl;
			while(dealer->hit(player1->handValue())) {
				dealer->dealToSelf();
				std::cout < "Dealer hits, hand : " << dealer->hand()<< std::endl;
			}
		}

		char winner = 'O';
		// one busted but the other didn't
		if(player1->busted() && ! dealer->busted()) {
			std::cout << "Player 1 Busted -- Dealer Wins!\n\n"
			winner = 'D';
		}
		else if(! player1->busted() && dealer->busted()) {
			std::cout << "Dealer Busted -- Player 1 Wins!\n\n"
			winner = '1'
		}
		// if they both didn't bust, who won?
		else if(! player1->busted() && ! dealer->busted() && dealer->handValue() > player1->handValue()) {
			std::cout << "Dealer Wins!\n\n"
			winner = 'D';
		}
		else if(! player1->busted() && ! dealer->busted() && player1->handValue() > dealer->handValue()) {
			std::cout << "Player 1 Wins!\n\n"
			winner = '1';
		}
		else
			std::cout << "Draw!\n\n"

		if(winner == '1') {
				player1->collectWinnings(pot * 2);
		}
		if(winner == 'O') {
				player->collectWinnings(pot);
		}

		dealer->clearHand();
		player1->clearHand();

		char enterToContinue;
		std::cin >> enterToContinue;

		if( ! dealer->deckIsGood())
			dealer->makeFreshStack();
	}

	return 0;
};