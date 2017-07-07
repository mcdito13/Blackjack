#include "Hand.hpp"

void Hand::clear() {
	if(cards.size() > 0) {
		std::vector<Card *>::iterator iter;
		for(iter = cards.begin(); iter != cards.end(); ++iter) {
			delete *iter;
			*iter = nullptr;
		}
		cards.clear(); 
	}
}

int Hand::total() const {
	if(cards.empty() || cards[0]->value() == 0) // value == 0 indicates face down
		return 0;

	bool hasAce = false;
	int total = 0;
	std::vector<Card *>::const_iterator iter;

	for(iter = cards.begin(); iter != cards.end(); ++iter) {
		total += (*iter)->value();
		if((*iter)->value() == Card::ACE)
			hasAce = true;
	}

	if(hasAce && total <= 11) // should we treat ace as 11?
		total += 10; // 10 bc we already added 1 for ace

	return total;
}
