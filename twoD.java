import java.util.Scanner;

public class TwoD_parity {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();//"1010100101";
        String str2 = sc.next();//"1110000101";
        String str3 = sc.next();
        String str4 = sc.next();
        String sb="";
        int s1,s2,s3,s4,s5;s1=s2=s3=s4=s5=0;
        for(int i=0;i<str1.length();i++)
        {
            if(str1.charAt(i)=='1')
                s1++;
        }
        for(int i=0;i<str2.length();i++)
        {
            if(str2.charAt(i)=='1')
                s2++;
        }
        for(int i=0;i<str3.length();i++)
        {
            if(str3.charAt(i)=='1')
                s3++;
        }
        for(int i=0;i<str4.length();i++)
        {
            if(str4.charAt(i)=='1')
                s4++;
        }
        for (int i = 0; i < str1.length(); i++)
            sb=sb+(str1.charAt(i)^str2.charAt(i)^str3.charAt(i)^str4.charAt(i));
        for(int i=0;i<sb.length();i++)
        {
            if(sb.charAt(i)=='1')
                s5++;
        }
        System.out.println("                  Input              Row parities");
        System.out.println("                 "+str1+"              "+s1%2);
        System.out.println("                 "+str2+"              "+s2%2);
        System.out.println("                 "+str3+"              "+s3%2);
        System.out.println("                 "+str4+"              "+s4%2);
        System.out.println("Column parities  "+sb+  "              "+s5%2);

        System.out.println("\nData to be sent is: ");
        System.out.println(str1+s1%2+" "+str2+s2%2+" "+str3+s3%2+" "+str4+s4%2+" "+sb+s5%2+" ");
    }
}