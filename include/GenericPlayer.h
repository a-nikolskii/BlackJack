#pragma once
#include <Hand.h>

class GenericPlayer : public Hand {
protected:
    std::string m_name;
public:
    GenericPlayer(std::string name);
    virtual bool IsHitting() const = 0;
    bool IsBoosted () const;
    void Bust () const;
    //~GenericPlayer();
    friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& g_player);
};

