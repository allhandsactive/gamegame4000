# gamegame 4000
All code for the *gameGame 4000* ESP8266 wifi-enabled badge with SSD1331 RGB OLED display, and video game-contoller style buttons is made by *All Hands Active* (http://www.allhandsactive.org), a 501(c)(3) not-for-profit hackerspace (http://hackerspaces.org) located in Downtown Ann Arbor, MI, USA.

As any good hackerspace should, we encourage people to fully tinker with our code and designs, and to find novel uses for this project.  We'd love to hear of your projects using our badge -- please get in contact with us if you'd like to share your project!

Since it is based on the same processor, much of this documentation is copied over from our last kit, the *mktwo* badge (https://github.com/allhandsactive/mktwo-badge/blob/master/README.md)

### **Requirements**
#### **Hardware**
The safest and more reliable way to load firmware onto your *gameGame 4000* is with a USB-serial programming cable.  You will need to use an FTDI cable, like the FTDI cable here (https://www.sparkfun.com/products/9717) , *OR* you can use a cheaper cable with the Prolific *PL2303HX* chipset (look on eBay! We were able to easily find them from US sellers for under $5).  A serial voltage level of 3.3v for programming is recommended, but we've safely done it with 5v, too.  **NOTE:** Windows/Apple users, you will likely have to download a driver to use the *PL2303HX*.  Sorry, we can't provide support on how to do that.

Such cables hook up to the FTDI pin block near the bottom of the *gameGame 4000*.  Take care when hooking up the cable, because the FTDI pins on the badge are not keyed.  When you plug it into the badge, make sure the black wire on the FTDI cable faces toward the left side of the badge (assuming you are viewing the front of the badge).  In case your cable doesn't have a single plug, but a bunch of individual wires (like the Prolific ones), the pinout should be as follows, assuming the board is facing up toward you, left-to-right (*NC = No Connection*):

**BLACK NC NC GREEN WHITE NC**

The red wire from the programming cable should not be connected, which also means you will need to power the badge with the battery when programming it.

#### **Software**
We recommend a current version of the Arduino IDE (https://www.arduino.cc/en/Main/Software), either binary or git clone.

Under Arduino's preferences, *Additional Boards Manager URLs*, you will need to add:

`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

Under *Tools|Board:|Boards Manager...* search for and install `esp8266`.
**NOTE: you will need to add the URL above in preferences first.**
You will also need some libraries to run the OLED screen.  Under *Sketch|Include Library|Manage Libraries...* search for `SSD1331`.  Any of those should work to varying degrees.  Try them out and experiment! If you want to try the included `arkanoid8-pcon` demo, grab the `ssd1306` library, which comes with some cool demo stuff for our `SSD1331` OLED screen.  Keep in mind that you will have to update the pin settings on the other demos since they are connected differently for this board.

Now restart the Arduino IDE.

### **Badge Programming**
#### **Wired Programming**
##### **SETUP**

Under the Arduino IDE settings (most of these seem to be defaults):

Board: "NodeMCU 1.0 (ESP-12E Module)"
CPU Frequency: "80 MHz"
Debug Port: "Disabled"
Debug Level: "None"
lwIP Variant: "v2 Lower Memory"
Flash Size: "4M (3M SPIFFS)"
Upload Speed: "460800" (try lowering this if you have issues while programming the board)
Port: (whatever port the programming cable is on.  In Linux, it'll be something like `/dev/ttyUSB0`)
Programmer: "AVRISP mkII"
Erase Flash: "Only Sketch"

##### **PROCEDURE**

Let's take a look at the `ssd1306` library's demo games.  After installing that library, you can load up the `arkanoid8-pcon` code from this repo.

To upload your code, you need to put the badge into "write" or "programming" mode.  To do this, locate the `PRGM` and `RESET` buttons on the badge.  Hold the `PRGM` button. Press and release the `RESET` button. You may now release `PRGM`. **You will need to repeat this procedure before each firmware upload.**
You may now compile and upload as you would with any Arduino, using the Arduino IDE.

**NOTE: Some FTDI cables might not cause the ESP to reset after successful programming.  If you are observing this behavior, just use the** `RESET` **button on the badge.**

### Other notes
The speaker is linked to pin 5, if you wish to make bleeps and bloops with the `tone` function.

Other pin settings that might be useful:
For the OLED display:
sclk = 14
mosi = 13
cs = 2
rst = 0
dc = 16
For buttons (check out the example code in this repo):
pl/sload = 4
shcp/sck = 0
stcp/clk = 15
shift reg. serial output ("BUTTONS" on schematic) = 10

The board works great with three NiMH AA batteries.
