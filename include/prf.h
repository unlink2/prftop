#ifndef prfH__
#define prfH__

struct prf_config {
  _Bool verbose;
};

int prf_main(struct prf_config *cfg);

#endif 
