#include"vector.h"


int main(){
    Vector v(10);
 
    for(int i{0}; i < 10;++i)
        v.set(i, i+1); 

    v.print();

    std::cout << v.find(5)  <<"\n" ;
    std::cout << v.find(55) << "\n";

    // Test the push_back and the push_front function 
    v.push_back(11324);
    v.print();
    v.push_front(14);
    v.print();
    std::cout << "******************\n";
    Vector v2(1);
    v2.push_back(14);
    v2.push_front(1);
    v2.push_front(2);
    v2.print();

}
