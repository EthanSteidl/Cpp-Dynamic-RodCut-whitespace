#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
holds row cost and total cost so far
*/
struct RowandTotal
{
	unsigned long long row_cost;
	unsigned long long total_cost;
};

/*
class to solve poster/bilboard problem
I think of it as books on a bookcase with witespace
at the end. Hence Bookcase
*/
class Bookcase
{


private:
	unsigned long long DMAX = ULLONG_MAX;	//value for INFINITY
	int max_width;		//max width for a shelf
	int books[400];		//array to hold posters
	int total_books;	//count of posters
	

	int shortest_height = INT_MAX; //shortest height calculated for speed up 
									//not required

	RowandTotal **cost_table = new RowandTotal*[400];	//table to hold dynamic calculations
	
public:
	void rod_cutting(int start, unsigned long long current_cost, int current_height);
	bool update_cost(int start, int end, int width, unsigned long long current_cost, int current_height);
	bool update_cost_inf(int start, int end);
	void print();
	void solve();
	int sum_width(int start, int end);
	Bookcase(int width, int book_count, int* book_arr);
	~Bookcase();
};

