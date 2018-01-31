#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



int main() {
  string word;
  string line;

  int x = 0;
  ifstream ff;
  ff.open("/Users/agorovoy/Desktop/data_structures/A2/fullText.txt");

  if (ff.is_open()) {
    while(x < 10)
    {
      getline(ff,line);

      stringstream ss(line);
      while (ss>>word)
      {
        cout << word << endl;
      }
      x++;
    }


  } else {

    ff.close();
  }
}



//______________-----------_______----_-_---_-_-_-_--_---_-_--_-_-__

stopCheck = isStopWord(a,ignoreWords);
if (stopCheck == true) {
    doNothing();
} else {
    if (wordCount == 0) {
        mainWordArray[j].word = a;
        mainWordArray[j].count = 1;
        a="";
        j++;
        wordCount++;
    } else {
        uniqueCheck = isUniqueWord(a,mainWordArray,wordCount);
        if (uniqueCheck != -1) {
            mainWordArray[uniqueCheck].count++;
            a="";
    } else if (uniqueCheck == -1) {
        mainWordArray[j].word = a;
        mainWordArray[j].count++;
        a="";
        j++;
        wordCount++;
  }









  if (wordCount == limit) {
    doubleCount++;
    item *temp;
    temp = new item[2*n];

    for (int z = 0; z < limit; z++)
    {
      temp[z].word = mainWordArray[z].word;
      temp[z].count = mainWordArray[z].count;
    }
    delete [] mainWordArray;
    mainWordArray = temp;
    temp = nullptr;
    limit = 2 * wordCount;

  }
