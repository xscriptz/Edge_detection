#include <stdio.h>
#include <stdlib.h>
#include <float.h>


#define LIMIT  255 

void sobelgx33()
{

  FILE *fp; 
  int x1, y1; 
  unsigned char myArray[281][500],myArray2[281][500];




fp = fopen("cat.raw", "rb");
  if (NULL == fp) {
    printf("File Not Found!!!!\n");
    exit(1);
  }
  

  int width = 500;
  int height = 281;
  
  for (y1 = 0; y1 < height; y1++) {
    for (x1 = 0; x1 < width; x1++) {
      myArray[y1][x1] = (unsigned char)fgetc(fp);
    }
  }
  
  fclose(fp);


  int weight[3][3] = {{ 1,  0,  -1 },
          { 2,  0,  -2 },
          { 1, 0,  -1 }};
  double store;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;

  for (y = 1; y < height - 1; y++) {
    for (x = 1; x < width - 1; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 1][i + 1] * myArray[y + j][x + i];
      }
    }
      if (store < start) 
        {
          start = store;
        }
      if (store > end) 
        {
          end = store;
        }
    }
  }
  if ((int)(end - start) == 0) {
    printf("File Not Found!!!!\n");
    exit(1);
  }

  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      myArray2[y][x] = 0;
    }
  }

  for (y = 1; y < height - 1; y++) {
    for (x = 1; x < width - 1; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 1][i + 1] * myArray[y + j][x + i];
      }
      }
      store = LIMIT * (store - start) / (end - start);
      myArray2[y][x] = (unsigned char)store;
    }
  }

  FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("sobelimgGx33.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray2[y2][x2], fd);
    }
  }
  fclose(fd);


}
void sobelgy33( )
{

  FILE *fp; 
  int x1, y1; 
  unsigned char myArray[281][500],myArray2[281][500];




fp = fopen("cat.raw", "rb");
  if (NULL == fp) {
    printf("File Not Found!!!!\n");
    exit(1);
  }
  

  int width = 500;
  int height = 281;
  
  for (y1 = 0; y1 < height; y1++) {
    for (x1 = 0; x1 < width; x1++) {
      myArray[y1][x1] = (unsigned char)fgetc(fp);
    }
  }
  
  fclose(fp);


int weight[3][3] = {{ -1,  -2,  -1 },
          { 0,  0,  0},
          { 1,  2,  1 }};

  double store;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;

  for (y = 1; y < height - 1; y++) {
    for (x = 1; x < width - 1; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 1][i + 1] * myArray[y + j][x + i];
      }
    }
      if (store < start) 
        {
          start = store;
        }
      if (store > end) 
        {
          end = store;
        }
    }
  }
  if ((int)(end - start) == 0) {
    printf("File Not Found!!!!\n");
    exit(1);
  }

  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      myArray2[y][x] = 0;
    }
  }

  for (y = 1; y < height - 1; y++) {
    for (x = 1; x < width - 1; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 1][i + 1] * myArray[y + j][x + i];
      }
      }
      store = LIMIT * (store - start) / (end - start);
      myArray2[y][x] = (unsigned char)store;
    }
  }

  FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("sobelimgGy33.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray2[y2][x2], fd);
    }
  }
  fclose(fd);


}

void sobelgx55( )
{

  FILE *fp; 
  int x1, y1; 
  unsigned char myArray[281][500],myArray2[281][500];

fp = fopen("cat.raw", "rb");
  if (NULL == fp) {
    printf("File Not Found!!!!\n");
    exit(1);
  }
  

  int width = 500;
  int height = 281;
  
  for (y1 = 0; y1 < height; y1++) {
    for (x1 = 0; x1 < width; x1++) {
      myArray[y1][x1] = (unsigned char)fgetc(fp);
    }
  }
  
  fclose(fp);

  int weight[5][5] = {{ 2,  2,  4, 2, 2 },{ 1, 1, 2, 1, 1 },
          { 0,  0,  0, 0, 0 },
          { -1,  -1,  -2, -1, -1 },{ -2, -2, -4, -2, -2 }};

  double store;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;

  for (y = 2; y < height - 2; y++) {
    for (x = 2; x < width - 2; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 2][i + 2] * myArray[y + j][x + i];
      }
    }
      if (store < start) 
        {
          start = store;
        }
      if (store > end) 
        {
          end = store;
        }
    }
  }
  if ((int)(end - start) == 0) {
    printf("File Not Found!!!!\n");
    exit(1);
  }

  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      myArray2[y][x] = 0;
    }
  }

  for (y = 2; y < height - 2; y++) {
    for (x = 2; x < width - 2; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 2][i + 2] * myArray[y + j][x + i];
      }
      }
      store = LIMIT * (store - start) / (end - start);
      myArray2[y][x] = (unsigned char)store;
    }
  }

  FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("sobelimgGx55.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray2[y2][x2], fd);
    }
  }
  fclose(fd);


}

void sobelgy55( )
{

  FILE *fp; 
  int x1, y1; 
  unsigned char myArray[281][500],myArray2[281][500];

fp = fopen("cat.raw", "rb");
  if (NULL == fp) {
    printf("File Not Found!!!!\n");
    exit(1);
  }
  

  int width = 500;
  int height = 281;
  
  for (y1 = 0; y1 < height; y1++) {
    for (x1 = 0; x1 < width; x1++) {
      myArray[y1][x1] = (unsigned char)fgetc(fp);
    }
  }
  
  fclose(fp);

  
int weight[5][5] = {{ -2,  -1,  0, 1, 2 },{ -2, -1, 0, 1, 2 },
          { -4,  -2,  0, 2, 4 },
          { -2,  -1,  0, 1, 2 },{ -2, -1, 0, 1, 2 }};
  double store;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;

  for (y = 2; y < height - 2; y++) {
    for (x = 2; x < width - 2; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 2][i + 2] * myArray[y + j][x + i];
      }
    }
      if (store < start) 
        {
          start = store;
        }
      if (store > end) 
        {
          end = store;
        }
    }
  }
  if ((int)(end - start) == 0) {
    printf("File Not Found!!!!\n");
    exit(1);
  }

  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      myArray2[y][x] = 0;
    }
  }

  for (y = 2; y < height - 2; y++) {
    for (x = 2; x < width - 2; x++) {
      store = 0.0;
      for (j = -1; j <= 1; j++) {
      for (i = -1; i <= 1; i++) {
        store += weight[j + 2][i + 2] * myArray[y + j][x + i];
      }
      }
      store = LIMIT * (store - start) / (end - start);
      myArray2[y][x] = (unsigned char)store;
    }
  }

  FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("sobelimgGy55.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray2[y2][x2], fd);
    }
  }
  fclose(fd);


}


void gradient3x3( )
{

  FILE *fp,*fc,*fg; 
  
  double store,d;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;
  int a,b,sum;
  unsigned char myArray[281][500],myArray2[281][500],myArray3[281][500];

fp = fopen("sobelimgGx33.raw", "rb");
  if (NULL == fp) 
  {
    printf("File Not Found!!!!\n");
    exit(1);
  }
fc = fopen("sobelimgGy33.raw", "rb");
  if (NULL == fc) 
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
      myArray2[y1][x1] = (unsigned char)fgetc(fc);
    }
  }
  
  fclose(fp);
  fclose(fc);

  for (int y1 = 0; y1 < height; y1++) 
  {
    for (int x1 = 0; x1 < width; x1++) 
    {

      a = myArray[y1][x1];
      b = myArray2[y1][x1];
      

      sum = abs(a)+abs(b);
      if(sum>255) sum=255;
      if(sum<0) sum=0;
      myArray3[y1][x1] =  255 - (unsigned char)sum;
    }
  }

FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("Gradient3x3.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray3[y2][x2], fd);
    }
  }
  fclose(fd);



}


void gradient5x5( )
{

  FILE *fp,*fc,*fg; 
  
  double store,d;
  double start = DBL_MAX, end = -DBL_MAX;
  int x, y, i, j;
  int a,b,sum;
  unsigned char myArray[281][500],myArray2[281][500],myArray3[281][500];

fp = fopen("sobelimgGx55.raw", "rb");
  if (NULL == fp) 
  {
    printf("File Not Found!!!!\n");
    exit(1);
  }
fc = fopen("sobelimgGy55.raw", "rb");
  if (NULL == fc) 
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
      myArray2[y1][x1] = (unsigned char)fgetc(fc);
    }
  }
  
  fclose(fp);
  fclose(fc);

  for (int y1 = 0; y1 < height; y1++) 
  {
    for (int x1 = 0; x1 < width; x1++) 
    {

      a = myArray[y1][x1];
      b = myArray2[y1][x1];
      

      sum = abs(a)+abs(b);
      if(sum>255) sum=255;
      if(sum<0) sum=0;
      myArray3[y1][x1] =  255 - (unsigned char)sum;
    }
  }

FILE *fd; 
  int x2, y2; 
  
  
  fd = fopen("Gradient5x5.raw", "wb");
  
  for (y2 = 0; y2 < height; y2++) {
    for (x2 = 0; x2 < width; x2++) {
      fputc(myArray3[y2][x2], fd);
    }
  }
  fclose(fd);



}

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
        myArray2[y1][x1] = 255;
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
        myArray2[y1][x1] = 255;
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
  sobelgx33();
  sobelgy33();
  gradient3x3();

  sobelgx55();
  sobelgy55();
  gradient5x5();

}




