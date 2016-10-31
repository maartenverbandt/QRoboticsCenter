classdef QPositionRecord < QRecord
    %QPOSITIONRECORD Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        excitation
        FRF
    end
    
    methods
        function self = QPositionRecord(filename)
            self@QRecord(filename);
            DOM = xmlread(filename);            
            
            % Get the excitation
            item_time = DOM.getElementsByTagName('excitation').item(0);
            type = str2double(char(item_time.getElementsByTagName('type').item(0).getFirstChild.getData()));
            fmin = str2double(char(item_time.getElementsByTagName('fmin').item(0).getFirstChild.getData()));
            fmax = str2double(char(item_time.getElementsByTagName('fmax').item(0).getFirstChild.getData()));
            fs = str2double(char(item_time.getElementsByTagName('fs').item(0).getFirstChild.getData()));
            period = str2double(char(item_time.getElementsByTagName('period').item(0).getFirstChild.getData()));
            self.excitation = struct('type',type,'fmin',fmin,'fmax',fmax,'fs',fs,'period',period);
        
            % Compute the frf
            self = computeFRF(self);
        end
        
        function self = computeFRF(self)
			% compute some settings
            t = self.getData('time');
			nrofsamp = self.excitation.period*self.excitation.fs;
			nrofperi = floor(length(t)/nrofsamp);

			% get data
			measurements = self.getData({'x','y','z'});
			commands = self.getData({'xcmd','ycmd','zcmd'});
			controls = self.getData({'xact','yact','zact'});
            
			% compute frfs
			% Response matrix is: [T,H;U,I]
			response = zeros(2,2,round(nrofsamp/2)-1,nrofperi,3);
			for j = 1:3			
				for k = 1:nrofperi
                    range = (k-1)*nrofsamp + (1:nrofsamp);
					in = [commands(range,j),controls(range,j)];
					out = [measurements(range,j),controls(range,j)];
					[~,~,freq,~,~,~,response(1,1,:,k,j),~] = time2frf(in(:,1),out(:,1),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
                    [~,~,freq,~,~,~,response(1,2,:,k,j),~] = time2frf(in(:,2),out(:,1),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
                    [~,~,freq,~,~,~,response(2,1,:,k,j),~] = time2frf(in(:,1),out(:,2),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
                    [~,~,freq,~,~,~,response(2,2,:,k,j),~] = time2frf(in(:,2),out(:,2),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
				end
			end

			% Put everything in frd object
			self.FRF = frd(response,freq,'FrequencyUnit','Hz');
        end
        
        function FRF = getFRF(self)
            FRF = self.FRF;
        end
        
        function [FRFm,FRFs] = getPlant(self,direction)
            switch direction
                case 'x'
                    k = 1;
                case 'y'
                    k = 2;
                case 'z'
                    k = 3;
            end
            FRFs = self.FRF(1,2,:,k);
            respm = mean(squeeze(FRFs.response),2);
            FRFm = frd(respm,FRFs.frequency,'FrequencyUnit',FRFs.FrequencyUnit);
        end
        
        function showPlant(self,direction)
            [frfm,frfs] = getPlant(self,direction);
            figure, 
            bode(frfs,'b:'), hold on, 
            bode(frfm,'k'), hold off
            h = findobj(gcf,'type','line');
            set(h,'linewidth',2);
        end
    end
end

