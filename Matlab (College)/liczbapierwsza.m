function[a]=liczbapierwsza(x)
s=0;
for i=2:x;
    if (mod(x,i)==0);
        s=s+1;
    end
end
    if (s==1);
        disp('l.pierwsza');
    elseif (s==0);
        disp('ani to, ani to');
    else
        disp('l.z�o�ona')
    end
end