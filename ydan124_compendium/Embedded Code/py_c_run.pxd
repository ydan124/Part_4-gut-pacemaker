cdef extern from "py_c_run.h":
    double* py_c_run(double* data, int length)
