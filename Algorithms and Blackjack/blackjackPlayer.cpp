#include <iostream>
#include "player.h"
#include "deck.h"
#include "blackjackPlayer.h"
#include "card.h"
#include <string>

using  namespace std;

blackjackPlayer::blackjackPlayer(){
	name = "Carlos";
	amount_points = 0;
	amount_money = 100;
	amount_bet = 0;
	busted = false;
}

void blackjackPlayer::setamount_bet(int bet){
	amount_bet = bet;
}

int blackjackPlayer::getamount_bet(){
	return amount_bet;
}

void blackjackPlayer::setName(string playername){
	name = playername;
}




