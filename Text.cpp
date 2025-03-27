#include <iostream>

int f(int a){
    if (a == 0){
        return 1;
    }
    return a * f(a - 1);
}

int main(){
    int a;
    std::cin >> a;
    std::cout << f(a) << std::endl;
    return 0;
}