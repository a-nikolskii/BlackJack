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

std::ostream& operator<< (std::ostream& out, const Card& card) {
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const std::string SUITS[] = { "c", "d", "h", "s" };

    if (card.m_isFaceUp) {
        out << RANKS[card.m_rank] << SUITS[card.m_suit];
    }
    else {
        out << "XX";
    }
    return out;
}
