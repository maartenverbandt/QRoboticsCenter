classdef QVelocityRecord < QLoopRecord
    %QVELOCITYRECORD Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function self = QVelocityRecord(filename)
            self@QLoopRecord(filename);
            
            % Rescale velocities
            self.data(:,2:3) = (1e-3)*self.data(:,2:3);
            self.data(:,5:6) = (1e-3)*self.data(:,5:6);
            
            % Rescale the angles: *1e-4
            self.data(:,8:13) = (1e-4)*self.data(:,8:13);
            self = extend(self);
        end
        
        function [measurements,commands,actuation,controls] = getLoopData(self)
            % get data
            measurements = self.getData({'vx','vy','vz'});
            commands = self.getData({'vxcmd','vycmd','vzcmd'});
            actuation = self.getData({'vxact','vyact','vzact'});
            controls = self.getData({'vxcont','vycont','vzcont'});
        end
        
        function index = getDirectionIndex(self,direction)
            switch direction
                case 'vx'
                    index = 1;
                case 'vy'
                    index = 2;
                case 'vz'
                    index = 3;
            end
        end
    end
end

