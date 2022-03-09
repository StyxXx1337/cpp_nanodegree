#include <memory>
#include <iostream>

void RawPointer()
{
    int *raw = new int; // create a raw pointer on the heap
    *raw = 1; // assign a value
    delete raw; // delete the resource again
}

std::unique_ptr<int> UniquePointer()
{
    std::unique_ptr<int> unique(new int); // create a unique pointer on the stack
    *unique = 2; // assign a value
    // delete is not needed
    std::cout << "Create pointer at: " << &unique << " with value: " << *unique <<std::endl;
    return std::move(unique);
}

int main(){
    std::unique_ptr<int> ptr = std::move(UniquePointer());

    std::cout << "Pointer at: " << &ptr << " with value: " << *ptr <<std::endl;
    return 0;
}