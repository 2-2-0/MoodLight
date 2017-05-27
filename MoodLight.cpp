/*
 * MoodLight.cpp
 * Originally developed for meta.humano by 220 (220metahumano.tumblr.com | 2-2-0.online)
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

#include "Arduino.h"
#include "MoodLight.h"

// ...but light can be a decoy, too... 
// ...if it weren't for light, we would be able to see things in their true form.

// CONSTRUCTOR
MoodLight::MoodLight (int pin_R, int pin_G, int pin_B) {
  #ifdef MOODLIGHT_DEBUG
  Serial.begin (115200);
  #endif

  // save pins
  _pin_R = pin_R;
  _pin_G = pin_G;
  _pin_B = pin_B;

  // init pins
  pinMode (_pin_R, OUTPUT);
  pinMode (_pin_G, OUTPUT);
  pinMode (_pin_B, OUTPUT);

  // init basic parameters  
  _min_range = 0;
  _max_range = 255;

  _sleep = 100;

  // init values
  _current = _r = _g = _b = 128;
  _delta = 1;

  // init timer
  _timer = millis ();
}

// The exercise is simple, but difficult:
// Try to see around without using your eyes... ;)

// PARAMETERS
MoodLight::pattern (void (MoodLight::* pattern)(void)) {
  _pattern= pattern;
}

MoodLight::range (int min_range, int max_range) {
  _min_range = min_range;
  _max_range = max_range;
}
MoodLight::sleep (int sleep) {
  _sleep = sleep;
}
MoodLight::color (float red_ratio, float green_ratio, float blue_ratio) {
  _red_ratio = red_ratio;
  _blue_ratio = blue_ratio;
  _green_ratio = green_ratio;
}

// EXEC
MoodLight::process () {
  // Do this only when it needs to be done. by doing this, we avoid hanging other ops from the main app.
  // Basically you can do other things and actions will only happen when they need to.
  if (millis () - _timer > _sleep) {

    // call selected pattern by using a function pointer
    (this->*_pattern)();

    // adjust color values to configured color ratios
    _r = _current * _red_ratio;
    _g = _current * _green_ratio;
    _b = _current * _blue_ratio;

    // send the appropriate values to the pins
    analogWrite (_pin_R, _r);
    analogWrite (_pin_G, _g);
    analogWrite (_pin_B, _b);

    // set the timer back, otherwise, it's useless.
    _timer = millis ();

    #ifdef MOODLIGHT_DEBUG
    Serial.println (_current);
    #endif
  }
}

// Master light in order to become an illuminated one...

// PATTERNS
void MoodLight::off () {
  _current = 0;
}
void MoodLight::on () {
  _current = _max_range;
}
void MoodLight::noise () {
  _current = random (_min_range, _max_range);
}
void MoodLight::flicker () {
  _current = random (0, 2)*_max_range;
}
void MoodLight::flash () {
  _current = (_current==_max_range?_min_range:_max_range);
}
void MoodLight::rampUp() {
  _current = (++_current>_max_range?_min_range:_current);
}
void MoodLight::rampDown () {
  _current = (--_current<_min_range?_max_range:_current);
}

// Add your own patterns here...
