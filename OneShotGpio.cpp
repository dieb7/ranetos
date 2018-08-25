/*
 * OneShotGpio.cpp
 *
 *  Created on: Aug 25, 2018
 *      Author: diebm
 */

#include "OneShotGpio.h"

namespace ranetos {

} /* namespace ranetos */

bool ranetos::OneShotGpio::isOn() {
	switch (currentState) {
	case OFF_STATE:
		if (gpio.isOn()) {
			currentState = ON_STATE;
		}
		break;
	case ON_STATE:
		currentState = CHECKED_STATE;
		break;
	case CHECKED_STATE:
		if (!gpio.isOn()) {
			currentState = OFF_STATE;
		}
		break;
	default:
		break;
	}
	return currentState == ON_STATE;
}
