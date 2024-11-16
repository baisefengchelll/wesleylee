#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  fstream file;
  // open the file
  file.open("test.txt", ios::out);
  if(!file.is_open()){
    cout << "The file didn't be opened rightly!"<<endl;
    return -1;
  }
  
  // operate the file
  file << "This is the write file" << endl;
  file << "Hello world!!!" << endl;
  file << "Operation finished!" << endl;

  // close the file
  file.close();
  return 0;
}