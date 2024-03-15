#include"linkedlist.h"
#include<iostream>


using namespace std;

void linked_list::print(){
    for(NODE* cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << "\n";
}

void linked_list::insert_end(int value){
    NODE* tmp = new NODE(value); 
    if(!head)
        head = tail = tmp;
    else 
        tail->next = tmp, tail = tmp;
}
int linked_list::search(int value){
    int i {0};
    for(NODE* cur = head; cur; ++i,cur=cur->next)
        if(cur->data == value)
            return i;
    return -1;
}
int linked_list::improved_search(int value){
    int i{0};
    NODE* prev = nullptr;
    for(NODE* cur = head; cur ; ++i, cur=cur->next){
        if(cur->data == value){ 
            if(!prev)
                return i;
        swap(prev->data, cur->data);
        return i - 1;
        }
        prev = cur;
    }
    return -1;
}
