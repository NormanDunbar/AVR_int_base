#ifndef AVR_INT_BASE_H
#define AVR_INT_BASE_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

namespace intbase {

	class AVR_int_base {
		// This class is a base class for AVR_int0 and AVR_int1 as
		// these two share a few commonalities.

	public:

		// a void function to call when the interrupt occurs. 
		typedef void (*onInterrupt)();

		
		// Constructor. 
		AVR_int_base(uint8_t eb, uint8_t fb, uint8_t tb);

		
		// Enable and disable the interrupt.
		void enable(uint8_t trigger) {
		    // Clear existing bits, and set up new trigger.
		    EICRA &= ~(triggerBitMask);
		    EICRA |= (trigger);

		    // Clear the flag bit, in case set already.
		    EIFR |= (1 << flagBit);

		    // Enable the interrupt.
		    EIMSK |= (1 << enableBit); 

		};

		void disable() { 
		    // Disable the interrupt.
		    EIMSK &= ~(1 << enableBit);

		    // Clear the trigger bits.
		    EICRA &= ~(triggerBitMask);
		};


		// Is the interrupt enabled?
		// !! is correct by the way! It forces a 0 or 1 result.
		// It's the same as ((EIMSK & (1 << INT0)) >> INT0.
		// Must be overridden in descendant classes.
		bool isEnabled() { 
		    return !!(EIMSK & (1 << enableBit)); 
		};

		// Is the "has been triggered but is not yet enabled" 
		// flag bit been set?
		bool isTriggered() { 
		    return !!(EIFR & (1 << flagBit)); 
		};

		// Reset the flag bit to prevent spurious interrupt
		// triggering if the stimulus was seen before 
		// enabling the interrupt.
		// In the manner of AVR weirdness, we write a 1 to 
		// a 1 bit to clear it to 0. XOR anyone?
		void resetFlagBit() { 
		    EIFR |= (1 << flagBit); 
		};

		// Allow a user function to be attached to the interrupt.
		void onInterruptTriggered(onInterrupt functionName);

		// Allow the ISR to call the interrupt function.
		void interrupt() {
		    if (interruptFunction) {
		        interruptFunction();
		    }
		}

	private:
		// Bit in EIMSK to enable this interrupt. 
		// INT0 or INT1.
		uint8_t enableBit;

		// Flag bit in EIFR for this interrupt. 
		// INTF0 or INTF1.
		uint8_t flagBit;

		// Bit mask for the two bits to define this interrupt's
		// trigger. INT0 = 0x03 or INT 1 = 0x0C
		// 
		uint8_t triggerBitMask;

		// (User) function to call when triggered.
		onInterrupt interruptFunction;
	};

} // End of namespace.

#endif // AVR_INT_BASE_H
