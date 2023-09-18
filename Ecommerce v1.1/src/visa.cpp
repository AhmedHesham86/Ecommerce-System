#include "../Include/Payment/visa.h"

void visa::PayMethod() 
{
    std::cout<<"Paying using a visa card!\n";
}

std::shared_ptr<Ipayment> make_Shared_Payments_visa()
{
    return std::make_shared<visa>();
}