#include <iostream>
using namespace std;

// Macro definition
#define SQUARE(x) ((x) * (x))

// Function definition
int multiply(int a, int b) {
    return a * b;
}

int main() {
    int num1 = 3, num2 = 4;
    cout << "The square of " << num1 << " is: " << SQUARE(num1) << endl;
    cout << "The product of " << num1 << " and " << num2 << " is: " << multiply(num1, num2) << endl;
    return 0;
}
