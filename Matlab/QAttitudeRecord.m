classdef QAttitudeRecord < QLoopRecord
    %QATTITUDERECORD Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function self = QAttitudeRecord(filename)
            self@QLoopRecord(filename);
            
            % Rescale the angles: *1e-4
            self.data(:,2:7) = (1e-4)*self.data(:,2:7);
            self = extend(self);
        end
        
        function [measurements,commands,actuation,controls] = getLoopData(self)
            % get data
            measurements = self.getData({'roll','pitch','yaw'});
            commands = self.getData({'rollcmd','pitchcmd','yawcmd'});
            actuation = self.getData({'rollact','pitchact','yawact'});
            controls = self.getData({'rollcont','pitchcont','yawcont'});
        end
        
        function index = getDirectionIndex(self,direction)
            switch direction
                case 'roll'
                    index = 1;
                case 'pitch'
                    index = 2;
                case 'yaw'
                    index = 3;
            end
        end
    end
end

