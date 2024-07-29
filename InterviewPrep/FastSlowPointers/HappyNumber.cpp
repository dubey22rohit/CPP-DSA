#include <iostream>
using namespace std;

// Any number will be called a happy number if, after repeatedly replacing it
// with a number equal to the sum of the square of all of its digits, leads us
// to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead,
// they will be stuck in a cycle of numbers which does not include ‘1’.

/**
 * Calculates the sum of the squares of the digits of a given number.
 *
 * @param n The number to calculate the sum of squares of digits for.
 * @return The sum of the squares of the digits of the given number.
 */
int getPow(int n) {
  // Initialize the sum variable to 0.
  int sum = 0;

  // Iterate through each digit of the given number.
  while (n > 0) {
    // Extract the rightmost digit of the given number.
    int rem = n % 10;

    // Calculate the square of the digit and add it to the sum.
    sum += rem * rem;

    // Remove the rightmost digit from the given number.
    n /= 10;
  }

  // Return the sum of the squares of the digits.
  return sum;
}

/**
 * Determines whether a given number is a happy number.
 *
 * @param num The number to check.
 * @return True if the number is a happy number, false otherwise.
 *
 * A happy number is a number that eventually reaches the number 1 when
 * repeatedly replacing it with the sum of the squares of its digits.
 */
static bool findHappy(int num) {
  // Initialize the slow and fast pointers to the given number.
  int slow = num, fast = getPow(num);

  // Continue the loop until the slow and fast pointers converge to the same
  // value.
  while (slow != fast) {
    // Calculate the next value of the slow pointer by squaring and summing the
    // digits of the current value.
    slow = getPow(slow);

    // Calculate the next value of the fast pointer by repeatedly squaring and
    // summing the digits of the current value until convergence.
    fast = getPow(getPow(fast));
  }

  // Return true if the fast pointer has converged to the number 1, indicating
  // that the number is a happy number.
  return fast == 1;
}

int main() {
  cout << findHappy(23) << endl;
  cout << findHappy(12) << endl;
  return 0;
}