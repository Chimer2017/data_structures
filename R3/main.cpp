/* Quiz Answer

1. first one is creating a dynamic single int variable while the second one is creating a dynamic array with 25 elements intially

2. Because it is passing that actual array to the function

3.

*/


#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  string line;
  int n = 10;
	int *a;
  a = new int[n];
  int i = 0;
  int limit = 10;
  int *temp;



  fstream data;
  data.open(argv[1]);

  if (data.is_open()) {
    while(getline(data,line))
    {
      a[i] = stoi(line);
      //cout << a[i] << endl;
      i++;



      if (i == limit) {
        temp = new int[2*limit];
        for( int z = 0; z < limit; z++ )
        {
          temp[z] = a[z];
        }
        delete [] a;

        a = temp;
        temp = nullptr;
        limit = 2 * i;



      }

    }

  } else {
    data.close();
    cout << "file did not open" << endl;
  }

  for (int j = 0; j < i; j++)
  {
    cout << a[j] << endl;
  }

  cout << i;



  return 0;




}
