// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
//
// Lab 11-1
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#include "customer.h"

// ========================= YOUR CODE HERE =========================
// This implementation file (customer.cc) is where you should implement
// the member functions declared in the header (customer.h), only
// if you didn't implement them inline within customer.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Customer class.
// ===================================================================
Customer::Customer(const std::string &name, int product_count, std::shared_ptr<Customer> next_customer) {
    name_ = name;
    product_count_ = product_count;
    next_customer_ = next_customer;
}

std::string Customer::GetName() { return name_; }

int Customer::GetProductCount() { return product_count_; }

std::shared_ptr<Customer> Customer::GetNextCustomer() { return next_customer_; }

int Customer::TotalCustomersInLine() {
    if(next_customer_ == NULL) return 1;
    return next_customer_->TotalCustomersInLine() + 1;
}

int Customer::TotalProductsInLine() {
    if(next_customer_ == NULL) return product_count_;
    return next_customer_->TotalProductsInLine() + product_count_;
}

std::string Customer::FirstAlphabeticalCustomerInLine() {
    if(next_customer_ == NULL) return name_;
    std::string next_customer = next_customer_->FirstAlphabeticalCustomerInLine();
    if(next_customer < name_) return next_customer;
    return name_;
}