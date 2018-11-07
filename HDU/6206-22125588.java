import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T;
        BigDecimal x1, y1, x2, y2, x3, y3, x4, y4, x, y, R, tmp2, A1, B1, C1, A2, B2, C2;
        BigDecimal two = new BigDecimal("2");
        T = in.nextInt();
        while ((T--) > 0) {
            x1 = in.nextBigDecimal();
            y1 = in.nextBigDecimal();
            x2 = in.nextBigDecimal();
            y2 = in.nextBigDecimal();
            x3 = in.nextBigDecimal();
            y3 = in.nextBigDecimal();
            x4 = in.nextBigDecimal();
            y4 = in.nextBigDecimal();
            A1 = new BigDecimal(two.multiply(x2.subtract(x1)).toString());
            B1 = new BigDecimal(two.multiply(y2.subtract(y1)).toString());
            C1 = new BigDecimal(x2.multiply(x2).add(y2.multiply(y2)).subtract(x1.multiply(x1)).subtract(y1.multiply(y1)).toString());
            A2 = new BigDecimal(two.multiply(x3.subtract(x2)).toString());
            B2 = new BigDecimal(two.multiply(y3.subtract(y2)).toString());
            C2 = new BigDecimal(x3.multiply(x3).add(y3.multiply(y3)).subtract(x2.multiply(x2)).subtract(y2.multiply(y2)).toString());
            x = new BigDecimal(C1.multiply(B2).subtract(C2.multiply(B1)).divide(A1.multiply(B2).subtract(A2.multiply(B1))).toString());
            y = new BigDecimal(A1.multiply(C2).subtract(A2.multiply(C1)).divide(A1.multiply(B2).subtract(A2.multiply(B1))).toString());
            R = new BigDecimal(x1.subtract(x).multiply(x1.subtract(x)).add(y1.subtract(y).multiply(y1.subtract(y))).toString());
            tmp2 = new BigDecimal(x4.subtract(x).multiply(x4.subtract(x)).add(y4.subtract(y).multiply(y4.subtract(y))).toString());
            if (tmp2.compareTo(R) == 1) {
                System.out.println("Accepted");
            } else {
                System.out.println("Rejected");
            }
        }
        in.close();
    }
}