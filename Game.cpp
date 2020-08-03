#include "Game.h"

Game::Game(std::vector<std::string>& names) {
    for(auto it = names.begin(); it != names.end(); ++it) {
        m_Players.push_back(Player(*it));
    }
    srand(static_cast<unsigned int>(time(0)));

    m_Deck.Shuffle();
}

void Game::Play(){

    for (int i =0 ; i < 2; ++i) {
        for (auto it = m_Players.begin(); it != m_Players.end(); ++it) {
            m_Deck.Deal(*it);
        }
        m_Deck.Deal(m_House);
    }

    m_House.FlipFirstCard();

    for (auto it = m_Players.begin(); it != m_Players.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << m_House << std::endl;
    std::cout << std::endl;

    for (auto it = m_Players.begin(); it != m_Players.end(); ++it) {
        m_Deck.AditionalCards(*it);
    }

    m_House.FlipFirstCard();
    std::cout << m_House << std::endl;

    m_Deck.AditionalCards(m_House);

    if (m_House.IsBoosted()) {
        for (auto it = m_Players.begin(); it != m_Players.end(); ++it) {
            if (!it->IsBoosted()) it->Win();
        }
    }
    else {
        for (auto it = m_Players.begin(); it != m_Players.end(); ++it) {
            if(!it->IsBoosted()) {
                if (it->GetTotal() > m_House.GetTotal()) {
                    it->Win();
                }
                else if (it->GetTotal() < m_House.GetTotal()){
                    it->Lose();
                }
                else {
                    it->Push();
                }
            }
        }
    }

    for (auto it = m_Players.begin(); it != m_Players.end(); it++) {
        it ->Clear();
    }
    m_House.Clear();

}
