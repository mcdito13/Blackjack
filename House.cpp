#include "House.hpp"

void House::flipUpCard() {
	 if( ! cards.empty() )
		 cards[0]->flip(); 
}
