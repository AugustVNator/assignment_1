
#include <errno.h>
#include <unistd.h>

#include "io.h"

#include <string.h>

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
  char buf[1];
  size_t nbytes = sizeof(buf);
  ssize_t bytes_read = read(STDIN_FILENO, buf, nbytes);

  //Think this is wrong, it should return EOF without throwing an error?
  if (bytes_read > 0) {
    return buf[0];
  }
  return EOF;
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
  size_t nbytes = sizeof(c);
  ssize_t bytes_write = write(STDOUT_FILENO, &c , nbytes);

  if (bytes_write) {
    return 0;
  }
  return EOF;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
  size_t nbytes = strlen(s);

  ssize_t bytes_write = write(STDOUT_FILENO, s, nbytes);

  if (bytes_write) {
    return 0;
  }
  return EOF;
}

/* Writes n to stdout (without any formatting).
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
  char convertedInt = n + '0';
  char* pCI = &convertedInt;
  size_t nbytes = sizeof(convertedInt);
  ssize_t bytes_write = write(STDOUT_FILENO,  pCI, nbytes);

  if (bytes_write) {
    return 0;
  }
  return EOF;
}
