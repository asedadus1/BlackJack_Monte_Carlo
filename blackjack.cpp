#include <iostream>
#include "Card.h"
#include "Deck.h" 
#include "Player.h"
#include "Game.h"


using namespace std;
int main(){
    int num;
    cout << "wellcom to blackjack" << endl;
    Game test("Ased");
    test.show_dealer_top(1);
    while(!test.isBusted()){
        test.show_player_hand();
        std::cout << "Enter 1 for HIT or 2 for STAND: ";
        std::cin >> num; 



        if(num == 1){
            test.player_hit();
        }else if(num == 2){
            break;
        }else{
            std::cout << "Enter valid number 1 for HIT or 2 for STAND: ";
            std::cin >> num; 
        }
    }

    cout << "==== Final result =====" << endl;
    test.show_dealer_hand();
    cout << "Dealer val = " << test.DL_total() << endl;
    test.show_player_hand();
    cout << "Player val = " << test.PL_total() << endl;
    if(test.isBusted()){
        cout << "Player Lost" << endl;
    }else {
        cout << "Player Won!!!" << endl;
    }
    


    return 0;
}