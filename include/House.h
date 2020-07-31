#pragma once
#include <GenericPlayer.h>

class House : public GenericPlayer {
public:
    virtual bool IsHitting() const override;
    void FlipFirstCard();
    //~House();
};
