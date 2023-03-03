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
#include <iostream>
#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()

using namespace std;

// 1_1 заполненный случайным образом числами
// из заданного пользователем промежутка.
int getRandomValue(int min, int max)
{
  srand(time(NULL));
  return min + rand() % (max - min + 1);
}

// 1_2 Удалить из него все элементы, в которых последняя
//     цифра четная, а само число делится на нее.
int *removeEvenNumbersFromArray(int *array, int arraySize)
{
  int updateArraySize = arraySize;

  // cycle for replacing "even" numbers with "0"
  for (int j = 0; j < arraySize; j++)
  {
    int lastDigit = array[j] % 10;

    if (lastDigit % 2 == 0 && array[j] % lastDigit == 0)
    {
      array[j] = 0;
      updateArraySize--;
    }
  }

  int updateArray[updateArraySize], i = 0;
  // for transfering non-zero values to other array
  for (int j = 0; j < arraySize; j++)
  {
    if (array[j] != 0)
    {
      updateArray[i] = array[j];
      i++;
    }
  }

  return updateArray;
}

void firstTask()
{
  int n, intervalStart, intervalEnd;

  while (true)
  {
    cout << "Input start of the interval: ";
    cin >> intervalStart;

    cout << "Input end of the interval: ";
    cin >> intervalEnd;

    if (intervalStart >= intervalEnd)
    {
      cout << "You might write same values or you mixed up start and end of interval." << endl
           << "Repeat again!" << endl;
      continue;
    }
    break;
  }

  cout << "Input array count: ";
  cin >> n;

  int numberArray[n];

  for (int i = 0; i < n; i++)
  {
    numberArray[i] = getRandomValue(intervalStart, intervalEnd);
    cout << i + 1 << ") " << numberArray[i] << endl;
  }

  int *updateArray = removeEvenNumbersFromArray(numberArray, n);
  for (int i = 0; i < n; i++)
  {
    cout << i + 1 << ") " << updateArray[i] << endl;
  }
}

int main()
{
  firstTask();
  //   secondTask();
  //   thirdTask();
  return 0;
}
