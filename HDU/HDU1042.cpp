import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        BigInteger a;
        int target;
        Scanner in = new Scanner(System.in);
        while(in.hasNext())
        {
            target=in.nextInt();
            a=BigInteger.ONE;
            for(int i=1;i<=target;++i)
            {
                a=a.multiply(BigInteger.valueOf((long)i));
            }
            System.out.println(a);
        }
    }
}

