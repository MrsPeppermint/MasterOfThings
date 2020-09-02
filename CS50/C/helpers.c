#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / (float)3); //pixels can only be int
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate new red value
            float newRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            //calculate new green value
            float newGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            //calculate new blue value
            float newBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            if (newRed > 255)       //fix the overflow
            {
                newRed = 255;
            }
            if (newGreen > 255)
            {
                newGreen = 255;
            }
            if (newBlue > 255)
            {
                newBlue = 255;
            }
            image[i][j].rgbtRed = round(newRed); //round to int, there's no floats in pixels
            image[i][j].rgbtGreen = round(newGreen);
            image[i][j].rgbtBlue = round(newBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, half = width / 2; j < half; j++)
        {
            RGBTRIPLE temp = image[i][j];                   //bubble sort
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE oldImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            oldImage[i][j] = image[i][j]; //make a copy to always compare original color values
        }
    }
    //go through array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float newRed = 0.0;
            float newGreen = 0.0;
            float newBlue = 0.0;
            //go aroud each pixel
            for (int k = - 1 ; k < 2; k++)
            {
                for (int l = - 1; l < 2; l++)
                {
                    //check for edges; MIND: 0 -> [height(or width) - 1
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        newRed += oldImage[i + k][j + l].rgbtRed;
                        newGreen += oldImage[i + k][j + l].rgbtGreen;
                        newBlue += oldImage[i + k][j + l].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(newRed / count);
            image[i][j].rgbtGreen = round(newGreen / count);
            image[i][j].rgbtBlue = round(newBlue / count);
        }
    }
    return;
}


