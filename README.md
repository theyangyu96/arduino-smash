# Setup
Our code is designed for the Adafruit Pro Trinket, 5V/16MHz controller.  The [Arduino IDE](https://www.arduino.cc/en/Guide/Environment) is required for installation.

The Adafruit drivers can be found at `https://adafruit.github.io/arduino-board-index/package_adafruit_index.json`.  Place this URL in Arduino -> Preferences -> Additional Board Manager URLs.  Once this is done, go to Tools -> Boards -> Boards Manager, then search for the Adafruit AVR drivers and install them.  Switch your board to `Pro Trinket 5V/16MHz (USB)`.

On OSX, place the included libraries in ~/Documents/Arduino/libraries, so that the folder structure is:

    | ~/Documents/Arduino/libraries
	    | Pro_Trinket_USB_Keyboard_Library-master
	    | Pro_Trinket_USB_Mouse-master
	    
On windows, navigate to your home directory and include the libraries in Users\<your user>\Documents\Arduino\Libraries. Folder structure looks like: 
    
    | ~Users/<your user>/Documents/Arduino/libraries
	    | Pro_Trinket_USB_Keyboard_Library-master
	    | Pro_Trinket_USB_Mouse-master



The Arduino code can be run from anywhere once you have it downloaded.  To upload to your device, hit the reset button on your Adafruit; in Arduino, hit `Sketch`, then `Upload`.
