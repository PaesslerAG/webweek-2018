echo %cd%

set "LocalLibraries=%cd%\libraries"
set "TargetLibraryFolder=%userprofile%\Documents\Arduino\libraries"

xcopy /s "%LocalLibraries%\Adafruit_Sensor" "%TargetLibraryFolder%\Adafruit_Sensor" /i /y
xcopy /s "%LocalLibraries%\Arduino_SigFox_for_MKRFox1200" "%TargetLibraryFolder%\Arduino_SigFox_for_MKRFox1200" /i /y
xcopy /s "%LocalLibraries%\ArduinoLowPower" "%TargetLibraryFolder%\ArduinoLowPower" /i /y
xcopy /s "%LocalLibraries%\DHT_sensor_library" "%TargetLibraryFolder%\DHT_sensor_library" /i /y
xcopy /s "%LocalLibraries%\RTCZero" "%TargetLibraryFolder%\RTCZero" /i /y
xcopy /s "%LocalLibraries%\sds011_mkrfox" "%TargetLibraryFolder%\sds011_mkrfox" /i /y