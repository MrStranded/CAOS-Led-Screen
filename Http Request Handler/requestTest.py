import requests
import json

apiKey = "3410a8375afbfb13baeeff03f2472b6b"

r = requests.get("http://api.openweathermap.org/data/2.5/weather?q=Basel&APPID=" + apiKey)

json.loads(r.text)

r = requests.get("http://192.168.178.42/?text=yeahboy")
