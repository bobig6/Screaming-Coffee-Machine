# Screaming-Coffee-Machine

![Screaming Coffee Machine Logo](https://github.com/bobig6/Screaming-Coffee-Machine/blob/master/Photos/coffee.png?raw=true)

Проектът ни е кафемашина, която в посочен от теб час, ти приготвя кафе и те събужда със звуков сигнал


## Как да си сваля и използвам проекта?

Трябват ви следните части:

     - Стара кафемашина
     - Arduino Mega
     - SRD-05VDC-SL-C реле
     - DS3231 Real Time Clock 
     - ТМ1637 display
     - ESP-01 WiFi Module
     - ESP-01 USB Programmer 
     - Micro SD Card Module 
     - 2 броя бутони
     - ML144110VP 6 bit DAC
     - UA741 Op-Amp


### Инструкции за сваляне и инсталация

1) Изтеглете си файла *CoffeeMachine.ino*
2) Отворете го в Arduino IDE
3) Свържете ардуиното си към компютъра
4) Изберете **Tools > Board > Arduino/Genuino Mega or Mega 2560**
5) Изберете **Tools > Port** и порта, който ви е показан
6) Изберете **Upload**
7) Поставете ESP модула в програматора
8) Свържете **RESET** пина с **GND** пина на ESP модула
9) Отворете *ESP8266.ino*
10) Изберете **File > Preferences > Additional Boards Manager URLs:**
11) Поставете този линк: https://arduino.esp8266.com/stable/package_esp8266com_index.json
12) Изберете **Tools > Board > Boards Manager**
13) Потърсете **ESP8266** и инсталираите **“ESP8266 by ESP8266 Community“**
14) Изберете **Tools > Board > Generic ESP8266 Module**
15) Изберете **Tools > Port** и порта, към който е свързан програматорът
16) Изберете **Upload**

### Инструкции за сглобяване
Свържете пиновете на компонентите по следният начин:

1) Дисплей:
      - CLK -> pin 9
      - DIO -> pin 28
      - VCC -> 5V
      - GND -> GND
2) ESP:
      - VCC -> 3.3V
      - GND -> GND
      - GPIO 0 -> pin 32
3) Relay:
      - VCC -> 5V
      - GND -> GND
      - IN -> pin 10
4) Buttons:
      - pin 30 and pin 31
5) DS3231:
      - VCC -> 5V
      - GND -> GND
      - SCL -> SCL on Mega
      - SDA -> SDA on Mega


### Инструкции за стартиране на проекта

Свържете вашата кафемашина към релето и поберете всичко вътре. Enjoy!

## Използвани технологии

* Arduino
* C

## Автори

* Боян Иванов
* Симеон Георгиев

