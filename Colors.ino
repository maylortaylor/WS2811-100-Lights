/***************************************************************************************
  Single Colors
***************************************************************************************/
void All_Red()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, strip.Color(currBrightness, 0, 0)); // Red
    }
    strip.show();
}
void All_Green()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, strip.Color(0, currBrightness, 0)); // Green
    }
    strip.show();
}
void All_Blue()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 0, currBrightness)); // Blue
    }
    strip.show();
}
void All_White()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, strip.Color(currBrightness, currBrightness, currBrightness)); // White
    }
    strip.show();
}
void AmberWhite()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, Strip_Amber(currBrightness));
        strip.setPixelColor(i + 1, Strip_White(currBrightness));
    }
    strip.show();
}
void PurpleTeal()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, Strip_Purple(currBrightness));
        strip.setPixelColor(i + 1, Strip_BlueGreen(currBrightness));
    }
    strip.show();
}

/***************************************************************************************
  Rainbow Colors
  1) spaceinc = space between colors, increment to have a greater gap
  2) timeinc = time between each color, increment for faster color transitions
***************************************************************************************/
void RainbowYoffset(float _speed, float _spacing, bool _useFadeDirection)
{
    timeinc = _speed;
    spaceinc = _spacing;

    if (_useFadeDirection)
    {
        if (fadeDirection2 == 1)
        {
            yoffset += timeinc;
        }
        if (fadeDirection2 == 0)
        {
            yoffset -= timeinc;
        }
    }
    else
    {
        yoffset += timeinc;
    }

    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowXoffset(float _speed, float _spacing, bool _useFadeDirection)
{
    timeinc = _speed;
    spaceinc = _spacing;

    if (_useFadeDirection)
    {
        if (fadeDirection2 == 1)
        {
            xoffset += timeinc;
        }
        if (fadeDirection2 == 0)
        {
            xoffset -= timeinc;
        }
    }
    else
    {
        xoffset += timeinc;
    }

    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowOneYoffset()
{
    spaceinc = 0.03;
    timeinc = .0007;

    if (fadeDirection2 == 1)
    {
        yoffset += timeinc;
    }

    if (fadeDirection2 == 0)
    {
        yoffset -= timeinc;
    }

    // yoffset += timeinc;
    // xoffset += timeinc;
    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowTwoYoffset()
{
    spaceinc = 0.05;
    timeinc = 0.003;
    yoffset += timeinc;
    ;
    // xoffset += timeinc;
    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowTwoYoffset01()
{
    spaceinc = 0.07;
    timeinc = 0.009;
    yoffset += timeinc;
    // xoffset += timeinc;
    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowThreeXoffset()
{
    spaceinc = 0.05;
    timeinc = 0.0005;
    // yoffset += timeinc;
    xoffset += timeinc;
    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowThreeXoffset03()
{
    spaceinc = 0.05;
    timeinc = 0.007;
    // yoffset += timeinc;
    xoffset += timeinc;
    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowFourXoffset()
{
    spaceinc = 0.03;
    timeinc = 0.0009;
    // yoffset += timeinc;
    xoffset += timeinc;
    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowFourXoffset2()
{
    spaceinc = 0.03;
    timeinc = 0.001;
    // yoffset += timeinc;
    xoffset += timeinc;
    SimplexNoisePatternInterpolated(spaceinc, timeinc, yoffset, xoffset);
}
void RainbowFive()
{
    h += .0004; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    hTemp = h + .1; // space between colors

    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}

/***************************************************************************************
  TWO Colors
***************************************************************************************/
void RedGreenBlueSteady()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 3)
    {
        strip.setPixelColor(i, strip.Color(0, currBrightness, 0));     // Green
        strip.setPixelColor(i + 1, strip.Color(currBrightness, 0, 0)); // Red
        strip.setPixelColor(i + 2, strip.Color(0, 0, currBrightness)); // Blue
    }
    strip.show();
}
void PurpleBlueSteady()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        if ((i % 2) == 0)
        {
            strip.setPixelColor(i, strip.Color(0, 0, currBrightness)); // Blue
        }
        else
        {
            strip.setPixelColor(i, strip.Color(currBrightness, 0, currBrightness)); // Purple
        }
    }
    strip.show();
}
void BlueWhiteSteady()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        if ((i % 2) == 0)
        {
            strip.setPixelColor(
                i, strip.Color(currBrightness, currBrightness, currBrightness)); // White
        }
        else
        {
            strip.setPixelColor(i, strip.Color(0, 0, currBrightness)); // Blue
        }
    }
    strip.show();
}
void LargeGroupBlueWhite(int _ledSpacing)
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + _ledSpacing)
    {
        strip.setPixelColor(i, Strip_Blue(currBrightness));
        strip.setPixelColor(i + 1, Strip_Blue(currBrightness));
        strip.setPixelColor(i + 2, Strip_Blue(currBrightness));
        strip.setPixelColor(i + 3, Strip_Blue(currBrightness));
        strip.setPixelColor(i + 4, Strip_Blue(currBrightness));
        strip.setPixelColor(i + 5, Strip_Blue(currBrightness));

        strip.setPixelColor(i + 6, Strip_White(currBrightness));
        strip.setPixelColor(i + 7, Strip_White(currBrightness));
        strip.setPixelColor(i + 8, Strip_White(currBrightness));
        strip.setPixelColor(i + 9, Strip_White(currBrightness));
        strip.setPixelColor(i + 10, Strip_White(currBrightness));
        strip.setPixelColor(i + 11, Strip_White(currBrightness));
    }
    strip.show();
}
void LargeGroupRedGreen(int _ledSpacing)
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + _ledSpacing)
    {
        strip.setPixelColor(i, Strip_Red(currBrightness));
        strip.setPixelColor(i + 1, Strip_Red(currBrightness));
        strip.setPixelColor(i + 2, Strip_Red(currBrightness));
        strip.setPixelColor(i + 3, Strip_Red(currBrightness));
        strip.setPixelColor(i + 4, Strip_Red(currBrightness));
        strip.setPixelColor(i + 5, Strip_Red(currBrightness));

        strip.setPixelColor(i + 6, Strip_Green(currBrightness));
        strip.setPixelColor(i + 7, Strip_Green(currBrightness));
        strip.setPixelColor(i + 8, Strip_Green(currBrightness));
        strip.setPixelColor(i + 9, Strip_Green(currBrightness));
        strip.setPixelColor(i + 10, Strip_Green(currBrightness));
        strip.setPixelColor(i + 11, Strip_Green(currBrightness));
    }
    strip.show();
}
/***************************************************************************************
  Rainbow Flow Colors
***************************************************************************************/
void RainbowFlow(float _speed, float _spacing)
{
    // increment 'h' to make transitions faster
    h = GetH_BouncingWithLimits(_speed, .98, .01);

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += _spacing; // decrease to space out the colors
        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}
void RainbowNoFlow()
{
    h = 0;

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .042; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}
void RainbowOne()
{
    h = 0;

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .018; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}
void RainbowFlow2()
{
    h += .0005; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .012; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}
void PurpleFlowSlow()
{
    h += .0003; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red * .07, 0, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .35; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}
void RainbowFlowSlow()
{
    h += .0005; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .0045; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}
void RainbowFlowSlowTwo()
{
    h += .00005; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .09; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}

/***************************************************************************************
  Random
***************************************************************************************/
void Pinkish()
{
    h = 85;

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {

        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .002; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}
void Purpleish()
{
    h = 0;

    float hTemp = h;

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {

        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue));

        // slowly increment 'h' by small increments to make color flow
        hTemp += .016; // decrease to space out the colors

        if (hTemp > 1)
        {
            hTemp -= 1;
        }
        if (hTemp < 0)
        {
            hTemp += 1;
        }
    }
    strip.show();
}

/***************************************************************************************
  Dual Color Flow
***************************************************************************************/
void LargeGroupColorFlowBounce(int _ledSpacing, float _speed, float _colorSpacing, float _hHigh, float _hLow)
{
    h = GetH_BouncingWithLimits(_speed, _hHigh, _hLow);

    float hTemp = h;
    hTemp = h + _colorSpacing; // space between colors
    if (hTemp > .93)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);
    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + _ledSpacing)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red, green, blue));
        strip.setPixelColor(i + 2, strip.Color(red, green, blue));
        strip.setPixelColor(i + 3, strip.Color(red, green, blue));
        strip.setPixelColor(i + 4, strip.Color(red, green, blue));
        strip.setPixelColor(i + 5, strip.Color(red, green, blue));

        strip.setPixelColor(i + 6, strip.Color(red2, green2, blue2));
        strip.setPixelColor(i + 7, strip.Color(red2, green2, blue2));
        strip.setPixelColor(i + 8, strip.Color(red2, green2, blue2));
        strip.setPixelColor(i + 9, strip.Color(red2, green2, blue2));
        strip.setPixelColor(i + 10, strip.Color(red2, green2, blue2));
        strip.setPixelColor(i + 11, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlow(float _speed, float _spacing)
{
    h = GetH_BouncingWithLimits(_speed, .97, 0);

    float hTemp = h;

    hTemp = h + _spacing; // space between colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);
    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowBounce(int _ledSpacing, float _speed, float _spacing, float _hHigh, float _hLow)
{
    h = GetH_BouncingWithLimits(_speed, _hHigh, _hLow);

    float hTemp = h;
    hTemp = h - _spacing; // space between colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }
    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);
    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + _ledSpacing)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowOne()
{
    h += .00007; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    hTemp = h + .5; // space between colors

    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowFour()
{
    float hHigh = .9;
    float hLow = .5;
    float hHigh2 = .85;
    float hLow2 = .6;

    if (h > hHigh)
    {
        h = hHigh;
        fadeDirection = 0;
    }
    if (h < hLow)
    {
        h = hLow;
        fadeDirection = 1;
    }

    if (fadeDirection == 1)
    {
        h += .00009; // increment to make faster
    }
    if (fadeDirection == 0)
    {
        h -= .00009; // decrement to make faster
    }

    float hTemp = h;

    hTemp = h - .1; // space between colors

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 6)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowPurpleFast()
{
    float hHigh = .9;
    float hLow = .5;
    float hHigh2 = .85;
    float hLow2 = .6;

    if (h > hHigh)
    {
        h = hHigh;
        fadeDirection = 0;
    }
    if (h < hLow)
    {
        h = hLow;
        fadeDirection = 1;
    }

    if (fadeDirection == 1)
    {
        h += .0009; // increment to make faster
    }
    if (fadeDirection == 0)
    {
        h -= .0009; // decrement to make faster
    }

    float hTemp = h;

    hTemp = h - .1; // space between colors

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowRedFast()
{
    float hHigh = .15;
    float hLow = .05;

    if (h > hHigh)
    {
        h = hHigh;
        fadeDirection = 0;
    }
    if (h < hLow)
    {
        h = hLow;
        fadeDirection = 1;
    }

    if (fadeDirection == 1)
    {
        h += .001; // increment to make faster
    }
    if (fadeDirection == 0)
    {
        h -= .001; // decrement to make faster
    }

    float hTemp = h;

    hTemp = h - .1; // space between colors

    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }
    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowGreenFast()
{
    float hHigh = .7;
    float hLow = .3;
    float hHigh2 = .85;
    float hLow2 = .6;

    if (h > hHigh)
    {
        h = hHigh;
        fadeDirection = 0;
    }
    if (h < hLow)
    {
        h = hLow;
        fadeDirection = 1;
    }

    if (fadeDirection == 1)
    {
        h += .0009; // increment to make faster
    }
    if (fadeDirection == 0)
    {
        h -= .0009; // decrement to make faster
    }

    float hTemp = h;

    hTemp = h - .1; // space between colors

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowPurpleSlow()
{
    float hHigh = .85;
    float hLow = .58;
    float hHigh2 = .46;
    float hLow2 = .09;

    if (h > hHigh)
    {
        h = hHigh;
        fadeDirection = 0;
    }
    if (h < hLow)
    {
        h = hLow;
        fadeDirection = 1;
    }

    if (fadeDirection == 1)
    {
        h += .00009; // increment to make faster
    }
    if (fadeDirection == 0)
    {
        h -= .00009; // decrement to make faster
    }

    float hTemp = h;

    hTemp = h - .1; // space between colors

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowPurple()
{
    float hHigh = .9;
    float hLow = .5;
    float hHigh2 = .85;
    float hLow2 = .6;

    if (h > hHigh)
    {
        h = hHigh;
        fadeDirection = 0;
    }
    if (h < hLow)
    {
        h = hLow;
        fadeDirection = 1;
    }

    if (fadeDirection == 1)
    {
        h += .00009; // increment to make faster
    }
    if (fadeDirection == 0)
    {
        h -= .00009; // decrement to make faster
    }

    float hTemp = h;

    hTemp = h - .1; // space between colors

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowTwo()
{
    h += .00009; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    hTemp = h + .9; // space between colors

    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void TealPurple()
{
    h += .0003; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    hTemp = h + .3; // space between colors

    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {
        int high = 80;
        int low = 0;
        if (red > high)
        {
            red = low;
        }
        if (red2 > high)
        {
            red2 = low;
        }
        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}
void DualColorFlowThree()
{
    h += .0003; // increment to make faster
    if (h > 1)
    {
        h -= 1;
    }
    if (h < 0)
    {
        h += 1;
    }

    float hTemp = h;

    hTemp = h + .3; // space between colors

    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {

        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
    }
    strip.show();
}

/***************************************************************************************
  Three Color Flow
***************************************************************************************/
void ThreeColorFlow(float _speed, float _spacing)
{
    h = GetH_BouncingWithLimits(_speed, .98, .01);

    //   h += _speed; // increment to make faster
    //   CheckLimitForH();

    float hTemp = h;

    hTemp = h + _spacing; // space between colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    hTemp3 = h + _spacing; // space between colors
    if (hTemp3 > 1)
    {
        hTemp3 -= 1;
    }
    if (hTemp3 < 0)
    {
        hTemp3 += 1;
    }

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);
    hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red2, green2, blue2);
    hsv2rgb(float(hTemp3), 1, (float(currBrightness) / 255.0), red3, green3, blue3);

    for (uint16_t i = 0; i < PWM_MaxPixels; i = i + 2)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
        strip.setPixelColor(i + 1, strip.Color(red2, green2, blue2));
        strip.setPixelColor(i + 2, strip.Color(red3, green3, blue3));
    }
    strip.show();
}
/***************************************************************************************
  HSV Flow
***************************************************************************************/
void PurpleTealHsvFlow(float _speed, float _high)
{
    h = GetH_BouncingWithLimits(_speed, .98, .01);

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

        strip.setPixelColor(i, Strip_Set_RGB(red, 0, blue));
        strip.setPixelColor(i + 1, Strip_Set_RGB(0, green, blue));
    }
    strip.show();
}
void PurpleTealHsv()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {

        h += .0001;      //increment to make faster
        float high = .7; //color limit
        if (h > high)
        {
            h -= high;
        }
        if (h < 0)
        {
            h += high;
        }

        float hTemp = currBrightness;
        hsv2rgb(float(hTemp), 1, (float(currBrightness) / 255.0), red, green, blue);

        strip.setPixelColor(i, strip.Color(currBrightness, 0, currBrightness));         //Red & Blue
        strip.setPixelColor(i + 1, strip.Color(0, currBrightness, currBrightness / 2)); //Red & Blue
    }
    strip.show();
}
/***************************************************************************************
  Dual Color Flow
***************************************************************************************/
void RainbowHsv(float _speed)
{
    h = GetH_BouncingWithLimits(_speed, .98, .01);

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
}
void RainbowHsvSlow()
{
    h += .0002; // increment to make faster

    if (h > 1)
    {
        h -= 1;
    }

    if (h < 0)
    {
        h += 1;
    }
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue)); // Red
    }
    strip.show();
}
void RainbowHsvSlowTwo()
{
    h += .00008; // increment to make faster

    if (h > 1)
    {
        h -= 1;
    }

    if (h < 0)
    {
        h += 1;
    }
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue)); // Red
    }
    strip.show();
}
void RainbowHsvSlowThree()
{
    h += .00095; // increment to make faster

    if (h > 1)
    {
        h -= 1;
    }

    if (h < 0)
    {
        h += 1;
    }
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);
        strip.setPixelColor(i, strip.Color(red, green, blue)); // Red
    }
    strip.show();
}
void RainbowHsvFast()
{
    h += .0007; // increment to make faster

    if (h > 1)
    {
        h -= 1;
    }

    if (h < 0)
    {
        h += 1;
    }
    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue)); // Red
    }
    strip.show();
}

/***********************************************************
  Single Pixels Moving
***********************************************************/
void RedMovingTrail(float _spacing, float _frameRate, int _timeBetweenCycles, bool _resetLeds)
{
    hTemp += _spacing; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int i = 0; i < maxPixels; i++)
    {
        //   hsv2rgb(float(hTemp), 1, (float(currBrightness / i) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - i, strip.Color(currBrightness, 0, 0));
    }

    if (_resetLeds)
    {
        // clear existing LEDs (all LEDs off)
        strip.setPixelColor(ledPosition - maxPixels, strip.Color(0, 0, 0));
    }

    ledPosition++;

    if (ledPosition > (maxPixels * _timeBetweenCycles))
    {
        ledPosition = 0;
    }

    strip.show();

    tempTimer = millis() + _frameRate;
    while (millis() < tempTimer)
    {
    }
}
void GreenMovingTrail(float _spacing, float _frameRate, int _timeBetweenCycles, bool _resetLeds)
{
    hTemp += _spacing; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int i = 0; i < maxPixels; i++)
    {
        //   hsv2rgb(float(hTemp), 1, (float(currBrightness / i) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - i, strip.Color(0, currBrightness, 0));
    }

    if (_resetLeds)
    {
        // clear existing LEDs (all LEDs off)
        strip.setPixelColor(ledPosition - maxPixels, strip.Color(0, 0, 0));
    }

    ledPosition++;

    if (ledPosition > (maxPixels * _timeBetweenCycles))
    {
        ledPosition = 0;
    }

    strip.show();

    tempTimer = millis() + _frameRate;
    while (millis() < tempTimer)
    {
    }
}
void MovingTrail(float _spacing, float _frameRate, int _timeBetweenCycles, bool _resetLeds)
{
    hTemp += _spacing; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int i = -1; i < maxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / i) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - i, strip.Color(red, green, blue));
    }

    if (_resetLeds)
    {
        // clear existing LEDs (all LEDs off)
        strip.setPixelColor(ledPosition - maxPixels, strip.Color(0, 0, 0));
    }

    ledPosition++;

    if (ledPosition > (maxPixels * _timeBetweenCycles))
    {
        ledPosition = 0;
    }

    strip.show();

    tempTimer = millis() + _frameRate;
    while (millis() < tempTimer)
    {
    }
}
void MovingTrailWithBlueTail(float _spacing, float _frameRate, int _tailSize)
{
    hTemp += _spacing; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = -1; b < _tailSize; b++)
    {
        //   hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition + b, Strip_Blue(currBrightness));
    }

    // clear existing pixels
    // strip.setPixelColor(ledPosition - maxPixels, strip.Color(0,0,0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i++)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition++;

    tempTimer = millis() + _frameRate;
    while (millis() < tempTimer)
    {
    }
}
void MovingTrailWithPurpleTail(float _spacing, float _frameRate, int _tailSize)
{
    hTemp += _spacing; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = -1; b < _tailSize; b++)
    {
        //   hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition + b, Strip_Purple(currBrightness));
    }

    // clear existing pixels
    // strip.setPixelColor(ledPosition - maxPixels, strip.Color(0,0,0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i++)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition++;

    tempTimer = millis() + _frameRate;
    while (millis() < tempTimer)
    {
    }
}
void MovingTrailWithTail(float _spacing, float _frameRate, int _tailSize)
{
    hTemp += _spacing; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = -1; b < _tailSize; b++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition + b, strip.Color(red, green, blue));
    }

    // clear existing pixels
    // strip.setPixelColor(ledPosition - maxPixels, strip.Color(0,0,0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i++)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition++;

    tempTimer = millis() + _frameRate;
    while (millis() < tempTimer)
    {
    }
}
void MovingSpiralUpMultiColor01()
{
    hTemp += .05; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    // slowly increment 'h' by small increments to make color flow
    int ii = 0;

    for (int i = 0; i < maxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / i) / 255.0), red, green, blue);
        // if ((ledPosition - i) < 0)
        // {
        // ii = maxPixels + 1 - i;
        // }else
        // {
        // ii = i;
        // }
        strip.setPixelColor(ledPosition - i, strip.Color(red, green, blue));
    }

    strip.setPixelColor(ledPosition - maxPixels, strip.Color(0, 0, 0));

    ledPosition++;

    if (ledPosition > (maxPixels * 2))
    {
        ledPosition = 0;
    }

    strip.show();

    tempTimer = millis() + 100;
    while (millis() < tempTimer)
    {
    }
}
void MovingSpiralUpMultiColor02()
{
    hTemp += .05; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    // slowly increment 'h' by small increments to make color flow
    int ii = 0;

    for (int i = 0; i < maxPixels; i++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / i) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - i, strip.Color(red, green, blue));
    }

    strip.setPixelColor(ledPosition - maxPixels, strip.Color(0, 0, 0));

    ledPosition++;

    if (ledPosition > (maxPixels * 1.3))
    {
        ledPosition = 0;
    }

    strip.show();

    tempTimer = millis() + 100;
    while (millis() < tempTimer)
    {
    }
}
void MovingSpiralUpDownMultiColor()
{
    hTemp += .05; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    // slowly increment 'h' by small increments to make color flow

    if (currDirection == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            hsv2rgb(float(hTemp), 1, (float(currBrightness / i) / 255.0), red, green, blue);
            strip.setPixelColor(ledPosition - i, strip.Color(red, green, blue));
        }
        strip.setPixelColor(ledPosition - 8, strip.Color(0, 0, 0));
    }
    else
    {
        for (int i = 8; i > 0; i--)
        {
            hsv2rgb(float(hTemp), 1, (float(currBrightness / i) / 255.0), red, green, blue);
            strip.setPixelColor(ledPosition + i, strip.Color(red, green, blue));
        }
        strip.setPixelColor(ledPosition + 8, strip.Color(0, 0, 0));
    }

    if (ledPosition > maxPixels - 8)
    {
        currDirection = 0;
    }

    if (ledPosition < 0)
    {
        currDirection = 1;
    }

    strip.show();
    if (currDirection == 1)
    {
        ledPosition += 1;
    }
    else
    {
        ledPosition -= 1;
    }

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
    }
}
void MovingSpiralUpMultiColor4()
{
    hTemp += .1; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = 1; b < 8; b++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - b, strip.Color(red, green, blue));
    }
    // clear existing pixels
    strip.setPixelColor(ledPosition - 8, strip.Color(0, 0, 0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i++)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition += 1;

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
    }
}
void MovingSpiralUpMultiColor2()
{
    hTemp += .08; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = 1; b < 8; b++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - b, strip.Color(red, green, blue));
    }

    // clear existing pixels
    // strip.setPixelColor(ledPosition - 8, strip.Color(0,0,0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i++)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition += 1;

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
    }
}
void MovingSpiralUpMultiColor3()
{
    hTemp += .05; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = 1; b < 8; b++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition + b, strip.Color(red, green, blue));
    }

    // clear existing pixels
    // strip.setPixelColor(ledPosition - 8, strip.Color(0,0,0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i++)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition += 1;

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
    }
}
void MovingPixel3()
{
    hTemp += .01; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = 1; b < 8; b++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - b, strip.Color(red, green, blue));
    }

    // clear existing pixels
    // strip.setPixelColor(ledPosition - 8, strip.Color(0,0,0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i--)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition += 1;

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
    }
}
void MovingSpiralUpMultiColor1()
{
    hTemp += .007; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = 1; b < 8; b++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - b, strip.Color(red, green, blue));
    }

    // clear existing pixels
    strip.setPixelColor(ledPosition - 8, strip.Color(0, 0, 0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i++)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition += 1;

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
    }
}
void MovingPixel5()
{
    hTemp += .01; // decrease to space out the colors
    if (hTemp > 1)
    {
        hTemp -= 1;
    }
    if (hTemp < 0)
    {
        hTemp += 1;
    }

    for (int b = 1; b < 8; b++)
    {
        hsv2rgb(float(hTemp), 1, (float(currBrightness / b) / 255.0), red, green, blue);
        strip.setPixelColor(ledPosition - b, strip.Color(red, green, blue));
    }

    // clear existing pixels
    strip.setPixelColor(ledPosition - 8, strip.Color(0, 0, 0));

    if (ledPosition > maxPixels)
    {
        ledPosition = 0;
        h = random(1000);
        h = h / 1000;
        // Serial.println(h);
        hsv2rgb(h, 1, (float(currBrightness) / 255.0), red, green, blue);

        for (int i = 0; i < maxPixels; i--)
        {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
    }

    strip.show();
    ledPosition += 1;

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
    }
}

/***********************************************************
  Twinkle Patterns
***********************************************************/
void TwinkleRgb()
{
    hTemp = random(maxPixels);
    h += .001;
    if (h > 1)
    {
        h = 0;
    }
    if (h < 0)
    {
        h = 1;
    }
    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(red, green, blue));

    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }
            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleRgb01()
{
    hTemp = random(maxPixels);
    h += .05;
    if (h > 1)
    {
        h = 0;
    }
    if (h < 0)
    {
        h = 1;
    }
    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(red, green, blue));

    strip.show();

    tempTimer = millis() + 100;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }
            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleRgb02()
{
    hTemp = random(maxPixels);
    h += .006;
    if (h > 1)
    {
        h = 0;
    }
    if (h < 0)
    {
        h = 1;
    }
    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(red, green, blue));

    strip.show();

    tempTimer = millis() + 100;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }
            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleRgb03()
{
    hTemp = random(maxPixels);
    h += .0011;
    if (h > 1)
    {
        h = 0;
    }
    if (h < 0)
    {
        h = 1;
    }
    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(red, green, blue));

    strip.show();

    tempTimer = millis() + 100;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }
            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleRed()
{
    hTemp = random(maxPixels);

    h = 0;

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(currBrightness, 0, 0));

    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleGreen()
{
    hTemp = random(maxPixels);

    h = 0;

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(0, currBrightness, 0));

    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleBlue()
{
    hTemp = random(maxPixels);

    h = 0;

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(0, 0, currBrightness));

    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleWhite()
{
    hTemp = random(maxPixels);

    h = 0;

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(currBrightness, currBrightness, currBrightness));

    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleRainbow()
{
    hTemp = random(maxPixels);

    h = random(1000);
    h = h / 1000;

    hsv2rgb(float(h), 1, (float(currBrightness) / 255.0), red, green, blue);

    strip.setPixelColor(hTemp, strip.Color(red, blue, green));

    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinkleBlueRed()
{
    hTemp = random(maxPixels);

    ledPosition += 1;
    if (ledPosition > 1)
    {
        ledPosition = 0;
    }
    if (ledPosition == 1)
    {
        red = currBrightness;
        blue = 0;
        green = 0;
    }
    else
    {
        red = 0;
        blue = currBrightness;
        green = 0;
    }

    strip.setPixelColor(hTemp, strip.Color(red, green, blue));
    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void TwinklePurple()
{
    hTemp = random(maxPixels);
    strip.setPixelColor(hTemp, strip.Color(currBrightness, 0, currBrightness));
    strip.show();

    tempTimer = millis() + 50;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}

/***********************************************************
  Glowing Patterns
***********************************************************/
void GlowingPink()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        if ((i % 2) == 0)
        {
            strip.setPixelColor(
                i, strip.Color(currBrightness, currBrightness / 3, currBrightness / 2)); // Green
        }
        else
        {
            strip.setPixelColor(i, strip.Color(currBrightness, 0, currBrightness)); // Blue
        }
    }
    strip.show();
}
void GlowingeBlue()
{
    hTemp = random(maxPixels);

    red = 0;
    blue = currBrightness;
    green = 0;

    strip.setPixelColor(hTemp, strip.Color(red, green, blue));
    strip.show();

    tempTimer = millis() + 75;
    while (millis() < tempTimer)
    {
        for (int i = 0; i < maxPixels; i++)
        {
            red = (strip.getPixelColor(i) >> 16 & 0xff);
            green = ((strip.getPixelColor(i) >> 8) & 0xff);
            blue = (strip.getPixelColor(i) & 0xff);

            if (red >= 1)
            {
                red--;
            }
            if (blue >= 1)
            {
                blue--;
            }

            if (green >= 1)
            {
                green--;
            }

            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
}
void GlowingAmber()
{
    hTemp = random(maxPixels);
    strip.setPixelColor(hTemp, strip.Color(currBrightness, currBrightness / 2, 0));
    // strip.show();

    // tempTimer = millis() + 5;
    // while(millis() < tempTimer){
    for (int i = 0; i < maxPixels; i++)
    {
        red = (strip.getPixelColor(i) >> 16 & 0xff);
        green = ((strip.getPixelColor(i) >> 8) & 0xff);
        blue = (strip.getPixelColor(i) & 0xff);

        if (red >= 1)
        {
            red--;
        }
        if (blue >= 1)
        {
            blue--;
        }

        if (green >= 1)
        {
            green--;
        }

        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
    // }
}
void SparkleBlue()
{
    hTemp = random(maxPixels);
    strip.setPixelColor(hTemp, strip.Color(0, 0, currBrightness));
    // strip.show();

    // tempTimer = millis() + 5;
    // while(millis() < tempTimer){
    for (int i = 0; i < maxPixels; i++)
    {
        red = (strip.getPixelColor(i) >> 16 & 0xff);
        green = ((strip.getPixelColor(i) >> 8) & 0xff);
        blue = (strip.getPixelColor(i) & 0xff);

        if (red >= 1)
        {
            red--;
        }
        if (blue >= 1)
        {
            blue--;
        }

        if (green >= 1)
        {
            green--;
        }

        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
    // }
}
void SparkleBlueGreen()
{
    hTemp = random(maxPixels);
    strip.setPixelColor(hTemp, strip.Color(0, currBrightness, currBrightness / 2));
    // strip.show();

    // tempTimer = millis() + 5;
    // while(millis() < tempTimer){
    for (int i = 0; i < maxPixels; i++)
    {
        red = (strip.getPixelColor(i) >> 16 & 0xff);
        green = ((strip.getPixelColor(i) >> 8) & 0xff);
        blue = (strip.getPixelColor(i) & 0xff);

        if (red >= 1)
        {
            red--;
        }
        if (blue >= 1)
        {
            blue--;
        }

        if (green >= 1)
        {
            green--;
        }

        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
    // }
}
void GlowingGreen()
{
    hTemp = random(maxPixels);
    strip.setPixelColor(hTemp, strip.Color(0, currBrightness, 0));

    // tempTimer = millis() + 5;
    // while(millis() < tempTimer){
    for (int i = 0; i < maxPixels; i++)
    {
        red = (strip.getPixelColor(i) >> 16 & 0xff);
        green = ((strip.getPixelColor(i) >> 8) & 0xff);
        blue = (strip.getPixelColor(i) & 0xff);

        if (red >= 1)
        {
            red--;
        }
        if (blue >= 1)
        {
            blue--;
        }

        if (green >= 1)
        {
            green--;
        }

        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
    // }
}
void GlowingBlueGreen()
{
    hTemp = random(maxPixels);
    strip.setPixelColor(hTemp, strip.Color(0, currBrightness, currBrightness / 2));

    // strip.show();

    // tempTimer = millis() + 5;
    // while(millis() < tempTimer){
    for (int i = 0; i < maxPixels; i++)
    {
        red = (strip.getPixelColor(i) >> 16 & 0xff);
        green = ((strip.getPixelColor(i) >> 8) & 0xff);
        blue = (strip.getPixelColor(i) & 0xff);

        if (red >= 1)
        {
            red--;
        }
        if (blue >= 1)
        {
            blue--;
        }

        if (green >= 1)
        {
            green--;
        }

        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
    // }
}
void GlowingPurple()
{
    hTemp = random(maxPixels);
    strip.setPixelColor(hTemp, strip.Color(currBrightness, 0, currBrightness / 2));
    // strip.show();

    // tempTimer = millis() + 5;
    // while(millis() < tempTimer){
    for (int i = 0; i < maxPixels; i++)
    {
        red = (strip.getPixelColor(i) >> 16 & 0xff);
        green = ((strip.getPixelColor(i) >> 8) & 0xff);
        blue = (strip.getPixelColor(i) & 0xff);

        if (red >= 1)
        {
            red--;
        }
        if (blue >= 1)
        {
            blue--;
        }

        if (green >= 1)
        {
            green--;
        }

        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
    // }
}
void GlowingAmberWhite()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        if ((i % 2) == 0)
        {
            strip.setPixelColor(i,
                                strip.Color(currBrightness / 2, currBrightness / 2, currBrightness / 2)); // White
        }
        else
        {
            strip.setPixelColor(i, strip.Color(currBrightness, currBrightness / 3, 0)); // Amber
        }
    }
    strip.show();
}
void GlowingRedBlue()
{
    for (uint16_t i = 0; i < PWM_MaxPixels; i++)
    {
        if ((i % 2) == 0)
        {
            strip.setPixelColor(i, strip.Color(currBrightness, 0, 0)); // Red
        }
        else
        {
            strip.setPixelColor(i, strip.Color(0, 0, currBrightness)); // Blue
        }
    }
    strip.show();
}

/***********************************************************
  Simplex Noise Pattern (Rainbow Cloud Generator)
***********************************************************/
void SimplexNoisePatternInterpolated(float spaceinc, float timeinc, float yoffset, float xoffset)
{

    // Simplex noise for whole strip of LEDs.
    // (Well, it's simplex noise for set number of LEDs and cubic interpolation between those
    // nodes.)

    // Calculate simplex noise for LEDs that are nodes:
    // Store raw values from simplex function (-0.347 to 0.347)
    // float xoffset = 0.0;
    float xoffset_holder = xoffset;

    for (int i = 0; i <= maxPixels / 2; i = i + node_spacing)
    {
        xoffset += spaceinc;
        LED_array_red[i] = SimplexNoise(xoffset, yoffset, 0);
        LED_array_green[i] = SimplexNoise(xoffset, yoffset, 1);
        LED_array_blue[i] = SimplexNoise(xoffset, yoffset, 2);
    }

    xoffset = xoffset_holder;

    // Interpolate values for LEDs between nodes
    for (int i = 0; i < maxPixels / 2; i++)
    {
        int position_between_nodes = i % node_spacing;
        int last_node, next_node;

        // If at node, skip
        if (position_between_nodes == 0)
        {
            // At node for simplex noise, do nothing but update which nodes we are between
            last_node = i;
            next_node = last_node + node_spacing;
        }
        // Else between two nodes, so identify those nodes
        else
        {
            // And interpolate between the values at those nodes for red, green, and blue
            float t = float(position_between_nodes) / float(node_spacing);
            float t_squaredx3 = 3 * t * t;
            float t_cubedx2 = 2 * t * t * t;
            LED_array_red[i] = LED_array_red[last_node] * (t_cubedx2 - t_squaredx3 + 1.0) + LED_array_red[next_node] * (-t_cubedx2 + t_squaredx3);
            LED_array_green[i] = LED_array_green[last_node] * (t_cubedx2 - t_squaredx3 + 1.0) + LED_array_green[next_node] * (-t_cubedx2 + t_squaredx3);
            LED_array_blue[i] = LED_array_blue[last_node] * (t_cubedx2 - t_squaredx3 + 1.0) + LED_array_blue[next_node] * (-t_cubedx2 + t_squaredx3);
        }
    }

    // Convert values from raw noise to scaled r,g,b and feed to strip
    for (int i = 0; i < maxPixels; i = i + 2)
    {
        // TODO: maxPixels is half (50), space out pixels

        int r = currBrightness * ((LED_array_red[i] * 734 + 16) / 255);
        int g = currBrightness * ((LED_array_green[i] * 734 + 16) / 255);
        int b = currBrightness * ((LED_array_blue[i] * 734 + 16) / 255);

        if (r > 255)
        {
            r = 255;
        }
        else if (r < 0)
        {
            r = 0;
        } // Adds no time at all. Conclusion: constrain() sucks.

        if (g > 255)
        {
            g = 255;
        }
        else if (g < 0)
        {
            g = 0;
        }

        if (b > 255)
        {
            b = 255;
        }
        else if (b < 0)
        {
            b = 0;
        }

        // Convert to 24 bit output for WS2801
        strip.setPixelColor(i, strip.Color(r, g, b));
        strip.setPixelColor(i + 1, strip.Color(r, g, b));
    }

    // Update strip
    strip.show();
}
