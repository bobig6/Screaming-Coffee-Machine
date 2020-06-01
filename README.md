# Screaming-Coffee-Machine

![alt text](https://github.com/bobig6/Screaming-Coffee-Machine/blob/master/VideoAndPhotos/coffee.png?raw=true)

Проектът ни е кафемашина, която в посочен от теб час, ти приготвя кафе и те събужда със звуков сигнал


## Как да си сваля и използвам проекта?

Трябват ви следните части:

     - Стара кафемашина
     - Ардуино Мега
     - SRD-05VDC-SL-C реле
     - DS3231 Real Time Clock 
     - ТМ1637 дисплей
     - ESP8266
     - SPI Micro SD card module 
     - 2 броя бутони

### Инструкции за сваляне и инсталация

1) Изтеглете си файла CoffeeMachine.ino
2) Отворете го в Arduino IDE
3) Свържете ардуиното си към компютъра
4) Изберете Tools>Board>Arduino/Genuino Mega or Mega 2560
5) Изберете Tools>Port и порта, който ви е показан

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

