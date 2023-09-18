#include "../Include/Products/Apple.h"

Apple::Apple(): name("Apple"),price(50),description("Color: red , Size: small , Type: Fruit"){}

std::string Apple::getname()const 
{
    return name;
}

double Apple::getprice()const 
{
    return price;
}

std::string Apple::ShowDescription() const 
{
    return description;
}   

void Apple::setprice(double value)
{
    price = value;
}

void Apple::getDetails()
{
    std::cout<<"The name of the product: "<<name <<std::endl;
    std::cout<<"The Price of the product: "<<price <<std::endl;
    std::cout<<"The Description of the product: "<<description <<std::endl;
}