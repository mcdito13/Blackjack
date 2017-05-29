#include "Hand.hpp"

void Hand::add(Card * card) {
	_hand.push_back(card);
	handStr += card->value() + card->suit() + ' ';
	if(_hand.size() == 2)
		calculateInitialValue();
	if(_hand.size() > 2)
		updateValue();
}

void calculateInitialValue() {	
	int cv1 = intCardValue(_hand[0]->value());
	int cv2 = intCardValue(_hand[1]->value());
	if(cv1 == 1)
		cv1 += 10;
	if(cv2 == 1 && cv1 != 1)
		cv2 += 10;
	_value = cv1 + cv2;
}

void updateValue() {}
	int cv = intCardValue(_hand[_hand.size() - 1]->value());
	_value += cv;
	if(cv == 1 && _value + 10 <= 21)
		_value += 10;
}

int intCardValue(char v) {
	switch(v) {
		case('A') : return 1;
		case('2') : return 2;
		case('3') : return 3;
		case('4') : return 4;
		case('5') : return 5;
		case('6') : return 6;
		case('7') : return 7;
		case('8') : return 8;
		case('9') : return 9;
		case('0') : return 10;
		case('J') : return 10;
		case('Q') : return 10;
		case('K') : return 10;
	}
}

std::string Hand::upCard() {
	Card * c = _hand[1];
	std::string upCard += c->value() + c->suit();
	return upCard; 
}