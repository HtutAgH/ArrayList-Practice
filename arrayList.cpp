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
