#pragma once

class Image {
public:
	Image(const TCHAR* path);
	~Image();
	void Scale(double x, double y);
	void Position(int x, int y);
	void Draw();
private:
	int handle;
	int positionX;
	int positionY;
	int sizeX;
	int sizeY;
};