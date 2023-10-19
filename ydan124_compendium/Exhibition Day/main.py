import matplotlib.pyplot as plt
import numpy as np
import time
from scipy.io import loadmat

# Load the MATLAB file
data = loadmat('pig41exp2.mat')

# Extract the signal from the MATLAB data
channel_select = 2
signal = data['sigRawSelect'][channel_select-1, :]

# Create an iterator for the signal
signal_iterator = iter(signal)

def get_next_data_point():
    # Get the next data point from the signal, if available
    return next(signal_iterator, 0)  # Default to 0 if no more data

# Number of data points to display
num_samples = 500
data_buffer = np.zeros(num_samples)

# Create the initial plot
plt.ion()  # Turn on interactive mode
fig, ax = plt.subplots()
ecg_line, = ax.plot(data_buffer)
activation_line, = ax.plot([], [], 'ro')  # Empty plot for activation points

# Set plot properties
ax.set_ylim(min(signal) - 1, max(signal) + 1)  # Adjust the y-axis limits based on your data

# Update the plot in a loop
while True:
    new_data_point = get_next_data_point()

    # Append the new data point to the buffer and remove the oldest
    data_buffer = np.append(data_buffer[1:], new_data_point)

    # Generate random activation points (for example) change it with acual activation data for presentation
    activation_points = np.random.choice(np.arange(num_samples), size=5)

    # Update the ECG plot data
    ecg_line.set_ydata(data_buffer)

    # Update the activation points plot data
    activation_line.set_xdata(activation_points)
    activation_line.set_ydata(data_buffer[activation_points])

    # Redraw the plot
    plt.pause(0.01)

    # Optionally, add a delay to control the display rate
    time.sleep(0.01)

# When you're done, close the plot
plt.ioff()
plt.show()
