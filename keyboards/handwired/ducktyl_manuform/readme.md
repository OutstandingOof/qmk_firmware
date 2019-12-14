Ducktyl Manuform (5x6, more versions maybe added later)
======
The [Ducktyl-Manuform](https://github.com/OutstandingOof/ducktyl-manuform) is a split curved keyboard with an OLED display based on the [Dactyl-Manuform](https://github.com/tshort/dactyl-keyboard) and its predecessors. All Information to build one is in the first link. 

![Imgur](https://i.imgur.com/VhYYnnR.jpg)

## First Time Setup

Download or clone OutstandigOof's `qmk_firmware` repo, navigate to its top level directory and switch to the `ducktyl_manuform` branch (`git checkout ducktyl_manuform`), as it is currently not in the main QMK repository (I'll change that soon). Once your build environment is setup, you'll be able to generate the default .hex using:

Depending on your Layout chose one of the follwing commands:

```
$ make handwired/ducktyl_manuform/YOUR_LAYOUT:YOUR_KEYMAP_NAME
```

example:
```
$ make handwired/ducktyl_manuform/4x5:default
```

If everything worked correctly you will see a file:

```
ducktyl_manuform_YOUR_LAYOUT_YOUR_KEYMAP_NAME.hex
```

For more information on customizing keymaps, take a look at the primary documentation for [Customizing Your Keymap](/docs/faq_keymap.md) in the main readme.md.


## Keymaps

### [Keymaps 5x6](/keyboards/handwired/ducktyl_manuform/5x6/keymaps/)

#### Default
Copy of the Dactyl Manuform's default keymap with OLED and rotary encoder support + layers GAME and MOUSE.

#### OutstandingOof
Dvorak keymap changed to go well with a German layout and i3 (linux window manager). 

## Required Hardware

Apart from diodes and key switches for the keyboard matrix in each half, you
will need:

* 2 Arduino Pro Micros. You can find these on AliExpress for ≈3.50USD each.
* 2 TRRS sockets and 1 TRRS cable, or 2 TRS sockets and 1 TRS cable 
* 1 SSD1603 0.91" OLED display 

Alternatively, you can use any sort of cable and socket that has at least 3
wires. I2C communication betveen halves isn't possible due to I2C already being used for the OLED. 
## Optional Hardware
A speaker can be hooked-up to either side to the `A2` (`F5`) pin and `GND`, and turned on via `AUDIO_ENABLE`.
Rotary encodes can be added by connecting them to `A3` (`F4`), `A2` (`F5`) and `GND`. Follow the steps on [QMK's guide page](https://docs.qmk.fm/#/feature_encoders) to use them in your keymap. 

## Wiring

The 3 wires of the TRS/TRRS cable need to connect GND, VCC, and digital pin `RX1` (i.e.
`PD2` on the ATmega32u4) between the two Pro Micros. Make sure to wire `GND` to `GND`, `VCC` to `VCC` and `RX1` to `RX1` on the two boards. 

Next, wire your key matrix to any of the remaining 17 IO pins of the pro micro
and modify the `matrix.c` accordingly.

## Flashing

To flash your firmware take a look at: [Flashing Instructions and Bootloader Information](https://docs.qmk.fm/#/flashing)


## Choosing which board to plug the USB cable into (choosing Master)

Because the two boards are identical, the firmware has logic to differentiate the left and right board.

It uses two strategies to figure things out: looking at the EEPROM (memory on the chip) or looking if the current board has the usb cable.

The EEPROM approach requires additional setup (flashing the eeprom) but allows you to swap the usb cable to either side.

The USB cable approach is easier to setup and if you just want the usb cable on the left board, you do not need to do anything extra.

### Setting the left hand as master

If you always plug the usb cable into the left board, nothing extra is needed as this is the default. Comment out `EE_HANDS` and comment out `I2C_MASTER_RIGHT` or `MASTER_RIGHT` if for some reason it was set.

### Setting the right hand as master

If you always plug the usb cable into the right board, add an extra flag to your `config.h`
```
 #define MASTER_RIGHT
```

### Setting EE_hands to use either hands as master

If you define `EE_HANDS` in your `config.h`, you will need to set the
EEPROM for the left and right halves.

The EEPROM is used to store whether the
half is left handed or right handed. This makes it so that the same firmware
file will run on both hands instead of having to flash left and right handed
versions of the firmware to each half. To flash the EEPROM file for the left
half run:
```
make handwired/dactyl_promicro:default:dfu-split-left
make handwired/dactyl_promicro:default:dfu-split-right
```

After you have flashed the EEPROM, you then need to set `EE_HANDS` in your config.h, rebuild the hex files and reflash.

Note that you need to program both halves, but you have the option of using
different keymaps for each half. You could program the left half with a QWERTY
layout and the right half with a Colemak layout using bootmagic's default layout option.
Then if you connect the left half to a computer by USB the keyboard will use QWERTY and Colemak when the
right half is connected.


Notes on Using Pro Micro 3.3V
-----------------------------

Do update the `F_CPU` parameter in `rules.mk` to `8000000` which reflects
the frequency on the 3.3V board.

Also, if the slave board is producing weird characters in certain columns,
update the following line in `matrix.c` to the following:

```
// wait_us(30);  // without this wait read unstable value.
wait_us(300);  // without this wait read unstable value.
```
