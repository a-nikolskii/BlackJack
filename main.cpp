#include <iostream>
#include "Hand.h"

int main(int argc, char *argv[])
{

    Card AceClubs (ACE, CLUBS);
    Card TwoClubs (TWO, CLUBS);
    Card JackClubs (JACK, CLUBS);

    AceClubs.Flip();

    //Одна из карт не перевертнута
    //Hand h0 (1, &TwoClubs);
    //h0.Add(&AceClubs);
    //std::cout << h0.GetTotal() << std::endl;

    TwoClubs.Flip();
    JackClubs.Flip();
    //Добор карты по одной + туз меняет значение на 1
    Hand h1;
    h1.Add(&AceClubs);
    h1.Add(&TwoClubs);
    h1.Add(&JackClubs);

    std::cout << h1.GetTotal() << std::endl;

    //Тест конструктора с произвольным числом параметров
    //Hand h2 (2, &AceClubs, &JackClubs);
    //std::cout << h2.GetTotal() << std::endl;



    return 0;
}
