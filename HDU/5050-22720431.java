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
        int kase=0;
        while(T-->0)
        {
            BigInteger a=in.nextBigInteger(2);
            BigInteger b=in.nextBigInteger(2);
            a=a.gcd(b);
            System.out.println("Case #"+String.valueOf(++kase)+": "+a.toString(2));
        }
    }
}