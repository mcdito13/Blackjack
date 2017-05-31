#include "GeneralPlayer.hpp"

ostream & operator << (ostream & os, const GeneralPlayer & player) {
	os << player.name << ":\t";
	if(player.cards.empty())
		os << "<empty>";
	else {
		vector<Card *> const_iterator iter;
		for(iter = player.cards.begin(); iter != player.cards.end(); ++iter)
			os << *(*card) << '\t';
	}
	return os;
}