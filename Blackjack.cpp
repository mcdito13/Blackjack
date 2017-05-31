#include "Blackjack.hpp"

Blackjack::Blackjack(): Game() {
	deck.init();
	deck.shuffle();
}

Blackjack::addPlayer(const std::string & playerName, int buyIn) {
	players.push_back(new Player(playerName, buyIn));
}

void Blackjack::start() {
	playRound();
}

void Blackjack::playRound() {
	int pot;
	std::vector<Player *>::iterator playerIter;
	for(playerIter = players.begin(); playerIter != players.end(); ++playerIter) {
		// assume all players want to play & have the cash for it
		pot += *playerIter->bet(MIN_BET);
	}

	for(int i = 0; i < 2; ++i) {
		for(playerIter = players.begin(); playerIter != players.end(); ++playerIter)
			deck->deal(*(*playerIter));
		deck->deal(house);
	}

	house->flipUpCard();

	for(playerIter = players.begin(); playerIter != players.end(); ++playerIter)
		std::cout << *(*playerIter) << std::endl;
	std::cout << *house << std::endl;

	for(playerIter = players.begin(); playerIter != players.end(); ++playerIter)
		deck->dealAdditionalCards(*(*playerIter));

	house->flipUpCard();
	std::cout << std:endl << *house;

	deck->dealAdditionalCards(*house);

	if(house->isBusted())
		for(playerIter = players.begin(); playerIter != players.end(); ++playerIter)
			if( ! playerIter->isBusted() ) {
				std::cout << *(*playerIter) << "wins!\n";
				(*playerIter)->collect(MIN_BET * 2);
			}
			else {
						for(playerIter = players.begin(); playerIter != players.end(); ++playerIter) {
							if( ! playerIter->isBusted() )
								if(*playerIter->total() > house->total()) {
									std::cout << *(*playerIter) << "wins!\n";
									(*playerIter)->collect(MIN_BET * 2);
								}
								else if(*playerIter->total() < house->total())
									std::cout << *(*playerIter) << "loses.\n";
								else
									std::cout << *(*playerIter) << "draws.\n";
						}
				}
				
	for(playerIter = players.begin(); playerIter != players.end(); ++playerIter) {
		*playerIter->clear();

	house->clear();
}

