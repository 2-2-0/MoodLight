/*
 * showcase_example.ino
 *
 * MoodLight LED strip controller library basic usage example
 * 
 * Copyright 2017 by 220
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <MoodLight.h>

// set the pins for your own board configuration
#define pin_red 9
#define pin_green 10
#define pin_blue 11

// start the MoodLight object, using the chosen pins
MoodLight mood_light (pin_red, pin_green, pin_blue);

long timer;

void setup() {
  // set pattern configuration
  reset ();

  timer = millis ();
}
void loop() {
  // Let it run for 10 seconds...
  if (millis () - timer > 10000) {
    // and then change the pattern
    reset ();
    
    timer = millis ();
  }
  mood_light.process ();
}
void reset () {
  // This function uses random math to set LED strip parameters
  // set the pattern you're going to use
  int v = random (0, 5);
  switch (v) {
    case 0:
      mood_light.pattern (&mood_light.noise);
      break;
    case 1:
      mood_light.pattern (&mood_light.flicker);
      break;
    case 2:
      mood_light.pattern (&mood_light.flash);
      break;
    case 3:
      mood_light.pattern (&mood_light.rampUp);
      break;
    case 4:
      mood_light.pattern (&mood_light.rampDown);
      break;
  }
  
  // set a light range from 0 to 255
  mood_light.range (random (0, 128), random (128, 255));

  // set the color ratios, to pick which ones to use
  mood_light.color (random (0.0f, 2.0f), random (0.0f, 2.0f), random (0.0f, 2.0f));
  
  // set the sleeping time between changes
  mood_light.sleep (random (12, 180));
}

