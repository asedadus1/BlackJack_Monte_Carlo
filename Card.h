#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card
{
private:
    std::string suit;
    std::string rank;
    int value;
public:
    Card(std::string cardSuit, std::string cardRank, int cardValue)
        : suit(cardSuit), rank(cardRank), value(cardValue) {}

    int getValue() const { return value;}

    std::string toString() const {
        return rank + " of " + suit;
    }
};

#endif  