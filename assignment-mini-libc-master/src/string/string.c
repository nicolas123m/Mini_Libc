// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char * strcpy(char * destination,
  const char * source) {
  /* TODO: Implement strcpy(). */
  if (destination == NULL) {
    return NULL;
  }
  char * aux = destination;
  while (*source != '\0') {
    * destination = * source;
    destination++;
    source++;
  }
  * destination = '\0';
  return aux;
}

char * strncpy(char * destination,
  const char * source, size_t len) {
  /* TODO: Implement strncpy(). */
  if (destination == NULL) {
    return NULL;
  }
  size_t lenght = 0;
  char * aux = destination;
  while ( *source != '\0' && lenght <= len ){
    * destination = * source;
    destination++;
    source++;
    lenght++;
  }
  * destination = '\0';
  return aux;
}

char * strcat(char * destination,
  const char * source) {
  /* TODO: Implement strcat(). */
  //strcat-https://www.techiedelight.com/implement-strcat-function-c/
  char * aux = destination + strlen(destination);
  while ( *source != '\0' ) {
    * aux++ = * source++;
  }
  * aux = '\0';
  return destination;
}

char * strncat(char * destination,
  const char * source, size_t len) {
  /* TODO: Implement strncat(). */
  char * aux = destination + strlen(destination);
  while ( *source != '\0' && len > 0 ) {
    * aux++ = * source++;
    len--;
  }
  * aux = '\0';
  return destination;
}
int strcmp(const char * str1, const char * str2) {
  /* TODO: Implement strcmp(). */
  while ( *(str1 + 1) != '\0' && * (str2 + 1) != '\0' ) {
    if (* str1 == * str2) {
      str1++;
      str2++;
    }
    if (* str1 > * str2) {
      return 1;
    }
    if (* str1 < * str2) {
      return -1;
    }
  }
  if (*(str1 + 1) != '\0') {
    if (* str1 == * str2) {
      return 1;
    }
    if (* str1 > * str2) {
      return 1;
    }
    if (*str1 < * str2) {
      return -1;
    }
  }
  if (*(str2 + 1) != '\0') {
    if (*str1 == * str2) {
      return -1;
    }
    if (*str1 > * str2) {
      return 1;
    }
    if (*str1 < * str2) {
      return -1;
    }
  }
  return 0;
}
int strncmp(const char * str1,
  const char * str2, size_t len) {
  /* TODO: Implement strncmp(). */
  size_t k = -1;
  while (*(str1 + 1) != '\0' && * (str2 + 1) != '\0' && len >= k) {
    if (*str1 == * str2) {
      str1++;
      str2++;
      len--;
    }
    if (*str1 > * str2) {
      return 1;
    }
    if (*str1 < * str2) {
      return -1;
    }
  }
  str1++;
  str2++;
  if (*str1 > * str2) {
    return 1;
  }
  if (*str1 < * str2) {
    return -1;
  }
  return 0;
}
size_t strlen(const char * str) {
  size_t i = 0;

  for (;* str != '\0'; str++, i++)
  ;

  return i;
}

char * strchr(const char * str, int c) {
  /* TODO: Implement strchr(). */
  while (*str != (char) c && * str != '\0') {
    str++;
  }
  if (*str == (char) c) {
    return str;
  } else {
    return NULL;
  }
}

char * strrchr(const char * str, int c) {
  /* TODO: Implement strrchr(). */
  //strchr-https://www.harishnote.com/2016/06/c-programming-78-strchr-implementation.html
  const char * k = str + strlen(str);
  while ( k != str ) {
    if ( * k == c ) {
      return k;
    }
    k--;
  }
  if ( k == str && * k == c ) {
    return k;
  }
  return NULL;
}

char * strstr(const char * haystack,
  const char * needle) {
  /* TODO: Implement strstr(). */
  //http://www.firmcodes.com/write-c-code-to-implement-the-strstr-function-to-search-for-a-substring/
  while ( * haystack ) {
    char * begin = haystack;
    char * pattern = needle;
    while ( *haystack && * pattern && * haystack == * pattern ) {
      pattern++;
      haystack++;
    }
    if ( !*pattern ) {
      return begin;
    }
    haystack = begin + 1;
  }
  return NULL;
}

char * strrstr(const char * haystack,
  const char * needle) {
  /* TODO: Implement strrstr(). */
  size_t h_len = strlen(haystack);
  size_t n_len = strlen(needle);

  if (n_len == 0) {
    return (char * )(haystack + h_len);
  }

  for (const char * haystack_ptr = haystack + h_len - 1; haystack_ptr >= haystack; haystack_ptr--) {
    if ( * haystack_ptr == needle[n_len - 1] ) {
      const char * h = haystack_ptr;
      const char * n = needle + n_len - 1;
      while (h >= haystack && n >= needle && * h == * n) {
        h--;
        n--;
      }
      if (n < needle) {
        return (char * )(h + 1);
      }
    }
  }

  return NULL; // Needle not found.
}

void * memcpy(void * destination,
  const void * source, size_t num) {
  /* TODO: Implement memcpy(). */
  char * dest = (char *) destination;
  char * src = (char *) source;
  for (size_t i = 0; i < num; i++) {
    dest[i] = src[i];
  }
  return dest;
}

void * memmove(void * destination,
  const void * source, size_t num) {
  /* TODO: Implement memmove(). */
  char * dest = (char *) destination;
  char * src = (char *) source;

  if (dest == src) {
    return destination;
  }
  if (src < dest && (src + num) > dest) {
    dest += num;
    src += num;
    while (num != 0) {
      dest--;
      src--;
      * dest = * src;
      num--;
    }
  } else {
    while (num != 0) {
      * dest = * src;
      dest++;
      src++;
      num--;
    }
  }

  return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  /* TODO: Implement memcmp(). */
  char * p = (char *) ptr1;
  char * q = (char *) ptr2;
  for (size_t i = 0; i < num; i++) {
    if ( *p > *q ) {
      return 1;
    }
    if ( * p < * q ) {
      return -1;
    }
    p++;
    q++;
  }
  return 0;
}

void * memset(void * source, int value, size_t num) {
  /* TODO: Implement memset(). */
  char * k = (char *) source;
  for (size_t i = 0; i < num; i++) {
    *(k) = (char) value;
    k++;
  }
  return k;
}
