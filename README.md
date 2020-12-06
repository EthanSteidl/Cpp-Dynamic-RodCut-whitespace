# Rod-Cutting-whitespace-version
This is an implementation of the Rod Cutting algorithm that will evenly distribute cost among buckets where the object distributed is unable to be rearanged.

## What problem does this solve
Assume you have n books each having a width d. How can the books be placed on the bookshelf so the whitespace at the end of the shelf is as even as possible. The books are not
allowed to be rearranged. Find a solution utilizing the least shelves then the solution anong those that has the most even whitespace.

## Algorithm
This utilizes a top down rod cutting approach to solve the issue. This dynamic algorithm runs in N lg2 N where N is the amount of books.
--Note: There is an error in this example that causes the algorithm to scale linearly with shelf width. Causing this implementation to run in N * W lg2 N time. Where W is the widht of the shelf

## Usage
See the main.cpp for example code.
