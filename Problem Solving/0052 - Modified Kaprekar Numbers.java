import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'kaprekarNumbers' function below.
     *
     * The function accepts following parameters:
     *  1. INTEGER p
     *  2. INTEGER q
     */

    public static void kaprekarNumbers(int p, int q) {
    // Write your code here
        long tmp;
        long l;
        long r;
        long ns;
        int d;
        int Sum=0;
        boolean outp=true;
        for(; p<=q; p++){
            Sum=0;
            tmp=p;
            d = (int)Math.log10(p)+1;
            ns=(long)Math.pow(p,2);
            r=ns%(long)(Math.pow(10, d));
            l=ns/(long)Math.pow(10,d);
            //System.out.println(r + " " + l);
            if(l+r==p){
                System.out.print(p);
                System.out.print(" ");
                outp=false;
            }
        }
        if(outp){
            System.out.print("INVALID RANGE");
        }
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int p = Integer.parseInt(bufferedReader.readLine().trim());

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        Result.kaprekarNumbers(p, q);

        bufferedReader.close();
    }
}
