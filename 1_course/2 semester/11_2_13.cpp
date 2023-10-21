/*
  Part 2.13 Составить программу, которая формирует список L, включив в него по
одному разу элементы, которые входят в один из списков L1 и L2, но в то же время
не входят в другой. Проще для понимания: (L1 / L2) U (L2 / L1)
*/

// Сложность алгоритма: O(2n^2)

// Example:
// L1: 1, 10, 3, 3, 5, 2, 6, 9
// L2: 20, 30, 1, 3, 6, 12, 5, 7, 9
// L after first couple of cycles: 10, 2
// L after second couple of cycles: 20, 30, 12, 7

// L has to have following items: 10, 2, 20, 30, 12, 7

#include <iostream>
#include <stdlib.h> // srand(), rand()
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int generateRandomNumber(int startRange, int endRange) {
  int randomValue = startRange + rand() % (endRange - startRange + 1);
  return randomValue;
}

int main() {
  srand(time(NULL));

  vector<int> L1;
  vector<int> L2;
  int L1Size, L2Size;
  cout << "Input a size for first list: ";
  cin >> L1Size;
  cout << "Input a size for second list: ";
  cin >> L2Size;

  cout << "\n"
       << "We have following values in the lists:"
       << "\n";
  cout << "L1: ";
  for (int i = 0; i < L1Size; i++) {
    L1.push_back(generateRandomNumber(0, 10));
    cout << L1.back() << " ";
  }
  cout << "\n";
  cout << "L2: ";
  for (int k = 0; k < L2Size; k++) {
    L2.push_back(generateRandomNumber(0, 10));
    cout << L2.back() << " ";
  }
  cout << "\n";

  int isThereMatches = false;
  vector<int> L;

  for (int L1Item : L1) {
    for (int L2Item : L2) {
      if (L1Item == L2Item) {
        isThereMatches = true;
      }
    }
    if (!isThereMatches) {
      L.push_back(L1Item);
    }
    isThereMatches = false;
  }

  for (int L2Item : L2) {
    for (int L1Item : L1) {
      if (L1Item == L2Item) {
        isThereMatches = true;
      }
    }
    if (!isThereMatches) {
      L.push_back(L2Item);
    }
    isThereMatches = false;
  }

  cout << "L: ";
  for (int LItem : L) {
    cout << LItem << " ";
  }
}