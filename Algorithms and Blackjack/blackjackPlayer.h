#include <iostream>
#include <string>
#include "player.h"

#ifndef blackjackPlayer_H_
#define blackjackPlayer_H_

class blackjackPlayer:  public player {

private:
	bool playAgain;
	int amount_bet;



public:
	blackjackPlayer();
	void setamount_bet(int);
	int getamount_bet();
	void setName(string);


};
#endif