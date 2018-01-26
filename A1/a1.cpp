//Andrew Gorovoy
//CSCI 2270
//Assignment 1



#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
/* define item struct with three attributes */
struct item {
	string type;
	int stat;
	string price;
};
/*
this is the function that reads file lines and implements necessary logic for checking the array for matches
First, I go through the array of items and initialize every array element
Then I open the file and begin reading in line by line.
First line is automatically placed into the array.
Then every line after that is compared to the items stored in the array. If an item is a match, then that elemnt in the array with which the match was made is nullified, and comparison
item is never stored in the array, and the match is printed to the console. If item is not a match, then it is stored in next open spot in the array
*/
void readCheck(string filename) {
	string line;
	string tempType;
	string tempStat;
	string tempPrice;
	item itemArray[100];
	for (int z = 0; z < 100; z++)
	{
		itemArray[z].type = "init";
		itemArray[z].stat = 10;
		itemArray[z].price = "init";
	}
	item compareItem;
	int check = 0;
	int arrayCount = 0;
	fstream dd;
	dd.open(filename);
	if (dd.is_open()) {
		while (!dd.eof())
		{
			getline(dd,line);
			stringstream ss(line);         //breaking down each line for storing in variables
			getline(ss,tempType,',');
			getline(ss,tempStat,',');
			getline(ss,tempPrice);
			compareItem.type = tempType;   //stores things into a comparison item struct
			if (tempStat == " wanted") {
				compareItem.stat = 1;
			} else {
				compareItem.stat = 0;
			}
			compareItem.price = tempPrice;

			if (arrayCount == 0) {                         //whole process for checking the arrays
				itemArray[arrayCount] = compareItem;
				arrayCount++;
			} else {
				check = 0;
				for (int i = 0; i < arrayCount; i++)
				{
					if ((itemArray[i].type == compareItem.type) && (itemArray[i].stat != compareItem.stat)) {
						if (   (  itemArray[i].stat == 1 && stoi(itemArray[i].price) >= stoi(compareItem.price)   ) || (compareItem.stat == 1 && stoi(compareItem.price) >= stoi(itemArray[i].price)   ) ) {
							if (stoi(compareItem.price) < stoi(itemArray[i].price)) {
								cout << compareItem.type << compareItem.price << endl;
							} else {
								cout << compareItem.type << itemArray[i].price << endl;
							}
							itemArray[i].type = "0";
							itemArray[i].stat = 0;
							itemArray[i].price = "0";
							check = 1;
							break;

						}

					}
				}
				if (check == 0) {
					itemArray[arrayCount] = compareItem;
					arrayCount++;
				}
			}


		}
/*
This is the printing part of the function. Every element in the array that has not been nullified therefore has not had a match, so it is printed to the console
*/
		dd.close();

	} else {
		dd.close();
	}
	cout << "#\n";
	for (int j = 0; j < 100; j++)
	{
		if (itemArray[j].type == "bike" || itemArray[j].type == "truck" || itemArray[j].type == "dresser" || itemArray[j].type == "chicken" || itemArray[j].type == "microwave") {
			if (itemArray[j].stat == 1) {
				cout << itemArray[j].type << ", wanted," << itemArray[j].price << endl;

			} else {
				cout << itemArray[j].type << ", for sale," << itemArray[j].price << endl;
			}
		}

	}
}
/*
This is the main of this program. Takes in command line arguements and passes it over to the readCheck function
*/
int main(int argc, char *argv[]) {
	/*string file_name;
	string test;
	cout << "Hello Shopper!!! Welcome to Andrew's E-Store. Before we continue, I do need to warn you about consuming raw chicken as we sell it on this site. Please type yes if assume the risks of chicken and press enter.\n";
	cin >> test;
	cout << "Great. Please enter your filename now and press enter!!\n";
	cin >> file_name;*/


	readCheck(argv[1]);
	cout << "#" << endl;
	//cout << endl << endl;






}
