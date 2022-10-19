#include <iostream>
#include <array>
#include "card.h"

using namespace std;

// Default constructor
card::card(){
	suit = Hearts;
	rank = King;
	facedown = false;
}

// Parameterized constructor for  the card class to create a card with a specific suit and rank; necessary for deck creation
card::card(int card_rank, int card_suit){
	suit = card_suit;
	rank = card_rank;
}

//Returns the value of the card
int card::getValue(){
	return rank;
}


// Sets the type of Rank based on the enum value set
void card::setRank(Rank a){
	rank = a;
}

// Sets the type of suit based on the enum value set
void card::setSuit(Suit a){
	suit = a;
}

ostream &operator <<(ostream &output, const card &card) {
	output <<  Rank_array[card.rank] << Suit_array[card.suit] << endl;
	return output;
}

// Testing rank functionality
int card::getRank(){
	return rank;
}

int card::getSuit(){
	return suit;
}
