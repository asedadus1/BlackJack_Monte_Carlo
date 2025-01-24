#ifndef DECK_H
#define DECK_H

#include <vector>
#include <random>
#include "Card.h"


class Deck
{
private:
    std::vector<Card> cards;
public:
    Deck(){
        std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
        int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10 , 10 , 11};

        for(int j = 0; j < 4; j++){
            for(int i = 0; i < 13; i++){
                cards.emplace_back(suits[j], ranks[i], values[i]);
            }
        }
    };
    
    void shuffle(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    }

    Card drawCard() {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }
};

#endif