#pragma once
#include "Ipayment.h"

class one_card : public Ipayment
{
    public:
    void PayMethod() override;
};

