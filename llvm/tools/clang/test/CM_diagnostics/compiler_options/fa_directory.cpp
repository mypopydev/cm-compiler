// We check that the Finalizer is run using FileCheck, and that the expected
// files are generated by deleting them (leaving things tidy)
// Only the basename of the /Fa value is used - if only a directory (i.e. a
// value ending in a path separator) is given it is ignored and the default
// name is used.
// RUN: %cmc -Qxcm_jit_target=cnl -Fa=Output/ %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

#include <cm/cm.h>

_GENX_MAIN_
void test() {
}

#ifdef CM_GENX
#warning CM_GENX defined
#endif

#ifdef CM_GEN7_5
#warning CM_GEN7_5 defined
#endif

#ifdef CM_GEN8
#warning CM_GEN8 defined
#endif

#ifdef CM_GEN8_5
#warning CM_GEN8_5 defined
#endif

#ifdef CM_GEN9
#warning CM_GEN9 defined
#endif

#ifdef CM_GEN9_5
#warning CM_GEN9_5 defined
#endif

#ifdef CM_GEN10
#warning CM_GEN10 defined
#endif

// CHECK: fa_directory.cpp(16,2) :  warning: CM_GENX defined [-W#warnings]
// CHECK: fa_directory.cpp(40,2) :  warning: CM_GEN10 defined [-W#warnings]
// CHECK: 2 warnings generated.
// CHECK: -platform CNL