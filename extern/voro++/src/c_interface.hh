typedef void container;
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    container* container_new(double ax_,double bx_,double ay_,double by_,double az_,double bz_,
                        int nx_,int ny_,int nz_,int xperiodic_,int yperiodic_,int zperiodic_,int init_mem);

    void container_put(container* container, int n, double x, double y, double z);
    void container_print_custom(container* container, const char* format, FILE* fp);

#ifdef __cplusplus
}
#endif

