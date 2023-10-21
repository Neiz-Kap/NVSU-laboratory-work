/*
  Part 1.13 Написать функцию, которая использует исходный список L и создает два
новых списка L1 и L2. L1 содержит нечетные числа, а L2 – четные.
*/

#include <iostream>
#include <list>
#include <stdlib.h> // srand(), rand()

using namespace std;

int generateRandomNumber(int startRange, int endRange) {
  int randomValue = startRange + rand() % (endRange - startRange + 1);
  return randomValue;
}

void splitLists(list<int> &L, list<int> &L1, list<int> &L2) {
  for (int listItem : L) {
    if (listItem % 2 == 0)
      L2.push_back(listItem);
    else
      L1.push_back(listItem);
  }
}

int main() {
  srand(time(NULL));

  list<int> L;
  int n;

  cout << "Input a list number: ";
  cin >> n;

  // put values into the list
  for (int i = 0; i < n; i++) {
    L.push_back(generateRandomNumber(0, 25));
  }

  // output list items
  cout << "The initial list: "
       << "\n";
  for (int n : L)
    cout << n << " ";
  cout << "\n\n";

  // create two lists and get them to be ready from the function
  list<int> L1;
  list<int> L2;
  splitLists(L, L1, L2);

  //   output elements from the 2 lists
  // L1
  cout << "The odd list (L1): \n";
  for (int n : L1)
    cout << n << " ";
  cout << "\n\n";

  // L2
  cout << "The even list (L2): \n";
  for (int n : L2)
    cout << n << " ";
  cout << "\n\n";

  return 0;
}
