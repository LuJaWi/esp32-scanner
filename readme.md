# Overview
🚧 This project is still in development! Feel free to fork and tweak, but expect bugs and weirdness. 🚧

This project is intended to be an open-source wireless scanner that can easily be controlled via a host computer. The original intended use was for laboratory robotics to help with sample tracking in life sciences laboratories, so many of the models are based around the [SBS](https://www.slas.org/SLAS/assets/File/public/standards/ANSI_SLAS_4-2004_WellPositions.pdf) format, but I've tried to keep the language as general as possible to make the project flexible and transferrable!

# Hardware

The primary objective with the hardware choices for this project is to prioritize using parts that are widely available and simple to assemble.
To make the barrier to getting started as low as possible, I've opted to avoid hardware configurations that require addtional soldering wherever possible.
This does mean that the finished product is not as small as it could possibly be, but it should be much easier to assemble and repair for folks of all skill levels.
There are a few portions of this project where that may become unavoidable, but I'll do my best to make that as clear as possible whenever I can. 

### Microcontroller
The brains of this project is an [ESP32 Microcontoller](https://www.espressif.com/en/products/socs/esp32). These are super cheap, widely available, and thoroughly documented.

### Scanner
I've opted to use a [1D/2D Barcode Scanner from Waveshare (14810)](https://www.waveshare.com/barcode-scanner-module.htm) as the scanner.
I haven't tested other scanners, and there are certain configuration codes within the Arduino code that I assume are unique to the scanner firmware, so I would reccommend sticking with that brand and model of scanner. 
The 3D models are also assuming a module with the Waveshare dimensions, so other scanners might not fit.

### Case
The housing and dock for this project are 3D printed pieces, which you can either print yourself, or order using a [3D printing service](https://duckduckgo.com/?t=h_&q=3d+printing+services&ia=web)


# Software
🚧 Coming soon...
