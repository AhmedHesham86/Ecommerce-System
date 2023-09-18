#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "../Payment/Ipayment.h"
#include "../Orders/Iorders.h"

class IEcommerce 
{
    public:
    virtual void push(std::shared_ptr<Iorders> order) = 0;
    virtual void remove(std::shared_ptr<Iorders>  order) = 0;
    virtual void notify_users() = 0;
    virtual void pay(std::shared_ptr<Ipayment>  method) = 0;
    virtual ~IEcommerce() = default;

};

std::shared_ptr<IEcommerce> make_Shared_Commerce();