#include "MicroBit.h"

ManagedString msg;
MicroBit uBit;
bool gameOver = false;
bool atBottom = false;
int _bx = microbit_random(5);
int _by = 0;
int _x = 2;
int _y = 4;

void onBtnA(MicroBitEvent)
{
    uBit.display.image.setPixelValue(_x, _y, 0);
    _x -= _x > 0 ? 1 : 0;
}
void onBtnB(MicroBitEvent)
{
    uBit.display.image.setPixelValue(_x, _y, 0);
    _x += _x < 4 ? 1 : 0;
}
void endGame()
{
    gameOver = true;
    uBit.display.clear();
    uBit.display.scroll("LOSE!");
    gameOver = false;
}
// display platform thread
void displayDot()
{
    while (1)
    {
        if (!gameOver)
        {
            uBit.display.image.setPixelValue(_x, _y, 255);
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onBtnA);
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onBtnB);
            fiber_sleep(100);
        }
        else
        {
            fiber_sleep(1000);
        }
    }
}

// display ball thread
void displayBall()
{
    while (1)
    {
        if (!gameOver)
        {
            // turn off the lights at the previous position
            uBit.display.image.setPixelValue(_bx, _by, 0);
            if (atBottom == false)
            {
                _by += 1;
            }
            else
            {
                _by -= 1;
            }
            // check if we are at the bottom
            if (_by == 4)
            {
                msg = 'Top Hit!';
                uBit.serial.send(msg, ASYNC);
                atBottom = true;
                // check if platform is not where the ball is
                if (!((_x == _bx) && (_y == _by)))
                {
                    endGame();
                    fiber_sleep(50);
                }
            }
            // check if we are at the top of the board
            if (_by == 0)
            {
                // if so set atBottom to false to indicate we need to be falling down
                atBottom = false;
                _bx = microbit_random(5);
            }

            uBit.display.image.setPixelValue(_bx, _by, 255);
            fiber_sleep(1000);
        }
        else
        {
            fiber_sleep(1000);
        }
    }
}
int main()
{
    uBit.init();
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);
    create_fiber(displayDot);
    create_fiber(displayBall);

    release_fiber();
}
