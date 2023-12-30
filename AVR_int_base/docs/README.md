# AVR_int_base Library

The `AVR_int_base` library provides a base class for the INT0 and INT1 interrupts on an Arduino running with an ATmega328P and *probably* works on an ATmega168 as well -- they are extremely similar.

The two INTx libraries, `AVR_int0` and `AVR_int1` are descendants of this base class and require this library in order to function.

Your code need not worry about this one though - there's nothing you can do or need to do, it's all already done for you.


The code has been tested on projects created in the Arduino IDE version 1.8.18 onwards, including version 2.2.1, and also in PlatformIO (platformio.org), with no problems on either system.

## Arduino

To install the library:

* Click Sketch->Include Library->Add .ZIP Library;
* Navigate to where the zip file for this library is located on your system;
* Select it and click the OK button;
* Follow the prompts.

## PlatformIO

As of the time of typing, I have not built this library into a format suitable for uploading to the official PlatformIO Library Registry.

* Unzip the downloaded zip file.
* In your project's directory, create a new directory under `lib`, named `AVR_int_base`.
* Copy files from the `src` directory *of the extracted zip file* to the new directory you created above.
* That's it.

Norman Dunbar

15 September 2020.
