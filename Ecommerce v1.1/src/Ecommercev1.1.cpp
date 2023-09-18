#include "../Include/Payment/Ipayment.h"
#include "../Include/Products/Iproduct.h"
#include "../Include/Cart/Icart.h"
#include "../Include/Orders/Iorders.h"
#include "../Include/System/Isystem.h"

namespace Ecommerce{

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

}

int main()
{
    Ecommerce::run();
    Ecommerce::end();
    return 0;
}