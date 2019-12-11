
function bitn(nn)
 bitnn=BitArray(undef, 64)
    i=1
    n=Int64(nn)
    for i in 1:64
        u=(n%2)
        if(u==1)
            bitnn[i]=1
        end
        n=div(n,2)
    end
    return bitnn
end

function MxM(m1,m2,mod)
    res=zeros(Int64,2,2)
        res[1]=(((m1[1]*m2[1])%mod)+((m1[2]*m2[3])%mod)%mod)
        res[2]=(((m1[1]*m2[2])%mod)+((m1[2]*m2[4])%mod)%mod)
        res[3]=(((m1[3]*m2[1])%mod)+((m1[4]*m2[3])%mod)%mod)
        res[4]=(((m1[3]*m2[2])%mod)+((m1[4]*m2[4])%mod)%mod)
    return res
end


function mpow(powof2,mod)
    m=zeros(Int64,2,2)
    buf=zeros(Int64,2,2)
    buf=[[1,1];[1,0]]
    for h in 0:powof2
        m[1]=((buf[1]*buf[1]+buf[2]*buf[3])%mod)
        m[2]=((buf[1]*buf[2]+buf[2]*buf[4])%mod)
        m[3]=((buf[3]*buf[1]+buf[4]*buf[3])%mod)
        m[4]=((buf[3]*buf[2]+buf[4]*buf[4])%mod)
        buf=m
        m=zeros(Int64,2,2)
    end
   # print("         ",buf)
    return buf
end
   


function Fib(pos,mod)
    pow=zeros(Int64,2,2)
    pow=[[1,0];[0,1]]
    nbit=bitn(pos)
    #print(nbit)
    for i in 1:length(nbit)
       # print(nbit[i])
        if(nbit[i])
        #print("Evt.       ",i)
            pow=MxM(pow,mpow(i-2,mod),mod)
        end
    end
    print(pow[4])
end
for i in 1:16
    Fib(i,5)
    print("  ")
end

print(5%3)


