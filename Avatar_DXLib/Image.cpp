#include "DxLib.h"
#include "Image.h"

Image::Image(const TCHAR* path) {
	sizeX = 0;
	sizeY = 0;
	positionX = 0;
	positionY = 0;
	handle = LoadGraph(path); // 画像をロード
	GetGraphSize(handle, &sizeX, &sizeY); // サイズの取得
}

Image::~Image() {
	DeleteGraph(handle);
}

void Image::Scale(double x, double y) {
	sizeX = (int)(sizeX * x);
	sizeY = (int)(sizeY * y);
}

void Image::Position(int x, int y) {
	positionX = x;
	positionY = y;
}

void Image::Draw() const {
	DrawExtendGraph(
		positionX - sizeX,
		positionY - sizeY,
		positionX + sizeX,
		positionY + sizeY,
		handle,
		TRUE
	);
}