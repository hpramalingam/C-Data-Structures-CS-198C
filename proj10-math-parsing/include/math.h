#include <stdio.h>
#include <stdlib.h>

#ifndef MATH_H
#define MATH_H

// goal: read equations from a file and write them in a solved state to another
// file
//   NOTE: format details specified in instructions
// param qfile: file with math questions to solve
// param afile: file to write equations with answers in
// example:
//   qfile at start of function:
//     12 + 13
//     24 / 5
//     8 * 234
//     65 - 78
//     239 % 13
//   afile after function:
//      12 +  13 = 25
//      24 /   5 = 4
//       8 * 234 = 1872
//      65 -  78 = -13
//     239 %  13 = 5
void solve(const char* qfile, const char* afile);

#endif