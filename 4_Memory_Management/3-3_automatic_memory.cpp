#include <iostream>

void call_me(long i, long* addr){
    int temp {0};
    std::cout << i << ": stack bottom : " << addr << ", current : " << &temp << std::endl;
    call_me(++i, addr);
}

int main(){
    long i = 1;
    call_me(i, &i);
    return 0;
}