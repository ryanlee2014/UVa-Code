import java.util.*;
import java.math.*;
public class Main{
    static Scanner in=new Scanner(System.in);
    public static void main(String args[])
    {
        BigDecimal a;
        int b;
        while(in.hasNext())
        {
            a=in.nextBigDecimal();
            b=in.nextInt();
            String ans=a.pow(b).stripTrailingZeros().toPlainString();
            if(ans.charAt(0)=='0')ans=ans.substring(1);
            System.out.println(ans);
        }
    }
}