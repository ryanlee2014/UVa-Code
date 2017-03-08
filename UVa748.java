import java.io.*;
import java.util.*;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigDecimal a;
        int b;
        while(in.hasNext())
        {
            a=in.nextBigDecimal();
            b=in.nextInt();
            a=a.pow(b).stripTrailingZeros();
            String ans=a.toPlainString();
            int i;
            for(i=0;;i++)
            {
                if(ans.charAt(i)!='0')
                    break;
            }
            System.out.println(ans.substring(i));
        }
    }
}