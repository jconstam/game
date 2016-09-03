#include <pthread.h>

class ConsoleEngine
{
	private:
		pthread_t threadHandle;

		static void* threadFunction( void* );

	public:
		ConsoleEngine( void );
};
