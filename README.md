# Lynxmotion_Hexapod

This is an updated and revived project based on the hexapod project made by [TimMcR](https://github.com/TimMcR/SeniorProjectHexapod)

Several years after @TimMcR's departure, I found the hexapod he worked on and wanted to revive it. However, the OneSheeld software he used to control it had since been discontinued, and the PS2 adapter he used previously was lost. I chose to use a SparkFun USB Host Shield and a wired PS4 Controller to control the Hexapod, using the [USB Host Shield 2.0](https://github.com/felis/USB_Host_Shield_2.0) library. I use a single arduino and the usb shield to control the servo controller. Once I got wired control to work, I then wanted to control it wireslessly with bluetooth. I bought a bluetooth usb dongle and converted the code from usb to bluetooth. However, the Arduino UNO did not have enough RAM to hold the code, so I switched to using two Arduino UNOs and I2C to communicate between them. This proved to work great, and it is the current setup used to control the hexapod.

## In order to use the Hexapod:
1. Connect a 9V battery to the battery clip connected to the SSC-32.
2. Connect the 6V battery to the adapter connected to the SSC-32.
3. Connect a 9V battery to the master Arduino (usb shield) via a barrel jack. Ensure the bluetooth dongle is in the usb port. It should be emitting a blue light; this shows that it is ready to recieve signals.
4. Connect a 9V battery to the follower Arduino (no usb shield) via a barrel jack
5. On your PS4 controller, press and hold share and start at the same time. This will activate the bluetooth pairing sequence, and the controller light should quickly flash light blue. Keep holding start and shar until the controller light turns solid dark blue.
6. Once connected, press start to activate the hexapod. The hexapod should stand up with its legs and body level. It is now ready to be controlled.

## Controls:
The Venom sticker is the front of the hexapod. L1, R1, and circle toggle different modes of stand still movement. 
+ Start (toggle): turns on/off the robot.
+ Triangle (toggle): robot drops down to where the body hits the ground, and toggling off will bring it back to normal.
### Walk Mode (default):
+ Left stick up/down:  Walk Forward and Backwards
+ Left stick left/right: Rotate body by walking
+ Right stick left/right: Walk Left and Right.
### L1 
+ Left stick: the robot will lean in the direction you push the stick.
+ Right stick up/down: the robot will push itself up/down.
+ Right sitck left/right: the robot will twist in place.
### R1
+ Left stick: the robot will tilt its body, the highest point will be the direction of the stick.
+ Right stick: same as L1.
### Circle (Single Leg Control)
When toggled, the robot will stand in place and lift one leg into the air. Press circle again to return to walk mode.
+ Left stick: move selected leg horizontally.
+ Right stick: move selected leg vertically.
+ Options: change selected leg (the robot will chose the next leg through a predetermined pattern each time you press it)

## Troubleshooting:
The SSC-32 has an led that should be emitting solid green while the SSC-32 is powered. if the robot is limping and the light is flickering or off, then one of the power sources is likely drained. Charge the 6V battery or replace the 9V battery.



