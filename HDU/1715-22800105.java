import java.util.*;
import java.math.*;
public class Main{
    static Scanner in=new Scanner(System.in);
    public static void main(String args[])
    {
        BigInteger[] fib=new BigInteger[1010];
        fib[1]=fib[2]=BigInteger.ONE;
        for(int i=3;i<=1000;++i)
        {
            fib[i]=fib[i-1].add(fib[i-2]);
        }
        int T=in.nextInt();
        for(int kase=0;kase<T;++kase)
        {
            int pos=in.nextInt();
            System.out.println(fib[pos]);
        }
    }
}