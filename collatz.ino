//
// Ron Bentley, Stafford UK
// November 2021
//
// This example and code is in the public domain and may be used without
// restriction and without warranty.
//
// Collatz Conjecture
// ^^^^^^^^^^^^^^^^^^
//
// A sketch to produce the Collatz sequence for a given positive integer.
// The Collatz sequence for any positive integer, N, is determined as follows:
//
//   if N is odd set  N = 3*N + 1 (which will then be even)
//   if N is even set N = N/2     (which will be either be an odd or an even number)
//   repeat the above until N converges to 1, ie N = 1.
//
// For any given positive integer the Collatz squence will always converge to 1, although
// this remains unproven.  The Collatz conjecture is also know as the 3N+1 conjecture.
//

uint32_t collatz_num;  // the positive integer for which the Collatz sequence will be determined

//
// The function implements/executes the Collatz 'rules' to determine the Collatz
// sequence for the given positive integer.
// The function prints each number in the Collatz sequence to the currently
// selected output stream - the serial monitor ot the serial polotter.
//
void collatz(uint32_t collatz_num) {
  uint16_t convergence_steps; // records the number of steps performed before the Collatz sequence reaches 1
  convergence_steps = 0;      // count of the number of steps to convergence
  Serial.print("\nCollatz sequence for ");
  Serial.print(collatz_num);
  Serial.println("...");
  // apply the Collatz rules
  while (collatz_num > 1) {
    convergence_steps++;
    Serial.println(collatz_num);
    if (collatz_num & 1 == 1) {// test bottom bit
      // odd number
      collatz_num = collatz_num * 3 + 1;
    } else
    {
      // even number
      collatz_num = collatz_num >> 1; // divide by 2
    }
  }
  // done, we have reached convergence (1)
  convergence_steps++;
  Serial.println(collatz_num); // final value in the Collatz sequence, which will be 1
  Serial.print("Collatz convergence steps = ");
  Serial.println(convergence_steps);
  Serial.flush();
}

uint32_t read_collatz_num() {
  int32_t collatz_num = 0;
  while (!Serial.available()); // wait for input
  while (collatz_num <= 0) {
    collatz_num = Serial.parseInt(); // read next +ve integer in the current input stream
  }
  // input is a positive integer, now flush out any following chars
  delay(50); // this shouldnt be necessary but it is!
  while (Serial.available() > 0) {
    // still more chars in the input stream so read and discard
    Serial.read();
  }
  return collatz_num; // return the integer read
}

void setup() {
  Serial.begin(9600);
  Serial.println("Collatz Conjecture Examples");
  Serial.println("^^^^^^^^^^^^^^^^^^^^^^^^^^^");
  Serial.println("Enter any positive integer and press return/send");
}

void loop() {
  // keep reading user supplied values and determine their Collatz sequences
  do {
    collatz_num = read_collatz_num(); // read user input
    collatz(collatz_num);
  } while (true);
}
