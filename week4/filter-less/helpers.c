#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE tmp = (BYTE)round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = tmp;
            image[i][j].rgbtGreen = tmp;
            image[i][j].rgbtBlue = tmp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float tmp1, tmp2, tmp3;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp1 = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            tmp1 = tmp1 >= 0 ? tmp1 : 0;
            tmp1 = tmp1 < 256 ? tmp1 : 255;

            tmp2 = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            tmp2 = tmp2 >= 0 ? tmp2 : 0;
            tmp2 = tmp2 < 256 ? tmp2 : 255;

            tmp3 = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            tmp3 = tmp3 >= 0 ? tmp3 : 0;
            tmp3 = tmp3 < 256 ? tmp3 : 255;

            image[i][j].rgbtRed = (BYTE)tmp1;
            image[i][j].rgbtGreen = (BYTE)tmp2;
            image[i][j].rgbtBlue = (BYTE)tmp3;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (tmp == NULL)
    {
        return;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j].rgbtRed = image[i][j].rgbtRed;
            tmp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tmp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][width - j - 1].rgbtBlue;
        }
    }
    free(tmp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (tmp == NULL)
    {
        return;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j].rgbtRed = image[i][j].rgbtRed;
            tmp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tmp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    int r, g, b;
    float extra, count;
    int t1, t2, t3, t4;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            t1 = i - 1 >= 0 ? i - 1 : 0;
            t2 = i + 1 < height ? i + 1 : height - 1;
            t3 = j - 1 >= 0 ? j - 1 : 0;
            t4 = j + 1 < width ? j + 1 : width - 1;
            r = 0, g = 0, b = 0, count = 0.0;
            // if (i < 3 && j < 3){
            //     printf("t1:%d; t2:%d; t3:%d; t4:%d\n", t1, t2, t3, t4);
            // }

            for (int m = t1; m <= t2; m++)
            {
                for (int n = t3; n <= t4; n++)
                {
                    count++;
                    //printf("pixel red:%d\n", image[m][n].rgbtRed);
                    r += tmp[m][n].rgbtRed;
                    g += tmp[m][n].rgbtGreen;
                    b += tmp[m][n].rgbtBlue;
                    // if (i ==0 && j ==0){
                    //     printf("red:%d\n", tmp[m][n].rgbtRed);
                    //     printf("r:%d\n", r);
                    // }
                }
            }
            // printf("count:%d\n", count);
            // printf("red:%d\n", r);
            extra = round(r / count);
            extra = extra >= 0 ? extra : 0;
            extra = extra < 256 ? extra : 255;
            image[i][j].rgbtRed = (BYTE)extra;
            // if (i < 2 && j < 2){
            //     printf("final extra:%f\n", extra);
            //     printf("final red:%d\n", image[i][j].rgbtRed);
            // }

            extra = round(g / count);
            extra = extra >= 0 ? extra : 0;
            extra = extra < 256 ? extra : 255;
            image[i][j].rgbtGreen = (BYTE)extra;

            extra = round(b / count);
            extra = extra >= 0 ? extra : 0;
            extra = extra < 256 ? extra : 255;
            image[i][j].rgbtBlue = (BYTE)extra;
            // printf("red:%d\n", image[i][j].rgbtRed);
            // break;
        }
        //break;
    }
    free(tmp);
    return;
}
