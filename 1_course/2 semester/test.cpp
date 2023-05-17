/******************************************************************************
    №1 Дан массив целых чисел из n элементов, 1) заполненный
    случайным образом числами из заданного пользователем
    промежутка.
    2) Удалить из него все элементы, в которых последняя
    цифра четная, а само число делится на нее.
    3) Отсортировать
    получившийся массив и вывести его на экран и в файл.
*******************************************************************************/

#include <algorithm> // for a sorting way
#include <cmath>
#include <fstream> // for work with files
#include <iostream>
#include <sstream>
#include <stdlib.h> // srand(), rand()
#include <string>
#include <time.h> // time()
#include <vector>

using namespace std;

void printArrayToTerminal(int *array, int length, string mark) {
  cout << endl << mark << endl;
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl << "--------------------------" << endl;
}

void printArrayToFile(int *array, int length, string mark, string fileName) {
  ofstream out(fileName);

  out << mark << endl;
  if (out.is_open()) {
    for (int i = 0; i < length; i++) {
      out << array[i] << " ";
    }
    out.close();
  } else {
    cout << "Unable to open file";
  }
}

// функция для вывода одномерного массива на экран и в файл
void printArray(int *array, int length, string mark, string fileName) {
  printArrayToTerminal(array, length, mark);
  printArrayToFile(array, length, mark, fileName);
}

void inputValidRange(int &startRange, int &endRange) {
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
}

void inputRange(int &startRange, int &endRange) {
  int n1, n2;
  cout << "Input the range of the numbers: ";
  cin >> n1 >> n2;

  if (n2 <= n1) {
    startRange = n2;
    endRange = n1;
  } else {
    startRange = n1;
    endRange = n2;
  }
}

int generateRandomNumber(int startRange, int endRange) {
  int randomValue = startRange + rand() % (endRange - startRange + 1);
  return randomValue;
}

void fillArray(int arr[], int n, int startRange, int endRange) {
  for (int i = 0; i < n; i++)
    arr[i] = generateRandomNumber(startRange, endRange);
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
  }
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
  }

  return result;
}

// ________________first task____________________

void firstTask() {
  int n, startRange, endRange;

  // check valid range values and input again, when these aren't corrected
  inputValidRange(startRange, endRange);

  cout << "Input the count of an array: ";
  cin >> n;

  int numberArray[n];

  // 1_1 заполненный случайным образом числами
  // из заданного пользователем промежутка.
  fillArray(numberArray, n, startRange, endRange);
  printArrayToTerminal(numberArray, n, "[Initail array]");

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
  int filteredArray[n - zeroValueCount], k = 0;

  // cycle for moving non-zero values to the update array
  for (int i = 0; i < n; i++) {
    if (numberArray[i] != 0) {
      filteredArray[k] = numberArray[i];
      k++;
    }
  }
  printArrayToTerminal(filteredArray, k, "[Filtered array]");

  int *sortedArray = sortArrayByBubble(filteredArray, k);
  printArray(sortedArray, k, "[Sorted array]", "result.txt");

  delete[] sortedArray;
}

/******************************************************************************

    №2 Дан двумерный массив размером n*m, заполненный
  случайными числами из заданного пользователем промежутка.
  Поменять в нем порядок строк: последнюю сделать первой,
  предпоследнюю – второй и т.д., вторую – предпоследней,
  первую сделать последней. Вывести получившийся массив на
  экран и в файл.

*******************************************************************************/

void fillMatrix(int **matrix, int rowCount, int colCount, int startRange,
                int endRange) {
  for (int x = 0; x < rowCount; x++) {
    for (int y = 0; y < colCount; y++) {
      matrix[x][y] = generateRandomNumber(startRange, endRange);
    }
  }
}

void swapRows(int **matrix, int rowCount, int colCount) {
  for (int x = 0; x < rowCount / 2; x++) {
    for (int y = 0; y < colCount; y++) {
      int temp = matrix[x][y];
      matrix[x][y] = matrix[rowCount - x - 1][y];
      matrix[rowCount - x - 1][y] = temp;
    }
  }
}

// функция для вывода двумерного массива на экран и в файл
void printMatrix(int **matrix, int rowCount, int colCount, string fileName,
                 string mark) {
  ofstream out(fileName);
  cout << mark << endl;
  out << mark << endl;
  for (int x = 0; x < rowCount; x++) {
    for (int y = 0; y < colCount; y++) {
      cout << matrix[x][y] << " ";
      out << matrix[x][y] << " ";
    }
    cout << endl;
    out << endl;
  }
  cout << endl;
  out << endl;
  out.close();
}

void secondTask() {
  int startRange, endRange;
  // check valid range values and input again, when these aren't corrected
  inputRange(startRange, endRange);

  int rowCount, colCount;
  cout << "Input the count of the row and column: ";
  cin >> rowCount >> colCount;

  int **matrix = new int *[rowCount];
  for (int i = 0; i < rowCount; ++i)
    matrix[i] = new int[colCount];

  fillMatrix(matrix, rowCount, colCount, startRange, endRange);
  printMatrix(matrix, rowCount, colCount, "init.txt", "[Initial matrix]:");

  swapRows(matrix, rowCount, colCount);
  printMatrix(matrix, rowCount, colCount, "result.txt", "[Swapped matrix]:");

  for (int i = 0; i < rowCount; ++i)
    delete[] matrix[i];
  delete[] matrix;
}

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
struct Student {
  string firstName;
  string lastName;
  int birthYear;
  int grade;
};

// Функция для сравнения учеников по фамилии
bool sortByLastName(const Student &s1, const Student &s2) {
  return s1.lastName < s2.lastName;
}

void thirdTask() {
  vector<Student> students;

  // Заполнение массива структур данными учеников
  students.push_back({"Ivan", "Mekhedov", 2002, 5});
  students.push_back({"Danil", "Ryabushkin", 2004, 1});
  students.push_back({"Maxim", "Kostinov", 2004, 1});
  students.push_back({"Gleb", "Ahtyamov", 2004, 1});
  students.push_back({"Andrey", "Titarenko", 2003, 4});
  students.push_back({"Alex", "Nevecherya", 2001, 4});
  students.push_back({"Nikita", "Mamedov", 2004, 1});

  cout << "[INFO] Initial array of students:" << endl;
  for (const auto &student : students) {
    cout << student.lastName << ", " << student.firstName << " (Grade "
         << student.grade << ")" << endl;
  }
  cout << endl;

  // Сортировка списка учеников по фамилии
  sort(students.begin(), students.end(), sortByLastName);

  // Вывод отсортированного списка учеников
  cout << "[INFO] Sorted Students List:" << endl;
  for (const auto &student : students) {
    cout << student.lastName << ", " << student.firstName << " (Grade "
         << student.grade << ")" << endl;
  }
  cout << endl;

  // Ввод буквы для фильтрации учеников
  char letter;
  cout << "Enter a letter to filter students by last name: ";
  cin >> letter;

  // Вывод учеников, фамилия которых начинается с заданной буквы
  int count = 0;
  cout << "[INFO] Students with last name starting with letter '" << letter
       << "':" << endl;
  for (const auto &student : students) {
    if (student.lastName[0] == letter) {
      cout << student.lastName << ", " << student.firstName << " (Grade "
           << student.grade << ")" << endl;
      count++;
    }
  }
  if (count == 0)
    cout << "No found student(s) with current letter in the last name" << endl;
  cout << endl;

  // Запись данных учеников в файл
  ofstream outFile("students.txt");
  if (outFile.is_open()) {
    for (const auto &student : students) {
      outFile << student.firstName << " " << student.lastName << " "
              << student.birthYear << " " << student.grade << "\n";
    }
    outFile.close();
    cout << "[SUCCESS] Data has been written to students.txt" << endl << endl;
  } else {
    cout << "[ERROR] Failed to open file for writing!" << endl;
  }

  // Чтение данных учеников из файла
  vector<Student> studentsFromFile;
  ifstream inFile("students.txt");
  if (inFile.is_open()) {
    string line;
    while (getline(inFile, line)) {
      istringstream iss(line);
      string firstName, lastName;
      int birthYear, grade;
      if (iss >> firstName >> lastName >> birthYear >> grade) {
        studentsFromFile.push_back({firstName, lastName, birthYear, grade});
      } else {
        cout << "[ERROR] Failed to parse line: " << line << endl;
      }
    }
    inFile.close();

    // Вывод учеников из файла
    cout << "[INFO] Students read from file:" << endl;
    for (const auto &student : studentsFromFile) {
      cout << student.lastName << ", " << student.firstName << " (Grade "
           << student.grade << ")" << endl;
    }
  } else {
    cout << "[ERROR] Failed to open file for reading!" << endl;
  }
}

int main() {
  srand(time(NULL));
  int a;
  do {
    printf("Input: \n");
    printf("1 and Enter - output the first task\n");
    printf("2 and Enter - output the second task\n");
    printf("3 and Enter - output the third task\n");
    printf("0 and Enter - for exit from a subprogram\n");

    scanf("%d", &a);

    switch (a) {
    case 0:
      break;

    case 1:
      firstTask();
      break;
    case 2:
      secondTask();
      break;
    case 3:
      thirdTask();
      break;

    default:
      cout << "Your input is invalid. \n Try entering a number from 0 to 3"
           << endl;
      break;
    }

  } while (a != 0);
  return 0;
}
