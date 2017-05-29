#include "Deck.hpp"

bool testing = true;

Deck::Deck() {
	limit = NUM_DECKS * 26;
	initDeck();
	for(int i = 0; i < SHUFFLE_AMOUNT; ++i)
		shuffle();
	initStacks();
}

void Deck::makeFresh() {
	currentCards = freshCards;
	for(int i = 0; i < SHUFFLE_AMOUNT; ++i)
		shuffle();
}

Card * Deck::topCard() {
	Card * topCard = currentStack.top();
	currentStack.pop();
	return topCard;
}

void Deck::initDeck() {
	char SUITS = { 'H', 'D', 'C', 'S' };
	char VALUES = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
	for(int i = 0; i < NUM_DECKS; ++i)
		for(int j = 0; j < 4; ++j)
			for(int k = 0; k < 13; k++)
				currentCards.push_back(new Card(SUITS[j], VALUES[k]));
	freshCards = currentCards;

	if(testing)
		for(auto card : currentCards)
			std::cout << card->value() + card->suit() << endl;
}

void Deck::initStack() {
	for(auto card : currentCards) {
		currentStack.push(card);
		freshStack.push(card);
	}
}

void Deck::shuffle() {
	std::vector<Card *> firstHalf, secondHalf, all;
	for(unsigned int i = 0; i < currentCards.size(); ++i)
		if(i < currentCards.size() / 2)
			firstHalf.push_back(currentCards[i]);
		else
			secondHalf.push_back(currentCards[i]);
	auto half1 = firstHalf.end();
	auto half2 = seconHalf.end();
	while(half1 != half1.begin() && half2 != half2.begin()) {
		all.push_back(half1--);
		all.push_back(half2--);
	}
	currentCards = all;
}