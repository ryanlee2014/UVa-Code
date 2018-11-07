import java.util.*;
import java.math.*;
public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger[] b=new BigInteger[1010];
        b[1]=BigInteger.ZERO;
        b[2]=BigInteger.ONE;
        for(int i=3;i<=1001;++i)
        {
            b[i]=b[i-1].add(b[i-2].add(b[i-2]));
        }
        int n;
        while(in.hasNext())
        {
            n=in.nextInt();
            System.out.println(b[n]);
        }
    }
}
