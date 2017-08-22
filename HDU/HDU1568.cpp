import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        BigInteger[] arr=new BigInteger[500];
        arr[0]=BigInteger.ZERO;
        arr[1]=BigInteger.ONE;
        for (int i=2;i<500;++i)
        {
            arr[i]=arr[i-1].add(arr[i-2]);
        }
        int a;
        Scanner in=new Scanner(System.in);
        while(in.hasNext())
        {
            a=in.nextInt();
            if(a<500) {
                if (arr[a].toString().length() < 4)
                    System.out.println(arr[a]);
                else
                    System.out.println(arr[a].toString().substring(0, 4));
            }
            else
            {
                double b=(1.0+Math.sqrt(5.0))/2.0;
                double ans=-0.5*Math.log10(5.0)+a*Math.log10(b);
                ans =ans-Math.floor(ans);
                ans=Math.pow(10,ans);
                int answer=(int)(ans*1000);
                System.out.println(answer);
            }
        }
    }
}
