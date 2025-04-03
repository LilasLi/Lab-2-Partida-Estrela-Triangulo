#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
int main(void) 
{   
    // config entradas
    DDRB &= ~(1 << 1) | (1 << 2); // PB1 PB2 e como entradas
    PORTB |= (1 << 1) | (1 << 2); // ativa pull up PB1 PB2

    // config saídas
    DDRB |= ((1 << 3) | (1 << 4) | (1 << 5)); // PB3 PB4 PB5 como saídas
    PORTB &= ~((1 << 3) | (1 << 4) | (1 << 5)); // desativa pull up PB3 PB4 PB5
    while (1)
    {
        if( !(PINB & (1 << 2))) // se S1 (PB1) pressionado
        {
            PORTB |= (1 << 5); // ativa K1 (PB5)
            PORTB |= (1 << 4); // ativa K2 (PB4)
            _delay_ms(5000); // espera 5 segundo
            PORTB &= ~(1 << 4); // desativa K2 (PB4)
            PORTB |= (1 << 3); // ativa K3 (PB3)
        }
        else if( !(PINB & (1 << 1))) // se S0 (PB2) pressionado
        {
            PORTB &= ~(1 << 3); // desativa K3 (PB3)
            PORTB &= ~(1 << 4); // desativa K2 (PB4)
            PORTB &= ~(1 << 5); // desativa K1 (PB5)
        }
    }
}