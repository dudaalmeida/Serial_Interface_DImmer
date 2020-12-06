#include "mbed.h"

Serial pc(USBTX, USBRX, 9600);
PwmOut light (p9);

volatile char c = '\0';

void onCharReceived() {
c = pc.getc();
}

float i = 0.5;

int main() {
    lights = i;
    pc.attach(&onCharReceived); 
    while (1) {
        if (c != '\0') {
            switch(c) {
                case '+' :
                    if(i<=0.95)) i += 0.05;
                    pc.printf("Intensidade = %.2f \n", i);
                    break;
                case '-' :
                    if(i>=0.05)) i -= 0.05;
                    pc.printf("Intensidade = %.2f \n", i);
                    break;
                case '*' :
                    i = 1;
                    pc.printf("Intensidade = %.2f \n", i);
                    break;
                case '/' :
                    i = 0;
                    pc.printf("Intensidade = %.2f \n", i);
                    break;
                default :
                    pc.printf("Caracter Invalido\n");
                    break;
                }
            lights = i;
            c = '\0'; 
            }
        wait_ms(50);
        }
    }