#include "Deck.h"
#include "Card.h"
#include <algorithm>

void Deck::Populate() {
    for (int s = DIAMONDS; s <= CLUBS; ++s){
        for (int r = ACE; r <= KING; ++r){
            Add(new Card(r,s));
        }
    }
}

Deck::Deck() {
    m_Cards.reserve(52);
    Populate();
}

void Deck::Shuffle(){
    std::random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand){
    if (!m_Cards.empty()) {
       m_Cards.back()->Flip();
       aHand.Add(m_Cards.back());
       m_Cards.pop_back();
    } else {
        std::cout << "Out of cards. Unuble to deal.";
    }
}

void Deck::AditionalCards(GenericPlayer& aGenericPlayer){
    while (!(aGenericPlayer.IsBoosted()) && aGenericPlayer.IsHitting()) {
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;
        if (aGenericPlayer.IsBoosted()) aGenericPlayer.Bust();
    }
}

