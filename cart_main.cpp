#include <iostream>
#include "dataModel.h"
#include <vector>
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(3,"mango", 16),
    Product (2, "guava",36),
    Product (5, "banana", 56),
    Product(4,"strawberry", 29),
    Product(6,"pineapple", 20),

};

Product* chooseProduct() {
    string productList;
    cout << "Available Products: " << endl;

    for(auto product: allProducts){
        productList.append(product.getDisplayName());
    }

    cout << productList << endl;

    cout << "----------------------" << endl;

    string choice;
    cin >> choice;

    for(int i=0; i< allProducts.size(); i++){
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i];
        }
    }

    cout << "Product not found" << endl;
    return NULL;

}

bool checkout(Cart &cart) {
    if(cart.isEmpty()){
        cout << "Cart is empty please shop" << endl;
        return false;
    }

    int total = cart.getTotal();
    cout << "Pay is cash ";

    int paid;
    cin >> paid;

    if(paid >= total){
        cout << "Change: " << paid-total << endl;
        cout << "Thank You for shopping" << endl;
        return true;
    } else {
        cout << "Not enough cash" << endl;
        return false;
    }
}

int main() {
    char action;
    Cart cart;//create everytime on ecart for every user

    while(true){
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;

        if(action == 'a'){
            //add to cart
            //view all the above products + let user choose the product among the allProducts + add the selected product to the cart

            Product *product = chooseProduct();
            if(product != NULL){
                cout << "Added to the cart " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        } else if(action == 'v'){
            cout << "--------------" << endl;
            cout << cart.viewCart();
            cout <<"---------------" << endl;
        } else if(action == 'c'){
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }
    
    return 0;
}