/*
 * main.c
 *
 * Created: 9/15/2022 2:07:04 PM
 *  Author: thomane1
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>


class Led {
public:

  typedef uint8_t port_type;
  typedef uint8_t bval_type;

  // constructor
  Led(const port_type p, const bval_type b):port(p), bval(b) {
    // Set pin to output
    const port_type pdir = port - 1U;
    *reinterpret_cast<volatile bval_type*>(pdir) |= bval;

    // Set pin to low
    *reinterpret_cast<volatile bval_type*>(port) &= static_cast<bval_type>(~bval);
  }

  void toggle() const {
   *reinterpret_cast<volatile bval_type*>(port) ^= bval;
   
  }
private:
  const port_type port;
  const bval_type bval; 
  
};




int main(void)
{
 Led myLed1(0x25, 1);
 Led myLed2(0x25, 2);
 Led myLed3(0x25, 4);

 
  myLed3.toggle();
  while (1)
  {
    myLed3.toggle();
    myLed1.toggle();
    _delay_ms(200);
    myLed1.toggle();
    myLed2.toggle();
    _delay_ms(200);
    myLed2.toggle();
    myLed3.toggle();
    _delay_ms(200);
  }
}
