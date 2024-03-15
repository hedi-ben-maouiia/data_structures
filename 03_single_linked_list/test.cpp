#include"linkedlist.h"
int main(){
      
    linked_list list;
    list.insert_end(20);
    list.insert_end(30);
    list.insert_end(40);
    list.insert_end(50);
    int a = list.improved_search(40);
    list.print();
    cout << "\n***********\n";
    cout << a << "\n";
    a = list.improved_search(40);
    cout << a << "\n";
    return 0x00;
}
