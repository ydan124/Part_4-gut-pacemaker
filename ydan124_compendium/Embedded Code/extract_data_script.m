% Load data from 'exp_10_output.mat'  change file name to ex 16 for other
% data
load('exp_10_output.mat');
channel_select = 28;
% Assuming data is stored in a structure, extract the matrix
% (Note: Modify this if the structure field name is different and change channela s you wifsh )
signal = data_struct(1:end,channel_select);

% Downsample the signal
signal = downsample(signal,16); % Downsample to 32Hz

% Transpose the signal
signal = signal.';

% Visualize the downsampled signal (if needed)
sampling_f = 32;
%visualise_signal(signal,sampling_f,"Downsampled Data At 32Hz");

% Export data to a text file
fileID = fopen('bad_signal_data.txt','w');
fprintf(fileID, '{');
fprintf(fileID, '%f, ', signal(1:end-1));
fprintf(fileID, '%f', signal(end));
fprintf(fileID, '}');
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % Load data from 'pig41exp2.mat'  cahnge name to pig 37 to get other data
% load('pig41exp2.mat');
% channel_select = 2;
% % Extract the specific channel
% signal = sigRawSelect(channel_select,1:end);	
% 
% % You might want to downsample or process the signal
% 
% 
% % Export data to a text file
% fileID = fopen('good_signal_data.txt','w');
% fprintf(fileID, '{');
% fprintf(fileID, '%f, ', signal(1:end-1));
% fprintf(fileID, '%f', signal(end));
% fprintf(fileID, '}');
% fclose(fileID);
