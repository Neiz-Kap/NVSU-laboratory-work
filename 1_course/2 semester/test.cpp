/******************************************************************************
    №1 Дан массив целых чисел из n элементов, 1) заполненный
    случайным образом числами из заданного пользователем
    промежутка.
    2) Удалить из него все элементы, в которых последняя
    цифра четная, а само число делится на нее.
    3) Отсортировать
    получившийся массив и вывести его на экран и в файл.
*******************************************************************************/

/******************************************************************************

    №2 Дан двумерный массив размером n*m, заполненный
  случайными числами из заданного пользователем промежутка.
  Поменять в нем порядок строк: последнюю сделать первой,
  предпоследнюю – второй и т.д., вторую – предпоследней,
  первую сделать последней. Вывести получившийся массив на
  экран и в файл.

*******************************************************************************/

/******************************************************************************

  №3 Создать массив, элементами которого являются структуры –
  список учеников. В записи должны содержаться имя, фамилия
  ученика, год рождения, класс. Вывести на экран
  отсортированный список по фамилии ученика.
  Запрограммировать возможность вывода всех учеников,
  фамилия которых начинается с буквы, введенной
  пользователем, запись данных в файл и чтение из файла уже
  записанных данных.

*******************************************************************************/
#include <algorithm> // for a sorting way
#include <fstream>   // for work with files
#include <iostream>
#include <stdlib.h> // srand(), rand()
#include <string>
#include <time.h> // time()

using namespace std;

void logElement(int item) { cout << item << " "; }

void logArrayNameAndCount(string arrayMark, int count) {
  cout << endl << "[" << arrayMark << "] Count of the array: " << count << endl;
}

void fillArray(int arr[], int n, int startRange, int endRange) {
  for (int i = 0; i < n; i++) {
    arr[i] = startRange + rand() % (endRange - startRange + 1);
    logElement(arr[i]);
  }
  logArrayNameAndCount("Initial array", n);
}

// 1_2 Удалить из него все элементы, в которых последняя
//     цифра четная, а само число делится на нее.
void transformArray(int array[], int n, int newArray[]) {
  int zeroValueCount = 0;
  for (int i = 0; i < n; i++) {
    int lastDigit = array[i] % 10;

    if (lastDigit % 2 != 0 || array[i] % lastDigit != 0) {
      newArray[zeroValueCount] = array[i];
      zeroValueCount++;
    }
  }
}

int *sortArrayByLibrary(int array[], int length) {
  int *result = new int[length];

  copy(array, array + length, result);
  sort(result, result + length);

  for (int i = 0; i < length; i++) {
    logElement(result[i]);
  }
  logArrayNameAndCount("Sorted array", length);
  return result;
}

int *sortArrayByBubble(int array[], int length) {
  int *result = new int[length];

  for (int i = 0; i < length; i++) {
    result[i] = array[i];
  }

  for (int i = 0; i < length - 1; i++) {
    for (int m = 0; m < length - 1; m++) {
      if (result[m] > result[m + 1]) {
        int tempNumb = result[m];
        result[m] = result[m + 1];
        result[m + 1] = tempNumb;
      }
    }
  }
  for (int i = 0; i < length; i++) {
    logElement(result[i]);
  }
  logArrayNameAndCount("Sorted array", length);

  return result;
}

void firstTask() {
  int n, startRange, endRange;

  // check valid range values and input again, when these aren't corrected
  while (true) {
    cout << "Input the range of the numbers (startRange and endRange): ";
    cin >> startRange >> endRange;

    if (startRange >= endRange) {
      cout << "You might write same values or you mixed up start and end of "
              "the range."
           << endl
           << "Repeat again!" << endl;
      continue;
    }
    break;
  }

  cout << "Input the count of a array: ";
  cin >> n;

  int numberArray[n];

  // 1_1 заполненный случайным образом числами
  // из заданного пользователем промежутка.
  fillArray(numberArray, n, startRange, endRange);

  // find out a count of zero values
  int zeroValueCount = 0;
  for (int i = 0; i < n; i++) {
    int lastDigit = numberArray[i] % 10;

    if (lastDigit != 0 && lastDigit % 2 == 0 &&
        numberArray[i] % lastDigit == 0) {
      numberArray[i] = 0;
      zeroValueCount++;
    }
  }

  // create update array
  int updateArray[n - zeroValueCount], k = 0;
  cout << endl << "--------------------------" << endl;
  // cycle for moving non-zero values to the update array
  for (int i = 0; i < n; i++) {
    if (numberArray[i] != 0) {
      updateArray[k] = numberArray[i];
      logElement(updateArray[k]);
      k++;
    }
  }
  logArrayNameAndCount("Filtered array", k);

  cout << endl << "--------------------------" << endl;

  int *sortedArray = sortArrayByBubble(updateArray, k);

  ofstream outFile("output.txt");

  if (outFile.is_open()) {
    for (int i = 0; i < k; i++) {
      outFile << sortedArray[i] << " ";
    }
    outFile.close();
  } else {
    cout << "Unable to open file";
  }

  delete[] sortedArray;
}

int main() {
  srand(time(NULL));
  firstTask();
  //   secondTask();
  //   thirdTask();
  return 0;
}
