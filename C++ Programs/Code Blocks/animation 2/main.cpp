#include <graphics.h>

using namespace std;

int main()
{
    initwindow (625,351,"marvel");
 readimagefile("marvel-cinematic-universe-625x351.jpg",0,0,625,351);
 delay(1000);
 readimagefile("SHIELD.jpg",0,0,625,351);
 delay(1000);
 readimagefile("ARC REACTOR.jpg",0,0,625,351);
    return 0;
}
