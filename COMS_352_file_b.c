#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int bytes;
  FILE *fp1, *fp2;
  char pathname1[50], pathname2[50];
  char c;
  double start, end, time_taken;

  printf("Enter file1 pathname: ");
  fscanf(stdin, "%s", pathname1);
  printf("\n");

  printf("Enter file2 pathname: ");
  fscanf(stdin, "%s", pathname2);
  printf("\n");

  start = clock();

  if ((fp1 = fopen(pathname1, "r")) == NULL) {
    printf("Error: Failed to open.\n");
    exit(1);
  }

  printf("Opened file: %s\n\n", pathname1);

  fp2 = fopen(pathname2, "w");

  printf("Opened file: %s\n\n", pathname2);

  bytes = fread(&c, 1, 1, fp1);
  do {
    if(c >= 97 && c <= 122) {
      c -= 32;
    }

    fwrite(&c, 1, 1, fp2);
    bytes = fread(&c, 1, 1, fp1);
 
  } while (bytes != 0);

  fclose(fp1);
  fclose(fp2);

  end = clock();

  time_taken = end - start;

  printf("Time taken: %lf \n", time_taken);

  return 0;
}
