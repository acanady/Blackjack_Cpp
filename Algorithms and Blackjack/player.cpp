#include <iostream>
#include "player.h"
#include <vector>

using namespace std;

// Normal set and get functions for the player attributes


int player::getAmount_money(){
	return amount_money;
}

int player::getAmount_points(){
	return amount_points;
}

void player::setAmount_money(int money){
	amount_money = money;
}

void player::setAmount_points(int points){
	amount_points = points;
}

string player::getName(){
	return name;
}

void player::isBusted(){
	busted = true;
}

bool player::getBusted(){
	return busted;
}
