#include "Card.h"

Card::Card (int rank, int suit) : m_rank(rank), m_suit(suit) {}

Card::Card (int rank, int suit, bool isFaceUp) : m_rank(rank), m_suit(suit), m_isFaceUp(isFaceUp) {}

int Card::GetValue () const {
    if (m_isFaceUp) return m_rank;
    else {
        std::cout << "Card is not FaceUp!" <<std::endl;
        return 0;
    }
}

int Card::GetSuit () const {
    if (m_isFaceUp) return m_suit;
    else {
        std::cout << "Card is not FaceUp!" <<std::endl;
        return 0;
    }
}

void Card::Flip() {m_isFaceUp = true;}
