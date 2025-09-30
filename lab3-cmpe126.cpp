#include <iostream>
#include "arrayList.h"
#include "complexNumber.h"

int main() {
    std::cout << std::boolalpha;

    arrayList array1(6);
    arrayList array2(6);

    std::cout << "Initial:\n";
    std::cout << "array1 empty=" << array1.isEmpty() << ", full=" << array1.isFull()
              << ", size=" << array1.listSize() << ", max=" << array1.maxListSize() << "\n";
    std::cout << "array2 empty=" << array2.isEmpty() << ", full=" << array2.isFull()
              << ", size=" << array2.listSize() << ", max=" << array2.maxListSize() << "\n";
    std::cout << "\n";

    // some values
    complexNumber a(1, 2), b(3, -4), c(5, 6), d(-7, 8), e(9, 0), z(42, 42);

    // ---- Test all funcs on array1 ----
    array1.insertEnd(a);     // [a]
    array1.insertEnd(b);     // [a, b]
    array1.insertEnd(c);     // [a, b, c]
    array1.insertAt(1, d);   // strict: index < length, now [a, d, b, c]
    std::cout << "array1 after inserts:\n";
    array1.print();

    std::cout << "retrieveAt(2): " << array1.retrieveAt(2) << "\n"; // should be b
    std::cout << "isItemAtEqual(0, a): " << array1.isItemAtEqual(0, a) << "\n";
    std::cout << "isItemAtEqual(1, d): " << array1.isItemAtEqual(1, d) << "\n";

    array1.replaceAt(2, e);  // replace b with e -> [a, d, e, c]
    std::cout << "array1 after replaceAt(2, e):\n";
    array1.print();

    array1.removeAt(1);      // remove d -> [a, e, c]
    std::cout << "array1 after removeAt(1):\n";
    array1.print();

    std::cout << "array1 empty=" << array1.isEmpty()
              << ", full=" << array1.isFull()
              << ", size=" << array1.listSize()
              << ", max=" << array1.maxListSize() << "\n\n";

    // Fill and clear array2
    array2.insertEnd(complexNumber(-1, -1));
    array2.insertEnd(complexNumber(-2, -2));
    std::cout << "array2 before clear:\n";
    array2.print();

    array2.clearList();
    std::cout << "array2 after clear: size=" << array2.listSize()
              << ", empty=" << array2.isEmpty() << "\n";
    array2.print();
    std::cout << "\n";

    // operator= test: assign array1 -> array2 (array2 is empty now) 
    array2 = array1;
    std::cout << "After array2 = array1:\n";
    std::cout << "array1:\n"; array1.print();
    std::cout << "array2:\n"; array2.print();

    // array1, array2 should stay unchanged (deep copy check)
    array1.replaceAt(0, z);  // array1[0] becomes z
    std::cout << "After modifying array1[0] to z:\n";
    std::cout << "array1:\n"; array1.print();
    std::cout << "array2 (should be unchanged):\n"; array2.print();

    return 0;
}
