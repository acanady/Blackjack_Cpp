#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "card.h"

using namespace std;

#ifndef hand_H_
#define hand_H_


class hand {

private:
	int card_amount;

protected:
	vector<card> Hand_vector;

public:
	
	hand();
	void clear();
	void add_card(card);
	int getTotal();
	void display_hand();
	void display_handpartial();
};

#endif