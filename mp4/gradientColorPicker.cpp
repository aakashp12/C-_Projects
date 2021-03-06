#include <stdlib.h>
#include "gradientColorPicker.h"
#include <cmath>

/**
 * Constructs a new gradientColorPicker.
 *
 * @param fadeColor1 The first color to start the gradient at.
 * @param fadeColor2 The second color to end the gradient with.
 * @param radius How quickly to transition to fadeColor2.
 * @param centerX X coordinate for the center of the gradient.
 * @param centerY Y coordinate for the center of the gradient.
 */
gradientColorPicker::gradientColorPicker(RGBAPixel fadeColor1,
                                         RGBAPixel fadeColor2, int radius,
                                         int centerX, int centerY)
{
    /**
     * @todo Construct your gradientColorPicker here! You may find it
     *	helpful to create additional member variables to store things.
     */
     theFade1 = fadeColor1; // just setting up the object with initial values
     theFade2 = fadeColor2;

     theRadius = radius;
     theCenterX = centerX;
     theCenterY = centerY;
}

/**
 * Picks the color for pixel (x, y).
 *
 * The first color fades into the second color as you move from the initial
 * fill point, the center, to the radius. Beyond the radius, all pixels
 * should be just color2.
 *
 * You should calculate the distance between two points using the standard
 * Manhattan distance formula,
 *
 * \f$d = |center\_x - given\_x| + |center\_y - given\_y|\f$
 *
 * Then, scale each of the three channels (R, G, and B) from fadeColor1 to
 * fadeColor2 linearly from d = 0 to d = radius.
 *
 * For example, the red color at distance d where d is less than the radius
 * must be
 *
 * \f$ redFill = fadeColor1.red - \left\lfloor
   \frac{d*fadeColor1.red}{radius}\right\rfloor +
   \left\lfloor\frac{d*fadeColor2.red}{radius}\right\rfloor\f$
 *
 * Note that all values are integers. If you do not follow this formula,
 * your colors may be very close but round differently than ours.
 *
 * @param x The x coordinate to pick a color for.
 * @param y The y coordinate to pick a color for.
 * @return The color selected for (x, y).
 */
RGBAPixel gradientColorPicker::operator()(int x, int y)
{
    RGBAPixel color;
    /**
     * @todo Return the correct color here!
     */
    int d = abs(theCenterX - x) + abs(theCenterY - y); // this gets the distance we need later on 

    if(d == 0 || d <= theRadius)
    {
        color.red = theFade1.red - floor( (d * theFade1.red) / (theRadius)) + floor( (d * theFade2.red) / (theRadius));
        color.green = theFade1.green - floor( (d * theFade1.green) / (theRadius)) + floor( (d * theFade2.green) / (theRadius));
        color.blue = theFade1.blue - floor( (d * theFade1.blue) / (theRadius)) + floor( (d * theFade2.blue) / (theRadius));
    }
    else
        color = theFade2;
    return color;
}
