#include <Hand.h>

class GenericPlayer : public Hand {
private:
    std::string m_name;
public:
    GenericPlayer(std::string name);
    virtual bool IsHitting() = 0;
    bool IsBoosted () const;
    void Bust () const;
};

