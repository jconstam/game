#include "consoleEngine.h"

ConsoleEngine::ConsoleEngine( unsigned int height, unsigned int width ) :
		height( height ), width( width ), running( false ), exitRequested( false )
{
	assert( pthread_create( &( ConsoleEngine::outputThreadHandle ), nullptr, ConsoleEngine::outputThreadFunction, this ) == 0 );
}

void* ConsoleEngine::outputThreadFunction( void* param )
{
	ConsoleEngine* thisEngine = ( ConsoleEngine* ) param;

	thisEngine->running = true;

	initscr( );
	cbreak( );
	noecho( );
	resize_term( thisEngine->height, thisEngine->width );

	thisEngine->initializeOutput( );
	while( !thisEngine->exitRequested )
	{
		thisEngine->writeOutput( );
		usleep( 100000 );
	}
	delwin( thisEngine->windowHandle );
	endwin( );

	thisEngine->running = false;

	pthread_exit( 0 );
}

void ConsoleEngine::writeOutput( void )
{
	static bool up = false;
	static bool down = true;
	static bool left = false;
	static bool right = false;
	static int x = 0;
	static int y = 0;

	werase( windowHandle );

	if( down )
	{
		y++;
		if( y >= height - 3 )
		{
			up = false;
			down = false;
			right = true;
			left = false;
		}
	}
	else if( right )
	{
		x++;
		if( x >= width - 3 )
		{
			up = true;
			down = false;
			right = false;
			left = false;
		}
	}
	else if( up )
	{
		y--;
		if( y <= 0 )
		{
			up = false;
			down = false;
			right = false;
			left = true;
		}
	}
	else if( left )
	{
		x--;
		if( x <= 0 )
		{
			up = false;
			down = true;
			right = false;
			left = false;
		}
	}
	mvwaddstr( windowHandle, y, x, "X" );

	wrefresh( windowHandle );
}

void ConsoleEngine::initializeOutput( void )
{
	border( 0, 0, 0, 0, 0, 0, 0, 0 );

	windowHandle = newwin( height - 2, width - 2, 1, 1 );

	refresh( );
}

ConsoleEngine::~ConsoleEngine( void )
{
	Shutdown( );
}

bool ConsoleEngine::IsRunning( void )
{
	return running;
}

void ConsoleEngine::Shutdown( void )
{
	exitRequested = true;

	while( running )
	{
		usleep( 1000 );
	}
}
