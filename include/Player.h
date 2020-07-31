#include <GenericPlayer.h>

class Player : public GenericPlayer {
public:
    virtual bool IsHitting() const override;
    void Win() const;
    void Lose() const;
    void Push() const;
    //~Player();
};
