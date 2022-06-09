#include "math.h"


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
//
// TODO: Complete the function
void solve(const char* qfile, const char* afile) {
  FILE *iF = fopen(qfile,"r");
  FILE *oF = fopen(afile,"w");

  if (iF == NULL && oF == NULL) {
    return;
  }
  if (iF == NULL) {
    fclose(oF);
    return;
  }
  if (oF == NULL) {
    fclose(iF);
    return; 
  }

  int a;
  int b;
  int ans;
  char op;
  while(fscanf(iF, "%d %c %d", &a, &op, &b) > 0) {
    switch(op) {
    case '+':
      ans = a + b;
      break; 
    case '-':
      ans = a - b;
      break;
    case '*':
      ans = a * b;
      break;
    case '/':
      ans = a / b;
      break;
    case '%':
      ans = a % b;
      break;
    default:
      continue; 
    }
    fprintf(oF,"%3d %c %3d = %d\n", a,op,b,ans); 
  }
  fclose(iF);
  fclose(oF); 
  
}
