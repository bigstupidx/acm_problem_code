import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			BigInteger result = new BigInteger("1");
			for (int i = 2; i <= n; i++) {
				result = result.multiply(BigInteger.valueOf(i));
			}
			System.out.println(result);
		}
	}
}
