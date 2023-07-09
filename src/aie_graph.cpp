include <adf.h>
#include "aie_kernel.hpp"

class myGraph : public adf::graph {
private:
    kernel k1;
public:
    port<input> inptr;
    port<output> outptr;
    port<input> kernelCoefficients;

    myGraph() {
        k1 = kernel::create(filter2D);
        adf::connect<window<TILE_WINDOW_SIZE> >(inptr, k1.in[0]);
        adf::connect<parameter>(kernelCoefficients, async(k1.in[1]));
        adf::connect<window<TILE_WINDOW_SIZE> >(k1.out[0], outptr);
        source(k1) = "xf_filter2d.cc";
        // Initial mapping
        runtime<ratio>(k1) = 0.5;
    }
};
