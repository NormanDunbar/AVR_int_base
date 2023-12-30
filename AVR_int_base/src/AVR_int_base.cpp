#include "AVR_int_base.h"

namespace intbase {

	// Constructor.
	AVR_int_base::AVR_int_base(uint8_t eb, uint8_t fb, uint8_t tb) 
		: enableBit(eb), 
		  flagBit(fb),
		  triggerBitMask(tb),
		  interruptFunction(nullptr)
	{}


	// Make sure we have a function to call when the 
	// interrupt fires.
	void AVR_int_base::onInterruptTriggered(onInterrupt functionName) {
		// Probably best not to change this when enabled!
		if (!isEnabled()) {
		    interruptFunction = functionName;
		}
	}

} // End of namespace.
