#pragma once
#include "Iorders.h"


class Orders : public Iorders
{
    public:
    
    void push_cart(std::shared_ptr<Icart> cartt) override;

    void Preview() override;

    private:
    std::vector<std::shared_ptr<Icart>> carts;
};