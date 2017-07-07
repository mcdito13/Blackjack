#include "GeneralPlayer.hpp"

std::ostream & operator << (std::ostream & os, const GeneralPlayer & player) {
	os << player.name << ":\t";
	if(player.cards.empty())
		os << "<empty>";
	else {
		std::vector<Card *>::const_iterator iter;
		for(iter = player.cards.begin(); iter != player.cards.end(); ++iter)
			os << *(*iter) << '\t';
	}
	return os;
}
