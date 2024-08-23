/*
  Moonuino.h - Library for controlling the MOONUINO 5x5 LED Matrix Shield
  Created by pipythonmc based on sample code available at
  https://moonpreneur.com/tech-corner/moonuino-5x5-led-matrix-shield/

  This library is licensed under CC BY-SA 4.0.

  Buttons are named right, left, up, down for the dpad on the left.
  Button a refers to the button on top on the right side of the board.
  Button b is below button a, also on the right side of the board.
*/

#ifndef Moonuino_h
#define Moonuino_h

#include "Arduino.h"

class Moonuino {
private:
  /* Config */
  int _row_pins[5];
  int _col_pins[5];
  int _input_pins[6];

  /* Cached Data */
  int _button_cache[6];
  unsigned char _current_display[5][5];

public:
  // API
  Moonuino(int s1 = A0, int s2 = A1, int s3 = A2, int s4 = A3, int s5 = A4,
           int s6 = A5, int r1 = 6, int r2 = 5, int r3 = 4, int r4 = 3,
           int r5 = 2, int c1 = 11, int c2 = 10, int c3 = 9, int c4 = 8,
           int c5 = 7);

  void begin();
  void update();

  void display(unsigned char data[5][5]);
  void clear();

  void display_once(unsigned char data[5][5]);

  int btn_right();
  int btn_left();
  int btn_up();
  int btn_down();
  int btn_a();
  int btn_b();

  void delay(int milliseconds);
};

#endif
