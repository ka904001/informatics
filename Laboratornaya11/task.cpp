#include <ctime>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
  //char n = '7';
  string str;
  cout<<"Enter value in range [2, 5]"<<endl;
  //cin.ignore(2, istream::eofbit);
  cin>>str;
  //cin.clear();
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  //cin.ignore(1, istream::eofbit);
  while (!((int)str[0] >= 50 && (int)str[0] <= 53&&str.length()==1)) {
    cout << "Invalid input, try again" << endl;
    //cin.ignore(2, istream::eofbit);
    cin>>str;
    //cin.get(n);
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    //cin.clear();
    //cin.ignore(256);
    //cin.ignore(1, istream::eofbit);
  }
  string a[5][5];
  string temp = "0000";
  srand(time(0));
  // cout<<"check"<<endl;
  for (int i = 0; i < (int)str[0] - 48; i++) {
    for (int k = 0; k < (int)str[0] - 48; k++) {
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
  for (int i = 0; i < (int)str[0] - 48; i++) {
    for (int k = 0; k < (int)str[0] - 48; k++) {
      int result = 0;
      for (int j = 0; j < 4; j++) {
        if (a[i][j][k] == 'A' || a[i][j][k] == 'E' || a[i][j][k] == 'I' ||
            a[i][j][k] == 'O' || a[i][j][k] == 'U')
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
