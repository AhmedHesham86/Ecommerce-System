#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "../Products/Iproduct.h"

class Icart
{
    public:
    virtual void Preview_cart() = 0;
    virtual void Add_Product_cart(std::shared_ptr<Iproduct> prod) = 0;
    virtual void Remove_Product_cart(std::shared_ptr<Iproduct> prod) = 0;
    virtual double TotalPrice_cart() = 0;
    virtual void Discount_cart(double val) = 0;
};

std::shared_ptr<Icart> make_Shared_cart();