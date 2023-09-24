#ifndef prfH__
#define prfH__

#include <stddef.h>
#include <stdio.h>

#define PRF_START_TAG "prfmon-start"
#define PRF_END_TAG "prfmon-end"

struct prf_config {
  _Bool verbose;
  _Bool echo;

  FILE *in;
  FILE *out;

  const char *start_tag;
  size_t start_tag_len;
  const char *end_tag;
  size_t end_tag_len;
};

int prf_main(struct prf_config *cfg);

#endif 
