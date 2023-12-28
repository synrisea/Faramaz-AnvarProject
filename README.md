## Faramaz-AnvarProject

# Project "GoodStrings"

The `countGoodStrings` project provides the `countGoodSubstrings` function, which calculates the number of "good" substrings in the given string `s`. "Good" substrings are defined as substrings in which the maximum number of repeating characters of one type does not exceed the others.

## Usage

To use the `countGoodSubstrings` function, include the header file `countGoodStrings.h` and import the necessary dependencies:

```cpp
#include "countGoodStrings.h"
#include <unordered_map>
#include "factorials.h"
#include "combinations.h"
```


Then you can call the function by passing a string as an argument:

```cpp
std::string inputString = "your_input_string";
uint1024_t result = countGoodSubstrings(inputString);
```

The result will be represented as a number of type `uint1024_t`.

## Implementation

The `countGoodSubstrings` function works as follows:

1. First, the frequency of each character in the string is counted using `std::unordered_map`.

2. Then, the maximum frequency of a character is found.

3. Factorials are calculated and stored in a vector for further use in combination calculations.

4. For each possible substring size from 1 to the maximum frequency of a character:
    - Combinations are calculated for each character in the string.
    - The results of combinations are multiplied together.
    - The final result is increased by the obtained product minus 1 (to exclude the empty substring).

5. The final result is returned modulo 100.000.000.7.


The formula for calculating the result is:

$$\prod_{i=1}^{l} \left( \binom{n_i}{k_i} + 1 \right) - 1$$

where $\binom{n_i}{k_i}$ represents a binomial coefficient $C(n_i, k_i) = \binom{n_i}{k_i} = \frac{k_i!}{(n_i - k_i)! \cdot n_i!}$, which can be expressed using factorials.

## Complexity

The time complexity of the 'countGoodSubstrings' function is $O(n \cdot \text{{const}})$, where $\text{{const}} \leq 10000$. Consequently, the overall complexity is $O(n)$.

## Dependencies

  $\texttt{countGoodStrings.h}$ : Header file for the $\texttt{countGoodSubstrings}$ function.
  
  $\texttt{factorials.h}$ : Header file for factorial calculations.
  
  $\texttt{combinations.h}$ : Header file for combination calculations.

## Example

```cpp
#include "countGoodStrings.h"
#include <iostream>

int main() {
    std::string inputString = "abca";
    uint1024_t result = countGoodSubstrings(inputString);

    std::cout << "Number of good substrings: " << result << std::endl;

    return 0;
}
```
