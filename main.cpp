#include <iostream>
#include <fstream>
#include <vector>
#include <map> 
#include "Bookcase.h"

using namespace std;



void get_input(int& width, int& count, int* announcements);
void get_input_file(int& width, int& count, int* announcements, char* filename);
void test(int width, int count, int* announcements, char* filename);
void run_tests();

/*
Author: Ethan Steidl
Runs program to do rod cutting on
the billboard poster problem

---------------------
SOLVES ALL TEST CASES
---------------------


*/
int main()
{
	int width = 0;
	int count = 0;
	int announcements[400];

	//THIS RUNS TESTS
	//run_tests();
	
	get_input(width, count, announcements);
	Bookcase x = Bookcase(width, count, announcements);
	x.solve();	//solve solution
	x.print();	//print solution
	
	return 0;
}

/*
Author: Ethan Steidl
Runs test cases
*/
void run_tests()
{
	int width = 0;
	int count = 0;
	int announcements[400];

	char file0[20] = "test0.txt\0";
	cout << "test 0";
	test(width, count, announcements, file0);
	char file1[20] = "test1.txt\0";
	cout << "test 1";
	test(width, count, announcements, file1);
	char file2[20] = "test2.txt\0";
	cout << "test 2";
	test(width, count, announcements, file2);
	char file3[20] = "test3.txt\0";
	cout << "test 3";
	test(width, count, announcements, file3);

	char file4[20] = "test4.txt\0";
	cout << "test 4";
	test(width, count, announcements, file4);
	char file5[20] = "test5.txt\0";
	cout << "test 5";
	test(width, count, announcements, file5);

	char file6[20] = "test6.txt\0";
	cout << "test 6";
	test(width, count, announcements, file6);
	char file7[20] = "test7.txt\0";
	cout << "test 7";
	test(width, count, announcements, file7);

	char file8[20] = "test8.txt\0";
	cout << "test 8";
	test(width, count, announcements, file8);
	char file9[20] = "test9.txt\0";
	cout << "test 9";
	test(width, count, announcements, file9);

	char file10[20] = "test10.txt\0";
	cout << "test 10";
	test(width, count, announcements, file10);

	//note extra newline in test file
	char file11[20] = "test11.txt\0";
	cout << "\ntest 11";
	test(width, count, announcements, file11);
}

/*
Author: Ethan Steidl
Performs given test
*/
void test(int width, int count, int* announcements, char* filename)
{
	get_input_file(width, count, announcements, filename);
	Bookcase x = Bookcase(width, count, announcements);
	x.solve();
	x.print();
}

/*
Author: Ethan Steidl
Gets input from a file
*/
void get_input_file(int& width, int& count, int* announcements, char* filename)
{

	
	ifstream fin(filename);
	fin >> width;
	fin >> count;
	for (int i = 0; i < count; i++)
	{
		fin >> announcements[i];
	}
	fin.close();



}

/*
Author: Ethan Steidl
gets user input
*/
void get_input(int& width, int& count, int* announcements)
{

	cin >> width;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> announcements[i];
	}


}