#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main(){
   /* --STATEMENTS-- */
    srand (time(NULL));
    int dealer_lose = 0;
    double bet;
    Player player(100);
    char c;
    
    while (player.get_money() > 0 && dealer_lose < 900) {
        Hand my_hand;
        Hand dealer_hand;
        bool another_card = true;
        int my_count = 0;
        int dealer_count = 0;
        cout << "You have $" << player.get_money() << ". Enter bet: ";
        cin >> bet;
        while(true) {
            if (bet > player.get_money() || bet < 0) {
                cout << "Please enter a valid bet: ";
                cin >> bet;
            }
            else
                break;
        }
        bool done = false;
        while (another_card){
            my_hand.add_card();
            
            if (my_count > 0) {
                my_hand.show_new_card();
            }
            cout << "Your cards: " << endl;
            my_hand.show_card();
            cout << "Your total is " << my_hand.get_value() << ". ";
            if (my_hand.get_value() > 7.5) {
                cout << "Too bad. You lose " << bet << "." << endl;
                player.lose_money(bet);
                done = true;
                break;
            }
            cout << "Do you want another card (y/n)?";
            cin >> c;
            if (c == 'y') {
                my_count = my_count + 1;
                another_card = true;
            }
            else {
                another_card = false;
            }
        }
        if(done){
            continue;
        }
        while (dealer_hand.get_value() < 5.5) {
            dealer_hand.add_card();
            if (dealer_count > 0) {
                dealer_hand.show_new_card();
            }
            cout << "Dealer's cards:" << endl;
            dealer_hand.show_card();
            cout << "The dealer's total is " << dealer_hand.get_value()<< "." << endl << endl;
            dealer_count++;
        }
        if (dealer_hand.get_value() > 7.5) {
            cout << "You win " << bet << "." << endl << endl;
            player.win_money(bet);
            dealer_lose += bet;
        } else if (dealer_hand.get_value() < my_hand.get_value()) {
            cout << "You win " << bet << "." << endl << endl;
            player.win_money(bet);
            dealer_lose += bet;
        } else if (dealer_hand.get_value() > my_hand.get_value()) {
            cout << "Too bad. You lose " << bet << "." << endl << endl;
            player.lose_money(bet);
        } else {
            cout << "No body wins!" << endl;
        }
    }
    if (player.get_money() == 0) {
        cout << "You have $0! GAME OVER!" << endl;
        cout << "Come back when you have more money." << endl << endl;
        cout << "Bye!" << endl;
    }
    if (dealer_lose >= 900) {
        cout << "Congratulations. You beat the casino!" << endl << endl;
        cout << "Bye!" << endl;
    }
    
   return 0;
}
