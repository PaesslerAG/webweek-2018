# webweek-2018
Der Technologietrend IoT entwickelt sich rasant. Die #nueww 2018 bei Paessler steht mit einem Vortrag "Wie aus Wissen Daten entstehen" und Workshops "Environmental Monitoring" deshalb ganz im Fokus IoT


## Arduino IDE installation
### Install on MacOSX

- Download [Arduino IDE](https://s3-eu-west-1.amazonaws.com/web-week-2018/arduino-1.8.7-macosx.zip)
- Install [Arduino IDE](https://www.arduino.cc/en/Guide/MacOSX)
- Copy required libraries
```console
cp -rf ./Libraries/* ~/Documents/Arduino/libraries
```
or manually copy content of `Libraries` folder to `Documents/Arduino/libraries`


### Install on Windows
- Download [Arduino IDE](https://s3-eu-west-1.amazonaws.com/web-week-2018/arduino-1.8.7-windows.exe)
- Install [Arduino IDE](https://www.arduino.cc/en/Guide/Windows)
- Execute `WINDOWS_copy_libraries.bat` from folder setup
  or manually copy content of `libraries` folder to `Documents\Arduino\libraries`



### Install on Linux

- Download [Arduino IDE](https://www.arduino.cc/download_handler.php)
- Install [Arduino IDE](https://www.arduino.cc/download_handler.php?f=/arduino-1.8.7-linux64.tar.xz)
- Copy required libraries

Optionally you can install libraries from zip folder following [this instruction](https://www.arduino.cc/en/Guide/Libraries#toc4).



## Arduino MKRFOX 1200 board driver installation
> NOTE: Board driver installation takes approximately 10-15 minutes

- Start Arduino IDE
- Go to `Tools` > `Board: <board>` > `Boards Manager...`
- Enter `MKR FOX` in the search field
- Install `Arduino SAMD Boards (32-bits ARM Cortex-M0+) by Arduino` Version `1.6.19`
