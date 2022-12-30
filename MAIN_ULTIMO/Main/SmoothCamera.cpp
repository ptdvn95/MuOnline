#include "stdafx.h"
#include "SmoothCamera.h"
#include "Util.h"
#include "Import.h"

cSmoothCamera SmoothCamera;

cSmoothCamera::cSmoothCamera()
{
	this->enable = false;

	this->StackZoom = 0;

	this->StackX = 0;

	this->StackY = 0;

	this->isHold = false;
}

cSmoothCamera::~cSmoothCamera()
{
}


void cSmoothCamera::Toggle() // OK
{
	if (*(DWORD*)(0x00E609E8) == 5)
	{
		this->enable ^= 1;
	}
}

void cSmoothCamera::Restore() // OK
{
	if (*(DWORD*)(0x00E609E8) == 5)
	{
		this->SetDefaultValue();
	}
}

void cSmoothCamera::SetCurrentValue() // OK
{
	SetDouble(0x00D2C848, (4190.0f + (abs(((*(double*)0x00D255A0) - 150.0f))*3.0f)));

	SetDouble(0x00D2C898, (4190.0f + (abs(((*(double*)0x00D255A0) - 150.0f))*3.0f)));

	SetFloat(0x00D2C894, (5400.0f + (((float)abs(((*(double*)0x00D255A0) - 150.0f)))*3.0f)));

	SetFloat(0x00D2C8A8, (5400.0f + (((float)abs(((*(double*)0x00D255A0) - 150.0f)))*3.0f)));

	SetFloat(0x00D2570C, (2100.0f + (((float)abs(((*(double*)0x00D255A0) - 150.0f)))*3.0f)));
}

void cSmoothCamera::SetDefaultValue() // OK
{
	this->StackZoom = 0;

	this->StackX = 0;

	this->StackY = 0;

	this->isHold = false;

	SetFloat(0x00D27BFC, 35);
	SetFloat(0x087933D8, -45);
	SetFloat(0x00D27B88, -48.5);
	SetDouble(0x00D255A0, 150);

	//for what?
	SetDouble(0x00D2C848, 1190);
	SetDouble(0x00D2C898, 580);
	SetFloat(0x00D2C894, 2400);
	SetFloat(0x00D2C8A8, 3300);
	SetFloat(0x00D2570C, 2000);

}

void cSmoothCamera::Camera()
{
	if (*(bool*)0x00E609E8 != 5)
		return;

	if (pIsKeyRelease(VK_F10)){ // on/off
		this->enable ^= 1;
	}
	if (pIsKeyRelease(VK_F11)){ // restore value
		this->SetDefaultValue();
	}

	if (!this->enable) {
		return;
	}

	int mouseWheel = *(int*)0x0879337C;
	if (mouseWheel != 0)
	{
		if ((mouseWheel > 0 && this->StackZoom < 0) || (mouseWheel < 0 && this->StackZoom > 0))
			this->StackZoom = 0;
		this->StackZoom += mouseWheel * 3.0;
		*(int*)0x0879337C = 0;
	}

	if (pIsKeyRepeat(VK_MBUTTON)){
		if (this->isHold) //update
		{
			if (pCursorX != this->MouseStore[0])
			{
				this->StackX += (float)(pCursorX - this->MouseStore[0]);
			}
			if (pCursorY != this->MouseStore[1])
			{
				this->StackY += (float)(pCursorY - this->MouseStore[1]);
			}
		}
		else { //create
			this->isHold = true;
		}
		this->MouseStore[0] = pCursorX;
		this->MouseStore[1] = pCursorY;
	}

	if (pIsKeyRelease(VK_MBUTTON))
	{
		this->isHold = false;
	}

	float curZoom = *(float*)0x00D27BFC;
	float curX = *(float*)0x087933D8;
	float curY = *(float*)0x00D27B88;
	double curZ = *(double*)0x00D255A0;

	if (curX < -417.0f)
	{
		SetFloat(0x087933D8, -45.0f);
	}

	if ((curY > -45.0f && this->StackY > 0) || (curY < -70.0f && this->StackY < 0))
	{
		this->StackY = 0;
	}

	if ((curZoom >= MAX_CAMERA_ZOOM && this->StackZoom > 0) || (curZoom <= MIN_CAMERA_ZOOM && this->StackZoom < 0)) {
		this->StackZoom = 0;
	}

	float fpsRate = *(float*)0x5EF5A18 / 40.0f; //for unlimited FPS system

	float speedZoom = max(0.05 * fpsRate, abs(this->StackZoom / 25.f));
	float speedX = max(0.5 * fpsRate, abs(this->StackX / 50.f));
	float speedY = max(0.5 * fpsRate, abs(this->StackY / 50.f));

	if (this->StackZoom > 0)
	{
		SetFloat(0x00D27BFC, curZoom + speedZoom);
		this->StackZoom -= speedZoom;
		this->SetCurrentValue();
		if (this->StackZoom < speedZoom) {
			this->StackZoom = 0;
		}
	}
	else if (this->StackZoom < 0)
	{
		SetFloat(0x00D27BFC, curZoom - speedZoom);
		this->StackZoom += speedZoom;
		this->SetCurrentValue();
		if (this->StackZoom > speedZoom) {
			this->StackZoom = 0;
		}
	}

	if (this->StackX > 0)
	{
		SetFloat(0x087933D8, curX + speedX);
		this->StackX -= speedX;
		if (this->StackX < speedX) {
			this->StackX = 0;
		}
	}
	else if (this->StackX < 0)
	{
		SetFloat(0x087933D8, curX - speedX);
		this->StackX += speedX;
		if (this->StackX > speedX) {
			this->StackX = 0;
		}
	}

	if (this->StackY > 0)
	{
		SetFloat(0x00D27B88, curY + speedY);
		SetDouble(0x00D255A0, curZ - speedY * 10);
		this->StackY -= speedY;
		this->SetCurrentValue();
		if (this->StackY < speedY) {
			this->StackY = 0;
		}
	}
	else if (this->StackY < 0)
	{
		SetFloat(0x00D27B88, curY - speedY);
		SetDouble(0x00D255A0, curZ + speedY * 10);
		this->StackY += speedY;
		this->SetCurrentValue();
		if (this->StackY > speedY) {
			this->StackY = 0;
		}
	}

}
