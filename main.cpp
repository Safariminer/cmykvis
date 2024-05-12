/*


cmykvis: a tool to visualise and convert cmyk to rgb


*/

#include <iostream>
#include <raylib.h>
#include <raymath.h>

int main() {
	// Initialize raylib
	InitWindow(1280, 720, "cmykvis");
	SetTargetFPS(60);

	float c, m, y, k;
	c = 100; m = 100; y = 100; k = 100; // percentages of color represented as integers.à

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground({
			(unsigned char)(int)(255.0f * (1 - (c / 100)) * (1 - k / 100)), // R = 255 * (1-C) * (1-K) | C and K are percentages, which is why they're divided by 100 in this code.
			(unsigned char)(int)(255.0f * (1 - (m / 100)) * (1 - k / 100)), // G = 255 * (1-M) * (1-K) | M and K are percentages, which is why they're divided by 100 in this code.
			(unsigned char)(int)(255.0f * (1 - (y / 100)) * (1 - k / 100)), // B = 255 * (1-Y) * (1-K) | Y and K are percentages, which is why they're divided by 100 in this code.
			255
		});
		
		SetWindowTitle("cmykvis - Press C, M, Y, or K and scroll up or down to change the color.");
		DrawRectangle(0, GetScreenHeight() - 20, GetScreenWidth(), 20, BLACK);

		DrawText(TextFormat("C:%f - M:%f - Y:%f - K:%f | R:%f - G:%f - B:%f",
			c,
			m,
			y,
			k,
			(255 * (1 - (c / 100)) * (1 - k / 100)),
			(255 * (1 - (m / 100)) * (1 - k / 100)),
			(255 * (1 - (y / 100)) * (1 - k / 100))
		), 0, GetScreenHeight() - 20, 20, WHITE);

		if (IsKeyDown(KEY_C)) c = Clamp(c + GetMouseWheelMove(), 0, 100);
		if (IsKeyDown(KEY_M)) m = Clamp(m + GetMouseWheelMove(), 0, 100);
		if (IsKeyDown(KEY_Y)) y = Clamp(y + GetMouseWheelMove(), 0, 100);
		if (IsKeyDown(KEY_K)) k = Clamp(k + GetMouseWheelMove(), 0, 100);

		EndDrawing();
	}
}