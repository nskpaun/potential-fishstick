#include <iostream>
#include <cassert>

// Function to test
int add(int a, int b) {
    return a + b;
}

// Test case
void testAdd() {
    int result = add(2, 3);
    assert(result == 5);
    std::cout << "Test passed!" << std::endl;
}

int main() {
    testAdd();
    return 0;
}