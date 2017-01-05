classdef QVelocityRecord < QLoopRecord
    %QVELOCITYRECORD Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        function self = QVelocityRecord(filename)
            self@QLoopRecord(filename);
            
            % Rescale the angles: *1e-4
            self.data(:,8:10) = (1e-4)*self.data(:,8:10);
        end
        
        function [measurements,commands,controls] = getLoopData(self)
			% get data
			measurements = self.getData({'vx','vy','vz'});
			commands = self.getData({'vxcmd','vycmd','vzcmd'});
			controls = self.getData({'vxact','vyact','vzact'});
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

