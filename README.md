# Overview

🚧 **This project is still in development!** Feel free to fork and tweak things, but expect bugs and weirdness along the way. 🚧

This is an open-source **wireless barcode scanner** designed to be easily controlled from a host computer. It was originally developed for use in **laboratory robotics** to assist with sample tracking in life sciences labs. As a result, many of the design choices assume compatibility with the [SBS format](https://www.slas.org/SLAS/assets/File/public/standards/ANSI_SLAS_4-2004_WellPositions.pdf), but I've tried to keep the terminology and logic general enough for use in other settings as well.

---

# Hardware

The goal of this project is to use **widely available, easy-to-assemble components** to make it accessible for hobbyists and professionals alike.

To lower the barrier to entry, I've avoided hardware that requires soldering wherever possible. While this might result in a slightly bulkier build, it should be easier to assemble and repair.

There may be a few unavoidable exceptions where soldering is required, but I'll do my best to make those cases clear when they come up.

---

### Microcontroller

The brain of the scanner is an [ESP32 microcontroller](https://www.espressif.com/en/products/socs/esp32). It's affordable, well-documented, and widely available.

---

### Barcode Scanner

This project uses the [Waveshare 1D/2D Barcode Scanner (Part #14810)](https://www.waveshare.com/barcode-scanner-module.htm).

> ⚠️ **Note**: I haven’t tested other scanner modules. Some parts of the Arduino code (e.g., configuration barcodes) are likely **specific to this scanner's firmware**. If you're using a different scanner, compatibility may be limited, and the 3D models might not fit.

---

### Case

The scanner housing and charging dock are designed to be 3D printed. You can print them yourself or use a [3D printing service](https://duckduckgo.com/?t=h_&q=3d+printing+services&ia=web) if you don’t have access to a printer.

---

# Software

🚧 *Coming soon…*

---
