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
    RGBTRIPLE copy[height][width];
	float vRed;
	float vGreen;
	float vBlue;
	//create a copy of original image
	for (int row = 0; row < height; row++)
	{
		for (int w = 0; w < width; w++)
		{
			copy[row][w].rgbtRed = image[row][w].rgbtRed;
			copy[row][w].rgbtGreen = image[row][w].rgbtGreen;
			copy[row][w].rgbtBlue = image[row][w].rgbtBlue;
		}
	}
	int h;
	int w;
	for (h = 0; h < height; h++)
	{
		for (w = 0; w < width; w++)
		{
			//if the pixel is on the top left corner
			if (w == 0 && h == 0)
			{
				vRed = (float)(copy[h][w].rgbtRed + copy[h][w+1].rgbtRed + copy[h+1][w].rgbtRed + copy[h+1][w+1].rgbtRed) / 4;
				vGreen = (float)(copy[h][w].rgbtGreen + copy[h][w+1].rgbtGreen + copy[h+1][w].rgbtGreen + copy[h+1][w+1].rgbtGreen) / 4;
				vBlue = (float)(copy[h][w].rgbtBlue + copy[h][w+1].rgbtBlue + copy[h+1][w].rgbtBlue + copy[h+1][w+1].rgbtBlue) / 4;
			}
			//if the pixel is on the lower left corner
			else if (w == 0 && h == (height - 1))
			{
				vRed =(float)(copy[h-1][w].rgbtRed + copy[h-1][w+1].rgbtRed + copy[h][w].rgbtRed + copy[h][w+1].rgbtRed) / 4;
				vGreen = (float)(copy[h-1][w].rgbtGreen + copy[h-1][w+1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w+1].rgbtGreen) / 4;
				vBlue = (float)(copy[h-1][w].rgbtBlue + copy[h-1][w+1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w+1].rgbtBlue) / 4;
			}
			//if the pixel is on top Right corner
			else if (h == 0 && w == (width - 1))
			{
				vRed = (float)(copy[h][w-1].rgbtRed + copy[h][w].rgbtRed + copy[h+1][w-1].rgbtRed + copy[h+1][w].rgbtRed)/ 4;
				vGreen = (float)(copy[h][w-1].rgbtGreen + copy[h][w].rgbtGreen + copy[h+1][w-1].rgbtGreen + copy[h+1][w].rgbtGreen) / 4;
				vBlue = (float)(copy[h][w-1].rgbtBlue + copy[h][w].rgbtBlue + copy[h+1][w-1].rgbtBlue + copy[h+1][w].rgbtBlue) / 4;
			}
			//if the pixel is on lower right corner
			else if(h == (height - 1) && w == (width - 1))
			{
				vRed = (float)(copy[h-1][w-1].rgbtRed + copy[h-1][w].rgbtRed + copy[h][w-1].rgbtRed + copy[h][w].rgbtRed) / 4;
		 		vBlue = (float)(copy[h-1][w-1].rgbtBlue + copy[h-1][w].rgbtBlue + copy[h][w-1].rgbtBlue + copy[h][w].rgbtBlue) / 4;
				vGreen = (float)(copy[h-1][w-1].rgbtGreen + copy[h-1][w].rgbtGreen + copy[h][w-1].rgbtGreen + copy[h][w].rgbtGreen) / 4;
			}
       //if the pixel is on left side
			else if (w == 0 && (h > 0 && h < height - 1))
			{
				vRed = (float)(copy[h-1][w].rgbtRed + copy[h-1][w+1].rgbtRed + copy[h][w].rgbtRed + copy[h][w+1].rgbtRed + copy[h+1][w].rgbtRed + copy[h+1][w+1].rgbtRed) / 6;
				vGreen = (float)(copy[h-1][w].rgbtGreen + copy[h-1][w+1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w+1].rgbtGreen + copy[h+1][w].rgbtGreen + copy[h+1][w+1].rgbtGreen) / 6;
				vBlue = (float)(copy[h-1][w].rgbtBlue + copy[h-1][w+1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w+1].rgbtBlue + copy[h+1][w].rgbtBlue + copy[h+1][w+1].rgbtBlue) / 6;
			}
      //if the pixel is on right side
			else if (w == (width - 1) && (h > 0 && h < height - 1))
			{
				vRed = (float)(copy[h-1][w-1].rgbtRed + copy[h-1][w].rgbtRed + copy[h][w-1].rgbtRed + copy[h][w].rgbtRed + copy[h+1][w-1].rgbtRed + copy[h+1][w].rgbtRed) / 6;
				vGreen = (float)(copy[h-1][w-1].rgbtGreen + copy[h-1][w].rgbtGreen + copy[h][w-1].rgbtGreen + copy[h][w].rgbtGreen + copy[h+1][w-1].rgbtGreen + copy[h+1][w].rgbtGreen) / 6;
				vBlue = (float)(copy[h-1][w-1].rgbtBlue + copy[h-1][w].rgbtBlue + copy[h][w-1].rgbtBlue + copy[h][w].rgbtBlue + copy[h+1][w-1].rgbtBlue + copy[h+1][w].rgbtBlue) / 6;
			}
       //if the pixel is on upper side
			else if (h == 0 && (w > 0 &&  w < width - 1))
			{
				vRed = (float)(copy[h][w-1].rgbtRed + copy[h][w].rgbtRed + copy[h][w+1].rgbtRed + copy[h+1][w-1].rgbtRed + copy[h+1][w].rgbtRed + copy[h+1][w+1].rgbtRed) / 6;
				vGreen = (float)(copy[h][w-1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w+1].rgbtGreen + copy[h+1][w-1].rgbtGreen + copy[h+1][w].rgbtGreen + copy[h+1][w+1].rgbtGreen) / 6;
				vBlue = (float)(copy[h][w-1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w+1].rgbtBlue + copy[h+1][w-1].rgbtBlue + copy[h+1][w].rgbtBlue + copy[h+1][w+1].rgbtBlue) / 6;
			}
       //if the pixel is on lower side
			else if  (h == height - 1 && (w > 0 && w < width - 1))
			{
				vRed = (float)(copy[h-1][w-1].rgbtRed + copy[h-1][w].rgbtRed + copy[h-1][w+1].rgbtRed + copy[h][w-1].rgbtRed + copy[h][w].rgbtRed + copy[h][w+1].rgbtRed) / 6;
				vGreen = (float)(copy[h-1][w-1].rgbtGreen + copy[h-1][w].rgbtGreen + copy[h-1][w+1].rgbtGreen + copy[h][w-1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w+1].rgbtGreen) / 6;
				vBlue = (float)(copy[h-1][w-1].rgbtBlue + copy[h-1][w].rgbtBlue + copy[h-1][w+1].rgbtBlue + copy[h][w-1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w+1].rgbtBlue) / 6;
			}
      //if the pixel is on the middle and can form a 3x3 grid
			else
			{
				vRed = (float)(copy[h-1][w-1].rgbtRed + copy[h-1][w].rgbtRed + copy[h-1][w+1].rgbtRed + copy[h][w-1].rgbtRed + copy[h][w].rgbtRed + copy[h][w+1].rgbtRed + copy[h+1][w-1].rgbtRed + copy[h+1][w].rgbtRed + copy[h+1][w+1].rgbtRed) / 9;
				vGreen = (float)(copy[h-1][w-1].rgbtGreen + copy[h-1][w].rgbtGreen + copy[h-1][w+1].rgbtGreen + copy[h][w-1].rgbtGreen + copy[h][w].rgbtGreen + copy[h][w+1].rgbtGreen + copy[h+1][w-1].rgbtGreen + copy[h+1][w].rgbtGreen + copy[h+1][w+1].rgbtGreen) / 9;
				vBlue = (float)(copy[h-1][w-1].rgbtBlue + copy[h-1][w].rgbtBlue + copy[h-1][w+1].rgbtBlue + copy[h][w-1].rgbtBlue + copy[h][w].rgbtBlue + copy[h][w+1].rgbtBlue + copy[h+1][w-1].rgbtBlue + copy[h+1][w].rgbtBlue + copy[h+1][w+1].rgbtBlue) / 9;
			}
		}
				vRed = round(vRed);
				vGreen = round(vGreen);
				vBlue = round(vBlue);
				image[h][w].rgbtRed = vRed;
				image[h][w].rgbtGreen = vGreen;
				image[h][w].rgbtBlue = vBlue;
	}
    return;
}
