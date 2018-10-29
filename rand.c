#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

//A function that generates a random number by reading in the correct number of bytes from /dev/random.
int rd_byte()
{
  int f = open("/dev/random", O_RDONLY);
  int n;
  read(f, &n, sizeof(n));
  close(f);
  return n;
}

int main()
{
  int arr1[10];
  int arr2[10];
  int i;
  int val;
  int f;
  printf("---Populate an array w/ random numbers---\n");
  for (i = 0; i < 10; i++) {
    printf("arr1[%d]: %d\n", i, val = rd_byte());
    arr1[i] = val;
  }

  printf("---Writes the array to a file---\n");
  f = open("arrFile", O_CREAT | O_WRONLY, 0644);
  write(f, arr1, sizeof(arr1));
  close(f);

  printf("---Reads that file into a different array---\n");
  f = open("arrFile", O_RDONLY);
  read(f, arr2, sizeof(arr1));
  close(f);

  printf("---Verify the random numbers are the same from step 1---\n");
  for (i = 0; i < 10; i++) {
    printf("arr2[%d]: %d\n", i, arr2[i]);
  }

  return 0;
}
