# gameGame 4000
This is the *gameGame 4000*: an ESP8266-based, wifi-enabled "badge" learn-to-solder project designed for anyone who is interested in soldering on a somewhat intermediate level, or how to program these ubiquitous microcontrollers. Along with the ESP8266, it is equipped with an SSD1331 RGB OLED display, video game controller-alike buttons, and a small speaker for bleeps and bloops.  This kit is designed by *All Hands Active* (http://www.allhandsactive.org), a 501(c)(3) not-for-profit hackerspace (http://hackerspaces.org) located in Downtown Ann Arbor, MI, USA.  The included Arkanoid demo code here is based, almost verbatim, on code from the *ssd1331* library by Alexey Dynda (@lexus2k).  We added some tweaks to accommodate our unique button handling library, and adjusted pins to match our OLED screen setup.

As any good hackerspace should, we encourage people to fully tinker with the code and designs, and to find novel uses for this project.  We'd love to hear of your projects using our badge -- please get in contact with us if you'd like to share your project!

Since it is based on the same processor, much of this documentation is copied over from our last kit, the *mktwo* badge (https://github.com/allhandsactive/mktwo-badge/blob/master/README.md)

# Build instructions on Imgur
Heads up! There are a few errors in the assembly pictures at the imgur link here.  Please follow the instructions in the captions first and foremost: https://imgur.com/gallery/5YhMqiV

### **Kit parts list**

Make sure you have the following in your kit:

1x gameGame 4000 PCB

1x ESP8266 12E or 12F microprocessor

1x SSD1331 OLED display

1x 3-AA battery holder

1x Female battery connector lead with pigtail

1x Male battery connector header

1x Toggle switch

1x Header 7-socket

1x Right-angle header 6-pin

1x Speaker 8-ohm 20mm

1x Linear regulator 1.2A 3.3v STMicroelectronics P/N LDL1117S33R

1x Shift register 8-bit Nexperia USA Inc. P/N 74HC597D,653

2x Electrolytic capacitor 10uF 50V

2x Ceramic capacitor 0.1uF 50V

4x Nylon standoff M2 x 12mm

4x Nylon nut M2

4x Nylon screw M2 x 5mm

10x Push button

12x Resistor 10k Ohm 1/8W 5%

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

Let's take a look at the `ssd1306` library's demo games.  After installing that library, you can load up the `arkanoid8-gamegame` code from this repo.

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
