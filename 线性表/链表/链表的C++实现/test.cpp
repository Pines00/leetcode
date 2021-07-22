#include"LinkedList.h"
#include<iostream>
using namespace std;
int main(){
    int x=111;
    LinkedList<int> l(0);
    l.input(5);
    l.output();
    l.Insert(2,x);
    l.output();
return 0;
}