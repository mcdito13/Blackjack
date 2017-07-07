#ifndef _HOUSE_HPP
#define _HOUSE_HPP

#include "GeneralPlayer.hpp"

class House : public GeneralPlayer
{
	public:
		House(): GeneralPlayer("House") {}
		virtual ~House() {}
		virtual bool isHitting() const { return total() <= 16; }
		void flipUpCard();
};

#endif
