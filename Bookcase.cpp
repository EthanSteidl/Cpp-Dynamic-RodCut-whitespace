#include "Bookcase.h"


/*
Author: Ethan Steidl
Prints out to the screen cuts and total poster width
per shelf of the billboard

*/
void Bookcase::print()
{
	

	unsigned long long smallest_cost = DMAX;	//smallest cost found
	unsigned long long row_cost = DMAX;			//cost of current row


	int end = total_books - 1;	//last index of a poster on a shelf
	int start = end;			//first index of poster on a shelf
	int proper_start = end;		//saved first index for displaying

	bool first_run = true;		//if first run conditional
	vector<string> output;		//output comes out in reverse order, this
								//vector is used to reverse the output order
	/*
		loops starting from the end finding the cheapest set ending with the final
		poster. once found, find the cheapest set ending with the poster before the
		first in the previous set.  Once complete and back to the start print out
		results in proper order rather than reverse order
	*/
	while (start != -1)
	{

		//finds smallest cost set for an ending index
		if (cost_table[start][end].total_cost <= smallest_cost)
		{
			smallest_cost = cost_table[start][end].total_cost;
			proper_start = start;	//this is the propper start of the set
			row_cost = cost_table[start][end].row_cost;
		}
		
		start = start - 1;

		//if we have reached in infinite value, or the beginning of the posters
		//add the correct output to the ouptut vector
		if ( (start < 0) || (cost_table[start][end].total_cost == DMAX))
		{
			if (first_run)
			{

				cout << "Board Cost: " << smallest_cost << endl;
				string words = "(" + to_string(proper_start + 1) + ", " + to_string(end + 1) + ") --> " + to_string(sum_width(proper_start, end));
				output.push_back(words);
				first_run = false;
			}
			else
			{
				string words = "(" + to_string(proper_start + 1) + ", " + to_string(end + 1) + ") --> " + to_string(sum_width(proper_start, end));
				output.push_back(words);
			}

			//reset end and starts
			end = proper_start - 1;
			proper_start = end;
			start = end;
		}

	}

	//print out vector in reverse order
	for (vector<string>::reverse_iterator i = output.rbegin(); i != output.rend(); i++)
	{
		cout << *i << endl;
	}
	cout << endl;


}

/*
Author: Ethan Steidl
Sums width of a shelf
*/
int Bookcase::sum_width(int start, int end)
{
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += books[i];
	return sum;
}

/*
Author: Ethan Steidl
Constructor setting internal 2d array to infinity
takes width of billboard, poster count and the poster wieights
*/
Bookcase::Bookcase(int width, int book_count, int* book_arr)
{
	max_width = width;
	total_books = book_count;

	for (int i = 0; i < 400; i++)
	{
		cost_table[i] = new RowandTotal[400];
		RowandTotal rt;
		rt.row_cost = DMAX;
		rt.row_cost = DMAX;
		for (int j = 0; j < 400; j++)
			cost_table[i][j] = rt;
	}

	
	
	//cout << "width = " << width << " books = " << book_count << "\nBook widths:\n";
	for (int i = 0; i < total_books; i++)
	{
		books[i] = book_arr[i];
		//cout << books[i] << " ";
	}

	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++)
			cost_table[i][j] = RowandTotal{ DMAX,DMAX };
	cout << endl;
	
}

/*
Author: Ethan
delets dynamic array
*/
Bookcase::~Bookcase()
{
	for (int i = 0; i < 400; i++)
		delete[] cost_table[i];
	delete[] cost_table;
}



/*
Performs a recursive rod cutting algorithm on the posters
*/
void Bookcase::rod_cutting(int start, unsigned long long current_cost, int current_height)
{

	int i;
	int temp_width = 0;
	unordered_map<int, bool> duplicates;

	//loops setting the weights of book sets
	//if there are reused values make note
	//once an infinite cost is reached, break early
	for (i = start; i < total_books; i++)
	{
		temp_width = temp_width + books[i];
		if (temp_width <= max_width)
			duplicates[i] = update_cost(start, i, temp_width, current_cost, current_height);
		else
			continue;

	}

	//reverse the order of the indexes to start itterating for faster solution
	vector<int> values;
	//checks to not repeat duplicates, and not dive down paths that are bad
	for (int j = start; (j < i - 1) && (duplicates[j] == true) && (current_height <= shortest_height); j++)
		values.push_back(j + 1);

	for (auto it = values.rbegin(); it != values.rend(); it++ ) /*&& (current_height < shortest_height)*/ //if lt and not in bad values
	{
		//GRADING: REUSE in for loop
		//for each valid combo for the row found, try starting at the last book
		rod_cutting(*it, cost_table[start][*it - 1].total_cost, current_height + 1); //j+1 since cant start at the same book as last
	}
	
}



/*
Author: Ethan Steidl
updates the cost of books
returns true if cost updated
returns false if cost was worse and not updated
*/
bool Bookcase::update_cost(int start, int end, int width, unsigned long long current_cost, int current_height)
{
	//GRADING:UPDATE this is where i update normally, this is the first update

	//find row cost, if last item set cost to 0
	unsigned long long row_cost; 
	if (end == total_books - 1)
		row_cost = 0;
	else
		row_cost = pow(max_width - width, 3);

	//find row and total cost
	RowandTotal rt;
	rt.row_cost = row_cost;
	rt.total_cost = current_cost + row_cost;

	//attempts to update cost, if new cost is worse return false
	if (rt.total_cost < cost_table[start][end].total_cost)
		cost_table[start][end] = rt;
	else
		return false;

	//sets shortest height to speed up other calculations slightly
	if ( (end == total_books - 1) && current_height < shortest_height)
	{
		shortest_height = current_height;
	}
	return true;
}


/*
Author: Ethan Steidl
starts the rod cutting solution
*/
void Bookcase::solve()
{
	rod_cutting(0, 0, 0);
	return;
}