/* Includes para header files das bibliotecas do OLED */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* Endereço I2C do display */
#define OLED_ADDR   0x3C

/* Configuração da resolução do display (este módulo possui display 128x64) */
#define SCREEN_WIDTH    128 
#define SCREEN_HEIGHT   64  

/* Objeto do display */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() 
{
    /* Inicializa comunicação serial */
    Serial.begin(115200); // Taxa de transmissão para a comunicação serial

    /* Inicializa comunicação I2C */
    Wire.begin(4, 15);

    /* Inicializa display OLED */
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) 
    {
        Serial.println("Display OLED: falha ao inicializar");
        for(;;); // Loop infinito para parar a execução
    }
    else
    {
        Serial.println("Display OLED: inicialização ok");            
        
        /* Limpa display e configura tamanho de fonte */
        display.clearDisplay();
        display.setTextSize(2); // Aumenta o tamanho da fonte para melhor visualização
        display.setTextColor(WHITE);

        display.setCursor(0, 0); // Define o cursor no topo do display
        display.println("Hello World"); // Escreve "Hello World" no display
    
        display.display(); // Atualiza o display  
    }
}      

void loop() {
}
