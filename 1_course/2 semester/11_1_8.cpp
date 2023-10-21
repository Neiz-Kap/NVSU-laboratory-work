/*
  Part 1.8 Сформировать список целых чисел и удалить из него все четные.
*/

#include <iostream>
#include <list>
#include <stdlib.h> // srand(), rand()

using namespace std;

int generateRandomNumber(int startRange, int endRange) {
  int randomValue = startRange + rand() % (endRange - startRange + 1);
  return randomValue;
}

int main() {
  srand(time(NULL));

  list<int> numbers;
  int n;

  cout << "Input list number: ";
  cin >> n;

  // put values into the list
  for (int i = 0; i < n; i++) {
    numbers.push_back(generateRandomNumber(0, 25));
  }

  // output list items
  cout << "The initial list: ";
  for (int n : numbers)
    cout << n << " ";
  cout << "\n\n";

  list<int> oddNumbers;

  // remove even numbers
  int oddCount = 0;
  for (int i = 0; i < n; i++) {
    int beginNumber = numbers.front();
    cout << i << ") " << beginNumber;
    if (beginNumber % 2 != 0) {
      oddCount++;
      cout << " is odd number";
      oddNumbers.push_back(beginNumber);
    }
    numbers.pop_front();
    cout << ". Next number has to be " << numbers.front() << endl;
  }
  cout << endl
       << "Count of the even numbers: " << oddCount
       << "\nCount of the odd numbers: " << oddCount << "\n\n";

  // output odd elements from the list
  cout << "The odd list: ";
  for (int n : oddNumbers)
    cout << n << " ";
  cout << endl;
  cout << "\n\n";

  return 0;
}
