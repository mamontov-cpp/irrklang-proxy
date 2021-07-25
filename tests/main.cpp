// This is a basic irrKlang demo with edits to make MinGW-x64 work

#include <stdio.h>
#include <irrKlang.h>
#include "../include/irrklang-proxy.h"

// include console I/O methods (conio.h for windows, our wrapper in linux)
#if defined(WIN32)
#include <windows.h>
#include <conio.h>
#else

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

#endif


#ifdef _MSC_VER
	#define getch _getch
#endif

using namespace irrklang;


int main(int argc, const char** argv)
{
	// start the sound engine with default parameters
	ISoundEngine* engine = irrklangProxy::createIrrKlangDevice(ESOD_AUTO_DETECT, ESEO_DEFAULT_OPTIONS, 0, IRR_KLANG_VERSION);

	if (!engine)
	{
		printf("Could not startup engine\n");
		return 0; // error starting up the engine
	}

	// To play a sound, we only to call play2D(). The second parameter
	// tells the engine to play it looped.

	// play some sound stream, looped
	irrklangProxy::ISoundEngine::play2DFileName(engine, "../../getout.ogg", true, false, false, irrklang::ESM_AUTO_DETECT,false);

	// In a loop, wait until user presses 'q' to exit or another key to
	// play another sound.

	printf("\nHello World!\n");

	do
	{
		printf("Press any key to play some sound, press 'q' to quit.\n");

		// play a single sound
		irrklangProxy::ISoundEngine::play2DFileName(engine, "../../bell.wav", false, false, false, irrklang::ESM_AUTO_DETECT,false);
	}
	while(getch() != 'q');

	// After we are finished, we have to delete the irrKlang Device created earlier
	// with createIrrKlangDevice(). Use ::drop() to do that. In irrKlang, you should
	// delete all objects you created with a method or function that starts with 'create'.
	// (an exception is the play2D()- or play3D()-method, see the documentation or the
	// next example for an explanation)
	// The object is deleted simply by calling ->drop().

	irrklangProxy::ISoundEngine::dropSoundEngine(engine); // delete engine
	
	return 0;
}
