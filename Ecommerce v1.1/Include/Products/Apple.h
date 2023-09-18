#pragma once
#include "Iproduct.h"

class Apple : public Iproduct
{
    public:

    Apple();

    std::string getname()const override;

    double getprice()const override;

    std::string ShowDescription() const override;

    void setprice(double value);

    void getDetails()override;

    private:
    std::string name;
    double price;
    std::string description;
};

std::shared_ptr<Iproduct> make_Shared_Apple()
{
    return std::make_shared<Apple>();
}