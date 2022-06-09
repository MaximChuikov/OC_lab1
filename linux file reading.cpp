#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void checkOwner(struct stat buf) {
  printf("\nowner ");
  //разрешение на чтение
  if (buf.st_mode & S_IRUSR)
    printf("read ");
  //бит на запись
  if (buf.st_mode & S_IWUSR)
    printf("write ");
  //выполнение
  if (buf.st_mode & S_IXUSR)
    printf("use ");
}
void checkGroup(struct stat buf) {
  printf("\ngroup ");
  if (buf.st_mode & S_IRGRP)
    printf("read ");
  if (buf.st_mode & S_IWGRP)
    printf("write ");
  if (buf.st_mode & S_IXGRP)
    printf("use ");
}
void checkOther(struct stat buf) {
  printf("\nother ");
  if (buf.st_mode & S_IROTH)
    printf("read ");
  if (buf.st_mode & S_IWOTH)
    printf("write ");
  if (buf.st_mode & S_IXOTH)
    printf("use ");
}
void checkFile(struct stat buf) {
  printf("\nFile ");
  //extract file type (buf.st_mode & S_IFMT)
  //S_IFREG This is the file type constant of a regular file.
  if ((buf.st_mode & S_IFMT) == S_IFREG)
    printf("default file");
  //Directory type
  else if ((buf.st_mode & S_IFMT) == S_IFDIR)
    printf("direcrory");
  //Symbol oriented file
  else if ((buf.st_mode & S_IFMT) == S_IFCHR)
    printf("sign device");
  //File type constant of a FIFO or pipe.
  else if ((buf.st_mode & S_IFMT) == S_IFIFO)
    printf("\nFIFO");
}
int main(int argc, char *argv[]) {
  struct stat buf;
  if (argc != 2) {
    fprintf(stderr, "Использование: %s <путь>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if (stat(argv[1], &buf) == -1) {
    perror("stat");
    exit(EXIT_FAILURE);
  }
  checkFile(buf);
  checkOwner(buf);
  checkGroup(buf);
  checkOther(buf);
  return 0;
}