# RC_Servo_To_Switch

Convert RC Servo PWM into an on/off output

I developed this into my RC car to make possible turn on / off the lights based on a servo output, so practically remotely. I attached on of my switch in my transmitter to a channel, so the output is -100% or +100% (this is the servo PWM marking).

## Features

- Convert the typical RC reciever servo signal into a on or off output
- Based on cheap, accessable and tiny digispark board with attiny85 controller
- Two, simultan output, both are tolarate around ~40mA. More then enough for a LED
- Failover mode: Older recievers (for example Flysky AFHDS) don't support failover, but the characteristic of PWM output change. This code detect this and turn the outputs into `off` state.

## Possible ideas

These are not implemented at the moment, but with minimal work you can implement it for yourself.

- Easy: More output, we have some free leg
- Easy: Add some integrated logic, for example flashing the leds instead contant on
- Medium: Not trivial to read different input PWMs simulteniusly with this tiny controller, but I believe it's possible without too much pain. This would make possible to read multiple inputs, and control multiple outputs independently with only one controller

## Build your hardware

_TODO_

## Upload the firmware

You'll need a platformIO IDE to upload the code. I suggest to disconnect everything while uploading, don't fight with USB bus. No programer tool needed, this board have bootloader and can upload itself.