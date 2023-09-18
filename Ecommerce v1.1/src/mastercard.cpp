#include "../Include/Payment/mastercard.h"

void mastercard::PayMethod() 
{
    std::cout<<"Paying using a master card!\n";
}

std::shared_ptr<Ipayment> make_Shared_Pyaments_mastercard()
{
    return std::make_shared<mastercard>();
}

