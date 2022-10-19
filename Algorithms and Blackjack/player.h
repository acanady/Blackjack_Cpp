#include <iostream>
#include "hand.h"
#include "deck.h"
#include <vector>
#include <string>


using namespace std;

#ifndef player_H_
#define player_H_

class player: public hand {
	
protected:
	int amount_points;
	int amount_money;
	string name;
	bool busted;
	

public:
	int getAmount_points();
	int getAmount_money();
	void setAmount_points(int);
	void setAmount_money(int);
	string getName();
	void  isBusted();
	bool getBusted();
};


#endif

