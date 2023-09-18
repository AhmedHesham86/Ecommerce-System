#pragma once
#include "Iproduct.h"

class Orange : public Iproduct
{
    public:

    Orange();

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

std::shared_ptr<Iproduct> make_Shared_Orange()
{
    return std::make_shared<Orange>();
}