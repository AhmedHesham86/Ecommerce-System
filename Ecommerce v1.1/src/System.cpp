#include "../Include/System/system.h"

void Ecommerce::push(std::shared_ptr<Iorders> order) 
{
    Orders.push_back(order);
    std::cout<<"The order has been added\n";
}

void Ecommerce::remove(std::shared_ptr<Iorders> order) 
{
    Orders.erase(std::remove(Orders.begin(),Orders.end(),order),Orders.end());
    std::cout<<"The Order has been removed!\n";
}

void Ecommerce::notify_users() 
{
    for(auto order : Orders)
    {
        std::cout<<"Order is ready please proceed to pay the order\n";
    }
}

void Ecommerce::pay(std::shared_ptr<Ipayment> method) 
{
    method->PayMethod();
}

std::shared_ptr<IEcommerce> make_Shared_Commerce()
{
    return std::make_shared<Ecommerce>();
}