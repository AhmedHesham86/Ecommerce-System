#pragma once
#include "Ipayment.h"

class mastercard : public Ipayment
{
    public:
    void PayMethod() override;
};

