/*
 * InputDebouncer.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: diebm
 */

#include "GpioDebouncer.h"

namespace ranetos {

} /* namespace ranetos */

bool ranetos::GpioDebouncer::isOn() {
	switch (currentState) {
	case OFF_STATE:
		if (input.isOn()) {
			timer.setTimeOut(delay);
			currentState = DEBOUNCING_STATE;
		}
		break;
	case DEBOUNCING_STATE:
		if (timer.timedOut()) {
			if (input.isOn()) {
				currentState = ON_STATE;
			} else {
				currentState = OFF_STATE;
			}
		}
		break;
	case ON_STATE:
		if (!input.isOn()) {
			timer.setTimeOut(delay);
			currentState = DEBOUNCING_STATE;
		}
		break;
	default:
		break;
	}

	return currentState == ON_STATE;
}
