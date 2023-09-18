#include "../Include/Orders/Orders.h"

void Orders::push_cart(std::shared_ptr<Icart> cartt) 
{
    carts.push_back(cartt);
}

void Orders::Preview() 
{
    for(auto x : carts)
    {
        x->Preview_cart();
    }
}

std::shared_ptr<Iorders> make_Shared_Orders()
{
    return std::make_shared<Orders>();
}