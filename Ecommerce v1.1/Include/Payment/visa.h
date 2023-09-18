#pragma once
#include "Ipayment.h"

class visa : public Ipayment
{
    public:
    void PayMethod() override;
};
