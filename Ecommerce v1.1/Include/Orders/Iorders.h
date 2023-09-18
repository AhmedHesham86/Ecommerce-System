#pragma once
#include <memory>
#include <vector>
#include "../Cart/Icart.h"

class Iorders
{
    public:
    virtual ~Iorders() = default;
    virtual void Preview() = 0;
    virtual void push_cart(std::shared_ptr<Icart> cartt) = 0;
};

std::shared_ptr<Iorders> make_Shared_Orders();