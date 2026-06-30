#pragma once

template<typename T>
concept Addable = requires(T a, T b)  // defining the Concept Addable
{
    a + b;
};


// Addable checks whether two values of type T support the + operator using a requires expression.
// If a type satisfies this constraint(e.g., int, double, std::string), it is considered Addable.

template<Addable T>  // using the Concept Addable in Constrained template
T add(T a, T b)
{
    return a + b;
}

//What does this function require?
//It actually requires that T supports operator+, but nothing in the code tells you that.
//The compiler only discovers the problem after someone tries to instantiate the template.

// With Concepts we have this "This function only works for types that are Addable."

// Instead of template<typename T>, it uses template<Addable T>, which restricts T to only types that satisfy the Addable concept.
// If we try to instantiate this with a non - Addable type, the compiler gives a clear, human - readable error 
// instead of the historically cryptic template substitution errors.