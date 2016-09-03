#include <iostream>
#include "consoleEngine.h"

using namespace std;

ConsoleEngine::ConsoleEngine( void )
{
	pthread_create( &( ConsoleEngine::threadHandle ), nullptr, ConsoleEngine::threadFunction, nullptr );
}

void* ConsoleEngine::threadFunction( void* param )
{
	cout << "Hello World!" << endl;

	pthread_exit( 0 );
}
