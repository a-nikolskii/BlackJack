#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand {
private:
    void Populate();
public:
    Deck();
    void Shuffle();
    void Deal(Hand& aHand);
    void AditionalCards (GenericPlayer& aGenericPlayer);
    //~Deck();
};
