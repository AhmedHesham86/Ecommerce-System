#pragma once
#include <iostream>
#include <memory>
class Ipayment
{
    public:
    virtual void PayMethod() = 0;
    virtual ~Ipayment() = default;
};



std::shared_ptr<Ipayment> make_Shared_Payments_visa();
std::shared_ptr<Ipayment> make_Shared_Pyaments_mastercard();
std::shared_ptr<Ipayment> make_Shared_Payments_one_card();
std::shared_ptr<Ipayment> make_Shared_American_Express();