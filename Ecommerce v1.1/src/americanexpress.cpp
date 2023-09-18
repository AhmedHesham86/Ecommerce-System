#include "../Include/Payment/americanexpress.h"

void AmericanExpress::PayMethod() 
{
    std::cout<<"paying using American Express Card\n";
}

std::shared_ptr<Ipayment> make_Shared_American_Express()
{
    return std::make_shared<AmericanExpress>();
}