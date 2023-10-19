import py_c_run
import matplotlib.pyplot as plt
import numpy as np
import time
from scipy.io import loadmat

# Load the MATLAB file
data = loadmat('pig41exp2.mat')

# Extract the signal from the MATLAB data
channel_select = 2
signal = data['sigRawSelect'][channel_select-1, :]

data = [1.0, 2.0, 3.0]  # =siganal change with data from import
length = len(data)
result = py_c_run.py_py_c_run(data, length)
print(result)
