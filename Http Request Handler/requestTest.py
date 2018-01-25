import requests

apiKey = "3410a8375afbfb13baeeff03f2472b6b"

r = requests.get("http://api.openweathermap.org/data/2.5/weather?q=Basel&APPID=" + apiKey)

print(r.text)
print(r.content)
