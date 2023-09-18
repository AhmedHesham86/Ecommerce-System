#pragma once
#include <iostream>
#include <memory>
class Iproduct
{
    public:
    virtual void getDetails()=0;
    virtual std::string getname()const = 0;
    virtual double getprice()const = 0;
    virtual std::string ShowDescription() const = 0;
    virtual void setprice(double value) = 0;
    virtual ~Iproduct() = default;
};

std::shared_ptr<Iproduct> make_Shared_Orange();
std::shared_ptr<Iproduct> make_Shared_Apple();