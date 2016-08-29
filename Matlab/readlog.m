function [data] = readlog(log)
%READLOG Summary of this function goes here
%   Detailed explanation goes here

fid = fopen(log,'r');
if (fid < 0) 
    printf('Error:could not open file\n')
else
    % Read first line: type
    data.type = fgetl(fid);
    % Read second line: creation time
    scan = textscan(fgetl(fid),'%s','delimiter',', ');
    data.date = scan{1}{1};
    data.time = scan{1}{3};
    % Read third line: version number
    version = sscanf(fgetl(fid),'%f');
    data.version = floor(version);
    data.subversion = round((version-data.version)*10);
    % Read 4th line: empty
    fgetl(fid);
    
    switch data.type
        case 'QGPIORecord'
            data = readgpio(fid,data);
    end
end
end

function data = readgpio(fid,data)
%READGPIO Reads the gpio log file.
switch(data.version*10+data.subversion)
    case 10
        data = readgpio_v1_0(fid,data);
end
end

function data = readgpio_v1_0(fid,data)
%READGPIO_V1_0 Reads version 1.0 gpio file
%   input: file descriptor of non-general header
%   input: data structure
    % read labels
    scan = textscan(fgetl(fid),'%s','delimiter','\t');
    data.labels = scan{1};
    % read data
    format = [repmat('%f\t',1,9),repmat('%d\t',1,3),'%d'];
    size = [13 Inf];
    data.data = transpose(fscanf(fid,format,size));
end