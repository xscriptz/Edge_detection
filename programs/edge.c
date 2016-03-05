#include <stdio.h>
#include <stdlib.h>
#include <float.h>


void edge3x3( )
{

  FILE *fp,*fc,*fg; 
  
  double store,d;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;
  int a,b,sum;
  unsigned char myArray[281][500],myArray2[281][500];

fp = fopen("Gradient3x3.raw", "rb");
  if (NULL == fp) 
  {
    printf("File Not Found!!!!\n");
    exit(1);
  }


  int width = 500;
  int height = 281;
  
  for (int y1 = 0; y1 < height; y1++) 
  {
    for (int x1 = 0; x1 < width; x1++) 
    {
      myArray[y1][x1] = (unsigned char)fgetc(fp);
    }
  }
  
  fclose(fp);
  fclose(fc);

  for (int y1 = 0; y1 < height; y1++) 
  {
    for (int x1 = 0; x1 < width; x1++) 
    {

      a = myArray[y1][x1];

      if(a > 30)
      {
        myArray2[y1][x1] = 150;
      }
      else
      {
        myArray2[y1][x1] = 0;
      }
      

    }
  }

FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("edgeimg3x3.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray2[y2][x2], fd);
    }
  }
  fclose(fd);



}

void edge5x5( )
{

  FILE *fp,*fc,*fg; 
  
  double store,d;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;
  int a,b,sum;
  unsigned char myArray[281][500],myArray2[281][500];

  fp = fopen("Gradient5x5.raw", "rb");
  if (NULL == fp) 
  {
    printf("File Not Found!!!!\n");
    exit(1);
  }


  int width = 500;
  int height = 281;
  
  for (int y1 = 0; y1 < height; y1++) 
  {
    for (int x1 = 0; x1 < width; x1++) 
    {
      myArray[y1][x1] = (unsigned char)fgetc(fp);
    }
  }
  
  fclose(fp);
  fclose(fc);

  for (int y1 = 0; y1 < height; y1++) 
  {
    for (int x1 = 0; x1 < width; x1++) 
    {

      a = myArray[y1][x1];

      if(a > 30)
      {
        myArray2[y1][x1] = 150;
      }
      else
      {
        myArray2[y1][x1] = 0;
      }
      

    }
  }

FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("edgeimg5x5.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray2[y2][x2], fd);
    }
  }
  fclose(fd);



}

int main()
{
  edge3x3();
  edge5x5();
  return 0;
}