#include "../Include/Products/Orange.h"

Orange::Orange(): name("Orange"),price(30),description("Color: Orange , Size: medium , Type: Fruit"){}

std::string Orange::getname()const 
{
    return name;
}

double Orange::getprice()const 
{
    return price;
}

std::string Orange::ShowDescription() const 
{
    return description;
}   

void Orange::setprice(double value)
{
    price = value;
}

void Orange::getDetails()
{
    std::cout<<"The name of the product: "<<name <<std::endl;
    std::cout<<"The Price of the product: "<<price <<std::endl;
    std::cout<<"The Description of the product: "<<description <<std::endl;
}