#include "Hand.h"
#include <stdarg.h>

Hand::Hand() {
    m_Cards.clear();
}

Hand::Hand(unsigned num, ...) {
    m_Cards.clear();
    va_list args;
    va_start(args, num);
    while (num--) {
        m_Cards.push_back(va_arg(args, Card*));
    }
    va_end(args);
}

void Hand::Add(Card* pCard) {m_Cards.push_back(pCard);}

void Hand::Clear() {m_Cards.clear();}

int Hand::GetTotal() const {
    int total = 0;
    bool thereIsAce;

    for (auto card = m_Cards.begin(); card != m_Cards.end(); ++card) {
        if (!(**card).GetValue() ) { // если одна из карт перевернута, то сумма посчитать не можем
            std::cout << "Once of card is not faceUp"<< std::endl;
            return 0;
        }
        total += (**card).GetValue();
        if ( (**card).GetValue() == ACE ) thereIsAce = true;
    }

    if (thereIsAce && total > 21) total -=10; // если есть туз  и перебор, то туз считаем за 1

    return total;
}
