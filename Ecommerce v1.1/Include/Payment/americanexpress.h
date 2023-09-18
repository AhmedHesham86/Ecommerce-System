#pragma once
#include "Ipayment.h"

class AmericanExpress : public Ipayment
{
    public:
    void PayMethod() override;
};

