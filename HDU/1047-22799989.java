import java.util.*;
import java.math.*;
public class Main{
    static Scanner in=new Scanner(System.in);
    public static void main(String args[])
    {
        int T=in.nextInt();
        for(int i=0;i<T;++i)
        {
            if(i!=0)
            {
                System.out.println("");
            }
            BigInteger a=BigInteger.ZERO;
            while (true)
            {
                BigInteger b=in.nextBigInteger();
                if(b.compareTo(BigInteger.ZERO)==0)
                {
                    break;
                }
                else
                {
                    a=a.add(b);
                }
            }
            System.out.println(a);
        }
    }
}