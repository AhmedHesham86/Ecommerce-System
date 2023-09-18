#pragma once
#include "Isystem.h"

class Ecommerce : public IEcommerce
{
    public:

    void push(std::shared_ptr<Iorders> order) override;

    void remove(std::shared_ptr<Iorders> order) override;

    void notify_users() override;

    void pay(std::shared_ptr<Ipayment> method) override;

    private:
    
    std::vector<std::shared_ptr<Iorders>> Orders;
};