#include "prf.h"
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define PRF_BUF_LEN 256

struct timespec prf_utime(void) {
  struct timespec time;
  clock_gettime(CLOCK_MONOTONIC, &time);

  return time;
}

double prf_timediff(struct timespec start, struct timespec end) {
  double time_taken = 0;
  time_taken = (double)(end.tv_sec - start.tv_sec) * 1e9;
  time_taken = (time_taken + (double)(end.tv_nsec - start.tv_nsec)) * 1e-9;

  return time_taken;
}

int prf_time(struct prf_config *cfg, const char *tag, int depth) {
  char buf[PRF_BUF_LEN];

  struct timespec start_time = prf_utime();

  while (fgets(buf, PRF_BUF_LEN, cfg->in)) {
    if (strncmp(cfg->start_tag, buf, cfg->start_tag_len) == 0) {
      prf_time(cfg, buf + cfg->start_tag_len, depth + 1);
    } else if (strncmp(cfg->end_tag, buf, cfg->end_tag_len) == 0) {
      break;
    } else if (cfg->echo) {
      fputs(buf, cfg->out);
    }
  }

  fprintf(cfg->out, "%d:%s\tfinished in %.32lf ms\n", depth, tag,
          prf_timediff(start_time, prf_utime()));

  return 0;
}

int prf_main(struct prf_config *cfg) {
  cfg->start_tag_len = strlen(cfg->start_tag);
  cfg->end_tag_len = strlen(cfg->end_tag);
  prf_time(cfg, "main\n", 0);

  return 0;
}
