classdef QPositionRecord < QLoopRecord
    %QPOSITIONRECORD Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        excitation
        FRF
    end
    
    methods
        function self = QPositionRecord(filename)
            self@QLoopRecord(filename);
        end
        
        function [measurements,commands,actuation,controls] = getLoopData(self)
            % get data
            measurements = self.getData({'x','y','z'});
            commands = self.getData({'xcmd','ycmd','zcmd'});
            actuation = self.getData({'xact','yact','zact'});
            controls = self.getData({'xcont','ycont','zcont'});
        end
        
        function index = getDirectionIndex(self,direction)
            switch direction
                case 'x'
                    index = 1;
                case 'y'
                    index = 2;
                case 'z'
                    index = 3;
            end
        end
    end
end

