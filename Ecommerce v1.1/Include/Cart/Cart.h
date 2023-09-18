#pragma once
#include "Icart.h"


class Cart : public Icart
{
    public:

    void Add_Product_cart(std::shared_ptr<Iproduct> prod) override;

    void Remove_Product_cart(std::shared_ptr<Iproduct> prod) override;

    double TotalPrice_cart() override;

    void Discount_cart(double val) override;

    void Preview_cart() override;

    private:
    
    std::vector<std::shared_ptr<Iproduct>> Products;

};