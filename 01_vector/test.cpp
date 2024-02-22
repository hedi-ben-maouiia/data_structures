#include"vector.h"


int main(){
    Vector v(10);
 
    for(int i{0}; i < 10;++i)
        v.set(i, i+1); 

    v.print();

    std::cout << v.find(5)  <<"\n" ;
    std::cout << v.find(55) << "\n";
}
