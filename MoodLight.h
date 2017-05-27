/*
 * MoodLight.h
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

#ifndef MoodLight_h
#define MoodLight_h

#include "Arduino.h"

// Light affects the way we perceive life, in fact, light is the way we perceive life!

class MoodLight {
  public:
	// constructor
    MoodLight (int pin_R, int pin_G, int pin_B);

    // config
    pattern (void (MoodLight::* pattern)(void));
    
    range (int min_range, int max_range);
    color (float red_ratio, float green_ratio, float blue_ratio);
    sleep (int ms_delay);

    // exec
    process ();

    // patterns
    void off ();
    void on ();
    void noise ();
    void flicker ();
    void flash ();
    void rampUp ();
    void rampDown ();

  private:
    // hardware
    int _pin_R;
    int _pin_G;
    int _pin_B;

    // values
    int _current;
    int _delta;

    int _r;
    int _g;
    int _b;

    // parameters
    float _red_ratio;
    float _green_ratio;
    float _blue_ratio;

    int _max_range;
    int _min_range;

    int _sleep;

    // internal handling
    long _timer;
    void (MoodLight::* _pattern)(void);
    
};

#endif

// There's also the light of gnosis, the light of knowledge.
// Knowledge affects your capacity to influence your own life.
