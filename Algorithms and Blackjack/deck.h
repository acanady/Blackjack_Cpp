#include<iostream>
#include "hand.h"
#include "card.h"
#include <vector>

using namespace std;

#ifndef deck_H_
#define deck_H_

class deck: public hand {

protected:
	vector <card> blackjack_deck;

public:
	void create_deck();
	void shuffle_deck();
	void deal(hand&);
	void print_deck();
	
	int checkDeck();

	friend ostream &operator << (ostream &, const deck & );

};

#endif