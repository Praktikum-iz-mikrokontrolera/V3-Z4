#include "mbed.h"
#include "Adafruit_SSD1306.h"

#define SDA PB_14
#define SCL PB_13
#define addr 0x78

I2C magistrala(SDA, SCL);
Adafruit_SSD1306_I2c ekran(magistrala, PA_5, addr, 64, 128);
AnalogIn pot1(PA_0);
AnalogIn pot2(PA_1);

int main() {
    while(1) {
        ekran.clearDisplay();
        int x = 128 * pot1.read();
        int y = 64 * pot1.read();

        int w = (128 - x) * pot2.read();
        int h = (64 - y) * pot2;

        ekran.drawRect(x, y, w, h, WHITE);
        ekran.display();
        ThisThread::sleep_for(1ms);
    }
    return 0;
}
