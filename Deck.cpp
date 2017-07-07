#include "Deck.hpp"

void Deck::init() {
	clear();
	for(int i = 0; i < NUM_DECKS; ++i)
		for(int s = Card::CLUBS; s <= Card::SPADES; ++s)
			for(int r = Card::ACE; r <= Card::KING; ++r)
				add(new Card(static_cast<Card::RANK>(r), static_cast<Card::SUIT>(s), false));
}

void Deck::deal(Hand & hand) {
	if(cards.size() > LIMIT) {
		Card * c = cards.back();
		c->flip();
		hand.add(c);
		cards.pop_back();
	}
	else
		std::cout << "Cards below limit. Need new deck.\n";
}

void Deck::dealAdditionalCards(GeneralPlayer & player) {
	while( ! player.isBusted() && player.isHitting() ) {
		deal(player);
		std::cout << player << std::endl;
		if(player.isBusted())
			std::cout << "Player bust!\n";
	}
}
