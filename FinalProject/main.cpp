#include "DarkGDK.h"
#include <string>
#include <map>
using namespace std;
#include "Grin.h"

void setUp();
void background();

void DarkGDK()
{
	setUp();
	Grin grin;

	while ( LoopGDK() )
	{
		grin.move();
		grin.draw();
		background();
		dbSync();
	}
}
void background()
{
	dbPasteImage(1, 0, 0);
}
void setUp()
{
	dbSetImageColorKey(0, 255, 0);
	dbLoadImage("small_mountains.bmp", 1);
	dbSyncOn();
	dbSyncRate(60);
}