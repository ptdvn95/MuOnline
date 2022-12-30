#pragma once

class cFullViewMode
{
public:
	cFullViewMode();
	~cFullViewMode();
	void Init();
	void Hook();
	static void NewUISystemUpdate();
	static void NewUISystemRender();
	static void RenderInfomation();
	static void RenderCursor();
	bool Hidden;
	int  BackupHeight;
private:

};

extern cFullViewMode FullViewMode;