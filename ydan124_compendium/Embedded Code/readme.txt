
#To deploy the program to the DE1-SoC and copy it to the microSD card:

requirements:
1 Have c11 and python 3.10 (with cython for running wrapper ) in windows
2 Linux(yocto) wit c compiler imaged on a SD card( refer to Doc my fist HPs and getting stated)
3 GNU plot latest version on windows
4 At least 4 GB sd card ( 8 to 64 Gb recommandable)
5

On Windows:
1.) Connect the DE1-SoC to your computer using a USB cable.
2.) Mount the microSD card on your computer. Refer to hardware doc Linux my first Hps to load sd card with linux imager.
3.) Copy the executable file (my_first_hps) to the microSD card.
4.) Unmount the microSD card from your computer.
5.) Power on the DE1-SoC.

#On Linux:
1.) Connect the DE1-SoC to your Linux computer using a USB cable.
2.) Mount the microSD card on your Linux computer. 

# Detection Algorithm Model

This folder encapsulates the embedded model that has been developed for the duration of the project. It is composed of many files, 
with the key main.c is called file**, which calls on many other functions to model funcitonality of the detection 
algorithm.

## List of files
* NEO_transform.c- a mathematical function that operates on a signal - used for magnitude change detection
* artifact_detect.c - function to detect pacing artifacts
* artifact_remove.c - function to remove the detected artifacts (matlab coder help was taken  to implement this)
* main.c - combined detection algorithm functionality encapsulated within a function - provided input parameters (used mainly in the application) 
* exp_10_output.mat - low-resolution experimental data
* exp_16_output.mat - low-resolution experimental data
* fir_51.mat - high-pass filter coefficients
* extract_data_script.m - function to import relevant files to a text file to get data
* moving_average_1s_window.c - moving average filter function
* pig37exp2.mat - high-resolution experimental data
* pig41exp2.mat - high-resolution experimental data
*ppval.c - polynomial evaluation function 
* visualise_signal.m - function to plot signals from output data written to text file by main.c 
*ppval.c contains piece wise polynomial evaluation file

## Running the model
Desoc1 with Linux is required.

##Visualisation
This folder contain a visualisation function 'visualise_signal.m' as c code write data to text file which could be copied and visualised in Matlab using it



#### To test "Low-Resolution" signals:
* changing between exp16 mat and exp10.mat::: use extract data  file to get text file with new data
* channel selection (1 to 256) - ::::use the extract data file  to get text file with different channel

#### To test "High-Resolution" signals:
* changing between pig41 and pig37 - //import file to get text file with new data
* channel selection(1to 40) //change in import.m matlab file to get text file with different channel


#### functionality changes
* artifact detection threshold change variable 'threshold'
* change variable baseline calculation (baseline =sum/buffer*59) change between 59 or 5.9 check result doc and final report 



#### Exhibition Visualisation
main.c contains visualisation using gnuplot
 
#### python
If want to build on top of this code in python for machilene learing wrappers are given adjust them as required.
wrapper function '.pyx' nad'.pxd' file is given to run this c to python python.c and python.h are file showing change in file function name to be called from '.pyx') file .
use pip or other toool to install cython.use command cythonize -i py_c_run.pyx to compile
more about it :-http://docs.cython.org/en/latest/


