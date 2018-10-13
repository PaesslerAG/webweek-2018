
## GEOLOCATION Callback


Type: `SERVICE` `GEOLOC`  

Channel: `URL`   

URL pattern:  
```
https://web-week-<NUMBER<.my-prtg.com:5051/{device}-geoloc
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
                "channel": "Latitude",
            	"float": 1,
                "value": {lat},
                "unit": "custom",
                "customunit": "°"
            
          },
          {
                "channel": "Longitude",
            	"float": 1,
                "value": {lng},
                "unit": "custom",
                "customunit": "°"
            
          },
          {
                "channel": "Accuracy",
                "value": {radius},
                "unit": "custom",
                "customunit": "m"
            
          },
          {
                "channel": "seqNumber",
                "value": {seqNumber},
                "unit": "custom",
                "customunit": ""
            
          },
          {
                "channel": "SNR",
                "float": 1,
                "value": {snr},
                "unit": "custom",
                "customunit": "dB"
            
          },
          {
                "channel": "RSSI",
                "float": 1,
                "value": {rssi},
                "unit": "custom",
                "customunit": "dBm"
            
          }  
    ]
  }
}
```
