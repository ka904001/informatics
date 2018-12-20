#include <ctime>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

void checking(string &str, int size, int start, int end) {
  cin >> str;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка входящего потока
  for (int i = 0; i < size; i++) {//проверка всех букв на соответсвие заданным критериям
    while (
        !((int)str[i] >= start && (int)str[i] <= end && str.length() == size)) {
      cout << "Invalid input, try again" << endl;
      cin >> str;
      i = 0;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
};

void sortingg(int a[], int start, int end){
  int min = 0;
  for(int i = start; i < end; i++){
    min = i;
    for(int k = i; k < end; k++){
      if(a[k] < a[min]){min = k;}
    }
    int tmp = a[min];
    a[min] = a[i];
    a[i] = tmp;
  }
}

int main() {
  string str, str1;
  int m = 0;
  cout << "Enter value in range [2, 5]" << endl;
  checking(str, 1, 50, 53);
  cout << "If you wish to type in values manually, type 1, if not, type 2"
       << endl;
  checking(str1, 1, 49, 50);
  string a[5][5];//Объявление массива (большего размера он быть не может)
  m = (int)str[0] - 48;//получение размера массива
  if (str1 == "1") {
    string str2;
    for (int i = 0; i < m; i++) {
      for (int k = 0; k < m; k++) {
        checking(str2, 4, 65, 90);//проверка ввода
        a[i][k] = str2;
      }
    }
    for (int i = 0; i < m; i++) {//вывод массива
      for (int k = 0; k < m; k++) {
        cout<<a[i][k]<<' ';
      }
      cout<<endl;
    }
  } else {
    srand(time(0));
    for (int i = 0; i < m; i++) {
      for (int k = 0; k < m; k++) {
        for (int j = 0; j < 4; j++) {
          a[i][k][j] = (char)(65 + rand() % 26);//Добавление случайного символа
          cout << a[i][k][j];
        }
        cout << ' ';
      }
      cout << endl;
    }
  }
  int mas[25]{0};//Из условий задачи массив не может быть больше 25
  for (int i = 0; i < m; i++) {
    for (int k = 0; k < m; k++) {
      int result = 0;
      for (int j = 0; j < 4; j++) {//поиск гласных
        if (a[i][k][j] == 'A' || a[i][k][j] == 'E' || a[i][k][j] == 'I' ||
            a[i][k][j] == 'O' || a[i][k][j] == 'U')
          result++;
      }
      mas[i * m + k] = result;//запись в массив
    }
  }
  for (int i = 0; i < m * m; i++) {//вывод массива
    cout << mas[i] << ' ';
  }
  cout<<endl;
  sortingg(mas, 0, m*m);//сортировка
  for (int i = 0; i < m * m; i++) {//вывод отсортированного массива
    cout << mas[i] << ' ';
  }
  return 0;
}
