#include "prf.h"
#include <stdio.h>
#include <string.h>

#define PRF_BUF_LEN 256

int prf_time(struct prf_config *cfg, const char *tag) {
  char buf[PRF_BUF_LEN];

  int start_time = 0;
  int end_time = 0;

  while (fgets(buf, PRF_BUF_LEN, cfg->in)) {
    if (strncmp(cfg->start_tag, buf, cfg->start_tag_len) == 0) {
    }

    if (cfg->echo) {
      fputs(buf, cfg->out);
    }
  }

  return 0;
}

int prf_main(struct prf_config *cfg) {
  cfg->start_tag_len = strlen(cfg->start_tag);
  cfg->end_tag_len = strlen(cfg->end_tag);
  return 0;
}
