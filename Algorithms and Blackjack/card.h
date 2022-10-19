#include <iostream>
#include <array>
#include <string>



using namespace std;

#ifndef card_H_
#define card_H_

enum Rank{Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
const Rank START_RANK = Ace;	// use if for iteration
const Rank END_RANK = King;

enum Suit{ Clubs, Diamonds, Spades, Hearts};
const Suit START_SUIT = Clubs;
const Suit END_SUIT = Hearts;

// An array of strings that will be indexed by the enums
// "Filler" acts as a space holder since the array starts at place 0 and the enum starts at place 1, this is for easy understanding of what rank a card has
const string Rank_array[] = {"Filler","A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const string Suit_array[] = {"C","D","S","H"};

/*An array of integers indexed by the Rank enum. It's starts at 0 because Ace 
starts  at 1, this returns the value of the card type in the getValue() function*/



class card{

private:
	int value;
	bool facedown;
	int suit;
	int rank;
	

public:
	card();
	card(int, int);
	bool isfacedown();
	int getValue();
	void setRank(Rank);
	void setSuit(Suit);
	int getRank();
	int getSuit();
	
	
		// Ostream operator that connects to the card class
	friend ostream &operator << (ostream &, const card &);
};

#endif