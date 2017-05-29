#include "Dealer.hpp"

Dealer::Dealer() {
	_shuffleLimit = NUM_DECKS * 26;
	initDealerCards();
	for(int i = 0; i < SHUFFLE_AMOUNT; ++i)
		dealer->shuffle();
	initDealerStacks();
}

void Dealer::initDealerCards() {
	char SUITS = { 'H', 'D', 'C', 'S' };
	char VALUES = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
	for(int i = 0; i < NUM_DECKS; ++i)
		for(int j = 0; j < 4; ++j)
			for(int k = 0; k < 13; k++)
				dealerCards.push_back(new Card(SUITS[j], VALUES[k]));
	freshCards = dealerCards;
}

void Dealer::initDealerStacks() {
	cardStack.clear();
	for(auto card : dealerCards) {
		cardStack.push(card);
		freshStack.push(card);
	}
}

void Dealer::shuffle() {
	std::vector<Card *> firstHalf, secondHalf, all;
	for(unsigned int i = 0; i < dealerCards.size(); ++i)
		if(i < dealerCards.size() / 2)
			firstHalf.push_back(dealerCards[i]);
		else
			secondHalf.push_back(dealerCards[i]);
	auto half1 = firstHalf.end();
	auto half2 = seconHalf.end();
	while(half1 != half1.begin() && half2 != half2.begin()) {
		all.push_back(half1--);
		all.push_back(half2--);
	}
	dealerCards = all;
}

void Dealer::dealToPlayer(Player * player) {
	auto card = cardStack.front();
	cardStack.pop();
	player->addToHand(card);
}
