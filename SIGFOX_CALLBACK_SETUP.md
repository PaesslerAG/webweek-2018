
## New callback


Type: `DATA` `UPLINK`  

Channel: `URL`  

Custom payload config:  

```
moduleTemperature::int:16:little-endian dhtTemperature::int:16:little-endian dhtHumidity::uint:16:little-endian laststatus::uint:8:little-endian
```  

URL pattern:  
```
https://web-week-<NUMBER>.my-prtg.com:5051/{device}-DHT22
```  
 
Use HTTP Method: `POST`  

Content type: 
```
application/json
```  

Body:

```json
{
     "prtg": {
        "text": "OK",
        "result": [
          {
                "channel": "Temperature",
                "value": {customData#dhtTemperature},
                "float": "1",
                "unit": "custom",
                "customunit": "°C",
                "limitminwarning": "0",
                "limitminerror": "-5",
                "limitmaxwarning": "25",
                "limitmaxerror": "35"

          },
          {
                "channel": "Humidity",
                "value": {customData#dhtHumidity},
                "float": "1",
                "unit": "custom",
                "customunit": "%",
                "limitmode": "1",
                "limitminwarning": "25",
                "limitminerror": "10"

          },
          {
                "channel": "moduleTemperature",
                "value": {customData#moduleTemperature},
                "float": "1",
                "unit": "custom",
                "customunit": "°C"

          },
          {
                "channel": "moduleStatus",
                "value": {customData#laststatus}

          }
      ]
     }   
}
```
