#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h=0; h<height; h++)
    {
        for (int w=0; w<width/2; w++) // (width/2) To make sure you swap only once.
        {
            int firstRed = image[h][w].rgbtRed;
            int firstGreen = image[h][w].rgbtGreen;
            int firstBlue = image[h][w].rgbtBlue;

            int lastRed = image[h][width-1 -w].rgbtRed;
            int lastGreen = image[h][width-1 -w].rgbtGreen;
            int lastBlue = image[h][width-1 -w].rgbtBlue;

            swap(&firstRed, &lastRed);
            swap(&firstGreen, &lastGreen);
            swap(&firstBlue, &lastBlue);

            image[h][w].rgbtRed = firstRed;
            image[h][w].rgbtGreen = firstGreen;
            image[h][w].rgbtBlue = firstBlue;

            image[h][width-1 -w].rgbtRed = lastRed;
            image[h][width-1 -w].rgbtGreen = lastGreen;
            image[h][width-1 -w].rgbtBlue = lastBlue;
        }
    }
    return;
}

// Blur image
struct pixel
{
    int red;
    int green;
    int blue;
};
void blurPixel(int h, int w, int height, int width, struct pixel img[height][width], struct pixel structName)
{
    // int squares = 9;
    // struct pixel blured;
    // calc red
    // float total = img[h-1][w-1].red + img[h-1][w].red + img[h-1][w+1].red + img[h][w-1].red + img[h][w + 1].red + img[h+1][w-1].red + img[h+1][w].red + img[h-1][w+1].red;
    // blured.red = round(total/squares);
    structName.red = 1;
    structName.green = 2;
    structName.blue = 3;
    return;
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy the orinial image.
    struct pixel img[height][width];
    for (int h=0; h<height; h++)
    {
        for (int w=0; w<width; w++)
        {
            img[h][w].red = image[h][w].rgbtRed;
            img[h][w].green = image[h][w].rgbtGreen;
            img[h][w].blue = image[h][w].rgbtBlue;
        }
    }
    // blur the original image.
    for (int h=0; h<height-1; h++)
    {
        for (int w=0; w<width-1; w++)
        {
            // printf("Before: %i - ", image[h][w].rgbtRed);
            image[h][w].rgbtRed = (img[h-1][w-1].red + img[h-1][w].red + img[h-1][w+1].red + img[h][w-1].red + img[h][w].red + img[h][w+1].red + img[h+1][w-1].red + img[h+1][w].red+ img[h+1][w+1].red) / 9;
            image[h][w].rgbtGreen = (img[h-1][w-1].green + img[h-1][w].green + img[h-1][w+1].green + img[h][w-1].green + img[h][w].green + img[h][w+1].green + img[h+1][w-1].green + img[h+1][w].green + img[h+1][w+1].green) / 9;
            image[h][w].rgbtBlue = (img[h-1][w-1].blue + img[h-1][w].blue + img[h-1][w+1].blue + img[h][w-1].blue + img[h][w].blue + img[h][w+1].blue + img[h+1][w-1].blue + img[h+1][w].blue + img[h+1][w+1].blue) / 9;
            // printf("After: %i\n", image[h][w].rgbtRed);
        }
    }
    return;
}
