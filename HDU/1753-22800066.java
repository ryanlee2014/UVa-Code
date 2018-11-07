import java.util.*;
import java.math.*;
public class Main{
    static Scanner in=new Scanner(System.in);
    public static void main(String args[])
    {
        BigDecimal a,b;
        while(in.hasNext())
        {
            a=in.nextBigDecimal();
            b=in.nextBigDecimal();
            System.out.println(a.add(b).stripTrailingZeros().toPlainString());
        }
    }
}