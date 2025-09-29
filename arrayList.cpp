#include "arrayList.h"

arrayList::arrayList(int maxSize)
    : length(0), capacity(maxSize), data(nullptr)
{
    if (maxSize <= 0) throw std::invalid_argument("maxSize must be > 0");
    data = new complexNumber[capacity];
}

arrayList::~arrayList() {
    delete[] data;
}

bool arrayList::isEmpty() const { return length == 0; }
bool arrayList::isFull()  const { return length == capacity; }
int  arrayList::listSize() const { return length; }
int  arrayList::maxListSize() const { return capacity; }

void arrayList::print() const {
    if (isEmpty()) {  
        std::cout << "(empty)\n";
        return;
    }
    for (int i = 0; i < length; ++i) {
        std::cout << i << ": " << data[i] << "\n";
    }
}

bool arrayList::isItemAtEqual(int index, const complexNumber& item) const {
    if (index < 0 || index >= length) throw std::out_of_range("index out of range");
    const complexNumber& x = data[index];
    return x.getReal() == item.getReal() && x.getIm() == item.getIm();
}

void arrayList::insertAt(int index, const complexNumber& item) {
    if (index < 0 || index > length) throw std::out_of_range("index out of range");
    if (isFull()) throw std::overflow_error("list is full");
    // shift right [index..length-1]
    for (int i = length; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = item;
    ++length;
}

void arrayList::insertEnd(const complexNumber& item) {
    if (isFull()) throw std::overflow_error("list is full");
    data[length++] = item;
}

void arrayList::removeAt(int index) {
    if (index < 0 || index >= length) throw std::out_of_range("index out of range");
    // shift left [index+1..length-1]
    for (int i = index; i < length - 1; ++i) {
        data[i] = data[i + 1];
    }
    --length;
}

complexNumber arrayList::retrieveAt(int index) const {
    if (index < 0 || index >= length) throw std::out_of_range("index out of range");
    return data[index]; 
}

void arrayList::replaceAt(int index, const complexNumber& item) {
    if (index < 0 || index >= length) throw std::out_of_range("index out of range");
    data[index] = item;
}

void arrayList::clearList() {
    // no need to delete[]; we keep capacity and reuse the buffer
    length = 0;
}
