#include "prf.h"
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define PRF_BUF_LEN 256

long prf_utime(void) {
  struct timeval time;
  gettimeofday(&time, NULL);
  long s1 = (long)(time.tv_sec) * 1000;
  long s2 = (time.tv_usec / 1000);
  return s1 + s2;
}

int prf_time(struct prf_config *cfg, const char *tag, int depth) {
  char buf[PRF_BUF_LEN];

  long start_time = prf_utime();

  while (fgets(buf, PRF_BUF_LEN, cfg->in)) {
    if (strncmp(cfg->start_tag, buf, cfg->start_tag_len) == 0) {
      prf_time(cfg, buf + cfg->start_tag_len, depth + 1);
    } else if (strncmp(cfg->end_tag, buf, cfg->end_tag_len) == 0) {
      break;
    } else if (cfg->echo) {
      fputs(buf, cfg->out);
    }
  }
  fprintf(cfg->out, "%d:%s\tfinished in %ld ms\n", depth, tag,
          prf_utime() - start_time);

  return 0;
}

int prf_main(struct prf_config *cfg) {
  cfg->start_tag_len = strlen(cfg->start_tag);
  cfg->end_tag_len = strlen(cfg->end_tag);
  prf_time(cfg, "main\n", 0);

  return 0;
}
