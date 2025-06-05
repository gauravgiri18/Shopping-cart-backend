//Product Item cart
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//Forward declaration of class
//cause there could be an error if we say friend class Item in Product so will will declare class Item and Cart before hand
class Item;
class Cart;


class Product {
    int id;
    string name;
    int price;

    public:
        Product() {//dummy constructor for the Product product i call in class Item

        }

        Product(int u_id, string name, int price) {
            //assignment way of initialization
            id = u_id;
            this->name = name;
            this->price = price;

        }
        
        string getDisplayName() {
            return name + " : Rs " + to_string(price) + "\n";
        }

        string getShortName() {
            return name.substr(0,1);
        }

        friend class Item;//Now friend can access Product.price because price is the private member of Product
        friend class Cart;
};


//item and quqality
class Item {
    Product product;
    int quantity;

public:
    Item() {

    }

    //constructor
    Item(Product p, int q): product(p), quantity(q){}//Initialization list

    int getItemPrice(){
        return quantity * product.price;
    }

    string geteItemInfo() {
        return to_string(quantity) + " x " + product.name + " = Rs. " + to_string(quantity * product.price) + "\n"; 
    }

    friend class Cart;
};

class Cart {
    //collection
    unordered_map<int, Item>items;//id is id and item is value

public:
    void addProduct(Product product){
        if(items.count(product.id) == 0){
            Item newItem(product, 1);
            items[product.id] = newItem;
        }
        else {
            items[product.id].quantity += 1;
        }
    }

    int getTotal() {
        int total = 0;
        for(auto itemPair: items){
            total += itemPair.second.getItemPrice();
        }
        return total;
    }

    string viewCart() {
        if(items.empty()){
            return "Cart is empty";
        }
        string itemizedList;
        int cart_total = getTotal();

        for(auto itemPair: items){
            auto item = itemPair.second;
            itemizedList.append(item.geteItemInfo());
        }

        return itemizedList + "\n Total amount : Rs, " + to_string(cart_total) + '\n';
    }

    bool isEmpty() {
        return items.empty();
    }

};