# bdesc-s10e-rtr-example-control

Speed and direction control by Arduino


<br><br>


I was having trouble getting the `bdesc-s10e-rtr` to work with *Arduino*, especially controlling the direction. After binding it with `bdesc`, I could only control the direction clockwise or counterclockwise, indicating that there must be a correct process for this. I didn't find much information about how `bdesc-s10e-rtr` works, but I did come across a post on this [forum](
https://forum.arduino.cc/t/bdesc-s10e-rtr-electronic-speed-control-setup-for-brushed-motor/616972). Although the example provided in the post didn't work for me, the working description of `bdesc` made sense. Based on this, I created another example that worked for me.

<br>

In short, `bdesc-s10e-rtr` is designed for RC cars, thus it operates in a specific manner. Similar to servo motors, `bdesc` is controlled using PWM signals, where the control pulse varies between 1000 ms to 2000 ms. Here's a breakdown:


<br>


Status			| Pulse to Minimum speed	| Pulse to Maximum speed
------------------------|-------------------------------|------------------------
Motor stopped		| 1500 ms			| 1500 ms
Motor to Clockwised	| 1600 ms			| 1900 ms 
Motor to Anticlockwise	| 1400 ms			| 1000 ms 

<br>

It's possible to have a pulse variance of 50 ms to initiate rotation, considering that motors often have mechanical reductions or other mechanisms in place. At this stage, it's opportune to take measurements regarding power and current for safe operation.

<br>

Another important detail is that for counterclockwise rotation, a specific process is required, as described in the "anticlockwise" function in this [code](./bdesc-s10e-rtr-example-control.ino). This process takes at least about 300 ms. Therefore, an immediate reversal from clockwise to counterclockwise appears to be impossible, possibly implemented to safeguard the battery. Additionally, it's noteworthy that the maximum speed for counterclockwise rotation is half of the maximum speed achievable in the clockwise direction.
