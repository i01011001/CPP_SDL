#include "screen.h"
#include <numeric>
#include "unistd.h"

void line(Screen& screen, float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float length = std::sqrt( dx*dx + dy*dy);
	float angle = std::atan2(dy, dx);

	for(float i=0 ; i < length; i++)
	{
		screen.pixel(
				x1 + std::cos(angle) * i,
				y1 + std::sin(angle) * i
				);
	}
}

int x_point(int x){
	return x%640;
}
int y_point(int y){
	return y%480;
}

int main()
{
	Screen screen;

	int x0, y0=0;
	int x1, y1=0;
	int x2, y2=0;
	int x3, y3=0;

	x0 = 200; y0 = 130;
	x1 = 400; y1 = 130;
	x2 = 400; y2 = 330;
	x3 = 200; y3 = 330;


	while(true){
		for(int i=0 ; i< 100; i++){
			screen.pixel(x_point(rand()), y_point(rand()));
		}
		line(screen, x_point(x0), y_point(y0), x_point(x1), y_point(y1));
		line(screen, x_point(x1), y_point(y1), x_point(x2), y_point(y2));
		line(screen, x_point(x2), y_point(y2), x_point(x3), y_point(y3));
		line(screen, x_point(x3), y_point(y3), x_point(x0), y_point(y0));

		screen.show();
		screen.input();
		SDL_Delay(60);
		screen.clear();
	}
	return 0;
}
