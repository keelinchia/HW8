#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int bytes;
  int fp1, fp2;
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
  
  if ((fp1 = open(pathname1, O_RDONLY)) < 0) {
    printf("Error: Failed to open.\n");
    exit(1);
  }

  printf("Opened file: %s\n\n", pathname1);
  
  fp2 = open(pathname2, O_WRONLY | O_CREAT);

  printf("Opened file: %s\n\n", pathname2);
  
  bytes = read(fp1, &c, 1);
  do {
    if(c >= 97 && c <= 122) {
      c -= 32; 
    }

    write(fp2, &c, 1);

    bytes = read(fp1, &c, 1); 
    
  } while (bytes > 0);

  close(fp1);
  close(fp2);
  
  end = clock();

  time_taken = end - start; 
  
  printf("Time taken: %lf \n", time_taken);
  
  return 0; 
}
