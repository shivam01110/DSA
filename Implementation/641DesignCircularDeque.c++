#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> que;
    int f,l,size,capacity;
    MyCircularDeque(int k) {
        que.resize(k);
        f=0;
        l=k-1;
        size=0;
        capacity=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        f=(f-1+capacity)%capacity;
        que[f]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        l=(l+1)%capacity;
        que[l]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        f=(f+1)%capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        l=(l-1+capacity)%capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return que[f];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return que[l];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */