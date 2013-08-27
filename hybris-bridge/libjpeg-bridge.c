

#include <stddef.h>
#include <stdio.h>

#include <dlfcn.h>

#include <jinclude.h>
#include <jpeglib.h>

#include <hybris/internal/binding.h>


HYBRIS_LIBRARY_INITIALIZE(libjpeg, "libjpeg2.so")

HYBRIS_IMPLEMENT_VOID_FUNCTION3(libjpeg, jpeg_CreateCompress, j_compress_ptr, int, size_t);
HYBRIS_IMPLEMENT_VOID_FUNCTION3(libjpeg, jpeg_CreateDecompress, j_decompress_ptr, int, size_t);
HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_destroy_compress, j_compress_ptr);
HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_destroy_decompress, j_decompress_ptr);

HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_simple_progression, j_compress_ptr);
HYBRIS_IMPLEMENT_VOID_FUNCTION2(libjpeg, jpeg_set_colorspace, j_compress_ptr, J_COLOR_SPACE);


HYBRIS_IMPLEMENT_FUNCTION1(libjpeg, struct jpeg_error_mgr *, jpeg_std_error, struct jpeg_error_mgr *);

HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_set_defaults, j_compress_ptr);
HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_default_colorspace, j_compress_ptr);
HYBRIS_IMPLEMENT_VOID_FUNCTION2(libjpeg, jpeg_stdio_dest, j_compress_ptr, FILE*);
HYBRIS_IMPLEMENT_VOID_FUNCTION2(libjpeg, jpeg_start_compress, j_compress_ptr, boolean);
HYBRIS_IMPLEMENT_FUNCTION3(libjpeg, JDIMENSION, jpeg_write_scanlines, j_compress_ptr, JSAMPARRAY, JDIMENSION);
HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_finish_compress, j_compress_ptr);
HYBRIS_IMPLEMENT_FUNCTION1(libjpeg, boolean, jpeg_finish_decompress, j_decompress_ptr);

// no HYBRIS_IMPLEMENT_VOID_FUNCTION5
void jpeg_add_quant_table(j_compress_ptr param1, int param2, const unsigned int * param3, int param4, boolean param5)
{
  static void (*f)(j_compress_ptr, int, const unsigned int *, int, boolean) = NULL;
  HYBRIS_DLSYSM(libjpeg, &f, "jpeg_add_quant_table");
  f(param1, param2, param3, param4, param5);
}


HYBRIS_IMPLEMENT_FUNCTION1(libjpeg, int, jpeg_quality_scaling, int);
HYBRIS_IMPLEMENT_VOID_FUNCTION2(libjpeg, jpeg_default_qtables, j_compress_ptr, boolean);

HYBRIS_IMPLEMENT_VOID_FUNCTION3(libjpeg, jpeg_set_marker_processor, j_decompress_ptr, int, jpeg_marker_parser_method);
HYBRIS_IMPLEMENT_VOID_FUNCTION2(libjpeg, jpeg_stdio_src, j_decompress_ptr, FILE*);
HYBRIS_IMPLEMENT_FUNCTION2(libjpeg, int, jpeg_read_header, j_decompress_ptr, boolean);
HYBRIS_IMPLEMENT_FUNCTION1(libjpeg, boolean, jpeg_start_decompress, j_decompress_ptr);
HYBRIS_IMPLEMENT_FUNCTION3(libjpeg, JDIMENSION, jpeg_read_scanlines, j_decompress_ptr, JSAMPARRAY, JDIMENSION);
HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_calc_output_dimensions, j_decompress_ptr);

HYBRIS_IMPLEMENT_FUNCTION1(libjpeg, jvirt_barray_ptr*, jpeg_read_coefficients, j_decompress_ptr);
HYBRIS_IMPLEMENT_VOID_FUNCTION2(libjpeg, jpeg_copy_critical_parameters, j_decompress_ptr, j_compress_ptr);
HYBRIS_IMPLEMENT_VOID_FUNCTION2(libjpeg, jpeg_write_coefficients, j_compress_ptr, jvirt_barray_ptr *);
HYBRIS_IMPLEMENT_VOID_FUNCTION1(libjpeg, jpeg_core_output_dimensions, j_decompress_ptr);
HYBRIS_IMPLEMENT_VOID_FUNCTION3(libjpeg, jpeg_save_markers, j_decompress_ptr, int, unsigned int);
HYBRIS_IMPLEMENT_VOID_FUNCTION4(libjpeg, jpeg_write_marker, j_compress_ptr, int, const JOCTET *, unsigned int);

HYBRIS_IMPLEMENT_VOID_FUNCTION3(libjpeg, jcopy_block_row, JBLOCKROW, JBLOCKROW, JDIMENSION);
HYBRIS_IMPLEMENT_FUNCTION2(libjpeg, long, jdiv_round_up, long, long);
