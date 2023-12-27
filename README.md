# Faramaz-AnvarProject

% Project "GoodStrings"

\documentclass{article}
\usepackage{amsmath}
\usepackage{amsfonts}

\begin{document}

\begin{center}
  \section*{Project "GoodStrings"}
\end{center}

The \texttt{countGoodStrings} project provides the \texttt{countGoodSubstrings} function, which calculates the number of "good" substrings in the given string \texttt{s}. "Good" substrings are defined as substrings in which the maximum number of repeating characters of one type does not exceed the others.

\subsection*{Usage}

To use the \texttt{countGoodSubstrings} function, include the header file \texttt{countGoodStrings.h} and import the necessary dependencies:

\begin{verbatim}
#include "countGoodStrings.h"
#include <unordered_map>
#include "factorials.h"
#include "combinations.h"
\end{verbatim}

Then you can call the function by passing a string as an argument:

\begin{verbatim}
std::string inputString = "your_input_string";
uint1024_t result = countGoodSubstrings(inputString);
\end{verbatim}

The result will be represented as a number of type \texttt{uint1024\_t}.

\subsection*{Implementation}

The \texttt{countGoodSubstrings} function works as follows:

\begin{enumerate}
  \item First, the frequency of each character in the string is counted using \texttt{std::unordered\_map}.
  \item Then, the maximum frequency of a character is found.
  \item Factorials are calculated and stored in a vector for further use in combination calculations.
  \item For each possible substring size from 1 to the maximum frequency of a character:
    \begin{enumerate}
      \item Combinations are calculated for each character in the string.
      \item The results of combinations are multiplied together.
      \item The final result is increased by the obtained product minus 1 (to exclude the empty substring).
    \end{enumerate}
  \item The final result is returned modulo 1000000007.
\end{enumerate}

The formula for calculating the result is:

\[
\prod_{i=1}^{l} \left( \binom{n_i}{k_i} + 1 \right) - 1
\]

where \(\binom{n_i}{k_i}\) represents a binomial coefficient \(C(n_i, k_i) = \binom{n_i}{k_i} = \frac{k_i!}{(n_i - k_i)! \cdot n_i!}\), which can be expressed using factorials.

\subsection*{Complexity}

The time complexity of the \texttt{countGoodSubstrings} function is \(O(n \cdot \text{{const}})\), where \(\text{{const}} \leq 10000\). Consequently, the overall complexity is \(O(n)\).

\subsection*{Dependencies}

\begin{itemize}
  \item \texttt{countGoodStrings.h}: Header file for the \texttt{countGoodSubstrings} function.
  \item \texttt{factorials.h}: Header file for factorial calculations.
  \item \texttt{combinations.h}: Header file for combination calculations.
\end{itemize}

\subsection*{Example}

\begin{verbatim}
#include "countGoodStrings.h"
#include <iostream>

int main() {
    std::string inputString = "abca";
    uint1024_t result = countGoodSubstrings(inputString);

    std::cout << "Number of good substrings: " << result << std::endl;

    return 0;
}
\end{verbatim}

\subsection*{License}

This project is created by Faramaz and Anvar.

\end{document}
