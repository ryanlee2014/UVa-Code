import java.util.*;
import java.math.*;
public class Main{
    static Scanner in=new Scanner(System.in);
    public static void main(String args[])
    {
        BigInteger[] fib=new BigInteger[1030];
        fib[1]=fib[2]=BigInteger.ONE;
        fib[2]=fib[2].add(fib[2]);
        for(int i=3;i<=1010;++i)
        {
            fib[i]=fib[i-1].add(fib[i-2]);
        }
        BigInteger a,b;
        while(in.hasNext())
        {
            a=in.nextBigInteger();
            b=in.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO)==0&&b.compareTo(BigInteger.ZERO)==0)
            {
                break;
            }
            int cnt=0;
            for(int i=1;i<=1010;++i)
            {
                if(fib[i].compareTo(a)<0)
                {
                    continue;
                }
                else if(fib[i].compareTo(b)>0)
                {
                    break;
                }
                else
                    ++cnt;
            }
            System.out.println(cnt);
        }
    }
}