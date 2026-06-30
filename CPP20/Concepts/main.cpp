#include <iostream>

 // concept is a C++20 keyword used to define a named constraint on template type parameters.

#include "MathUtils.h"

struct Person
{

};

int main()
{
    std::cout << add(10, 20) << '\n';

    std::cout << add(1.5, 2.7) << '\n';

    // Uncomment these lines below to see Concepts in action.
    // Person p1, p2;
    // add(p1, p2);   // Person has no operator+ — Concept violation!

    //Before Concepts : Template misuse caused deep, unreadable substitution failure errors(SFINAE errors).
    //With Concepts : The constraint is explicit, and the compiler error is immediate and descriptive,
    //pointing directly to the unsatisfied requirement(a + b not valid for Person).

    return 0;
}

// This is exactly what your comments on lines 22–24 describe — Concepts don't change whether it compiles,
// they improve how the compiler communicates the failure.
// To express what a template requires from a type, before the template is instantiated, we use Concepts.

//When should we create our own Concept?
//Whenever our templates have meaningful requirements.

// Concepts allow you to describe what a type must be able to do, instead of only naming the type.
// That's why they're considered one of the best additions in C++20—they make generic code easier to read,
// easier to maintain, and much easier to diagnose when something doesn't meet the expected requirements.