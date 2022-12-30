#pragma once

#define MAX_CAMERA_ZOOM		70
#define MIN_CAMERA_ZOOM		15

class cSmoothCamera
{
public:
	cSmoothCamera();
	~cSmoothCamera();
	void SetState(bool s);
	void Toggle();
	void Restore();
	void SetCurrentValue();
	void SetDefaultValue();
	void Camera();

private:
	BOOL  enable;
	float Temp_Zoom_Value;
	float Temp_Zoom_ValueX;
	float StackZoom;
	float StackX;
	float StackY;
	bool  isHold;
	short MouseStore[2];
private:

};

extern cSmoothCamera SmoothCamera;