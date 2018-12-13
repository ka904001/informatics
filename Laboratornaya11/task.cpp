#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  char n = '7';
  cin >> n;
  while (!((int)n >= 50 && (int)n <= 53)) {
    cout << "Invalid input, try again" << endl;
    cin >> n;
  }
  string a[5][5];
  string temp = "0000";
  srand(time(0));
  // cout<<"check"<<endl;
  for (int i = 0; i < (int)n - 48; i++) {
    for (int k = 0; k < (int)n - 48; k++) {
      for (int j = 0; j < 4; j++) {
        // cout<<"check"<<endl;
        temp[j] = (char)(65 + rand() % 26);
        // cout<<temp<<' ';
      }
      a[i][k] = temp;
      cout << a[i][k] << ' ';
    }
    cout << endl;
  }
  int mas[25]{0};
  for (int i = 0; i < (int)n - 48; i++) {
    for (int k = 0; k < (int)n - 48; k++) {
      int result = 0;
      for (int j = 0; j < 4; j++) {
        if (a[i][j][k] == 'A' || a[i][j][k] == 'E' || a[i][j][k] == 'I' ||
            a[i][j][k] == 'O' || a[i][j][k] == 'U')
          result++;
      }
      mas[i * ((int)n - 48) + k] = result;
    }
  }
  for (int i = 0; i < ((int)n - 48) * ((int)n - 48); i++) {
    cout << mas[i] << ' ';
  }
  return 0;
}
