#include <iostream>
#include <string>
#include <vector>
#include "hand.h"
#include "card.h"
#include <numeric>

using namespace std;

int total_value;

hand::hand(){ // returns the number  of cards as it pertains to the size of  the vector
	card_amount = Hand_vector.size();

}

void hand::add_card(card the_card ){ // adds a card to the hand, not sure how to do this; i think its right now though.
	Hand_vector.push_back(the_card);
}

void hand::clear(){ // completely clears the hand using the clear command
	Hand_vector.clear();
}

int hand::getTotal(){
	
	int total_value;
	vector <int> Totalvalue_vector;
	
	for(unsigned int i = 0; i < Hand_vector.size(); i++){ // for loop assigning every value in the hand to a vector named Totalvalue_vector to be totaled using the getValue function to return the cards value
		Totalvalue_vector.push_back(Hand_vector[i].getValue());
	}

	total_value = accumulate(Totalvalue_vector.begin(),Totalvalue_vector.end(), 0); // Adding all the elements in Totalvalue_vector using the accumulate member function
	
	return total_value;
	
}

void hand:: display_hand(){
	for (int i = 0; i < Hand_vector.size(); i++){
		cout << "[" << Rank_array[Hand_vector[i].getRank()] << Suit_array[Hand_vector[i].getSuit()] << "] ";
	}
}
 // Was having trouble with the whole [??] Thing so i implemented handpartial, it only displays the second card in the hand
void hand:: display_handpartial(){
	for (int i = 1; i < Hand_vector.size(); i++){
		cout << "[" << Rank_array[Hand_vector[i].getRank()] << Suit_array[Hand_vector[i].getSuit()] << "] ";
	}
}





	




