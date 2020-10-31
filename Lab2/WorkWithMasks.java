import java.util.Scanner;

public class WorkWithMasks {
    public static Scanner scanf = new Scanner(System.in);

    public static void main(String[] args) {
        int M;
        int N;
        boolean key;
        N = enter_number();

        key = N < 0;

        System.out.print("Enter your 1 mask:  ");
        M = get_dec_from_oct();
        N = clear(M, N);
        System.out.print(" The first operation: " + N);

        System.out.print("\nEnter your 2 mask:  ");
        M = get_dec_from_oct();
        N = set(M, N);
        System.out.print(" The second operation: " + N + '\n');


        if (key) {
            System.out.print("Enter your 3 mask:  ");
            M = get_dec_from_oct();
            N = set(M, N);
        }
        System.out.print(" Result:  " + N);
        System.out.println(" ");

        System.out.println("\nDo you want to continue? Y or N: ");
        String ans;
        ans = scanf.nextLine();
        if (ans.equals("Y")) {
            main(args);
        }
    }

    public static int enter_number() {
        System.out.print("Enter your number:  ");
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        if (N > -128 & N < 127) {
            String tmpStr = Integer.toHexString(N);
            System.out.println("HexaDecimal: " + tmpStr);
            tmpStr = Integer.toOctalString(N);
            System.out.println("Octal: " + tmpStr);
            tmpStr = Integer.toBinaryString(N);
            System.out.println("Binary: " + tmpStr + '\n');
            return N;
        } else {
            System.out.println("The number is out of range! ");
            enter_number();
        }
        return 0;
    }

    public static int set(int M, int N) {
        return N ^= M;
    }

    public static int clear(int M, int N) {
        return N &= M;
    }

    public static int get_dec_from_oct() {
        String tmp = scanf.nextLine();
        return Integer.parseUnsignedInt(tmp, 8);
    }

}

