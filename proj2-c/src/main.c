#include "unit.h"

// lacklustre "float equal" function
int feq(float x, float y, float thresh) {
  return x - y < thresh && y - x < thresh;
}

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main() {
  // check "freezing point" of water
  printf(
      "Your function converted  32.00°F to %6.2f°C (should be   0.00°C) %s\n",
      convert(32.0), feq(convert(32.0), 0.0, 1e-5) ? "ok" : "INCORRECT");
  // check "boiling point" of water
  printf(
      "Your function converted 212.00°F to %6.2f°C (should be 100.00°C) %s\n",
      convert(212.0), feq(convert(212.0), 100.0, 1e-5) ? "ok" : "INCORRECT");
}
