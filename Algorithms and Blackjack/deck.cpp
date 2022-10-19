#include <iostream>
#include <vector>
#include <array>
#include "hand.h"
#include "deck.h"
#include "card.h"
#include <time.h>
#include <iterator>
#include <algorithm>

using namespace std;

/* Creates the deck for the game. Uses a nested for loop to iterate through the Enums and Rank list to create
a deck of 52 cards*/

void deck::create_deck(){
	for (int suit = START_SUIT; suit <= END_SUIT; suit++){
		for (int rank = START_RANK; rank <= END_RANK; rank++){
			blackjack_deck.push_back(card(rank,suit));
		}
	}

}

void deck::print_deck(){
	for (int i = 0; i < 52; i++)
		cout << Rank_array [blackjack_deck[i].getRank()] << Suit_array [blackjack_deck[i].getSuit()] << endl;
	
}

//Test code that checks the size of the deck and returns it
int deck::checkDeck(){
	int fullDeck;
	fullDeck = blackjack_deck.size();
	cout << fullDeck;
	return fullDeck;
}

void deck::shuffle_deck(){
	random_shuffle(blackjack_deck.begin(), blackjack_deck.end());
}

// Uses passby reference to update the hand, without it the hand object is not updated
void deck::deal(hand& thehand){
	thehand.add_card(blackjack_deck.back());
	blackjack_deck.erase(blackjack_deck.end()-1);
}
	

ostream &operator <<(ostream &output, const deck &deck){
		for (int i = 0; i < deck.blackjack_deck.size(); i++)
			output << deck.blackjack_deck[i];
		return output;
}
