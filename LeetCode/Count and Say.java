public class Main {

	public static class Solution {

		public String generate(String aa) {
			StringBuilder result = new StringBuilder();
			int len = aa.length(), cnt = 1;
			char ch = aa.charAt(0);
			System.out.println(aa);
			for (int i = 1; i < len; i++) {
				char new_ch = aa.charAt(i);
				if (new_ch != ch) {
					result.append(cnt);
					result.append(ch);
					ch = new_ch;
					cnt = 1;
				} else {
					++cnt;
				}
			}
			result.append(cnt);
			result.append(ch);
			return result.toString();
		}

		public String countAndSay(int n) {
			String start = "" + 1;
			for (int i = 1; i < n; i++) {
				start = generate(start);
			}
			return start;
		}
	}

	public static void main(String[] args) {
		Solution aa = new Solution();
		System.out.println(aa.countAndSay(6));
	}

//	Scanner cin = new Scanner(System.in);
//	while (cin.hasNext()) {
//		int n = cin.nextInt();
//		BigInteger result = new BigInteger("1");
//		for (int i = 2; i <= n; i++) {
//			result = result.multiply(BigInteger.valueOf(i));
//		}
//		System.out.println(result);
//	}
}
