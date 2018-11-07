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
        int T=in.nextInt();
        while(T-->0)
        {
            BigInteger a,b,c,d;
            a=in.nextBigInteger();
            b=in.nextBigInteger();
            c=in.nextBigInteger();
            d=in.nextBigInteger();
            System.out.println(a.add(b).add(c).add(d));
        }
    }
}