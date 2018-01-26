#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct CarData {
  string model;
  string make;
  string year;

};

void dataIO(CarData array[], string in_file_name, string out_file_name, int number_of_lines) {
  ifstream ff;
  string line;

  string carModel;
  string carMake;
  string carYear;
  int i = 0;


  ff.open(in_file_name);
  if (ff.is_open()) {
    while(getline(ff,line))
    {
      stringstream ss(line);
      getline(ss,array[i].make,' ');
      getline(ss,array[i].model,' ');
      getline(ss,array[i].year);

      i++;


    }

    ff.close();
  } else {
    ff.close();
  }

  ofstream oo;

  oo.open(out_file_name);
  if (oo.is_open()) {
    for (int j = 0; j < number_of_lines; j++)
    {
      oo << array[j].make << '\t' << array[j].model << '\t' << array[j].year << endl;
    }

  } else {
    oo.close();
  }



}

int main(int argc, char * argv[]) {
  string ifile = argv[1];
  int numLine = stoi(argv[2]);
  string ofile = argv[3];

  CarData carArray[numLine];
  dataIO(carArray,ifile,ofile, numLine);

}
