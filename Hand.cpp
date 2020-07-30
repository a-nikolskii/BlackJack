#include "Hand.h"
#include <stdarg.h>

Hand::Hand() {
    m_Cards.reserve(7);
}

//Hand::Hand(unsigned num, ...) {
//    m_Cards.clear();
//    va_list args;
//    va_start(args, num);
//    while (num--) {
//        m_Cards.push_back(va_arg(args, Card*));
//    }
//    va_end(args);
//}

void Hand::Add(Card* pCard) {m_Cards.push_back(pCard);}

void Hand::Clear() {
    for (auto it = m_Cards.begin(); it != m_Cards.end(); ++it) {
        delete *it;
        *it = nullptr;
    }
    m_Cards.clear();
}

int Hand::GetTotal() const {
    int total = 0;
    bool thereIsAce;

    for (auto card = m_Cards.begin(); card != m_Cards.end(); ++card) {
        if (!(*card)->GetValue() ) { // если одна из карт перевернута, то сумму посчитать не можем
            std::cout << "Once of card is not faceUp"<< std::endl;
            return 0;
        }
        total += (*card)->GetValue();
        if ( (*card)->GetValue() == ACE ) thereIsAce = true;
    }

    if (thereIsAce && total <= 11) total +=10;

    return total;
}

Hand::~Hand() {
    Clear();
}
