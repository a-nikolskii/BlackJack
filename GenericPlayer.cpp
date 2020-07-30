#include <GenericPlayer.h>

GenericPlayer::GenericPlayer(std::string name) : Hand(), m_name(name) {}

bool GenericPlayer::IsBoosted() const {
    if ( GetTotal() > 21 )
        return true;
    return false;
}

void GenericPlayer::Bust () const {
    if (IsBoosted()) {
        std::cout << "The player " << m_name << " is bust!" << std::endl;
    }
}
