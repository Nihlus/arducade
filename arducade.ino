//
//  arducade.ino
//
//  Author:
//       Jarl Gullberg <jarl.gullberg@gmail.com>
//
//  Copyright (c) 2016 Jarl Gullberg
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <Joystick.h>

// Joystick setup
Joystick_ Joystick;

// Pins
const int pinJoyP1Up = 9;
const int pinJoyP1Down = 8;
const int pinJoyP1Left = 7;
const int pinJoyP1Right = 6;

const int pinJoyP2Up = 5;
const int pinJoyP2Down = 4;
const int pinJoyP2Left = 3;
const int pinJoyP2Right = 2;

const int pinButtonP1B1 = A0;
const int pinButtonP1B2 = A1;
const int pinButtonP1B3 = A2;
const int pinButtonP1B4 = A3;

const int pinButtonP2B1 = 10;
const int pinButtonP2B2 = 11;
const int pinButtonP2B3 = 12;

const int pinResetGame = A4;


void setup() {
  pinMode(pinJoyP1Up, INPUT_PULLUP);
  pinMode(pinJoyP1Down, INPUT_PULLUP);
  pinMode(pinJoyP1Left, INPUT_PULLUP);
  pinMode(pinJoyP1Right, INPUT_PULLUP);

  pinMode(pinJoyP2Up, INPUT_PULLUP);
  pinMode(pinJoyP2Down, INPUT_PULLUP);
  pinMode(pinJoyP2Left, INPUT_PULLUP);
  pinMode(pinJoyP2Right, INPUT_PULLUP);

  pinMode(pinButtonP1B1, INPUT_PULLUP);
  pinMode(pinButtonP1B2, INPUT_PULLUP);
  pinMode(pinButtonP1B3, INPUT_PULLUP);
  pinMode(pinButtonP1B4, INPUT_PULLUP);

  pinMode(pinButtonP2B1, INPUT_PULLUP);
  pinMode(pinButtonP2B2, INPUT_PULLUP);
  pinMode(pinButtonP2B3, INPUT_PULLUP);

  pinMode(pinResetGame, INPUT_PULLUP);

  // Joystick setup
  Joystick.begin();
}


int joyP1UpLastState = 0;
int joyP1DownLastState = 0;
int joyP1LeftLastState = 0;
int joyP1RightLastState = 0;

int joyP2UpLastState = 0;
int joyP2DownLastState = 0;
int joyP2LeftLastState = 0;
int joyP2RightLastState = 0;

int buttonP1B1LastState = 0;
int buttonP1B2LastState = 0;
int buttonP1B3LastState = 0;
int buttonP1B4LastState = 0;

int buttonP2B1LastState = 0;
int buttonP2B2LastState = 0;
int buttonP2B3LastState = 0;

int resetGameLastState = 0;

/// <summary>
/// Checks the state of the given button against a known state, and sets an associated
/// joystick button according to it.
/// </summary>
/// <param name="pin">The pin to check.</param>
/// <param name="stateVariable">The state variable for that pin.</param>
/// <param name="button">The associated joystick button.</param>
void checkButton(int pin, int &stateVariable, int button)
{
  int currentButtonState = !digitalRead(pin);
  if (currentButtonState != stateVariable)
  {
    Joystick.setButton(button, currentButtonState);
    stateVariable = currentButtonState;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  checkButton(pinJoyP1Up, joyP1UpLastState, 0);
  checkButton(pinJoyP1Down, joyP1DownLastState, 1);
  checkButton(pinJoyP1Left, joyP1LeftLastState, 2);
  checkButton(pinJoyP1Right, joyP1RightLastState, 3);

  checkButton(pinJoyP2Up, joyP2UpLastState, 4);
  checkButton(pinJoyP2Down, joyP2DownLastState, 5);
  checkButton(pinJoyP2Left, joyP2LeftLastState, 6);
  checkButton(pinJoyP2Right, joyP2RightLastState, 7);

  checkButton(pinButtonP1B1, buttonP1B1LastState, 8);
  checkButton(pinButtonP1B2, buttonP1B2LastState, 9);
  checkButton(pinButtonP1B3, buttonP1B3LastState, 10);
  checkButton(pinButtonP1B4, buttonP1B4LastState, 11);

  checkButton(pinButtonP2B1, buttonP2B1LastState, 12);
  checkButton(pinButtonP2B2, buttonP2B2LastState, 13);
  checkButton(pinButtonP2B3, buttonP2B3LastState, 14);

  checkButton(pinResetGame, resetGameLastState, 15);

  delay(50);
}

