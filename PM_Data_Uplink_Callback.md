
## DHT22 Data Uplink Callback


Type: `DATA` `UPLINK`  

Channel: `URL`  

Custom payload config:  

```
state::uint:8:little-endian moduleTemperature::int:16:little-endian pm25::uint:16:little-endian pm10::uint:16:little-endian
```  

URL pattern:  
```
https://web-week-<NUMBER>.my-prtg.com:5051/{device}-pm
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
                "channel": "state",
                "value": {customData#state}
           
          },
          {
                "channel": "moduleTemperature",
                "value": {customData#moduleTemperature},
                "float": "1",
                "unit": "custom",
                "customunit": "°C"
           
          },
          {
                "channel": "pm25",
                "value": {customData#pm25},
                "float": "1",
                "unit": "custom",
                "customunit": "µg/m³"
          },
          {
                "channel": "pm10",
                "value": {customData#pm10},
                "float": "1",
                "unit": "custom",
                "customunit": "µg/m³"           
          }
      ]
     }   
 }
```
