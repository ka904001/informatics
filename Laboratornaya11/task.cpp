#include <ctime>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int main() {
  string str;
  cout << "Enter value in range [2, 5]" << endl;
  cin >> str;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (!((int)str[0] >= 50 && (int)str[0] <= 53 && str.length() == 1)) {
    cout << "Invalid input, try again" << endl;
    cin >> str;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  string a[5][5];
  string temp = "0000";
  srand(time(0));
  for (int i = 0; i < (int)str[0] - 48; i++) {
    for (int k = 0; k < (int)str[0] - 48; k++) {
      for (int j = 0; j < 4; j++) {
        a[i][k][j] = (char)(65 + rand() % 26);
        cout<<a[i][k][j];
      }
      cout<<' ';
    }
    cout << endl;
  }
  int mas[25]{0};
  for (int i = 0; i < (int)str[0] - 48; i++) {
    for (int k = 0; k < (int)str[0] - 48; k++) {
      int result = 0;
      for (int j = 0; j < 4; j++) {
        if (a[i][k][j] == 'A' || a[i][k][j] == 'E' || a[i][k][j] == 'I' ||
            a[i][k][j] == 'O' || a[i][k][j] == 'U')
          result++;
      }
      mas[i * ((int)str[0] - 48) + k] = result;
    }
  }
  for (int i = 0; i < ((int)str[0] - 48) * ((int)str[0] - 48); i++) {
    cout << mas[i] << ' ';
  }
  return 0;
}
