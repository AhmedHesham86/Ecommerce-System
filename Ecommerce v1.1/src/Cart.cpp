#include "../Include/Cart/cart.h"

void Cart::Add_Product_cart(std::shared_ptr<Iproduct> prod) 
{
    Products.push_back(prod);
    std::cout<<"The product : "<<prod->getname() <<" has been pushed into the cart !\n";
}

void Cart::Remove_Product_cart(std::shared_ptr<Iproduct> prod) 
{
    Products.erase(std::remove(Products.begin(),Products.end(),prod),Products.end());
    std::cout<<"The product : "<<prod->getname() <<" has been removed from the cart!\n";
}

double Cart::TotalPrice_cart() 
{
    double total_price = 0;
    for(auto prod : Products)
    {
        total_price += prod->getprice();
    }
    return total_price;
}

void Cart::Discount_cart(double val) 
{
    double new_price = 0;
    for(auto &prod : Products)
    {
        new_price = prod->getprice() - (prod->getprice() * val / 100);
        prod->setprice(new_price);
        new_price = 0;
    }
    std::cout<<"A discount of "<< val <<" percent has been made to all products inside the cart!\n";
}

void Cart::Preview_cart() 
{
    double total_price = 0;
    int quantity = 0;
    for(auto prod : Products)
    {
        prod->getDetails();
        total_price += prod->getprice();

    }
    std::cout<<"The total price of all products inside the cart = "<<total_price<<std::endl;
    for(auto x : Products)
    {
        quantity++;
    }
    std::cout<<"The cart has "<<quantity << " Products!\n";
}

std::shared_ptr<Icart> make_Shared_cart()
{
    return std::make_shared<Cart>();
}