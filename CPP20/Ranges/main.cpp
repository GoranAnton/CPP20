#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // Filter even numbers and transform them

    auto result = numbers
        | std::ranges::views::filter( [](int n) { return n % 2 == 0; })  // using (int& n) would introduce a pointer indirection for no benefit
        | std::ranges::views::transform( [](int n) { return n * n; });

    /*
        The Pipe Operator |
        Borrowed from Unix pipes, it chains views together left to right
        Each | passes the output of the left side as input to the right side
        Makes code read like a data pipeline — very readable
    */

    /*
         views::filter
         Takes a predicate (a callable returning bool)
         Produces a view containing only elements where the predicate returns true
         From {1..10} → keeps {2, 4, 6, 8, 10}
    */

    /*
        views::transform
        Takes a transformation function
        Applies it to every element in the incoming view
        From {2, 4, 6, 8, 10} → produces {4, 16, 36, 64, 100}
    */

    /*
        Lazy Evaluation (key concept) - No work done until iteration
        Nothing is computed here — result is just a view description
        Computation only happens when you iterate in the for loop
        Elements are processed one at a time, not all at once
        No intermediate std::vector is created — memory efficient
    */

    for (const auto& n : result)
    {
        std::cout << n << " ";
    }

    /*
        This is the core power of C++20 Ranges — composable, lazy, expressive pipelines without allocating temporary containers.
    */
}