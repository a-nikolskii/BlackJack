#include <Player.h>
#include <cctype>


bool Player::IsHitting() const {
    std::string responce;
    std::cout << m_name << ", do you want a hit? (Y/N): ";
    do {
        getline(std::cin, responce);
        if (responce.size() > 3) {
            std::cout << "Please enter (Y/N): ";
            continue;
        }
        for (auto it = responce.begin(); it != responce.end(); ++it){
            tolower(*it);
        }
        if (responce == "y" || responce == "yes") return true;
        else if (responce == "n" || responce == "now") return false;
        else {
            std::cout << "Please enter (Y/N): ";
            continue;
        }
    } while(true);
};

void Player::Win() const{
    std::cout << m_name << " Wins!\n";
};

void Player::Lose() const {
    std::cout << m_name << " Loses!\n";
};

void Player::Push() const {
    std::cout << m_name << " Pushes!\n";
};
