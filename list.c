#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
// Please use the man pages of opendir etc to find out more #include's you need.

int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "not enough arguments\n");
    return 1;
  }
  // we will write here
  DIR *d = opendir(argv[1]);
  if (d == NULL) return 1;
  struct dirent *helper;
  while ((helper = readdir(d)) != NULL ){
    if (helper->d_type == DT_REG){
      printf("%s regular\n",helper->d_name);
    }
    else if (helper->d_type == DT_DIR){
      printf("%s directory\n", helper->d_name);
    }
    else if (helper->d_type == DT_LNK){
      printf("%s symlink\n", helper->d_name);
    }
    else{
      printf("%s other\n", helper->d_name);
    }
  }
  closedir(d);
  return 0;
}
