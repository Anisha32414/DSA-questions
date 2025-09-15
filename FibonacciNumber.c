int fib(int n){
        int first=0,second=1,sum=0;
        if(n==0)
        return first;
        if(n==1)
        return second;
        for(int i=2;i<=n;i++)
        {
            sum=first+second;
            first=second;
            second=sum;
        }
        return sum;
}
