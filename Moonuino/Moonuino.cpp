#include "Moonuino.h"

#include "Arduino.h"

Moonuino::Moonuino(int s1, int s2, int s3, int s4, int s5, int s6, int r1,
                   int r2, int r3, int r4, int r5, int c1, int c2, int c3,
                   int c4, int c5) {
  _row_pins[0] = r1;
  _row_pins[1] = r2;
  _row_pins[2] = r3;
  _row_pins[3] = r4;
  _row_pins[4] = r5;
  _col_pins[0] = c1;
  _col_pins[1] = c2;
  _col_pins[2] = c3;
  _col_pins[3] = c4;
  _col_pins[4] = c5;

  _input_pins[0] = s1;
  _input_pins[1] = s2;
  _input_pins[2] = s3;
  _input_pins[3] = s4;
  _input_pins[4] = s5;
  _input_pins[5] = s6;

  clear();

  for (int i = 0; i < 6; i++)
    _button_cache[i] = 0;
}

void Moonuino::begin() {
  // Init Input Pins
  for (int i = 0; i < 6; i++) {
    pinMode(_input_pins[i], INPUT);
  }

  // Init Output Pins
  for (int i = 0; i < 5; i++) {
    pinMode(_row_pins[i], OUTPUT);
    pinMode(_col_pins[i], OUTPUT);
  }
}

void Moonuino::update() {
  // Update cache once per loop so btn_* methods are consistent
  for (int i = 0; i < 6; i++) {
    _button_cache[i] = digitalRead(_input_pins[i]);
  }

  if (_current_display != nullptr)
    display_once(_current_display);
}

void Moonuino::display(unsigned char data[5][5]) {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      _current_display[i][j] = data[i][j];
}

void Moonuino::clear() {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      _current_display[i][j] = 0;
}

/* Displays something once. Function takes 5ms to return. */
void Moonuino::display_once(unsigned char data[5][5]) {
  for (int c = 0; c < 5; c++) {
    digitalWrite(_col_pins[c], LOW);

    for (int r = 0; r < 5; r++)
      digitalWrite(_row_pins[r], data[4-c][r]); // col is inverted

    // required since led matrixes have to sweep row by row or col by col
    ::delay(1);

    digitalWrite(_col_pins[c], HIGH);

    for (int r = 0; r < 5; r++)
      digitalWrite(_row_pins[r], LOW);
  }
}

int Moonuino::btn_right() { return _button_cache[1]; }

int Moonuino::btn_left() { return _button_cache[3]; }

int Moonuino::btn_up() { return _button_cache[0]; }

int Moonuino::btn_down() { return _button_cache[2]; }

int Moonuino::btn_a() { return _button_cache[4]; }

int Moonuino::btn_b() { return _button_cache[5]; }

void Moonuino::delay(int milliseconds) {
  // delay implementation that keeps the screen drawn

  while (milliseconds > 0) {
    display_once(_current_display);
    milliseconds -= 5;
  }
}
