#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
#include <vector>


class Game
{
private:
    int dealer_total = 0;
    int player_total = 0;
    Deck DK;
    Player DL;
    Player PL;
public:
    Game(std::string player_name) : PL(Player(player_name)), DL(Player("Dealer")) {
        DK.shuffle();
        DL.add_card(DK.drawCard());
        DL.add_card(DK.drawCard());
        PL.add_card(DK.drawCard());
        PL.add_card(DK.drawCard());
        dealer_total = DL.hand_value();
        player_total = PL.hand_value();

    }

    void show_player_hand(){
        PL.show_hand();
    }

    int DL_total(){
        return DL.hand_value();
    }

    int PL_total(){
        return PL.hand_value();
    }

    
    void show_dealer_hand(){
        DL.show_hand();
    }

    void show_dealer_top(int num){
        DL.show_one_card(num);
    }

    bool isBusted(){
        if (PL.hand_value() > 21) return true;
        else return false;
    }

    void player_hit(){
        Card new_card = DK.drawCard();
        player_total += new_card.getValue();
        PL.add_card(DK.drawCard());
    }

};


#endif

