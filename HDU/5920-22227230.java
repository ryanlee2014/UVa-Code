import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int n = readin();
        String temp = readstr();
        for (int cas = 1; cas <= n; cas++) {
            String ans[] = new String[60];
            String s = readstr();
            System.out.println("Case #" + cas + ":");
            int cnt = 0;
            while (!Objects.equals(s, "0")) {
                int k = s.length();
                String s1 = s.substring(0, k / 2);
                StringBuffer s2 = new StringBuffer(s1);
                s2.reverse();
                StringBuffer s3 = new StringBuffer(s1);
                if (k % 2 != 0) {
                    s3 = s3.append(s.substring(k / 2, k / 2 + 1));
                }
                s3 = s3.append(s2);
                BigInteger a = new BigInteger(s3.toString());
                BigInteger b = new BigInteger(s);
                if (b.compareTo(a) == 0 || b.compareTo(a) > 0) {
                    ans[cnt] = a.toString();
                    cnt++;
                    s = b.subtract(a).toString();
                }
                if (b.compareTo(a) < 0) {
                    int l = k / 2 - 1;
                    char c = s3.charAt(l);
                    while (c == '0') {
                        l--;
                        c = s3.charAt(l);
                    }
                    String s4 = "";
                    if (l != 0) {
                        s4 = s3.toString().substring(0, l);
                        s3 = new StringBuffer(s4);
                        s2 = new StringBuffer(s4);
                        s3.append((char) (c - 1));
                        s2.append((char) (c - 1));
                        if (k % 2 != 0) {
                            s2.append("9");
                        }
                        s3.reverse();
                        s2 = s2.append(s3);
                        ans[cnt] = s2.toString();
                        cnt++;
                        a = new BigInteger(s2.toString());
                        b = new BigInteger(s);
                        s = b.subtract(a).toString();
                    } else {
                        s3 = new StringBuffer(s4);
                        if ((char) (c - 1) != '0') {
                            s3.append((char) (c - 1));
                        }
                        for (int i = 0; i < k - 2; i++)
                            s3.append("9");
                        if ((char) (c - 1) == '0')
                            s3.append("9");
                        else
                            s3.append((char) (c - 1));
                        ans[cnt] = s3.toString();
                        cnt++;
                        a = new BigInteger(s3.toString());
                        b = new BigInteger(s);
                        s = b.subtract(a).toString();
                    }
                }
            }
            System.out.println(cnt);
            for (int i = 0; i < cnt; i++)
                System.out.println(ans[i]);
        }
    }

    public static int readin() {
        return in.nextInt();
    }

    public static double readd() {
        return in.nextDouble();
    }

    public static BigInteger readBigInt() {
        return in.nextBigInteger();
    }

    public static BigDecimal readDecimal() {
        return in.nextBigDecimal();
    }

    public static String readstr() {
        return in.nextLine();
    }
}