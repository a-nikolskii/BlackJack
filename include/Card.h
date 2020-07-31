#include <iostream>

enum Rank {
    ACE =    1,
    TWO =    2,
    THREE =  3,
    FOUR =   4,
    FIVE =   5,
    SIX =    6,
    SEVEN =  7,
    EIGHT =  8,
    NINE =   9,
    JACK =  10,
    QUEEN = 10,
    KING =  10,
};

enum Suit {
    DIAMONDS = 1,
    HEARTS =   2,
    SPADES =   3,
    CLUBS =    4
};

class Card {
private:
    int m_rank;
    int m_suit;
    bool m_isFaceUp = false;
public:
    Card (int rank, int suit);
    Card (int rank, int suit, bool isFaceUp);
    int GetValue () const;
    int GetSuit () const;
    void Flip();
    friend std::ostream& operator<< (std::ostream& out, const Card& card);
};
