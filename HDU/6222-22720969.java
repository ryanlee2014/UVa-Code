import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        BigInteger res[]=new BigInteger[100];
        res[0]=BigInteger.valueOf(4L);
        res[1]=BigInteger.valueOf(14L);
        for(int i=2;i<100;++i)
        {
            res[i]=res[i-1].multiply(new BigInteger("4")).subtract(res[i-2]);
        }
        int T=in.nextInt();
        while(T-->0)
        {
            BigInteger n=in.nextBigInteger();
            int i;
            for(i=0;i<100;++i)
            {
                if(n.compareTo(res[i])!=1)break;
            }
            System.out.println(res[i]);
        }
    }
}