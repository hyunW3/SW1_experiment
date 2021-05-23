#include "main.h"
#include <math.h>
int main(){
		
	print_f();
	print_R();
	
	// print normal distribution
    double* seq;
    srand((unsigned int)time(NULL));
    if ( (seq = generate(NMAX)) != NULL )
    {
        printf("mean = %g, stddev = %g\n\n", mean(seq,NMAX), stddev(seq,NMAX));
        printHistogram(seq,NMAX);
        free(seq);
 
        printf("\n%s\n", "press enter");
        getchar();
        return EXIT_SUCCESS;
    }
	
	
	return 0;
}