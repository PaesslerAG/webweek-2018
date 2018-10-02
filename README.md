# webweek-2018
Der Technologietrend IoT entwickelt sich rasant. Die #nueww 2018 bei Paessler steht mit einem Vortrag "Wie aus Wissen Daten entsteht" und Workshops "Environmental Monitoring" deshalb ganz im Fokus IoT


## Arduino IDE installation
### Install on MacOSX

- Download [Adruino IDE](https://www.arduino.cc/download_handler.php)
- Install [Adruino IDE](https://www.arduino.cc/en/Guide/MacOSX)
- Copy required libraries
```console
cp -rf ./libraries/* ~/Documents/Arduino/libraries
```
or manually copy content of `libraries` folder to `Documents/Arduino/libraries`


### Install on Windows
- Download [Adruino IDE](https://www.arduino.cc/download_handler.php)
- Install [Adruino IDE](https://www.arduino.cc/en/Guide/MacOSX)
- Execute `WINDOWS_copy_libraries.bat` from folder setup
  or manually copy content of `libraries` folder to `Documents\Arduino\libraries`



### Install on Linux

- Download [Adruino IDE](https://www.arduino.cc/download_handler.php)
- Install [Adruino IDE](https://www.arduino.cc/download_handler.php?f=/arduino-1.8.7-linux64.tar.xz)
- Copy required libraries
```console
cp -rf ./libraries/ ???
```

????

Optionally you can install libraries from zip folder following [this instruction](https://www.arduino.cc/en/Guide/Libraries#toc4).





## Arduino MK FOX 1200 board driver installation
> NOTE: Board driver installation takes approximately 10-15 minutes

- Start Arduino IDE
- Go to `Tools` > `Board: <board>` > `Boards Manager...`
- Enter `MKR FOX` in the search field
- Install `Arduino SAMD Boards (32-bits ARM Cortex-M0+) by Arduino`
