#include "imgproc/xf_filter2d_16b_aie.hpp"
#include "aie_kernel.hpp"

void filter2D(input_window_int16* input, const int16_t (&coeff)[16], output_window_int16* output) {
        xf::cv::aie::filter2D_k3_border(input, coeff, output);
};
