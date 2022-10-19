#include <iostream>
#include "card.h"
#include "hand.h"
#include "deck.h"
#include "player.h"
#include "blackjackPlayer.h"
#include "dealer.h"
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	
	string player1_name;
	string player2_name;
	int player1_bet;
	int player2_bet;
	char player_choice;
	int betcheck = 0;
	char newgame;
	
	system ("CLS");

	cout << "==========================================================" << endl << endl;
	cout << "Welcome  to blackjack, the rules are as follows: " << endl << endl;
	cout << "You and another player play against a dealer. The dealer will deal cards  from a deck with the following values: " << endl;
	cout << "Ace = 1, Two = 2, Three =  3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, " << endl << "Nine = 9, Ten = 10, and Jacks, Queens, and Kings = 10 as well" << endl;
	cout << "Your goal is to get as close as possible to 21 points without going over, if you do you loose the game and any money that you bet" << endl;
	cout << "Let's get started.     "; system("pause"); system("CLS");

	cout << "**********************************************************" << endl << endl;
	cout << "Hello, what is Player 1's name? ";
	cin >> player1_name;
	cout << endl << "What is Player 2's name? ";
	cin >> player2_name;

	dealer TheDealer;

	blackjackPlayer Player1;
	blackjackPlayer Player2;

	hand Player1_hand;
	hand Player2_hand;
	hand TheDealer_hand;

	deck Thedeck;

	Player1.setName(player1_name);
	Player2.setName(player2_name);

	cout << "Would you like to start a new game? (Y or Enter any key to exit) ";
	cin >> newgame;


	while (newgame == 'Y' ){
	
	system("CLS");
	cout << "**********************************************************" <<  endl;
	cout << endl << "Hello " << Player1.getName() << ", Hello " << Player2.getName() << " it's time to play" << endl << endl;
	cout << "==========================================================" << endl << endl;
	
	// Takes in the amount bet and sets it to the bet attirbute
	
	//Bug, if you input a letter it infinitely runs through the while  loop at line 86. That loop isn't even infinite but it skips cin >> player_choice, must fix in the next version.
	//Knowing more I realize this bug isn't due to a skipping, more that the value being stored at player1_bet, whatever it is for the specific letter, is probably beinmg stored as some
	//ascii value representaiton which is almost always going to be freater than Player1's money, i.e: don't in put letters.
	cout << "How much would you like to bet " << Player1.getName() << "? ";
	cin >> player1_bet;
	
	while (player1_bet > Player1.getAmount_money()){
		cout << " You don't have that much money, you only have $" << Player1.getAmount_money() << " left ";
		cin >> player1_bet;
	}


	cout << "How much would you like to bet " << Player2.getName() << "? ";
	cin >> player2_bet;

	
	while (player2_bet > Player2.getAmount_money()){
		cout << " You don't have that much money, you only have $" << Player2.getAmount_money() << " left ";
		cin >> player2_bet;
	}

	Player1.setamount_bet(player1_bet); Player2.setamount_bet(player2_bet);
	cout << endl << "==========================================================" << endl << endl;
	cout << Player1.getName() << " bets $" << Player1.getamount_bet() << endl;
	cout << endl << Player2.getName() << " bets $" << Player2.getamount_bet() << endl << endl << endl;

	//Deck and dealing
	Thedeck.create_deck();
	Thedeck.shuffle_deck();

	Thedeck.deal(Player1_hand); Thedeck.deal(Player1_hand);
	Thedeck.deal(Player2_hand); Thedeck.deal(Player2_hand);
	Thedeck.deal(TheDealer_hand); Thedeck.deal(TheDealer_hand);

	cout << "The starting cards: " << endl << "==========================================================" << endl << endl;
	
	// Shows the hand partially, yeah i know it seems hacky, but hey i created a whole new function for this, display_handpartial only partially displays the hand.
	cout << Player1.getName() << "'s starting hand is: " << "[??] "; Player1_hand.display_handpartial(); 
	cout << endl;
	cout << Player2.getName() << "'s starting hand is: " << "[??] "; Player2_hand.display_handpartial();
	cout << endl;
	cout << TheDealer.getName() << "'s starting hand is: " << "[??] ";TheDealer_hand.display_handpartial();
	cout << endl << endl;
	cout << "==========================================================" << endl << endl;
	cout << Player1.getName() << "'s turn" << endl << "----------------------------------------------------------" << endl << endl;							
	cout << Player1.getName() << "'s hand:"; Player1_hand.display_hand(); cout << "(" << Player1_hand.getTotal() << " points)" <<  endl;
	cout << "Would you like to draw? (Y or N) ";
	cin >> player_choice;

	// This While loop checks the response of the  player making sure that it's a character
	while (player_choice != 'Y' && player_choice != 'N' ){
		cout << "Please input a valid reponse ";
		cin >> player_choice;
	}
	
	// This While loop loops through the amount of times the a player wants to draw a card
	while (player_choice == 'Y' ){
		Thedeck.deal(Player1_hand);
		cout << endl << Player1.getName() << "'s current hand: "; Player1_hand.display_hand(); cout << "(" << Player1_hand.getTotal() << " points) ";
		
		Player1.setAmount_points(Player1_hand.getTotal());
		
		// if statement that checks if the player is busted or not
		if (Player1_hand.getTotal() > 21){
			cout << endl << "You're point total is greater than 21, you're BUSTED! ";
			Player1.isBusted();
			break;
		}
		
		cout << endl << "Would you like to draw another card? (Y or N) ";
		cin >> player_choice;

		// The same while loop to check valid  response, this  way it continually checks valid response, not just on the onset.
		while (player_choice != 'Y' && player_choice != 'N' ){
			cout << "Please input a valid response ";
			cin >> player_choice;
		}
	}
	

	if (player_choice == 'N' )
		cout << endl << Player1.getName() << " chooses to stay" << endl << endl;


	// Code for Player 2's turn, pretty much an exact copy of Player 1.
	cout << Player2.getName() << "'s turn" << endl << "----------------------------------------------------------" << endl << endl;
	cout << Player2.getName() << "'s hand:"; Player2_hand.display_hand(); cout << "(" << Player2_hand.getTotal() << " points)" <<  endl;
	
	cout << "Would you like to draw another card? (Y or N) ";
	cin >> player_choice;

	while (player_choice != 'Y' && player_choice != 'N' ){
		cout << "Please input a valid response ";
		cin >> player_choice;
	}
	
	while (player_choice == 'Y' ){
		Thedeck.deal(Player2_hand);
		cout << endl << Player2.getName() << "'s current hand: "; Player2_hand.display_hand(); cout << "(" << Player2_hand.getTotal() << " points) ";
		
		Player2.setAmount_points(Player2_hand.getTotal());

		if (Player2_hand.getTotal() > 21){
			cout << endl << "You're point total is greater than 21, you're BUSTED! ";
			Player2.isBusted();
			break;
		}
		
		cout << endl << "Would you like to draw another  card? (Y or N) ";
		cin >> player_choice;

		while (player_choice != 'Y' && player_choice != 'N' ){
			cout << "Please input a valid response ";
			cin >> player_choice;
		}
	
	}
		
	if (player_choice == 'N')
		cout << endl << Player2.getName() << " chooses to stay" << endl << endl;


	// The Dealers turn
	cout << TheDealer.getName() << "'s turn" << endl << "----------------------------------------------------------" << endl << endl;
	cout << TheDealer.getName() << "'s hand:"; TheDealer_hand.display_hand(); cout << "(" << TheDealer_hand.getTotal() << " points)" <<  endl;

	while (TheDealer_hand.getTotal() <= 16){
		cout << TheDealer.getName() << " chooses to draw. ";
		Thedeck.deal(TheDealer_hand);
		cout << TheDealer.getName() << "'s hand: "; TheDealer_hand.display_hand(); cout << "(" << TheDealer_hand.getTotal() << " points)" <<  endl;
	}

	//Sets dealers busted value to true if over 21
	if (TheDealer_hand.getTotal() > 21){
	cout << "Hah, the dealer is busted!" << endl;
	TheDealer.isBusted();
	}
	else
	cout << TheDealer.getName() << " chooses to stay" << endl << endl;
	
	cout << "Let's see how it turned out!" << endl << "----------------------------------------------------------" << endl << endl;

	Player1.setAmount_points(Player1_hand.getTotal() );
	Player2.setAmount_points(Player2_hand.getTotal() );
	TheDealer.setAmount_points(TheDealer_hand.getTotal() );

	// The conditions for who wins the game in case of busted
	
		// If the dealer has the most points and is not busted then the dealer wins
	
	if (TheDealer.getBusted() == false) {	
	
		if (TheDealer.getAmount_points() > Player1.getAmount_points() && TheDealer.getAmount_points() > Player2.getAmount_points() ){
			Player1.setAmount_money(Player1.getAmount_money() - Player1.getamount_bet() );
			Player2.setAmount_money(Player2.getAmount_money() - Player2.getamount_bet() );
			cout << Player1.getName() << " and " << Player2.getName() << " have lost! " << endl;
			cout << TheDealer.getName() << " wins the hand!" << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $" << Player1.getamount_bet() + Player2.getamount_bet();
		}
	
		else if (Player1.getBusted() == true && Player2.getBusted() == true){
			Player1.setAmount_money(Player1.getAmount_money() - Player1.getamount_bet() );
			Player2.setAmount_money(Player2.getAmount_money() - Player2.getamount_bet() );
			cout << Player1.getName() << " and " << Player2.getName() << " are both busted! " << endl;
			cout << TheDealer.getName() << " wins the hand!" << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player1.getamount_bet() + Player2.getamount_bet() ); cout << TheDealer.getAmount_money();
		}

		else if (Player1.getAmount_points() == 21 && TheDealer.getAmount_points() == 21 && (Player2.getAmount_points() < 21 ) ){
			Player1.setAmount_money(Player1.getAmount_money() + Player1.getamount_bet() ); //Player1 gets money
			Player2.setAmount_money(Player2.getAmount_money() - Player2.getamount_bet() ); //Player2 looses money
			cout << Player2.getName() << " lost, they loose: $" << Player2.getamount_bet() << endl;
			cout << Player1.getName() << " wins, they recieve: $" << Player2.getamount_bet() << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player2.getamount_bet() ); cout << TheDealer.getAmount_money();
		}

		else if (Player2.getAmount_points() == 21 && TheDealer.getAmount_points() == 21 && Player1.getAmount_points() < 21){
			Player2.setAmount_money(Player2.getAmount_money() + Player2.getamount_bet() ); //Player2 gets money
			Player1.setAmount_money(Player1.getAmount_money() - Player1.getamount_bet() ); //Player1 looses money
			cout << Player1.getName() << " lost, they loose: $" << Player1.getamount_bet() << endl;
			cout << Player2.getName() << " wins, they recieve: $" << Player2.getamount_bet() << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player2.getamount_bet() ); cout << TheDealer.getAmount_money();
		}
	}


	//  If the dealer is busted all other if statements run to check the outcomes of player 1 and 2

	if (TheDealer.getBusted() == true){
		
		if (Player1.getBusted() == true && Player2.getBusted() == true){
			Player1.setAmount_money(Player1.getAmount_money() - Player1.getamount_bet() );
			Player2.setAmount_money(Player2.getAmount_money() - Player2.getamount_bet() );
			cout << Player1.getName() << " and " << Player2.getName() << " are both busted! " << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player1.getamount_bet() + Player2.getamount_bet() ); cout << TheDealer.getAmount_money();
		}

		else if (Player1.getBusted() == true){
			Player1.setAmount_money(Player1.getAmount_money() - Player1.getamount_bet() ); // Player1 looses money
			Player2.setAmount_money(Player2.getAmount_money() + Player2.getamount_bet() ); // Player 2 gets money
			cout << Player1.getName() << " is busted, they loose: $" << Player1.getamount_bet() << endl;
			cout << Player2.getName() << " wins, they recieve: $" << Player2.getamount_bet() << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player1.getamount_bet() ); cout << TheDealer.getAmount_money();
		}

		else if (Player2.getBusted() == true){
			Player2.setAmount_money(Player2.getAmount_money() - Player2.getamount_bet () ); // Player 2 looses money
			Player1.setAmount_money(Player1.getAmount_money() + Player1.getamount_bet() ); // Player 1 gets money
			cout << Player2.getName() << " is busted, they loose: $" << Player2.getamount_bet() << endl;
			cout << Player1.getName() << " wins, they recieve: $" << Player2.getamount_bet() << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player2.getamount_bet() ); cout << TheDealer.getAmount_money();
		}
	
		// Conditions for who wins the game under most points rule
		else if (Player1.getAmount_points() > Player2.getAmount_points() && Player1.getBusted() == false){
			Player2.setAmount_money(Player2.getAmount_money() - Player2.getamount_bet() ); // Player 2 looses money
			Player1.setAmount_money(Player1.getAmount_money() + Player1.getamount_bet() ); // Player 1 gets money
			cout << Player2.getName() << " lost, they loose: $" << Player2.getamount_bet() << endl;
			cout << Player1.getName() << " wins, they recieve: $" << Player2.getamount_bet() << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player2.getamount_bet() ); cout << TheDealer.getAmount_money();
		}

		else if (Player2.getAmount_points() > Player1.getAmount_points() && Player2.getBusted() == false){
			Player1.setAmount_money(Player1.getAmount_money() - Player1.getamount_bet() ); // Player1 looses money
			Player2.setAmount_money(Player2.getAmount_money() + Player2.getamount_bet() ); // Player 2 gets money
			cout << Player1.getName() << " lost, they loose: $" << Player1.getamount_bet() << endl;
			cout << Player2.getName() << " wins, they recieve: $" << Player2.getamount_bet() << endl << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
			cout << TheDealer.getName() << " is up $"; TheDealer.setAmount_money(TheDealer.getAmount_money() + Player1.getamount_bet() ); cout << TheDealer.getAmount_money();
		}

		else {
			cout << "It's a draw, nothing happens" << endl;
			cout << Player1.getName() << "'s current balance: $" << Player1.getAmount_money() << endl;
			cout << Player2.getName() << "'s current balance: $" << Player2.getAmount_money() << endl;
		}

	}



	// Clears the hands of player 1 and player 2 and Dealer

	Player1_hand.clear();
	Player2_hand.clear();
	TheDealer_hand.clear();

	cout << endl << endl;

	system("pause");

	cout << endl << "Would you like to play again? ( Y or N) ";
	cin >> newgame;
	

	}// End of While loop

}
