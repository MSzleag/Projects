function [] = probk()
    %variables
    tstart = -1;
    tstop = 1; 
    fx = 1000; %amount of samples
    fs = 2; %signal freq
    %Analog signal
    t = linspace(tstart, tstop, fx);
    xa = 2*sin(2*pi*t*fs);
    %digital sampling signal
    fp = 10;
    dt = 1/fp;
    n = tstart/dt:tstop/dt;
    x = 2*sin(2*pi*fs*n*dt);
    figure(1)
    plot(t,xa)
    title('Syganl analogowy')
    xlabel('czas')
    ylabel('Sygnal analogowy x(t)')
    %stem(n,x)
    xlabel('n');ylabel('dyskretne probki')
    t = linspace(tstart, tstop, fx);
    figure(2)
    clf
    hold on;
    stem(n*dt,x,'r')
    
    for i= 1:length(x)
        xsinc(i,:) = x(i)*sinc(fp*(t-(i+min(n)-1)*dt));
    end
    
    title('Sygnal rekonstruowany');xlabel('czas(sekundy)');ylabel('x(n)*Sinc(Fs*(t-nTs))')
    hold off
    xar = sum(xsinc);

    plot(t,xar,'b-')
    legend('Sygnal rekonstruowany','Orgianlny sygnal signal');ylabel('Syganl rekonstruowany xa(t)');xlabel('czas (sekundy)')
end

