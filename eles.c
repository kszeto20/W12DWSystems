#include "eles.h"

void eles (DIR * d) {
  d = opendir("somedir");
  struc dirent *entry;
  entry = readdir(d);
  closedir(d);
}
