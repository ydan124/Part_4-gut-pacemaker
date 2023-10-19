# Import numpy for array interactions
import numpy as np
cimport numpy as np
# cython: language_level=3
# Declare the C function
cdef extern from "py_c_run.h":
    void py_c_run(double* data, int length)

# Create a Python function that calls the C function
def call_py_c_run(np.ndarray[np.float64_t, ndim=1] data):
    cdef int length = data.shape[0]
    py_c_run(&data[0], length)
    return data


