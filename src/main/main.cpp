#include <iostream>
#include <unistd.h>
#include "consoleEngine.h"

using namespace std;

int main( int argc, char* argv[ ] )
{
	ConsoleEngine* engine = new ConsoleEngine( 40, 100 );

	while( !engine->IsRunning( ) )
	{
		sleep( 1 );
	}
	while( engine->IsRunning( ) )
	{
		sleep( 1 );
	}

	delete engine;

	return 0;
}
