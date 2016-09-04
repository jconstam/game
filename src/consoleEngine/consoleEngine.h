#include <string>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <ncurses.h>

class ConsoleEngine
{
	private:
		pthread_t		outputThreadHandle;
		unsigned int	height;
		unsigned int	width;
		bool			running;
		bool			exitRequested;
		WINDOW*			windowHandle;

		static void*	outputThreadFunction( void* );

		void 			writeOutput( void );
		void			initializeOutput( void );

	public:
		ConsoleEngine( unsigned int, unsigned int );
		~ConsoleEngine( void );

		bool			IsRunning( void );

		void			Shutdown( void );
};
