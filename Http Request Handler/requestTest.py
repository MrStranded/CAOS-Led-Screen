import requests
import json

apiKey = "3410a8375afbfb13baeeff03f2472b6b"

#r = requests.get("http://api.openweathermap.org/data/2.5/weather?q=Basel&APPID=" + apiKey)
r2 = requests.get("http://api.timezonedb.com/v2/get-time-zone?key=BABN0SKZ17HX&format=json&by=zone&zone=Europe/Berlin")

j = json.loads(r2.text)
s = j["formatted"]
print(s)


# j = json.loads(r.text)
#
# print(j)
# f = float(j["main"]["temp_min"] - 273.15)
# city = j["name"]
#
# a = int(f)
# b = (f - a)*100
# s = "http://192.168.178.42/?text=Temperatur%20in%20" + city + "%3A%20" + str(a) + "%2E" + str(int(b)) + "%C2%B0C"
#
# print(s)
#
# r = requests.get(s)
