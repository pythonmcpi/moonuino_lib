#include "Moonuino.h"

// These are designs for the display.
unsigned char LETTER_A[5][5] = {
  0, 0, 1, 0, 0,
  0, 1, 0, 1, 0,
  0, 1, 1, 1, 0,
  1, 0, 0, 0, 1,
  1, 0, 0, 0, 1,
};

unsigned char LETTER_B[5][5] = {
  1, 1, 1, 1, 0,
  1, 0, 0, 0, 1,
  1, 1, 1, 1, 0,
  1, 0, 0, 0, 1,
  1, 1, 1, 1, 0,
};

unsigned char UP_ARROW[5][5] = {
  0, 0, 1, 0, 0,
  0, 1, 1, 1, 0,
  1, 0, 1, 0, 1,
  0, 0, 1, 0, 0,
  0, 0, 1, 0, 0,
};

unsigned char DOWN_ARROW[5][5] = {
  0, 0, 1, 0, 0,
  0, 0, 1, 0, 0,
  1, 0, 1, 0, 1,
  0, 1, 1, 1, 0,
  0, 0, 1, 0, 0,
};

unsigned char RIGHT_ARROW[5][5] = {
  0, 0, 1, 0, 0,
  0, 0, 0, 1, 0,
  1, 1, 1, 1, 1,
  0, 0, 0, 1, 0,
  0, 0, 1, 0, 0,
};

unsigned char LEFT_ARROW[5][5] = {
  0, 0, 1, 0, 0,
  0, 1, 0, 0, 0,
  1, 1, 1, 1, 1,
  0, 1, 0, 0, 0,
  0, 0, 1, 0, 0,
};

Moonuino matrix;

void setup() {
  // Call this once in setup.
  matrix.begin();
}

void loop() {
  // Call this every loop.
  matrix.update();

  // matrix.btn_* methods return 1 if a button is currently held, and 0 otherwise.
  if (matrix.btn_a()) {
    // display will keep a design on-screen until the next display() call or clear() call.
    matrix.display(LETTER_A);
  } else if (matrix.btn_b()) {
    matrix.display(LETTER_B);
  } else if (matrix.btn_up()) {
    matrix.display(UP_ARROW);
  } else if (matrix.btn_down()) {
    matrix.display(DOWN_ARROW);
  } else if (matrix.btn_right()) {
    matrix.display(RIGHT_ARROW);
  } else if (matrix.btn_left()) {
    matrix.display(LEFT_ARROW);
  } else {
    // The following line clears the screen if none of the buttons are held
    // Comment it out if you want things to remain on-screen after the button is released
    matrix.clear();
  }

  // matrix.display_once(your_display) will display something once but not keep it on-screen
  // use matrix.delay(milliseconds) instead of delay(milliseconds) to keep the led matrix on during that delay
}
