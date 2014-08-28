#include "XboxController.h"

XboxController::XboxController(uint32_t com, float deadband, float threshHold)
{
	m_com = com;
	m_deadband = deadband;
	m_threshHold = threshHold;

}

XboxController::~XboxController()
{
}

bool XboxController::isConnected()
{
	sf::Joystick::update();
	return sf::Joystick::isConnected(m_com);

}

uint32_t XboxController::getCom()
{
	return m_com;

}

void XboxController::setCom(uint32_t com)
{
	m_com = com;

}

float XboxController::getDeadband()
{
	return m_deadband;

}

void XboxController::setDeadband(float deadband)
{
	m_deadband = deadband;

}

float XboxController::getThreshHold()
{
	return m_threshHold;

}

void XboxController::setThreshHold(float threshHold)
{
	m_threshHold = threshHold;

}

float XboxController::leftStickX()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	float x = sf::Joystick::getAxisPosition(m_com, sf::Joystick::X)/100.0f;
	if(fabs(x) < m_deadband)
	{
		x = 0.0f;

	}

	return x;

}

float XboxController::leftStickY()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	float y = sf::Joystick::getAxisPosition(m_com, sf::Joystick::Y)/100.0f;
	if(fabs(y) < m_deadband)
	{
		y = 0.0f;

	}

	return y;

}

float XboxController::rightStickX()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	float x = sf::Joystick::getAxisPosition(m_com, sf::Joystick::U)/100.0f;
	if(fabs(x) < m_deadband)
	{
		x = 0.0f;

	}

	return x;

}

float XboxController::rightStickY()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	float y = sf::Joystick::getAxisPosition(m_com, sf::Joystick::V)/100.0f;
	if(fabs(y) < m_deadband)
	{
		y = 0.0f;

	}

	return y;

}

float XboxController::DPadX()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	return sf::Joystick::getAxisPosition(m_com, sf::Joystick::PovX)/100.0f;

}

float XboxController::DPadY()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	return sf::Joystick::getAxisPosition(m_com, sf::Joystick::PovY)/100.0f;

}

float XboxController::leftTriggerValue()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	float left = sf::Joystick::getAxisPosition(m_com, sf::Joystick::Z)/100.0f;
	left = (left + 1)/2;
	return left;

}

float XboxController::rightTriggerValue()
{
	sf::Joystick::update();

	if(!isConnected())
	{
		return 0.0f;

	}

	float right = sf::Joystick::getAxisPosition(m_com, sf::Joystick::R)/100.0f;
	right = (right + 1)/2;
	return right;

}

bool XboxController::leftTrigger()
{
	if(leftTriggerValue() >= m_threshHold)
	{
		return true;

	}

	return false;

}

bool XboxController::rightTrigger()
{
	if(rightTriggerValue() >= m_threshHold)
	{
		return true;

	}

	return false;

}

bool XboxController::leftBumper()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 4);

}

bool XboxController::rightBumper()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 5);

}

bool XboxController::buttonA()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 0);

}

bool XboxController::buttonB()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 1);

}

bool XboxController::buttonX()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 2);

}

bool XboxController::buttonY()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 3);

}

bool XboxController::buttonBack()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 6);

}

bool XboxController::buttonStart()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 7);

}

bool XboxController::buttonLeftStick()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 9);

}

bool XboxController::buttonRightStick()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 10);

}

bool XboxController::buttonXbox()
{
	sf::Joystick::update();
	return sf::Joystick::isButtonPressed(m_com, 8);

}

/*void XboxController::vibrate(float left, float right)
{
	/*
	XINPUT_VIBRATION vibration;
	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
	vibration.wLeftMotorSpeed = (WORD)(left*65535);
	vibration.wRightMotorSpeed = (WORD)(right*65535);
	XInputSetState(m_com, &vibration);
    //TODO: this
}*/
