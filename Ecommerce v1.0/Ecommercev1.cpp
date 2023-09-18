#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

//payment handling classes

class Ipayment
{
    public:
    virtual void PayMethod() = 0;
    virtual ~Ipayment() = default;
};

class visa : public Ipayment
{
    public:
    void PayMethod() override
    {
        std::cout<<"Paying using a visa card!\n";
    }
};

class mastercard : public Ipayment
{
    public:
    void PayMethod() override
    {
        std::cout<<"Paying using a master card!\n";
    }
};

class one_card : public Ipayment
{
    public:
    void PayMethod() override
    {
        std::cout<<"Paying using one card!\n";
    }
};

class AmericanExpress : public Ipayment
{
    public:
    void PayMethod() override
    {
        std::cout<<"paying using American Express Card\n";
    }
};

//product classes

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

class Apple : public Iproduct
{
    public:

    Apple(): name("Apple"),price(50),description("Color: red , Size: small , Type: Fruit"){}

    std::string getname()const override
    {
        return name;
    }

    double getprice()const override
    {
        return price;
    }

    std::string ShowDescription() const override
    {
        return description;
    }   

    void setprice(double value)
    {
        price = value;
    }

    void getDetails()override
    {
        std::cout<<"The name of the product: "<<name <<std::endl;
        std::cout<<"The Price of the product: "<<price <<std::endl;
        std::cout<<"The Description of the product: "<<description <<std::endl;
    }
    private:
    std::string name;
    double price;
    std::string description;
};

class Orange : public Iproduct
{
    public:

    Orange(): name("Orange"),price(30),description("Color: Orange , Size: medium , Type: Fruit"){}

    std::string getname()const override
    {
        return name;
    }

    double getprice()const override
    {
        return price;
    }

    std::string ShowDescription() const override
    {
        return description;
    }   

    void setprice(double value)
    {
        price = value;
    }

    void getDetails()override
    {
        std::cout<<"The name of the product: "<<name <<std::endl;
        std::cout<<"The Price of the product: "<<price <<std::endl;
        std::cout<<"The Description of the product: "<<description <<std::endl;
    }
    private:
    std::string name;
    double price;
    std::string description;
};

//cart class

class Icart
{
    public:
    virtual void Preview_cart() = 0;
    virtual void Add_Product_cart(std::shared_ptr<Iproduct> prod) = 0;
    virtual void Remove_Product_cart(std::shared_ptr<Iproduct> prod) = 0;
    virtual double TotalPrice_cart() = 0;
    virtual void Discount_cart(double val) = 0;
};

class Cart : public Icart
{
    public:

    void Add_Product_cart(std::shared_ptr<Iproduct> prod) override
    {
        Products.push_back(prod);
        std::cout<<"The product : "<<prod->getname() <<" has been pushed into the cart !\n";
    }

    void Remove_Product_cart(std::shared_ptr<Iproduct> prod) override
    {
        Products.erase(std::remove(Products.begin(),Products.end(),prod),Products.end());
        std::cout<<"The product : "<<prod->getname() <<" has been removed from the cart!\n";
    }

    double TotalPrice_cart() override
    {
        double total_price = 0;
        for(auto prod : Products)
        {
            total_price += prod->getprice();
        }
        return total_price;
    }

    void Discount_cart(double val) override
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

    void Preview_cart() override
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

    private:
    
    std::vector<std::shared_ptr<Iproduct>> Products;

};

//orders class

class Iorders
{
    public:
    virtual ~Iorders() = default;
    virtual void Preview() = 0;
    virtual void push_cart(std::shared_ptr<Icart> cartt) = 0;
};

class Orders : public Iorders
{
    public:
    
    void push_cart(std::shared_ptr<Icart> cartt) override
    {
        carts.push_back(cartt);
    }

    void Preview() override
    {
        for(auto x : carts)
        {
            x->Preview_cart();
        }
    }

    private:
    std::vector<std::shared_ptr<Icart>> carts;
};

//Ecommerce system class

class IEcommerce 
{
    public:
    virtual void push(std::shared_ptr<Iorders> order) = 0;
    virtual void remove(std::shared_ptr<Iorders>  order) = 0;
    virtual void notify_users() = 0;
    virtual void pay(std::shared_ptr<Ipayment>  method) = 0;
    virtual ~IEcommerce() = default;

};

class Ecommerce : public IEcommerce
{
    public:

    void push(std::shared_ptr<Iorders> order) override
    {
        Orders.push_back(order);
        std::cout<<"The order has been added\n";
    }

    void remove(std::shared_ptr<Iorders> order) override
    {
        Orders.erase(std::remove(Orders.begin(),Orders.end(),order),Orders.end());
        std::cout<<"The Order has been removed!\n";
    }

    void notify_users() override
    {
        for(auto order : Orders)
        {
            std::cout<<"Order is ready please proceed to pay the order\n";
        }
    }

    void pay(std::shared_ptr<Ipayment> method) override
    {
        method->PayMethod();
    }

    private:
    std::vector<std::shared_ptr<Iorders>> Orders;
};

std::shared_ptr<Iorders> make_Shared_Orders()
{
    return std::make_shared<Orders>();
}

std::shared_ptr<IEcommerce> make_Shared_Commerce()
{
    return std::make_shared<Ecommerce>();
}

std::shared_ptr<Ipayment> make_Shared_Payments_visa()
{
    return std::make_shared<visa>();
}

std::shared_ptr<Ipayment> make_Shared_Pyaments_mastercard()
{
    return std::make_shared<mastercard>();
}

std::shared_ptr<Ipayment> make_Shared_Payments_one_card()
{
    return std::make_shared<one_card>();
}

std::shared_ptr<Ipayment> make_Shared_American_Express()
{
    return std::make_shared<AmericanExpress>();
}

std::shared_ptr<Iproduct> make_Shared_Apple()
{
    return std::make_shared<Apple>();
}

std::shared_ptr<Iproduct> make_Shared_Orange()
{
    return std::make_shared<Orange>();
}

std::shared_ptr<Icart> make_Shared_cart()
{
    return std::make_shared<Cart>();
}

void run()
{
    auto order   = make_Shared_Orders();
    auto system  = make_Shared_Commerce();
    auto method1 = make_Shared_Payments_visa();
    auto method2 = make_Shared_Pyaments_mastercard();
    auto method3 = make_Shared_Payments_one_card();
    auto method4 = make_Shared_American_Express();
    auto prod1   = make_Shared_Apple();
    auto prod2   = make_Shared_Orange();
    auto cart    = make_Shared_cart();

    cart->Add_Product_cart(prod1);
    cart->Add_Product_cart(prod2);

    
    order->push_cart(cart);
    order->Preview();

    system->push(order);
    system->notify_users();
    system->pay(method4);
}

void end()
{
    std::cout<<"Thank you for using simple Ecommerce system!\n";
}

int main()
{
    run();
    end();
    return 0;
}