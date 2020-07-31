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

std::ostream& operator<<(std::ostream& out, const GenericPlayer& g_player){
    out << g_player.m_name << ":\t";

    if (!g_player.m_Cards.empty()){
        for (auto it = g_player.m_Cards.begin();
            it != g_player.m_Cards.end();
            ++it) {
            out << **it << "\t";
        }
    }
    else { out << "<empty>";}

    return out;
}
