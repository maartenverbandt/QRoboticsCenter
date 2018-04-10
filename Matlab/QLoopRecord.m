classdef QLoopRecord < QRecord
    %QLOOPRECORD Summary of this class goes here
    %   Detailed explanation goes here
        
    methods
        function self = QLoopRecord(filename)
            self@QRecord(filename);
            DOM = xmlread(filename);
        end
        
        function FRF = getFRF(self,mode)
            if nargin < 2
                mode = 'freq';
            end
            
            % compute some settings
            t = self.getData('time');
            switch mode
                case 'freq'
                    % multi frf
                    nrofsamp = self.excitation.period*self.excitation.fs;
                    nrofperi = floor(length(t)/nrofsamp);
                case 'time'
                    % mean time
                    nrofsamp = self.excitation.period*self.excitation.fs;
                    nrofperi = 1;
                case 'noise'
                    nrofsamp = self.excitation.period*self.excitation.fs*2;
                    nrofperi = 1;
            end

            % get data
            [measurements,commands,actuation,controls] = getLoopData(self);

			% compute frfs
			% Response matrix is: [T,H;U,I]
			response = zeros(2,2,round(nrofsamp/2)-1,nrofperi,3);
            window = ones(nrofsamp,1);
			for j = 1:3			
				for k = 1:nrofperi
                    range = (k-1)*nrofsamp + (1:nrofsamp);
                    in = [commands(range,j).*window,actuation(range,j).*window];
                    out = [measurements(range,j).*window,actuation(range,j).*window];
					[~,~,freq,~,~,~,response(1,1,:,k,j),~] = time2frf(in(:,1),out(:,1),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
                    [~,~,freq,~,~,~,response(1,2,:,k,j),~] = time2frf(in(:,2),out(:,1),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
                    [~,~,freq,~,~,~,response(2,1,:,k,j),~] = time2frf(in(:,1),out(:,2),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
                    [~,~,freq,~,~,~,response(2,2,:,k,j),~] = time2frf(in(:,2),out(:,2),self.excitation.fs,1,nrofsamp/2-1,nrofsamp);
				end
			end

			% Put everything in frd object
			FRF = frd(response,freq,'FrequencyUnit','Hz');
        end
        
        function plant = getPlant(self,direction,mode)
            k = getDirectionIndex(self,direction);
            FRF = self.getFRF(mode);
            plant = FRF(1,2,:,k);
        end
        
        function showPlant(self,direction)
            [frfm] = getPlant(self,direction,'time');
            [frfs] = getPlant(self,direction,'freq');
            
            %options:
            opts = bodeoptions('cstprefs');
            opts.PhaseWrapping = 'on';
            opts.PhaseMatching = 'on';
            opts.PhaseMatchingFreq = 1;
            
            figure, bode(frfs,'b:',frfm,'k',opts);
            h = findobj(gcf,'type','line');
            set(h,'linewidth',2);
        end
        
        function error = getError(self)
            [measurements,commands,~,~] = getLoopData(self);
            error = commands - measurements;
        end
        
        function disturbance = getDisturbance(self)
            [~,~,actuation,controls] = getLoopData(self);
            disturbance = actuation - controls;
        end
        
        function self = extend(self)
            [measurements,commands,actuation,controls] = getLoopData(self);
            error = commands - measurements;
            errorlabels = cellfun(@(x) [x '_error'], self.labels(2:4), 'un', 0);
            disturbance = actuation - controls;
            disturbancelabels = cellfun(@(x) [x '_disturbance'], self.labels(11:13), 'un', 0);
            
            self.data = [self.data, error, disturbance];
            self.labels = [self.labels, errorlabels, disturbancelabels];
        end
    end
    
    methods (Abstract)
        getLoopData(self)
        getDirectionIndex(self,direction);
    end
    
end

