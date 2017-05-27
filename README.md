# MoodLight

MoodLight analog LED strips controller for Arduino compatible devices!


MoodLight is a light weight library that allows you control of analog RGB LED strips easily with a very simple circuit that uses three NPN amp transistors, a voltage regulator and the proper power supply. It should work well with single color strips, as well... just use one channel.


## Usage

First, call the library on the top of your code:
```
#include <MoodLight.h>
```


Then instantiate the object:
```
MoodLight mood_light (9, 10, 11);
```
...don't forget to set your own PWM or analog pins. The order is R, G, B.


Now, configure the light parameters:
```
mood_light.pattern (&mood_light.noise);
mood_light.range (0, 255);
mood_light.color (1.0, 0.2, 0.35);
mood_light.sleep (12);
```
You can do this one time only, or change parameters according to your needs.


Finally, call the object inside your loop ():
```
mood_light.process ();
```
The class is timer based, so you can call process () and then run another batch of commands.


## Methods

### Constructor
Initialize the object.
```
MoodLight <object_name> (red_pin, green_pin, blue_pin);
```

Parameters:
- red_pin   (int): pin id for the red output.
- green_pin (int): pin id for the green output.
- blue_pin  (int): pin id for the blue output.

Example:
```
MoodLight mood_light (9, 10, 11);
```


### Parameters configuration
#### Pattern selection
Picks the pattern method to use for operation. Points directly to a method inside the object you have instantiated.
```
<object_name>.pattern (pointer_to_function);
```

Parameters:
- pointer_to_function (MoodLight::(void)(*f)(void): pointer to the function

Example:
```
mood_light.pattern (&mood_light.noise);
```

> Don't forget to use & before the name of the function! That allows it to work as a function pointer.


#### Brightness range
Allows you to set a range of values for the strips to operate. Use byte values (from 0 to 255).
```
<object_name>.range (min_range, max_range);
```

Parameters:
- min_range (int): minimum value for the range.
- max_range (int): maximum value for the range.

Example:
```
mood_light.range (0, 255); // from off to full brightness
// or...
mood_light.range (64, 192);
```


#### Color ratios:
Lets you set how much of each channel you want for your pattern. It uses values from 0.0 to 1.0. If you wan't half red, no green and all blue, you'd use 0.5, 0.0, 1.0.
```
<object_name>.color (red_value, green_value, blue_value);
```

Parameters:
- red_value   (float): red color ratio
- green_value (float): green color ratio
- blue_value  (float): blue color ratio

Example:
```
mood_light.color (1.0, 0.5, 0.0); // set color to orange
```


#### Sleep time:
How much time does it take between each change. It uses milliseconds. Use low values for quick operation and high values for slow updates.
```
<object_name>.sleep (milliseconds);
```

Parameters:
- milliseconds (long): time it takes between each step

Example:
```
mood_light.sleep (65);
```


### Execution
Call inside your loop () method to make MoodLight work. You can call this and make other operations in the meantime.
```
<object_name>.process ();
```

Parameters:
None

Example:
```
mood_light.process ();
```


## Patterns
Currently available patterns include:
- **off**      - turns off the strip completely
- **on**       - turns on the strip to the max_range
- **noise**    - produces multiple brightness noise
- **flicker**  - simulates a broken lamp
- **flash**    - the usual "blink" effect
- **rampUp**   - Fade in
- **rampDown** - Fade out


## Pending work
- While this works with single color strips, some coded can be optimized for them.
- Add more patterns.


## About the circuit
The circuit/ directory includes diagram and bill of materials needed to assemble a basic circuit that will allow you to use a 5 meters long RGB strip. It uses a 3V amp. If you're going to use more than that length, you need to recalculate the supply needed and probably change the TIP120 if it's too much current for it.


## Credits
Created by 220 for [meta.humano](http://220metahumano.tumblr.com)

Visit [2-2-0.online](http://2-2-0.online) and [github/2-2-0](http://www.github.com/2-2-0)

Shoutout to Luis Molina and Antonio Aragón for the head start!

Production made possible with support from Secretaría de Cultura de México, and Centro Nacional de las Artes, and of course Mexican tax payers. Thanks a million to you all!


## License
Check the included GPLv3 license agreement file.
Use it as you want, just be sure to include some credits with it.

