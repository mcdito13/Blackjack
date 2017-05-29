#include "Player.hpp"
#include "Dealer.hpp"
#include "Setup.hpp"

const int MINIMUM_BET = 10;

int main() {
	startup();

	auto player1 = new Player();
	auto dealer = new Dealer();

	player1->buyIn(500);
	
	while(player1->cashValue() > MINIMUM_BET) {
		int pot = player1->bet(MINIMUM_BET);

		dealer->dealToPlayer(player1);
		dealer->dealToPlayer(dealer);
		dealer->dealToPlayer(player1);
		dealer->dealToPlayer(dealer);
		char dealersFaceUp = dealer->faceUp();

		mvaddstr(5, 44, 'DEALER');
		mvaddstr(6, 44, '?' + dealersFaceUp);

		mvaddstr(8, 44, 'PLAYER 1');
		mvaddstr(8, 30, player1->cashStr());
		mvaddstr(9, 44, player1->hand());

		//  player hits 1st
		while(player1->hit(dealersFaceUp)) {
			dealer->dealToPlayer(player1);
			mv(9, 0);
			clrtoeol();
			mvaddstr(9, 44, player1->hand());
		}
		// if player didn't bust the house shows hand 
		if( ! player1->busted())
			mv(6, 0);
			clrtoeol();
			mvaddstr(6, 44, dealer->hand());
			while(dealer->hit()) {
				dealer->dealToPlayer(dealer);
				mv(6, 0);
				clrtoeol();
				mvaddstr(6, 44, dealer->hand());
		}

		// one busted but the other didn't
		if(player1->busted() && ! dealer->busted()) {
			auto winner = dealer;
			mvaddstr(12, 44, 'PLAYER 1 BUSTED!')
		}
		else if(! player1->busted() && dealer->busted()) {
			auto winner = player1;
			mvaddstr(12, 44, 'DEALER BUSTED!')
		}
		// if they both didn't bust, who won?
		else if(! player1->busted() && ! dealer->busted() && dealer->handValue() > player1->handValue())
			auto winner = dealer;
		else if(! player1->busted() && ! dealer->busted() && player1->handValue() > dealer->handValue())
			auto winner = player1;
		else
			// it was a draw!
			// money back, continue...
		if(winner == player1) {
				mvaddstr(13, 44, 'PLAYER 1 WINS!');
				player1->collectWinnings(pot * 2);
		}
		else if(winner = dealer) {
				mvaddstr(13, 44, 'DEALER WINS!');
		}
		else {
				mvaddstr(13, 44, 'DRAW');
				player->collectWinnings(pot);
		}

		dealer->clearHand();
		player1->clearHand();

		char enterToContinue;
		std::cin >> enterToContinue;

		if( ! dealer->deckIsGood())
			dealer->makeFreshStack();
	}

	terminate();
	return 0;
};