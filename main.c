#include <stdio.h>
#include "eles.h"

int main(int argc, char *argv[]) {

    DIR *d;
    struct dirent *directDent;

    if (argc > 1) {
      d = opendir(argv[1]);
      if (errno != 0) {
        printf("There was an error opening the directory: %s", strerror(errno));
      }
    }
    else {
      char *newPath;
      printf("Please give a valid path: \n");

      // grab the file name
      scanf("%ms", &newPath);
      d = opendir(newPath);
      free(newPath);


      if (errno != 0) {
        printf("There was an error opening the directory: %s", strerror(errno));
        return 0;
      }
    }

    long size = 0;

    directDent = readdir(d);

    printf("Statistics for directory: \n");

    // readdir = next
    while (directDent != NULL) {

      struct stat sub;
      stat(directDent->d_name, &sub);

      if (directDent->d_type == DT_DIR) {
          printf("%s \t\tis a directory\n", directDent->d_name);
      }
      else {
          printf("%s\n", directDent->d_name);
      }

      size += sub.st_size;
      directDent = readdir(d);
    }
  printf("Total Directory Size: %lu Bytes\n", size);

  return 0;
}
