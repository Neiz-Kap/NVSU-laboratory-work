/*
  Part 2.8 Составить программу, которая вставляет в список L все элементы, после
первого вхождения элемента Е все элементы списка L, если Е входит в L.
*/

#include <iostream>
#include <list>
#include <stdlib.h> // srand(), rand()

using std::cin;
using std::cout;
using std::list;

int generateRandomNumber(int startRange, int endRange) {
  int randomValue = startRange + rand() % (endRange - startRange + 1);
  return randomValue;
}

int main() {
  srand(time(NULL));

  list<int> L;
  int LSize;
  cout << "Input a size for first list: ";
  cin >> LSize;

  // putting values to L list
  cout << "\n"
       << "We have following values in the list L:"
       << "\n";
  for (int i = 0; i < LSize; i++) {
    L.push_back(generateRandomNumber(0, 30));
    cout << L.back() << " ";
  }
  cout << "\n";

  int E;
  cout << "\nInput the value (E): ";
  cin >> E;

  list<int>::iterator it = L.begin();

  while (it != L.end()) {
    if (*it == E)
      break;
    ++it;
  }

  if (it != L.end()) {
    ++it;

    list<int> temporaryList(it, L.end());
    L.insert(it, temporaryList.begin(), temporaryList.end());
  } else {
    cout << "\n The L list doesn't contain such value E, so the list hasn't "
            "changed. \n";
  }

  cout << "The list L: ";
  for (int LItem : L) {
    cout << LItem << " ";
  }
  cout << "\n";

  return 0;
}