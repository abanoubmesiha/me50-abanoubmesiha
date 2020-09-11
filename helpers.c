#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h=0; h<height; h++)
    {
        for (int w=0; w<width; w++)
        {
            float sum = image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue;
            int average = round(sum/3);
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtRed = average;
        }
    }
    return;
}
int betweenLimits(int value)
{
    int result;
    if (value < 0){
        result = 0;
    }
    else if (value > 255)
    {
        result =  255;
    }
    else
    {
        result = value;
    }
    return result;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h=0; h<height; h++)
    {
        for (int w=0; w<width; w++)
        {
            int Red = image[h][w].rgbtRed;
            int Green = image[h][w].rgbtGreen;
            int Blue = image[h][w].rgbtBlue;

            float sepiaRed = 0.393 * Red + 0.769 * Green + 0.189 * Blue;
            float sepiaGreen = 0.349 * Red + 0.686 * Green + 0.168 * Blue;
            float sepiaBlue = 0.272 * Red + 0.534 * Green + 0.131 * Blue;

            Red = betweenLimits(round(sepiaRed));
            Green = betweenLimits(round(sepiaGreen));
            Blue = betweenLimits(round(sepiaBlue));

            image[h][w].rgbtRed = Red;
            image[h][w].rgbtGreen = Green;
            image[h][w].rgbtBlue = Blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h=0; h<height; h++)
    {
        for (int w=0; w<width; w++)
        {
            int firstRed = image[h][w].rgbtRed;
            int firstGreen = image[h][w].rgbtGreen;
            int firstBlue = image[h][w].rgbtBlue;

            int secondRed = image[h][width-1 -w].rgbtRed;
            int secondGreen = image[h][width-1 -w].rgbtGreen;
            int secondBlue = image[h][width-1 -w].rgbtBlue;

            image[h][w].rgbtRed = secondRed;
            image[h][w].rgbtGreen = secondGreen;
            image[h][w].rgbtBlue = secondBlue;

            image[h][width-1 -w].rgbtRed = firstRed;
            image[h][width-1 -w].rgbtGreen = firstGreen;
            image[h][width-1 -w].rgbtBlue = firstBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
