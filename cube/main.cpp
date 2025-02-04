#include "screen.h"
#include "unistd.h"

int main()
{
	Screen screen;

	while(true){
		for(int i=0 ; i< 100; i++){
			screen.pixel(rand()%640, rand()%480);
		}
		screen.show();
		screen.input();
		sleep(2);
		screen.clear();
	}
	return 0;
}
