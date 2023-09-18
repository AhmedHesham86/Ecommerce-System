#include "../Include/Payment/onecard.h"

void one_card::PayMethod()
{
    std::cout<<"Paying using one card!\n";
}

std::shared_ptr<Ipayment> make_Shared_Payments_one_card()
{
    return std::make_shared<one_card>();
}