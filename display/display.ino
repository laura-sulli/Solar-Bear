#include <Adafruit_GFX.h> // Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;


#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    tft.reset();
    uint16_t identifier = tft.readID();
    Serial.print("ID = 0x");
    Serial.println(identifier, HEX);
    if (identifier == 0xEFEF) identifier = 0x9486;
    tft.begin(identifier);
    //  tft.fillScreen(BLACK);
}

char *msg[] = { "PORTRAIT", "LANDSCAPE", "PORTRAIT_REV", "LANDSCAPE_REV" };
uint8_t aspect;


void loop()
{
    // put your main code here, to run repeatedly:
    constants();
    delay(1000); 
    tft.setTextSize(2);
    tft.setTextColor(YELLOW);
    tft.setCursor(0, 80);
    tft.println("Solar Panel Charge");
    delay(1000);
    tft.setTextColor(GREEN);
    tft.setCursor(0,100);
    tft.println("420 WATTS");
    delay(1000);
    tft.setTextColor(BLUE);
    tft.setCursor(0, 160);
    tft.println("Hand Crank Charge");
    delay(1000);
    tft.setTextColor(CYAN);
    tft.setCursor(0,180);
    tft.println("69 WATTS");
    delay(1000);
    tft.setTextColor(MAGENTA);
    tft.setCursor(0, 240);
    tft.println("Battery Charge");
    delay(1000);
    tft.setTextColor(WHITE);
    tft.setCursor(0,260);
    tft.println("42069 WATTS!!!!!!!!!!!");
    delay(1000);
    delay(3000);
    pulsedisplay();
}

void constants()
{
    tft.setRotation(0);
    tft.fillScreen(0x0000);
    tft.setCursor(0, 10);
    tft.setTextSize(4);
    tft.setTextColor(RED);
    tft.println("Solar Bear");
}

void pulsedisplay(){
    tft.setTextColor(RED);
    tft.setTextSize(4);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0,80);
    tft.println("DISPLAY");
    tft.setCursor(0,160);
    tft.println("ACTIVATED");
    delay(80);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0,80);
    tft.println("DISPLAY");
    tft.setCursor(0,160);
    tft.println("ACTIVATED");
    delay(80);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0,80);
    tft.println("DISPLAY");
    tft.setCursor(0,160);
    tft.println("ACTIVATED");
   
}
