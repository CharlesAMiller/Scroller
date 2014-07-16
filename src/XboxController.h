#ifndef XBOXCONTROLLER_H_
#define XBOXCONTROLLER_H_
/*
The MIT License (MIT)

Copyright (c) 2014 Harrison D. Miller

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

author: Harrison D. Miller
psuedonym: Verrazano
contact: hdmscratched@gmail.com
*/

#include <stdint.h>
#include <XInput.h>
#include "iostream"

/**XboxController class.
 */
class XboxController
{
public:
	/**XboxController constructor.
	 * @param com is the controller communication port.
	 * @param deadband is the joystick deadband.
	 * @param threshHold is the trigger threshHold.
	 */
	XboxController(uint32_t com = 0, float deadband = 0.1f, float threshHold = 0.2f);

	/**XboxController deconstructor.
	 */
	virtual ~XboxController();

	/**Returns true if the XboxController is connected.
	 * @reutrn true if the XboxController is connected.
	 */
	bool isConnected();

	/**Returns the com port.
	 * @return the com port.
	 */
	uint32_t getCom();

	/**Sets the com port.
	 * @param com the new com port.
	 */
	void setCom(uint32_t com);

	/**Returns the deadband.
	 * @return the deadband.
	 */
	float getDeadband();

	/**Sets the joystick deadband.
	 * Deadband is a cut off value for joysticks if the joystick value
	 * is below the deadband it is set to 0.
	 * @param the new deadband.
	 */
	void setDeadband(float deadband);

	/**Returns the threshHold.
	 * @return the threshHold.
	 */
	float getThreshHold();

	/**Sets the trigger threshold.
	 * Threshold is the point where a trigger is considered pressed.
	 * @param threshHold the new threshHold.
	 */
	void setThreshHold(float threshHold);

	/**Returns the value of the left joystick x.
	 * @return value from 1 to -1.
	 */
	float leftStickX();

	/**Returns the value of the left joystick y.
	 * @return value from 1 to -1.
	 */
	float leftStickY();

	/**Returns the value of the right joystick x.
	 * @return value from 1 to -1.
	 */
	float rightStickX();

	/**Returns the value of the right joystick y.
	 * @return value from 1 to -1.
	 */
	float rightStickY();

	/**Returns the value of the dpad x.
	 * @return value from 1 to -1.
	 */
	float DPadX();

	/**Returns the value of the dpad y.
	 * @return value from 1 to -1.
	 */
	float DPadY();

	/**Returns the value of the left trigger.
	 * a value of 0 is all the way unpressed.
	 * a value of 1 is all the way pressed.
	 * @return value from 0 to 1.
	 */
	float leftTriggerValue();

	/**Returns the value of the right trigger.
	 * a value of 0 is all the way unpressed.
	 * a value of 1 is all the way pressed.
	 * @return value from 0 to 1.
	 */
	float rightTriggerValue();

	/**Returns true if leftTriggerValue is above the threshHold.
	 * @return true if leftTriggerValue is above the threshHold.
	 */
	bool leftTrigger();

	/**Returns true if rightTriggerValue is above the threshHold.
	 * @return true if rightTriggerValue is above the threshHold.
	 */
	bool rightTrigger();

	/**Returns true if the left bumper is pressed.
	 * @return true if the left bumper is pressed.
	 */
	bool leftBumper();

	/**Returns true if the left bumper is pressed.
	 * @return true if the left bumper is pressed.
	 */
	bool rightBumper();

	/**Returns true if the A button is pressed.
	 * @return true if the A button is pressed.
	 */
	bool buttonA();

	/**Returns true if the B button is pressed.
	 * @return true if the B button is pressed.
	 */
	bool buttonB();

	/**Returns true if the X button is pressed.
	 * @return true if the X button is pressed.
	 */
	bool buttonX();

	/**Returns true if the Y button is pressed.
	 * @return true if the Y button is pressed.
	 */
	bool buttonY();

	/**Returns true if the back button is pressed.
	 * @return true if the back button is pressed.
	 */
	bool buttonBack();

	/**Returns true if the start button is pressed.
	 * @return true if the start button is pressed.
	 */
	bool buttonStart();

	/**Returns true if the left stick button is pressed.
	 * @return true if the left stick button is pressed.
	 */
	bool buttonLeftStick();

	/**Returns true if the right stick button is pressed.
	 * @return true if the right stick button is pressed.
	 */
	bool buttonRightStick();

	/**Returns true if the xbox button is pressed.
	 * @return true if the xbox button is pressed.
	 */
	bool buttonXbox();

	/**Rumbles the XboxController.
	 * Currently only supported on windows.
	 * @param left the left motor rumble value.
	 * @param right the right motor rumble value.
	 */
	void vibrate(float left = 0.5f, float right = 0.5f);

private:
	uint32_t m_com; ///< the communication port of the controller.
	float m_deadband; ///< the deadband to be applied to joystick values.
	float m_threshHold; ///< the threshHold to detect trigger presses.

};

#endif /* XBOXCONTROLLER_H_ */
