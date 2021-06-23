#include "orGate.h"

void orGate::calcOut() {
	if (in1->getValue() == 1 || in2->getValue() == 1) {
		out1->setValue(1);
	}
	else
		out1->setValue(0);
}