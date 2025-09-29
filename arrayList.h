#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "complexNumber.h"
#include <iostream>
#include <stdexcept>

class arrayList {
private:
    int length;
    int capacity;
    complexNumber* data;
public:
    arrayList(int maxSize = 100);
    ~arrayList();

    bool isEmpty() const;
    bool isFull() const;
    int  listSize() const;
    int  maxListSize() const;
    void print() const;
    bool isItemAtEqual(int index, const complexNumber& item) const;
    
    arrayList(const arrayList&) = delete;
    arrayList& operator=(const arrayList&) = delete;
};

#endif
