#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include "Card.h"

class Player
{
private:
    std::string name;
    std::vector<Card> hand;
public:
    Player(std::string player_name) : name(player_name){}

    void add_card(Card card){ hand.push_back(card);}

    int hand_value(){
        int total = 0;
        int ace_count = 0;
        for(int i =0; i < hand.size(); i++){
            int val = hand[i].getValue();
            if(val == 11){
                ace_count++;
            }
            total += val;
        }
        while(total >= 21 && ace_count != 0){
            ace_count--;
            total -= 10;
        }
        return total;
    }

    void show_hand(){
        std::cout << "==" << name << "==" << std::endl; 
        for(const auto card: hand){
            std::cout<< card.toString() << std::endl;
        }
    } 

    void show_one_card(int num){
        for(int i = 0; i < num; i++){
            std::cout << hand[i].toString() << std::endl;
        }
    }

};


#endif