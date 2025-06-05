# Shopping-cart-backend
This is a console-based C++ shopping cart system that allows users to browse a list of products, add items to their cart, view itemized totals, and complete checkout with a simple payment simulation.

## 🛒 Console-Based Shopping Cart System

A simple console-based C++ application that simulates a shopping cart experience. Users can view available products, add them to their cart, view cart details, and checkout using cash payment.

## 🚀 Features

- View available products.
- Add products to a cart using product initials.
- View cart contents with itemized billing.
- Checkout with simple cash payment logic.

---

## 🧱 Classes Overview

### `Product`
Represents a product with an ID, name, and price.

### `Item`
Contains a `Product` and its quantity.

### `Cart`
Handles the collection of `Item`s, cart total, and display logic.

---

## 🔧 How to Compile and Run

Using `g++` (Linux/Mac/Windows with MinGW)
bash
g++ cart_main.cpp -o shoppingCart
./shoppingCart


## Example Interaction

Available Products:
apple : Rs 26
mango : Rs 16
guava : Rs 36
banana : Rs 56
strawberry : Rs 29
pineapple : Rs 20

Select an action - (a)dd item, (v)iew cart, (c)heckout
a
Added to the cart apple : Rs 26

Select an action - (a)dd item, (v)iew cart, (c)heckout
v
1 x apple = Rs. 26

Total amount : Rs. 26



