import requests

apiKey = "3410a8375afbfb13baeeff03f2472b6b"

#r = requests.get("http://api.openweathermap.org/data/2.5/weather?q=Basel&APPID=" + apiKey)

r = requests.post("http://192.168.1.177", "bitches in da house!!!")

print(r.text)
print(r.content)
