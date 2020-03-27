function [] = wyklad()
    
to = -1;
    tk = 1; 
    fx = 1000; 
    fs = 2; 
    t = linspace(to, tk, fx);
    xa = 2*sin(2*pi*t*fs);
    fp = 10;
    dt = 1/fp;
    n = to/dt:tk/dt;
    x = 2*sin(2*pi*fs*n*dt);
    
 figure(1)
    subplot(211)
    plot(t,xa)
    title('analogowy')
    xlabel('czas')
    ylabel('analogowy')
    subplot(212)
    stem(n,x)
    xlabel('n');ylabel('dyskretny')
    
    t = linspace(to, tk, fx);
    figure(2)
    clf
    hold on;
    stem(n*dt,x,'r')
    
    for i= 1:length(x)
        xsinc(i,:) = x(i)*sinc(fp*(t-(i+min(n)-1)*dt));
        
    end
    
    title('Signal reconstruction');xlabel('time(second)');ylabel('x(n)*Sinc(Fs*(t-nTs))')
    hold off
    xar = sum(xsinc);

    
    plot(t,xar,'r-')
    legend('Rekonstrukcja','sygna³');ylabel('Rekonstrukcj');xlabel('czas')
end

