#include "Card.h"
#include <vector>

class Hand {
protected:
    std::vector<Card*> m_Cards;
public:
    Hand();
    //Hand(unsigned num, ...);
    void Add(Card* pCard);
    void Clear();
    int GetTotal() const;
    virtual ~Hand();
};
