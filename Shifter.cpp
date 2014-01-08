#include "Shifter.h"

void LowGear() {
	// Shift to low gear
}

void HighGear() {
	// Shift to high gear
}

void ToggleGear() {
	if (GetGear() == 0) {
		HighGear();
	} else {
		LowGear();
	}
}

int CurrentGear() {
	// Return the current gear, somehow
}
