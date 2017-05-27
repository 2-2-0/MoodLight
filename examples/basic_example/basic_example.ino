/*
 * basic_example.ino
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

void setup() {
  // set the pattern you're going to use
  mood_light.pattern (&mood_light.rampDown);

  // set a light range from 0 to 255
  mood_light.range (0, 255);

  // set the color ratios, to pick which ones to use
  mood_light.color (1.0, 0.2, 0.35);

  // set the sleeping time between changes
  mood_light.sleep (12);
}

void loop() {
  // you can call anything else afterwards, as this is a timer based object
  // this means you can do other things in your script while operating the strip
  mood_light.process ();
}

